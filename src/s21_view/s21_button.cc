#include "s21_button.h"

s21::Button::Button(const QString &text, const bool h_fixed) {
  setText(text);
  if (h_fixed)
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  else
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}
