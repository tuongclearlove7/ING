﻿
/**
 *	Include IOStream
 */
#include <iostream>



 /**
  *	Include Application
  */
#include <ING/Application/Application.h>



  /**
   *	Include Thread And Thread Manager
   */
#include <ING/Thread/Thread.h>

#include <ING/Thread/Manager/Manager.h>



/**
 *	Include Event And Event Manager
 */
#include <ING/Event/Event.h>

#include <ING/Event/Manager/Manager.h>



/**
 *	Include Rendering
 */
#include <ING/Rendering/Rendering.h>

using namespace ING::Rendering;



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h> 



/**
 *	Include Rendering API
 */
#include <ING/Rendering/API/API.h> 



/**
 *	Include Rendering Device
 */
#include <ING/Rendering/API/Device/Device.h> 



/**
 *	Include Rendering Device Context
 */
#include <ING/Rendering/API/Device/Context/Context.h> 



/**
 *	Include Rendering Shader
 */
#include <ING/Rendering/Shader/Shader.h> 



/**
 *	Include Window
 */
#include <ING/Window/Window.h> 



/**
 *	Include Configuration
 */
#include <ING/Configuration/Configuration.h> 



/**
 *	Include Convertor
 */
#include <ING/Rendering/API/Convertor/Convertor.h> 



/**
 *	Include DX11 Convertor
 */
#include <ING/Rendering/API/DirectX11/Convertor/Convertor.h> 



/**
 *	Include Time
 */
#include <ING/Time/Time.h> 



/**
 *	Include Math
 */
#include <ING/Math/Math.h> 

using namespace ING::Math;




using namespace ING;



int main() {
	 


	//Create ING Application
	ING::Application::CreateInstance();

	ING::Application::GetInstance()->Init();



	Window* consoleWindow = WindowManager::GetInstance()->GetConsoleWindow();

	consoleWindow->Show();



	Window* mainWindow = WindowManager::GetInstance()->GetMainWindow();

	mainWindow->Show();



	ING::Application::GetInstance()->GetEvent("RUN")->AddListener([](Event* event) {
		
		Quaternion q = Quaternion::Euler(Vector3(0, 90.0f * Deg2Rad,0));

		Debug::Log(q);

		F4IJK qF4 = q;

		Debug::Warning(qF4); 

		Vector3 c = q * Vector3(1,5,1);

		Debug::Error(c);
		
	});



	ING::Application::GetInstance()->GetEvent("START_FRAME_UPDATE")->AddListener([](Event* event) {



	});



	ING::Application::GetInstance()->GetEvent("END_FRAME_UPDATE")->AddListener([](Event* event) {



	});


	ING::Application::GetInstance()->Run();

	return 0;
}