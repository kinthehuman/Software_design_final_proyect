#include <stdexcept> // contains runtime_error

class EmptyDatabase : public std::runtime_error {
public:
  EmptyDatabase()
    : std::runtime_error ("La base de datos se encuentra vacía, por favor cree una cuenta\n") {}
};
