#include "s21_figure.h"

std::vector<s21::Vertex> &s21::Figure::GetVertices() noexcept {
  return vertices_;
}

std::vector<s21::Edge> &s21::Figure::GetEdges() noexcept { return edges_; }

void s21::Figure::Transform(TransformContext *transform_context,
                            const double &x, const double &y,
                            const double &z) noexcept {
  for (auto i = 0UL, vertices_size = vertices_.size(); i < vertices_size; i++) {
    vertices_[i].Transform(transform_context, x, y, z);
  }
}

void s21::Figure::PushBack(Vertex &&vertex) {
  vertices_.push_back(std::move(vertex));
}

void s21::Figure::PushBack(Edge &&edge) { edges_.push_back(std::move(edge)); }
