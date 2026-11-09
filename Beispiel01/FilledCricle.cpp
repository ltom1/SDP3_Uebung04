#include "FilledCricle.h"

FilledCircle::FilledCircle(size_t const x, size_t const y, std::string const& color, size_t const radius) :
	Circle{x,y,color,radius}
{
}

std::string FilledCircle::GetProperties() const
{
	// In this case we need no additional properties as filling is the default behaviour.
	return "";
}
