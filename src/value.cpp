#include <stackvm/value.hpp>

namespace stackvm {

Value::Value() : slot(Nil{}) {}

Value::Value(bool b) : slot(b) {}

Value::Value(double d) : slot(d) {}

bool Value::is_nil() const { return std::holds_alternative<Nil>(slot); }

bool Value::is_bool() const { return std::holds_alternative<bool>(slot); }

bool Value::is_int() const { return std::holds_alternative<std::int64_t>(slot); }

bool Value::is_double() const { return std::holds_alternative<double>(slot); }

bool Value::as_bool() const { return std::get<bool>(slot); }

std::int64_t Value::as_int() const { return std::get<std::int64_t>(slot); }

double Value::as_double() const { return std::get<double>(slot); }

}
