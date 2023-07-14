#pragma once

#include <iostream>

struct Document {
  int id = 0;
  double relevance = 0.0;
  int rating = 0;
  Document() = default;

  Document(int id_, double relevance_, int rating_)
      : id(id_), relevance(relevance_), rating(rating_) {}
};

enum class DocumentStatus { ACTUAL, IRRELEVANT, BANNED, REMOVED };
