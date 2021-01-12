#include "Camera.h"
#include "Core.h"
#include "Entity.h"
#include "Transform.h"
#include <iostream>
namespace myengine
{

void Camera::onInitialize()
{
	// add self to special camera entities list. allows for multiple cameras (splitscren, animations etc.)
  std::shared_ptr<Camera> self = getEntity()->getComponent<Camera>();
  getCore()->cameras.push_back(self);
}

// return a view matrix *BROKEN* not returning a transform due to getEntity() {entity.lock()} in components returning an exception error
rend::mat4 Camera::getView()
{
  return rend::inverse(getTransform()->getModel());
}

// get renderTexture
std::shared_ptr<rend::RenderTexture> Camera::getRenderTexture()
{
  return renderTexture;
}

// set renderTexture
std::shared_ptr<rend::RenderTexture> Camera::addRenderTexture()
{
  renderTexture = getCore()->context->createRenderTexture();

  return renderTexture;
}

}
