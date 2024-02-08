#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_CONTROLLER_S21_CONTROLLER_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_CONTROLLER_S21_CONTROLLER_H_

#include "../s21_facade/s21_facade.h"

namespace s21 {
class Controller {
 public:
  Controller() = delete;
  explicit Controller(Facade *facade);

  SceneDrawer *GetSceneDrawer() noexcept;

  bool LoadScene(const std::string &path) noexcept;
  void MoveScene(const double &x, const double &y, const double &z) noexcept;
  void RotateScene(const double &x, const double &y, const double &z) noexcept;
  void ScaleScene(const double &x, const double &y, const double &z) noexcept;
  void ProjectionScene(bool central_projection) noexcept;

  void SetVertexColor(const QColor &color) noexcept;
  void SetVertexDisplayMethod(int type) noexcept;
  void SetVertexSize(int size) noexcept;

  void SetEdgeColor(const QColor &color) noexcept;
  void SetSolidDashedEdgeLineType(int type) noexcept;
  void SetEdgeLineWidth(int size) noexcept;

  void SetBackgroundColor(const QColor &color) noexcept;

  std::string &GetObjectName() noexcept;
  std::size_t &GetNumberOfVertices() noexcept;
  std::size_t &GetNumberOfEdges() noexcept;

  QImage &GetImage() noexcept;

 private:
  Facade *facade_{};
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_CONTROLLER_S21_CONTROLLER_H_
