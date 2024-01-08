// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: header.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_header_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_header_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3011000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3011003 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_header_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_header_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_header_2eproto;
class HeaderMessage;
class HeaderMessageDefaultTypeInternal;
extern HeaderMessageDefaultTypeInternal _HeaderMessage_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::HeaderMessage* Arena::CreateMaybeMessage<::HeaderMessage>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

enum ProtocolID : int {
  PROT_ID_NONE = 0,
  PROT_ID_DNP3 = 1
};
bool ProtocolID_IsValid(int value);
constexpr ProtocolID ProtocolID_MIN = PROT_ID_NONE;
constexpr ProtocolID ProtocolID_MAX = PROT_ID_DNP3;
constexpr int ProtocolID_ARRAYSIZE = ProtocolID_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ProtocolID_descriptor();
template<typename T>
inline const std::string& ProtocolID_Name(T enum_t_value) {
  static_assert(::std::is_same<T, ProtocolID>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function ProtocolID_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    ProtocolID_descriptor(), enum_t_value);
}
inline bool ProtocolID_Parse(
    const std::string& name, ProtocolID* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<ProtocolID>(
    ProtocolID_descriptor(), name, value);
}
enum MessageType : int {
  MSG_TYPE_NONE = 0,
  MSG_TYPE_GW = 1,
  MSG_TYPE_USER = 2
};
bool MessageType_IsValid(int value);
constexpr MessageType MessageType_MIN = MSG_TYPE_NONE;
constexpr MessageType MessageType_MAX = MSG_TYPE_USER;
constexpr int MessageType_ARRAYSIZE = MessageType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* MessageType_descriptor();
template<typename T>
inline const std::string& MessageType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, MessageType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function MessageType_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    MessageType_descriptor(), enum_t_value);
}
inline bool MessageType_Parse(
    const std::string& name, MessageType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<MessageType>(
    MessageType_descriptor(), name, value);
}
// ===================================================================

class HeaderMessage :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:HeaderMessage) */ {
 public:
  HeaderMessage();
  virtual ~HeaderMessage();

  HeaderMessage(const HeaderMessage& from);
  HeaderMessage(HeaderMessage&& from) noexcept
    : HeaderMessage() {
    *this = ::std::move(from);
  }

