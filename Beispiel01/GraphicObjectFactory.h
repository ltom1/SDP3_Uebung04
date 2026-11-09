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
	virtual std::unique_ptr<GraphicObject> CreateCircle(size_t x, size_t y, std::string color, size_t radius) = 0;


	/// @brief Creates a rectangle
	/// @param[in] x x-pos of the rectangle
	/// @param[in] y y-pos of the rectangle
	/// @param[in] color color of the rectangle
	/// @param[in] width width of the rectangle
	/// @param[in] height height of the rectangle
	virtual std::unique_ptr<GraphicObject> CreateRectangle(size_t x, size_t y, std::string color, size_t width, size_t height) = 0;
};

#endif