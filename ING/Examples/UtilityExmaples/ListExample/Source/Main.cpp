
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



using namespace ING;



int main() {



	//Create ING Application
	ING::Application::CreateInstance();

	ING::Application::GetInstance()->Init();

	ING::Application::GetInstance()->Run();



	//Create List
	List<int> list;



	//Add Elements
	int firstElement = 5;
	List<int>::Node* firstNode = list.Add(firstElement);

	int secondElement = 3;
	List<int>::Node* secondNode = list.Add(secondElement);



	//Log List
	list.Foreach([](int& item) {
	
		Debug::Log(item);
		
	});



	Debug::Log();



	//Remove First Element
	list.Remove(firstNode);



	//Log List
	list.Foreach([](int& item) {

		Debug::Log(item);

	});
	


	//Clear List
	list.Clear();



	system("pause");
	return 0;
}