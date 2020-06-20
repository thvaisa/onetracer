#include <project.hpp>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <limits>
#include "sphere_tracer.hpp"
#include "input_reader.hpp"


using ::testing::_;
using ::testing::ElementsAre;
using ::testing::Gt;
using ::testing::ExitedWithCode;

class SphereTracerTest : public ::testing::Test{
    protected:
        SphereTracer* _tracer;

        virtual void SetUp() {
            _tracer = new SphereTracer();
        };

        virtual void TearDown() {
            delete _tracer;
            _tracer = nullptr;
        };

};


TEST_F(SphereTracerTest, Test_constructor) {
    delete _tracer;
    _tracer = new SphereTracer(); 
}
