// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: header.proto

#include "header.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
class HeaderMessageDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<HeaderMessage> _instance;
} _HeaderMessage_default_instance_;
static void InitDefaultsscc_info_HeaderMessage_header_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_HeaderMessage_default_instance_;
    new (ptr) ::HeaderMessage();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::HeaderMessage::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_HeaderMessage_header_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_HeaderMessage_header_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_header_2eproto[1];
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_header_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_header_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_header_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::HeaderMessage, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::HeaderMessage, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::HeaderMessage, protocol_),
  PROTOBUF_FIELD_OFFSET(::HeaderMessage, msgtype_),
  PROTOBUF_FIELD_OFFSET(::HeaderMessage, serial_),
  PROTOBUF_FIELD_OFFSET(::HeaderMessage, ticket_),
  PROTOBUF_FIELD_OFFSET(::HeaderMessage, gwid_),
  0,
  1,
  2,
  3,
  4,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 10, sizeof(::HeaderMessage)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_HeaderMessage_default_instance_),
};

const char descriptor_table_protodef_header_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\014header.proto\"{\n\rHeaderMessage\022\035\n\010proto"
  "col\030\001 \001(\0162\013.ProtocolID\022\035\n\007msgType\030\002 \001(\0162"
  "\014.MessageType\022\016\n\006serial\030\003 \001(\004\022\016\n\006ticket\030"
  "\004 \002(\004\022\014\n\004gwid\030\005 \002(\004*0\n\nProtocolID\022\020\n\014PRO"
  "T_ID_NONE\020\000\022\020\n\014PROT_ID_DNP3\020\001*D\n\013Message"
  "Type\022\021\n\rMSG_TYPE_NONE\020\000\022\017\n\013MSG_TYPE_GW\020\001"
  "\022\021\n\rMSG_TYPE_USER\020\002"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_header_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_header_2eproto_sccs[1] = {
  &scc_info_HeaderMessage_header_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_header_2eproto_once;
static bool descriptor_table_header_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_header_2eproto = {
  &descriptor_table_header_2eproto_initialized, descriptor_table_protodef_header_2eproto, "header.proto", 259,
  &descriptor_table_header_2eproto_once, descriptor_table_header_2eproto_sccs, descriptor_table_header_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_header_2eproto::offsets,
  file_level_metadata_header_2eproto, 1, file_level_enum_descriptors_header_2eproto, file_level_service_descriptors_header_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_header_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_header_2eproto), true);
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ProtocolID_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_header_2eproto);
  return file_level_enum_descriptors_header_2eproto[0];
}
bool ProtocolID_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* MessageType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_header_2eproto);
  return file_level_enum_descriptors_header_2eproto[1];
}
bool MessageType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}


// ===================================================================

void HeaderMessage::InitAsDefaultInstance() {
}
class HeaderMessage::_Internal {
 public:
  using HasBits = decltype(std::declval<HeaderMessage>()._has_bits_);
  static void set_has_protocol(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_msgtype(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_serial(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_ticket(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_gwid(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
};

HeaderMessage::HeaderMessage()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:HeaderMessage)
}
HeaderMessage::HeaderMessage(const HeaderMessage& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&protocol_, &from.protocol_,
    static_cast<size_t>(reinterpret_cast<char*>(&gwid_) -
    reinterpret_cast<char*>(&protocol_)) + sizeof(gwid_));
  // @@protoc_insertion_point(copy_constructor:HeaderMessage)
}

void HeaderMessage::SharedCtor() {
  ::memset(&protocol_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&gwid_) -
      reinterpret_cast<char*>(&protocol_)) + sizeof(gwid_));
}

HeaderMessage::~HeaderMessage() {
  // @@protoc_insertion_point(destructor:HeaderMessage)
  SharedDtor();
}

void HeaderMessage::SharedDtor() {
}

void HeaderMessage::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const HeaderMessage& HeaderMessage::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_HeaderMessage_header_2eproto.base);
  return *internal_default_instance();
}


void HeaderMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:HeaderMessage)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000001fu) {
    ::memset(&protocol_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&gwid_) -
        reinterpret_cast<char*>(&protocol_)) + sizeof(gwid_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* HeaderMessage::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional .ProtocolID protocol = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
          if (PROTOBUF_PREDICT_TRUE(::ProtocolID_IsValid(val))) {
            _internal_set_protocol(static_cast<::ProtocolID>(val));
          } else {
            ::PROTOBUF_NAMESPACE_ID::internal::WriteVarint(1, val, mutable_unknown_fields());
          }
        } else goto handle_unusual;
        continue;
      // optional .MessageType msgType = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
          if (PROTOBUF_PREDICT_TRUE(::MessageType_IsValid(val))) {
            _internal_set_msgtype(static_cast<::MessageType>(val));
          } else {
            ::PROTOBUF_NAMESPACE_ID::internal::WriteVarint(2, val, mutable_unknown_fields());
          }
        } else goto handle_unusual;
        continue;
      // optional uint64 serial = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          _Internal::set_has_serial(&has_bits);
          serial_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required uint64 ticket = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          _Internal::set_has_ticket(&has_bits);
          ticket_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required uint64 gwid = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 40)) {
          _Internal::set_has_gwid(&has_bits);
          gwid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* HeaderMessage::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:HeaderMessage)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional .ProtocolID protocol = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      1, this->_internal_protocol(), target);
  }

  // optional .MessageType msgType = 2;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      2, this->_internal_msgtype(), target);
  }

  // optional uint64 serial = 3;
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt64ToArray(3, this->_internal_serial(), target);
  }

  // required uint64 ticket = 4;
  if (cached_has_bits & 0x00000008u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt64ToArray(4, this->_internal_ticket(), target);
  }

  // required uint64 gwid = 5;
  if (cached_has_bits & 0x00000010u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt64ToArray(5, this->_internal_gwid(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:HeaderMessage)
  return target;
}

size_t HeaderMessage::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:HeaderMessage)
  size_t total_size = 0;

  if (_internal_has_ticket()) {
    // required uint64 ticket = 4;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64Size(
        this->_internal_ticket());
  }

  if (_internal_has_gwid()) {
    // required uint64 gwid = 5;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64Size(
        this->_internal_gwid());
  }

  return total_size;
}
size_t HeaderMessage::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:HeaderMessage)
  size_t total_size = 0;

  if (((_has_bits_[0] & 0x00000018) ^ 0x00000018) == 0) {  // All required fields are present.
    // required uint64 ticket = 4;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64Size(
        this->_internal_ticket());

    // required uint64 gwid = 5;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64Size(
        this->_internal_gwid());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    // optional .ProtocolID protocol = 1;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_protocol());
    }

    // optional .MessageType msgType = 2;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_msgtype());
    }

    // optional uint64 serial = 3;
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64Size(
          this->_internal_serial());
    }

  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void HeaderMessage::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:HeaderMessage)
  GOOGLE_DCHECK_NE(&from, this);
  const HeaderMessage* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<HeaderMessage>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:HeaderMessage)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:HeaderMessage)
    MergeFrom(*source);
  }
}

void HeaderMessage::MergeFrom(const HeaderMessage& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:HeaderMessage)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x0000001fu) {
    if (cached_has_bits & 0x00000001u) {
      protocol_ = from.protocol_;
    }
    if (cached_has_bits & 0x00000002u) {
      msgtype_ = from.msgtype_;
    }
    if (cached_has_bits & 0x00000004u) {
      serial_ = from.serial_;
    }
    if (cached_has_bits & 0x00000008u) {
      ticket_ = from.ticket_;
    }
    if (cached_has_bits & 0x00000010u) {
      gwid_ = from.gwid_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void HeaderMessage::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:HeaderMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void HeaderMessage::CopyFrom(const HeaderMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:HeaderMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool HeaderMessage::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000018) != 0x00000018) return false;
  return true;
}

void HeaderMessage::InternalSwap(HeaderMessage* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  swap(protocol_, other->protocol_);
  swap(msgtype_, other->msgtype_);
  swap(serial_, other->serial_);
  swap(ticket_, other->ticket_);
  swap(gwid_, other->gwid_);
}

::PROTOBUF_NAMESPACE_ID::Metadata HeaderMessage::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::HeaderMessage* Arena::CreateMaybeMessage< ::HeaderMessage >(Arena* arena) {
  return Arena::CreateInternal< ::HeaderMessage >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
