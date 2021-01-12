#ifndef MYENGINE_RESOURCE_H
#define MYENGINE_RESOURCE_H

#include <string>
#include <memory>

namespace myengine
{
	struct Core;
	struct Resources;
	
	struct Resource
	{
		virtual ~Resource();
		virtual void onLoad();

		std::shared_ptr<Core>getCore();
		std::string getPath();
		std::string getName();
		void setName(std::string _name);

		
	private:
		friend struct myengine::Resources;
		
		std::string path;
		std::string name;
		std::weak_ptr<Core> core;
		
	};
}

#endif