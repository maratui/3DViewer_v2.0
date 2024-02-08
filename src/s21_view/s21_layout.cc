#include "s21_layout.h"

s21::GridLayout::GridLayout(QWidget *parent) : QGridLayout(parent) {
  setContentsMargins(3, 3, 3, 3);
  setSpacing(3);
}

s21::VBoxLayout::VBoxLayout(QWidget *parent) : QVBoxLayout(parent) {
  setContentsMargins(3, 3, 3, 3);
  setSpacing(3);
}

s21::HBoxLayout::HBoxLayout(QWidget *parent) : QHBoxLayout(parent) {
  setContentsMargins(3, 3, 3, 3);
  setSpacing(3);
}
