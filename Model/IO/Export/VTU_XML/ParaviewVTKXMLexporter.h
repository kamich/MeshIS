#pragma 
#ifndef MESHIS_PARAVIEW_VTK_XML_EXPORTER_H_
#define MESHIS_PARAVIEW_VTK_XML_EXPORTER_H_
#include "../MeshExporter.h"
#include "../../../Common/CommonMeshRepresentation.h"
#include "../../IO_Exceptions.h"


namespace MeshIS
{
	namespace Model
	{
		using Common::CMR;
		using Common::Element_P6;
		using Common::Element_T4;
		namespace Export
		{
			
			class ParaviewVTKXMLExporter: public MeshExporter
			{
			public:
				ParaviewVTKXMLExporter(){};
				ParaviewVTKXMLExporter(vector<Element_T4>  connT4): connectivitiesT4(connT4) {};
				ParaviewVTKXMLExporter(vector<Element_P6>  connP6): connectivitiesP6(connP6) {};
				ParaviewVTKXMLExporter(vector<Element_T4>  connT4, vector<Element_P6>  connP6) : connectivitiesT4(connT4), connectivitiesP6(connP6){};
				void Export(const string& absolute_file_path, const CMR& mesh_data) override;
				void setConnectivitiesT4(vector<Element_T4>  connectivitiesT4) ;
				void setConnectivitiesP6(vector<Element_P6>  connectivitiesP6) ;
			private:
				 void checkFileToSave(const string& absolute_file_path);
				 void putVerticesTofile(CMR mesh_data, std::fstream *fileStream);
				 void putConnectivityTofile(std::fstream *fileStream);
				 void putTypesTofile(CMR mesh_data, std::fstream *fileStream);
				 std::fstream * buildFstreamAndOpenFile(const std::string absolute_file_path);
				 vector<Element_T4>  connectivitiesT4;
				 vector<Element_P6>  connectivitiesP6;
			};

			typedef  ParaviewVTKXMLExporter VTKXMLImporter;

		}
	}
}


#endif
