#pragma once

#include <cstdint>

namespace stackvm {

enum class Opcode : std::uint8_t;

const char* opcode_name(Opcode op);

}
