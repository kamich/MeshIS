#include "ParaviewVTKXMLexporter.h"
#include <iostream>
#include <fstream>


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
				std::fstream* fileStream = buildFstreamAndOpenFile(absolute_file_path);
				
				/*========================================
						Export starts here
				=======================================*/
				const unsigned int noOfCells = mesh_data.elementsT4.size() + mesh_data.elementsP6.size();

				*fileStream << "<VTKFile type=\"UnstructuredGrid\" version=\"1.0\" byte_order=\"LittleEndian\" header_type=\"UInt64\">" << std::endl;
				*fileStream << "<UnstructuredGrid>" << std::endl;
				*fileStream << "<Piece NumberOfPoints=\"" << mesh_data.vertices.size() << "\" NumberOfCells=\"" << noOfCells << "\">" << std::endl;
				*fileStream << "<PointData>" << std::endl;
				*fileStream << "</PointData>" << std::endl;
				*fileStream << "<CellData>" << std::endl;
				*fileStream << "</CellData>" << std::endl;
				*fileStream << "<Points>" << std::endl;
				*fileStream << "<DataArray type=\"Float64\" Name=\"Points\" NumberOfComponents=\"3\" format=\"ascii\">" << std::endl;

				putVerticesTofile(mesh_data, fileStream);

				*fileStream << std::endl << "</DataArray>" << std::endl;
				*fileStream << "</Points>" << std::endl;
				*fileStream << "<Cells>" << std::endl;
				*fileStream << "<DataArray type=\"Int64\" Name=\"connectivity\" format=\"ascii\">" << std::endl;

				putConnectivityTofile(fileStream);

				*fileStream << "</DataArray>" << std::endl;
				*fileStream << "<DataArray type=\"UInt8\" Name=\"types\" format=\"ascii\">" << std::endl;
				
				putTypesTofile(mesh_data,fileStream);

				*fileStream << std::endl << "</DataArray>" << std::endl;
				*fileStream << "</Cells>" << std::endl;
				*fileStream << "</Piece>" << std::endl;
				*fileStream << "</UnstructuredGrid>" << std::endl;
				*fileStream << "</VTKFile>" << std::endl;
				
				fileStream->close();

				std::cout << "Export Completed!" << std::endl;

			}
			void ParaviewVTKXMLExporter::setConnectivitiesT4(const vector<Element_T4>  connectivitiesT4){
				this->connectivitiesT4 = connectivitiesT4;
			}
			void ParaviewVTKXMLExporter::setConnectivitiesP6(const vector<Element_P6>  connectivitiesP6){
				this->connectivitiesP6 = connectivitiesP6;
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
			void ParaviewVTKXMLExporter::putVerticesTofile(CMR mesh_data, std::fstream *fileStream) {
				if (mesh_data.vertices.size() > 1)
				{
					for (unsigned int i = 1; i < mesh_data.vertices.size() + 1; i++) {

						*fileStream << mesh_data.vertices[i - 1].at(0) << " "
							<< mesh_data.vertices[i - 1].at(1) << " "
							<< mesh_data.vertices[i - 1].at(2) << " ";
						if (i % 2 == 0) {
							*fileStream << std::endl;
						}
					};
				}
			}
			void ParaviewVTKXMLExporter::putConnectivityTofile(std::fstream *fileStream) {
				if (connectivitiesT4.size() > 1)
				{
					for (unsigned int i = 0; i < connectivitiesT4.size() - 1; i++) {
						if (i % 2 == 0) {
							*fileStream << connectivitiesT4[i].at(0) << " "
								<< connectivitiesT4[i].at(1) << " "
								<< connectivitiesT4[i].at(2) << " "
								<< connectivitiesT4[i].at(3) << " "
								<< connectivitiesT4[i + 1].at(0) << " "
								<< connectivitiesT4[i + 1].at(1) << std::endl;
						}
						else {
							*fileStream << connectivitiesT4[i].at(0) << " "
								<< connectivitiesT4[i].at(1) << " "
								<< connectivitiesT4[i + 1].at(0) << " "
								<< connectivitiesT4[i + 1].at(1) << " "
								<< connectivitiesT4[i + 1].at(2) << " "
								<< connectivitiesT4[i + 1].at(3) << std::endl;

						}

					};
				}

				if (connectivitiesP6.size() > 0) {
					for (unsigned int i = 0; i < connectivitiesP6.size(); i++) {
						for (unsigned int j = 0; j < 5; j++) {
							*fileStream << connectivitiesP6[i].at(j) << " ";
						}
						*fileStream << connectivitiesP6[i].at(5) << std::endl;

					};
				}
			}
			void ParaviewVTKXMLExporter::putTypesTofile(CMR mesh_data, std::fstream *fileStream) {

				/*========================================
					VTK_TETRA - 4POINT FIGURE
				=======================================*/
				if (mesh_data.elementsT4.size() > 0) {
					for (unsigned int i = 1; i < mesh_data.elementsT4.size() + 1; i++) {
						*fileStream << "10" << " ";
						if (i % 6 == 0) {
							*fileStream << std::endl;
						}
					}
				}
				/*========================================
					VTK_WEDGE - 6POINT FIGURE
				=======================================*/
				if (mesh_data.elementsP6.size() > 0) {
					for (unsigned int i = 1; i < mesh_data.elementsP6.size() + 1; i++) {
						*fileStream << "13" << " ";
						if (i % 6 == 0) {
							*fileStream << std::endl;
						}
					}

				}
			}
			std::fstream* ParaviewVTKXMLExporter::buildFstreamAndOpenFile(const std::string absolute_file_path) {
				
				std::fstream *fileStream = new std::fstream(absolute_file_path);
				fileStream->open(absolute_file_path, std::ios::out |std::ios::trunc);
				fileStream->close();				
				fileStream->flush();
				fileStream->open(absolute_file_path, std::ios::out);

				if (!fileStream->good()) {
					std::cout << "Error while opening file.\nEnter will close program." << std::endl;
					std::cin.get();
					fileStream->close();
					exit(0);
				}
				return fileStream;
			}
			}
	}
}
