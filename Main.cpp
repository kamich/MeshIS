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

//static int read_file(std::string& buf, const char *fn)
//{
//	ifstream file(fn, ios_base::in | ios_base::binary);
//	boost::iostreams::filtering_streambuf<boost::iostreams::input> in;
//	in.push(boost::iostreams::gzip_decompressor());
//	in.push(file);
//
//	std::istream inf(&in);
//
//	while (inf.good()) {
//		char tmpbuf[8192];
//
//		inf.read(tmpbuf, sizeof(tmpbuf));
//		buf.append(tmpbuf, inf.gcount());
//	}
//
//	return 0;
//}

//static void add_data(std::string& buf, const char *data)
//{
//	buf += data;
//	buf += "\n";
//}

//static void write_file(std::string& buf, const char *fn)
//{
//	ofstream file(fn, ios_base::out | ios_base::binary | ios_base::trunc);
//	boost::iostreams::filtering_streambuf<boost::iostreams::output> out;
//	out.push(boost::iostreams::gzip_compressor());
//	out.push(file);
//
//	std::ostream outf(&out);
//
//	outf.write(buf.c_str(), buf.size());
//}



int main()
{
	string absolute_file_path = "c.txt.gz";
	CMR net;
	Vertex v = { 1,1,1 };
	net.vertices.push_back(v);

//	for (int i = 0; i < 10; i++)


	//string d = "";
	//for (int i = 0; i < 10; i++)
	//	for (int j = 0; j < 4; j++)
	//	{
	//		d += i + ", ";
	//		d += dane[i].vertices[j][1];
	//	}

	GZipCompressor compressor;
	compressor.Export(absolute_file_path, net);

	return 0;
}