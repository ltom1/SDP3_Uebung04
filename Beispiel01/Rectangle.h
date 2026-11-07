#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "GraphicObject.h"


/// @author Thomas Lechner
/// @date 07.11.2026
/// @brief Abstract base class of all rectangles.
/// 
/// Stores common information like height and width of the rectangle.
class Rectangle : public GraphicObject
{
public:
	/// @brief std::unique_ptr of this class.
	using UPtr = std::unique_ptr<Rectangle>;

	/// @brief CTor.
	/// @param[in] x The X-coordinate of position.
	/// @param[in] y The Y-coordinate of position.
	/// @param[in] color Color of the rectangle (e.g. black, green,...).
	/// @param[in] width The width of the rectangle.
	/// @param[in] height The height of the rectangle.
	Rectangle(size_t const x, size_t const y, std::string const& color, size_t const width, size_t const height);

	/// @brief Creates a SVG-XML-Element of the rectangle.
	/// @returns The SVG-XML-Element as a string.
	std::string ToSVG() const override;

protected:
	/// @brief The width of the rectangle.
	size_t const mWidth;
	/// @brief The height of the rectangle.
	size_t const mHeight;
};

#endif