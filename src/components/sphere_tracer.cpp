#include "sphere_tracer.hpp"


//Find a way to read and output variables better
void SphereTracer::initialize(domain_code domain_code, InputReader& input){
    InputReader& reader = InputReader::get_instance();
    DomainCodeHandler &domain_codes =   DomainCodeHandler::get_instance();
    if(radiuses.find( domain_code ) == radiuses.end()){
        radiuses[domain_code] = default_radius;
    }
    radiuses[domain_code] = 
        reader.get_value(radiuses[domain_code], "domains",
            domain_codes.get_domain_name(domain_code), 
            name,"radius");
}


void SphereTracer::process(domain_code domain_code, 
                            RayList& ray_list){
    
    //for(auto it = ray_list.begin(); it != ray_list.end(); it++){
            
    //}




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
