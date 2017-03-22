#include "FileManager.h"

namespace IO = MeshIS::Model::IO;

bool IO::FileManager::file_exists(path & file_path)
{
	file_path.make_preferred();
	return exists(file_path);
}

bool IO::FileManager::extension_checker(const string & extension)
{
	return any_of(begin(valid_extensions), end(valid_extensions), [&](const string &valid_extension) {
		return extension == valid_extension;
	});
}

ifstream IO::FileManager::open_file(path & file_path)
{
	if (!file_exists(file_path)) {
		
		throw 1;	
	}
	if (!extension_checker(file_path.extension().string())) {
		throw 2;	//TODO the same
	}
	return ifstream(file_path.make_preferred().string());
}

stringstream IO::FileManager::map_file_to_stringstream(ifstream & input_file)
{
	stringstream file_contents;

	file_contents << input_file.rdbuf();

	return file_contents;
}

IO::FileManager::FileManager(vector<string> extensions_base) : valid_extensions(move(extensions_base))
{}