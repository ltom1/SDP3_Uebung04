#include "gtest/gtest.h"

#include <vld.h>

#include "FramedRectangle.h"
#include "FilledRectangle.h"
#include "FramedCircle.h"
#include "FilledCricle.h"
#include "FramedObjectFactory.h"
#include "FilledObjectFactory.h"

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

TEST(FramedCircle, Test) {
	FramedCircle const circ1{ 0, 0, "black", 10};
	FramedCircle const circ2{ 100, 100,  "doesnotexist", 0};
	EXPECT_EQ(circ1.ToSVG(), "<circle cx=\"0\" cy=\"0\" r=\"10\" stroke=\"black\" fill=\"none\"/>");
	EXPECT_EQ(circ2.ToSVG(), "<circle cx=\"100\" cy=\"100\" r=\"0\" stroke=\"doesnotexist\" fill=\"none\"/>");

	FramedCircle const circ3{ circ1 };

	EXPECT_EQ(circ3.ToSVG(), circ1.ToSVG());
}

/////////////////////////////////////////////////

TEST(FilledCircle, Test) {
	FilledCircle const circ1{ 0, 0, "black", 10 };
	FilledCircle const circ2{ 100, 100,  "doesnotexist", 0 };
	EXPECT_EQ(circ1.ToSVG(), "<circle cx=\"0\" cy=\"0\" r=\"10\" stroke=\"black\" />");
	EXPECT_EQ(circ2.ToSVG(), "<circle cx=\"100\" cy=\"100\" r=\"0\" stroke=\"doesnotexist\" />");

	FilledCircle const circ3{ circ1 };

	EXPECT_EQ(circ3.ToSVG(), circ1.ToSVG());
}

/////////////////////////////////////////////////

TEST(FramedObjectFactory, Test) {
	FramedObjectFactory& fact = FramedObjectFactory::GetInstance();

	GraphicObject::UPtr circ1 = fact.CreateCircle(10, 10, "black", 3);
	ASSERT_NE(circ1, nullptr);
}

/////////////////////////////////////////////////

TEST(FilledObjectFactory, Test) {
	FilledObjectFactory& fact = FilledObjectFactory::GetInstance();

	GraphicObject::UPtr circ1 = fact.CreateCircle(10, 10, "black", 3);
	ASSERT_NE(circ1, nullptr);
}