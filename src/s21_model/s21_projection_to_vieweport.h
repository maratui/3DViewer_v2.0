#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_MODEL_S21_PROJECTION_TO_VIEWEPORT_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_MODEL_S21_PROJECTION_TO_VIEWEPORT_H_

#include "s21_transform_matrix.h"

namespace s21 {
class ProjectionToVieweportModel {
 public:
  static void ProjectionToVieweport(std::array<double, 4> &vertex_array,
                                    const double &width, const double &height,
                                    const double &z);
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_MODEL_S21_PROJECTION_TO_VIEWEPORT_H_
