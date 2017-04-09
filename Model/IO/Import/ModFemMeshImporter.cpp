#include "ModFEMMeshImporter.h"


namespace MeshIS
{
	namespace Model
	{
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

				importPoints(ModFem_file);

				importEdges(ModFem_file);

				importFaces(ModFem_file);

				importElements(ModFem_file);

				ModFem_file.close();

				translateF4toT4(modfemcmr.elementsF4);

				translateF5toP6(modfemcmr.elementsF5);

				return cmr;
			}
			void ModFEMMeshImporter::importPoints(std::fstream &ModFem_file)
			{
				ModFem_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


				ModFem_file >> vertex_amount;
				ModFem_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				for (size_t i = 0; i < vertex_amount; ++i)
				{

					ModFem_file >> _points[0];
					ModFem_file >> _points[1];
					ModFem_file >> _points[2];
					cmr.vertices.push_back({ _points[0], _points[1], _points[1] });
				}
			}
			void ModFEMMeshImporter::importEdges(std::fstream &ModFem_file)
			{
				ModFem_file >> edges_amount;
				ModFem_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				for (size_t i = 0; i < edges_amount; ++i)
				{
					ModFem_file.ignore(std::numeric_limits<std::streamsize>::max(), '1');
					ModFem_file >> _vertices[0];
					ModFem_file >> _vertices[1];
					modfemcmr.edges.push_back({ _vertices[0] - 1, _vertices[1] - 1 });
				}

			}
			void ModFEMMeshImporter::importFaces(std::fstream &ModFem_file)
			{
				ModFem_file >> face_amount;
				ModFem_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				for (size_t i = 0; i < face_amount; ++i)
				{
					ModFem_file >> type;
					ModFem_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

					if (type == 3)
					{
						ModFem_file >> _edges[0];
						ModFem_file >> _edges[1];
						ModFem_file >> _edges[2];
						_edges[0] = abs(_edges[0]);
						_edges[1] = abs(_edges[1]);
						_edges[2] = abs(_edges[2]);
						modfemcmr.triangularfaces.push_back({ _edges[0] - 1, _edges[1] - 1, _edges[2] - 1 });
						faces.push_back(modfemcmr.triangularfaces.back());
					}
					else if (type == 4)
					{
						ModFem_file >> _edges[0];
						ModFem_file >> _edges[1];
						ModFem_file >> _edges[2];
						ModFem_file >> _edges[3];
						_edges[0] = abs(_edges[0]);
						_edges[1] = abs(_edges[1]);
						_edges[2] = abs(_edges[2]);
						_edges[3] = abs(_edges[3]);

						modfemcmr.quadrilateralfaces.push_back({ _edges[0] - 1, _edges[1] - 1, _edges[2] - 1,  _edges[3] - 1 });
						faces.push_back(modfemcmr.quadrilateralfaces.back());
					}
				}
			}
			void ModFEMMeshImporter::importElements(std::fstream &ModFem_file)
			{
				ModFem_file >> elements_amount;
				ModFem_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				for (size_t i = 0; i < elements_amount; ++i)
				{
					ModFem_file >> type;
					ModFem_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					if (type == 5)
					{
						ModFem_file >> _faces[0];
						ModFem_file >> _faces[1];
						ModFem_file >> _faces[2];
						ModFem_file >> _faces[3];
						ModFem_file >> _faces[4];
						_faces[0] = abs(_faces[0]);
						_faces[1] = abs(_faces[1]);
						_faces[2] = abs(_faces[2]);
						_faces[3] = abs(_faces[3]);
						_faces[4] = abs(_faces[4]);
						modfemcmr.elementsF5.push_back({ _faces[0] - 1, _faces[1] - 1, _faces[2] - 1, _faces[3] - 1, _faces[4] - 1 });
					}
					if (type == 7)
					{
						ModFem_file >> _faces[0];
						ModFem_file >> _faces[1];
						ModFem_file >> _faces[2];
						ModFem_file >> _faces[3];
						_faces[0] = abs(_faces[0]);
						_faces[1] = abs(_faces[1]);
						_faces[2] = abs(_faces[2]);
						_faces[3] = abs(_faces[3]);
						modfemcmr.elementsF4.push_back({ _faces[0] - 1, _faces[1] - 1, _faces[2] - 1, _faces[3] - 1 });
					}
				}
			}
			void ModFEMMeshImporter::translateF5toP6(std::vector<MeshIS::Model::Common::Element_F5>&elementsF5)
			{
				std::set<int> nodes;
				for (auto current_element : elementsF5)
				{
					nodes.clear();
					for (auto current_face : current_element)
					{
						if (faces[current_face].which() == 0) // triangular
						{
							TriangularFace current_triangular_face = boost::get<TriangularFace>(faces[current_face]);
							for (auto current_edge : current_triangular_face)
							{
								for (auto current_vertex : modfemcmr.edges[current_edge])
								{
									nodes.insert(current_vertex);
								}
							}
						}
						else //quadrilateral
						{
							QuadrilateralFace current_quadrilateral_face = boost::get<QuadrilateralFace>(faces[current_face]);
							for (auto current_edge : current_quadrilateral_face)
							{
								for (auto current_vertex : modfemcmr.edges[current_edge])
								{
									nodes.insert(current_vertex);
								}
							}
						}

					}
					int i = 0;
					for (auto current_vertex : nodes)
					{
						_vertices[i] = current_vertex;
						i++;
					}
					cmr.elementsP6.push_back(Element_P6{ _vertices[0], _vertices[1], _vertices[2], _vertices[3], _vertices[4], _vertices[5] });
				}

			}
			void ModFEMMeshImporter::translateF4toT4(std::vector<MeshIS::Model::Common::Element_F4>&elementsF4)
			{
				std::set<int> nodes;
				for (auto current_element : elementsF4)
				{
					nodes.clear();
					for (auto current_face : current_element)
					{
						if (faces[current_face].which() == 0) // triangular
						{
							TriangularFace current_triangular_face = boost::get<TriangularFace>(faces[current_face]);
							for (auto current_edge : current_triangular_face)
							{
								for (auto current_vertex : modfemcmr.edges[current_edge])
								{
									nodes.insert(current_vertex);
								}
							}
						}
						else //quadrilateral
						{
							QuadrilateralFace current_quadrilateral_face = boost::get<QuadrilateralFace>(faces[current_face]);
							for (auto current_edge : current_quadrilateral_face)
							{
								for (auto current_vertex : modfemcmr.edges[current_edge])
								{
									nodes.insert(current_vertex);
								}
							}
						}

					}
					int i = 0;
					for (auto current_vertex : nodes)
					{
						_vertices[i] = current_vertex;
						i++;
					}
					cmr.elementsT4.push_back(Element_T4{ _vertices[0], _vertices[1], _vertices[2], _vertices[3] });
				}

			}


		}
	}
}