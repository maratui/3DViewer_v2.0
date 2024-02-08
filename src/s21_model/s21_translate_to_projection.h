#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_MODEL_S21_TRANSLATE_TO_PROJECTION_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_MODEL_S21_TRANSLATE_TO_PROJECTION_H_

#include "s21_transform_matrix.h"

namespace s21 {
class TranslateToProjectionModel {
 public:
  static void TranslateToProjection(std::array<double, 4> &vertex_array,
                                    const double &x, const double &y,
                                    const double &z);
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_MODEL_S21_TRANSLATE_TO_PROJECTION_H_
