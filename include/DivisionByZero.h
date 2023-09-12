#include <stdexcept> // contains runtime_error

class DivisionByZero : public std::runtime_error {
public:
  DivisionByZero()
    : std::runtime_error ("ERROR: Division by zero is not possible\n") {}
};
