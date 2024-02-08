#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_BUTTON_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_BUTTON_H_

#include <QPushButton>

namespace s21 {
class Button : public QPushButton {
  Q_OBJECT

 public:
  Button(const QString &text, const bool h_fixed);
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_BUTTON_H_
