#include "Resource.h"

namespace myengine
{
	Resource::~Resource() {}
	void Resource::onLoad() {}
	
	std::string Resource::getPath()
	{
		return path;
	}
	
	std::string Resource::getName()
	{
		return name;
	}

	void Resource::setName(std::string _name)
	{
		name = _name;
	}

	std::shared_ptr<Core> Resource::getCore()
	{
		return core.lock();
	}
}