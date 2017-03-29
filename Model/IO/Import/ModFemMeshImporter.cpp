#include "ModFEMMeshImporter.h"
#include <fstream>
#include <vector>
#include <cstdlib>
#include "boost/variant.hpp"


namespace MeshIS
{
	namespace Model
	{
		using Common::Vertex;
		using Common::Edge;
		using Common::TriangularFace;
		using Common::QuadrilateralFace;
		using Common::Element_F5;
		using Common::Element_P6;

		namespace Import
		{
			Common::CMR ModFEMMeshImporter::Import(const string & absolute_file_path)
			{
				std::fstream ModFem_file;
				ModFem_file.open(absolute_file_path, std::ios::in);
				if (!ModFem_file.good())
				{
					std::cout << "Can not open the file." << std::endl;
					std::cin.get();
					return cmr;
				}


				ModFem_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				double x, y, z, k, l, type;

				ModFem_file >> vertex_amount;
				ModFem_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				for (size_t i = 0; i < vertex_amount; ++i)
				{
					ModFem_file >> x;
					ModFem_file >> y;
					ModFem_file >> z;
					cmr.vertices.push_back({ x-1, y-1, z-1 });
				}

				int edges_amount;
				ModFem_file >> edges_amount;
				ModFem_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				for (size_t i = 0; i < edges_amount; ++i)
				{
					ModFem_file.ignore();
					ModFem_file >> x;
					ModFem_file >> y;
					modfemcmr.edges.push_back({ x - 1, y - 1 });
				}

				int face_amount;
				ModFem_file >> face_amount;
				ModFem_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				vector <boost::variant<TriangularFace, QuadrilateralFace>> faces;
				for (size_t i = 0; i < face_amount; ++i)
				{
					ModFem_file >> type;
					ModFem_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

					if (type == 3)
					{
						ModFem_file >> x;
						ModFem_file >> y;
						ModFem_file >> z;
						x = abs(x);
						x = abs(y);
						x = abs(z);
						modfemcmr.triangularfaces.push_back({ x - 1, y - 1, z - 1 });
						faces.push_back(modfemcmr.triangularfaces.back());
					}
					else if (type == 4)
					{
						ModFem_file >> x;
						ModFem_file >> y;
						ModFem_file >> z;
						ModFem_file >> k;
						x = abs(x);
						y = abs(y);
						z = abs(z);
						k = abs(k);
						modfemcmr.quadrilateralfaces.push_back({ x - 1, y - 1, z - 1, k - 1 });
						faces.push_back(modfemcmr.quadrilateralfaces.back());
					}
				}

				int elements_amount;
				ModFem_file >> elements_amount;
				ModFem_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				for (size_t i = 0; i < elements_amount; ++i)
				{
					ModFem_file >> type;
					ModFem_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					if (type == 5)
					{
						ModFem_file >> x;
						ModFem_file >> y;
						ModFem_file >> z;
						ModFem_file >> k;
						ModFem_file >> l;
						x = abs(x);
						y = abs(y);
						z = abs(z);
						k = abs(k);
						l = abs(l);
						modfemcmr.elementsF5.push_back({ x - 1, y - 1, z - 1, k - 1, l - 1 });
					}
				}

				ModFem_file.close();

				//TODO tranlation from Element_F5 to Element_P6

				return cmr;
			}
		}
	}
}