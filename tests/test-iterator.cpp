#include <gtest/gtest.h>
#include <iterator>
#include <concepts>
#include "list.h"
using namespace clist;

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(IteratorTest, BeginEndForward) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    int expected[] = {10, 20, 30};
    int i = 0;
    for (auto it = list.begin(); it != list.end(); ++it) {
        EXPECT_EQ(*it, expected[i++]);
    }
    EXPECT_EQ(i, 3);
}

TEST(IteratorTest, BeginEndBackward) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    auto it = list.begin();
    ++it;
    ++it;
    --it;
    EXPECT_EQ(*it, 2);
    --it;
    EXPECT_EQ(*it, 1);
}

TEST(IteratorTest, ConstIterator) {
    List<int> list;
    list.push_back(5);
    list.push_back(10);

    const List<int>& const_list = list;
    auto it = const_list.cbegin();
    EXPECT_EQ(*it, 5);
    ++it;
    EXPECT_EQ(*it, 10);
}

TEST(IteratorTest, IteratorComparison) {
    List<int> list;
    list.push_back(100);
    list.push_back(200);
    auto it1 = list.begin();
    auto it2 = list.begin();
    EXPECT_TRUE(it1 == it2);
    ++it2;
    EXPECT_TRUE(it1 != it2);
}

TEST(IteratorTest, Dereference) {
    List<int> list;
    list.push_back(42);
    auto it = list.begin();
    EXPECT_NO_THROW({
        int value = *it;
        (void)value;
    });
}

TEST(IteratorTest, MultiplePostIncrements) {
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

TEST(IteratorTest, MultiplePostDecrements) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    auto it = list.begin();
    ++it; ++it;
    EXPECT_EQ(*it--, 30);
    EXPECT_EQ(*it--, 20);
    EXPECT_EQ(*it, 10);
}


static_assert(std::bidirectional_iterator<clist::iterator<int>>);
static_assert(std::bidirectional_iterator<clist::const_iterator<int>>);
