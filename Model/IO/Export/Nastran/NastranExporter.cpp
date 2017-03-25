
// Created by lordkopakos on 2017-03-17.
//

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
	create_nastran_file_from_CMR(mesh_data);

	//set<string> b{ istream_iterator<string>{is},istream_iterator<string>{ } }; // wczytywanie danych
	//copy(b.begin(),b.end(),ostream_iterator<string>{os,"\n"});              // kopiowanie na wyjœcie

	//return !is.eof() || !os; // zwrot b³êdu (2.2.1, 38.3)
}


vector<string> MeshIS::Model::Export::Nastran::NastranExporter::create_nastran_file_from_CMR(
	const MeshIS::Model::Common::CMR & mesh_data)
{
	os.open(absolute_file_path, std::ios_base::out);
	if (os.good) 
	{
		create_bulk_data(mesh_data);
	}
	os.close();
}

void MeshIS::Model::Export::Nastran::NastranExporter::create_bulk_data(const MeshIS::Model::Common::CMR & mesh_data)
{
	
	set_GRID(mesh_data);
	set_CTETRA(mesh_data);
	set_CPENTA(mesh_data);
	
}

void MeshIS::Model::Export::Nastran::NastranExporter::set_GRID(const MeshIS::Model::Common::CMR & mesh_data)
{

	for (auto vertex : mesh_data.vertices)
	{
		auto line_of_GRID_data{ "GRID" };

	}
}

void MeshIS::Model::Export::Nastran::NastranExporter::set_CTETRA(const MeshIS::Model::Common::CMR & mesh_data)
{
	for (auto elementT4 : mesh_data.elementsT4)
	{
		auto line_of_CTETRA_data{ "CTETRA" };
	}
}

void MeshIS::Model::Export::Nastran::NastranExporter::set_CPENTA(const MeshIS::Model::Common::CMR & mesh_data)
{
	for (auto elementP6 : mesh_data.elementsP6)
	{
		auto line_of_CPENTA_data{ "CPENTA" };
	}
}


void MeshIS::Model::Export::Nastran::NastranExporter::set_gap()
{
	switch (this->state_of_nastran_version) {
	case Type_Of_Nastran_Version::FREE:
		this->gap = 0;
		break;
	case Type_Of_Nastran_Version::SHORT:
		this->gap = 8;
		break;
	case Type_Of_Nastran_Version::LONG:
		this->gap = 16;
		break;
	}
}

void MeshIS::Model::Export::Nastran::NastranExporter::set_default_state()
{
	this->state_of_nastran_version = Type_Of_Nastran_Version::FREE;
	this->state_of_continuation_entrie = Type_Of_Method_Continuation::BLANK_FIELD;
}
