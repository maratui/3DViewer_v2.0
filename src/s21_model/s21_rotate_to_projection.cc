#include "s21_rotate_to_projection.h"

void s21::RotateToProjectionModel::RotateToProjection(
    std::array<double, 4> &vertex_array, const double &angle_x,
    const double &angle_y, const double &angle_z) {
  std::array<std::array<double, 4>, 4> rotate_matrix;
  TransformMatrixModel::InitializMatrix(rotate_matrix);
  if (angle_x != 0.0) {
    double angle = TransformMatrixModel::DegreesToRadians(angle_x);
    rotate_matrix[1][1] = cos(angle);
    rotate_matrix[1][2] = -sin(angle);
    rotate_matrix[2][1] = sin(angle);
    rotate_matrix[2][2] = cos(angle);
  } else if (angle_y != 0.0) {
    double angle = TransformMatrixModel::DegreesToRadians(angle_y);
    rotate_matrix[0][0] = cos(angle);
    rotate_matrix[0][2] = sin(angle);
    rotate_matrix[2][0] = -sin(angle);
    rotate_matrix[2][2] = cos(angle);
  } else if (angle_z != 0.0) {
    double angle = TransformMatrixModel::DegreesToRadians(angle_z);
    rotate_matrix[0][0] = cos(angle);
    rotate_matrix[0][1] = -sin(angle);
    rotate_matrix[1][0] = sin(angle);
    rotate_matrix[1][1] = cos(angle);
  }
  TransformMatrixModel::TransformMatrix(rotate_matrix, vertex_array);
}
