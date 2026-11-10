#include "Image.h"

#include <format>
#include <fstream>

static auto const cErrFileOpen = "Error opening file";
static auto const cErrFileWrite = "Error writing file";
static auto const cErrFileClose = "Error closing file";
static auto const cErrName = "Invalid name";

Image::Image(std::string const& name, GraphicObjectFactory& factory) :
	mName{ name },
	mObjectFactory{ factory }
{
	if (name.empty()) throw std::invalid_argument(cErrName);
}

void Image::AddRectangle(size_t const x, size_t const y, std::string const& color, size_t const width, size_t const height)
{
	mObjects.emplace_back(mObjectFactory.CreateRectangle(x, y, color, width, height));
}

void Image::AddCircle(size_t const x, size_t const y, std::string const& color, size_t const radius)
{
	mObjects.emplace_back(mObjectFactory.CreateCircle(x, y, color, radius));
}

void Image::WriteToSVG() const
{
	std::ofstream file{ std::format("{}.svg", mName) };
	if (!file.is_open()) throw std::runtime_error(cErrFileOpen);

	file << "<?xml version=\"1.0\"?>\n<svg xmlns=\"http://www.w3.org/2000/svg\">\n";

	for (auto const& obj : mObjects)
	{
		if (obj == nullptr) continue; // Cannot happen in the current implementation -> just for safety.
		file << obj->ToSVG() << std::endl;
	}

	file << "</svg>";

	if (!file.good()) throw std::runtime_error(cErrFileWrite);

	file.close();

	if (file.fail()) throw std::runtime_error(cErrFileClose);
}
