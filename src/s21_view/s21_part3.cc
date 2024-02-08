#include "s21_part3.h"

s21::Part3::Part3() {
  saving_image_button_ = new Button("Сохранить изображение", false);
  label_ = new Label("Part 3. Bonus. Record", false);

  v_layout_ = new VBoxLayout(this);
  v_layout_->addWidget(label_, 0, Qt::AlignTop);
  v_layout_->addWidget(saving_image_button_, 1, Qt::AlignTop);

  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}
