//*************************
//Created by Dominik Kopaczka
//*************************

#include "NastranExporter.h"

MeshIS::Model::Export::Nastran::NastranExporter::NastranExporter()
{
	set_default_state();
}

MeshIS::Model::Export::Nastran::NastranExporter::NastranExporter(
	Type_Of_Nastran_Version state_of_nastran_version,
	Type_Of_Method_Continuation state_of_continuation_entrie)
	: state_of_nastran_version(state_of_nastran_version),
	state_of_continuation_entrie(state_of_continuation_entrie)
{

}

void MeshIS::Model::Export::Nastran::NastranExporter::Export(
	const string & absolute_file_path,
	const MeshIS::Model::Common::CMR & mesh_data)
{
	set_gap();
	create_nastran_file_from_CMR(absolute_file_path, mesh_data);
}


void MeshIS::Model::Export::Nastran::NastranExporter::create_nastran_file_from_CMR(
	const string & absolute_file_path,
	const MeshIS::Model::Common::CMR & mesh_data)
{
	boost::filesystem::path p(absolute_file_path);
	os.open(p.c_str(), std::ios_base::out);
	if (os.good())
	{
		create_bulk_data(mesh_data);
	}
	os.close();
}

void MeshIS::Model::Export::Nastran::NastranExporter::create_bulk_data(const MeshIS::Model::Common::CMR & mesh_data)
{
	add_line_of_text_to_nastran_file("BEGIN BULK");
	set_GRID(mesh_data);
	set_CTETRA(mesh_data);
	set_CPENTA(mesh_data);
	add_line_of_text_to_nastran_file("END DATA");

	
}

void MeshIS::Model::Export::Nastran::NastranExporter::set_GRID(const MeshIS::Model::Common::CMR & mesh_data)
{
	add_line_of_text_to_nastran_file("$");
	add_line_of_text_to_nastran_file("$ GRID POINTS DESCRIBE THE GEOMETRY");
	add_line_of_text_to_nastran_file("$");
	auto index{ 1 };
	for (auto vertex : mesh_data.vertices)
	{
		os << bulkData->get_GRID_line_from_vertex(vertex, index)<<std::endl;
		index++;
	}
}

void MeshIS::Model::Export::Nastran::NastranExporter::set_CTETRA(const MeshIS::Model::Common::CMR & mesh_data)
{
	add_line_of_text_to_nastran_file("$");
	add_line_of_text_to_nastran_file("$ TETRAHEDRAL ELEMENTS");
	add_line_of_text_to_nastran_file("$");
	auto index{ 1 };
	for (auto elementT4 : mesh_data.elementsT4)
	{
		os << bulkData->get_CTETRA_line_from_elementT4(elementT4, index) << std::endl;
		index++;
	}
}

void MeshIS::Model::Export::Nastran::NastranExporter::set_CPENTA(const MeshIS::Model::Common::CMR & mesh_data)
{
	add_line_of_text_to_nastran_file("$");
	add_line_of_text_to_nastran_file("$ PRISMATIC ELEMENTS");
	add_line_of_text_to_nastran_file("$");
	auto index{ 1 };
	for (auto elementP6 : mesh_data.elementsP6)
	{
		os<<bulkData->get_CPENTA_line_from_elementP6(elementP6, index) << std::endl;
		index++;
	}
}

void MeshIS::Model::Export::Nastran::NastranExporter::add_line_of_text_to_nastran_file(string line)
{
	os << line << std::endl;
}


void MeshIS::Model::Export::Nastran::NastranExporter::set_gap()
{
	switch (this->state_of_nastran_version) {
	case Type_Of_Nastran_Version::FREE:
		this->gap = 0;
		this->bulkData = &fbd;
		break;

	case Type_Of_Nastran_Version::SHORT:
		this->bulkData = &sbd;
		this->gap = 8;
		break;

	case Type_Of_Nastran_Version::LONG:
		this->gap = 16;
		this->bulkData = &lbd;
		break;
	}
}

void MeshIS::Model::Export::Nastran::NastranExporter::set_default_state()
{
	this->state_of_nastran_version = Type_Of_Nastran_Version::FREE;
	this->state_of_continuation_entrie = Type_Of_Method_Continuation::BLANK_FIELD;
}

void MeshIS::Model::Export::Nastran::NastranExporter::set_state_of_nastran_version(Type_Of_Nastran_Version type)
{
	this->state_of_nastran_version = type;
}
