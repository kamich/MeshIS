#pragma
#ifndef MESHIS_IO_EXCEPTIONS_H_
#define MESHIS_IO_EXCEPTIONS_H_

#include <stdexcept>
#include <string>

using std::string;

namespace MeshIS {
    namespace Model {
        namespace IO {



            class FileException : public std::runtime_error {
            public:

                FileException(const string &file_name)
                        : runtime_error("Problem with file:" + file_name), problematic_file_name(file_name) {}

                const char *get_problematic_filename() const {
                    return problematic_file_name.c_str();
                }

            private:
                string problematic_file_name;
            };


            class InvalidFileNameException : public FileException {
            public:
                InvalidFileNameException(const string &file_name)
                        : FileException(file_name) {}
            };


            class FileNotExistException : public FileException {
            public:
                FileNotExistException(const string &file_name)
                        : FileException(file_name) {}
            };


            class IncorrectFileFormatException : public FileException {
            public:
                IncorrectFileFormatException(const string &file_name)
                        : FileException(file_name) {}
            };

        } //! end of namespace IO
    } //! end of namespace Model
} //! end of namespace MeshIS

#endif /* end of include guard: MESHIS_IO_EXCEPTIONS_H_ */
