#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_FACADE_S21_DRAWER_SETTING_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_FACADE_S21_DRAWER_SETTING_H_

#include <QColor>

namespace s21 {
struct Setting {
  QColor color;
  int type;
  int size;
};

struct DrawerSetting {
  Setting vertex_setting;
  Setting edge_setting;
  QColor background_color;
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_FACADE_S21_DRAWER_SETTING_H_
