//
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
	//copy(b.begin(),b.end(),ostream_iterator<string>{os,"\n"});              // kopiowanie na wyjście

	//return !is.eof() || !os; // zwrot błędu (2.2.1, 38.3)
}


vector<string> MeshIS::Model::Export::Nastran::NastranExporter::create_nastran_file_from_CMR(
	const MeshIS::Model::Common::CMR & mesh_data)
{
	create_bulk_data(mesh_data);
	
}

void MeshIS::Model::Export::Nastran::NastranExporter::create_bulk_data(const MeshIS::Model::Common::CMR & mesh_data)
{
	std::ofstream os{ absolute_file_path };
	set_GRID(mesh_data);
	set_CTETRA(mesh_data);
	set_CPENTA(mesh_data);
}

void MeshIS::Model::Export::Nastran::NastranExporter::set_GRID(const MeshIS::Model::Common::CMR & mesh_data)
{

}

void MeshIS::Model::Export::Nastran::NastranExporter::set_CTETRA(const MeshIS::Model::Common::CMR & mesh_data)
{
	for (MeshIS::Model::Common::Element_T4 element : mesh_data.)
	{
	}
}

void MeshIS::Model::Export::Nastran::NastranExporter::set_CPENTA(const MeshIS::Model::Common::CMR & mesh_data)
{
	for (MeshIS::Model::Common::Element_P6 element : mesh_data.elements)
	{
	}
}


void MeshIS::Model::Export::Nastran::NastranExporter::set_gap()
{
    switch (this->state_of_nastran_version){
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
