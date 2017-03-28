#tests

add_definitions( -DTESTARGS )

add_executable( Tests ../main.cpp ../Converter.cpp TestExporter.cpp TestImporter.cpp ConversionTest.cpp)
