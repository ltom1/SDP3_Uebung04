#include "FilledRectangle.h"

FilledRectangle::FilledRectangle(size_t const x, size_t const y, std::string const& color, size_t const width, size_t const height) :
	Rectangle{ x, y, color, width, height }
{
}

std::string FilledRectangle::GetProperties() const
{
	// In this case we need no additional properties as filling is the default behaviour.
	return "";
}
