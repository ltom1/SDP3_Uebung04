#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H

#include "SingletonBase.h"
#include "Image.h"

#include <vector>


/// @author Thomas Lechner
/// @date 07.11.2026
/// @brief Manages multiple Image objects.
/// 
/// Provides operations on Image objects.
class ImageManager : public SingletonBase<ImageManager>
{
	friend class SingletonBase<ImageManager>;
public:
	/// @brief Add a new Image to the ImageManager.
	/// @param[in] name The name of the image -> will be the filename.
	/// @param[in] factory The GraphicObjectFactory used to construct new GraphicObject.
	/// 
	/// The Image is selected until the next call to this function. During this time it is possible to add GraphicObjects by using the Add methods.
	void AddImage(std::string const& name, GraphicObjectFactory& factory);

	/// @brief Adds a new Rectangle to the currently selected Image.
	/// @param[in] x The X-coordinate of position.
	/// @param[in] y The Y-coordinate of position.
	/// @param[in] color Color of the rectangle (e.g. black, green,...).
	/// @param[in] width The width of the rectangle.
	/// @param[in] height The height of the rectangle.
	/// 
	/// The Rectangle is constructed by the Image's mObjectFactory.
	void AddRectangle(size_t const x, size_t const y, std::string const& color, size_t const width, size_t const height);


	/// @brief Adds a new Circle to the currently selected Image.
	/// @param[in] x The X-coordinate of position.
	/// @param[in] y The Y-coordinate of position.
	/// @param[in] color Color of the circle (e.g. black, green,...).
	/// @param[in] radius The radius of the circle.
	/// 
	/// The Circle is constructed by the Image's mObjectFactory.
	void AddCircle(size_t const x, size_t const y, std::string const& color, size_t const radius);

	/// @brief Writes all Image objects to a file in SVG-Format.
	///
	/// The name of each created file is <Image.mName>.svg.
	void WriteAllSVG() const;

private:
	/// @brief Default CTor.
	ImageManager() = default;

	/// @brief Stores multiple images.
	std::vector<Image::UPtr> mImages;
};

#endif