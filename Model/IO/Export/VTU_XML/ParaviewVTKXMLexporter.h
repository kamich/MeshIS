#pragma
#ifndef MESHIS_PARAVIEW_VTK_XML_EXPORTER_H_
#define MESHIS_PARAVIEW_VTK_XML_EXPORTER_H_
#include "../MeshExporter.h"
#include "../../../Common/CommonMeshRepresentation.h"
#include "../../IO_Exceptions.h"
#include <fstream>
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
				void Export(const string& absolute_file_path, const CMR& mesh_data) override;
			private:
				std::fstream fileStream;
				void checkFileToSave(const string& absolute_file_path);
				void putVerticesTofile(const CMR& mesh_data);
				void putConnectivityTofile(const CMR& mesh_data);
				void putTypesTofile(const CMR& mesh_data);
			};

			typedef  ParaviewVTKXMLExporter VTKXMLExporter;

		}
	}
}
#endif
