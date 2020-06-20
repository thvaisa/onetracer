#include "input_reader.hpp"


bool InputReader::read_arg_file(const std::string& fname){
    if(!boost::filesystem::exists(fname)) return false;
    std::ifstream input_stream(fname.c_str());;
    try{
        input_stream >> data;
    }catch (std::exception& e){
        BOOST_LOG_TRIVIAL(error) << "Check input: " << fname;
        BOOST_LOG_TRIVIAL(error) << "Message: " << e.what();
        input_stream.close();
        return false;
    }
    input_stream.close();
    return true;
}