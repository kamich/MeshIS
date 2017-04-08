//*************************
//Created by Dominik Kopaczka
//*************************

#include "NastranExporter.h"

using namespace MeshIS::Model::Export::Nastran;

NastranExporter::NastranExporter()
	:bulkData(nullptr)
{
	set_default_state();
}

NastranExporter::NastranExporter(
	Type_Of_Nastran_Version state_of_nastran_version)
	: state_of_nastran_version(state_of_nastran_version),
	bulkData(nullptr)
{
}

MeshIS::Model::Export::Nastran::NastranExporter::~NastranExporter()
{
	delete bulkData;
}

void NastranExporter::Export(
	const string & absolute_file_path,
	const CMR & mesh_data)
	
{
	set_bulkdata_pointer_depending_on_the_nastran_version_state();
	create_nastran_file_from_CMR(absolute_file_path, mesh_data);
}


void NastranExporter::create_nastran_file_from_CMR(
	const string & absolute_file_path,
	const CMR & mesh_data)
	noexcept
{
	boost::filesystem::path p(absolute_file_path);
	os.open(p.string(), std::ios_base::out);
	if (os.good())
		create_bulk_data(mesh_data);
	os.close();
}

void NastranExporter::create_bulk_data(
	const CMR & mesh_data)
	noexcept
{
	add_line_of_text_to_nastran_file("BEGIN BULK");
	set_GRID(mesh_data);
	set_CTETRA(mesh_data);
	set_CPENTA(mesh_data);
	add_line_of_text_to_nastran_file("END DATA");
}



void NastranExporter::set_GRID(
	const CMR & mesh_data)
	noexcept
{
	set_header(std::string{ "GRID POINTS DESCRIBE THE GEOMETRY" });
	set_block_of_bulk_data(mesh_data.vertices, &BulkData::get_GRID_line_from_vertex);
}

void NastranExporter::set_CTETRA(
	const CMR & mesh_data)
	noexcept
{
	set_header(std::string{ "TETRAHEDRAL ELEMENTS" });
	set_block_of_bulk_data( mesh_data.elementsT4, &BulkData::get_CTETRA_line_from_elementT4);
}

void NastranExporter::set_CPENTA(
	const CMR & mesh_data)
	noexcept
{
	set_header(std::string{ "PRISMATIC ELEMENTS" });
	set_block_of_bulk_data(mesh_data.elementsP6, &BulkData::get_CPENTA_line_from_elementP6);
}

void MeshIS::Model::Export::Nastran::NastranExporter::set_header(string & string)
{
	add_line_of_text_to_nastran_file("$");
	add_line_of_text_to_nastran_file("$ " + string);
	add_line_of_text_to_nastran_file("$");
}

void NastranExporter::add_line_of_text_to_nastran_file(
	string line) 
	noexcept
{
	os << line << std::endl;
}


void NastranExporter::set_bulkdata_pointer_depending_on_the_nastran_version_state() 
	noexcept
{
	switch (this->state_of_nastran_version) {
	case Type_Of_Nastran_Version::FREE:
		this->bulkData= new FreeBulkData;
		break;

	case Type_Of_Nastran_Version::SHORT:
		this->bulkData = new ShortBulkData;
		break;

	case Type_Of_Nastran_Version::LONG:
		this->bulkData = new LongBulkData;
		break;
	}
}

void NastranExporter::set_default_state() 
	noexcept
{
	this->state_of_nastran_version = Type_Of_Nastran_Version::FREE;
}

void NastranExporter::set_state_of_nastran_version(
	Type_Of_Nastran_Version type) 
	noexcept
{
	this->state_of_nastran_version = type;
}

