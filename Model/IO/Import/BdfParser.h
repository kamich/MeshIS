#pragma
#ifndef BDF_PARSER_H_
#define BDF_PARSER_H_

#include <vector>
#include <array>
#include <sstream>
#include "NastranParser.h"
#include "../../nastran_transform.h"

class BdfParser :
    public NastranParser
{
private:
    constexpr static int COLUMN_LENGTH = 8;
    virtual void parse_grid_point(stringstream & stream, CMR & mesh) override;
    virtual void parse_triangular_face(stringstream & stream, CMR & mesh) override;
    virtual void parse_quadrilateral_face(stringstream & stream, CMR & mesh) override;
    virtual void parse_tetra_volume(stringstream & stream, CMR & mesh) override;
    virtual void parse_penta_volume(stringstream & stream, CMR & mesh) override;
    string convert_chunk_to_string(stringstream & stream);

public:
    virtual void choose_parser(const string & token, stringstream & stream, CMR & mesh) override;
};

#endif