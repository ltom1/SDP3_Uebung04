#ifndef FRAMEDCIRCLE_H
#define FRAMEDCIRCLE_H

#include "Circle.h"


/// @author Philip Ackermann
/// @date 09.11.2026
/// @brief Class of a framed circle.
/// 
/// Represents a circle drawn as frame.
class FramedCircle : public Circle
{
public:
	/// @brief std::unique_ptr of this class.
	using UPtr = std::unique_ptr<FramedCircle>;

	/// @brief CTor.
	/// @param[in] x The X-coordinate of position.
	/// @param[in] y The Y-coordinate of position.
	/// @param[in] color Color of the circle (e.g. black, green,...).
	/// @param[in] width The width of the circle.
	/// @param[in] height The height of the circle.
	FramedCircle(size_t const x, size_t const y, std::string const& color, size_t const radius);

protected:
	/// @brief Gets additional properties for the SVG-XML-Element.
	/// @returns XML-properties as a string.
	/// 
	/// This is used as a template method in ToSVG for SVG creation.
	std::string GetProperties() const override;
};

#endif