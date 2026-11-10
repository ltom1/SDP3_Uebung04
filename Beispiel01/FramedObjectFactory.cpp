#include "FramedObjectFactory.h"
#include "FramedRectangle.h"
#include "FramedCircle.h"

GraphicObject::UPtr FramedObjectFactory::CreateCircle(size_t const x, size_t const y, std::string const& color, size_t const radius) const
{
	return std::make_unique<FramedCircle>(x, y, color, radius);
}

GraphicObject::UPtr FramedObjectFactory::CreateRectangle(size_t const x, size_t const y, std::string const& color, size_t const width, size_t const height) const
{
	return std::make_unique<FramedRectangle>(x, y, color, width, height);
}