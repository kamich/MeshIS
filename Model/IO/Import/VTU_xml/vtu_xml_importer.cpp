#include "vtu_xml_importer.h"

CMR Vtu_xml_importer::Import(const string &absolute_file_path)
{
	CMR vtuCMR;
	
	std::fstream file;
	file.open(absolute_file_path.c_str(), std::ios::in | std::ios::out);

	xml_document<> doc;
	xml_node<> * root_node;
	xml_node<> * child_node;

	vector<char> buffer((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
	file.close();

	buffer.push_back('\0');
	doc.parse<0>(&buffer[0]);

	root_node = doc.first_node("VTKFile");
	root_node = root_node->first_node("UnstructuredGrid");
	root_node = root_node->first_node("Piece");

	double number_of_points = atof(root_node->first_attribute("NumberOfPoints")->value());

	child_node = root_node->first_node("Points");
	child_node = child_node->first_node("DataArray");

	stringstream pointStream(child_node->value());
	double  x, y, z;

	for (int i = 0; i < number_of_points; i++)
	{
		pointStream >> x;
		pointStream >> y;
		pointStream >> z;
		vtuCMR.vertices.push_back({ x,y,z });
	}

	/// CELS SECTION
	child_node = root_node->first_node("Cells");

	for (xml_node<> * data_array = child_node->first_node("DataArray"); data_array; data_array = data_array->next_sibling())
	{
		string name = data_array->first_attribute("Name")->value();
		
		if (name == "connectivity") fillConnectivitiesVector(data_array->value());
		if (name == "types") fillTypeVector(data_array->value());
	}

	fillMesh(vtuCMR);

	return vtuCMR;
}

void Vtu_xml_importer::fillConnectivitiesVector(const string& data)
{
	double t;
	stringstream connectivitiesStream(data);
	while (connectivitiesStream >> t)
	{
		connectivities.push_back(t);
	}

}

void Vtu_xml_importer::fillTypeVector(string data)
{
	double t;
	stringstream typesStream(data);
	while (typesStream >> t)
	{
		types.push_back(t);
	}
}

void Vtu_xml_importer::fillMesh(CMR &vtuCMR)
{
	vector<int>::iterator connIt = connectivities.begin();

	for (auto type : types)
	{
		switch (type)
		{
		case 10:
			vtuCMR.elementsT4.push_back({ *connIt++, *connIt++ ,*connIt++ ,*connIt++ });
			break;
		}
	}
}
