// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: objects.proto

#include "objects.pb.h"

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
extern PROTOBUF_INTERNAL_EXPORT_objects_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_ValObj_objects_2eproto;
class ValObjDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<ValObj> _instance;
} _ValObj_default_instance_;
class ObjectValuesDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<ObjectValues> _instance;
} _ObjectValues_default_instance_;
static void InitDefaultsscc_info_ObjectValues_objects_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_ObjectValues_default_instance_;
    new (ptr) ::ObjectValues();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::ObjectValues::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_ObjectValues_objects_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_ObjectValues_objects_2eproto}, {
      &scc_info_ValObj_objects_2eproto.base,}};

static void InitDefaultsscc_info_ValObj_objects_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_ValObj_default_instance_;
    new (ptr) ::ValObj();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::ValObj::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_ValObj_objects_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_ValObj_objects_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_objects_2eproto[2];
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_objects_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_objects_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_objects_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::ValObj, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::ValObj, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::ValObj, point_),
  PROTOBUF_FIELD_OFFSET(::ValObj, ivalue_),
  PROTOBUF_FIELD_OFFSET(::ValObj, fvalue_),
  PROTOBUF_FIELD_OFFSET(::ValObj, timestamp_),
  PROTOBUF_FIELD_OFFSET(::ValObj, online_),
  0,
  1,
  3,
  2,
  4,
  PROTOBUF_FIELD_OFFSET(::ObjectValues, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::ObjectValues, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::ObjectValues, objtype_),
  PROTOBUF_FIELD_OFFSET(::ObjectValues, objvalues_),
  0,
  ~0u,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 10, sizeof(::ValObj)},
  { 15, 22, sizeof(::ObjectValues)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_ValObj_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_ObjectValues_default_instance_),
};

const char descriptor_table_protodef_objects_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\robjects.proto\"Z\n\006ValObj\022\r\n\005point\030\001 \001(\r"
  "\022\016\n\006iValue\030\002 \001(\005\022\016\n\006fValue\030\003 \001(\002\022\021\n\ttime"
  "stamp\030\004 \001(\003\022\016\n\006online\030\005 \001(\010\"E\n\014ObjectVal"
  "ues\022\031\n\007objType\030\001 \001(\0162\010.ObjType\022\032\n\tobjVal"
  "ues\030\002 \003(\0132\007.ValObj*\352\001\n\007ObjType\022\021\n\rOBJ_TY"
  "PE_NONE\020\000\022\016\n\nRESERVED_1\020\001\022\016\n\nRESERVED_2\020"
  "\002\022\016\n\nRESERVED_3\020\003\022\031\n\025OBJ_TYPE_BINARY_INP"
  "UT\020\004\022\032\n\026OBJ_TYPE_BINARY_OUTPUT\020\005\022\033\n\027OBJ_"
  "TYPE_BINARY_COUNTER\020\006\022\031\n\025OBJ_TYPE_ANALOG"
  "_INPUT\020\007\022\032\n\026OBJ_TYPE_ANALOG_OUTPUT\020\010\022\021\n\r"
  "OBJ_TYPE_FILE\020\t"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_objects_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_objects_2eproto_sccs[2] = {
  &scc_info_ObjectValues_objects_2eproto.base,
  &scc_info_ValObj_objects_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_objects_2eproto_once;
static bool descriptor_table_objects_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_objects_2eproto = {
  &descriptor_table_objects_2eproto_initialized, descriptor_table_protodef_objects_2eproto, "objects.proto", 415,
  &descriptor_table_objects_2eproto_once, descriptor_table_objects_2eproto_sccs, descriptor_table_objects_2eproto_deps, 2, 0,
  schemas, file_default_instances, TableStruct_objects_2eproto::offsets,
  file_level_metadata_objects_2eproto, 2, file_level_enum_descriptors_objects_2eproto, file_level_service_descriptors_objects_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_objects_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_objects_2eproto), true);
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ObjType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_objects_2eproto);
  return file_level_enum_descriptors_objects_2eproto[0];
}
bool ObjType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
      return true;
    default:
      return false;
  }
}


