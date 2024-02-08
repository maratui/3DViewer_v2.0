#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_MODEL_S21_CENTRAL_PROJECTION_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_MODEL_S21_CENTRAL_PROJECTION_H_

#include "s21_transform_matrix.h"

namespace s21 {
class CentralProjectionModel {
 public:
  static void CentralProjection(std::array<double, 4> &vertex_array,
                                const double &min_z, const double &max_z,
                                const double &z);
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_MODEL_S21_CENTRAL_PROJECTION_H_
