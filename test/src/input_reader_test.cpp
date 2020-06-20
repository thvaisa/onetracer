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
    
    EXPECT_FALSE(s1.read_arg_file(std::string("I- do not exists")));
    EXPECT_FALSE(s1.read_arg_file(std::string("../data/empty.json")));

    EXPECT_TRUE(s1.read_arg_file(std::string("../data/test.json")));

    InputReader& s2 = InputReader::get_instance();
    c_int original_int = 5;
    c_int test_int = original_int;
    test_int = s1.get_value(test_int,"asd","eee");
    EXPECT_EQ(original_int, test_int);
    test_int = s1.get_value(test_int,"test","ImInteger");
    EXPECT_EQ(1, test_int);

    c_float original_float = 3.5;
    c_float test_float = original_float;
    test_float = s1.get_value(test_float,"asd","eee");
    EXPECT_EQ(test_float, original_float);
    test_float = s1.get_value(test_float,"test","ImFloat");
    EXPECT_EQ(test_float,5.1);

    std::string original_string = "pekoni";
    std::string test_string = original_string;
    test_string = s1.get_value(test_string,"test","title");
    EXPECT_EQ(test_string,"example glossary");

}