#include "s21_file_reader.h"

bool s21::FileReader::ReadScene(Scene &scene, std::size_t &number_of_vertices,
                                std::size_t &number_of_edges,
                                const std::string &path) {
  number_of_vertices = 0UL;
  number_of_edges = 0UL;
  fail_ = false;
  count_ = 0UL;
  std::vector<std::vector<double>> vertex_vector;
  std::vector<std::vector<long long>> figure_vector;
  do {
    figure_vector.clear();
    number_of_vertices = vertex_vector.size();
    if (!fail_) ReadVertices(vertex_vector, path);
    if ((!fail_) && (number_of_vertices < vertex_vector.size())) {
      ReadFigures(figure_vector, path);

      if (!fail_) {
        std::vector<std::size_t> vertex_degree_vector(vertex_vector.size());
        for (auto i = 0UL; i < vertex_degree_vector.size(); i++)
          vertex_degree_vector[i] = 0UL;

        FillScene(scene, figure_vector, vertex_vector, vertex_degree_vector);

        for (auto vertex_degree : vertex_degree_vector)
          number_of_edges += vertex_degree;
      }
    }
  } while (!fail_ && figure_vector.size() > 0);

  number_of_edges /= 2;

  return fail_;
}

std::string s21::FileReader::GetObjectName(const std::string &path) {
  std::ifstream in(path);
  std::string line;
  std::size_t pos{};
  if (in.is_open()) {
    while (std::getline(in, line) &&
           (pos = line.find("mtllib")) == std::string::npos &&
           (pos = line.find("object")) == std::string::npos &&
           (pos = line.find("o ")) == std::string::npos) {
    }
  }
  in.close();

  if (pos != std::string::npos) {
    line = line.substr(pos);
    if ((pos = line.find(" .\\")) != std::string::npos ||
        (pos = line.find(" ./")) != std::string::npos)
      pos += 3UL;
    else
      pos = line.find(" ") + 1UL;
    line = line.substr(pos);
    if ((pos = line.rfind(".")) != std::string::npos)
      line = line.substr(0, pos);
  } else {
    line = path.substr(path.rfind("/") + 1);
    line = line.substr(0, line.length() - 4);
  }
  line += "     Название файла: " + path;

  return line;
}

void s21::FileReader::FillScene(
    Scene &scene, std::vector<std::vector<long long>> &figure_vector,
    const std::vector<std::vector<double>> &vertex_vector,
    std::vector<std::size_t> &vertex_degree_vector) {
  auto vertices_size = vertex_vector.size();
  for (auto i = 0UL, i_size = figure_vector.size(); i < i_size; i++) {
    Figure figure;
    auto j = 0UL;
    auto j_size = figure_vector[i].size();
    for (; j < j_size; j++) {
      auto k = figure_vector[i][j];
      if (k > 0)
        k -= 1;
      else if (k < 0)
        k += vertices_size;
      vertex_degree_vector[k] += 1UL;
      double x = vertex_vector[k][0];
      double y = vertex_vector[k][1];
      double z = vertex_vector[k][2];
      figure.PushBack(Vertex(x, y, z));
      if (j > 0) {
        figure.PushBack(Edge((j - 1UL), j));
      }
    }
    if (j_size > 0) {
      figure.PushBack(Edge((j - 1UL), 0));
      scene.PushBack(figure);
    }
  }
}

void s21::FileReader::ReadVertices(
    std::vector<std::vector<double>> &vertex_vector, const std::string &path) {
  ReadFile<double>(vertex_vector, path, 'v');
}

void s21::FileReader::ReadFigures(
    std::vector<std::vector<long long>> &figure_vector,
    const std::string &path) {
  ReadFile<long long>(figure_vector, path, 'f');
}

std::string s21::FileReader::FindNumber(std::string &str,
                                        const char chr) noexcept {
  std::size_t pos = 0UL;
  while ((pos < str.length()) && !IsNumber(str, pos, chr)) {
    pos += 1UL;
  }
  str = str.substr(pos);

  std::string num_str = str;
  pos = 0UL;
  while ((pos < num_str.length()) && IsNumber(num_str, pos, chr)) {
    pos += 1UL;
  }
  num_str = num_str.substr(0, pos);

  return num_str;
}

bool s21::FileReader::IsNumber(const std::string &str, const std::size_t pos,
                               const char chr) noexcept {
  bool is_number{};
  if (((str[pos] >= '0') && (str[pos] <= '9')) || (str[pos] == '-')) {
    is_number = true;
  } else if ((chr == 'v') && ((str[pos] == '.') || (str[pos] == ','))) {
    is_number = true;
  } else {
    is_number = false;
  }

  return is_number;
}
