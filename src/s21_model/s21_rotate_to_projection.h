#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_MODEL_S21_RATATE_TO_PROJECTION_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_MODEL_S21_RATATE_TO_PROJECTION_H_

#include <cmath>

#include "s21_transform_matrix.h"

namespace s21 {
class RotateToProjectionModel {
 public:
  static void RotateToProjection(std::array<double, 4> &vertex_array,
                                 const double &angle_x, const double &angle_y,
                                 const double &angle_z);
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_MODEL_S21_RATATE_TO_PROJECTION_H_