  inline HeaderMessage& operator=(const HeaderMessage& from) {
    CopyFrom(from);
    return *this;
  }
  inline HeaderMessage& operator=(HeaderMessage&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const HeaderMessage& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const HeaderMessage* internal_default_instance() {
    return reinterpret_cast<const HeaderMessage*>(
               &_HeaderMessage_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(HeaderMessage& a, HeaderMessage& b) {
    a.Swap(&b);
  }
  inline void Swap(HeaderMessage* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline HeaderMessage* New() const final {
    return CreateMaybeMessage<HeaderMessage>(nullptr);
  }

  HeaderMessage* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<HeaderMessage>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const HeaderMessage& from);
  void MergeFrom(const HeaderMessage& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(HeaderMessage* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "HeaderMessage";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_header_2eproto);
    return ::descriptor_table_header_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kProtocolFieldNumber = 1,
    kMsgTypeFieldNumber = 2,
    kSerialFieldNumber = 3,
    kTicketFieldNumber = 4,
    kGwidFieldNumber = 5,
  };
  // optional .ProtocolID protocol = 1;
  bool has_protocol() const;
  private:
  bool _internal_has_protocol() const;
  public:
  void clear_protocol();
  ::ProtocolID protocol() const;
  void set_protocol(::ProtocolID value);
  private:
  ::ProtocolID _internal_protocol() const;
  void _internal_set_protocol(::ProtocolID value);
  public:

  // optional .MessageType msgType = 2;
  bool has_msgtype() const;
  private:
  bool _internal_has_msgtype() const;
  public:
  void clear_msgtype();
  ::MessageType msgtype() const;
  void set_msgtype(::MessageType value);
  private:
  ::MessageType _internal_msgtype() const;
  void _internal_set_msgtype(::MessageType value);
  public:

  // optional uint64 serial = 3;
  bool has_serial() const;
  private:
  bool _internal_has_serial() const;
  public:
  void clear_serial();
  ::PROTOBUF_NAMESPACE_ID::uint64 serial() const;
  void set_serial(::PROTOBUF_NAMESPACE_ID::uint64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint64 _internal_serial() const;
  void _internal_set_serial(::PROTOBUF_NAMESPACE_ID::uint64 value);
  public:

  // required uint64 ticket = 4;
  bool has_ticket() const;
  private:
  bool _internal_has_ticket() const;
  public:
  void clear_ticket();
  ::PROTOBUF_NAMESPACE_ID::uint64 ticket() const;
  void set_ticket(::PROTOBUF_NAMESPACE_ID::uint64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint64 _internal_ticket() const;
  void _internal_set_ticket(::PROTOBUF_NAMESPACE_ID::uint64 value);
  public:

  // required uint64 gwid = 5;
  bool has_gwid() const;
  private:
  bool _internal_has_gwid() const;
  public:
  void clear_gwid();
  ::PROTOBUF_NAMESPACE_ID::uint64 gwid() const;
  void set_gwid(::PROTOBUF_NAMESPACE_ID::uint64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint64 _internal_gwid() const;
  void _internal_set_gwid(::PROTOBUF_NAMESPACE_ID::uint64 value);
  public:

  // @@protoc_insertion_point(class_scope:HeaderMessage)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  int protocol_;
  int msgtype_;
  ::PROTOBUF_NAMESPACE_ID::uint64 serial_;
  ::PROTOBUF_NAMESPACE_ID::uint64 ticket_;
  ::PROTOBUF_NAMESPACE_ID::uint64 gwid_;
  friend struct ::TableStruct_header_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// HeaderMessage

// optional .ProtocolID protocol = 1;
inline bool HeaderMessage::_internal_has_protocol() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool HeaderMessage::has_protocol() const {
  return _internal_has_protocol();
}
inline void HeaderMessage::clear_protocol() {
  protocol_ = 0;
  _has_bits_[0] &= ~0x00000001u;
}
inline ::ProtocolID HeaderMessage::_internal_protocol() const {
  return static_cast< ::ProtocolID >(protocol_);
}
inline ::ProtocolID HeaderMessage::protocol() const {
  // @@protoc_insertion_point(field_get:HeaderMessage.protocol)
  return _internal_protocol();
}
inline void HeaderMessage::_internal_set_protocol(::ProtocolID value) {
  assert(::ProtocolID_IsValid(value));
  _has_bits_[0] |= 0x00000001u;
  protocol_ = value;
}
inline void HeaderMessage::set_protocol(::ProtocolID value) {
  _internal_set_protocol(value);
  // @@protoc_insertion_point(field_set:HeaderMessage.protocol)
}

// optional .MessageType msgType = 2;
inline bool HeaderMessage::_internal_has_msgtype() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool HeaderMessage::has_msgtype() const {
  return _internal_has_msgtype();
}
inline void HeaderMessage::clear_msgtype() {
  msgtype_ = 0;
  _has_bits_[0] &= ~0x00000002u;
}
inline ::MessageType HeaderMessage::_internal_msgtype() const {
  return static_cast< ::MessageType >(msgtype_);
}
inline ::MessageType HeaderMessage::msgtype() const {
  // @@protoc_insertion_point(field_get:HeaderMessage.msgType)
  return _internal_msgtype();
}
inline void HeaderMessage::_internal_set_msgtype(::MessageType value) {
  assert(::MessageType_IsValid(value));
  _has_bits_[0] |= 0x00000002u;
  msgtype_ = value;
}
inline void HeaderMessage::set_msgtype(::MessageType value) {
  _internal_set_msgtype(value);
  // @@protoc_insertion_point(field_set:HeaderMessage.msgType)
}

// optional uint64 serial = 3;
inline bool HeaderMessage::_internal_has_serial() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool HeaderMessage::has_serial() const {
  return _internal_has_serial();
}
inline void HeaderMessage::clear_serial() {
  serial_ = PROTOBUF_ULONGLONG(0);
  _has_bits_[0] &= ~0x00000004u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 HeaderMessage::_internal_serial() const {
  return serial_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 HeaderMessage::serial() const {
  // @@protoc_insertion_point(field_get:HeaderMessage.serial)
  return _internal_serial();
}
inline void HeaderMessage::_internal_set_serial(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  _has_bits_[0] |= 0x00000004u;
  serial_ = value;
}
inline void HeaderMessage::set_serial(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  _internal_set_serial(value);
  // @@protoc_insertion_point(field_set:HeaderMessage.serial)
}

// required uint64 ticket = 4;
inline bool HeaderMessage::_internal_has_ticket() const {
  bool value = (_has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool HeaderMessage::has_ticket() const {
  return _internal_has_ticket();
}
inline void HeaderMessage::clear_ticket() {
  ticket_ = PROTOBUF_ULONGLONG(0);
  _has_bits_[0] &= ~0x00000008u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 HeaderMessage::_internal_ticket() const {
  return ticket_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 HeaderMessage::ticket() const {
  // @@protoc_insertion_point(field_get:HeaderMessage.ticket)
  return _internal_ticket();
}
inline void HeaderMessage::_internal_set_ticket(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  _has_bits_[0] |= 0x00000008u;
  ticket_ = value;
}
inline void HeaderMessage::set_ticket(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  _internal_set_ticket(value);
  // @@protoc_insertion_point(field_set:HeaderMessage.ticket)
}

// required uint64 gwid = 5;
inline bool HeaderMessage::_internal_has_gwid() const {
  bool value = (_has_bits_[0] & 0x00000010u) != 0;
  return value;
}
inline bool HeaderMessage::has_gwid() const {
  return _internal_has_gwid();
}
inline void HeaderMessage::clear_gwid() {
  gwid_ = PROTOBUF_ULONGLONG(0);
  _has_bits_[0] &= ~0x00000010u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 HeaderMessage::_internal_gwid() const {
  return gwid_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 HeaderMessage::gwid() const {
  // @@protoc_insertion_point(field_get:HeaderMessage.gwid)
  return _internal_gwid();
}
inline void HeaderMessage::_internal_set_gwid(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  _has_bits_[0] |= 0x00000010u;
  gwid_ = value;
}
inline void HeaderMessage::set_gwid(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  _internal_set_gwid(value);
  // @@protoc_insertion_point(field_set:HeaderMessage.gwid)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::ProtocolID> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::ProtocolID>() {
  return ::ProtocolID_descriptor();
}
template <> struct is_proto_enum< ::MessageType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::MessageType>() {
  return ::MessageType_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_header_2eproto