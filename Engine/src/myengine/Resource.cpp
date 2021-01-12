#include "Resource.h"

namespace myengine
{
	Resource::~Resource() {}
	void Resource::onLoad() {}
	
	// where is the file located
	std::string Resource::getPath()
	{
		return path;
	}
	
	// name could be used as a alternative to using a full file directory *NOT IMPLIMENTED*
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