
/**
 *	Include Header
 */
#include "Context.h"



/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



/**
 *	Include Configuration
 */
#include <ING/Configuration/Configuration.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	namespace Scripting {

		/**
		 *	Constructors And Destructor
		 */
		IContext::IContext(const std::string& name, ILanguage* language, bool isMainContext) :
			name(name),
			language(language),
			isMainContext(isMainContext)
		{

			 

		}

		IContext::~IContext()
		{



		}



		/**
		 *	Release Method
		 */
		void IContext::Release() {

			delete this;
			
		}



		/**
		 *	Methods
		 */
		IOuternalMethod* IContext::GetOuternalMethod(IMethodContainer* container, const std::string& name) {



			return 0;
		}

		void IContext::Load() {



		}

		void IContext::Unload() {



		}

		void IContext::Reload() {



		}

	}

}