#include <gtest/gtest.h>

#include "../s21_facade/s21_file_reader.h"
#include "../s21_strategy/s21_central_strategy.h"
#include "../s21_strategy/s21_parallel_strategy.h"
#include "../s21_strategy/s21_rotate_strategy.h"
#include "../s21_strategy/s21_scale_strategy.h"
#include "../s21_strategy/s21_transform_client.h"
#include "../s21_strategy/s21_translate_strategy.h"
#include "../s21_strategy/s21_vieweport_strategy.h"

TEST(Test3DViewer, ReadScene) {
  s21::Scene scene;
  std::size_t number_of_vertices;
  std::size_t number_of_edges;
  std::string path = "s21_tests/cub.txt";
  s21::FileReader file_reader;

  file_reader.ReadScene(scene, number_of_vertices, number_of_edges, path);
  //---------------------------------------------------------------------------
  EXPECT_NEAR(1.0, scene.GetFigures().at(0).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(0).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(0).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(0).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(0).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(0).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(0).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(0).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(0).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(0).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(0).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(0).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(2.0, scene.GetFigures().at(1).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(1).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(1).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(1).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(1).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(1).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(1).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(1).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(1).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(1).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(1).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(1).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(2.0, scene.GetFigures().at(2).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(2).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(2).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(2).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(2).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(2).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(2).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(2).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(2).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(2).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(2).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(2).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(1.0, scene.GetFigures().at(3).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(3).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(3).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(3).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(3).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(3).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(3).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(3).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(3).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(3).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(3).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(3).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(1.0, scene.GetFigures().at(4).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(4).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(4).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(4).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(4).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(4).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(4).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(4).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(4).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(4).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(4).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(4).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(1.0, scene.GetFigures().at(5).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(5).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(5).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(5).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(5).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(5).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(5).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(5).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(5).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(5).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(5).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(5).GetVertices().at(3).GetPosition().z,
              1.0e-7);
  //---------------------------------------------------------------------------
  EXPECT_EQ(8, number_of_vertices);
  EXPECT_EQ(12, number_of_edges);

  file_reader.ReadScene(scene, number_of_vertices, number_of_edges,
                        "s21_tests/skull.txt");

  EXPECT_EQ("cube     Название файла: s21_tests/cub.txt",
            file_reader.GetObjectName(path));
  EXPECT_EQ("Cube     Название файла: s21_tests/cub_name.txt",
            file_reader.GetObjectName("s21_tests/cub_name.txt"));
  EXPECT_EQ("cub_not_name     Название файла: s21_tests/cub_not_name.txt",
            file_reader.GetObjectName("s21_tests/cub_not_name.txt"));
}

TEST(Test3DViewer, ClearScene) {
  s21::Scene scene;
  std::size_t number_of_vertices;
  std::size_t number_of_edges;
  std::string path = "s21_tests/cub.txt";
  s21::FileReader file_reader;
  file_reader.ReadScene(scene, number_of_vertices, number_of_edges, path);
  scene.Clear();
  EXPECT_EQ(0UL, scene.GetFigures().size());
}

void ParallelProjectionScene(s21::Scene &scene) {
  s21::TransformClient transform_client;

  s21::SceneScope scene_scope = scene.GetSceneScope();
  double max = 1.0 / scene_scope.max;

  s21::ScaleStrategy scale_strategy;
  transform_client.SetTransformStrategy(&scale_strategy);
  scene.TransformFigures(&transform_client, max, max, max);

  s21::ParallelStrategy parallel_strategy;
  transform_client.SetTransformStrategy(&parallel_strategy);
  scene.TransformFigures(&transform_client,
                         (scene_scope.min_x + scene_scope.max_x) * max,
                         (scene_scope.min_y + scene_scope.max_y) * max,
                         (scene_scope.min_z + scene_scope.max_z) * max);
}

TEST(Test3DViewer, ParallelProjectionScene) {
  s21::Scene scene;
  std::size_t number_of_vertices;
  std::size_t number_of_edges;
  std::string path = "s21_tests/cub.txt";
  s21::FileReader file_reader;
  file_reader.ReadScene(scene, number_of_vertices, number_of_edges, path);

  ParallelProjectionScene(scene);
  //---------------------------------------------------------------------------
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(0).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(0).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(0).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(0).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(0).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(0).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(0).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(0).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(0).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(0).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(0).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(0).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(1.0, scene.GetFigures().at(1).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(1).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(1).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(1).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(1).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(1).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(1).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(1).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(1).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(1).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(1).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(1).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(1.0, scene.GetFigures().at(2).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(2).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(2).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(2).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(2).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(2).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(2).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(2).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(2).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(2).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(2).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(2).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(3).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(3).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(3).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(3).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(3).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(3).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(3).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(3).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(3).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(3).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(3).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(3).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(4).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(4).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(4).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(4).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(4).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(4).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(4).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(4).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(4).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(4).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(4).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(4).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(5).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(5).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(5).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(5).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(5).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(5).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(5).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(5).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(5).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(5).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(5).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(5).GetVertices().at(3).GetPosition().z,
              1.0e-7);
  //---------------------------------------------------------------------------
  for (std::size_t i = 0; i < scene.GetFigures().size(); i++) {
    EXPECT_EQ(0, scene.GetFigures().at(i).GetEdges().at(0).GetBegin());
    EXPECT_EQ(1, scene.GetFigures().at(i).GetEdges().at(0).GetEnd());
    EXPECT_EQ(1, scene.GetFigures().at(i).GetEdges().at(1).GetBegin());
    EXPECT_EQ(2, scene.GetFigures().at(i).GetEdges().at(1).GetEnd());
    EXPECT_EQ(2, scene.GetFigures().at(i).GetEdges().at(2).GetBegin());
    EXPECT_EQ(3, scene.GetFigures().at(i).GetEdges().at(2).GetEnd());
    EXPECT_EQ(3, scene.GetFigures().at(i).GetEdges().at(3).GetBegin());
    EXPECT_EQ(0, scene.GetFigures().at(i).GetEdges().at(3).GetEnd());
  }
  //---------------------------------------------------------------------------

  scene.Clear();
  file_reader.ReadScene(scene, number_of_vertices, number_of_edges,
                        "s21_tests/cub_name.txt");
  ParallelProjectionScene(scene);
  EXPECT_NEAR(2.0, scene.GetSceneScope().max, 1.0e-7);

  scene.Clear();
  file_reader.ReadScene(scene, number_of_vertices, number_of_edges,
                        "s21_tests/cub_not_name.txt");
  ParallelProjectionScene(scene);
  EXPECT_NEAR(2.0, scene.GetSceneScope().max, 1.0e-7);
}

void MoveScene(s21::Scene &scene, const double &x, const double &y,
               const double &z) {
  s21::TransformClient transform_client;
  s21::TranslateStrategy translate_strategy;
  transform_client.SetTransformStrategy(&translate_strategy);
  scene.TransformFigures(&transform_client, x, y, z);
}

TEST(Test3DViewer, MoveScene) {
  s21::Scene scene;
  std::size_t number_of_vertices;
  std::size_t number_of_edges;
  std::string path = "s21_tests/cub.txt";
  s21::FileReader file_reader;
  file_reader.ReadScene(scene, number_of_vertices, number_of_edges, path);
  ParallelProjectionScene(scene);

  MoveScene(scene, 0.1, 0.2, 0.3);
  //---------------------------------------------------------------------------
  EXPECT_NEAR(-0.9,
              scene.GetFigures().at(0).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.2, scene.GetFigures().at(0).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.3, scene.GetFigures().at(0).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-0.9,
              scene.GetFigures().at(0).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-0.8,
              scene.GetFigures().at(0).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.3, scene.GetFigures().at(0).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.1, scene.GetFigures().at(0).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-0.8,
              scene.GetFigures().at(0).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.3, scene.GetFigures().at(0).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.1, scene.GetFigures().at(0).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.2, scene.GetFigures().at(0).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.3, scene.GetFigures().at(0).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(1.1, scene.GetFigures().at(1).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.2, scene.GetFigures().at(1).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-0.699999999999,
              scene.GetFigures().at(1).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.1, scene.GetFigures().at(1).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-0.8,
              scene.GetFigures().at(1).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-0.6999999999,
              scene.GetFigures().at(1).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-0.9,
              scene.GetFigures().at(1).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-0.8,
              scene.GetFigures().at(1).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-0.6999999999,
              scene.GetFigures().at(1).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-0.9,
              scene.GetFigures().at(1).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.2, scene.GetFigures().at(1).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-0.6999999999,
              scene.GetFigures().at(1).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(1.1, scene.GetFigures().at(2).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.2, scene.GetFigures().at(2).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.3, scene.GetFigures().at(2).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.1, scene.GetFigures().at(2).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-0.8,
              scene.GetFigures().at(2).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.3, scene.GetFigures().at(2).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.1, scene.GetFigures().at(2).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-0.8,
              scene.GetFigures().at(2).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-0.6999999999,
              scene.GetFigures().at(2).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.1, scene.GetFigures().at(2).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.2, scene.GetFigures().at(2).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-0.6999999999,
              scene.GetFigures().at(2).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(-0.9,
              scene.GetFigures().at(3).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.2, scene.GetFigures().at(3).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-0.6999999999,
              scene.GetFigures().at(3).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-0.9,
              scene.GetFigures().at(3).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.2, scene.GetFigures().at(3).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.3, scene.GetFigures().at(3).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.1, scene.GetFigures().at(3).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.2, scene.GetFigures().at(3).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.3, scene.GetFigures().at(3).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.1, scene.GetFigures().at(3).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.2, scene.GetFigures().at(3).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-0.6999999999,
              scene.GetFigures().at(3).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(-0.9,
              scene.GetFigures().at(4).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.2, scene.GetFigures().at(4).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-0.69999999999,
              scene.GetFigures().at(4).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-0.9,
              scene.GetFigures().at(4).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-0.8,
              scene.GetFigures().at(4).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-0.6999999999,
              scene.GetFigures().at(4).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-0.9,
              scene.GetFigures().at(4).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-0.8,
              scene.GetFigures().at(4).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.3, scene.GetFigures().at(4).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-0.9,
              scene.GetFigures().at(4).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.2, scene.GetFigures().at(4).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.3, scene.GetFigures().at(4).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(-0.9,
              scene.GetFigures().at(5).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-0.8,
              scene.GetFigures().at(5).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.3, scene.GetFigures().at(5).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-0.9,
              scene.GetFigures().at(5).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-0.8,
              scene.GetFigures().at(5).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-0.6999999999,
              scene.GetFigures().at(5).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.1, scene.GetFigures().at(5).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-0.8,
              scene.GetFigures().at(5).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-0.6999999999,
              scene.GetFigures().at(5).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.1, scene.GetFigures().at(5).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-0.8,
              scene.GetFigures().at(5).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.3, scene.GetFigures().at(5).GetVertices().at(3).GetPosition().z,
              1.0e-7);
  //---------------------------------------------------------------------------
}

void VieweportScene(s21::Scene &scene, const double &width,
                    const double &height) {
  s21::TransformClient transform_client;
  s21::VieweportStrategy vieweport_strategy;
  transform_client.SetTransformStrategy(&vieweport_strategy);
  scene.TransformFigures(&transform_client, width, height, 1.0);
}

TEST(Test3DViewer, VieweportScene) {
  s21::Scene scene;
  std::size_t number_of_vertices;
  std::size_t number_of_edges;
  std::string path = "s21_tests/cub.txt";
  s21::FileReader file_reader;
  file_reader.ReadScene(scene, number_of_vertices, number_of_edges, path);
  ParallelProjectionScene(scene);
  MoveScene(scene, 0.1, 0.2, 0.3);

  VieweportScene(scene, 1280, 960);
  //---------------------------------------------------------------------------
  EXPECT_NEAR(-0.675,
              scene.GetFigures().at(0).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.2, scene.GetFigures().at(0).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.3, scene.GetFigures().at(0).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-0.675,
              scene.GetFigures().at(0).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-0.8,
              scene.GetFigures().at(0).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.3, scene.GetFigures().at(0).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(0.825,
              scene.GetFigures().at(0).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-0.8,
              scene.GetFigures().at(0).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.3, scene.GetFigures().at(0).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(0.825,
              scene.GetFigures().at(0).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.2, scene.GetFigures().at(0).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.3, scene.GetFigures().at(0).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(0.825,
              scene.GetFigures().at(1).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.2, scene.GetFigures().at(1).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-0.699999999999,
              scene.GetFigures().at(1).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(0.825,
              scene.GetFigures().at(1).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-0.8,
              scene.GetFigures().at(1).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-0.6999999999,
              scene.GetFigures().at(1).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-0.675,
              scene.GetFigures().at(1).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-0.8,
              scene.GetFigures().at(1).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-0.6999999999,
              scene.GetFigures().at(1).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-0.675,
              scene.GetFigures().at(1).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.2, scene.GetFigures().at(1).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-0.6999999999,
              scene.GetFigures().at(1).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(0.825,
              scene.GetFigures().at(2).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.2, scene.GetFigures().at(2).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.3, scene.GetFigures().at(2).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(0.825,
              scene.GetFigures().at(2).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-0.8,
              scene.GetFigures().at(2).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.3, scene.GetFigures().at(2).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(0.825,
              scene.GetFigures().at(2).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-0.8,
              scene.GetFigures().at(2).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-0.6999999999,
              scene.GetFigures().at(2).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(0.825,
              scene.GetFigures().at(2).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.2, scene.GetFigures().at(2).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-0.6999999999,
              scene.GetFigures().at(2).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(-0.675,
              scene.GetFigures().at(3).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.2, scene.GetFigures().at(3).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-0.6999999999,
              scene.GetFigures().at(3).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-0.675,
              scene.GetFigures().at(3).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.2, scene.GetFigures().at(3).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.3, scene.GetFigures().at(3).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(0.825,
              scene.GetFigures().at(3).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.2, scene.GetFigures().at(3).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.3, scene.GetFigures().at(3).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(0.825,
              scene.GetFigures().at(3).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.2, scene.GetFigures().at(3).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-0.6999999999,
              scene.GetFigures().at(3).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(-0.675,
              scene.GetFigures().at(4).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.2, scene.GetFigures().at(4).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-0.69999999999,
              scene.GetFigures().at(4).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-0.675,
              scene.GetFigures().at(4).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-0.8,
              scene.GetFigures().at(4).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-0.6999999999,
              scene.GetFigures().at(4).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-0.675,
              scene.GetFigures().at(4).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-0.8,
              scene.GetFigures().at(4).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.3, scene.GetFigures().at(4).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-0.675,
              scene.GetFigures().at(4).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.2, scene.GetFigures().at(4).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.3, scene.GetFigures().at(4).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(-0.675,
              scene.GetFigures().at(5).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-0.8,
              scene.GetFigures().at(5).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.3, scene.GetFigures().at(5).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-0.675,
              scene.GetFigures().at(5).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-0.8,
              scene.GetFigures().at(5).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-0.6999999999,
              scene.GetFigures().at(5).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(0.825,
              scene.GetFigures().at(5).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-0.8,
              scene.GetFigures().at(5).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-0.6999999999,
              scene.GetFigures().at(5).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(0.825,
              scene.GetFigures().at(5).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-0.8,
              scene.GetFigures().at(5).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.3, scene.GetFigures().at(5).GetVertices().at(3).GetPosition().z,
              1.0e-7);
  //---------------------------------------------------------------------------
}

void RotateScene(s21::Scene &scene, const double &x, const double &y,
                 const double &z) {
  if (x != 0.0 || y != 0.0 || z != 0.0) {
    s21::TransformClient transform_client;
    s21::RotateStrategy rotate_strategy;
    transform_client.SetTransformStrategy(&rotate_strategy);
    scene.TransformFigures(&transform_client, x, y, z);
  }
}

TEST(Test3DViewer, RotateScene) {
  s21::Scene scene;
  std::size_t number_of_vertices;
  std::size_t number_of_edges;
  std::string path = "s21_tests/cub.txt";
  s21::FileReader file_reader;
  file_reader.ReadScene(scene, number_of_vertices, number_of_edges, path);
  ParallelProjectionScene(scene);

  RotateScene(scene, 45, 45, 45);
  //---------------------------------------------------------------------------
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(0).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(0.0, scene.GetFigures().at(0).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.4142135623730949,
              scene.GetFigures().at(0).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(0).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-1.4142135623730949,
              scene.GetFigures().at(0).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(0.0, scene.GetFigures().at(0).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(0).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-1.4142135623730949,
              scene.GetFigures().at(0).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(0.0, scene.GetFigures().at(0).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(0).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(0.0, scene.GetFigures().at(0).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.4142135623730949,
              scene.GetFigures().at(0).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(1.0, scene.GetFigures().at(1).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.4142135623730949,
              scene.GetFigures().at(1).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(0.0, scene.GetFigures().at(1).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(1).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(0.0, scene.GetFigures().at(1).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-1.4142135623730949,
              scene.GetFigures().at(1).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(1).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(0.0, scene.GetFigures().at(1).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-1.4142135623730949,
              scene.GetFigures().at(1).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(1).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.4142135623730949,
              scene.GetFigures().at(1).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(0.0, scene.GetFigures().at(1).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(1.0, scene.GetFigures().at(2).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(0.0, scene.GetFigures().at(2).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.4142135623730949,
              scene.GetFigures().at(2).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(2).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-1.4142135623730949,
              scene.GetFigures().at(2).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(0.0, scene.GetFigures().at(2).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(2).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(0.0, scene.GetFigures().at(2).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-1.4142135623730949,
              scene.GetFigures().at(2).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(2).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.4142135623730949,
              scene.GetFigures().at(2).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(0.0, scene.GetFigures().at(2).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(3).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.4142135623730949,
              scene.GetFigures().at(3).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(0.0, scene.GetFigures().at(3).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(3).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(0.0, scene.GetFigures().at(3).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.4142135623730949,
              scene.GetFigures().at(3).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(3).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(0.0, scene.GetFigures().at(3).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.4142135623730949,
              scene.GetFigures().at(3).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(3).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.4142135623730949,
              scene.GetFigures().at(3).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(0.0, scene.GetFigures().at(3).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(4).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(1.4142135623730949,
              scene.GetFigures().at(4).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(0.0, scene.GetFigures().at(4).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(4).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(0.0, scene.GetFigures().at(4).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-1.4142135623730949,
              scene.GetFigures().at(4).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(4).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-1.4142135623730949,
              scene.GetFigures().at(4).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(0.0, scene.GetFigures().at(4).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(4).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(0.0, scene.GetFigures().at(4).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.4142135623730949,
              scene.GetFigures().at(4).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(5).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-1.4142135623730949,
              scene.GetFigures().at(5).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(0.0, scene.GetFigures().at(5).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(5).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(0.0, scene.GetFigures().at(5).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-1.4142135623730949,
              scene.GetFigures().at(5).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(5).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(0.0, scene.GetFigures().at(5).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-1.4142135623730949,
              scene.GetFigures().at(5).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(5).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-1.4142135623730949,
              scene.GetFigures().at(5).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(0.0, scene.GetFigures().at(5).GetVertices().at(3).GetPosition().z,
              1.0e-7);
  //---------------------------------------------------------------------------
}

void ScaleScene(s21::Scene &scene, const double &x, const double &y,
                const double &z) {
  if (x != 0.0 || y != 0.0 || z != 0.0) {
    s21::TransformClient transform_client;
    s21::ScaleStrategy scale_strategy;
    transform_client.SetTransformStrategy(&scale_strategy);
    scene.TransformFigures(&transform_client, x, y, z);
  }
}

TEST(Test3DViewer, ScaleScene) {
  s21::Scene scene;
  std::size_t number_of_vertices;
  std::size_t number_of_edges;
  std::string path = "s21_tests/cub.txt";
  s21::FileReader file_reader;
  file_reader.ReadScene(scene, number_of_vertices, number_of_edges, path);
  ParallelProjectionScene(scene);

  ScaleScene(scene, 2.0, 2.0, 2.0);
  //---------------------------------------------------------------------------
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(0).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(0).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(0).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(0).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(0).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(0).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(0).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(0).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(0).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(0).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(0).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(0).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(2.0, scene.GetFigures().at(1).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(1).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(1).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(1).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(1).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(1).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(1).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(1).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(1).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(1).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(1).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(1).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(2.0, scene.GetFigures().at(2).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(2).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(2).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(2).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(2).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(2).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(2).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(2).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(2).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(2).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(2).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(2).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(3).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(3).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(3).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(3).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(3).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(3).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(3).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(3).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(3).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(3).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(3).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(3).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(4).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(4).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(4).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(4).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(4).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(4).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(4).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(4).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(4).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(4).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(4).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(4).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(5).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(5).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(5).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(5).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(5).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(5).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(5).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(5).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(5).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(5).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(5).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(5).GetVertices().at(3).GetPosition().z,
              1.0e-7);
  //---------------------------------------------------------------------------
}

void CentralProjectionScene(s21::Scene &scene) {
  s21::TransformClient transform_client;
  s21::CentralStrategy central_strategy;
  transform_client.SetTransformStrategy(&central_strategy);
  s21::SceneScope scene_scope = scene.GetSceneScope();
  scene.TransformFigures(&transform_client, scene_scope.min_z,
                         scene_scope.max_z, 0.0);
}

TEST(Test3DViewer, CentralScene) {
  s21::Scene scene;
  std::size_t number_of_vertices;
  std::size_t number_of_edges;
  std::string path = "s21_tests/cub.txt";
  s21::FileReader file_reader;
  file_reader.ReadScene(scene, number_of_vertices, number_of_edges, path);
  ParallelProjectionScene(scene);

  CentralProjectionScene(scene);
  //---------------------------------------------------------------------------
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(0).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(0).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(0).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(0).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(0).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(0).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(0).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(0).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(0).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(0).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(0).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(0).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(1).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(1).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(1).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(1).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(1).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(1).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(1).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(1).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(1).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(1).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(1).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(1).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(2.0, scene.GetFigures().at(2).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(2).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(2).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(2).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(2).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(2).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(2).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(2).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(2).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(2).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(2).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(2).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(2.0, scene.GetFigures().at(3).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(3).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(3).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(3).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(3).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(3).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(3).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(3).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(3).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(3).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(3).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(3).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(2.0, scene.GetFigures().at(4).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(4).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(4).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(4).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(4).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(4).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(4).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(4).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(4).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(4).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(4).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(4).GetVertices().at(3).GetPosition().z,
              1.0e-7);

  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(5).GetVertices().at(0).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(5).GetVertices().at(0).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(5).GetVertices().at(0).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(5).GetVertices().at(1).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(5).GetVertices().at(1).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(5).GetVertices().at(1).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(5).GetVertices().at(2).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(5).GetVertices().at(2).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(-1.0,
              scene.GetFigures().at(5).GetVertices().at(2).GetPosition().z,
              1.0e-7);
  EXPECT_NEAR(2.0, scene.GetFigures().at(5).GetVertices().at(3).GetPosition().x,
              1.0e-7);
  EXPECT_NEAR(-2.0,
              scene.GetFigures().at(5).GetVertices().at(3).GetPosition().y,
              1.0e-7);
  EXPECT_NEAR(1.0, scene.GetFigures().at(5).GetVertices().at(3).GetPosition().z,
              1.0e-7);
  //---------------------------------------------------------------------------
}
