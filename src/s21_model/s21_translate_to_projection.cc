#include "s21_translate_to_projection.h"

void s21::TranslateToProjectionModel::TranslateToProjection(
    std::array<double, 4> &vertex_array, const double &x, const double &y,
    const double &z) {
  std::array<std::array<double, 4>, 4> translate_matrix;
  TransformMatrixModel::InitializMatrix(translate_matrix);
  translate_matrix[0][3] = x;
  translate_matrix[1][3] = y;
  translate_matrix[2][3] = z;
  TransformMatrixModel::TransformMatrix(translate_matrix, vertex_array);
}
