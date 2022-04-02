#include <catch2/catch_test_macros.hpp>

unsigned long long factorial(unsigned long long number)
{
	if (number == 0)
	{
		return 1;
	}
	return number * factorial(number - 1);
}

TEST_CASE("Factorials are computed", "[factorial]") {
    REQUIRE( factorial(1) == 1 );
    REQUIRE( factorial(2) == 2 );
    REQUIRE( factorial(3) == 6 );
    REQUIRE( factorial(10) == 3628800 );
}

