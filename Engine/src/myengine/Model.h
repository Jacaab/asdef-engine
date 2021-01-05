#include "Resource.h"
#include "Exception.h"

#include <rend/rend.h>
#include <string>
#include <memory>

namespace myengine
{
	struct Renderer;
	
	struct Model : public Resource
	{
		void onLoad();
		
	private:
		friend struct myengine::Renderer;
		
		std::shared_ptr<rend::Mesh> mesh;
	};
}