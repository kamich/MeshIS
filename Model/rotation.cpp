#include <array>
#include <cmath>
#include <vector>
#include <numeric>
#include "Common/CommonMeshRepresentation.h"

using std::array;
using std::vector;
using std::inner_product;
using std::sin;
using std::cos;
using std::cbegin;
using std::cend;
using Matrix3x3 = std::array<std::array<double, 3>, 3>;
using MeshIS::Model::Common::Vertex;
using MeshIS::Model::Common::VertexID;

double degrees_to_radians(double degrees) {
    return degrees * 3.14159265 / 180.0;
}

Matrix3x3 rotation_matrix_x_axis(double degrees) {
    const auto angle = degrees_to_radians(degrees);
    Matrix3x3 rotation_matrix{{{1, 0, 0}, {0, cos(angle), -sin(angle)}, {0, 0, 0}}};
    return rotation_matrix;
}

Matrix3x3 rotation_matrix_y_axis(double degrees) {
    const auto angle = degrees_to_radians(degrees);
    Matrix3x3 rotation_matrix{{{cos(angle), 0, sin(angle)}, {0, 1, 0}, {-sin(angle), 0, cos(angle)}}};
    return rotation_matrix;
}

Matrix3x3 rotation_matrix_z_axis(double degrees) {
    const auto angle = degrees_to_radians(degrees);
    Matrix3x3 rotation_matrix{{{cos(angle), -sin(angle), 0}, {sin(angle), cos(angle), 0}, {0, 0, 1}}};
    return rotation_matrix;
}


template<size_t N>
void apply_rotation(const Matrix3x3 &matrix, vector<Vertex> &vertices, const array<VertexID, N> &element) {
    vector<Vertex *> local_verticies;
    local_verticies.reserve(N);
    for (const auto &vertex_id : element)
        local_verticies.push_back(&vertices[vertex_id]);

    for (auto &vertex : local_verticies) {
        Vertex result{0, 0, 0};
        for (auto i = 0; i < 3; ++i)
            result[i] = inner_product(cbegin(matrix[i]), cend(matrix[i]), cbegin(*vertex), 0);
        *vertex = result;
    }
}

template<size_t N>
void rotate_x_axis(double degrees, vector<Vertex> &vertices, const array<VertexID, N> &element) {
    const auto matrix = rotation_matrix_x_axis(degrees);
    apply_rotation(matrix, vertices, element);
}

template<size_t N>
void rotate_y_axis(double degrees, vector<Vertex> &vertices, const array<VertexID, N> &element) {
    const auto matrix = rotation_matrix_y_axis(degrees);
    apply_rotation(matrix, vertices, element);
}

template<size_t N>
void rotate_z_axis(double degrees, vector<Vertex> &vertices, const array<VertexID, N> &element) {
    const auto matrix = rotation_matrix_z_axis(degrees);
    apply_rotation(matrix, vertices, element);
}
