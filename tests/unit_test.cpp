#include "gtest/gtest.h"

TEST(test1, ex1) {
  EXPECT_EQ("hello", "hello");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}