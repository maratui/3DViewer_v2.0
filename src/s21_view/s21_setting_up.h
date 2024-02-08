#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_SETTING_UP_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_SETTING_UP_H_

#include <QCheckBox>

#include "s21_button.h"
#include "s21_layout.h"
#include "s21_two_radio_buttons.h"

namespace s21 {
class SettingUp : public QWidget {
  Q_OBJECT

 public:
  SettingUp(QString *text, const int checked);

  void SetSettingUpEnabled(const bool enabled) noexcept;

  QCheckBox *check_box_{};
  TwoRadioButtons *two_radio_buttons_{};
  Button *color_button_{};
  Button *size_button_{};

 private:
  VBoxLayout *v_layout_{};
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_SETTING_UP_H_
