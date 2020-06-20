 
#ifndef DOMAINHANDLER_H
#define DOMAINHANDLER_H

#include <map>
#include <string>

#include "project.hpp"
#include <boost/log/trivial.hpp>
#include "boost/log/utility/setup.hpp"

//Singleton
//https://stackoverflow.com/questions/1008019/c-singleton-design-pattern
//TOdo add 
class DomainCodeHandler{

    public:
        static DomainCodeHandler& get_instance()
        {
            static DomainCodeHandler instance;  // Guaranteed to be destroyed.
                                                // Instantiated on first use.
            return instance;
        }

        DomainCodeHandler(DomainCodeHandler const&)     = delete;
        void operator=(DomainCodeHandler const&)  = delete;


        bool register_domain(std::string name);
        bool registered(std::string name);
        bool valid_code(domain_code code);
        std::string get_domain_name(domain_code code);

        static std::string const NULLCODE;

    private:
        DomainCodeHandler() : 
            domain_codes(std::map<domain_code, std::string>()) {}  

        std::map<domain_code, std::string> domain_codes; 
        std::size_t code_counter = 0;
        
};





#endif