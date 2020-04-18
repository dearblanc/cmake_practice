#include "gtest/gtest.h"
#include "module_b1.h"

TEST(MODULE_B1, GET) {
    ModuleB1 b1;
    ASSERT_STREQ("B1", b1.get());
}