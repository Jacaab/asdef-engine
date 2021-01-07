#include "Component.h"

#include <rend/rend.h>

namespace myengine
{

struct Camera : public Component
{
  void onInitialize();

  rend::mat4 getView();

  std::shared_ptr<rend::RenderTexture> getRenderTexture();

  std::shared_ptr<rend::RenderTexture> addRenderTexture();

private:
  std::shared_ptr<rend::RenderTexture> renderTexture;


};

}

