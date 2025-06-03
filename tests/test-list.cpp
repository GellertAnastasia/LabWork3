#include <gtest/gtest.h>
#include "list.h"

using namespace clist;

TEST(BasicOperationsTest, PushBack) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    auto it = list.begin();
    EXPECT_EQ(*it++, 1);
    EXPECT_EQ(*it++, 2);
    EXPECT_EQ(*it++, 3);
    EXPECT_EQ(it, list.end());
}

TEST(BasicOperationsTest, PushFront) {
    List<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    auto it = list.begin();
    EXPECT_EQ(*it++, 3);
    EXPECT_EQ(*it++, 2);
    EXPECT_EQ(*it++, 1);
    EXPECT_EQ(it, list.end());
}

TEST(BasicOperationsTest, PopBack) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.pop_back();
    auto it = list.begin();
    EXPECT_EQ(*it++, 10);
    EXPECT_EQ(*it++, 20);
    EXPECT_EQ(it, list.end());
    list.pop_back();
    it = list.begin();
    EXPECT_EQ(*it++, 10);
    EXPECT_EQ(it, list.end());
    list.pop_back();
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}

TEST(BasicOperationsTest, PopFront) {
    List<int> list;
    list.push_back(100);
    list.push_back(200);
    list.push_back(300);
    list.pop_front();
    auto it = list.begin();
    EXPECT_EQ(*it++, 200);
    EXPECT_EQ(*it++, 300);
    EXPECT_EQ(it, list.end());
    list.pop_front();
    it = list.begin();
    EXPECT_EQ(*it++, 300);
    EXPECT_EQ(it, list.end());
    list.pop_front();
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}

TEST(BasicOperationsTest, EmptyAndSize) {
    List<int> list;
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
    list.push_back(1);
    EXPECT_FALSE(list.empty());
    EXPECT_EQ(list.size(), 1);
    list.push_front(2);
    EXPECT_EQ(list.size(), 2);
    list.pop_back();
    EXPECT_EQ(list.size(), 1);
    list.pop_front();
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}

TEST(BasicOperationsTest, PopBackOnEmptyList) {
    List<int> list;
    EXPECT_THROW(list.pop_back(), std::underflow_error);
}

TEST(BasicOperationsTest, PopFrontOnEmptyList) {
    List<int> list;
    EXPECT_THROW(list.pop_front(), std::underflow_error);
}

TEST(ConstIteratorTest, ConstIterator) {
    clist::List<int> list;
    list.push_back(1);
    list.push_back(2);
    const clist::List<int>& const_list = list;
    auto it = const_list.cbegin();
    static_assert(std::is_const_v<std::remove_reference_t<decltype(*it)>>);
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
}

TEST(RangeBasedLoopTest, IteratesCorrectly) {
    clist::List<int> list;
    list.push_back(3);
    list.push_back(6);
    list.push_back(9);

    int expected[] = {3, 6, 9};
    int i = 0;
    for (int value : list) {
        EXPECT_EQ(value, expected[i++]);
    }
    EXPECT_EQ(i, 3);
}

TEST(RangeBasedLoopTest, ConstListRangeLoop) {
    clist::List<int> list;
    list.push_back(5);
    list.push_back(10);

    const clist::List<int>& const_list = list;
    int expected[] = {5, 10};
    int i = 0;

    for (const int& value : const_list) {
        EXPECT_EQ(value, expected[i++]);
    }
    EXPECT_EQ(i, 2);
}

TEST(ErrorHandlingTest, PopBackFromEmpty) {
    clist::List<int> list;
    EXPECT_THROW(list.pop_back(), std::underflow_error);
}

TEST(ErrorHandlingTest, PopFrontFromEmpty) {
    clist::List<int> list;
    EXPECT_THROW(list.pop_front(), std::underflow_error);
}

TEST(ErrorHandlingTest, ClearListDoesNotThrow) {
    clist::List<int> list;
    list.push_back(1);
    list.push_back(2);
    EXPECT_NO_THROW(list.clear());
    EXPECT_TRUE(list.empty());
}


