#include "ParaviewVTKXMLexporter.h"
#include <iostream>


namespace MeshIS
{
	namespace Model
	{

		using Common::Element_T4;
		using Common::Element_P6;

		namespace Export
		{

			void ParaviewVTKXMLExporter::Export(const std::string& absolute_file_path, const CMR& mesh_data)
			{
				checkFileToSave(absolute_file_path);
				fileStream.open(absolute_file_path, std::ios::out | std::ios::trunc);
				
				if(!fileStream.good()){
					std::cout << "Error while opening file.\nEnter will close program." << std::endl;
					std::cin.get();
					fileStream.close();
					exit(0);
				}
				const unsigned int noOfCells = mesh_data.elementsT4.size() + mesh_data.elementsP6.size();

				fileStream << "<VTKFile type=\"UnstructuredGrid\" version=\"1.0\" byte_order=\"LittleEndian\" header_type=\"UInt64\">" << std::endl;
				fileStream << "<UnstructuredGrid>" << std::endl;
				fileStream << "<Piece NumberOfPoints=\"" << mesh_data.vertices.size() << "\" NumberOfCells=\"" << noOfCells << "\">" << std::endl;
				fileStream << "<PointData>" << std::endl;
				fileStream << "</PointData>" << std::endl;
				fileStream << "<CellData>" << std::endl;
				fileStream << "</CellData>" << std::endl;
				fileStream << "<Points>" << std::endl;
				fileStream << "<DataArray type=\"Float64\" Name=\"Points\" NumberOfComponents=\"3\" format=\"ascii\">" << std::endl;

				putVerticesTofile(mesh_data);

				fileStream << std::endl << "</DataArray>" << std::endl;
				fileStream << "</Points>" << std::endl;
				fileStream << "<Cells>" << std::endl;
				fileStream << "<DataArray type=\"Int64\" Name=\"connectivity\" format=\"ascii\">" << std::endl;

				putConnectivityTofile(mesh_data);

				fileStream << "</DataArray>" << std::endl;
				fileStream << "<DataArray type=\"UInt8\" Name=\"types\" format=\"ascii\">" << std::endl;
				
				putTypesTofile(mesh_data);

				fileStream << std::endl << "</DataArray>" << std::endl;
				fileStream << "</Cells>" << std::endl;
				fileStream << "</Piece>" << std::endl;
				fileStream << "</UnstructuredGrid>" << std::endl;
				fileStream << "</VTKFile>" << std::endl;
				
				fileStream.close();

				std::cout << "Export Completed!" << std::endl;

			}
			void ParaviewVTKXMLExporter::checkFileToSave(const string& absolute_file_path) {	
				const char extension[4] = { absolute_file_path[absolute_file_path.size() - 4],
							absolute_file_path[absolute_file_path.size() - 3],
							absolute_file_path[absolute_file_path.size() - 2],
							absolute_file_path[absolute_file_path.size() - 1]};
								
				if ( extension[0] != '.' || extension[1] != 'v'
					&& extension[2] != 't' || extension[3] != 'u') {
					std::cout << "Incorrect filetype. Correct is .vtu. Please change filetype.\nEnter will close program." << std::endl;
					std::cin.get();
					exit(0);
				}
			}
			void ParaviewVTKXMLExporter::putVerticesTofile(const CMR& mesh_data) {
				if (mesh_data.vertices.size() > 1)
				{
					for (unsigned int i = 1; i < mesh_data.vertices.size() + 1; i++) {

						fileStream << mesh_data.vertices[i - 1].at(0) << " "
							<< mesh_data.vertices[i - 1].at(1) << " "
							<< mesh_data.vertices[i - 1].at(2) << " ";
						if (i % 2 == 0) {
							fileStream << std::endl;
						}
					};
				}
			}
			void ParaviewVTKXMLExporter::putConnectivityTofile(const CMR& mesh_data) {
				if (mesh_data.elementsT4.size() > 1){
					for (unsigned int i = 0; i < mesh_data.elementsT4.size() - 1; i++) {
						if (i % 2 == 0) {
							fileStream << mesh_data.elementsT4[i].at(0) << " "
								<< mesh_data.elementsT4[i].at(1) << " "
								<< mesh_data.elementsT4[i].at(2) << " "
								<< mesh_data.elementsT4[i].at(3) << " "
								<< mesh_data.elementsT4[i + 1].at(0) << " "
								<< mesh_data.elementsT4[i + 1].at(1) << std::endl;
						}
						else {
							fileStream << mesh_data.elementsT4[i].at(0) << " "
								<< mesh_data.elementsT4[i].at(1) << " "
								<< mesh_data.elementsT4[i + 1].at(0) << " "
								<< mesh_data.elementsT4[i + 1].at(1) << " "
								<< mesh_data.elementsT4[i + 1].at(2) << " "
								<< mesh_data.elementsT4[i + 1].at(3) << std::endl;

						}

					};
				}
				
				if (mesh_data.elementsP6.size() > 0) {
					for (unsigned int i = 0; i < mesh_data.elementsP6.size(); i++) {
						for (unsigned int j = 0; j < 5; j++) {
							fileStream << mesh_data.elementsP6[i].at(j) << " ";
						}
						fileStream << mesh_data.elementsP6[i].at(5) << std::endl;

					};
				}
			}
			void ParaviewVTKXMLExporter::putTypesTofile(const CMR& mesh_data) {
				if (mesh_data.elementsT4.size() > 0) {
					for (unsigned int i = 1; i < mesh_data.elementsT4.size() + 1; i++) {
						fileStream << "10" << " ";
						if (i % 6 == 0) {
							fileStream << std::endl;
						}
					}
				}
				if (mesh_data.elementsP6.size() > 0) {
					for (unsigned int i = 1; i < mesh_data.elementsP6.size() + 1; i++) {
						fileStream << "13" << " ";
						if (i % 6 == 0) {
							fileStream << std::endl;
						}
					}

				}
			}

			}
	}
}
