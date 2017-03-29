#include "GZipCompressor.hpp"
#include <sstream>

GZipCompressor::GZipCompressor()
{
}

void GZipCompressor::Export(const string& absolute_file_path, const MeshIS::Model::Common::CMR& mesh_data)
{
	data = "";
	Vertex v;
	ostringstream ss;
	v = mesh_data.vertices[0];
	for (int i = 0; i < 3; i++)
	{
		ss << i;
		data += ss.str();
		data += ", \n";
	}


	read_file(buf, absolute_file_path.c_str());
	add_data(buf, data.c_str());
	write_file(buf, absolute_file_path.c_str());
}

int GZipCompressor::read_file(std::string& buf, const char *fn)
{
	ifstream file(fn, ios_base::in | ios_base::binary);
	boost::iostreams::filtering_streambuf<boost::iostreams::input> in;
	in.push(boost::iostreams::gzip_decompressor());
	in.push(file);

	std::istream inf(&in);

	while (inf.good()) {
		char tmpbuf[8192];

		inf.read(tmpbuf, sizeof(tmpbuf));
		buf.append(tmpbuf, inf.gcount());
	}

	return 0;
}

void GZipCompressor::add_data(std::string& buf, const char *data)
{
	buf += data;
	buf += "\n";
}

void GZipCompressor::write_file(std::string& buf, const char *fn)
{
	ofstream file(fn, ios_base::out | ios_base::binary | ios_base::trunc);
	boost::iostreams::filtering_streambuf<boost::iostreams::output> out;
	out.push(boost::iostreams::gzip_compressor());
	out.push(file);

	std::ostream outf(&out);

	outf.write(buf.c_str(), buf.size());
}

GZipCompressor::~GZipCompressor()
{
}
