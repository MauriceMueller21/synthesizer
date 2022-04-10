#include "components/widget.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("WidgetProperty")
{
	SWidget widget;
	
	SECTION("SettingPropertiesWork")
	{
		CHECK_NOTHROW(widget["id"] = 5);
		CHECK_NOTHROW(widget["name"] = std::string("hi"));
		CHECK_NOTHROW(widget["pi"] = 3.14f);
	}
	
	SECTION("ReadingPropertiesWork")
	{
		widget["id"] = 5;
		widget["name"] = std::string("hi");
		widget["pi"] = 3.14f;
	
		int id = widget["id"];
		std::string name = widget["name"];
		float pi = widget["pi"];
		
		float wrong_type, wrong_key;
		CHECK_THROWS(wrong_type = widget["id"]);
		CHECK_THROWS(wrong_key = widget["gibberisch"]);
	}
	
	SECTION("ComparingPropertiesWork")
	{
		widget["id"] = 5;
		widget["name"] = std::string("hi");
		widget["pi"] = 3.14f;
	
		CHECK((widget["id"] == 5));
		CHECK((widget["name"] == std::string("hi")));
		CHECK((widget["pi"] == 3.14f));
	}
}

