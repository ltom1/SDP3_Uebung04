#ifndef FILLEDRECTANGLE_H
#define FILLEDRECTANGLE_H

#include "Rectangle.h"


/// @author Thomas Lechner
/// @date 07.11.2026
/// @brief Class of a filled rectangle.
/// 
/// Represents a rectangle with its area drawn as filled.
class FilledRectangle : public Rectangle
{
public:
	/// @brief std::unique_ptr of this class.
	using UPtr = std::unique_ptr<FilledRectangle>;

	/// @brief CTor.
	/// @param[in] x The X-coordinate of position.
	/// @param[in] y The Y-coordinate of position.
	/// @param[in] color Color of the rectangle (e.g. black, green,...).
	/// @param[in] width The width of the rectangle.
	/// @param[in] height The height of the rectangle.
	FilledRectangle(size_t const x, size_t const y, std::string const& color, size_t const width, size_t const height);

protected:
	/// @brief Gets additional properties for the SVG-XML-Element.
	/// @returns XML-properties as a string.
	/// 
	/// This is used as a template method in ToSVG for SVG creation.
	std::string GetProperties() const override;
};

#endif