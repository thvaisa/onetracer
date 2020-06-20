#include <ray.hpp>
#include <ray_list.hpp>
#include <project.hpp>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <limits>


using ::testing::_;
using ::testing::ElementsAre;
using ::testing::Gt;
using ::testing::ExitedWithCode;

class RayListTest : public ::testing::Test{
    protected:
        RayList* _ray_list;
        
        virtual void SetUp() {
            _ray_list = new RayList();
        };

        virtual void TearDown() {
            delete _ray_list;
            _ray_list = nullptr;
        };
};



TEST_F(RayListTest, Test_adding_ray) {
    EXPECT_EQ(0,_ray_list->get_size());
    Ray* ray0 = _ray_list->get_new_ray();
    EXPECT_EQ(1,_ray_list->get_size());
    for(int i = 0; i<30; ++i){
        Ray* ray1  = _ray_list->get_new_ray();
    }
    EXPECT_EQ(31,_ray_list->get_size());
}

TEST_F(RayListTest, Test_iterator_change_read) {
    for(int i = 0; i<30; ++i){
        _ray_list->get_new_ray();
    }


    c_int test = 0;
    for(auto it = _ray_list->begin(); it!= _ray_list->end(); ++it){
        Ray& ray = *it;
        EXPECT_EQ(ray.ray_status(), RAYSTATUS::RAW);
        ray.set_ray_status(RAYSTATUS::ESCAPE);
        double X[3] = {test+1.0,test+2.0,test+3.0};
        double N[3] = {test*10.0+1.0,test*10.0+2.0,test*10.0+3.0};
        ray.set_X(X);
        ray.set_N(N);
        test++;
    }

    test = 0;
    for(auto it = _ray_list->begin(); it!= _ray_list->end(); ++it){
        Ray& ray = *it;
        EXPECT_EQ(ray.ray_status(), RAYSTATUS::ESCAPE);
        double X[3] = {test+1.0,test+2.0,test+3.0};
        double N[3] = {test*10.0+1.0,test*10.0+2.0,test*10.0+3.0};
        ASSERT_THAT(std::vector<c_float>(ray.X(), ray.X()+3), testing::ElementsAreArray(X,3));
        ASSERT_THAT(std::vector<c_float>(ray.N(), ray.N()+3), testing::ElementsAreArray(N,3));
        test++;
    }
}

TEST_F(RayListTest, Test_empty_iterator) {
    c_int test = 0;
    for(auto it = _ray_list->begin(); it!= _ray_list->end(); ++it){
    }

    EXPECT_EQ(test, 0);
}


TEST_F(RayListTest, Test_iterator_dead_rays) {
    for(int i = 0; i<30; ++i){
        _ray_list->get_new_ray();
    }

    c_int test = 0;
    for(auto it = _ray_list->begin(); it!= _ray_list->end(); ++it, ++test){
        Ray& ray = *it;
        if(test>=10 && test<20) ray.set_ray_status(RAYSTATUS::DEAD);
    }

    test = 0;
    for(auto it = _ray_list->begin(); it!= _ray_list->end(); ++it, ++test){
        Ray& ray = *it;
         EXPECT_EQ(ray.ray_status(), RAYSTATUS::RAW);
    }

    EXPECT_EQ(test,20);
}


TEST_F(RayListTest, Test_iterator_dead_rays_2) {
    for(int i = 0; i<30; ++i){
        _ray_list->get_new_ray();
    }

    c_int test = 0;
    for(auto it = _ray_list->begin(); it!= _ray_list->end(); ++it, test++){
        Ray& ray = *it;
        if(test>=10) ray.set_ray_status(RAYSTATUS::DEAD);
    }

    test = 0;
    for(auto it = _ray_list->begin(); it!= _ray_list->end(); ++it, ++test){
        Ray& ray = *it;
        EXPECT_EQ(ray.ray_status(), RAYSTATUS::RAW);
    }

    EXPECT_EQ(test,10);
}
