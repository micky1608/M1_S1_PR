// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: chat.proto

#include "chat.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace pr {
class chatMessagePBDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<chatMessagePB>
      _instance;
} _chatMessagePB_default_instance_;
}  // namespace pr
namespace protobuf_chat_2eproto {
static void InitDefaultschatMessagePB() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::pr::_chatMessagePB_default_instance_;
    new (ptr) ::pr::chatMessagePB();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::pr::chatMessagePB::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_chatMessagePB =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultschatMessagePB}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_chatMessagePB.base);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::pr::chatMessagePB, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::pr::chatMessagePB, author_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::pr::chatMessagePB, mes_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::pr::chatMessagePB)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::pr::_chatMessagePB_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "chat.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\nchat.proto\022\002pr\",\n\rchatMessagePB\022\016\n\006aut"
      "hor\030\001 \001(\t\022\013\n\003mes\030\002 \001(\tb\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 70);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "chat.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_chat_2eproto
namespace pr {

// ===================================================================

void chatMessagePB::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int chatMessagePB::kAuthorFieldNumber;
const int chatMessagePB::kMesFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

chatMessagePB::chatMessagePB()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_chat_2eproto::scc_info_chatMessagePB.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:pr.chatMessagePB)
}
chatMessagePB::chatMessagePB(const chatMessagePB& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  author_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.author().size() > 0) {
    author_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.author_);
  }
  mes_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.mes().size() > 0) {
    mes_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.mes_);
  }
  // @@protoc_insertion_point(copy_constructor:pr.chatMessagePB)
}

void chatMessagePB::SharedCtor() {
  author_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  mes_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

chatMessagePB::~chatMessagePB() {
  // @@protoc_insertion_point(destructor:pr.chatMessagePB)
  SharedDtor();
}

void chatMessagePB::SharedDtor() {
  author_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  mes_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void chatMessagePB::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* chatMessagePB::descriptor() {
  ::protobuf_chat_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_chat_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const chatMessagePB& chatMessagePB::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_chat_2eproto::scc_info_chatMessagePB.base);
  return *internal_default_instance();
}


void chatMessagePB::Clear() {
// @@protoc_insertion_point(message_clear_start:pr.chatMessagePB)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  author_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  mes_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _internal_metadata_.Clear();
}

bool chatMessagePB::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:pr.chatMessagePB)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string author = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_author()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->author().data(), static_cast<int>(this->author().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "pr.chatMessagePB.author"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string mes = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_mes()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->mes().data(), static_cast<int>(this->mes().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "pr.chatMessagePB.mes"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:pr.chatMessagePB)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:pr.chatMessagePB)
  return false;
#undef DO_
}

void chatMessagePB::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:pr.chatMessagePB)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string author = 1;
  if (this->author().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->author().data(), static_cast<int>(this->author().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "pr.chatMessagePB.author");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->author(), output);
  }

  // string mes = 2;
  if (this->mes().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->mes().data(), static_cast<int>(this->mes().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "pr.chatMessagePB.mes");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->mes(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:pr.chatMessagePB)
}

::google::protobuf::uint8* chatMessagePB::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:pr.chatMessagePB)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string author = 1;
  if (this->author().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->author().data(), static_cast<int>(this->author().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "pr.chatMessagePB.author");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->author(), target);
  }

  // string mes = 2;
  if (this->mes().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->mes().data(), static_cast<int>(this->mes().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "pr.chatMessagePB.mes");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->mes(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:pr.chatMessagePB)
  return target;
}

size_t chatMessagePB::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:pr.chatMessagePB)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // string author = 1;
  if (this->author().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->author());
  }

  // string mes = 2;
  if (this->mes().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->mes());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void chatMessagePB::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:pr.chatMessagePB)
  GOOGLE_DCHECK_NE(&from, this);
  const chatMessagePB* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const chatMessagePB>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:pr.chatMessagePB)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:pr.chatMessagePB)
    MergeFrom(*source);
  }
}

void chatMessagePB::MergeFrom(const chatMessagePB& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:pr.chatMessagePB)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.author().size() > 0) {

    author_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.author_);
  }
  if (from.mes().size() > 0) {

    mes_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.mes_);
  }
}

void chatMessagePB::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:pr.chatMessagePB)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void chatMessagePB::CopyFrom(const chatMessagePB& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:pr.chatMessagePB)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool chatMessagePB::IsInitialized() const {
  return true;
}

void chatMessagePB::Swap(chatMessagePB* other) {
  if (other == this) return;
  InternalSwap(other);
}
void chatMessagePB::InternalSwap(chatMessagePB* other) {
  using std::swap;
  author_.Swap(&other->author_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  mes_.Swap(&other->mes_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata chatMessagePB::GetMetadata() const {
  protobuf_chat_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_chat_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace pr
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::pr::chatMessagePB* Arena::CreateMaybeMessage< ::pr::chatMessagePB >(Arena* arena) {
  return Arena::CreateInternal< ::pr::chatMessagePB >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
