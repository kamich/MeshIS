#pragma once
#include"NastranExporter.h"
#include<fstream>
using namespace std;
class TestNastran
{
private:	MeshIS::Model::Common::CMR cmr;

#pragma region Constructors
public:		TestNastran();
#pragma endregion

#pragma region Destructor
public:		~TestNastran();
#pragma endregion

#pragma region Print Methods
public:		void	print_CMR();
private:	void	print_vertexes();
private:	void	print_single_vertex(MeshIS::Model::Common::Vertex vertex, int id);
private:	void	print_single_element_t4(MeshIS::Model::Common::Element_T4 element,int id);
private:	void	print_single_element_p6(MeshIS::Model::Common::Element_P6 element,int id);
private:	void	print_elements_t4();
private:	void	print_elements_p6();
#pragma endregion

#pragma region Load Data From File Methods
private:	bool load_CMR_from_file(std::string path);
private:	void load_file_lines(std::fstream &file);
private:	std::string set_first_sign_and_delete_from_line(std::string &line);
private:	std::vector<std::string> split(std::string line, char pattern);
#pragma endregion

#pragma region Init Methods
public:		void	init_CMR();
private:
	template<typename mesh_part>
	mesh_part init_mesh_part(std::vector<string> line_vector);
#pragma endregion

#pragma region Run Export Method
public:		void	run_nastran(std::string path ,MeshIS::Model::Export::Nastran::NastranExporter::Type_Of_Nastran_Version type);
#pragma endregion

};

