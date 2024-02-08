#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_XYZ_BUTTON_LINE_EDIT_BUTTON_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_XYZ_BUTTON_LINE_EDIT_BUTTON_H_

#include "s21_button_line_edit_button.h"
#include "s21_layout.h"

namespace s21 {
class XYZButtonLineEditButton : public QWidget {
  Q_OBJECT

 public:
  XYZButtonLineEditButton(const QString &text, const QString &value);

  double &GetXValue() noexcept;
  double &GetYValue() noexcept;
  double &GetZValue() noexcept;

  ButtonLineEditButton *x_bleb_{};
  ButtonLineEditButton *y_bleb_{};
  ButtonLineEditButton *z_bleb_{};

 private:
  VBoxLayout *v_layout_{};
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_XYZ_BUTTON_LINE_EDIT_BUTTON_H_
