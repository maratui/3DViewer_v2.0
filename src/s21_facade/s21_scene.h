#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_FACADE_S21_SCENE_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_FACADE_S21_SCENE_H_

#include "s21_figure.h"
#include "s21_scene_scope.h"

namespace s21 {
class Scene {
 public:
  std::vector<Figure> &GetFigures() noexcept;
  SceneScope &GetSceneScope() noexcept;

  void Clear();

  void TransformFigures(TransformContext *transform_context, const double &x,
                        const double &y, const double &z) noexcept;

  void PushBack(const Figure &figure);

 private:
  double GetMaxSceneScope() noexcept;

  std::vector<Figure> figures_;
  SceneScope scene_scope_{};
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_FACADE_S21_SCENE_H_
