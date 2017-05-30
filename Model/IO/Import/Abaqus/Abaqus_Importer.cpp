//
// Created by Lukasz on 27.03.2017.
//

#include "Abaqus_Importer.h"
#include <fstream>


MeshIS::Model::Common::CMR Abaqus_Importer::Import(const string &absolute_file_path) {


	MeshIS::Model::Common::CMR Abaqus_Elements;

	Set_Nodes(absolute_file_path, Abaqus_Elements);

	Set_Elements(absolute_file_path, Abaqus_Elements);

	return Abaqus_Elements;

}

void Abaqus_Importer::Set_Nodes(const string & absolute_file_path, MeshIS::Model::Common::CMR &Abaqus_Elements) {

	std::fstream data_file = open_abaqus_file(absolute_file_path);

	string line;

	size_t positions_start;
	size_t positions_end;

	bool start_import = false;
	bool end_import = false;


	int node_id;

	string node_dimension[3];
	double node_dim[3];
	
	while (!data_file.eof()) {
		
		getline(data_file, line);

		positions_end = line.find("Elements");
		if (positions_end != string::npos) {
			end_import = true;
		}

		if (start_import && !end_import) {
			

			delete_point(line);
			std::istringstream iss(line);
			iss >> node_id >> node_dimension[0] >>
				node_dimension[1] >> node_dimension[2];

			node_dim[0] = scientific_notation(node_dimension[0]);
			node_dim[1] = scientific_notation(node_dimension[1]);
			node_dim[2] = scientific_notation(node_dimension[2]);
			Abaqus_Elements.vertices.push_back({ node_dim[0], node_dim[1], node_dim[2] });

		}

		positions_start = line.find("NODE");
		if (positions_start != string::npos) {
			start_import = true;
		}

	}

	data_file.close();

}
void Abaqus_Importer::Set_Elements(const string & absolute_file_path, MeshIS::Model::Common::CMR &Abaqus_Elements) {

	std::fstream data_file = open_abaqus_file(absolute_file_path);

	string line;

	size_t positions_start;
	size_t positions_end;

	bool start_import = false;
	bool end_import = false;
	

	while (!data_file.eof()) {
		
		getline(data_file, line);

		positions_end = line.find("set");
		if (positions_end != string::npos) {
			end_import = true;
		} 

		if (start_import && !end_import) {
			
			if (recognize_element_T4(line)) {
				set_T4_element(line, Abaqus_Elements);
			}
			else {
				set_P6_element(line, Abaqus_Elements);
			}


		}

		positions_start = line.find("ELEMENT");
		if (positions_start != string::npos) {
			start_import = true;
		}


	}
	data_file.close();
}

void Abaqus_Importer::set_P6_element(string &line, MeshIS::Model::Common::CMR &Abaqus_Elements) {
	int element_id;
	int nodes_in_element[6];

	delete_point(line);

	std::istringstream iss(line);
	iss >> element_id >> nodes_in_element[0] >> nodes_in_element[1]
		>> nodes_in_element[2] >> nodes_in_element[3] 
		>> nodes_in_element[4] >> nodes_in_element[5];

	Abaqus_Elements.elementsP6.push_back({ nodes_in_element[0], nodes_in_element[1],
		nodes_in_element[2], nodes_in_element[3], nodes_in_element[4], nodes_in_element[5] });
}
void Abaqus_Importer::set_T4_element(string &line, MeshIS::Model::Common::CMR &Abaqus_Elements) {
	int element_id;
	int nodes_in_element[4];

	delete_point(line);

	std::istringstream iss(line);
	iss >> element_id >> nodes_in_element[0] >> nodes_in_element[1]
		>> nodes_in_element[2] >> nodes_in_element[3];

	Abaqus_Elements.elementsT4.push_back({ nodes_in_element[0], nodes_in_element[1],
		nodes_in_element[2], nodes_in_element[3] });
}

std::fstream Abaqus_Importer::open_abaqus_file(const string &absolute_file_path) {
	std::fstream data_file;
	data_file.open(absolute_file_path.c_str(), std::ios::in);

	if (data_file.good()) {
		std::cout << "Plik wczytany pomy?lnie\n";
		return data_file;
	}
	else {
		std::cout << "Plik nie wczytany\n";
	}

}

bool Abaqus_Importer::recognize_element_T4(string line) {

	int value = -1, result = 0;
	delete_point(line);
	std::istringstream iss(line);

	for (int i = 0; i < 6; i++) {
		iss >> value;
		if (value > -1) {
			result++;
			value = -1;
		}
	}
	
	if (result == 5) {
		return true;
	}
	else
		return false;
}
double Abaqus_Importer::scientific_notation(string &coordinates) {

	double value;
	int exponent;
	for (int i = 0; i < coordinates.length(); i++) {
		if (coordinates[i] == 'E')
			coordinates[i] = ' ';
	}

	std::istringstream iss(coordinates);
	iss >> value >> exponent;

	return value * pow(10, exponent);
}
void Abaqus_Importer::delete_point(string &line) {
	for (int i = 0; i< line.length(); i++) {
		if (line[i] == ',') {
			line[i] = ' ';
		}
	}
}

