#include <ray.hpp>
#include <project.hpp>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <limits>


using ::testing::_;
using ::testing::ElementsAre;
using ::testing::Gt;
using ::testing::ExitedWithCode;

const c_float X[3] = {1.0, 2.0, 3.0};
const c_float K[3] = {1/sqrt(3.0),1/sqrt(3.0),1/sqrt(3.0)};
const c_float N[3] = {1/sqrt(2.0),0.0,1/sqrt(2.0)};
const c_float step_size = 10.0;
const material_indx mat_indx = 11;
const RAYSTATUS ray_status = RAYSTATUS::DEAD;
const face_identifier face_id = 12;

const c_float inf = std::numeric_limits<c_float>::infinity();
const c_float nan0 = std::numeric_limits<c_float>::quiet_NaN();

class RayTest : public ::testing::Test{
    protected:
        Ray* _ray;
        
        virtual void SetUp() {
            _ray = new Ray(X,K,N,step_size,mat_indx,ray_status,face_id);
        };

        virtual void TearDown() {
            delete _ray;
            _ray = nullptr;
        };

        void verify(Ray* ray, bool check_X = true, bool check_K = true, bool check_N = true){
            EXPECT_EQ(step_size, ray->step_size());
            EXPECT_EQ(mat_indx, ray->mat_indx());
            EXPECT_EQ(ray_status, ray->ray_status());
            EXPECT_EQ(face_id, ray->face_id());

            if(check_X) ASSERT_THAT(std::vector<c_float>(ray->X(), 
                        ray->X()+3), testing::ElementsAreArray(X,3));
            if(check_K) ASSERT_THAT(std::vector<c_float>(ray->K(), 
                        ray->K()+3), testing::ElementsAreArray(K,3));
            if(check_N) ASSERT_THAT(std::vector<c_float>(ray->N(), 
                        ray->N()+3), testing::ElementsAreArray(N,3));
        }
};



TEST_F(RayTest, Test_Constructor) {
    verify(_ray);
    delete _ray;
    _ray = new Ray();
    EXPECT_EQ(RAYSTATUS::RAW, _ray->ray_status());
}


TEST_F(RayTest, Test_Setters) {
    delete _ray;
    _ray = new Ray();

    _ray->set_X(X);
    _ray->set_K(K);
    _ray->set_N(N);
    _ray->set_face_identifier(face_id);
    _ray->set_ray_status(ray_status);
    _ray->set_step_size(step_size);
    _ray->set_material_indx(mat_indx);
    verify(_ray);  
}


TEST_F(RayTest, Test_steps) {
    c_float vec0[3];
    c_float vec1[3] = {X[0]+K[0]*step_size,X[1]+K[1]*step_size,X[2]+K[2]*step_size};
    _ray->get_next_step(vec0);
    ASSERT_THAT(std::vector<c_float>(vec0, vec0+3), testing::ElementsAreArray(vec1,3));
    verify(_ray);
    _ray->take_step();
    ASSERT_THAT(std::vector<c_float>(_ray->X(), _ray->X()+3), testing::ElementsAreArray(vec1,3));
    verify(_ray,false,true);
}



TEST_F(RayTest, Test_problems) {
    EXPECT_DEBUG_DEATH(_ray->set_step_size(-1.0),"c");
    EXPECT_DEBUG_DEATH(_ray->set_step_size(inf),"c");
    c_float vec0[3] = {0,inf,inf};
    c_float vec1[3] = {0,0,nan0};
    EXPECT_DEBUG_DEATH(_ray->set_X(vec0),"c");
    EXPECT_DEBUG_DEATH(_ray->set_X(vec1),"c");
    EXPECT_DEBUG_DEATH(_ray->set_K(vec0),"c");
    EXPECT_DEBUG_DEATH(_ray->set_K(vec1),"c");
    EXPECT_DEBUG_DEATH(_ray->set_N(vec0),"c");
    EXPECT_DEBUG_DEATH(_ray->set_N(vec1),"c");

}
