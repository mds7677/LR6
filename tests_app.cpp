#include "../gtest/gtest.h"
#include <sstream>
#include "../tasks/tasks.cpp"
#include <string>

TEST(Task3Validation, CalculateAverageLength) {
    task_1 task;
    char str[5] = {10101};
    int result = task.countOnesInOddGroups(str);
    EXPECT_EQ(3, result);
}



int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}