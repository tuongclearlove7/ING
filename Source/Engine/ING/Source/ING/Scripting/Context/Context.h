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

	namespace Scripting {

		class ILanguage;

		class IMethodContainer;

		class IOuternalMethod;



		class ING_API IContext
		{

		public:
			friend class ILanguage;



			/**
			 *	Constructors And Destructor
			 */
		public:
			IContext(const std::string& name, ILanguage* language, bool isMainContext);
			~IContext();



			/**
			 *	Release Method
			 */
		public:
			virtual void Release();



			/**
			 *	Properties 
			 */
		private:
			std::string			name;
			ILanguage*			language;

			bool				isMainContext;

		public:
			const std::string&	GetName		() { return name; }
			ILanguage*			GetLanguage	() { return language; }

			bool				IsMainContext() { return isMainContext; }



			/**
			 *	Methods
			 */
		public:
			virtual IOuternalMethod* GetOuternalMethod(IMethodContainer* container, const std::string& name);

			virtual void Load();
			virtual void Unload();
			virtual void Reload();

		};

	}

}