#include "s21_setting_up.h"

s21::SettingUp::SettingUp(QString *text, const int checked) {
  int v{};
  v_layout_ = new VBoxLayout(this);
  if (text[0] != "") {
    check_box_ = new QCheckBox(text[0]);
    if (checked > -1)
      check_box_->setChecked(true);
    else
      check_box_->setChecked(false);
    v_layout_->addWidget(check_box_, 0, Qt::AlignTop);
    v = 1;
  } else {
    check_box_ = nullptr;
    v = 0;
  }
  two_radio_buttons_ = new TwoRadioButtons(++text, checked);
  color_button_ = new Button("Цвет " + text[3], false);
  size_button_ = new Button("Толщина " + text[3], false);
  if (v) SetSettingUpEnabled(checked > -1);

  v_layout_->addWidget(two_radio_buttons_, v, Qt::AlignTop);
  v_layout_->addWidget(color_button_, v + 1, Qt::AlignTop);
  v_layout_->addWidget(size_button_, v + 2, Qt::AlignTop);
}

void s21::SettingUp::SetSettingUpEnabled(const bool enabled) noexcept {
  if (enabled) {
    two_radio_buttons_->setEnabled(true);
    color_button_->setEnabled(true);
    size_button_->setEnabled(true);
  } else {
    two_radio_buttons_->setDisabled(true);
    color_button_->setDisabled(true);
    size_button_->setDisabled(true);
  }
}
