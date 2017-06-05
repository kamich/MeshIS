#include "GZipCompressor.h"
#include <sstream>

CMR GZipCompressor::Import(const string& absolute_file_path) 
{
	CMR OB;
	std::ifstream file(absolute_file_path, std::ios_base::in | std::ios_base::binary);  // file to decompresion 
	boost::iostreams::filtering_streambuf<boost::iostreams::input> in;// functions from boost toutorial for compression/decompression
	in.push(boost::iostreams::gzip_decompressor());					  //...
	in.push(file);													  //...
	std::istream inf(&in);											  //...

	if (inf.good()) {
		char tmpbuf[8192];
		std::ofstream file2("dane2.txt", std::ios_base::out | std::ios_base::binary); // file for decompressed text

		inf.read(tmpbuf, sizeof(tmpbuf));												// decompressed file is saving to tmpbuf
		int i = 0;
		while (tmpbuf[i] != '�'){ // after decompression empty cells of tmpbuf are filled with a sign "�" 
								  // I made mechanism to remove all "�" (is not really advanced...)
								  // text after decompression for example:

				//Litwo!Ojczyzno moja!ty jeste� jak zdrowie.

				//Ile ci� trzeba ceni�, ten tylko si� dowie,

				//Kto ci� straci�.Dzi� pi�kno�� tw� w ca�ej ozdobie

				//Widz� i opisuj�, bo t�skni� po tobie.����������������������������������������������������������������������������������������������������...
			
			file2 << tmpbuf[i]; //tmpbud to file2 "dane.txt
			i++;

			// I'm sorry for my english
		}	
	}
	return OB;
}

