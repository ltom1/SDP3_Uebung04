#include "FramedObjectFactory.h"
#include "FramedRectangle.h"
#include "FramedCircle.h"

std::unique_ptr<GraphicObject> FramedObjectFactory::CreateCircle(size_t x, size_t y, std::string color, size_t radius) const
{
	return std::make_unique<FramedCircle>(FramedCircle::FramedCircle(x, y, color, radius));
}

std::unique_ptr<GraphicObject> FramedObjectFactory::CreateRectangle(size_t x, size_t y, std::string color, size_t width, size_t height) const
{
	return std::make_unique<FramedRectangle>(FramedRectangle::FramedRectangle(x, y, color, width, height));
}