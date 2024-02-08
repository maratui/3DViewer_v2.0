#include "s21_lineEdit.h"

s21::LineEdit::LineEdit(const QString &text, const int max_length,
                        const bool read_only) {
  setText(text);
  setAlignment(Qt::AlignCenter);
  setMaxLength(max_length);
  setReadOnly(read_only);
  setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
}

QSize s21::LineEdit::sizeHint() const {
  QSize size = QLineEdit::sizeHint();
  size.rwidth() = 60;

  return size;
}
