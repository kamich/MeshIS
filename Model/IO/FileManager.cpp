#include "FileManager.h"

namespace fs = boost::filesystem;
namespace IO = MeshIS::Model::IO;

bool IO::FileManager::file_exists(fs::path & file_path)
{
	file_path.make_preferred();
	return fs::exists(file_path);
}

bool IO::FileManager::extension_checker(const std::string & extension)
{
	return std::any_of(begin(valid_extensions), end(valid_extensions), [&](const std::string &valid_extension) {
		return extension == valid_extension;
	});
}

std::ifstream IO::FileManager::open_file(fs::path & file_path)
{
	if (!file_exists(file_path)) {
		throw 1;	//TODO throw valid IO exception
	}
	if (!extension_checker(file_path.extension().string())) {
		throw 2;	//TODO the same
	}
	return std::ifstream(file_path.make_preferred().string());
}

std::stringstream IO::FileManager::map_file_to_stringstream(std::ifstream & input_file)
{
	std::stringstream file_contents;

	file_contents << input_file.rdbuf();

	return file_contents;
}

IO::FileManager::FileManager(std::vector<std::string> extensions_base) : valid_extensions(std::move(extensions_base))
{
	//valid_extensions.swap(extensions_base);
}
