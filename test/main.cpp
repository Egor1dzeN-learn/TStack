//
// Created by egorm on 27.10.2023.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include<stack>
using namespace std;

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::InitGoogleMock(&argc, argv);

    return RUN_ALL_TESTS();
}
