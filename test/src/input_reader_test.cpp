#include <project.hpp>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "input_reader.hpp"

using ::testing::_;
using ::testing::ElementsAre;
using ::testing::Gt;
using ::testing::ExitedWithCode;


class InputReaderTest : public ::testing::Test{
    protected:

        virtual void SetUp() {
        };

        virtual void TearDown() {
        };

};


TEST_F(InputReaderTest, Test_singleton) {
    InputReader& s1 = InputReader::get_instance();
    InputReader& s2 = InputReader::get_instance();
    EXPECT_EQ(&s1, &s2);
}


TEST_F(InputReaderTest, Test_file_reading) {
    InputReader& s1 = InputReader::get_instance();
    
    EXPECT_EQ(false, s1.read_arg_file(std::string("I- do not exists")));
    EXPECT_EQ(false, s1.read_arg_file(std::string("../data/empty.json")));

    EXPECT_EQ(true, s1.read_arg_file(std::string("../data/test.json")));

    //InputReader& s1 = InputReader::get_instance();
    s1.get_value(5.0,"asd","eee");
    s1.get_value(5.0,"test","ImInteger");
}