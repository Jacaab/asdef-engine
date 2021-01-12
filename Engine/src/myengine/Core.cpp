#include "Core.h"
#include "Entity.h"
#include "Resources.h"
#include "Exception.h"
#include "Transform.h"

#include <iostream>

namespace myengine
{

std::shared_ptr<Core> Core::initialize()
{
  std::shared_ptr<Core> rtn = std::make_shared<Core>();
  rtn->self = rtn;

  // create window using SDL
  rtn->window = SDL_CreateWindow("myengine",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    800, 600,
    SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

  // did the window create successfully
  if(!rtn->window)
  {
    throw Exception("Failed to create window");
  }

  // create Opengl context and exception check
  rtn->glContext = SDL_GL_CreateContext(rtn->window);

  if(!rtn->glContext)
  {
    throw Exception("Failed to create OpenGL context");
  }

  rtn->context = rend::Context::initialize();

  // create a resources list. used for things like models/textures maybe audio files later
  rtn->resources = std::make_shared<Resources>();
  rtn->resources->core = rtn;

  return rtn;
}

std::shared_ptr<Camera> Core::getCameraList()
{
  return currentCamera.lock();
}

std::shared_ptr<Entity> Core::addEntity()
{
  std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
  rtn->core = self;
  rtn->self = rtn;
  rtn->alive = true;

  // all entities have a transform so they can be placed withina scene
  rtn->addComponent<Transform>();

  // adding to the list of entities
  entities.push_back(rtn);

  return rtn;
}

std::shared_ptr<Resources> Core::getResources()
{
	return resources;
}

void Core::start()
{
  bool running = true;
  SDL_Event e = {0};

  while(running)
  {
      //quit poll event
    while(SDL_PollEvent(&e) != 0)
    {
      if(e.type == SDL_QUIT)
      {
        running = false;
      }
    }

    // cycle through entities and call update/tick function
    for(size_t ei = 0; ei < entities.size(); ei++)
    {
      entities.at(ei)->tick();
    }

    glClearColor(0.39f, 0.58f, 0.93f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // cycle through entities and call render function
    for(size_t ei = 0; ei < entities.size(); ei++)
    {
      entities.at(ei)->render();
    }

    SDL_GL_SwapWindow(window);
  }
}

}

