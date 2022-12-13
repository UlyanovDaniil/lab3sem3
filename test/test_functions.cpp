#include "Functions.h"

#include <gtest.h>

TEST(TStack, can_create_postfix_1)
{
  ASSERT_NO_THROW(PlshRcrd("12+4"));
}

TEST(TStack, throws_when_create_postfix_1)
{
  ASSERT_ANY_THROW(PlshRcrd("12++4"));
}

TEST(TStack, can_create_postfix_2)
{
  ASSERT_NO_THROW(PlshRcrd("s+b-c"));
}

TEST(TStack, throws_when_create_postfix_2)
{
  ASSERT_ANY_THROW(PlshRcrd("s--3+6"));
}

TEST(TStack, can_create_postfix_3)
{
  ASSERT_NO_THROW(PlshRcrd("12-32-(13.2+32.2)"));
}

TEST(TStack, throws_when_create_postfix_3)
{
  ASSERT_ANY_THROW(PlshRcrd("((12-0.3)+3.32"));
}

TEST(TStack, can_get_result_postfix_1)
{
  ASSERT_NO_THROW(Postfix("12 11 +"));
}

TEST(TStack, throws_when_get_result_postfix_1)
{
  ASSERT_ANY_THROW(Postfix("12 11 - +"));
}

TEST(TStack, can_get_result_postfix_2)
{
  ASSERT_NO_THROW(Postfix("12 33.3 * 7 - 0.8 9 + /"));
}

TEST(TStack, throws_when_get_result_postfix_2)
{
  ASSERT_ANY_THROW(Postfix("12 + 33.3 * - 7 13.2 - 8 9 + /"));
}

TEST(TStack, priority_operations)
{
  EXPECT_EQ(0, Priority("2"));
  EXPECT_EQ(2, Priority("-"));
  EXPECT_EQ(4, Priority("^"));
  EXPECT_EQ(3, Priority("/"));
  EXPECT_EQ(1, Priority("("));
  EXPECT_EQ(0, Priority(")"));
}