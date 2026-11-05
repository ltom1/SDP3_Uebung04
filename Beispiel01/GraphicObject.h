#ifndef GRAPHICOBJECT_H
#define GRAPHICOBJECT_H

#include "Object.h"

#include <string>
#include <memory>


/// @author Thomas Lechner
/// @date 05.11.2026
/// @brief Base class of all graphic objects.
/// 
/// Stores common information like position and color of the graphic object. 
class GraphicObject : public Object
{
public:
	/// @brief std::unique_ptr of this class.
	using UPtr = std::unique_ptr<GraphicObject>;

	/// @brief CTor.
	/// @param[in] x The X-coordinate of position.
	/// @param[in] y The Y-coordinate of position.
	/// @param[in] color Color of the graphic object (e.g. black, green,...).
	GraphicObject(size_t const x, size_t const y, std::string const& color);

	/// @brief Creates a SVG-XML-Element of the graphic object.
	/// @returns The SVG-XML-Element as a string.
	virtual std::string ToSVG() const = 0;

	/// @brief Gets additional properties for the SVG-XML-Element.
	/// @returns XML-properties as a string.
	/// 
	/// This is used as a template method in ToSVG for SVG creation.
	virtual std::string GetProperties() const = 0;

private:
	/// @ X-coordinate of position.
	size_t const mX;
	/// @ Y-coordinate of position.
	size_t const mY;

	/// @brief Color of the graphic object (e.g. black, green,...).
	std::string mColor;
};

#endif