#include "s21_label_line_edit.h"

s21::LabelLineEdit::LabelLineEdit(const QString &text) {
  label_ = new Label(text, true);
  output_line_edit_ = new LineEdit("0", 7, true);

  h_layout_ = new HBoxLayout(this);
  h_layout_->addWidget(label_, 0);
  h_layout_->addWidget(output_line_edit_, 1);
}

void s21::LabelLineEdit::SetValue(const int value) noexcept {
  output_line_edit_->setText(QString::number(value));
}
