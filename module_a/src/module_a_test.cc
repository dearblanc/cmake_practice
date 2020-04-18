#include "gtest/gtest.h"
#include "module_a.h"

TEST(MODULE_A, GET)
{
    ModuleA a;
    ASSERT_STREQ("A", a.get());
}

int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}