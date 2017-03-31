
#include "GZipCompressor.h"
#include <sstream>

GZipCompressor::GZipCompressor()
{
}

CMR OB;

CMR GZipCompressor::Import(const string& absolute_file_path)
{
	ifstream file(absolute_file_path, ios_base::in | ios_base::binary);
	boost::iostreams::filtering_streambuf<boost::iostreams::input> in;
	in.push(boost::iostreams::gzip_decompressor());
	in.push(file);
	std::istream inf(&in);

	if (inf.good()) {
		char tmpbuf[8192];
		ofstream file2("dane2.txt", ios_base::out | ios_base::binary);

		inf.read(tmpbuf, sizeof(tmpbuf));
		int i = 0;
		while (tmpbuf[i] != 'Ì'){

			file2 << tmpbuf[i];
		i++;
	}
		
	}
	

	return OB;
}

//int GZipCompressor::read_file(std::string& buf, const char *fn)
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


GZipCompressor::~GZipCompressor()
{
}