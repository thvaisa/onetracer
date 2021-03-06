#include "output_writer.hpp"

//Appends list of string with info line
void OutputList::append_info(const std::string& info){
    this->info.push_back(info);
}

//Appends input list with single row
//TODO: CHANGE Formatting
void OutputList::append_input(const std::string& name, 
                    const std::string& type, 
                    const std::string& value,
                    const std::string& description){
    std::string space = std::string(" ");
    this->input.push_back(name+space+type+space+value+space+description);
}