// ===================================================================

void ValObj::InitAsDefaultInstance() {
}
class ValObj::_Internal {
 public:
  using HasBits = decltype(std::declval<ValObj>()._has_bits_);
  static void set_has_point(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_ivalue(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_fvalue(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_timestamp(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_online(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
};

ValObj::ValObj()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:ValObj)
}
ValObj::ValObj(const ValObj& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&point_, &from.point_,
    static_cast<size_t>(reinterpret_cast<char*>(&online_) -
    reinterpret_cast<char*>(&point_)) + sizeof(online_));
  // @@protoc_insertion_point(copy_constructor:ValObj)
}

void ValObj::SharedCtor() {
  ::memset(&point_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&online_) -
      reinterpret_cast<char*>(&point_)) + sizeof(online_));
}

ValObj::~ValObj() {
  // @@protoc_insertion_point(destructor:ValObj)
  SharedDtor();
}

void ValObj::SharedDtor() {
}

void ValObj::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ValObj& ValObj::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_ValObj_objects_2eproto.base);
  return *internal_default_instance();
}


void ValObj::Clear() {
// @@protoc_insertion_point(message_clear_start:ValObj)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000001fu) {
    ::memset(&point_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&online_) -
        reinterpret_cast<char*>(&point_)) + sizeof(online_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* ValObj::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional uint32 point = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_point(&has_bits);
          point_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional int32 iValue = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _Internal::set_has_ivalue(&has_bits);
          ivalue_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional float fValue = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 29)) {
          _Internal::set_has_fvalue(&has_bits);
          fvalue_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      // optional int64 timestamp = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          _Internal::set_has_timestamp(&has_bits);
          timestamp_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional bool online = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 40)) {
          _Internal::set_has_online(&has_bits);
          online_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* ValObj::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ValObj)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional uint32 point = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(1, this->_internal_point(), target);
  }

  // optional int32 iValue = 2;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(2, this->_internal_ivalue(), target);
  }

  // optional float fValue = 3;
  if (cached_has_bits & 0x00000008u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(3, this->_internal_fvalue(), target);
  }

  // optional int64 timestamp = 4;
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(4, this->_internal_timestamp(), target);
  }

  // optional bool online = 5;
  if (cached_has_bits & 0x00000010u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(5, this->_internal_online(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ValObj)
  return target;
}

size_t ValObj::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ValObj)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000001fu) {
    // optional uint32 point = 1;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
          this->_internal_point());
    }

    // optional int32 iValue = 2;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->_internal_ivalue());
    }

    // optional int64 timestamp = 4;
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
          this->_internal_timestamp());
    }

    // optional float fValue = 3;
    if (cached_has_bits & 0x00000008u) {
      total_size += 1 + 4;
    }

    // optional bool online = 5;
    if (cached_has_bits & 0x00000010u) {
      total_size += 1 + 1;
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

void ValObj::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:ValObj)
  GOOGLE_DCHECK_NE(&from, this);
  const ValObj* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<ValObj>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:ValObj)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:ValObj)
    MergeFrom(*source);
  }
}

