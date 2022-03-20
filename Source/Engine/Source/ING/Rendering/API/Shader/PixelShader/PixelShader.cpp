
/**
 *	Include Header
 */
#include "PixelShader.h"



/**
 *	Include API Manager
 */
#include <ING/Rendering/API/Manager/Manager.h>



/**
 *	Include DirectX11 Pixel Shader
 */
#include <ING/Rendering/API/DirectX11/Shader/PixelShader/PixelShader.h>



/**
 *	Include File Resource
 */
#include <ING/Resource/File/File.h>



/**
 *	Include Resource Manager
 */
#include <ING/Resource/Manager/Manager.h>



#include <algorithm>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		IPixelShader::IPixelShader(IDevice* device) : IShader("PixelShader") {

			this->device = device;

		}

		IPixelShader::~IPixelShader() {



		}



		/**
		 *	Create Methods
		 */
		IPixelShader* IPixelShader::CreateFromHLSL(IDevice* device, const std::wstring& filePath) {

			FileResource* fileResource = ResourceManager::GetInstance()->LoadResource<FileResource>(filePath);

			std::string basicStrContent;

			std::transform(fileResource->content.begin(), fileResource->content.end(), std::back_inserter(basicStrContent), [](wchar_t c) {
				return (char)c;
			});

			switch (APIManager::GetInstance()->GetAPIFlag())
			{

			case NONE_API_FLAG:

				break;

			case DIRECTX11_API_FLAG:

				return DirectX11::PixelShader::CreateFromHLSL(device, basicStrContent);

				break;

			case DIRECTX12_API_FLAG:

				break;

			case VULKAN_API_FLAG:

				break;

			case OPENGL_API_FLAG:

				break;

			default:
				break;
			}

			return nullptr;

		}

	}

}