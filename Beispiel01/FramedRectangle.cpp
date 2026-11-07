#include "FramedRectangle.h"

FramedRectangle::FramedRectangle(size_t const x, size_t const y, std::string const& color, size_t const width, size_t const height) :
	Rectangle{ x, y, color, width, height }
{
}

std::string FramedRectangle::GetProperties() const
{
	// Makes the rectangle fill transparent.
	return "fill=\"none\"";
}
