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
 *	Include Rendering Material Manager
 */
#include <ING/Rendering/Material/Manager/Manager.h>



namespace ING {

	namespace Rendering {

		class IDrawableCategory;

		class IDrawble;

		class IShader;

		class IDeviceContext;

		class IDevice;

		class IBuffer;

		class IView;



		struct MaterialProperty {

			std::string  name;
			void*		 pData;
			unsigned int size;

		};



		struct MaterialView {

			MaterialView () {}

			MaterialView (

				const std::string& name, 
				const std::string& type,
				IView* view,
				unsigned int index
			
			) :
				name(name),
				type(type),
				view(view),
				index(index)
			{}

			std::string name;
			std::string type;
			IView* view;
			unsigned int index;

		};



		class ING_API IMaterial : public AsMethod
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IMaterial		(const std::string& name, IShader* shader);
			~IMaterial		();



			/**
			 *	Release Methods
			 */
		public:
			virtual void	Release();


			/**
			 *	Properties
			 */
		private:
			std::string		name;

			IShader*		shader;

			void*			propertyPData;
			IBuffer*		propertyBuffer;

			std::vector<MaterialView>						viewVector;
			std::unordered_map<std::string, unsigned int>	viewName2ViewIndexMap;
			std::unordered_map<std::string, std::vector<unsigned int>>	viewType2ViewIndexVectorMap;

			List<IMaterial*>::Node* node;

		protected:
			std::vector<IBuffer*> cbufferVector;

		public:
			std::string		GetName			() { return name; }

			IShader*		GetShader		() { return shader; }

			void			SetShader		(IShader* shader);

			IBuffer*		GetPropertyBuffer(){ return propertyBuffer; }
			void*			GetPropertyPData() { return propertyPData;}

			List<IMaterial*>::Node* GetNode () { return node; }

			const std::vector<IBuffer*>& GetCBufferVector() { return cbufferVector; }
			void			SetCBufferVector(const std::vector<IBuffer*>& cbufferVector);

			const std::vector<MaterialView>& GetViewVector() { return viewVector; }
			unsigned int				GetViewCount() { return viewVector.size(); }
			unsigned int				GetViewIndex(const std::string& name) { return viewName2ViewIndexMap[name]; }

			std::vector<MaterialView>	GetViewsByType(const std::string& type);

			virtual unsigned int		GetMinimumCBufferCount() { return 1; }

		private:
			unsigned int	GetPropertyIndex(const std::string& name);
			unsigned int	GetPropertyOffset(const std::string& name);



			/**
			 *	Methods
			 */
		public:
			virtual void Apply					(const std::string& passName);

			virtual void CreatePropertyBuffer	();
			virtual void ReleasePropertyBuffer	();
			template<typename T>
			void		 SetProperty			(const std::string& name, const T& value, bool updateBuffer) {

				if (shader == 0) return;

				unsigned int offset = GetPropertyOffset(name);

				char* charPData = (char*)propertyPData;

				*((T*)(charPData + offset)) = value;

				if (updateBuffer) {

					UpdatePropertyBuffer();

				}

			}
			template<typename T>
			void		 SetProperty			(const std::string& name, const T& value) { SetProperty<T>(name, value, true); }
			virtual void UpdatePropertyBuffer	();

			virtual void UpdateViewVector		();

			virtual void UpdateCBufferVector	();

			IBuffer*	 GetCBuffer(const std::string& name);
			void		 SetCBuffer(const std::string& name, IBuffer* cbuffer);

			IView*		 GetView				(const std::string& name);
			void		 SetView				(const std::string& name, IView* view);

			virtual void Update					();

		};

	}

}