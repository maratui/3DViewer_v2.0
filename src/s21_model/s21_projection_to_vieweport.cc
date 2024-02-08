#include "s21_projection_to_vieweport.h"

void s21::ProjectionToVieweportModel::ProjectionToVieweport(
    std::array<double, 4> &vertex_array, const double &width,
    const double &height, const double &z) {
  double height_width = height / width;

  if (height_width != 1.0) {
    std::array<std::array<double, 4>, 4> vieweport_matrix;
    TransformMatrixModel::InitializMatrix(vieweport_matrix);
    if (height_width > 1.0) {
      vieweport_matrix[0][0] = z;
      vieweport_matrix[1][1] = 1.0 / height_width;
    } else {
      vieweport_matrix[0][0] = height_width;
      vieweport_matrix[1][1] = z;
    }
    TransformMatrixModel::TransformMatrix(vieweport_matrix, vertex_array);
  }
}
