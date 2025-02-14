
/**
 * Include Header
 */
#include "Pipeline.h"



/**
 *	Include Camera
 */
#include <ING/Camera/Camera.h>



/**
 *	Include Renderer
 */
#include <ING/Rendering/Renderer/Renderer.h>



/**
 *	Include Rendering API
 */
#include <ING/Rendering/API/API.h>



/**
 *	Include Rendering Device Context
 */
#include <ING/Rendering/API/Device/Context/Context.h>



/**
 *	Include Rendering Device
 */
#include <ING/Rendering/API/Device/Device.h>



/**
 *	Include Rendering Pass
 */
#include <ING/Rendering/Pass/Pass.h>



/**
 *	Include SubRP Pass
 */
#include <ING/Rendering/SubRP/Pass/Pass.h>



/**
 *	Include SubRP First Pass
 */
#include <ING/Rendering/SubRP/Pass/First/First.h>



/**
 *	Include SubRP Final Pass
 */
#include <ING/Rendering/SubRP/Pass/Final/Final.h>



/**
 *	Include Rendering Engine
 */
#include <ING/Rendering/Engine/Engine.h>




namespace ING {

	namespace Rendering {

		namespace SubRP {

			/**
			 *	Constructors And Destructor
			 */
			Pipeline::Pipeline(std::string name) : IPipeline(name) {



			}

			Pipeline::~Pipeline() {



			}



			/**
			 *	Release Methods
			 */
			void Pipeline::Release() {

				IPipeline::Release();

			}



			/**
			 *	Methods
			 */
			bool Pipeline::Render(IDeviceContext* context) {

				IPipeline::Render(context);



				return true;
			}

			bool Pipeline::SubRender(IDeviceContext* context, Camera* camera, const PassInput& input, PassOutput& output) {

				unsigned int passCount = passVector.size();

				PassInput renderRS = input;

				for (unsigned int i = 0; i < passCount; ++i) {

					IPass* pass = passVector[i];

					PassOutput passOutput;

					RENDERING_ASSERTION(pass->Render(context, camera, &renderRS, &passOutput));

					renderRS += passOutput;

				}

				output += renderRS;

				return true;
			}

			unsigned int Pipeline::GetPassIndex(const std::string& name) {

				return passName2PassIndex[name];

			}

			IPass* Pipeline::GetPass(unsigned int index) {

				return passVector[index];

			}

			IPass* Pipeline::GetPass(const std::string& name) {

				return GetPass(GetPassIndex(name));

			}

			void Pipeline::AddPass(IPass* pass, unsigned int index) {

				unsigned int passVectorSize = passVector.size();

				passVector.resize(passVectorSize + 1);

				for (unsigned int i = index + 1; i < passVectorSize; ++i) {

					passVector[i] = passVector[i - 1];

					passName2PassIndex[passVector[i]->GetName()] = i;

				}

				passVector[index] = pass;

				passName2PassIndex[pass->GetName()] = index;

			}

			unsigned int Pipeline::AddPass(IPass* pass) {

				unsigned int passIndex = passVector.size();

				passVector.push_back(pass);

				return passIndex;

			}

			void Pipeline::RemovePass(unsigned int index) {

				std::string passName = passVector[index]->GetName();

				passVector.erase(passVector.begin() + index);

				unsigned int passVectorSize = passVector.size();

				for (unsigned int i = index; i < passVectorSize; ++i) {

					passVector[i] = passVector[i + 1];

					passName2PassIndex[passVector[i]->GetName()] = i;

				}

				passName2PassIndex.erase(passName);

			}

		}

	}

}