#include <myengine/myengine.h>

#include <iostream>

#define shared std::shared_ptr

// basic player struct/object for testing purposes. to be replaced with a dedicated object loader once testing is done so this wont have to be done manually for more objects
struct Player : public Component
{
	void onInitialize(int team, int type, std::string name)
	{
		std::shared_ptr<Renderer> r = getEntity()->addComponent<Renderer>();	//creates an entity for the renderer to reference.		more components to be added ie player controller, ui etc
		std::shared_ptr<Model> cm = getCore()->getResources()->load<Model>("../resources/models/curuthers/curuthers.obj");	//asign a model to render.
		// starts looking from which folder the program is run from(build/debug right now) so the directory will need to change between build options *needs a permenant fix*
		r->setModel(cm);
	}
};



int main()
{
  std::shared_ptr<Core> core = Core::initialize();
  
  // creating a temporary player object using a struct
  std::shared_ptr<Entity> pe = core->addEntity();
  pe->getTransform()->setPosition(rend::vec3(0,0,-10));
  std::shared_ptr<Player> p  = pe->addComponent<Player>(1,2,"testPlayer");
  // TDDO: add a kill command to remove entities from the scene.  probably through a component or for all entities
  
  // camera obj *Not working* something isnt returning a transform for the renderer 
  std::shared_ptr<Entity> camera = core->addEntity();
  camera->addComponent<Camera>();

  std::shared_ptr<Entity> c2 = core->addEntity();
  c2->getTransform()->setPosition(rend::vec3(0, 20, 0));
  c2->getTransform()->rotate(-90, 0, 0);
  std::shared_ptr<Camera> mc = c2->addComponent<Camera>();
  mc->addRenderTexture();
  
  // where the engine starts
  core->start();

  return 0;
}
