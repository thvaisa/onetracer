#ifndef RAY_H
#define RAY_H

#include "project.hpp"
#include <cmath>


//The most simplest implementation of the ray
class Ray{

    public:
        Ray(){}
        Ray(const c_float* X,
                const c_float* N,
                const c_float step_size,
                const material_indx mat_indx,
                const RAYSTATUS ray_status,
                const face_identifier face_id){
            copy_values(X,N,step_size,mat_indx,ray_status, face_id);
        }

        ~Ray(){};

        Ray(const Ray& other) // copy constructor
        : Ray(other.X(), other.N(), other.step_size(), other.mat_indx(), other.ray_status(), other.face_id())
        {}

        Ray(Ray&& other) noexcept // move constructor
        {
            Ray(other.X(), other.N(), other.step_size(), other.mat_indx(), other.ray_status(), other.face_id());
        }
 
        Ray& operator=(const Ray& other) // copy assignment
        {
            return *this = Ray(other);
        }

        //stupid but later more stuff when PhysicsRay will be included
        Ray& operator=(Ray&& other) noexcept // move assignment
        {
            copy_values(other.X(), other.N(), other.step_size(), 
                        other.mat_indx(), other.ray_status(), other.face_id());
            return *this;
        }

        const c_float* const X() const{
            return _X;
        }

        const c_float* const N() const{
            return _N;
        }

        const c_float step_size() const{
            return _step_size;
        }

        const material_indx mat_indx() const{
            return _mat_indx;
        }

        const RAYSTATUS ray_status() const{
            return _ray_status;
        } 

        const face_identifier face_id() const{
            return _face_id;
        } 

        inline void take_step(){
            for(std::size_t i=0; i<3; i++){
                _X[i] = _X[i]+_N[i]*_step_size;
                assertm(!std::isnan(_X[i]), "for some reason take_step got nan");
            }
        }

        inline void get_next_step(c_float * const X_next) const{
            for(std::size_t i=0; i<3; i++){
                X_next[i] = _X[i]+_N[i]*_step_size;
                assertm(!std::isnan(X_next[i]), "for some reason get_next_step got nan");
            }
        }

        void set_X(const c_float * const X){
            copy_arr(this->_X, X, 3);
        }

        void set_N(const c_float * const N){

            copy_arr(this->_N, N, 3);
        }

        void set_face_identifier(const c_float& face_id){
            this->_face_id;
        }

        void set_ray_status(const RAYSTATUS& ray_status){
            this->_ray_status = ray_status;
        } 

        void set_step_size(const c_float& step_size){
            assertm(step_size >= 0, "Step size must be positive");
            assertm(!std::isnan(step_size), "nan was passed");
            assertm(!std::isinf(step_size), "inf was passed");
            this->_step_size = step_size;
        }

        void set_material_indx(const material_indx& mat_indx){
            this->_mat_indx = mat_indx;
        }



    private:

        //TODO: Change later to place where tracer can access easier
        c_float _X[3];                  //position
        c_float _N[3];                  //direction

        c_float _step_size;             //step size
        material_indx _mat_indx;         //material index
        RAYSTATUS _ray_status = RAYSTATUS::RAW;
        face_identifier _face_id; 

        void copy_values(const c_float* X,
                const c_float* N,
                const c_float step_size,
                const c_int mat_indx,
                const RAYSTATUS ray_status,
                const face_identifier face_id){
            copy_arr <c_float> (this->_X, X, 3);
            copy_arr <c_float> (this->_N, N, 3);
            this->_step_size = step_size;
            this->_mat_indx = mat_indx;
            this->_ray_status = ray_status;
            this->_face_id = face_id;
        }
};


#endif
