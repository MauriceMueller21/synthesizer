#include "components/window.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("WindowCreation")
{
	SWindow* window = new SWindow();
	CHECK(window != nullptr);
	delete(window);
}

TEST_CASE("WindowProperty")
{
	SWindow window;
	
	SECTION("DefaultValues")
	{
		CHECK((window["width"] == 420));
		CHECK((window["height"] == 420));
		CHECK((window["title"] == std::string("")));
	}
}

