#include "Exception.h"

#include <vector>
#include <memory>

namespace myengine
{
// gives all entities access to use functions and parameters that ALL entities shouldhave access to. aything else should be a component ie model/controller
struct Component;
struct Core;
struct Exception;
struct Transform;

struct Entity
{
  friend struct ::myengine::Core;

  // ways to add a component
  template <typename T>
  std::shared_ptr<T> addComponent()
  {
    std::shared_ptr<T> rtn = std::make_shared<T>();
    rtn->entity = self;
    components.push_back(rtn);		// add to a vector of components associated with the individual entity -
    rtn->onInitialize();			// so they can be accessed and edited later
    return rtn;
  }
  template <typename T, typename ... Args>
  std::shared_ptr<T> addComponent(Args&&... args)
  {
	  std::shared_ptr<T> rtn = std::make_shared<T>();
	  rtn->entity = self;
	  components.push_back(rtn);
	  rtn->onInitialize(std::forward<Args>(args)...);
	  return rtn;
  }

  // accessing components
  template <typename T>
  std::shared_ptr<T> getComponent()
  {
	  // cycle through the vector of components
	  for (size_t i = 0; i < components.size(); i++)
	  {
		  std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(components.at(i));
		  if (!rtn)		// was the component found?
		  {
			  continue;
		  }
		  return rtn;
	  }
  }
  
  std::shared_ptr<Core> getCore();
  std::shared_ptr<Transform> getTransform();

  //update/tick, render, destroy functions
  void tick();		// update data per "frame"
  void render();	// render obj per "frame"
  void destroy();	// destroy object when finished

private:
  std::vector<std::shared_ptr<Component>> components;
  std::shared_ptr<Transform> transform = std::make_shared<Transform>();
  std::weak_ptr<Core> core;
  std::weak_ptr<Entity> self;
  bool alive;	// used for destroy()
  
};

}