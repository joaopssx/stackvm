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

    PUSH_CONST,
    POP,
    DUP,
    SWAP,
};

const char* opcode_name(Opcode op);

}
