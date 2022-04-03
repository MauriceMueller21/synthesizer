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
	SWindow* window = new SWindow();

	SECTION("width")
	{
		int default_value = 420;
		CHECK(window->width() == default_value);
		
		window->width(100);
		CHECK(window->width() == 100);
		
		window->width(200);
		CHECK(window->width() == 200);
	}
	
	SECTION("height")
	{
		int default_value = 420;
		CHECK(window->height() == default_value);
		
		window->height(100);
		CHECK(window->height() == 100);
		
		window->height(200);
		CHECK(window->height() == 200);
	}

	SECTION("title")
	{
		std::string default_value = "";
		CHECK(window->title() == default_value);
		
		window->title("Hello");
		CHECK(window->title() == "Hello");
		
		window->title("World");
		CHECK(window->title() == "World");
	}

	delete(window);
}

