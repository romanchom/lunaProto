// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_COMMANDS_H_
#define FLATBUFFERS_GENERATED_COMMANDS_H_

#include "flatbuffers/flatbuffers.h"

#include "SetColor_generated.h"

struct Command;

enum AnyCommand {
  AnyCommand_NONE = 0,
  AnyCommand_SetColor = 1,
  AnyCommand_MIN = AnyCommand_NONE,
  AnyCommand_MAX = AnyCommand_SetColor
};

inline const AnyCommand (&EnumValuesAnyCommand())[2] {
  static const AnyCommand values[] = {
    AnyCommand_NONE,
    AnyCommand_SetColor
  };
  return values;
}

inline const char * const *EnumNamesAnyCommand() {
  static const char * const names[] = {
    "NONE",
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

template<> struct AnyCommandTraits<SetColor> {
  static const AnyCommand enum_value = AnyCommand_SetColor;
};

bool VerifyAnyCommand(flatbuffers::Verifier &verifier, const void *obj, AnyCommand type);
bool VerifyAnyCommandVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types);

struct Command FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_ACKNOWLEDGE = 4,
    VT_COMMAND_TYPE = 6,
    VT_COMMAND = 8
  };
  bool acknowledge() const {
    return GetField<uint8_t>(VT_ACKNOWLEDGE, 0) != 0;
  }
  AnyCommand command_type() const {
    return static_cast<AnyCommand>(GetField<uint8_t>(VT_COMMAND_TYPE, 0));
  }
  const void *command() const {
    return GetPointer<const void *>(VT_COMMAND);
  }
  template<typename T> const T *command_as() const;
  const SetColor *command_as_SetColor() const {
    return command_type() == AnyCommand_SetColor ? static_cast<const SetColor *>(command()) : nullptr;
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_ACKNOWLEDGE) &&
           VerifyField<uint8_t>(verifier, VT_COMMAND_TYPE) &&
           VerifyOffset(verifier, VT_COMMAND) &&
           VerifyAnyCommand(verifier, command(), command_type()) &&
           verifier.EndTable();
  }
};

template<> inline const SetColor *Command::command_as<SetColor>() const {
  return command_as_SetColor();
}

struct CommandBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_acknowledge(bool acknowledge) {
    fbb_.AddElement<uint8_t>(Command::VT_ACKNOWLEDGE, static_cast<uint8_t>(acknowledge), 0);
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
    bool acknowledge = false,
    AnyCommand command_type = AnyCommand_NONE,
    flatbuffers::Offset<void> command = 0) {
  CommandBuilder builder_(_fbb);
  builder_.add_command(command);
  builder_.add_command_type(command_type);
  builder_.add_acknowledge(acknowledge);
  return builder_.Finish();
}

inline bool VerifyAnyCommand(flatbuffers::Verifier &verifier, const void *obj, AnyCommand type) {
  switch (type) {
    case AnyCommand_NONE: {
      return true;
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

#endif  // FLATBUFFERS_GENERATED_COMMANDS_H_
