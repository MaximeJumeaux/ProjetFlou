#include <gtest/gtest.h>
#include "../../src/core/UnaryExpressionModel.h"
#include "../../src/core/ValueModel.h"
#include "../../src/fuzzy/IsTriangle.h"

using namespace fuzzy;

TEST(UnaryExpressionModel,evaluate){

    core::ValueModel<float> food(8);
    core::ValueModel<float> service(3);

    IsTriangle<float> excellent(7.f,8.f,10.f);
    IsTriangle<float> bad(0.f,2.f,4.f);

    core::UnaryExpressionModel<float> left(&food,&excellent);
    core::UnaryExpressionModel<float> right(&service,&bad);
    ASSERT_EQ(left.evaluate(), 1.f);
    ASSERT_EQ(right.evaluate(),0.5f);
}