void ValObj::MergeFrom(const ValObj& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ValObj)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x0000001fu) {
    if (cached_has_bits & 0x00000001u) {
      point_ = from.point_;
    }
    if (cached_has_bits & 0x00000002u) {
      ivalue_ = from.ivalue_;
    }
    if (cached_has_bits & 0x00000004u) {
      timestamp_ = from.timestamp_;
    }
    if (cached_has_bits & 0x00000008u) {
      fvalue_ = from.fvalue_;
    }
    if (cached_has_bits & 0x00000010u) {
      online_ = from.online_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void ValObj::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:ValObj)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ValObj::CopyFrom(const ValObj& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ValObj)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ValObj::IsInitialized() const {
  return true;
}

void ValObj::InternalSwap(ValObj* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  swap(point_, other->point_);
  swap(ivalue_, other->ivalue_);
  swap(timestamp_, other->timestamp_);
  swap(fvalue_, other->fvalue_);
  swap(online_, other->online_);
}

::PROTOBUF_NAMESPACE_ID::Metadata ValObj::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void ObjectValues::InitAsDefaultInstance() {
}
class ObjectValues::_Internal {
 public:
  using HasBits = decltype(std::declval<ObjectValues>()._has_bits_);
  static void set_has_objtype(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

ObjectValues::ObjectValues()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:ObjectValues)
}
ObjectValues::ObjectValues(const ObjectValues& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_),
      objvalues_(from.objvalues_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  objtype_ = from.objtype_;
  // @@protoc_insertion_point(copy_constructor:ObjectValues)
}

void ObjectValues::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_ObjectValues_objects_2eproto.base);
  objtype_ = 0;
}

ObjectValues::~ObjectValues() {
  // @@protoc_insertion_point(destructor:ObjectValues)
  SharedDtor();
}

void ObjectValues::SharedDtor() {
}

void ObjectValues::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ObjectValues& ObjectValues::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_ObjectValues_objects_2eproto.base);
  return *internal_default_instance();
}


void ObjectValues::Clear() {
// @@protoc_insertion_point(message_clear_start:ObjectValues)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  objvalues_.Clear();
  objtype_ = 0;
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* ObjectValues::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional .ObjType objType = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
          if (PROTOBUF_PREDICT_TRUE(::ObjType_IsValid(val))) {
            _internal_set_objtype(static_cast<::ObjType>(val));
          } else {
            ::PROTOBUF_NAMESPACE_ID::internal::WriteVarint(1, val, mutable_unknown_fields());
          }
        } else goto handle_unusual;
        continue;
      // repeated .ValObj objValues = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_objvalues(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
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

::PROTOBUF_NAMESPACE_ID::uint8* ObjectValues::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ObjectValues)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional .ObjType objType = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      1, this->_internal_objtype(), target);
  }

  // repeated .ValObj objValues = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_objvalues_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(2, this->_internal_objvalues(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ObjectValues)
  return target;
}

size_t ObjectValues::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ObjectValues)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .ValObj objValues = 2;
  total_size += 1UL * this->_internal_objvalues_size();
  for (const auto& msg : this->objvalues_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // optional .ObjType objType = 1;
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_objtype());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ObjectValues::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:ObjectValues)
  GOOGLE_DCHECK_NE(&from, this);
  const ObjectValues* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<ObjectValues>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:ObjectValues)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:ObjectValues)
    MergeFrom(*source);
  }
}

void ObjectValues::MergeFrom(const ObjectValues& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ObjectValues)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  objvalues_.MergeFrom(from.objvalues_);
  if (from._internal_has_objtype()) {
    _internal_set_objtype(from._internal_objtype());
  }
}

void ObjectValues::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:ObjectValues)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ObjectValues::CopyFrom(const ObjectValues& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ObjectValues)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ObjectValues::IsInitialized() const {
  return true;
}

void ObjectValues::InternalSwap(ObjectValues* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  objvalues_.InternalSwap(&other->objvalues_);
  swap(objtype_, other->objtype_);
}

::PROTOBUF_NAMESPACE_ID::Metadata ObjectValues::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::ValObj* Arena::CreateMaybeMessage< ::ValObj >(Arena* arena) {
  return Arena::CreateInternal< ::ValObj >(arena);
}
template<> PROTOBUF_NOINLINE ::ObjectValues* Arena::CreateMaybeMessage< ::ObjectValues >(Arena* arena) {
  return Arena::CreateInternal< ::ObjectValues >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>