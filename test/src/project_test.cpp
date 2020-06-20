#include <project.hpp>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <limits.h>

using ::testing::_;
using ::testing::ElementsAre;



class ProjectTest : public ::testing::Test{
    protected:

        const c_float inf = std::numeric_limits<c_float>::infinity();
        const c_float nan0 = std::numeric_limits<c_float>::quiet_NaN();

        virtual void SetUp() {
        };

        virtual void TearDown() {
        };

};


TEST_F(ProjectTest, Test_copy_arr) {
    c_float vec0[3] = {0,inf,inf};
    c_float vec1[3] = {0,0, nan0};
    c_float vec2[3] = {1,2,3};
    c_float vec3[3];
    EXPECT_DEBUG_DEATH(copy_arr<c_float>(vec3,vec0,3),"c");
    EXPECT_DEBUG_DEATH(copy_arr<c_float>(vec3,vec1,3),"c");
    copy_arr<c_float>(vec3,vec2,3);
    ASSERT_THAT(std::vector<c_float>(vec2, vec2+3), testing::ElementsAreArray(vec3,3));
}


TEST_F(ProjectTest, Test_dot_product) {
    c_float vec2[2] = {1.0,2.0};
    c_float sum = dot_product(vec2,vec2,2);
    EXPECT_EQ(vec2[0]*vec2[0]+vec2[1]*vec2[1],sum);

}


TEST_F(ProjectTest, Test_dot_product_diff) {
    c_float vec2[2] = {1,2};
    c_float vec3[2] = {2,3};

    c_float value = 0.0;
    for(std::size_t i = 0; i<2; i++){
        c_float tmp = (vec2[i]-vec3[i]);
        value = value+tmp*tmp;
    }

    EXPECT_EQ(value,dot_product_diff<c_float>(vec2,vec3,2));
}


TEST_F(ProjectTest, Test_normalized) {
    c_float vec2[2] = {1,2};
    EXPECT_FALSE(normalized<c_float>(vec2,2));

    c_float vec3[2] = {1,0};
    EXPECT_TRUE(normalized<c_float>(vec3,2));

    c_float vec4[2] = {1.0/sqrt(2.0),1.0/sqrt(2.0)};
    EXPECT_TRUE(normalized<c_float>(vec4,2));

    c_float vec5[3] = {1.0/sqrt(3.0),1.0/sqrt(3.0),1.0/sqrt(3.0)};
    EXPECT_TRUE(normalized<c_float>(vec5));

}


TEST_F(ProjectTest, Test_normalize) {
    c_float vec2[2] = {1,2};
    EXPECT_FALSE(normalized<c_float>(vec2,2));
    normalize<c_float>(vec2,2);
    EXPECT_TRUE(normalized<c_float>(vec2,2));
    
    c_float vec3[3] = {1.0,2.0,3.0};
    EXPECT_FALSE(normalized<c_float>(vec3));
    normalize<c_float>(vec3);
    EXPECT_TRUE(normalized<c_float>(vec3));
    
}


TEST_F(ProjectTest, Test_distance) {
    c_float vec2[2] = {1.0,2.0};
    c_float vec3[2] = {2.0,2.0};
    EXPECT_EQ(distance<c_float>(vec2,vec3,2),1.0);
    EXPECT_LT(distance<c_float>(vec2,vec3,2),2.0);
}



TEST_F(ProjectTest, Test_distance_within) {
    c_float vec2[2] = {1.0,2.0};
    c_float vec3[2] = {2.0,2.0};
    EXPECT_FALSE(distance_within<c_float>(vec2,vec3,2,0.5));
    EXPECT_TRUE(distance_within<c_float>(vec2,vec3,2,5.0));

    c_float vec4[3] = {1.0,2.0,3.9};
    c_float vec5[3] = {2.0,2.0,1.0};
    EXPECT_FALSE(distance_within<c_float>(vec4,vec5,2,0.5));
    EXPECT_TRUE(distance_within<c_float>(vec4,vec5,2,5.0));


}