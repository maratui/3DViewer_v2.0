#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_STRATEGY_S21_TRANSFORM_STRATEGY_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_STRATEGY_S21_TRANSFORM_STRATEGY_H_

#include <array>

namespace s21 {
class TransformStrategy {
 public:
  virtual ~TransformStrategy() {}

  virtual void Transform(std::array<double, 4> &vertex_array,
                         const double &scale_x, const double &scale_y,
                         const double &scale_z) = 0;
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_STRATEGY_S21_TRANSFORM_STRATEGY_H_
