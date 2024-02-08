#include "s21_label.h"

s21::Label::Label(const QString &text, const bool alignleft) {
  setText(text);
  if (alignleft)
    setAlignment(Qt::AlignLeft);
  else
    setAlignment(Qt::AlignCenter);
  setMinimumSize(30, 30);
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}
