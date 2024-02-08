#include "s21_edge.h"

s21::Edge::Edge(const unsigned long &begin, const unsigned long &end)
    : begin_(begin), end_(end) {}

unsigned long &s21::Edge::GetBegin() noexcept { return begin_; }
unsigned long &s21::Edge::GetEnd() noexcept { return end_; }
