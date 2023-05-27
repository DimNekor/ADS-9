// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <string>
#include <cctype>

#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  std::ifstream file(filename);
  BST<std::string> tree;
  std::string tempStr = "";
  char ch;
  while (!file.eof()) {
    ch = file.get();
    if (!isalpha(ch)) {
      tree.AddToken(tempStr);
      tempStr = "";
    } else {
      tempStr += tolower(ch);
    }
  }
  file.close();
  return tree;
}
