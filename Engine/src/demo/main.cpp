#include <myengine/myengine.h>

#include <iostream>

#define shared std::shared_ptr


struct Player : public Component
{
	void onInitialize(int team, int type, std::string name)
	{
		std::shared_ptr<Renderer> r = getEntity()->addComponent<Renderer>();
		std::shared_ptr<Model> cm = getCore()->getResources()->load<Model>("resources/models/curuthers/curuthers.obj");
		r->setModel(cm);
	}
};



int main()
{
  std::shared_ptr<Core> core = Core::initialize();
  
  //testing player obj
  std::shared_ptr<Entity> pe = core->addEntity();
  pe->getTransform()->setPosition(rend::vec3(0,0,-10));
  std::shared_ptr<Player> p  = pe->addComponent<Player>(1,2,"testPlayer");
  //add kill command
  
  //camera obj
  std::shared_ptr<Entity> camera = core->addEntity();
  camera->addComponent<Camera>();
  //add controller
  
  
  core->start();

  return 0;
}
