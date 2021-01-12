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
		std::ifstream file(getPath());				// open the given path for file *starts search from where program is run*
		if (!file.is_open())						// check if the file was found. if not throw an exception
		{
			throw Exception("Failed to open model file");	
		}
		std::string content;
		std::string line;

		while (!file.eof())							// read through file and assign to mesh. *this might be capable of opening more than a mesh*
		{
			getline(file, line);
			content += line + "\n";
		}
		
		mesh->parse(content);
	}
}