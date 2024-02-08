#include "s21_scene.h"

std::vector<s21::Figure> &s21::Scene::GetFigures() noexcept { return figures_; }

s21::SceneScope &s21::Scene::GetSceneScope() noexcept {
  scene_scope_.min_x = figures_[0].GetVertices()[0].GetPosition().x;
  scene_scope_.min_y = figures_[0].GetVertices()[0].GetPosition().y;
  scene_scope_.min_z = figures_[0].GetVertices()[0].GetPosition().z;
  scene_scope_.max_x = scene_scope_.min_x;
  scene_scope_.max_y = scene_scope_.min_y;
  scene_scope_.max_z = scene_scope_.min_z;

  for (auto i = 0UL, figures_size = figures_.size(); i < figures_size; i++) {
    auto figure = figures_[i];
    for (auto j = 0UL, vertices_size = figure.GetVertices().size();
         j < vertices_size; j++) {
      auto vertex = figure.GetVertices()[j];
      double x = vertex.GetPosition().x;
      double y = vertex.GetPosition().y;
      double z = vertex.GetPosition().z;
      if (scene_scope_.min_x > x) scene_scope_.min_x = x;
      if (scene_scope_.min_y > y) scene_scope_.min_y = y;
      if (scene_scope_.min_z > z) scene_scope_.min_z = z;
      if (scene_scope_.max_x < x) scene_scope_.max_x = x;
      if (scene_scope_.max_y < y) scene_scope_.max_y = y;
      if (scene_scope_.max_z < z) scene_scope_.max_z = z;
    }
  }

  scene_scope_.max = GetMaxSceneScope();

  return scene_scope_;
}

void s21::Scene::Clear() {
  for (auto i = 0UL, figures_size = figures_.size(); i < figures_size; i++) {
    figures_[i].GetEdges().clear();
    figures_[i].GetVertices().clear();
  }
  figures_.clear();
}

void s21::Scene::TransformFigures(TransformContext *transform_context,
                                  const double &x, const double &y,
                                  const double &z) noexcept {
  for (auto i = 0UL, figures_size = figures_.size(); i < figures_size; i++) {
    figures_[i].Transform(transform_context, x, y, z);
  }
}

void s21::Scene::PushBack(const Figure &figure) { figures_.push_back(figure); }

double s21::Scene::GetMaxSceneScope() noexcept {
  double max = (scene_scope_.max_x - scene_scope_.min_x);
  if ((scene_scope_.max_y - scene_scope_.min_y) > max)
    max = (scene_scope_.max_y - scene_scope_.min_y);
  if ((scene_scope_.max_z - scene_scope_.min_z) > max)
    max = (scene_scope_.max_z - scene_scope_.min_z);

  return max;
}
