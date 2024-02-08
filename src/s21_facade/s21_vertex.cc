#include "s21_vertex.h"

s21::Vertex::Vertex(const double &x, const double &y, const double &z) {
  position_.x = x;
  position_.y = y;
  position_.z = z;
}

s21::Point &s21::Vertex::GetPosition() noexcept { return position_; }

void s21::Vertex::Transform(TransformContext *transform_context,
                            const double &x, const double &y,
                            const double &z) noexcept {
  std::array<double, 4> vertex_array;
  vertex_array[0] = position_.x;
  vertex_array[1] = position_.y;
  vertex_array[2] = position_.z;
  vertex_array[3] = 1.0;
  transform_context->Transform(vertex_array, x, y, z);
  position_.x = vertex_array[0];
  position_.y = vertex_array[1];
  position_.z = vertex_array[2];
}
