#ifndef GRAPHICOBJECTFACTORY_H
#define GRAPHICOBJECTFACTORY_H

#include <string>
#include <memory>

#include "GraphicObject.h"


/// @author Philip
/// @date 5.11.2026
/// @brief Interface class for diffrent graphic object factories
/// 
/// Circles and rectangle in diffrent styles can be created
class GraphicObjectFactory
{
public:
	/// @brief Creates a circle
	/// @param[in] x x-pos of the circle
	/// @param[in] y y-pos of the circle
	/// @param[in] color color of the circle
	/// @param[in] radius radius of the circle
	virtual GraphicObject::UPtr CreateCircle(size_t const x, size_t const y, std::string const& color, size_t const radius) const = 0;


	/// @brief Creates a rectangle
	/// @param[in] x x-pos of the rectangle
	/// @param[in] y y-pos of the rectangle
	/// @param[in] color color of the rectangle
	/// @param[in] width width of the rectangle
	/// @param[in] height height of the rectangle
	virtual GraphicObject::UPtr CreateRectangle(size_t const x, size_t const y, std::string const& color, size_t const width, size_t const height) const = 0;

	/// @brief Virtual DTor.
	virtual ~GraphicObjectFactory() = default;
};

#endif