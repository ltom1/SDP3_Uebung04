#include "FilledRectangle.h"

#include <format>

FilledRectangle::FilledRectangle(size_t const x, size_t const y, std::string const& color, size_t const width, size_t const height) :
	Rectangle{ x, y, color, width, height }
{
}

std::string FilledRectangle::GetProperties() const
{
	return std::format("fill=\"{}\"", mColor);
}
