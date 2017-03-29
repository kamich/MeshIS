#pragma 
#ifndef MESHIS_PARAVIEW_VTK_XML_EXPORTER_H_
#define MESHIS_PARAVIEW_VTK_XML_EXPORTER_H_
#include "..\MeshExporter.h"
#include "..\..\..\Common\CommonMeshRepresentation.h"


namespace MeshIS
{
	namespace Model
	{
		namespace Export
		{

			class ParaviewVTKXMLExporter: public MeshExporter
			{
			public:
				void Export(const string& absolute_file_path, const CMR& mesh_data) override;
				void setConnectivities(const vector<Element_T4>  connectivities);
			private:
				vector<Element_T4>  connectivities;
			};

			typedef  ParaviewVTKXMLExporter VTKXMLImporter;

		}
	}
}


#endif