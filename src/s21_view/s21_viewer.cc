#include "s21_viewer.h"

s21::Viewer::Viewer(Controller *controller) : controller_(controller) {
  setWindowTitle(tr("3DViewer v2.0"));
  GetSettings();
  CreateObjectButton();
  CreateConnectPart1();
  CreateConnectPart2();
  CreateConnectPart3();
  CreateGridLayout();
}

s21::Viewer::~Viewer() {
  GLfloat r, g, b, a;
  QSettings settings(ORGANIZATION_NAME, APPLICATION_NAME);

  settings.setValue("settings/central_projection", central_projection_);

  settings.setValue("settings/edge_line_type", edge_line_type_);
  edge_color_.getRgbF(&r, &g, &b, &a);
  settings.setValue("settings/edge_color/r", r);
  settings.setValue("settings/edge_color/g", g);
  settings.setValue("settings/edge_color/b", b);
  settings.setValue("settings/edge_line_width", edge_line_width_);

  settings.setValue("settings/vertex_display_method", vertex_display_method_);
  vertex_color_.getRgbF(&r, &g, &b, &a);
  settings.setValue("settings/vertex_color/r", r);
  settings.setValue("settings/vertex_color/g", g);
  settings.setValue("settings/vertex_color/b", b);
  settings.setValue("settings/vertex_size", vertex_size_);

  background_color_.getRgbF(&r, &g, &b, &a);
  settings.setValue("settings/background_color/r", r);
  settings.setValue("settings/background_color/g", g);
  settings.setValue("settings/background_color/b", b);
  settings.setValue("settings/background_color/a", a);
  settings.sync();
}

void s21::Viewer::CreateObjectButton() {
  object_button_ = new Button("Модель", true);
  object_line_edit_ = new LineEdit("", 255, true);
  connect(object_button_, SIGNAL(clicked()), this, SLOT(ObjectButtonClicked()));
}

void s21::Viewer::CreateConnectPart1() {
  part1_ = new Part1;

  connect(part1_->translate_xyz_bleb_->x_bleb_, SIGNAL(ValueChanged()), this,
          SLOT(TranslateXBLEBClicked()));
  connect(part1_->translate_xyz_bleb_->y_bleb_, SIGNAL(ValueChanged()), this,
          SLOT(TranslateYBLEBClicked()));
  connect(part1_->translate_xyz_bleb_->z_bleb_, SIGNAL(ValueChanged()), this,
          SLOT(TranslateZBLEBClicked()));

  connect(part1_->rotate_xyz_bleb_->x_bleb_, SIGNAL(ValueChanged()), this,
          SLOT(RotateXBLEBClicked()));
  connect(part1_->rotate_xyz_bleb_->y_bleb_, SIGNAL(ValueChanged()), this,
          SLOT(RotateYBLEBClicked()));
  connect(part1_->rotate_xyz_bleb_->z_bleb_, SIGNAL(ValueChanged()), this,
          SLOT(RotateZBLEBClicked()));

  connect(part1_->scale_bleb_, SIGNAL(ValueChanged()), this,
          SLOT(ScaleBLEBClicked()));
}

void s21::Viewer::CreateConnectPart2() {
  part2_ =
      new Part2(central_projection_, edge_line_type_, vertex_display_method_);

  connect(part2_->projection_two_radio_buttons_->first_radio_button_,
          SIGNAL(clicked()), this, SLOT(ParallelRadioButtonClicked()));
  connect(part2_->projection_two_radio_buttons_->second_radio_button_,
          SIGNAL(clicked()), this, SLOT(CentralRadioButtonClicked()));

  connect(part2_->edge_setting_up_->two_radio_buttons_->first_radio_button_,
          SIGNAL(clicked()), this, SLOT(SolidRadioButtonClicked()));
  connect(part2_->edge_setting_up_->two_radio_buttons_->second_radio_button_,
          SIGNAL(clicked()), this, SLOT(DashedRadioButtonClicked()));
  connect(part2_->edge_setting_up_->color_button_, SIGNAL(clicked()), this,
          SLOT(EdgeColorButtonClicked()));
  connect(part2_->edge_setting_up_->size_button_, SIGNAL(clicked()), this,
          SLOT(EdgeLineWidthButtonClicked()));

  connect(part2_->vertex_setting_up_->check_box_, SIGNAL(clicked()), this,
          SLOT(VertexCheckBoxClicked()));
  connect(part2_->vertex_setting_up_->two_radio_buttons_->first_radio_button_,
          SIGNAL(clicked()), this, SLOT(CircleRadioButtonClicked()));
  connect(part2_->vertex_setting_up_->two_radio_buttons_->second_radio_button_,
          SIGNAL(clicked()), this, SLOT(SquareRadioButtonClicked()));
  connect(part2_->vertex_setting_up_->color_button_, SIGNAL(clicked()), this,
          SLOT(VertexColorButtonClicked()));
  connect(part2_->vertex_setting_up_->size_button_, SIGNAL(clicked()), this,
          SLOT(VertexSizeButtonClicked()));

  connect(part2_->background_color_button_, SIGNAL(clicked()), this,
          SLOT(BackgroundColorButtonClicked()));
}

void s21::Viewer::CreateConnectPart3() {
  part3_ = new Part3;

  connect(part3_->saving_image_button_, SIGNAL(clicked()), this,
          SLOT(SavingImageButtonClicked()));
}

void s21::Viewer::CreateGridLayout() {
  grid_layout_ = new GridLayout(this);
  grid_layout_->setSizeConstraint(QLayout::SetFixedSize);
  grid_layout_->addWidget(object_button_, 0, 0, 1, 1);
  grid_layout_->addWidget(object_line_edit_, 0, 1, 1, 11);
  grid_layout_->addWidget(controller_->GetSceneDrawer(), 1, 0, 2, 10);
  grid_layout_->addWidget(part1_, 1, 10, 2, 1, Qt::AlignTop);
  grid_layout_->addWidget(part2_, 1, 11, Qt::AlignTop);
  grid_layout_->addWidget(part3_, 2, 11, Qt::AlignTop);
}
