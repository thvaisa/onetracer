#include "sphere_tracer.hpp"


//Find a way to read and output variables better
void SphereTracer::initialize(InputReader& input){
    //radius = input.read_input<c_float>("SphereTracer","radius", radius);
}


void SphereTracer::process(RayList& ray_list){

}


OutputList* SphereTracer::process_output(){
    return nullptr;
}


OutputList* SphereTracer::generate_input_list(){
    //OutputList* outputList = new OutputList(std::string("SphereTracer"));
    //outputList.append_info(std::string("Centered sphere"));
    //outputList.append_input(std::string("radius"), typeid(i).name(), std::string(radius),std::string("Radius of the sphere"));
    //return outputList;
    return nullptr;
}
