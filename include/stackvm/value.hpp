#pragma once

#include <cstdint>
#include <type_traits>
#include <variant>

namespace stackvm {

struct Nil {};

class Value {
public:
    Value();
    Value(bool b);
    Value(double d);

    template <class T, class = std::enable_if_t<std::is_integral_v<T> && !std::is_same_v<T, bool>>>
    Value(T i) : slot(static_cast<std::int64_t>(i)) {}

    bool is_nil() const;
    bool is_bool() const;
    bool is_int() const;
    bool is_double() const;

    bool as_bool() const;
    std::int64_t as_int() const;
    double as_double() const;

private:
    std::variant<Nil, bool, std::int64_t, double> slot;
};

}
