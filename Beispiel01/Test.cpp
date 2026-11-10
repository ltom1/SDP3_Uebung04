#include "gtest/gtest.h"

#include <vld.h>
#include <fstream>
#include <sstream>
#include <filesystem>

#include "FramedRectangle.h"
#include "FilledRectangle.h"
#include "FramedCircle.h"
#include "FilledCircle.h"
#include "FramedObjectFactory.h"
#include "FilledObjectFactory.h"
#include "Image.h"
#include "ImageManager.h"

using namespace std;

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
	EXPECT_EQ(rect1.ToSVG(), "<rect x=\"0\" y=\"0\" width=\"10\" height=\"20\" stroke=\"black\" fill=\"black\"/>");
	EXPECT_EQ(rect2.ToSVG(), "<rect x=\"100\" y=\"100\" width=\"0\" height=\"0\" stroke=\"doesnotexist\" fill=\"doesnotexist\"/>");

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
	EXPECT_EQ(circ1.ToSVG(), "<circle cx=\"0\" cy=\"0\" r=\"10\" stroke=\"black\" fill=\"black\"/>");
	EXPECT_EQ(circ2.ToSVG(), "<circle cx=\"100\" cy=\"100\" r=\"0\" stroke=\"doesnotexist\" fill=\"doesnotexist\"/>");

	FilledCircle const circ3{ circ1 };

	EXPECT_EQ(circ3.ToSVG(), circ1.ToSVG());
}

/////////////////////////////////////////////////

TEST(FramedObjectFactory, Test) {
	FramedObjectFactory& fact = FramedObjectFactory::GetInstance();

	GraphicObject::UPtr circ1 = fact.CreateCircle(10, 10, "black", 3);
	FramedCircle const circ1Manual = FramedCircle{ 10, 10, "black", 3 };
	EXPECT_EQ(circ1->ToSVG(), circ1Manual.ToSVG());

	GraphicObject::UPtr rect1 = fact.CreateRectangle(10, 10, "black", 3, 5);
	FramedRectangle const rect1Manual = FramedRectangle{ 10, 10, "black", 3, 5 };
	EXPECT_EQ(rect1->ToSVG(), rect1Manual.ToSVG());
}

/////////////////////////////////////////////////

TEST(FilledObjectFactory, Test) {
	FilledObjectFactory& fact = FilledObjectFactory::GetInstance();

	GraphicObject::UPtr circ1 = fact.CreateCircle(10, 10, "black", 3);
	FilledCircle const circ1Manual = FilledCircle{ 10, 10, "black", 3 };
	EXPECT_EQ(circ1->ToSVG(), circ1Manual.ToSVG());

	GraphicObject::UPtr rect1 = fact.CreateRectangle(10, 10, "black", 3, 5);
	FilledRectangle const rect1Manual = FilledRectangle{ 10, 10, "black", 3, 5 };
	EXPECT_EQ(rect1->ToSVG(), rect1Manual.ToSVG());
}

/////////////////////////////////////////////////

TEST(Image, Test) {
	filesystem::remove("TestImage.svg");
	ifstream file;
	ostringstream stream;
	Image img{ "TestImage", FilledObjectFactory::GetInstance() };
	
	img.WriteToSVG();
	
	file.open("TestImage.svg");
	EXPECT_EQ(file.is_open(), true);
	stream << file.rdbuf();
	EXPECT_EQ(stream.str(), "<?xml version=\"1.0\"?>\n<svg xmlns=\"http://www.w3.org/2000/svg\">\n</svg>");
	file.close();
	stream.str("");

	img.AddCircle(20, 20, "green", 10);
	img.AddCircle(30, 30, "red", 20);
	img.AddRectangle(0, 0, "black", 10, 20);

	img.WriteToSVG();
	file.open("TestImage.svg");
	EXPECT_EQ(file.is_open(), true);
	stream << file.rdbuf();
	EXPECT_EQ(stream.str(), "<?xml version=\"1.0\"?>\n<svg xmlns=\"http://www.w3.org/2000/svg\">\n<circle cx=\"20\" cy=\"20\" r=\"10\" stroke=\"green\" fill=\"green\"/>\n<circle cx=\"30\" cy=\"30\" r=\"20\" stroke=\"red\" fill=\"red\"/>\n<rect x=\"0\" y=\"0\" width=\"10\" height=\"20\" stroke=\"black\" fill=\"black\"/>\n</svg>");
	file.close();
	stream.str("");
}

TEST(Image, InvldName) {
	try {
		Image img{ "", FilledObjectFactory::GetInstance() };
		EXPECT_EQ(1, 0); // Fail.
	}
	catch (std::invalid_argument const& ex) {
		EXPECT_STREQ(ex.what(), "Invalid name");
	}

	Image const img{ "doesnotexist/file", FilledObjectFactory::GetInstance() };
	try {
		img.WriteToSVG();
		EXPECT_EQ(1, 0); // Fail.
	}
	catch (std::runtime_error const& ex) {
		EXPECT_STREQ(ex.what(), "Error opening file");
	}
}

/////////////////////////////////////////////////

