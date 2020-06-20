#include <project.hpp>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <limits>
#include "output_writer.hpp"

using ::testing::_;
using ::testing::ElementsAre;
using ::testing::Gt;
using ::testing::ExitedWithCode;

class OutputListTest : public ::testing::Test{
    protected:
        OutputList* _output_list;
        
        virtual void SetUp() {
            _output_list = new OutputList("test");
        };

        virtual void TearDown() {
            delete _output_list;
            _output_list = nullptr;
        };


};


TEST_F(OutputListTest, Test_constructor) {
    EXPECT_EQ(_output_list->name(), std::string("test"));
    delete _output_list;
    OutputList* _output_list = new OutputList(std::string("test2"));
    EXPECT_EQ(_output_list->name(), std::string("test2"));
    EXPECT_EQ(_output_list->get_info_lines().size(),0);
    EXPECT_EQ(_output_list->get_input_lines().size(),0);
}



TEST_F(OutputListTest, Test_appends_info) {
    std::string testStr = std::string("massive rain fall from Esteri");
    _output_list->append_info(std::string("marsu"));
    _output_list->append_info(testStr);
    
    EXPECT_EQ(_output_list->get_info_lines().size(),2);
    EXPECT_EQ(_output_list->get_info_lines()[1],testStr);
    EXPECT_EQ(_output_list->get_info_lines()[0],std::string("marsu"));
}



TEST_F(OutputListTest, Test_appends_inputs) {
    std::string testStr = std::string("massive rain fall from Esteri");
    int a = 1;
    std::string fname = "IM/FNAME";
    _output_list->append_input(std::string("a"),typeid(a).name(),
                            std::to_string(a),std::string("this is variable"));
    _output_list->append_input(std::string("fname"),typeid(fname).name(),
                                fname,std::string("this is variable 2"));
    

    EXPECT_EQ(_output_list->get_input_lines().size(),2);
    //TODO: add testing to ouput
}



