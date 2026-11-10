#ifndef SINGLETONBASE_H
#define SINGLETONBASE_H

#include "Object.h"

#include <memory>


/// @author Philip
/// @date 5.11.2026
/// @brief SingletonBase class to derive other singleton classes.
/// 
/// This class implements the shared methods of each derived Singleton class
template <typename T> class SingletonBase : public Object
{
public:

	/// @brief constructes the object of the class
	/// @returns the constructed object of the class
	static T& GetInstance()
	{
		if (mInstance == nullptr)
		{
			// add Object only if it does not already exist
			mInstance = std::unique_ptr<T>{ new T{} }; 
		}
		return *mInstance;
	}

protected:

	/// @brief CTor
	SingletonBase() = default;


private:
	/// @brief CCTor
	///
	/// must be deleted or private (or both), because only one instance of class must exist
	SingletonBase(SingletonBase const& other) = delete;

	/// @brief Assignment operator
	///
	/// deleted or private (or both), because no other instance of class can exist that could be assigned
	SingletonBase& operator = (SingletonBase const& other) = delete;

	/// @brief Uniqueptr on the instance
	static std::unique_ptr<T> mInstance;

};
// init static member
template <typename T> std::unique_ptr<T> SingletonBase<T>::mInstance = nullptr;

#endif