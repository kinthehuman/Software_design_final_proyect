#include <stdexcept> // contains runtime_error

class NotFound : public std::runtime_error {
public:
  NotFound()
    : std::runtime_error ("No se ha podido realizar la acción (User not found)\n") {}
};
