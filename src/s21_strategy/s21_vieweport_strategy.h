#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_STRATEGY_S21_VIEWEPORT_STRATEGY_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_STRATEGY_S21_VIEWEPORT_STRATEGY_H_

#include "../s21_model/s21_projection_to_vieweport.h"
#include "s21_transform_strategy.h"

namespace s21 {
class VieweportStrategy : public TransformStrategy {
 public:
  void Transform(std::array<double, 4> &vertex_array, const double &x,
                 const double &y, const double &z) override {
    ProjectionToVieweportModel::ProjectionToVieweport(vertex_array, x, y, z);
  }
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_STRATEGY_S21_VIEWEPORT_STRATEGY_H_
