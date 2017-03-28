#include "TestNastran.h"



TestNastran::TestNastran()
{
}


TestNastran::~TestNastran()
{
}

void TestNastran::init_CMR()
{
	string path;
	std::cin >> path;  // pobranie nazw plików Ÿród³owego i docelowego
	load_CMR_from_file(path);
}

void TestNastran::print_CMR()
{
	print_vertexes();
	print_elements_t4();
	print_elements_p6();
}


void TestNastran::print_single_vertex(
	MeshIS::Model::Common::Vertex vertex,
	int id)
{	
	cout << "Vertex: ";
	cout << "ID: " << id << "\t\t";
	for(int i=0;i<vertex.size();i++)
		std::cout << vertex[i]<< " ";
	std::cout << endl;
}

void TestNastran::print_single_element_t4(
	MeshIS::Model::Common::Element_T4 element,
	int id)
{
	cout << "elementT4: ";
	cout << "ID: " << id << "\t";
	for (int i = 0; i<element.size(); i++)
		std::cout << element[i] << " ";
	std::cout << endl;
}


void TestNastran::print_single_element_p6(
	MeshIS::Model::Common::Element_P6 element,
	int id)
{
	cout << "elementP6: ";
	cout << "ID: " << id <<"\t";
	for (int i = 0; i<element.size(); i++)
		std::cout << element[i] << " ";
	std::cout << endl;
}
void TestNastran::print_vertexes()
{
	auto id{ 1 };
	for (auto vertex : cmr.vertices)
		print_single_vertex(vertex,id++);
}


void TestNastran::print_elements_t4()
{
	auto id{ 1 };
	for (auto element : cmr.elementsT4)
		print_single_element_t4(element,id++);

}

void TestNastran::print_elements_p6()
{
	auto id{ 1 };
	for (auto element : cmr.elementsP6)
		print_single_element_p6(element,id++);
}

bool TestNastran::load_CMR_from_file(
	std::string path)
{
	std::fstream file { path };
	file.open(path + ".txt", std::ios::in);
	

	if (file.good())
	{
		load_file_lines(file);
		return true;
	}
	else
	{
		return false;
	}

}

void TestNastran::load_file_lines(
	std::fstream & file)
{
	std::string line;
	std::string firstSign;
	int nextElement = 0;
	int nextNode = 0;

	while (getline(file, line))
	{
		firstSign = set_first_sign_and_delete_from_line(line) ;
		std::vector<string> line_vector = split(line,',');
		if (firstSign == "v")
		{
			MeshIS::Model::Common::Vertex vertex = { init_mesh_part<MeshIS::Model::Common::Vertex> (line_vector)};

			cmr.vertices.push_back(vertex);
		}
		else if (firstSign == "e")
		{
			MeshIS::Model::Common::Element_T4 element = { init_mesh_part<MeshIS::Model::Common::Element_T4>(line_vector) };

			cmr.elementsT4.push_back(element);
		}
		else if (firstSign == "p")
		{
			MeshIS::Model::Common::Element_P6 element = { init_mesh_part<MeshIS::Model::Common::Element_P6>(line_vector) };

			cmr.elementsP6.push_back(element);
		}
	}
}

std::string TestNastran::set_first_sign_and_delete_from_line(
	std::string & line)
{
	std::string first_sign = line.substr(0, line.find(','));
	line = line.erase(0, (line.find(',') + 1));
	return first_sign;
}

std::vector<std::string> TestNastran::split(
	std::string line, 
	char pattern)
{
	std::vector<std::string> splitVector;
	
	while (line != "") {

		std::string newSign = line.substr(0, line.find(pattern));
		//usuwam do kolejnego przecinka
		line = line.erase(0, (line.find(pattern) + 1));
		splitVector.push_back(newSign);

	}
	return splitVector;
}
template<typename mesh_part>
mesh_part TestNastran::init_mesh_part(
	std::vector<string> line_vector)
{
	mesh_part mp;
	int mp_index = 0;
	for (auto coordinate_string : line_vector) 
	{
		double coordinate= atof(coordinate_string.c_str());
		mp[mp_index++] = coordinate;
	}
	return mp;
}


void TestNastran::run_nastran(
	std::string path, 
	MeshIS::Model::Export::Nastran::NastranExporter::Type_Of_Nastran_Version type)
{
	MeshIS::Model::Export::Nastran::NastranExporter nastran;
	nastran.set_state_of_nastran_version(type);
	nastran.Export(path, cmr);
}
