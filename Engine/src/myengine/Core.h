#include <SDL2/SDL.h>
#include <rend/rend.h>

#include <memory>
#include <vector>

namespace myengine
{

struct Renderer;
struct Entity;
struct Camera;
struct Resources;
struct Model;

struct Core
{
  static std::shared_ptr<Core> initialize();

  std::shared_ptr<Entity> addEntity();
  std::shared_ptr<Camera> getCameraList();
  std::shared_ptr<Resources> getResources();
  

  void start();

private:
  friend struct myengine::Camera;
  friend struct myengine::Renderer;
  friend struct myengine::Model;

  std::vector<std::shared_ptr<Entity>> entities;
  std::shared_ptr<Resources> resources = std::make_shared<Resources>();

  std::shared_ptr<rend::Context> context;
  std::weak_ptr<Core> self;
  
  SDL_Window* window;
  SDL_GLContext glContext;

  std::weak_ptr<Camera> currentCamera;
  std::vector<std::weak_ptr<Camera> > cameras;

};

}
