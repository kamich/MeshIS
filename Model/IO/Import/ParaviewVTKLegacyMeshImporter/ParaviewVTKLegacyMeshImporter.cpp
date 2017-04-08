#include "ParaviewVTKLegacyMeshImporter.h"
#include <fstream>
#include <iostream>
#include <vector>


namespace MeshIS
{
namespace Model
{
	using Common::Element_Q4;
	using Common::Element_T3;
	using Common::Element_T4;
	using Common::Element_P6;

namespace Import
{

	Common::CMR PVTKLImporter::Import(const string & absolute_file_path)
	{
		std::fstream vtk_legacy_file;
		vtk_legacy_file.open(absolute_file_path, std::ios::in);
		if (!vtk_legacy_file.good())
		{
			std::cout << "Can't open the file. Aborting..." << std::endl;
			std::cin.get();
			return cmr;
		}

		std::string marker;
		while (!vtk_legacy_file.eof())
		{
			vtk_legacy_file >> marker;
			if (marker == "POINTS")
			{
				int vertex_amount;
				vtk_legacy_file >> vertex_amount;
				std::getline(vtk_legacy_file, marker); // just to move to the next line
				for (size_t i = 0; i < vertex_amount; ++i)
				{
					double x, y, z;
					vtk_legacy_file >> x;
					vtk_legacy_file >> y;
					vtk_legacy_file >> z;
					cmr.vertices.push_back({ x, y, z });
				}
			}
			if (marker == "CELLS")
			{
				vtk_legacy_file >> elements_amount;
				std::getline(vtk_legacy_file, marker); // just to move to the next line
				for (size_t i = 0; i < elements_amount; ++i)
				{
					int points;
					vtk_legacy_file >> points;
					std::vector<int> element;
					int point;
					for (size_t j = 0; j < points; ++j)
					{
						vtk_legacy_file >> point;
						element.push_back(point);
					}
					temp_elements.push_back(element);
				}
			}
			if (marker == "CELL_TYPES")
			{
				vtk_legacy_file >> elements_amount;
				for (int i = 0; i < elements_amount; ++i)
				{
					int element_type;
					std::vector<int>& p = temp_elements[i];
					vtk_legacy_file >> element_type;
					addElementToCMR(element_type, p);	
				}
			}
			marker.clear();
		}
		vtk_legacy_file.close();
		return std::move(cmr);
	}

	void PVTKLImporter::addElementToCMR(int element_type, std::vector<int>& p)
	{
		if (element_type == ParaviewElementTypes::Triangular)
			cmr.elementsT3.push_back(Element_T3{ p[0], p[1], p[2] });
		else if (element_type == ParaviewElementTypes::Quadrilateral)
			cmr.elementsQ4.push_back(Element_Q4{ p[0], p[1], p[2], p[3] });
		else if (element_type == ParaviewElementTypes::Prismatic)
			cmr.elementsP6.push_back(Element_P6{ p[0], p[1], p[2], p[3], p[4], p[5] });
	}


}
}
}
