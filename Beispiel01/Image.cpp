#include "Image.h"

#include <format>
#include <fstream>

static auto const cErrFileOpen = "Error opening file";
static auto const cErrFileRead = "Error reading file";

Image::Image(std::string const& name, GraphicObjectFactory& factory) :
	mName{ name },
	mObjectFactory{ factory }
{
}

void Image::AddRectangle(size_t const x, size_t const y, std::string const& color, size_t const width, size_t const height)
{
	mObjects.emplace_back(std::move(mObjectFactory.CreateRectangle(x, y, color, width, height)));
}

void Image::AddCircle(size_t const x, size_t const y, std::string const& color, size_t const radius)
{
	mObjects.emplace_back(std::move(mObjectFactory.CreateCircle(x, y, color, radius)));
}

void Image::WriteToSVG() const
{
	std::ofstream file{ std::format("{}.svg", mName) };
	if (!file.is_open()) throw std::runtime_error(cErrFileOpen);

	file << "<?xml version=\"1.0\"?>\n<svg xmlns=\"http://www.w3.org/2000/svg\">\n";

	for (auto const& obj : mObjects)
	{
		file << obj->ToSVG() << std::endl;
	}

	file << "</svg>";

	if (!file.good()) throw std::runtime_error(cErrFileRead);

	file.close();
}
