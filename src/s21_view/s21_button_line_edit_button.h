#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_BUTTON_LINE_EDIT_BUTTON_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_BUTTON_LINE_EDIT_BUTTON_H_

#include <QWidget>

#include "s21_button.h"
#include "s21_label.h"
#include "s21_layout.h"
#include "s21_lineEdit.h"

namespace s21 {
class ButtonLineEditButton : public QWidget {
  Q_OBJECT

 public:
  ButtonLineEditButton(const QString &text, const QString &value);

  double &GetValue() noexcept;

 private slots:
  void MinusButtonClicked();
  void PlusButtonClicked();

 signals:
  void ValueChanged();

 private:
  double CheckValue();
  void EmitSignal();

  Label *label_{};
  LineEdit *input_line_edit_{};
  Button *minus_button_{};
  Button *plus_button_{};
  GridLayout *grid_layout_{};

  double value_{};
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_BUTTON_LINE_EDIT_BUTTON_H_
