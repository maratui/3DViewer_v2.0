#include "s21_scene_drawer.h"

s21::SceneDrawer *s21::SceneDrawer::instance_ = nullptr;

s21::SceneDrawer *s21::SceneDrawer::GetInstance() {
  if (!instance_) {
    instance_ = new SceneDrawer();
  }

  return instance_;
}

s21::SceneDrawer::SceneDrawer() {
  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

QSize s21::SceneDrawer::sizeHint() const {
  QSize size = QOpenGLWidget::sizeHint();
  size.rwidth() = 640 * 2;
  size.rheight() = 480 * 2;

  return size;
}

void s21::SceneDrawer::DrawScene(const Scene &scene,
                                 const DrawerSetting &drawer_setting) noexcept {
  scene_ = scene;

  vertex_color_ = drawer_setting.vertex_setting.color;
  vertex_display_method_ = drawer_setting.vertex_setting.type;
  vertex_size_ = drawer_setting.vertex_setting.size;

  edge_color_ = drawer_setting.edge_setting.color;
  edge_line_type_ = drawer_setting.edge_setting.type;
  edge_line_width_ = drawer_setting.edge_setting.size;

  background_color_ = drawer_setting.background_color;

  update();
}

QImage &s21::SceneDrawer::GetImage() {
  image_ = grabFramebuffer();
  return image_;
}

void s21::SceneDrawer::paintGL() {
  GLfloat edge_rgb[5];
  GLfloat vertix_rgb[5];

  PreparingForPaintGL(edge_rgb, vertix_rgb);
  DrawGL(edge_rgb, vertix_rgb);
}

void s21::SceneDrawer::PreparingForPaintGL(GLfloat *edge_rgb,
                                           GLfloat *vertix_rgb) {
  GLfloat rgba[4];

  if (edge_line_type_) {
    glLineStipple(1, 0x3F07);
    glEnable(GL_LINE_STIPPLE);
  } else {
    glDisable(GL_LINE_STIPPLE);
  }
  edge_color_.getRgbF(&edge_rgb[0], &edge_rgb[1], &edge_rgb[2], &edge_rgb[3]);
  glColor3f(edge_rgb[0], edge_rgb[1], edge_rgb[2]);
  glLineWidth(edge_line_width_);

  if (vertex_display_method_ > -1) {
    if (vertex_display_method_ == 0) {
      glEnable(GL_POINT_SMOOTH);
    } else {
      glDisable(GL_POINT_SMOOTH);
    }
    vertex_color_.getRgbF(&vertix_rgb[0], &vertix_rgb[1], &vertix_rgb[2],
                          &vertix_rgb[3]);
    glPointSize(vertex_size_);
  }

  background_color_.getRgbF(&rgba[0], &rgba[1], &rgba[2], &rgba[3]);
  glClearColor(rgba[0], rgba[1], rgba[2], rgba[3]);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void s21::SceneDrawer::DrawGL(GLfloat *edge_rgb, GLfloat *vertix_rgb) {
  glEnableClientState(GL_VERTEX_ARRAY);
  double vertex_array[4];
  for (auto i = 0UL, figures_size = scene_.GetFigures().size();
       i < figures_size; i++) {
    auto figure = scene_.GetFigures()[i];
    for (auto j = 0UL, edges_size = figure.GetEdges().size(); j < edges_size;
         j++) {
      auto edge = figure.GetEdges()[j];
      vertex_array[0] = figure.GetVertices()[edge.GetBegin()].GetPosition().x;
      vertex_array[1] = figure.GetVertices()[edge.GetBegin()].GetPosition().y;
      vertex_array[2] = figure.GetVertices()[edge.GetEnd()].GetPosition().x;
      vertex_array[3] = figure.GetVertices()[edge.GetEnd()].GetPosition().y;
      glVertexPointer(2, GL_DOUBLE, 0, vertex_array);
      glDrawArrays(GL_LINES, 0, 2);
      if (vertex_display_method_ > -1) {
        glColor3f(vertix_rgb[0], vertix_rgb[1], vertix_rgb[2]);
        glDrawArrays(GL_POINTS, 0, 2);
        glColor3f(edge_rgb[0], edge_rgb[1], edge_rgb[2]);
      }
    }
  }
  glDisableClientState(GL_VERTEX_ARRAY);
}
