#include "s21_part1.h"

s21::Part1::Part1() {
  label_ = new Label("Part 1. 3DViewer", false);
  vertices_label_line_edit_ = new LabelLineEdit("Количество вершин:");
  edges_label_line_edit_ = new LabelLineEdit("Количество ребер:    ");
  translate_xyz_bleb_ =
      new XYZButtonLineEditButton("Перемещение модели", "0.2");
  rotate_xyz_bleb_ = new XYZButtonLineEditButton("Поворот модели", "45");
  scale_bleb_ = new ButtonLineEditButton("Масштабирование модели", "1.25");

  v_layout_ = new VBoxLayout(this);
  v_layout_->addWidget(label_, 0, Qt::AlignTop);
  v_layout_->addWidget(vertices_label_line_edit_, 1, Qt::AlignTop);
  v_layout_->addWidget(edges_label_line_edit_, 2, Qt::AlignTop);
  v_layout_->addWidget(translate_xyz_bleb_, 3, Qt::AlignTop);
  v_layout_->addWidget(rotate_xyz_bleb_, 4, Qt::AlignTop);
  v_layout_->addWidget(scale_bleb_, 5, Qt::AlignTop);

  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}
