//
// Created by TigerZhao on 2020-09-14.
//


#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../StandardCalc.h"

using testing::Eq;

namespace {
class ClassDeclaration : public testing::Test {
 public:
  StandardCalc obj;
};
}

TEST_F(ClassDeclaration, BoundTo180Test) {
  //given tests
  ASSERT_FLOAT_EQ(obj.BoundTo180(360), 0);
  ASSERT_FLOAT_EQ(obj.BoundTo180(270), -90);
  ASSERT_FLOAT_EQ(obj.BoundTo180(-450), -90);

  //angle within 180
  ASSERT_FLOAT_EQ(obj.BoundTo180(5), 5);

  //angle with decimals
  ASSERT_FLOAT_EQ(obj.BoundTo180(55.5312), 55.5312);

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

TEST_F(ClassDeclaration, IsAngleBetweenTest) {
  //given tests
  ASSERT_TRUE(obj.IsAngleBetween(-90, -180, 110));
  ASSERT_FALSE(obj.IsAngleBetween(-90, -180, 80));

}