#include <stdexcept> // contains runtime_error

class NotAdmin : public std::runtime_error {
public:
  NotAdmin()
    : std::runtime_error ("ERROR: Acción restringida a ADMIN\n") {}
};
