
#include "catch.hpp"

#include <job_stream/job_stream.h>

using string = std::string;
namespace inv = job_stream::invoke;

TEST_CASE("invoke") {
    job_stream::invoke::_init();
    SECTION("echo") {
        std::string output, error;
        std::vector<string> args;
        args.push_back("/bin/echo");
        args.push_back("Hello, world!");
        std::tie(output, error) = inv::run(args);
        REQUIRE(output == "Hello, world!\n");
    }
    SECTION("bad cat") {
        std::string output, error;
        std::vector<string> args;
        args.push_back("/bin/cat");
        args.push_back("/some/nonexistant/file/ok/right");
        REQUIRE_THROWS_AS(inv::run(args), std::runtime_error);
    }
}