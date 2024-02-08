#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_TWO_RADIO_BUTTONS_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_TWO_RADIO_BUTTONS_H_

#include <QRadioButton>
#include <QWidget>

#include "s21_label.h"
#include "s21_layout.h"

namespace s21 {
class TwoRadioButtons : public QWidget {
  Q_OBJECT

 public:
  TwoRadioButtons(QString *text, const int checked);

  QRadioButton *first_radio_button_{};
  QRadioButton *second_radio_button_{};

 private:
  QRadioButton *CreateQRadioButton(const QString &text, const bool checked);

  Label *label_{};
  VBoxLayout *v_layout_{};
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_TWO_RADIO_BUTTONS_H_
