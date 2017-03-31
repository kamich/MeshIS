
#include <fstream>
#include <iostream>
#include <string>
#include "Su2MeshImporter.h"

using namespace std;

namespace MeshIS
{
	namespace Model
	{

		using Common::Element_P6;

		namespace Import
		{

			Common::CMR SU2LImporter::Import(const string & absolute_file_path)
			{
				//openin file
				std::fstream su2file;
				su2file.open(absolute_file_path, std::ios::in);
				if (!su2file.good())
				{
					std::cout << "Can't open the file. You have problem !" << std::endl;
					std::cin.get();
					return cmr;
				}
				//skip lines
				string line;
				double n_elem = 0;
				getline(su2file, line);
				su2file >> line;
				// reading amount elements on mesh
				su2file >> n_elem;
				//skip lines
				for (int i = 0; i < n_elem + 1; i++)
				{
					getline(su2file, line);
				}
				int type_element = 0;
				double points_amount = 0;
				string temp;
				su2file >> temp;
				//reading amount points on mesh
				su2file >> points_amount;
				double x, y, z;
				//generation points
				for (size_t j = 0; j < points_amount; j++)
				{
					su2file >> x;
					su2file >> y;
					su2file >> z;
					cmr.vertices.push_back({ x,y,z });
				}
				//jump to start file
				su2file.seekg(17);
				su2file >> temp;
				//generation elements
				for (size_t i = 0; i < n_elem; i++)
				{
					std::vector<int> element;
					int point_tmp;
					su2file >> type_element;
					for (int j = 0; j < 6; j++) {
						su2file >> point_tmp;
						element.push_back(point_tmp);
					}
					temp_elements.push_back(element);
					su2file >> temp;
					std::vector<int>& points_vector = temp_elements[i];
					addElement(type_element, points_vector);
				}
				line.clear();
				su2file.close();
				return std::move(cmr);
			}
			void SU2LImporter::addElement(int element_type, std::vector<int>&points_vector)
			{
				if (element_type == 13)
					cmr.elementsP6.push_back(Element_P6{ points_vector[0], points_vector[1], points_vector[2], points_vector[3], points_vector[4], points_vector[5] });
			}
		}
	}
}