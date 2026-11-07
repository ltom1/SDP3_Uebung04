#include "Rectangle.h"

#include <format>

Rectangle::Rectangle(size_t const x, size_t const y, std::string const& color, size_t const width, size_t const height) :
	GraphicObject{ x, y, color },
	mWidth{ width },
	mHeight{ height }
{
}

std::string Rectangle::ToSVG() const
{
	// Example: <rect x="10" y="10" width="90" height="70" stroke="black" fill="none"/>
	return std::format("<rect x=\"{}\" y=\"{}\" width=\"{}\" height=\"{}\" stroke=\"{}\" {}/>", mX, mY, mWidth, mHeight, mColor, GetProperties());
}
