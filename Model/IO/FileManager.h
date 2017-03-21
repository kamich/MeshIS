#pragma 
#ifndef FILEMANAGER_H_
#define FILEMANAGER_H_

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <boost/filesystem.hpp>

namespace MeshIS
{
namespace Model
{
namespace IO
{
	namespace fs = boost::filesystem;

	class FileManager
	{
		std::vector<std::string> valid_extensions;

	public:
		bool file_exists(fs::path & file_path);
		bool extension_checker(const std::string & extension);
		std::ifstream open_file(fs::path & file_path);

		static std::stringstream map_file_to_stringstream(std::ifstream & input_file);

		FileManager(std::vector<std::string> extensions_base);
	};

} //! end of namespace IO
} //! end of namespace Model
} //! end of namespace MeshIS

#endif // FILEMANAGER_H_