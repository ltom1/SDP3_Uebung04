#include "GraphicObject.h"

GraphicObject::GraphicObject(size_t const x, size_t const y, std::string const& color) :
	mX{ x },
	mY{ y },
	mColor{ color }
{
}