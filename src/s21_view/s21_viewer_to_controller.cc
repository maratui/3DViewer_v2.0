#include "s21_viewer.h"

void s21::Viewer::GetSettings() noexcept {
  QSettings settings(ORGANIZATION_NAME, APPLICATION_NAME);

  central_projection_ =
      settings.value("settings/central_projection", 0).toInt();
  controller_->ProjectionScene(central_projection_);

  edge_line_type_ = settings.value("settings/edge_line_type", 0).toInt();
  controller_->SetSolidDashedEdgeLineType(edge_line_type_);

  edge_color_ =
      QColor::fromRgbF(settings.value("settings/edge_color/r", 0).toDouble(),
                       settings.value("settings/edge_color/g", 0).toDouble(),
                       settings.value("settings/edge_color/b", 0).toDouble());
  controller_->SetEdgeColor(edge_color_);

  edge_line_width_ = settings.value("settings/edge_line_width", 1).toInt();
  controller_->SetEdgeLineWidth(edge_line_width_);

  vertex_display_method_ =
      settings.value("settings/vertex_display_method", -1).toInt();
  controller_->SetVertexDisplayMethod(vertex_display_method_);

  vertex_color_ =
      QColor::fromRgbF(settings.value("settings/vertex_color/r", 0).toDouble(),
                       settings.value("settings/vertex_color/g", 0).toDouble(),
                       settings.value("settings/vertex_color/b", 0).toDouble());
  controller_->SetVertexColor(vertex_color_);

  vertex_size_ = settings.value("settings/vertex_size", 1).toInt();
  controller_->SetVertexSize(vertex_size_);

  background_color_ = QColor::fromRgbF(
      settings.value("settings/background_color/r", 1).toDouble(),
      settings.value("settings/background_color/g", 1).toDouble(),
      settings.value("settings/background_color/b", 1).toDouble(),
      settings.value("settings/background_color/a", 1).toDouble());
  controller_->SetBackgroundColor(background_color_);
}

void s21::Viewer::ObjectButtonClicked() {
  QString filename = QFileDialog::getOpenFileName(
      this, "Выбрать файл с моделью", ".", "*.obj");
  if (filename != "") {
    if (!controller_->LoadScene(filename.toStdString())) {
      object_line_edit_->setText(
          QString::fromStdString(controller_->GetObjectName()));
      object_line_edit_->setCursorPosition(0);

      part1_->vertices_label_line_edit_->SetValue(
          controller_->GetNumberOfVertices());
      part1_->edges_label_line_edit_->SetValue(controller_->GetNumberOfEdges());
    } else {
      object_line_edit_->setText("");
      QMessageBox msg;
      msg.setText("Invalid data");
      msg.exec();
    }
  }
}

void s21::Viewer::TranslateXBLEBClicked() {
  double value =
      CheckValue(part1_->translate_xyz_bleb_->GetXValue(), 5.0, -5.0);
  controller_->MoveScene(value, 0.0, 0.0);
}

void s21::Viewer::TranslateYBLEBClicked() {
  double value =
      CheckValue(part1_->translate_xyz_bleb_->GetYValue(), 5.0, -5.0);
  controller_->MoveScene(0.0, value, 0.0);
}

void s21::Viewer::TranslateZBLEBClicked() {
  double value =
      CheckValue(part1_->translate_xyz_bleb_->GetZValue(), 5.0, -5.0);
  controller_->MoveScene(0.0, 0.0, value);
}

void s21::Viewer::RotateXBLEBClicked() {
  double value =
      CheckValue(part1_->rotate_xyz_bleb_->GetXValue(), 360.0, -360.0);
  controller_->RotateScene(value, 0.0, 0.0);
}

void s21::Viewer::RotateYBLEBClicked() {
  double value =
      CheckValue(part1_->rotate_xyz_bleb_->GetYValue(), 360.0, -360.0);
  controller_->RotateScene(0.0, value, 0.0);
}

