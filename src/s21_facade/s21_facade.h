#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_FACADE_S21_FACADE_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_FACADE_S21_FACADE_H_

#include <string>

#include "../s21_strategy/s21_central_strategy.h"
#include "../s21_strategy/s21_parallel_strategy.h"
#include "../s21_strategy/s21_rotate_strategy.h"
#include "../s21_strategy/s21_scale_strategy.h"
#include "../s21_strategy/s21_transform_client.h"
#include "../s21_strategy/s21_translate_strategy.h"
#include "../s21_strategy/s21_vieweport_strategy.h"
#include "s21_drawer_setting.h"
#include "s21_file_reader.h"
#include "s21_scene_drawer.h"

namespace s21 {
class Facade {
 public:
  Facade();

  bool LoadScene(const std::string &path);
  void MoveScene(const double &x, const double &y, const double &z);
  void RotateScene(const double &x, const double &y, const double &z);
  void ScaleScene(const double &x, const double &y, const double &z);
  void ProjectionScene(bool central_projection);

  void SetVertexColor(const QColor &color);
  void SetVertexDisplayMethod(int type);
  void SetVertexSize(int size);

  void SetEdgeColor(const QColor &color);
  void SetSolidDashedEdgeLineType(int type);
  void SetEdgeLineWidth(int size);

  void SetBackgroundColor(const QColor &color);

  std::string &GetObjectName() noexcept;
  std::size_t &GetNumberOfVertices() noexcept;
  std::size_t &GetNumberOfEdges() noexcept;

  QImage &GetImage();

 private:
  void ParallelProjectionScene();
  void CentralProjectionScene();
  void VieweportScene();
  void SetMovePosition(const double &x, const double &y,
                       const double &z) noexcept;

  SceneDrawer *scene_drawer_;
  double width_;
  double height_;

  FileReader file_reader_;
  std::string path_;
  std::string object_name_;

  Scene drawer_scene_;
  Scene scene_;

  double move_x_{};
  double move_y_{};
  double move_z_{};

  bool central_projection_{};

  DrawerSetting drawer_setting_{};

  std::size_t number_of_vertices_{};
  std::size_t number_of_edges_{};
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_FACADE_S21_FACADE_H_
