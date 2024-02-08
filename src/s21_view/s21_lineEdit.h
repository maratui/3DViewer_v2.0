#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_LINE_EDIT_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_LINE_EDIT_H_

#include <QLineEdit>

namespace s21 {
class LineEdit : public QLineEdit {
  Q_OBJECT

 public:
  LineEdit(const QString &text, const int max_length, const bool read_only);

  QSize sizeHint() const override;
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_VIEW_S21_LINE_EDIT_H_
