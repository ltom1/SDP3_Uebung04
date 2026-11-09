#include "FramedCircle.h"

FramedCircle::FramedCircle(size_t const x, size_t const y, std::string const& color, size_t const radius) :
	Circle{ x,y,color,radius }
{
}

std::string FramedCircle::GetProperties() const
{
	// Makes the rectangle fill transparent.
	return "fill=\"none\"";
}
