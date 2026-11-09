#ifndef CIRCLE_H
#define CIRCLE_H

#include "GraphicObject.h"


/// @author Philip Ackermann
/// @date 09.11.2026
/// @brief Abstract base class of all circles.
/// 
/// Stores common information like radius of the circle.
class Circle : public GraphicObject
{
public:
	/// @brief std::unique_ptr of this class.
	using UPtr = std::unique_ptr<Circle>;

	/// @brief CTor.
	/// @param[in] x The X-coordinate of position.
	/// @param[in] y The Y-coordinate of position.
	/// @param[in] color Color of the circle (e.g. black, green,...).
	/// @param[in] width The width of the circle.
	Circle(size_t const x, size_t const y, std::string const& color, size_t const radius);

	/// @brief Creates a SVG-XML-Element of the circle.
	/// @returns The SVG-XML-Element as a string.
	std::string ToSVG() const override;

protected:
	/// @brief The radius of the circle.
	size_t const mRadius;
	
};

#endif