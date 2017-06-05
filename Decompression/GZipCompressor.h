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

using namespace MeshIS::Model::Import;
using namespace MeshIS::Model::Common;


class GZipCompressor
	: MeshImporter
{
public:
	CMR Import(const string& absolute_file_path);

};