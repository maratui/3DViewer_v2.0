#include "s21_xyz_button_line_edit_button.h"

s21::XYZButtonLineEditButton::XYZButtonLineEditButton(const QString &text,
                                                      const QString &value) {
  x_bleb_ = new ButtonLineEditButton(text + " по оси X", value);
  y_bleb_ = new ButtonLineEditButton(text + " по оси Y", value);
  z_bleb_ = new ButtonLineEditButton(text + " по оси Z", value);

  v_layout_ = new VBoxLayout(this);
  v_layout_->addWidget(x_bleb_, 0, Qt::AlignTop);
  v_layout_->addWidget(y_bleb_, 1, Qt::AlignTop);
  v_layout_->addWidget(z_bleb_, 2, Qt::AlignTop);

  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

double &s21::XYZButtonLineEditButton::GetXValue() noexcept {
  return x_bleb_->GetValue();
}

double &s21::XYZButtonLineEditButton::GetYValue() noexcept {
  return y_bleb_->GetValue();
}

double &s21::XYZButtonLineEditButton::GetZValue() noexcept {
  return z_bleb_->GetValue();
}
