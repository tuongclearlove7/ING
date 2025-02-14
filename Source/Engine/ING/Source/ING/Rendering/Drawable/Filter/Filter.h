#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	namespace Rendering {

		class IDrawable;



		class ING_API IDrawableFilter
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IDrawableFilter	(const std::string& name);
			~IDrawableFilter	();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			std::string name;

			SmartArray<IDrawable*> drawableArray;

			IdGenerator		idGenerator;

		public:
			std::string				GetName			() { return name; }

			const SmartArray<IDrawable*>& GetDrawableArray	() { return drawableArray; }



			/**
			 *	Methods
			 */
		public:
			void	AddDrawable		(IDrawable* drawable);
			void	RemoveDrawable	(IDrawable* drawable);

		};

	}

}