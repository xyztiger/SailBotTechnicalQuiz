//
// Created by TigerZhao on 2020-09-14.
//


#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "StandardCalc.h"

using testing::Eq;

namespace {
 class ClassDeclaration : public testing::Test {
  public:
   StandardCalc obj;
   ClassDeclaration(){
     obj;
   }
 };
}

TEST_F(ClassDeclaration, nameOfTest1){
  ASSERT_EQ("","");
}

TEST_F(ClassDeclaration, nameOfTest2){
  ASSERT_EQ("", "1");
}