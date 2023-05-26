#pragma once

#include "vector.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.cpp>

TEST_CASE("my_vector: size/capacity testing", "[vector1]") {
	custom::vector<int> v_test1(4);

	INFO("Method `size` doesn't work properly");
	CHECK(v_test1.size() == 4);
	INFO("Method `capacity` doesn't work properly");
	CHECK(v_test1.capacity() == 4);

	v_test1.push_back(1729);

	INFO("Method `size` or method `push_back` doesn't work properly");
	CHECK(v_test1.size() == 5);
	INFO("Method `capacity` or method `push_back` doesn't work properly");
	CHECK(v_test1.capacity() == 6);

	v_test1.push_back(4104);
	v_test1.push_back(2052);
	v_test1.push_back(1026);
	v_test1.push_back(513);

	INFO("Method `size` or method `push_back` doesn't work properly");
	CHECK(v_test1.size() == 9);
	INFO("Method `capacity` or method `push_back` doesn't work properly");
	CHECK(v_test1.capacity() == 9);

	v_test1.at(0) = 171;
	v_test1.at(1) = 57;
	v_test1.at(2) = 19;
	v_test1.at(3) = 1;

	INFO("Method `size` or method `at` doesn't work properly");
	CHECK(v_test1.size() == 9);
	INFO("Method `capacity` or method `at` doesn't work properly");
	CHECK(v_test1.capacity() == 9);
}

TEST_CASE("my_vector: at/push_back testing", "[vector2]") {
	custom::vector<int> v_test2(2);

	INFO("Method `at` doesn't work properly");
	CHECK(v_test2.at(0) == 0);

	v_test2.push_back(1729);
	INFO("Method `push_back` or `at` doesn't work properly");
	CHECK(v_test2.at(2) == 1729);

	v_test2.at(0) = 69;
	v_test2.at(1) = 69;
	v_test2.at(2) = 69;

	for (int i = 0; i < v_test2.size(); ++i) {
		INFO("Method `at` doesn't work properly");
		CHECK(v_test2.at(i) == 69);
	}

	INFO("Method `at` doesn't throws an exception");
	REQUIRE_THROWS(v_test2.at(10) = 1729);
}

int main(int argc, char** argv)
{
	return Catch::Session().run();
}