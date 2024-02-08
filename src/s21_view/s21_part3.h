#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_PART3_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_PART3_H_

#include "s21_button.h"
#include "s21_label.h"
#include "s21_layout.h"

namespace s21 {
class Part3 : public QWidget {
  Q_OBJECT

 public:
  Part3();

  Button *saving_image_button_{};

 private:
  Label *label_{};
  VBoxLayout *v_layout_{};
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_PART3_H_
