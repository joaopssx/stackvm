#pragma once

#include <cstdint>

namespace stackvm {

enum class Opcode : std::uint8_t {
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    NEG,
};

const char* opcode_name(Opcode op);

}
