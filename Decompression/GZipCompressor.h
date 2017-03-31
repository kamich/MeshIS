#pragma once
#include "CommonMeshRepresentation.h"
#include "MeshImporter.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>

using namespace std;
using namespace MeshIS::Model::Import;
using namespace MeshIS::Model::Common;


class GZipCompressor
	: MeshImporter
{
private:
	int read_file(std::string& buf, const char *fn);
	void add_data(std::string& buf, const char *data);
	void write_file(std::string& buf, const char *fn);

	std::string data;
	std::string buf;

public:
	CMR Import(const string& absolute_file_path);

	GZipCompressor();
	~GZipCompressor();
};