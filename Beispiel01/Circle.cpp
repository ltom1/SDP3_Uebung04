#include "Circle.h"

#include <format>

Circle::Circle(size_t const x, size_t const y, std::string const& color, size_t const radius) :
	GraphicObject{ x, y, color },
	mRadius{radius}
{
}

std::string Circle::ToSVG() const
{
	// Example: <circle cx="55" cy="45" r="35" stroke="black" fill="none"/>
	return std::format("<circle cx=\"{}\" cy=\"{}\" r=\"{}\" stroke=\"{}\" {}/>", mX, mY, mRadius, mColor, GetProperties());
}

