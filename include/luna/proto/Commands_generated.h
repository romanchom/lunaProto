// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_COMMANDS_LUNA_PROTO_H_
#define FLATBUFFERS_GENERATED_COMMANDS_LUNA_PROTO_H_

#include "flatbuffers/flatbuffers.h"

#include "SetColor_generated.h"

namespace luna {
namespace proto {

struct Null;

struct Command;

enum AnyCommand {
  AnyCommand_NONE = 0,
  AnyCommand_Null = 1,
  AnyCommand_SetColor = 2,
  AnyCommand_MIN = AnyCommand_NONE,
  AnyCommand_MAX = AnyCommand_SetColor
};

inline const AnyCommand (&EnumValuesAnyCommand())[3] {
  static const AnyCommand values[] = {
    AnyCommand_NONE,
    AnyCommand_Null,
    AnyCommand_SetColor
  };
  return values;
}

inline const char * const *EnumNamesAnyCommand() {
  static const char * const names[] = {
    "NONE",
    "Null",
    "SetColor",
    nullptr
  };
  return names;
}

inline const char *EnumNameAnyCommand(AnyCommand e) {
  if (e < AnyCommand_NONE || e > AnyCommand_SetColor) return "";
  const size_t index = static_cast<int>(e);
  return EnumNamesAnyCommand()[index];
}

template<typename T> struct AnyCommandTraits {
  static const AnyCommand enum_value = AnyCommand_NONE;
};

template<> struct AnyCommandTraits<Null> {
  static const AnyCommand enum_value = AnyCommand_Null;
};

template<> struct AnyCommandTraits<SetColor> {
  static const AnyCommand enum_value = AnyCommand_SetColor;
};

bool VerifyAnyCommand(flatbuffers::Verifier &verifier, const void *obj, AnyCommand type);
bool VerifyAnyCommandVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types);

struct Null FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           verifier.EndTable();
  }
};

struct NullBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  explicit NullBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  NullBuilder &operator=(const NullBuilder &);
  flatbuffers::Offset<Null> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Null>(end);
    return o;
  }
};

inline flatbuffers::Offset<Null> CreateNull(
    flatbuffers::FlatBufferBuilder &_fbb) {
  NullBuilder builder_(_fbb);
  return builder_.Finish();
}

struct Command FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_ID = 4,
    VT_ACK = 6,
    VT_COMMAND_TYPE = 8,
    VT_COMMAND = 10
  };
  uint32_t id() const {
    return GetField<uint32_t>(VT_ID, 0);
  }
  uint32_t ack() const {
    return GetField<uint32_t>(VT_ACK, 0);
  }
  AnyCommand command_type() const {
    return static_cast<AnyCommand>(GetField<uint8_t>(VT_COMMAND_TYPE, 0));
  }
  const void *command() const {
    return GetPointer<const void *>(VT_COMMAND);
  }
  template<typename T> const T *command_as() const;
  const Null *command_as_Null() const {
    return command_type() == AnyCommand_Null ? static_cast<const Null *>(command()) : nullptr;
  }
  const SetColor *command_as_SetColor() const {
    return command_type() == AnyCommand_SetColor ? static_cast<const SetColor *>(command()) : nullptr;
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint32_t>(verifier, VT_ID) &&
           VerifyField<uint32_t>(verifier, VT_ACK) &&
           VerifyField<uint8_t>(verifier, VT_COMMAND_TYPE) &&
           VerifyOffset(verifier, VT_COMMAND) &&
           VerifyAnyCommand(verifier, command(), command_type()) &&
           verifier.EndTable();
  }
};

template<> inline const Null *Command::command_as<Null>() const {
  return command_as_Null();
}

template<> inline const SetColor *Command::command_as<SetColor>() const {
  return command_as_SetColor();
}

struct CommandBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_id(uint32_t id) {
    fbb_.AddElement<uint32_t>(Command::VT_ID, id, 0);
  }
  void add_ack(uint32_t ack) {
    fbb_.AddElement<uint32_t>(Command::VT_ACK, ack, 0);
  }
  void add_command_type(AnyCommand command_type) {
    fbb_.AddElement<uint8_t>(Command::VT_COMMAND_TYPE, static_cast<uint8_t>(command_type), 0);
  }
  void add_command(flatbuffers::Offset<void> command) {
    fbb_.AddOffset(Command::VT_COMMAND, command);
  }
  explicit CommandBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  CommandBuilder &operator=(const CommandBuilder &);
  flatbuffers::Offset<Command> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Command>(end);
    return o;
  }
};

inline flatbuffers::Offset<Command> CreateCommand(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t id = 0,
    uint32_t ack = 0,
    AnyCommand command_type = AnyCommand_NONE,
    flatbuffers::Offset<void> command = 0) {
  CommandBuilder builder_(_fbb);
  builder_.add_command(command);
  builder_.add_ack(ack);
  builder_.add_id(id);
  builder_.add_command_type(command_type);
  return builder_.Finish();
}

inline bool VerifyAnyCommand(flatbuffers::Verifier &verifier, const void *obj, AnyCommand type) {
  switch (type) {
    case AnyCommand_NONE: {
      return true;
    }
    case AnyCommand_Null: {
      auto ptr = reinterpret_cast<const Null *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case AnyCommand_SetColor: {
      auto ptr = reinterpret_cast<const SetColor *>(obj);
      return verifier.VerifyTable(ptr);
    }
    default: return false;
  }
}

inline bool VerifyAnyCommandVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types) {
  if (!values || !types) return !values && !types;
  if (values->size() != types->size()) return false;
  for (flatbuffers::uoffset_t i = 0; i < values->size(); ++i) {
    if (!VerifyAnyCommand(
        verifier,  values->Get(i), types->GetEnum<AnyCommand>(i))) {
      return false;
    }
  }
  return true;
}

inline const luna::proto::Command *GetCommand(const void *buf) {
  return flatbuffers::GetRoot<luna::proto::Command>(buf);
}

inline const luna::proto::Command *GetSizePrefixedCommand(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<luna::proto::Command>(buf);
}

inline bool VerifyCommandBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<luna::proto::Command>(nullptr);
}

inline bool VerifySizePrefixedCommandBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<luna::proto::Command>(nullptr);
}

inline void FinishCommandBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<luna::proto::Command> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedCommandBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<luna::proto::Command> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace proto
}  // namespace luna

#endif  // FLATBUFFERS_GENERATED_COMMANDS_LUNA_PROTO_H_