TEST(ImageManager, Test) {
	filesystem::remove("Img1.svg");
	filesystem::remove("Img2.svg");
	filesystem::remove("Img3.svg");
	ifstream file;
	ostringstream stream;
	
	ImageManager& mgr = ImageManager::GetInstance();
	mgr.WriteAllSVG();
	EXPECT_EQ(filesystem::exists("Img1.svg"), false);
	EXPECT_EQ(filesystem::exists("Img2.svg"), false);
	EXPECT_EQ(filesystem::exists("Img3.svg"), false);
	
	try {
		mgr.AddCircle(100, 100, "yellow", 10);
		EXPECT_EQ(1, 0); // Fail.
	}
	catch (std::runtime_error const& ex) {
		EXPECT_STREQ(ex.what(), "No image selected");
	}
	try {
		mgr.AddRectangle(100, 100, "yellow", 100, 200);
		EXPECT_EQ(1, 0); // Fail.
	}
	catch (std::runtime_error const& ex) {
		EXPECT_STREQ(ex.what(), "No image selected");
	}

	mgr.AddImage("Img1", FramedObjectFactory::GetInstance());
	mgr.WriteAllSVG();
	EXPECT_EQ(filesystem::exists("Img1.svg"), true);
	EXPECT_EQ(filesystem::exists("Img2.svg"), false);
	EXPECT_EQ(filesystem::exists("Img3.svg"), false);

	file.open("Img1.svg");
	EXPECT_EQ(file.is_open(), true);
	stream << file.rdbuf();
	EXPECT_EQ(stream.str(), "<?xml version=\"1.0\"?>\n<svg xmlns=\"http://www.w3.org/2000/svg\">\n</svg>");
	file.close();
	stream.str("");

	mgr.AddCircle(100, 100, "blue", 50);
	mgr.AddRectangle(50, 50, "red", 200, 300);
	mgr.WriteAllSVG();
	EXPECT_EQ(filesystem::exists("Img1.svg"), true);
	EXPECT_EQ(filesystem::exists("Img2.svg"), false);
	EXPECT_EQ(filesystem::exists("Img3.svg"), false);

	file.open("Img1.svg");
	EXPECT_EQ(file.is_open(), true);
	stream << file.rdbuf();
	EXPECT_EQ(stream.str(), "<?xml version=\"1.0\"?>\n<svg xmlns=\"http://www.w3.org/2000/svg\">\n<circle cx=\"100\" cy=\"100\" r=\"50\" stroke=\"blue\" fill=\"none\"/>\n<rect x=\"50\" y=\"50\" width=\"200\" height=\"300\" stroke=\"red\" fill=\"none\"/>\n</svg>");
	file.close();
	stream.str("");

	mgr.AddImage("Img2", FilledObjectFactory::GetInstance());
	mgr.AddImage("Img3", FilledObjectFactory::GetInstance());
	mgr.AddCircle(200, 200, "black", 100);
	mgr.AddCircle(200, 200, "red", 90);
	mgr.AddRectangle(300, 300, "yellow", 100, 100);

	mgr.WriteAllSVG();
	EXPECT_EQ(filesystem::exists("Img1.svg"), true);
	EXPECT_EQ(filesystem::exists("Img2.svg"), true);
	EXPECT_EQ(filesystem::exists("Img3.svg"), true);

	file.open("Img1.svg");
	EXPECT_EQ(file.is_open(), true);
	stream << file.rdbuf();
	EXPECT_EQ(stream.str(), "<?xml version=\"1.0\"?>\n<svg xmlns=\"http://www.w3.org/2000/svg\">\n<circle cx=\"100\" cy=\"100\" r=\"50\" stroke=\"blue\" fill=\"none\"/>\n<rect x=\"50\" y=\"50\" width=\"200\" height=\"300\" stroke=\"red\" fill=\"none\"/>\n</svg>");
	file.close();
	stream.str("");

	file.open("Img2.svg");
	EXPECT_EQ(file.is_open(), true);
	stream << file.rdbuf();
	EXPECT_EQ(stream.str(), "<?xml version=\"1.0\"?>\n<svg xmlns=\"http://www.w3.org/2000/svg\">\n</svg>");
	file.close();
	stream.str("");

	file.open("Img3.svg");
	EXPECT_EQ(file.is_open(), true);
	stream << file.rdbuf();
	EXPECT_EQ(stream.str(), "<?xml version=\"1.0\"?>\n<svg xmlns=\"http://www.w3.org/2000/svg\">\n<circle cx=\"200\" cy=\"200\" r=\"100\" stroke=\"black\" fill=\"black\"/>\n<circle cx=\"200\" cy=\"200\" r=\"90\" stroke=\"red\" fill=\"red\"/>\n<rect x=\"300\" y=\"300\" width=\"100\" height=\"100\" stroke=\"yellow\" fill=\"yellow\"/>\n</svg>");
	file.close();
	stream.str("");
}

TEST(ImageManager, InvldName) {
	try {
		ImageManager::GetInstance().AddImage("", FilledObjectFactory::GetInstance());
		EXPECT_EQ(0, 1); // Fail.
	}
	catch (std::invalid_argument const& ex) {
		EXPECT_STREQ(ex.what(), "Invalid name");
	}

	ImageManager::GetInstance().AddImage("doesnotexist/file", FilledObjectFactory::GetInstance());
	try {
		ImageManager::GetInstance().WriteAllSVG();
		EXPECT_EQ(1, 0); // Fail.
	}
	catch (std::runtime_error const& ex) {
		EXPECT_STREQ(ex.what(), "Error opening file");
	}
}