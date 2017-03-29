//
// Created by Kiełbasa Karol on 28.03.2017.
//

#ifndef CPP_NASTRANEXPORTER_H
#define CPP_NASTRANEXPORTER_H
#include "../../MeshExporter.h"
#include "../BulkData/ShortBulkData.h"
#include"../BulkData/FreeBulkData.h"
#include"../BulkData/LongBulkData.h"
#include<iostream>
#include<fstream>
#include <iterator>
#include<vector>
#include<boost/filesystem/path.hpp>


using std::string;

namespace MeshIS
{
    namespace Model
    {
        namespace Export
        {
            namespace Nastran
            {
                class NastranExporter : public MeshIS::Model::Export::MeshExporter {

                public:     enum class Type_Of_Nastran_Version {
                        FREE,
                        SHORT,
                        LONG
                    };

                public:		enum class Type_Of_Method_Continuation {
                        PLUS_FILED,
                        STAR_FILED,
                        BLANK_FIELD
                    };

                private:	string absolute_file_path;
                private:	std::ofstream os;

                private:    Type_Of_Nastran_Version state_of_nastran_version;
                private:	Type_Of_Method_Continuation state_of_continuation_entrie;

                private:	short int gap;

                private:	BulkData *bulkData;
                private:	FreeBulkData fbd;
                private:	ShortBulkData sbd;
                private:	LongBulkData lbd;

                public:     NastranExporter();
                public:     NastranExporter(Type_Of_Nastran_Version type_of_nastran, Type_Of_Method_Continuation state_of_continuation_entrie);


                public:		void virtual Export(const string& absolute_file_path, const MeshIS::Model::Common::CMR& mesh_data);

                private:    void create_nastran_file_from_CMR(const string & absolute_file_path, const MeshIS::Model::Common::CMR & mesh_data);

                private:	void create_bulk_data(const MeshIS::Model::Common::CMR & mesh_data);
                private:	void set_GRID(const MeshIS::Model::Common::CMR & mesh_data);
                private:	void set_CTETRA(const MeshIS::Model::Common::CMR & mesh_data);
                private:	void set_CPENTA(const MeshIS::Model::Common::CMR & mesh_data);

                private:	void add_line_of_text_to_nastran_file(string line);

                private:    void set_gap();

                private:	void set_default_state();

                public:	void set_state_of_nastran_version(Type_Of_Nastran_Version type);
                };
            }
        }
    }
}

#endif //CPP_NASTRANEXPORTER_H
