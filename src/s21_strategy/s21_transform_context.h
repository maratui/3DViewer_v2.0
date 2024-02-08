#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_STRATEGY_S21_TRANSFORM_CONTEXT_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_STRATEGY_S21_TRANSFORM_CONTEXT_H_

#include "s21_transform_strategy.h"

namespace s21 {
class TransformContext {
 public:
  virtual ~TransformContext() {}

  virtual void Transform(std::array<double, 4> &vertex_array, const double &x,
                         const double &y, const double &z) = 0;
  virtual void SetTransformStrategy(TransformStrategy *transform_strategy) = 0;

 protected:
  TransformStrategy *transform_strategy_;
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_STRATEGY_S21_TRANSFORM_CONTEXT_H_
