#pragma 
#ifndef SU2_IMPORTER_H_
#define SU2_IMPORTER_H_
#include "MeshImporter.h"

namespace MeshIS
{
	namespace Model
	{
		namespace Import
		{

			class SU2MeshImporter : public MeshImporter
			{
			public:
				Common::CMR Import(const string & absolute_file_path) override;

			private:
				Common::CMR cmr;
				std::vector<std::vector<int>> temp_elements;
				int elements_amount;

				void addElement(int, std::vector<int>&);
			};

			typedef  SU2MeshImporter SU2LImporter;

		}
	}
}

#endif