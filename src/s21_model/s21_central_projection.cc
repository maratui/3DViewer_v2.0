#include "s21_central_projection.h"

void s21::CentralProjectionModel::CentralProjection(
    std::array<double, 4> &vertex_array, const double &min_z,
    const double &max_z, const double &z) {
  std::array<std::array<double, 4>, 4> central_matrix;
  TransformMatrixModel::InitializMatrix(central_matrix);
  central_matrix[2][2] = -(max_z + min_z) / (2.0 * (max_z - min_z));
  central_matrix[2][3] = -(max_z * min_z) / (max_z - min_z);
  central_matrix[3][2] = 0.5;
  central_matrix[3][3] = z;
  TransformMatrixModel::TransformMatrix(central_matrix, vertex_array);
  if (vertex_array[3] != 0.0) {
    vertex_array[0] /= vertex_array[3];
    vertex_array[1] /= vertex_array[3];
    vertex_array[2] /= vertex_array[3];
  }
}
