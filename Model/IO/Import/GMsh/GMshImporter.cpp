#include "GMshImporter.h"
#include <fstream>
#include <iostream>
#include <vector>

namespace MeshIS
{
	namespace Model
	{
		namespace Import
		{
			Common::CMR GMshImporter::Import(const string & absolute_file_path)
			{
				std::fstream gmsh_file;
				gmsh_file.open(absolute_file_path, std::ios::in);
				if (!gmsh_file.good())
				{
					std::cout << "Can't open the file. Closing program..." << std::endl;
					std::cin.get();
					return cmr;
				}
				std::string temp_string;
				while (!gmsh_file.eof())
				{
					gmsh_file >> temp_string;
					if (temp_string == "$Nodes")
					{
						double x, y, z;
						int vertises_amount;
						std::getline(gmsh_file, temp_string); // here's number of nodes in file
						gmsh_file >> vertises_amount;
						std::getline(gmsh_file, temp_string); // getting to line where node is
						for (size_t i = 0; i < vertises_amount; ++i)
						{
							gmsh_file.ignore(10,' ');
							gmsh_file >> x;
							gmsh_file >> y;
							gmsh_file >> z;
							cmr.vertices.push_back({ x, y, z });
						}
					}
					if (temp_string == "$Elements")
					{
						std::getline(gmsh_file, temp_string); // here's number of elements in file
						gmsh_file >> elements_amount;
						std::getline(gmsh_file, temp_string); // getting to line where element is
						for (size_t i = 0; i < elements_amount; ++i)
						{
							int point_id, points_amount, element_type;
							std::vector<int> element;
							gmsh_file.ignore(10, ' ');
							gmsh_file >> points_amount;
							element_type = points_amount;
							if (points_amount < 4) {
								points_amount++;
							}
							for (size_t j = 0; j < 4; j++) {
								gmsh_file.ignore(10, ' ');
							}
							for (size_t j = 0; j < points_amount; ++j)
							{
								gmsh_file >> point_id;
								element.push_back(point_id);
							}
							addElementToCMR(element_type, element);
						}
					}
					temp_string.clear();
				}
				gmsh_file.close();
				return std::move(cmr);
			}

			void GMshImporter::addElementToCMR(int element_type, std::vector<int>& p)
			{
				if (element_type == 2)
					cmr.elementsT3.push_back(Common::Element_T3{ p[0], p[1], p[2] });
				else if (element_type == 3)
					cmr.elementsT4.push_back(Common::Element_T4{ p[0], p[1], p[2], p[3] });
				else if (element_type == 6)
					cmr.elementsP6.push_back(Common::Element_P6{ p[0], p[1], p[2], p[3], p[4], p[5] });
			}
		}
	}
}