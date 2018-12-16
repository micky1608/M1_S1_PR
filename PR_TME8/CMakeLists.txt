cmake_minimum_required(VERSION 3.12)
project(tme8_micky1608)

set(CMAKE_CXX_STANDARD 14)

find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

include_directories(src)


protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS src/chat.proto)

add_executable(client src/clientchat.cpp
        src/ChatRoomProxy.cpp
        src/ChatRoomProxy.h
        src/ConnectionHandler.h
        src/CRConnectionHandler.cpp
        src/CRConnectionHandler.h
        src/IChatRoom.h
        src/MTChatRoom.h
        src/ServerSocket.h
        src/Socket.cpp
        src/Socket.h
        src/TextChatRoom.h
        ${PROTO_SRCS} ${PROTO_HDRS}
        )

add_executable(server src/serverchat.cpp
        src/ChatRoomProxy.cpp
        src/ChatRoomProxy.h
        src/ChatRoomServer.cpp
        src/ChatRoomServer.h
        src/ConnectionHandler.h
        src/CRConnectionHandler.cpp
        src/CRConnectionHandler.h
        src/IChatRoom.h
        src/Job.h
        src/MTChatRoom.h
        src/Pool.cpp
        src/Pool.h
        src/Queue.h
        src/ServerSocket.h
        src/Socket.cpp
        src/Socket.h
        src/TCPServer.cpp
        src/TCPServer.h
        src/TextChatRoom.h
        ${PROTO_SRCS} ${PROTO_HDRS}
        )

target_link_libraries(server pthread ${Protobuf_LIBRARIES})

target_link_libraries(client ${Protobuf_LIBRARIES})