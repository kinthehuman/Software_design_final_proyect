#include <stdexcept> // contains runtime_error

class CurrentUser : public std::runtime_error {
public:
  CurrentUser()
    : std::runtime_error ("No se puede realizar la acción (User is logged in)\n") {}
};
