#include "Model.h"
#include "Core.h"

#include <rend/rend.h>

#include <iostream>
#include <fstream>

namespace myengine
{
	void Model::onLoad()
	{
		mesh = getCore()->context->createMesh();
		std::ifstream file(getPath());
		if (!file.is_open())
		{
			throw Exception("Failed to open model file");
		}
		std::cout << "load successful" << std::endl;
		std::string content;
		std::string line;

		while (!file.eof())
		{
			getline(file, line);
			content += line + "\n";
		}
		
		mesh->parse(content);
	}
}