#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_LABEL_LINE_EDIT_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_LABEL_LINE_EDIT_H_

#include <QWidget>

#include "s21_label.h"
#include "s21_layout.h"
#include "s21_lineEdit.h"

namespace s21 {
class LabelLineEdit : public QWidget {
  Q_OBJECT

 public:
  explicit LabelLineEdit(const QString &text);

  void SetValue(const int value) noexcept;

 private:
  Label *label_{};
  LineEdit *output_line_edit_{};
  HBoxLayout *h_layout_{};
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_LABEL_LINE_EDIT_H_
