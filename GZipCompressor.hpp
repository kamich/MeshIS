#pragma once
#include "CommonMeshRepresentation.h"
#include "MeshExporter.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>

using namespace std;
using namespace MeshIS::Model::Export;
using namespace MeshIS::Model::Common;


class GZipCompressor
	: MeshExporter
{

private:
	int read_file(std::string& buf, const char *fn);
	void add_data(std::string& buf, const char *data);
	void write_file(std::string& buf, const char *fn);

	std::string data;
	std::string buf;
	
public:
	void Export(const string& absolute_file_path, const MeshIS::Model::Common::CMR& mesh_data);

	GZipCompressor();
	~GZipCompressor();
};

