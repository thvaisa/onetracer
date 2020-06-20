#ifndef PROJECT_H
#define PROJECT_H

#include <cstdint>
#include <cstring>
#include <cassert>
#include <cmath>
#include <limits>
#include <math.h> 

typedef double c_float;
typedef int c_int;
typedef std::size_t face_identifier;
typedef std::size_t material_indx;
typedef std::size_t domain_code;


#define assertm(exp, msg) assert(((void)msg, exp))
#define EPSILON std::numeric_limits<T>::epsilon()*10

//Ray will have 4 statuses that it can. 
enum RAYSTATUS {TRACE, SURF_SCATTER, VOL_SCATTER, ESCAPE, DEAD, RAW};

template <typename T>
inline void copy_arr(T* const arr_to, const T* const arr_from, std::size_t n){
    #ifndef NDEBUG
        for(std::size_t i=0; i<n; i++){
            assertm(!std::isnan(arr_from[i]), "NaN was passed");
            assertm(!std::isinf(arr_from[i]), "inf was passed");
        } 
    #endif
    std::memcpy(arr_to, arr_from, sizeof(arr_from[0])*n);
}


//Change later

template <typename T>
inline T dot_product(const T* arr1, const T* arr2, std::size_t n){
    T sum = 0;
    for(std::size_t i=0; i<n; ++i){
        sum = sum+arr1[i]*arr2[i];
    }
    return sum;
}

template <typename T>
inline T dot_product_diff(const T* arr1, const T* arr2, std::size_t n){
    T sum = 0;
    for(std::size_t i=0; i<n; ++i){
        sum = sum+(arr1[i]-arr2[i])*(arr1[i]-arr2[i]);
    }
    return sum;
}

template <typename T>
inline bool normalized(const T* arr1, std::size_t n){
    T sum = dot_product(arr1,arr1, n);
    assertm(!std::isnan(sum), "NaN occurred");
    assertm(!std::isinf(sum), "inf occurred");
    return (sum >= 1.0-EPSILON && sum <= 1.0+EPSILON);
}

template <typename T>
inline bool normalized(const T* arr1){
    return normalized(arr1, 3);

}


template <typename T>
inline void normalize(T* arr1, std::size_t n){
    T sum = sqrt(dot_product(arr1,arr1,n));

    for(std::size_t i=0; i<n; ++i){
        arr1[i] = arr1[i]/sum;
    }

    assertm(normalized(arr1,n), "not normalized: ");
}


template <typename T>
inline void normalize(T* arr1){
    normalize(arr1,3);
}


template <typename T>
inline T distance(const T* arr1, const T* arr2, std::size_t n){
    return sqrt(dot_product_diff(arr1,arr2, n));
}

template <typename T>
inline T distance(const T* arr1, const T* arr2){
    return distance(arr1,arr2, 3);
}


template <typename T>
inline bool distance_within(const T* arr1, const T* arr2, std::size_t n, T distance){
    return (dot_product_diff(arr1,arr2, n)<=std::pow(distance,2));
}

template <typename T>
inline bool distance_within(const T* arr1, const T* arr2, T distance){
    return distance_within(arr1, arr2, 3, distance);
}

#endif
