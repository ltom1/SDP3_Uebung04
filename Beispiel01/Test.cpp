#include "gtest/gtest.h"

#include <vld.h>

#include "FramedRectangle.h"
#include "FilledRectangle.h"

/////////////////////////////////////////////////

TEST(FramedRectangle, Test) {
	FramedRectangle const rect1{ 0, 0, "black", 10, 20 };
	FramedRectangle const rect2{ 100, 100,  "doesnotexist", 0, 0 };
	EXPECT_EQ(rect1.ToSVG(), "<rect x=\"0\" y=\"0\" width=\"10\" height=\"20\" stroke=\"black\" fill=\"none\"/>");
	EXPECT_EQ(rect2.ToSVG(), "<rect x=\"100\" y=\"100\" width=\"0\" height=\"0\" stroke=\"doesnotexist\" fill=\"none\"/>");

	FramedRectangle const rect3{ rect1 };

	EXPECT_EQ(rect3.ToSVG(), rect1.ToSVG());
}

/////////////////////////////////////////////////

TEST(FilledRectangle, Test) {
	FilledRectangle const rect1{ 0, 0, "black", 10, 20 };
	FilledRectangle const rect2{ 100, 100,  "doesnotexist", 0, 0 };
	EXPECT_EQ(rect1.ToSVG(), "<rect x=\"0\" y=\"0\" width=\"10\" height=\"20\" stroke=\"black\" />");
	EXPECT_EQ(rect2.ToSVG(), "<rect x=\"100\" y=\"100\" width=\"0\" height=\"0\" stroke=\"doesnotexist\" />");

	FilledRectangle const rect3{ rect1 };

	EXPECT_EQ(rect3.ToSVG(), rect1.ToSVG());
}

/////////////////////////////////////////////////