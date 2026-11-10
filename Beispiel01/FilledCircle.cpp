#include "FilledCircle.h"

#include <format>

FilledCircle::FilledCircle(size_t const x, size_t const y, std::string const& color, size_t const radius) :
	Circle{x,y,color,radius}
{
}

std::string FilledCircle::GetProperties() const
{
	return std::format("fill=\"{}\"", mColor);
}
