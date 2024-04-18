#include "Error_.h"

Error::Error(std::string message)
    : message(message)
{}

std::string Error::What() {
    return message;
}