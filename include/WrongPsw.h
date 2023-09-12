#include <stdexcept> // contains runtime_error

class WrongPsw : public std::runtime_error {
public:
  WrongPsw()
    : std::runtime_error ("Contraseña incorrecta\n") {}
};
