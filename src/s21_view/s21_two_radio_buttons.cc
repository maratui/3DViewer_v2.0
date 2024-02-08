#include "s21_two_radio_buttons.h"

s21::TwoRadioButtons::TwoRadioButtons(QString *text, const int checked) {
  label_ = new Label(text[0], false);
  first_radio_button_ =
      CreateQRadioButton(text[1], (checked == -1 || checked == 0));
  second_radio_button_ = CreateQRadioButton(text[2], (checked == 1));

  v_layout_ = new VBoxLayout(this);
  v_layout_->addWidget(label_, 0, Qt::AlignTop);
  v_layout_->addWidget(first_radio_button_, 1, Qt::AlignTop);
  v_layout_->addWidget(second_radio_button_, 2, Qt::AlignTop);
}

QRadioButton *s21::TwoRadioButtons::CreateQRadioButton(const QString &text,
                                                       const bool checked) {
  QRadioButton *radio_button = new QRadioButton;
  radio_button->setText(text);
  radio_button->setChecked(checked);

  return radio_button;
}
