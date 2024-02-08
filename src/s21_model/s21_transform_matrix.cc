#include "s21_transform_matrix.h"

void s21::TransformMatrixModel::InitializMatrix(
    std::array<std::array<double, 4>, 4> &matrix) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == j) {
        matrix[i][j] = 1.0;
      } else {
        matrix[i][j] = 0.0;
      }
    }
  }
}

void s21::TransformMatrixModel::TransformMatrix(
    std::array<std::array<double, 4>, 4> &transform_matrix,
    std::array<double, 4> &vertex_array) {
  std::array<double, 4> result_array;
  for (int i = 0; i < 4; i++) {
    result_array[i] = 0.0;
    for (int j = 0; j < 4; j++) {
      result_array[i] += transform_matrix[i][j] * vertex_array[j];
    }
  }
  vertex_array = result_array;
}

double s21::TransformMatrixModel::DegreesToRadians(const double &degrees) {
  return degrees * 3.14159265358979323846 / 180.0;
}
