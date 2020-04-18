#include <string>
#include <module_a.hpp>
#include <module_b1.h>
#include <module_b2.h>

class Echo
{
public:
  void operator()();
  void operator()(const std::string &input);

private:
  ModuleA a_;
  ModuleB1 b1_;
  ModuleB2 b2_;
};