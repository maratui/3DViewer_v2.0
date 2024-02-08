#include "s21_scale_to_projection.h"

void s21::ScaleToProjectionModel::ScaleToProjection(
    std::array<double, 4> &vertex_array, const double &scale_x,
    const double &scale_y, const double &scale_z) {
  std::array<std::array<double, 4>, 4> scale_matrix;
  TransformMatrixModel::InitializMatrix(scale_matrix);
  scale_matrix[0][0] = scale_x;
  scale_matrix[1][1] = scale_y;
  scale_matrix[2][2] = scale_z;
  TransformMatrixModel::TransformMatrix(scale_matrix, vertex_array);
}
