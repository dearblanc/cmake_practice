#include "echo.h"

#include <iostream>

void Echo::operator()()
{
  std::cout << a_.get() << std::endl;
  std::cout << b1_.get() << std::endl;
  std::cout << b2_.get() << std::endl;
}

void Echo::operator()(const std::string &input) { std::cout << input << std::endl; }