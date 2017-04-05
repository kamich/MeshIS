#pragma once
#ifndef MESHIS_IO_EXCEPTIONS_H_
#define MESHIS_IO_EXCEPTIONS_H_

#include <stdexcept>
#include <string>

namespace MeshIS
{
namespace Model
{
namespace IO
{


/// For exceptions involving some file.
class FileException : public std::runtime_error {
public:

  FileException(const std::string& file_name)
  : runtime_error("Problem with file:"+file_name), problematic_file_name(file_name)
  {}

  const char* get_problematic_filename() const
  {
      return problematic_file_name.c_str();
  }

private:
  std::string problematic_file_name;
};

/// For the case when file string is ill-formatted.
class InvalidFileNameException : public FileException 
{
public:
      InvalidFileNameException(const std::string& file_name): FileException(file_name) {}
};

/// For the case when file string is correctly formatted, but no such file exist.
class FileNotExistException : public FileException 
{
public:
      FileNotExistException(const std::string& file_name): FileException(file_name) {}
};

/// For the case, when IO operation encounters a ill-formatted data.
class IncorrectFileFormatException : public FileException 
{
public:
      IncorrectFileFormatException(const std::string& file_name): FileException(file_name) {}
};

} //! end of namespace IO
} //! end of namespace Model
} //! end of namespace MeshIS

#endif /* end of include guard: MESHIS_IO_EXCEPTIONS_H_ */
