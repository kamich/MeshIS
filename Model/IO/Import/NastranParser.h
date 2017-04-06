#ifndef NASTRAN_PARSER_H_
#define NASTRAN_PARSER_H_

#include <string>
#include <sstream>
#include "../../../Model/Common/CommonMeshRepresentation.h"
#include "../../nastran_transform.h"

using std::string;
using std::stringstream;
using MeshIS::Model::Common::CMR;

class NastranParser
{
private:
    virtual void parse_grid_point(stringstream & stream, CMR & mesh) = 0;
    virtual void parse_triangular_face(stringstream & stream, CMR & mesh) = 0;
    virtual void parse_quadrilateral_face(stringstream & stream, CMR & mesh) = 0;
    virtual void parse_tetra_volume(stringstream & stream, CMR & mesh) = 0;
    virtual void parse_penta_volume(stringstream & stream, CMR & mesh) = 0;
public:
    virtual void choose_parser(const string & token, stringstream & stream, CMR & mesh) = 0;
};

#endif