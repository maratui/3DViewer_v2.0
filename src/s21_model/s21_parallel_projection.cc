#include "s21_parallel_projection.h"

void s21::ParallelProjectionModel::ParallelProjection(
    std::array<double, 4> &vertex_array, const double &x, const double &y,
    const double &z) {
  std::array<std::array<double, 4>, 4> parallel_matrix;
  TransformMatrixModel::InitializMatrix(parallel_matrix);
  parallel_matrix[0][0] = 2.0;
  parallel_matrix[0][3] = -x;
  parallel_matrix[1][1] = 2.0;
  parallel_matrix[1][3] = -y;
  parallel_matrix[2][2] = 2.0;
  parallel_matrix[2][3] = -z;
  TransformMatrixModel::TransformMatrix(parallel_matrix, vertex_array);
}
