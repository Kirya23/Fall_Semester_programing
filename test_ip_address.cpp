#include <gtest/gtest.h>

using namespace std;

TEST(Test,1){
    EXPECT_EQ(1, 1);
}
TEST(Test,2){
    EXPECT_EQ(2, 2);
}
TEST(Test,3){
    EXPECT_EQ(3, 3);
}
int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}