#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_MODEL_S21_TRANSFORM_MATRIX_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_MODEL_S21_TRANSFORM_MATRIX_H_

#include <array>

namespace s21 {
class TransformMatrixModel {
 public:
  static void InitializMatrix(std::array<std::array<double, 4>, 4> &matrix);
  static void TransformMatrix(
      std::array<std::array<double, 4>, 4> &transform_matrix,
      std::array<double, 4> &vertex_array);
  static double DegreesToRadians(const double &degrees);
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_MODEL_S21_TRANSFORM_MATRIX_H_
