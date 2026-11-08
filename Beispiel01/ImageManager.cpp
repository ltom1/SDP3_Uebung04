#include "ImageManager.h"

#include <stdexcept>

static auto const cErrNoImg = "No image selected";

void ImageManager::AddImage(std::string const& name, GraphicObjectFactory& factory)
{
	mImages.emplace_back(std::move(std::make_unique<Image>(name, factory)));
}

void ImageManager::WriteAllSVG() const
{
	for (auto const& img : mImages)
	{
		img->WriteToSVG();
	}
}

void ImageManager::AddRectangle(size_t const x, size_t const y, std::string const& color, size_t const width, size_t const height)
{
	if (mImages.empty()) throw std::runtime_error(cErrNoImg);

	mImages.back()->AddRectangle(x, y, color, width, height);
}


void ImageManager::AddCircle(size_t const x, size_t const y, std::string const& color, size_t const radius)
{
	if (mImages.empty()) throw std::runtime_error(cErrNoImg);

	mImages.back()->AddCircle(x, y, color, radius);
}