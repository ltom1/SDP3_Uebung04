#ifndef IMAGE_H
#define IMAGE_H

#include "Object.h"
#include "GraphicObject.h"
#include "GraphicObjectFactory.h"

#include <string>
#include <vector>


/// @author Thomas Lechner
/// @date 07.11.2026
/// @brief SVG-Image consisting of multiple GraphicObject.
/// 
/// You can add new Objects and write the SVG-Image to a file.
class Image : public Object
{
public:
	/// @brief std::unique_ptr of this class.
	using UPtr = std::unique_ptr<Image>;

	/// @brief CTor.
	/// @param[in] name The name of the image -> will be the filename.
	/// @param[in] factory The GraphicObjectFactory used to construct new GraphicObject.
	Image(std::string const& name, GraphicObjectFactory& factory);


	/// @brief Adds a new Rectangle to the Image.
	/// @param[in] x The X-coordinate of position.
	/// @param[in] y The Y-coordinate of position.
	/// @param[in] color Color of the rectangle (e.g. black, green,...).
	/// @param[in] width The width of the rectangle.
	/// @param[in] height The height of the rectangle.
	/// 
	/// The Rectangle is constructed by mObjectFactory.
	void AddRectangle(size_t const x, size_t const y, std::string const& color, size_t const width, size_t const height);
	

	/// @brief Adds a new Circle to the Image.
	/// @param[in] x The X-coordinate of position.
	/// @param[in] y The Y-coordinate of position.
	/// @param[in] color Color of the circle (e.g. black, green,...).
	/// @param[in] radius The radius of the circle.
	/// 
	/// The Circle is constructed by mObjectFactory.
	void AddCircle(size_t const x, size_t const y, std::string const& color, size_t const radius);

	/// @brief Writes the Image to a file in SVG-Format.
	///
	/// The name of the created file is <mName>.svg.
	void WriteToSVG() const;

private:
	/// @brief The name of the image -> will be the filename.
	std::string const mName;
	/// @brief The GraphicObjectFactory used to construct new GraphicObject.
	GraphicObjectFactory const& mObjectFactory;

	/// @brief List of all stored GraphicObject.
	std::vector<GraphicObject::UPtr> mObjects;
};

#endif