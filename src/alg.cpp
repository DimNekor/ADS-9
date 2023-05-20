// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"
#include <string>
#include <cctype>

BST<std::string> makeTree(const char* filename) {
  std::ifstream file(filename);
  BST<std::string> tree;
  int count = 0;
  std::string tempStr = "";
  bool flag = true;
  bool flag2 = true;
  while (!file.eof()) {
    int ch = file.get();
    flag2 = true;
    if (flag) {
      ch = tolower(ch);
      flag = false;
    }
    if (ch == ' ' || ch == '\n' || ch == -1) {
      flag = true;
      tree.AddToken(tempStr);
    }
    if (ch == '.' || ch == ',' || ch == ':' || ch == ';' || ch == '(' ||
        ch == ')' || ch == '!' || ch == '?' || ch == 'EOF')
      flag2 = false;
    if (flag2) tempStr += ch;
    if (flag) tempStr = "";
  }
  file.close();
  return tree;
}
