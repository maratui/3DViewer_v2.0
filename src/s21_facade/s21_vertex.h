#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_FACADE_S21_VERTEX_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_FACADE_S21_VERTEX_H_

#include "../s21_strategy/s21_transform_context.h"
#include "s21_point.h"

namespace s21 {
class Vertex {
 public:
  Vertex() = delete;
  explicit Vertex(const double &x, const double &y, const double &z);

  Point &GetPosition() noexcept;
  void Transform(TransformContext *transform_context, const double &x,
                 const double &y, const double &z) noexcept;

 private:
  Point position_{};
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_FACADE_S21_VERTEX_H_
