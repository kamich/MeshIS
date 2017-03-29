#include "ParaviewVTKXMLexporter.h"
#include<boost\filesystem.hpp>
#include<iostream>

namespace MeshIS
{
	namespace Model
	{

		using Common::Element_T4;
		using Common::Element_P6;

		namespace Export
		{

			void ParaviewVTKXMLExporter::Export(const string& absolute_file_path, const CMR& mesh_data)
			{

				/*========================================
					check file exist in system to avoid 
					chagne file by accident
				=======================================*/
				if (boost::filesystem::exists(absolute_file_path)){
					std::cout << "File exist in system! Please change name." << std::endl;
					return;
				}

				/*========================================
						check correct filetype. 
				  =======================================*/
				std::string extension = boost::filesystem::extension(absolute_file_path);
				if (extension.c_str() != ".vtu") {
					std::cout << "Incorrect filetype. Correct is .vtu. Please change filetype." << std::endl;
					return;
				}

				/*
				char filetype[3] = { absolute_file_path[absolute_file_path.length() - 3],
									 absolute_file_path[absolute_file_path.length() - 2],
									 absolute_file_path[absolute_file_path.length() - 1]};
				if (filetype != ".vtk") {
					std::cout << "Incorrect filetype. Correct is .vtk. Please change filetype." << std::endl;
					return;
				}*/

				std::fstream fileStream;
				fileStream.open(absolute_file_path, std::fstream::out);
				
				if (!fileStream.good()) {
					std::cout << "Error while opening file." << std::endl;
					return;
				}

				/*========================================
						Export starts here
				=======================================*/
				const unsigned int noOfCells = mesh_data.elementsT4.size(); 

				fileStream << "<VTKFile type=\"UnstructuredGrid\" version=\"1.0\" byte_order=\"LittleEndian\" header_type=\"UInt64>" << std::endl;
				fileStream << " <UnstructuredGrid>" << std::endl;
				fileStream << "<Piece NumberOfPoints=\""<<mesh_data.vertices.size()<<"\" NumberOfCells=\""<<noOfCells<<"\">" << std::endl;
				fileStream << "<Points>" << std::endl;
				fileStream << "<DataArray type=\"Float64\" Name=\"Points\" NumberOfComponents=\"3\" format=\"ascii\">"  << std::endl;
				
				/*========================================
						put all vertices to file
				=======================================*/
				for (auto i = 0; i < mesh_data.vertices.size(); i+=2) {
					fileStream << mesh_data.vertices[i].at(0) << " "
						<< mesh_data.vertices[i].at(1) << " "
						<< mesh_data.vertices[i].at(2) << " "
						<< mesh_data.vertices[i + 1].at(0) << " "
						<< mesh_data.vertices[i + 1].at(1) << " "
						<< mesh_data.vertices[i + 1].at(2) << std::endl;
				}

				fileStream << "</DataArray>" << std::endl;
				fileStream << "</Points>" << std::endl;
				fileStream << "<Cells>" << std::endl;
				fileStream << "<DataArray type=\"Int64\" Name=\"connectivity\" format=\"ascii\">" << std::endl;

				/*========================================
						put all connecitivity to file
				=======================================*/
				for (auto i = 0; i < connectivities.size();i+=3) {
					fileStream << connectivities[i].at(0) << " "
						<< connectivities[i].at(1) << " "
						<< connectivities[i].at(2) << " "
						<< connectivities[i].at(3) << " "
						<< connectivities[i + 1].at(0) << " "
						<< connectivities[i + 1].at(1) << std::endl
						<< connectivities[i + 1].at(2) << " "
						<< connectivities[i + 1].at(3) << " "
						<< connectivities[i + 2].at(0) << " "
						<< connectivities[i + 2].at(1) << " "
						<< connectivities[i + 2].at(2) << " "
						<< connectivities[i + 2].at(3) << std::endl;
				};

				fileStream << "</DataArray>" << std::endl;
				fileStream << "<DataArray type=\"UInt64\" Name=\"types\" format=\"ascii\">" << std::endl;

				/*========================================
						VTK_TETRA
				=======================================*/
				if (mesh_data.elementsT4.size() < 0) {
						for (auto i = 0; i < mesh_data.elementsT4.size(); i+=6) {
							for (auto j = 0; j < 6; j++){
								fileStream << "10" << " ";
								}
							fileStream << std::endl;
					}
						fileStream << "</DataArray>" << std::endl;
						fileStream << "</Cells>" << std::endl;
						fileStream << "</Piece>" << std::endl;
						fileStream << "</UnstructuredGrid>" << std::endl;
						fileStream << "</VTKFile>" << std::endl;

				}

				fileStream.close();
			}

		}
	}
}