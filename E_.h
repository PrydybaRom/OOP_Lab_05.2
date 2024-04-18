#pragma once
#include <exception>
#include <string>

class E : public std::exception
{
    std::string message;
public:
    E(std::string message);
    std::string What();
};

