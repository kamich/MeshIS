#include "FileManager.h"

#include <algorithm>
#include "IO_Exceptions.h"

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
	if (!file_exists(file_path))
        throw FileNotExistException(file_path.string());

	if (!extension_checker(file_path.extension().string()))
        throw IncorrectFileFormatException(file_path.string());

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