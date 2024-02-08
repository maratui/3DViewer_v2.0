#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_PART2_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_PART2_H_

#include "s21_layout.h"
#include "s21_setting_up.h"
#include "s21_two_radio_buttons.h"

namespace s21 {
class Part2 : public QWidget {
  Q_OBJECT

 public:
  Part2(int central_projection, int edge_line_type, int vertex_display_method);

  TwoRadioButtons *projection_two_radio_buttons_{};
  SettingUp *edge_setting_up_{};
  SettingUp *vertex_setting_up_{};
  Button *background_color_button_{};

 private:
  Label *label_{};
  VBoxLayout *v_layout_{};
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_PART2_H_
