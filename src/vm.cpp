#include <stackvm/vm.hpp>

#include <stdexcept>
#include <string>

#include <stackvm/opcode.hpp>

namespace stackvm {

VM::VM() : pc(0) {}

VM::~VM() = default;

void VM::load(std::vector<std::uint8_t> bytecode) {
    code = std::move(bytecode);
    pc = 0;
    stack.clear();
}

void VM::run() {
    while (pc < code.size()) {
        Opcode op = static_cast<Opcode>(code[pc]);
        ++pc;

        switch (op) {
        default:
            throw std::runtime_error("unimplemented opcode " + std::string(opcode_name(op)));
        }
    }
}

std::size_t VM::ip() const { return pc; }

const Stack& VM::operands() const { return stack; }

}
