#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include <stackvm/stack.hpp>

namespace stackvm {

class VM {
public:
    VM();
    ~VM();

    void load(std::vector<std::uint8_t> bytecode);
    void run();

    std::size_t ip() const;
    const Stack& operands() const;

private:
    std::vector<std::uint8_t> code;
    std::size_t pc;
    Stack stack;
};

}
