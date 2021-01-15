#include "Camera.h"
#include <rend/rend.h>
#include <memory>
#include <vector>

namespace myengine
{
	struct CameraManager
	{
	public:
		//recieve access to the list of cameras
		std::vector<std::shared_ptr<Camera>> getCameraList();

		//add a camera to the list
		void addCamera(std::shared_ptr<Camera> cameraContext);

		//assign the currently active camera to an index
		void setCurrentCamera(int _cameraIndex);

		//get the current index of camera
		std::shared_ptr<Camera>  getCurrentCamera();

	private:
		friend struct myengine::Core;
		std::vector<std::shared_ptr<Camera>>  cameraList;		//cam list
		int cameraIndex;										//ref for currently active camera
	};

}