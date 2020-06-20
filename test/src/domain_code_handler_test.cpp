#include "project.hpp"
#include "gtest/gtest.h"
#include "domain_code_handler.hpp"


class DomainCodeHandlerTest : public ::testing::Test{
    protected:  
        std::string test_name = "test_domain";

        virtual void SetUp() {
        };

        virtual void TearDown() {
        };

};


TEST_F(DomainCodeHandlerTest, Test_singleton) {
    DomainCodeHandler& s1 = DomainCodeHandler::get_instance();
    DomainCodeHandler& s2 = DomainCodeHandler::get_instance();
    EXPECT_EQ(&s1, &s2);
}


TEST_F(DomainCodeHandlerTest, Test_valid_code){
    DomainCodeHandler& s1 = DomainCodeHandler::get_instance();
    domain_code test_code = 0;
    EXPECT_FALSE(s1.valid_code(test_code));
}


TEST_F(DomainCodeHandlerTest,  Test_get_domain_name){
    DomainCodeHandler& s1 = DomainCodeHandler::get_instance();
    domain_code test_code = 0;
    EXPECT_EQ(s1.get_domain_name(test_code),DomainCodeHandler::NULLCODE);
}


TEST_F(DomainCodeHandlerTest, Test_registering) {
    DomainCodeHandler& s1 = DomainCodeHandler::get_instance();

    EXPECT_FALSE(s1.registered(test_name));
    EXPECT_TRUE(s1.register_domain(test_name));
    EXPECT_TRUE(s1.registered(test_name));
    EXPECT_FALSE(s1.register_domain(test_name));
    domain_code test_code = 1;
    EXPECT_FALSE(s1.valid_code(test_code));
    test_code = 0;
    EXPECT_TRUE(s1.valid_code(test_code));
}



TEST_F(DomainCodeHandlerTest,  Test_get_domain_name2){
    DomainCodeHandler& s1 = DomainCodeHandler::get_instance();
    domain_code test_code = 0;
    EXPECT_EQ(s1.get_domain_name(test_code),test_name);
}
