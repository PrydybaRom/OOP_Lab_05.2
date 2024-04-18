#pragma once
#include <string>

class Error
{
    std::string message;
public:
    Error(std::string message);
    std::string What();
};

