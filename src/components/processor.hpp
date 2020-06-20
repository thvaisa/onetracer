#ifndef PROCESSOR_H 
#define PROCESSOR_H

#include "ray_list.hpp"
#include "output_writer.hpp"
#include "input_reader.hpp"

class AbstractProcessor {
    public:
        virtual void initialize(InputReader& input) = 0; 
        virtual void process(RayList& ray_list) = 0; 
        virtual OutputList* process_output() = 0;
        virtual OutputList* generate_input_list() = 0;
};


#endif