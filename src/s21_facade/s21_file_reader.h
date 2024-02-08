#ifndef CPP4_3DVIEWER_V2_2_SRC_S21_FACADE_S21_FILE_READER_H_
#define CPP4_3DVIEWER_V2_2_SRC_S21_FACADE_S21_FILE_READER_H_

#include <fstream>
#include <sstream>
#include <string>

#include "s21_scene.h"

namespace s21 {
class FileReader {
 public:
  bool ReadScene(Scene &scene, std::size_t &number_of_vertices,
                 std::size_t &number_of_edges, const std::string &path);

  std::string GetObjectName(const std::string &path);

 private:
  void FillScene(Scene &scene,
                 std::vector<std::vector<long long>> &figure_vector,
                 const std::vector<std::vector<double>> &vertex_vector,
                 std::vector<std::size_t> &vertex_degree_vector);
  void ReadVertices(std::vector<std::vector<double>> &vertex_vector,
                    const std::string &path);
  void ReadFigures(std::vector<std::vector<long long>> &figure_vector,
                   const std::string &path);

  template <typename T>
  void ReadFile(std::vector<std::vector<T>> &vector, const std::string &path,
                const char chr);
  template <typename T>
  void FindNumbers(std::vector<T> &vertex_vector, std::string &str,
                   const char chr);
  std::string FindNumber(std::string &str, const char chr) noexcept;
  bool IsNumber(const std::string &str, const std::size_t pos,
                const char chr) noexcept;

  std::size_t count_ = 0UL;
  bool fail_ = false;
};

template <typename T>
void s21::FileReader::ReadFile(std::vector<std::vector<T>> &vector,
                               const std::string &path, const char chr) {
  std::ifstream in(path);
  if (in.is_open()) {
    std::string line;
    std::size_t count = 0UL;
    bool flag = true;
    bool flag_vf = true;
    while (!fail_ && std::getline(in, line) && flag) {
      count += 1UL;
      if (count > count_) {
        count_ += 1UL;
        if ((line.length() > 0) &&
            ((chr == 'f' && line[0] == 'v') ||
             (chr == 'v' && line[0] == 'f')) &&
            !flag_vf)
          flag = false;

        if ((line.length() > 1) && ((line[0] == chr) && (line[1] == ' '))) {
          flag_vf = false;
          std::vector<T> vertex_vector;
          FindNumbers(vertex_vector, line, chr);
          vector.push_back(vertex_vector);
          if (chr == 'v' && vertex_vector.size() != 3) fail_ = true;
        }
      }
    }
    if (count_ >= 1UL) count_ -= 1UL;
  }
  in.close();
}

template <typename T>
void s21::FileReader::FindNumbers(std::vector<T> &vertex_vector,
                                  std::string &str, const char chr) {
  std::size_t pos{};
  while ((pos = str.find(' ')) != std::string::npos) {
    str = str.substr(pos + 1);
    auto num_str = FindNumber(str, chr);
    if (num_str.length() > 0) {
      T number{};
      std::istringstream iss(num_str);
      iss >> number;
      if (chr == 'f' && number == 0) fail_ = true;
      vertex_vector.push_back(number);
    }
  }
}
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_2_SRC_S21_FACADE_S21_FILE_READER_H_
