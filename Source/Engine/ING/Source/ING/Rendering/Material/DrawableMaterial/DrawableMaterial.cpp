
/**
 *	Include Header
 */
#include "DrawableMaterial.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;




/**
 *	Include Rendering Device
 */
#include <ING/Rendering/API/Device/Device.h>



/**
 *	Include Rendering Device Context
 */
#include <ING/Rendering/API/Device/Context/Context.h>



/**
 *	Include SwapChain
 */
#include <ING/Rendering/API/SwapChain/SwapChain.h>



/**
 *	Include Buffer
 */
#include <ING/Rendering/API/Resource/Buffer/Buffer.h>



/**
 *	Include ConstantBuffer
 */
#include <ING/Rendering/API/Resource/ConstantBuffer/ConstantBuffer.h>



/**
 *	Include Drawable
 */
#include <ING/Rendering/Drawable/Drawable.h>



/**
 *	Include Drawable Category
 */
#include <ING/Rendering/Drawable/Filter/Filter.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Shader
 */
#include <ING/Rendering/Shader/Shader.h>



/**
 *	Include Math
 */
#include <ING/Math/Math.h>

using namespace ING::Math;



/**
 *	Include Camera
 */
#include <ING/Camera/Camera.h>





namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		DrawableMaterial::DrawableMaterial(const std::string& name, IShader* shader) :
			IMaterial(name, shader)
		{

			cbufferVector.resize(1);

		}

		DrawableMaterial::~DrawableMaterial()
		{



		}



		/**
		 *	Methods
		 */
		void DrawableMaterial::Apply(const std::string& passName) {

			IShader* shader = GetShader();

			if (shader != 0) {

				shader->Apply(passName);

				IDeviceContext* context = shader->GetDevice()->GetImmediateContext();

				if (shader->GetPropertyCount() > 0) {

					context->PSSetConstantBuffers(cbufferVector);
					context->VSSetConstantBuffers(cbufferVector);

				}

			}

		}

		void DrawableMaterial::ApplyTransform(const TransformM& transformMatrices, bool updateBuffer) {

			SetProperty<RMatrix4x4>("ING_WorldMatrix", transformMatrices.translationMatrix, false);

			if (updateBuffer) {

				UpdatePropertyBuffer();

			}

		}
		void DrawableMaterial::ApplyTransform(const TransformM& transformMatrices) {
			ApplyTransform(transformMatrices, true);
		}

		void DrawableMaterial::ApplyCamera(Camera* camera, bool updateBuffer) {

			SetProperty<RMatrix4x4>("ING_ViewMatrix", camera->GetViewMatrix(), false);
			SetProperty<RMatrix4x4>("ING_ProjectionMatrix", camera->GetProjectionMatrix(), false);

			if (updateBuffer) {

				UpdatePropertyBuffer();

			}

		}
		void DrawableMaterial::ApplyCamera(Camera* camera) {
			ApplyCamera(camera, true);
		}

	}

}