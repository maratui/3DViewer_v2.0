#include "s21_controller.h"

s21::Controller::Controller(Facade *facade) : facade_(facade) {}

s21::SceneDrawer *s21::Controller::GetSceneDrawer() noexcept {
  return SceneDrawer::GetInstance();
}

bool s21::Controller::LoadScene(const std::string &path) noexcept {
  return facade_->LoadScene(path);
}

void s21::Controller::MoveScene(const double &x, const double &y,
                                const double &z) noexcept {
  facade_->MoveScene(x, y, z);
}

void s21::Controller::RotateScene(const double &x, const double &y,
                                  const double &z) noexcept {
  facade_->RotateScene(x, y, z);
}

void s21::Controller::ScaleScene(const double &x, const double &y,
                                 const double &z) noexcept {
  facade_->ScaleScene(x, y, z);
}

void s21::Controller::ProjectionScene(bool central_projection) noexcept {
  facade_->ProjectionScene(central_projection);
}

void s21::Controller::SetVertexColor(const QColor &color) noexcept {
  facade_->SetVertexColor(color);
}

void s21::Controller::SetVertexDisplayMethod(int type) noexcept {
  facade_->SetVertexDisplayMethod(type);
}

void s21::Controller::SetVertexSize(int size) noexcept {
  facade_->SetVertexSize(size);
}

void s21::Controller::SetEdgeColor(const QColor &color) noexcept {
  facade_->SetEdgeColor(color);
}

void s21::Controller::SetSolidDashedEdgeLineType(int type) noexcept {
  facade_->SetSolidDashedEdgeLineType(type);
}

void s21::Controller::SetEdgeLineWidth(int size) noexcept {
  facade_->SetEdgeLineWidth(size);
}

void s21::Controller::SetBackgroundColor(const QColor &color) noexcept {
  facade_->SetBackgroundColor(color);
}

std::string &s21::Controller::GetObjectName() noexcept {
  return facade_->GetObjectName();
}

std::size_t &s21::Controller::GetNumberOfVertices() noexcept {
  return facade_->GetNumberOfVertices();
}
std::size_t &s21::Controller::GetNumberOfEdges() noexcept {
  return facade_->GetNumberOfEdges();
}

QImage &s21::Controller::GetImage() noexcept { return facade_->GetImage(); }
