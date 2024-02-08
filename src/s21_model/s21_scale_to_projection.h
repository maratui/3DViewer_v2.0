#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_MODEL_S21_SCALE_TO_PROJECTION_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_MODEL_S21_SCALE_TO_PROJECTION_H_

#include "s21_transform_matrix.h"

namespace s21 {
class ScaleToProjectionModel {
 public:
  static void ScaleToProjection(std::array<double, 4> &vertex_array,
                                const double &scale_x, const double &scale_y,
                                const double &scale_z);
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_MODEL_S21_SCALE_TO_PROJECTION_H_
