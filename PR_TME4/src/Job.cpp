//
// Created by root on 18/10/18.
//

#include "Job.h"

namespace micky {

    Job::~Job() = default;

    void FirstJob::run() {
        std::cout << "Debut sur arg = " << arg << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        *res = arg % 256;
        std::cout << "Fini sur arg = " << arg << " res vaut " << *res << std::endl;
    }

    FirstJob::FirstJob(int a, int *r) : arg(a) , res(r)  {}

    PixelJob::PixelJob(micky::Barrier& b , int x , int y , const pr::Scene::screen_t& s , pr::Scene& sc , std::vector<pr::Vec3D>& l , pr::Color *p) : barrier(b) , x(x) , y(y) , screen(s) , scene(sc) ,  lights(l) , pixels(p) {}

    void PixelJob::run() {

        // le point de l'ecran par lequel passe ce rayon
        auto & screenPoint = screen[y][x];
        // le rayon a inspecter
        pr::Rayon ray(scene.getCameraPos(), screenPoint);

        auto minz = std::numeric_limits<float>::max();
        int targetSphere = -1;
        int index = 0;
        for (const auto & obj : scene) {
            // rend la distance de l'objet a la camera
            auto zinter = obj.instersects(ray);
            // si intersection plus proche  ?
            if (zinter < minz) {
                minz = zinter;
                targetSphere = index;
            }
            index++;
        }

        if (targetSphere != -1) {

            const pr::Sphere & obj = *(scene.begin() + targetSphere);
            // pixel prend la couleur de l'objet
            pr::Color finalcolor = obj.getColor();

            // calcul du rayon et de sa normale a la sphere
            // on prend le vecteur de la camera vers le point de l'ecran (dest - origine)
            // on le normalise a la longueur 1, on multiplie par la distance à l'intersection
            pr::Vec3D rayInter = (ray.dest - ray.ori).normalize() * minz;
            // le point d'intersection
            pr::Vec3D intersection = rayInter + scene.getCameraPos();
            // la normale a la sphere au point d'intersection donne l'angle pour la lumiere
            pr::Vec3D normal = obj.getNormale(intersection);
            // le niveau d'eclairage total contribue par les lumieres 0 sombre 1 total lumiere
            double dt = 0;
            // modifier par l'eclairage la couleur
            for (const auto & light : lights) {
                // le vecteur de la lumiere au point d'intersection
                pr::Vec3D tolight = (light - intersection);
                // si on est du bon cote de la sphere, i.e. le rayon n'intersecte pas avant de l'autre cote
                if (obj.instersects(pr::Rayon(light,intersection)) >= tolight.length() - 0.05 ) {   //  epsilon 0.05 for double issues
                    dt += tolight.normalize() & normal ; // l'angle (scalaire) donne la puissance de la lumiere reflechie
                }
            }
            // eclairage total
            finalcolor = finalcolor * dt + finalcolor * 0.2; // *0.2 = lumiere speculaire ambiante

            // le point de l'image (pixel) dont on vient de calculer la couleur
            pr::Color & pixel = pixels[y*scene.getHeight() + x];
            // mettre a jour la couleur du pixel dans l'image finale.
            pixel = finalcolor;
        }

        barrier.done();


    }

}