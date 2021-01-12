#include "Entity.h"
#include "Component.h"
#include "Transform.h"

namespace myengine
{
    // update function. cycle through components to call tick functions inside
    // doesnt have a visible use yet but for future classes like controllers
void Entity::tick()
{
  for(size_t ci = 0; ci < components.size(); ci++)
  {
    components.at(ci)->tick();
  }
}

void Entity::render()
{
  for(size_t ci = 0; ci < components.size(); ci++)
  {
    components.at(ci)->render();
  }
}

std::shared_ptr<Core> Entity::getCore()
{
  return core.lock();
}

std::shared_ptr<Transform> Entity::getTransform()
{
  return transform;
}

void Entity::destroy()
{
  if(alive)
  {
    alive = false;

    for(size_t ci = 0; ci < components.size(); ci++)
    {
      components.at(ci)->destroy();
    }
  }
}

}



