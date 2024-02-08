#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_STRATEGY_S21_TRANSFORM_CLIENT_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_STRATEGY_S21_TRANSFORM_CLIENT_H_

#include "s21_transform_context.h"

namespace s21 {
class TransformClient : public TransformContext {
 public:
  void Transform(std::array<double, 4> &vertex_array, const double &x,
                 const double &y, const double &z) override {
    transform_strategy_->Transform(vertex_array, x, y, z);
  }

  void SetTransformStrategy(TransformStrategy *transform_strategy) override {
    transform_strategy_ = transform_strategy;
  }
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_STRATEGY_S21_TRANSFORM_CLIENT_H_
