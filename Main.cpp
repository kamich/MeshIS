#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include "GZipCompressor.hpp"

using namespace std;
using namespace MeshIS::Model::Common;

int main()
{
	string absolute_file_path = "c.txt.gz";
	CMR net;
	Vertex v1 = { 1.3,1.5,1.4 };
	Vertex v2 = { 2,2,2 };
	Vertex v3 = { 3,3,3 };
	Vertex v4 = { 4,4,4 };
	net.vertices.push_back(v1);
	net.vertices.push_back(v2);
	net.vertices.push_back(v3);
	net.vertices.push_back(v4);

	GZipCompressor compressor;
	compressor.Export(absolute_file_path, net);

	return 0;
}