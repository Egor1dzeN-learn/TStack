#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "TStack.h"
#include<vector>

using namespace std;
TEST(TestGroupName, can_create_TStack_1) {
    ASSERT_NO_THROW(TStack<int> stack);
}

TEST(TestGroupName, can_create_TStack_2) {
    ASSERT_NO_THROW(TStack<int> stack(12));
}

TEST(TestGroupName, can_create_TStack_3) {
    ASSERT_ANY_THROW(TStack<int> stack(-12));
}

TEST(TestGroupName, can_create_TStack_copy_constructor) {
    vector<int> v{1, 2, 3, 4, 5};
    TStack<int> stack(5);
    for (int i = 0; i < v.size(); ++i) {
        stack.push(v[i]);
    }
    TStack<int> stack1(stack);
    vector<int> v1(5);
    for (int i = v.size() - 1; i >= 0; --i) {
        int el = stack1.top();
        stack1.pop();
        v1[i] = el;
//        cout<<el<<" "<<i<<endl;

    }
    EXPECT_EQ(v, v1);
}

TEST(TestGroupName, test_get_size) {
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    TStack stack(v.size());
    for (int i = 0; i < v.size(); ++i) {
        stack.push(v[i]);
    }
    EXPECT_EQ(v.size(), stack.getSize());
}

TEST(TestGroupName, test_top_1) {
    TStack<int> stack(5);
    ASSERT_ANY_THROW(stack.top());
}

TEST(TestGroupName, test_top_2) {
    TStack<int> stack;
    stack.push(2);
    ASSERT_EQ(2, stack.top());
}

TEST(TestGroupName, test_top_3) {
    int size = 5;
    TStack<int> stack(size);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.top();
    ASSERT_EQ(size, stack.getSize());
}

TEST(TestGroupName, test_pop_1) {
    TStack<int> stack;
    stack.push(12);
    stack.pop();
    ASSERT_EQ(true, stack.isEmpty());
}

TEST(TestGroupName, test_pop_2) {
    TStack<int> stack;
    stack.push(12);
    int el = stack.pop();
    ASSERT_EQ(12, el);
}

TEST(TestGroupName, test_isEmpty_1) {
    TStack<int> stack;
    ASSERT_EQ(true, stack.isEmpty());
}

TEST(TestGroupName, test_push_1) {
    TStack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    ASSERT_EQ(5, stack.getSize());
}

TEST(TestGroupName, test_push_2) {
    TStack<int> stack(1);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    ASSERT_EQ(5, stack.getSize());
}

TEST(TestGroupName, test_operator_equal_1) {
    TStack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    TStack<int> stack1(stack);
//    cout<<stack1;
    ASSERT_EQ(true, stack == stack1);
}

TEST(TestGroupName, test_operator_equal_2) {
    TStack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    TStack<int> stack1(stack);
    stack.pop();
    stack1.pop();
//    cout<<stack1;
    ASSERT_EQ(true, stack == stack1);
}