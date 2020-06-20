#include "domain_code_handler.hpp"

const std::string DomainCodeHandler::NULLCODE = "NULLCODE";

bool DomainCodeHandler::register_domain(const std::string& name){
    if(registered(name)){
        BOOST_LOG_TRIVIAL(warning) << 
            "Trying to register multiple domains with name: "
                                << name;
        return false;
    }
    domain_codes[code_counter] = name;
    return true;
}

bool DomainCodeHandler::registered(const std::string& name){
    for(auto iter = domain_codes.begin(); iter != domain_codes.end(); ++iter){
        if(iter->second == name){
            return true;
        }
    }
    return false;
}

bool DomainCodeHandler::valid_code(domain_code code){
    return (domain_codes.find(code) != domain_codes.end());
}

std::string DomainCodeHandler::get_domain_name(domain_code code){
    if(!valid_code(code)){
        BOOST_LOG_TRIVIAL(error) << 
            "Trying to access nonregistered domain: ";
        return DomainCodeHandler::NULLCODE;
    }
    return domain_codes[code];
}

