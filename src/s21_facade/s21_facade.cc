#include "s21_facade.h"

s21::Facade::Facade()
    : scene_drawer_(SceneDrawer::GetInstance()),
      width_(scene_drawer_->width()),
      height_(scene_drawer_->height()) {}

bool s21::Facade::LoadScene(const std::string &path) {
  bool fail{};

  path_ = path;
  move_x_ = 0.0;
  move_y_ = 0.0;
  move_z_ = 0.0;

  scene_.Clear();
  fail = file_reader_.ReadScene(scene_, number_of_vertices_, number_of_edges_,
                                path);
  if (!fail) {
    ParallelProjectionScene();
    MoveScene(0.0, 0.0, 0.0);
  } else {
    scene_drawer_->DrawScene(scene_, drawer_setting_);
  }

  return fail;
}

void s21::Facade::MoveScene(const double &x, const double &y, const double &z) {
  SetMovePosition(x, y, z);

  TransformClient transform_client;
  TranslateStrategy translate_strategy;
  transform_client.SetTransformStrategy(&translate_strategy);
  drawer_scene_ = scene_;
  drawer_scene_.TransformFigures(&transform_client, move_x_, move_y_, move_z_);

  if (central_projection_) CentralProjectionScene();
  VieweportScene();
}

void s21::Facade::RotateScene(const double &x, const double &y,
                              const double &z) {
  if (x != 0.0 || y != 0.0 || z != 0.0) {
    TransformClient transform_client;
    RotateStrategy rotate_strategy;
    transform_client.SetTransformStrategy(&rotate_strategy);
    scene_.TransformFigures(&transform_client, x, y, z);
  }
  MoveScene(0.0, 0.0, 0.0);
}

void s21::Facade::ScaleScene(const double &x, const double &y,
                             const double &z) {
  if (x != 0.0 || y != 0.0 || z != 0.0) {
    TransformClient transform_client;
    ScaleStrategy scale_strategy;
    transform_client.SetTransformStrategy(&scale_strategy);
    scene_.TransformFigures(&transform_client, x, y, z);
  }
  MoveScene(0.0, 0.0, 0.0);
}

void s21::Facade::ProjectionScene(bool central_projection) {
  if (central_projection && !central_projection_) {
    central_projection_ = true;
    if (path_ != "") MoveScene(0.0, 0.0, 0.0);
  } else if (!central_projection && central_projection_) {
    central_projection_ = false;
    if (path_ != "") MoveScene(0.0, 0.0, 0.0);
  }
}

void s21::Facade::SetVertexColor(const QColor &color) {
  drawer_setting_.vertex_setting.color = color;
  if (path_ != "") MoveScene(0.0, 0.0, 0.0);
}

void s21::Facade::SetVertexDisplayMethod(int type) {
  drawer_setting_.vertex_setting.type = type;
  if (path_ != "") MoveScene(0.0, 0.0, 0.0);
}

void s21::Facade::SetVertexSize(int size) {
  drawer_setting_.vertex_setting.size = size;
  if (path_ != "") MoveScene(0.0, 0.0, 0.0);
}

void s21::Facade::SetEdgeColor(const QColor &color) {
  drawer_setting_.edge_setting.color = color;
  if (path_ != "") MoveScene(0.0, 0.0, 0.0);
}

void s21::Facade::SetSolidDashedEdgeLineType(int type) {
  drawer_setting_.edge_setting.type = type;
  if (path_ != "") MoveScene(0.0, 0.0, 0.0);
}

void s21::Facade::SetEdgeLineWidth(int size) {
  drawer_setting_.edge_setting.size = size;
  if (path_ != "") MoveScene(0.0, 0.0, 0.0);
}

void s21::Facade::SetBackgroundColor(const QColor &color) {
  drawer_setting_.background_color = color;
  if (path_ != "") MoveScene(0.0, 0.0, 0.0);
}

std::string &s21::Facade::GetObjectName() noexcept {
  if (path_ != "") {
    object_name_ = file_reader_.GetObjectName(path_);
  }
  return object_name_;
}

std::size_t &s21::Facade::GetNumberOfVertices() noexcept {
  return number_of_vertices_;
}
std::size_t &s21::Facade::GetNumberOfEdges() noexcept {
  return number_of_edges_;
}

QImage &s21::Facade::GetImage() { return scene_drawer_->GetImage(); }

void s21::Facade::ParallelProjectionScene() {
  TransformClient transform_client;

  SceneScope scene_scope = scene_.GetSceneScope();
  double max = 1.0 / scene_scope.max;

  ScaleStrategy scale_strategy;
  transform_client.SetTransformStrategy(&scale_strategy);
  scene_.TransformFigures(&transform_client, max, max, max);

  ParallelStrategy parallel_strategy;
  transform_client.SetTransformStrategy(&parallel_strategy);
  scene_.TransformFigures(&transform_client,
                          (scene_scope.min_x + scene_scope.max_x) * max,
                          (scene_scope.min_y + scene_scope.max_y) * max,
                          (scene_scope.min_z + scene_scope.max_z) * max);
}

void s21::Facade::CentralProjectionScene() {
  TransformClient transform_client;
  CentralStrategy central_strategy;
  transform_client.SetTransformStrategy(&central_strategy);
  SceneScope scene_scope = drawer_scene_.GetSceneScope();
  drawer_scene_.TransformFigures(&transform_client, scene_scope.min_z,
                                 scene_scope.max_z, 0.0);
}

void s21::Facade::VieweportScene() {
  TransformClient transform_client;
  VieweportStrategy vieweport_strategy;
  transform_client.SetTransformStrategy(&vieweport_strategy);
  drawer_scene_.TransformFigures(&transform_client, width_, height_, 1.0);

  scene_drawer_->DrawScene(drawer_scene_, drawer_setting_);
}

void s21::Facade::SetMovePosition(const double &x, const double &y,
                                  const double &z) noexcept {
  if (x != 0.0) {
    move_x_ += x;
  } else if (y != 0.0) {
    move_y_ += y;
  } else if (z != 0.0) {
    move_z_ += z;
  }
  SceneScope scene_scope = scene_.GetSceneScope();
  if (move_z_ < scene_scope.max_z + 1.0) move_z_ = scene_scope.max_z + 1.0;
}
