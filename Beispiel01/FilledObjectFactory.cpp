#include "FilledObjectFactory.h"
#include "FilledRectangle.h"
#include "FilledCricle.h"

std::unique_ptr<GraphicObject> FilledObjectFactory::CreateCircle(size_t x, size_t y, std::string color, size_t radius) const
{
	return std::make_unique<FilledCircle>(FilledCircle::FilledCircle(x, y, color,radius));
}

std::unique_ptr<GraphicObject> FilledObjectFactory::CreateRectangle(size_t x, size_t y, std::string color, size_t width, size_t height) const
{
	return std::make_unique<FilledRectangle>(FilledRectangle::FilledRectangle(x, y, color, width, height));
}