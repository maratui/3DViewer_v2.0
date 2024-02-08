#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_LAYOUT_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_LAYOUT_H_

#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>

namespace s21 {
class GridLayout : public QGridLayout {
  Q_OBJECT

 public:
  explicit GridLayout(QWidget *parent);
};

class VBoxLayout : public QVBoxLayout {
  Q_OBJECT

 public:
  explicit VBoxLayout(QWidget *parent);
};

class HBoxLayout : public QHBoxLayout {
  Q_OBJECT

 public:
  explicit HBoxLayout(QWidget *parent);
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_LAYOUT_H_
