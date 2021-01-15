#include "CameraManager.h"

namespace myengine
{
	std::vector<std::shared_ptr<Camera>> CameraManager::getCameraList()
	{
		return cameraList;
	}

	void CameraManager::addCamera(std::shared_ptr<Camera> cameraContext)
	{
		cameraList.push_back(cameraContext);
	}

	void CameraManager::setCurrentCamera(int _cameraIndex)
	{
		cameraIndex = _cameraIndex;
	}

	std::shared_ptr<Camera> CameraManager::getCurrentCamera()
	{
		return cameraList.at(cameraIndex);
	}
}