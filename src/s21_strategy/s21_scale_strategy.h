#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_STRATEGY_S21_SCALE_STRATEGY_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_STRATEGY_S21_SCALE_STRATEGY_H_

#include "../s21_model/s21_scale_to_projection.h"
#include "s21_transform_strategy.h"

namespace s21 {
class ScaleStrategy : public TransformStrategy {
 public:
  void Transform(std::array<double, 4> &vertex_array, const double &x,
                 const double &y, const double &z) override {
    ScaleToProjectionModel::ScaleToProjection(vertex_array, x, y, z);
  }
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_STRATEGY_S21_SCALE_STRATEGY_H_
