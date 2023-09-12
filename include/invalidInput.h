#include <stdexcept> // contains runtime_error

class invalidInput : public std::runtime_error {
public:
  invalidInput()
    : std::runtime_error ("Invalid input\n") {}
};
