#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_FACADE_S21_EDGE_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_FACADE_S21_EDGE_H_

namespace s21 {
class Edge {
 public:
  Edge() = delete;
  explicit Edge(const unsigned long &begin, const unsigned long &end);

  unsigned long &GetBegin() noexcept;
  unsigned long &GetEnd() noexcept;

 private:
  unsigned long begin_{};
  unsigned long end_{};
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_FACADE_S21_EDGE_H_
