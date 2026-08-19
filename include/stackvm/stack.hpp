#pragma once

#include <cstddef>
#include <vector>

#include <stackvm/value.hpp>

namespace stackvm {

class Stack {
public:
    explicit Stack(std::size_t limit = 4096);

    void push(const Value& v);
    Value pop();
    const Value& peek() const;

    bool empty() const;
    std::size_t size() const;
    std::size_t limit() const;
    void clear();

private:
    std::vector<Value> items;
    std::size_t cap;
};

}
