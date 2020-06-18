#ifndef PROJECT_H
#define PROJECT_H

#include <cstdint>
#include <cstring>
#include <cassert>
#include <cmath>

typedef double c_float;
typedef int c_int;
typedef std::size_t face_identifier;
typedef std::size_t material_indx;

#define assertm(exp, msg) assert(((void)msg, exp))

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


#endif
