#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_LABEL_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_LABEL_H_

#include <QLabel>

namespace s21 {
class Label : public QLabel {
  Q_OBJECT

 public:
  Label(const QString &text, const bool alignleft);
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_LABEL_H_
