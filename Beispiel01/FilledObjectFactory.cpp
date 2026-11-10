#include "FilledObjectFactory.h"
#include "FilledRectangle.h"
#include "FilledCircle.h"

GraphicObject::UPtr FilledObjectFactory::CreateCircle(size_t const x, size_t const y, std::string const& color, size_t const radius) const
{
	return std::make_unique<FilledCircle>(x, y, color,radius);
}

GraphicObject::UPtr FilledObjectFactory::CreateRectangle(size_t const x, size_t const y, std::string const& color, size_t const width, size_t const height) const
{
	return std::make_unique<FilledRectangle>(x, y, color, width, height);
}