void s21::Viewer::RotateZBLEBClicked() {
  double value =
      CheckValue(part1_->rotate_xyz_bleb_->GetZValue(), 360.0, -360.0);
  controller_->RotateScene(0.0, 0.0, value);
}

void s21::Viewer::ScaleBLEBClicked() {
  double value = part1_->scale_bleb_->GetValue();
  if (value < 0.0) value = -1.0 / value;
  value = CheckValue(value, 2.0, 0.5);
  controller_->ScaleScene(value, value, value);
}

void s21::Viewer::ParallelRadioButtonClicked() {
  central_projection_ = false;
  controller_->ProjectionScene(central_projection_);
}

void s21::Viewer::CentralRadioButtonClicked() {
  central_projection_ = true;
  controller_->ProjectionScene(central_projection_);
}

void s21::Viewer::SolidRadioButtonClicked() {
  edge_line_type_ = 0;
  controller_->SetSolidDashedEdgeLineType(edge_line_type_);
}

void s21::Viewer::DashedRadioButtonClicked() {
  edge_line_type_ = 1;
  controller_->SetSolidDashedEdgeLineType(edge_line_type_);
}

void s21::Viewer::EdgeColorButtonClicked() {
  edge_color_ = QColorDialog::getColor(Qt::red, this, "colors");
  controller_->SetEdgeColor(edge_color_);
}

void s21::Viewer::EdgeLineWidthButtonClicked() {
  edge_line_width_ = QInputDialog::getInt(
      this, "input", "Толщина ребра:", QLineEdit::Normal, 1, 10);
  if (edge_line_width_ < 1) edge_line_width_ = 1;
  controller_->SetEdgeLineWidth(edge_line_width_);
}

void s21::Viewer::VertexCheckBoxClicked() {
  part2_->vertex_setting_up_->SetSettingUpEnabled(
      part2_->vertex_setting_up_->check_box_->isChecked());
  if (part2_->vertex_setting_up_->check_box_->isChecked()) {
    if (part2_->vertex_setting_up_->two_radio_buttons_->first_radio_button_
            ->isChecked()) {
      vertex_display_method_ = 0;
      controller_->SetVertexDisplayMethod(vertex_display_method_);
    } else {
      vertex_display_method_ = 1;
      controller_->SetVertexDisplayMethod(vertex_display_method_);
    }
  } else {
    vertex_display_method_ = -1;
    controller_->SetVertexDisplayMethod(vertex_display_method_);
  }
}

void s21::Viewer::CircleRadioButtonClicked() {
  vertex_display_method_ = 0;
  controller_->SetVertexDisplayMethod(vertex_display_method_);
}

void s21::Viewer::SquareRadioButtonClicked() {
  vertex_display_method_ = 1;
  controller_->SetVertexDisplayMethod(vertex_display_method_);
}

void s21::Viewer::VertexColorButtonClicked() {
  vertex_color_ = QColorDialog::getColor(Qt::red, this, "colors");
  controller_->SetVertexColor(vertex_color_);
}

void s21::Viewer::VertexSizeButtonClicked() {
  vertex_size_ = QInputDialog::getInt(
      this, "input", "Размер вершин:", QLineEdit::Normal, 1, 50);
  if (vertex_size_ < 1) vertex_size_ = 1;
  controller_->SetVertexSize(vertex_size_);
}

void s21::Viewer::BackgroundColorButtonClicked() {
  background_color_ = QColorDialog::getColor(Qt::red, this, "colors");
  controller_->SetBackgroundColor(background_color_);
}

void s21::Viewer::SavingImageButtonClicked() {
  QString filename = QFileDialog::getSaveFileName(this, "Сохранить изображение",
                                                  "", "Image (*.bmp *.jpeg)");
  if (filename != "") {
    controller_->GetImage().save(filename, 0, 100);
  }
}

double s21::Viewer::CheckValue(double value, double bound_top_value,
                               double bound_buttom_value) noexcept {
  if (value > bound_top_value)
    value = bound_top_value;
  else if (value < bound_buttom_value)
    value = bound_buttom_value;

  return value;
}
