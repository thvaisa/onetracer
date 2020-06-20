#ifndef SPHERE_TRACER_H 
#define SPHERE_TRACER_H

#include "processor.hpp"
#include "input_reader.hpp"
#include "ray_list.hpp"
#include "project.hpp"

class SphereTracer : public AbstractProcessor{
    public:
        void initialize(InputReader& input);
        void process(RayList& ray_list);
        OutputList* process_output();
        OutputList* generate_input_list();
    private:
        c_float radius = 5.0;
};


#endif