#ifndef SPHERE_TRACER_H 
#define SPHERE_TRACER_H

#include "processor.hpp"
#include "input_reader.hpp"
#include "ray_list.hpp"
#include "project.hpp"
#include <map>
#include "domain_code_handler.hpp"

class SphereTracer : public AbstractProcessor{
    public:
        SphereTracer() : radiuses(std::map<domain_code,c_float>()){}
        void initialize(domain_code domain_code, InputReader& input);
        void process(domain_code domain_code,
                        RayList& ray_list);
        OutputList* process_output();
        OutputList* generate_input_list();
    private:
        c_float default_radius = 5.0;
        std::string name = "SphereTracer";
        std::map<domain_code, c_float> radiuses;
};


#endif