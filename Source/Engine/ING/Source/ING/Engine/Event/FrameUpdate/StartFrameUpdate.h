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



/**
 *	Include Event
 */
#include <ING/Event/Event.h>



namespace ING {

	class ING_API EngineStartFrameUpdateEvent : public Event {

		/**
		 *	Constructors And Destructor
		 */
	public:
		EngineStartFrameUpdateEvent();

		~EngineStartFrameUpdateEvent();



		/**
		 *	Name
		 */
	public:
		virtual std::string GetName() override;

	};


}