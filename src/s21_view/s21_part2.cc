#include "s21_part2.h"

s21::Part2::Part2(int central_projection, int edge_line_type,
                  int vertex_display_method) {
  QString text[5];
  text[0] = "Тип проекции";
  text[1] = "Параллельная";
  text[2] = "Центральная";
  projection_two_radio_buttons_ = new TwoRadioButtons(text, central_projection);
  text[0] = "";
  text[1] = "Тип линии ребер";
  text[2] = "Сплошная";
  text[3] = "Пунктирная";
  text[4] = "ребер";
  edge_setting_up_ = new SettingUp(text, edge_line_type);
  text[0] = "Отображать вершины";
  text[1] = "Способ отображения вершин";
  text[2] = "Круг";
  text[3] = "Квадрат";
  text[4] = "вершин";
  vertex_setting_up_ = new SettingUp(text, vertex_display_method);
  background_color_button_ = new Button("Цвет фона", false);
  label_ = new Label("Part 2. Bonus. Settings", false);

  v_layout_ = new VBoxLayout(this);
  v_layout_->addWidget(label_, 0, Qt::AlignTop);
  v_layout_->addWidget(projection_two_radio_buttons_, 1, Qt::AlignTop);
  v_layout_->addWidget(edge_setting_up_, 2, Qt::AlignTop);
  v_layout_->addWidget(vertex_setting_up_, 3, Qt::AlignTop);
  v_layout_->addWidget(background_color_button_, 4, Qt::AlignTop);
  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}
