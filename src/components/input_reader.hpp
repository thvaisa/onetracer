#ifndef INPUTREADER_H
#define INPUTREADER_H

#include <nlohmann/json.hpp>
#include <boost/filesystem.hpp>
#include <boost/log/trivial.hpp>
#include "boost/log/utility/setup.hpp"
#include <fstream>
#include <exception>
#include <string>
#include <sstream>
#include <iostream>

//Singleton
//https://stackoverflow.com/questions/1008019/c-singleton-design-pattern
//TOdo add 
class InputReader{

    public:
        static InputReader& get_instance()
        {
            static InputReader instance;    // Guaranteed to be destroyed.
                                            // Instantiated on first use.
            return instance;
        }

        InputReader(InputReader const&)     = delete;
        void operator=(InputReader const&)  = delete;

        bool read_arg_file(const std::string& fname);


        template<typename T, typename ... Args>
        T get_value(T default_value, Args ...args){
            std::cout << data["test"]["ImInteger"] << " " 
               << data["test","ImInteger"] << std::endl;
            std::stringstream path;
            path << '/';
            ((path << args << '/'), ...);
            std::string str = path.str();
            str.pop_back();
            try{
                return data[nlohmann::json::json_pointer(str)];
            }catch (std::exception& e){
                BOOST_LOG_TRIVIAL(warning) << "Could not read path";
                BOOST_LOG_TRIVIAL(warning) << str;
                BOOST_LOG_TRIVIAL(warning) << "Using default value: " << default_value;
                return default_value;
            }
        }



    private:
        InputReader() {
            data = nlohmann::json();
        }   
        nlohmann::json data;


};





#endif