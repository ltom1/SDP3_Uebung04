#ifndef FILLEDOBJECTFACTORY_H
#define FILLEDOBJECTFACTORY_H

#include "GraphicObjectFactory.h"
#include "SingletonBase.h"


/// @author Philip
/// @date 8.11.2026
/// @brief Factory to create filled circles and rectangles
class FilledObjectFactory : public GraphicObjectFactory, public SingletonBase<FilledObjectFactory>
{
	friend class SingletonBase<FilledObjectFactory>;
public:
	/// @brief Creates a filled circle
	/// @param[in] x x-pos of the circle
	/// @param[in] y y-pos of the circle
	/// @param[in] color color of the circle
	/// @param[in] radius radius of the circle
	std::unique_ptr<GraphicObject> CreateCircle(size_t x, size_t y, std::string color, size_t radius);


	/// @brief Creates a filled rectangle
	/// @param[in] x x-pos of the rectangle
	/// @param[in] y y-pos of the rectangle
	/// @param[in] color color of the rectangle
	/// @param[in] width width of the rectangle
	/// @param[in] height height of the rectangle
	std::unique_ptr<GraphicObject> CreateRectangle(size_t x, size_t y, std::string color, size_t width, size_t height);

};

#endif