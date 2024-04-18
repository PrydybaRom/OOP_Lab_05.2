#include "E_.h"

E::E(std::string message)
    : message(message)
{}

std::string E::What() {
    return message;
}
