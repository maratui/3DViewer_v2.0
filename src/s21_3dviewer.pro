QT      += widgets opengl openglwidgets

CONFIG  += c++17

SOURCES += \
  ../s21_model/s21_transform_matrix.cc \
  ../s21_model/s21_parallel_projection.cc \
  ../s21_model/s21_central_projection.cc \
  ../s21_model/s21_scale_to_projection.cc \
  ../s21_model/s21_rotate_to_projection.cc \
  ../s21_model/s21_translate_to_projection.cc \
  ../s21_model/s21_projection_to_vieweport.cc \
  ../s21_facade/s21_facade.cc \
  ../s21_facade/s21_file_reader.cc \
  ../s21_facade/s21_scene_drawer.cc \
  ../s21_facade/s21_scene.cc \
  ../s21_facade/s21_figure.cc \
  ../s21_facade/s21_edge.cc \
  ../s21_facade/s21_vertex.cc \
  ../s21_controller/s21_controller.cc \
  ../s21_view/s21_main.cc \
  ../s21_view/s21_viewer.cc \
  ../s21_view/s21_viewer_to_controller.cc \
  ../s21_view/s21_part1.cc \
  ../s21_view/s21_part2.cc \
  ../s21_view/s21_part3.cc \
  ../s21_view/s21_setting_up.cc \
  ../s21_view/s21_two_radio_buttons.cc \
  ../s21_view/s21_xyz_button_line_edit_button.cc \
  ../s21_view/s21_button_line_edit_button.cc \
  ../s21_view/s21_label_line_edit.cc \
  ../s21_view/s21_button.cc \
  ../s21_view/s21_lineEdit.cc \
  ../s21_view/s21_label.cc \
  ../s21_view/s21_layout.cc

HEADERS += \
  ../s21_strategy/s21_vieweport_strategy.h \
  ../s21_strategy/s21_parallel_strategy.h \
  ../s21_strategy/s21_central_strategy.h \
  ../s21_strategy/s21_transform_strategy.h \
  ../s21_strategy/s21_rotate_strategy.h \
  ../s21_strategy/s21_scale_strategy.h \
  ../s21_strategy/s21_transform_context.h \
  ../s21_strategy/s21_transform_client.h \
  ../s21_model/s21_transform_matrix.h \
  ../s21_model/s21_parallel_projection.h \
  ../s21_model/s21_central_projection.h \
  ../s21_model/s21_scale_to_projection.h \
  ../s21_model/s21_rotate_to_projection.h \
  ../s21_model/s21_translate_to_projection.h \
  ../s21_model/s21_projection_to_vieweport.h \
  ../s21_facade/s21_facade.h \
  ../s21_facade/s21_file_reader.h \
  ../s21_facade/s21_scene_drawer.h \
  ../s21_facade/s21_scene.h \
  ../s21_facade/s21_figure.h \
  ../s21_facade/s21_edge.h \
  ../s21_facade/s21_vertex.h \
  ../s21_facade/s21_point.h \
  ../s21_controller/s21_controller.h \
  ../s21_view/s21_settings.h \
  ../s21_view/s21_viewer.h \
  ../s21_view/s21_part1.h \
  ../s21_view/s21_part2.h \
  ../s21_view/s21_part3.h \
  ../s21_view/s21_setting_up.h \
  ../s21_view/s21_two_radio_buttons.h \
  ../s21_view/s21_xyz_button_line_edit_button.h \
  ../s21_view/s21_button_line_edit_button.h \
  ../s21_view/s21_label_line_edit.h \
  ../s21_view/s21_button.h \
  ../s21_view/s21_lineEdit.h \
  ../s21_view/s21_label.h \
  ../s21_view/s21_layout.h
