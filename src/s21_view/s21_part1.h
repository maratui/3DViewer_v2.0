#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_PART1_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_PART1_H_

#include "s21_button_line_edit_button.h"
#include "s21_label_line_edit.h"
#include "s21_layout.h"
#include "s21_xyz_button_line_edit_button.h"

namespace s21 {
class Part1 : public QWidget {
  Q_OBJECT

 public:
  Part1();

  LabelLineEdit *vertices_label_line_edit_{};
  LabelLineEdit *edges_label_line_edit_{};
  XYZButtonLineEditButton *translate_xyz_bleb_{};
  XYZButtonLineEditButton *rotate_xyz_bleb_{};
  ButtonLineEditButton *scale_bleb_{};

 private:
  Label *label_{};
  VBoxLayout *v_layout_{};
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_PART1_H_
