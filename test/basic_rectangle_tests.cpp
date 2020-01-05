//
// Created by Greg on 1/21/2019.
//

#include "gtest/gtest.h"
#include "Rectangle.h"

TEST(constructor, test_width) {
    Rectangle r(5,10);
    ASSERT_EQ(r.getWidth(), 5);
}

TEST(constructor, test_length) {
    Rectangle r(5,10);
    ASSERT_EQ(r.getLength(), 10);
}

TEST(constructor, test_default) {
    Rectangle r;
    EXPECT_EQ(r.getWidth(), 0);
    EXPECT_EQ(r.getLength(), 0);
}

TEST(area, test_area) {
    Rectangle r(5,10);
    ASSERT_EQ(r.area(), 50);
}