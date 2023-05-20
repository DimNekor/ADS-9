// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

struct Token {
  int number;
  std::string word;
  Token* left;
  Token* right;
};

static int ToLeft(const Token* t1, const Token* t2) {
  if (t1->word < t2->word)
    return 1;
  else if (t1->word > t2->word)
    return -1;
  else if (t1->word == t2->word)
    return 0;
}

static void AddNode(Token* new_node, Token* root) {
  if (ToLeft(new_node, root) == 1) {
    if (root->left == nullptr)
      root->left = new_node;
    else
      AddNode(new_node, root->left);
    } else if (ToLeft(new_node, root) == -1) {
    if (root->right == nullptr)
      root->right = new_node;
    else
      AddNode(new_node, root->right);
    } else if (ToLeft(new_node, root) == 0)
    root->number += 1;
}

int Depth(Token* root) {
    if (root == nullptr) return 0;
    int LeftTDepth = Depth(root->left);
    int RightTDepth = Depth(root->right);
    if (LeftTDepth > RightTDepth)
    return LeftTDepth + 1;
    else
    return RightTDepth + 1;
}

struct Token* Search(struct Token* root, std::string key) {
    if (root == nullptr || root->word == key) return root;
    if (root->word < key) return Search(root->right, key);
    return Search(root->left, key);
}

template<typename T>
class BST {
 private:
  Token* ptree;

 public:
  BST();
  void AddToken(T);
  int depth();
  int search(std::string);
};

template <typename T>
inline BST<T>::BST() {
  ptree = nullptr;
}

template <typename T>
inline void BST<T>::AddToken(T string) {
  Token* new_node = new Token;
  if (ptree == nullptr) {
    ptree = new_node;
    ptree->word = string;
    ptree->number = 1;
    ptree->left = nullptr;
    ptree->right = nullptr;
  } else {
    new_node->word = string;
    new_node->left = nullptr;
    new_node->right = nullptr;
    new_node->number = 1;
    AddNode(new_node, ptree);
  }
}

template <typename T>
inline int BST<T>::depth() {
  return Depth(ptree);
}

template <typename T>
inline int BST<T>::search(std::string name) {
  return Search(ptree, name)->number;
}

#endif  // INCLUDE_BST_H_
