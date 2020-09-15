//
// Created by TigerZhao on 2020-09-14.
//


#include <gtest/gtest.h>
#include "../StandardCalc.h"

using testing::Eq;

namespace {
class ClassDeclaration : public testing::Test {
 public:
  StandardCalc obj;
};
}

//tests for BoundTo180
TEST_F(ClassDeclaration, BoundTo180Test) {
  //given tests
  ASSERT_FLOAT_EQ(obj.BoundTo180(360), 0);
  ASSERT_FLOAT_EQ(obj.BoundTo180(270), -90);
  ASSERT_FLOAT_EQ(obj.BoundTo180(-450), -90);

  //angle within 180
  ASSERT_FLOAT_EQ(obj.BoundTo180(5), 5);

  //angle with decimals
  ASSERT_FLOAT_EQ(obj.BoundTo180(55.5312), 55.5312);
  ASSERT_FLOAT_EQ(obj.BoundTo180(-450.123), -90.123);

  //angle equal to 180
  ASSERT_FLOAT_EQ(obj.BoundTo180(180), -180);

  //angle between 180 and 360; should be converted to negative
  ASSERT_FLOAT_EQ(obj.BoundTo180(190), -170);
  ASSERT_FLOAT_EQ(obj.BoundTo180(300), -60);

  //angle in QI or QII with absolute value greater than 180
  ASSERT_FLOAT_EQ(obj.BoundTo180(370), 10);
  ASSERT_FLOAT_EQ(obj.BoundTo180(480), 120);
  ASSERT_FLOAT_EQ(obj.BoundTo180(-350), 10);
  ASSERT_FLOAT_EQ(obj.BoundTo180(-200), 160);

  //angle equal to 540; should be negative and not positive
  ASSERT_FLOAT_EQ(obj.BoundTo180(540), -180);

  //angle in QIII or QIV with absolute value greater than 360
  ASSERT_FLOAT_EQ(obj.BoundTo180(590), -130);
  ASSERT_FLOAT_EQ(obj.BoundTo180(700), -20);
  ASSERT_FLOAT_EQ(obj.BoundTo180(-400), -40);
  ASSERT_FLOAT_EQ(obj.BoundTo180(-480), -120);
}

//tests for IsAngleBetween; input angles are assumed to be bounded to [-180, 180) as per the note in the declaration
TEST_F(ClassDeclaration, IsAngleBetweenTest) {
  //given tests
  ASSERT_TRUE(obj.IsAngleBetween(-90, -180, 110));
  ASSERT_FALSE(obj.IsAngleBetween(-90, -180, 80));

  //angles with decimals
  ASSERT_TRUE(obj.IsAngleBetween(-90.5, -179.34, 110.312));
  ASSERT_FALSE(obj.IsAngleBetween(-90.5, -179.34, 80.842));

  //middle angle equal to bounding angle
  ASSERT_FALSE(obj.IsAngleBetween(100, 100, 120));
  ASSERT_FALSE(obj.IsAngleBetween(-50, -60, -60));
  ASSERT_FALSE(obj.IsAngleBetween(120.21, 100.3, 100.3));

  //bounding angles are the same
  ASSERT_FALSE(obj.IsAngleBetween(10, 10, 10));
  ASSERT_FALSE(obj.IsAngleBetween(-50, -60, -50));

  //bounding angles both positive
  ASSERT_TRUE(obj.IsAngleBetween(10, 50, 80));
  ASSERT_TRUE(obj.IsAngleBetween(170, 60, 20));
  ASSERT_TRUE(obj.IsAngleBetween(30, 170, 175));
  ASSERT_FALSE(obj.IsAngleBetween(10, 100, 80));
  ASSERT_FALSE(obj.IsAngleBetween(170, 175, 10));

  //bounding angles both negative
  ASSERT_TRUE(obj.IsAngleBetween(-10, -50, -80));
  ASSERT_TRUE(obj.IsAngleBetween(-170, -60, -20));
  ASSERT_TRUE(obj.IsAngleBetween(-30, -170, -175));
  ASSERT_FALSE(obj.IsAngleBetween(-10, -100, -80));
  ASSERT_FALSE(obj.IsAngleBetween(-170, -175, -10));

  //one positive bounding angle, one bounding angle negative
  ASSERT_TRUE(obj.IsAngleBetween(-10, 50, 80));
  ASSERT_TRUE(obj.IsAngleBetween(170, -60, -20));
  ASSERT_TRUE(obj.IsAngleBetween(-170, -180, 50));
  ASSERT_TRUE(obj.IsAngleBetween(-170, 170, 100));
  ASSERT_FALSE(obj.IsAngleBetween(-10, 100, 80));
  ASSERT_FALSE(obj.IsAngleBetween(170, -10, -20));
  ASSERT_FALSE(obj.IsAngleBetween(-170, -100, 50));
  ASSERT_FALSE(obj.IsAngleBetween(-170, 10, 100));
}