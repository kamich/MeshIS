//*************************
//Created by Dominik Kopaczka
//*************************

#include "NastranExporter.h"
#include "../BulkData/ShortBulkData.h"
#include"../BulkData/FreeBulkData.h"
#include"../BulkData/LongBulkData.h"
#include<vector>
#include<boost\filesystem\path.hpp>

using namespace MeshIS::Model::Export::Nastran;

//Local functions using in "Export" function/////////////////////////////////////////////////


template<class type_of_mesh_part>
using pointer_to_virtual_function_from_bulk_data = std::string(BulkData::*)(type_of_mesh_part, int);

/*
	Template for creating a bulk data block in "set_GRID","set_CTETRA" and "set_CPENTA" functions.
*/
template<class type_of_mesh_part>
void set_block_of_bulk_data(
	std::vector<type_of_mesh_part> const& mesh_data,
	pointer_to_virtual_function_from_bulk_data<type_of_mesh_part> const ptr_to_bulk_data_fn, 
	std::unique_ptr<File>& ptr_file_members) noexcept
{
	auto index{ 1 };
	for (auto mesh_part : mesh_data)
	{
		(ptr_file_members->os) << ((ptr_file_members->bulkData)->*ptr_to_bulk_data_fn)(mesh_part, index) << std::endl;
		index++;
	}
}

void add_line_of_text_to_nastran_file(
	string line, 
	std::ofstream& os)
	noexcept
{
	os << line << std::endl;
}

void set_header(
	string & string, 
	std::ofstream& os)
{
	add_line_of_text_to_nastran_file("$", os);
	add_line_of_text_to_nastran_file("$ " + string, os);
	add_line_of_text_to_nastran_file("$", os);
}

void set_GRID(
	const CMR & mesh_data, 
	std::unique_ptr<File>& ptr_file_members)
	noexcept
{
	set_header(std::string{ "GRID POINTS DESCRIBE THE GEOMETRY" }, ptr_file_members->os);
	set_block_of_bulk_data(mesh_data.vertices, &BulkData::get_GRID_line_from_vertex, ptr_file_members);
}

void set_CTETRA(
	const CMR & mesh_data, 
	std::unique_ptr<File>& ptr_file_members)
	noexcept
{
	set_header(std::string{ "TETRAHEDRAL ELEMENTS" }, ptr_file_members->os);
	set_block_of_bulk_data(mesh_data.elementsT4, &BulkData::get_CTETRA_line_from_elementT4, ptr_file_members);
}

void set_CPENTA(
	const CMR & mesh_data, 
	std::unique_ptr<File>& ptr_file_members)
	noexcept
{
	set_header(std::string{ "PRISMATIC ELEMENTS" }, ptr_file_members->os);
	set_block_of_bulk_data(mesh_data.elementsP6, &BulkData::get_CPENTA_line_from_elementP6, ptr_file_members);
}

void create_bulk_data(
	const CMR & mesh_data, 
	std::unique_ptr<File>& ptr_file_members)
	noexcept
{
	add_line_of_text_to_nastran_file("BEGIN BULK", ptr_file_members->os);
	set_GRID(mesh_data, ptr_file_members);
	set_CTETRA(mesh_data, ptr_file_members);
	set_CPENTA(mesh_data, ptr_file_members);
	add_line_of_text_to_nastran_file("END DATA", ptr_file_members->os);
}

void create_nastran_file_from_CMR(
	const string & absolute_file_path,
	const CMR & mesh_data, 
	std::unique_ptr<File>& ptr_file_members)
	noexcept
{
	boost::filesystem::path p(absolute_file_path);
	ptr_file_members->os.open(p.string(), std::ios_base::out);
	if (ptr_file_members->os.good())
		create_bulk_data(mesh_data, ptr_file_members);
	ptr_file_members->os.close();
}

void set_bulkdata_pointer_depending_on_the_nastran_version_state(
	std::unique_ptr<File>& ptr_file_members)
noexcept
{
	switch (ptr_file_members->state_of_nastran_version) {
	case NastranExporter::Type_Of_Nastran_Version::FREE:
		ptr_file_members->bulkData = new FreeBulkData;
		break;

	case NastranExporter::Type_Of_Nastran_Version::SHORT:
		ptr_file_members->bulkData = new ShortBulkData;
		break;

	case NastranExporter::Type_Of_Nastran_Version::LONG:
		ptr_file_members->bulkData = new LongBulkData;
		break;
	}
}

//////////////////////////////////////////////////////////////////////////////////////

//Functions from NastranExporter class////////////////////////////////////////////////
NastranExporter::NastranExporter()
	:ptr_file_members(std::make_unique<File>())
{
	set_default_state();
}

NastranExporter::NastranExporter(
	Type_Of_Nastran_Version state_of_nastran_version)
	:ptr_file_members(std::make_unique<File>())	
{
	ptr_file_members->state_of_nastran_version = { state_of_nastran_version };
	ptr_file_members->bulkData={ nullptr };
}


void NastranExporter::Export(
	const string & absolute_file_path,
	const CMR & mesh_data)
	
{
	set_bulkdata_pointer_depending_on_the_nastran_version_state(ptr_file_members);
	create_nastran_file_from_CMR(absolute_file_path, mesh_data, ptr_file_members);
}

void NastranExporter::set_default_state() 
	noexcept
{
	ptr_file_members->state_of_nastran_version = Type_Of_Nastran_Version::SHORT;
}

void NastranExporter::set_state_of_nastran_version(
	Type_Of_Nastran_Version type) 
	noexcept
{
	ptr_file_members->state_of_nastran_version = type;
}
//////////////////////////////////////////////////////////////////////////////////////
