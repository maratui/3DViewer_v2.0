#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_FACADE_S21_FIGURE_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_FACADE_S21_FIGURE_H_

#include <vector>

#include "../s21_strategy/s21_transform_context.h"
#include "s21_edge.h"
#include "s21_vertex.h"

namespace s21 {
class Figure {
 public:
  std::vector<Vertex> &GetVertices() noexcept;
  std::vector<Edge> &GetEdges() noexcept;

  void Transform(TransformContext *transform_context, const double &x,
                 const double &y, const double &z) noexcept;

  void PushBack(Vertex &&vertex);
  void PushBack(Edge &&edge);

 private:
  std::vector<Vertex> vertices_;
  std::vector<Edge> edges_;
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_FACADE_S21_FIGURE_H_
