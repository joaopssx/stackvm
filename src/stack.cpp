#include <stackvm/stack.hpp>

#include <stdexcept>

namespace stackvm {

Stack::Stack(std::size_t limit) : cap(limit) {}

void Stack::push(const Value& v) {
    if (items.size() >= cap) {
        throw std::out_of_range("stack overflow");
    }
    items.push_back(v);
}

Value Stack::pop() {
    if (items.empty()) {
        throw std::out_of_range("stack underflow");
    }
    Value top = items.back();
    items.pop_back();
    return top;
}

const Value& Stack::peek() const {
    if (items.empty()) {
        throw std::out_of_range("peek on empty stack");
    }
    return items.back();
}

bool Stack::empty() const { return items.empty(); }

std::size_t Stack::size() const { return items.size(); }

std::size_t Stack::limit() const { return cap; }

void Stack::clear() { items.clear(); }

}
