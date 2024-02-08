#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_VIEWER_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_VIEWER_H_

#include <QMessageBox>
#include <QtWidgets>

#include "../s21_controller/s21_controller.h"
#include "s21_part1.h"
#include "s21_part2.h"
#include "s21_part3.h"
#include "s21_settings.h"

namespace s21 {
class Viewer : public QWidget {
  Q_OBJECT

 public:
  explicit Viewer(s21::Controller *controller);
  Viewer(const Viewer &other) = delete;
  Viewer(Viewer &&other) = delete;
  void operator=(const Viewer &other) = delete;
  void operator=(const Viewer &&other) = delete;
  ~Viewer();

 private slots:
  void ObjectButtonClicked();
  void TranslateXBLEBClicked();
  void TranslateYBLEBClicked();
  void TranslateZBLEBClicked();
  void RotateXBLEBClicked();
  void RotateYBLEBClicked();
  void RotateZBLEBClicked();
  void ScaleBLEBClicked();
  void ParallelRadioButtonClicked();
  void CentralRadioButtonClicked();
  void SolidRadioButtonClicked();
  void DashedRadioButtonClicked();
  void EdgeColorButtonClicked();
  void EdgeLineWidthButtonClicked();
  void VertexCheckBoxClicked();
  void CircleRadioButtonClicked();
  void SquareRadioButtonClicked();
  void VertexColorButtonClicked();
  void VertexSizeButtonClicked();
  void BackgroundColorButtonClicked();
  void SavingImageButtonClicked();

 private:
  void GetSettings() noexcept;
  void CreateObjectButton();
  void CreateConnectPart1();
  void CreateConnectPart2();
  void CreateConnectPart3();
  void CreateGridLayout();
  double CheckValue(double value, double bound_top_value,
                    double bound_buttom_value) noexcept;

  Button *object_button_{};
  LineEdit *object_line_edit_{};
  Part1 *part1_{};
  Part2 *part2_{};
  Part3 *part3_{};
  QGridLayout *grid_layout_{};

  QColor vertex_color_ = Qt::white;
  int vertex_display_method_{};
  int vertex_size_{};
  QColor edge_color_ = Qt::white;
  int edge_line_type_{};
  int edge_line_width_{};
  QColor background_color_ = Qt::white;
  GLboolean central_projection_{};

  s21::Controller *controller_{};
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_VIEWER_H_
