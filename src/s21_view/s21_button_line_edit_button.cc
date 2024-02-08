#include "s21_button_line_edit_button.h"

s21::ButtonLineEditButton::ButtonLineEditButton(const QString &text,
                                                const QString &value) {
  value_ = 0.0;
  label_ = new Label(text, false);
  minus_button_ = new Button("-", false);
  input_line_edit_ = new LineEdit(value, 4, false);
  plus_button_ = new Button("+", false);

  connect(minus_button_, SIGNAL(clicked()), this, SLOT(MinusButtonClicked()));
  connect(plus_button_, SIGNAL(clicked()), this, SLOT(PlusButtonClicked()));

  grid_layout_ = new GridLayout(this);
  grid_layout_->addWidget(label_, 0, 0, 1, 3);
  grid_layout_->addWidget(minus_button_, 1, 0);
  grid_layout_->addWidget(input_line_edit_, 1, 1);
  grid_layout_->addWidget(plus_button_, 1, 2);

  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

double &s21::ButtonLineEditButton::GetValue() noexcept { return value_; }

void s21::ButtonLineEditButton::MinusButtonClicked() {
  if (!input_line_edit_->text().isEmpty()) {
    value_ = -CheckValue();
    EmitSignal();
  }
}

void s21::ButtonLineEditButton::PlusButtonClicked() {
  if (!input_line_edit_->text().isEmpty()) {
    value_ = CheckValue();
    EmitSignal();
  }
}

double s21::ButtonLineEditButton::CheckValue() {
  double value = input_line_edit_->text().toDouble();
  value = fabs(value);
  input_line_edit_->setText(QString::number(value));

  return value;
}

void s21::ButtonLineEditButton::EmitSignal() {
  if (value_ != 0.0) {
    emit ValueChanged();
  }
}
