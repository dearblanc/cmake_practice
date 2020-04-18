#include "gtest/gtest.h"
#include "module_b2.h"

TEST(MODULE_B2, GET) {
    ModuleB2 b2;
    ASSERT_STREQ("B2", b2.get());
}