#ifndef OUTPUTWRITER_H
#define OUTPUTWRITER_H

#include <utility>
#include <vector>
#include <string>

class OutputList{

    public:
        OutputList() = delete;
        OutputList(std::string&& name) : module_name{std::move(name)}, 
                                        info(std::vector<std::string>()), 
                                        input(std::vector<std::string>()){}


        OutputList(const char* const name) : module_name{std::string(name)}, 
                                        info(std::vector<std::string>()), 
                                        input(std::vector<std::string>()){}


        OutputList(std::string& name) : module_name{std::string(name)}, 
                                        info(std::vector<std::string>()), 
                                        input(std::vector<std::string>()){}


        ~OutputList(){};

        OutputList(const OutputList& other) : // copy constructor
                                        module_name{other.module_name}, 
                                        info(other.info), 
                                        input(other.input){}
        
  
        OutputList(OutputList&& other) noexcept : // move constructor
                                        module_name{std::move(other.module_name)}, 
                                        info(std::move(other.info)), 
                                        input(std::move(other.input)){}
        
 

        OutputList& operator=(const OutputList& other) // copy assignment
        {
            return *this = OutputList(other);
        }

        OutputList& operator=(OutputList&& other) noexcept // move assignment
        {
            std::swap(module_name, other.module_name);
            std::swap(info, other.info);
            std::swap(input, other.input);

            return *this;
        }

        void append_info(const std::string& info);

        void append_input(const std::string& name, 
                            const std::string& type, 
                            const std::string& value,
                            const std::string& description);

        std::string name() const{
            return module_name;
        }

        const std::vector<std::string>& get_info_lines(){
            return info;
        } 

        const std::vector<std::string>& get_input_lines(){
            return input;
        }


    private:
        std::string module_name;
        std::vector<std::string> info;
        std::vector<std::string> input;

};








class OutputWriter{

};



#endif