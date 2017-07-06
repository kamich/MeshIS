#include "GZipCompressor.hpp"
#include <sstream>

GZipCompressor::GZipCompressor()
{
}

void GZipCompressor::Export(const string& absolute_file_path, const MeshIS::Model::Common::CMR& mesh_data)
{
	buf = "";
	Vertex v;
	for (int i = 0; i < 4; i++)
	{
		v = mesh_data.vertices[i];
		for (int j = 0; j < 3; j++)
		{
			ostringstream ss;
			ss << v[j];
			buf += ss.str() + ",";
		}
		buf += ";";
	}

	ofstream file(absolute_file_path, ios_base::out | ios_base::binary | ios_base::trunc);
	boost::iostreams::filtering_streambuf<boost::iostreams::output> out;
	out.push(boost::iostreams::gzip_compressor());
	out.push(file);

	std::ostream outf(&out);

	outf.write(buf.c_str(), buf.size());

}

GZipCompressor::~GZipCompressor()
{
}
