#ifndef NAS_PARSER_H_
#define NAS_PARSER_H_

#include <vector>
#include <array>
#include "NastranParser.h"

class NasParser :
    public NastranParser
{
private:
    const int COLUMN_LENGTH = 8;
    virtual void parse_grid_point(stringstream & stream, CMR & mesh) override;
    virtual void parse_triangular_face(stringstream & stream, CMR & mesh) override;
    virtual void parse_quadrilateral_face(stringstream & stream, CMR & mesh) override;
    virtual void parse_tetra_volume(stringstream & stream, CMR & mesh) override;
    virtual void parse_penta_volume(stringstream & stream, CMR & mesh) override;

public:
    virtual void choose_parser(const string & token, stringstream & stream, CMR & mesh) override;
};

#endif