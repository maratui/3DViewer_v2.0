#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_FACADE_S21_SCENE_DRAWER_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_FACADE_S21_SCENE_DRAWER_H_

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#endif

#include <QOpenGLWidget>

#include "s21_drawer_setting.h"
#include "s21_scene.h"

namespace s21 {
class SceneDrawer : public QOpenGLWidget {
 public:
  ~SceneDrawer() = default;

  static SceneDrawer *GetInstance();
  QSize sizeHint() const override;

  void DrawScene(const Scene &scene,
                 const DrawerSetting &drawer_setting) noexcept;

  QImage &GetImage();

 protected:
  void paintGL() override;

 private:
  SceneDrawer();
  SceneDrawer(const SceneDrawer &other) = delete;
  SceneDrawer(SceneDrawer &&other) = delete;
  void operator=(const SceneDrawer &other) = delete;
  void operator=(const SceneDrawer &&other) = delete;

  void PreparingForPaintGL(GLfloat *edge_rgb, GLfloat *vertix_rgb);
  void DrawGL(GLfloat *edge_rgb, GLfloat *vertix_rgb);

  static SceneDrawer *instance_;

  Scene scene_;

  QColor vertex_color_ = Qt::white;
  int vertex_display_method_{};
  int vertex_size_{};

  QColor edge_color_ = Qt::white;
  int edge_line_type_{};
  int edge_line_width_{};

  QColor background_color_ = Qt::white;

  QImage image_{};
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_FACADE_S21_SCENE_DRAWER_H_
