#pragma 
#ifndef FILEMANAGER_H_
#define FILEMANAGER_H_

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <boost/filesystem.hpp>
#include "IO_Exceptions.h"

using std::vector;
using std::array;
using std::string;
using std::ifstream;
using std::stringstream;
using boost::filesystem::path;

namespace MeshIS
{
namespace Model
{
namespace IO
{

	class FileManager
	{
		vector<string> valid_extensions;

	public:
		bool file_exists(path & file_path);
		bool extension_checker(const string & extension);
		ifstream open_file(path & file_path);

		static stringstream map_file_to_stringstream(ifstream & input_file);

		FileManager(vector<string> extensions_base);
	};

} //! end of namespace IO
} //! end of namespace Model
} //! end of namespace MeshIS

#endif // FILEMANAGER_H_