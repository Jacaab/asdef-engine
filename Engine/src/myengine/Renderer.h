#include "Component.h"

#include <rend/rend.h>

#include <memory>

namespace myengine
{

struct Model;

struct Renderer : public Component
{
  void onInitialize();
  void onRender();

  void setModel (std::shared_ptr<Model> model);
private:
  std::shared_ptr<rend::Shader> shader;
  std::shared_ptr<rend::Buffer> shape;
  std::shared_ptr<Model> model;

};

}
