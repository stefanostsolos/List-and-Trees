#include <iostream>

using namespace std;

struct list_node {
  int data;
  list_node *next;
};

struct tree_node {
  int data;
  tree_node *left, *right;
};

int count_smaller_than(list_node *n, int x) {
  int i = 0;
  while (n != NULL){
    if (n->data < x) i++;
    n = n->next;
  }
  return i;
}

bool is_descending(list_node *n) {
  bool  flag = true;
  list_node *first = n;
  if (first == NULL) return flag;
  list_node *second = n->next;
  if (second == NULL) return flag;
  while (second != NULL) {
    if ((second->data) > (first->data)) flag = false;
    first = second;
    second = second->next;
  }
  return flag;
}

int count_internal(tree_node *t) {
  if (t == NULL) return 0;
  if ((t->right == NULL)&&(t->left == NULL)) return 0;
  return (1+(count_internal(t->left))+(count_internal(t->right)));  
}

int minimum(tree_node *t) {
  tree_node * leftt = t->left; //not empty
  tree_node * prev = t;
  while (leftt != NULL){
    prev = leftt;
    leftt = leftt->left;
  }
  return (prev->data);
}

bool sum_of_children(tree_node *t) {
  if (t == NULL) return true;
  if (((t->right) == NULL)&&((t->left) == NULL))return true;
  if ((t->right) == NULL) return (((t->data) == (t->left)->data)&&(sum_of_children(t->left))); 
  if ((t->left) == NULL) return (((t->data) == (t->right)->data)&&(sum_of_children(t->right)));
  return (((t->data) == (((t->right)->data) + ((t->left)->data)))&&(sum_of_children(t->left)&&(sum_of_children(t->right))));
}

list_node * list(int x, list_node *next) {
  list_node *n = new list_node;
  n->data = x;
  n->next = next;
  return n;
}

tree_node * tree(int x, tree_node *left, tree_node *right) {
  tree_node *n = new tree_node;
  n->data = x;
  n->left = left;
  n->right = right;
  return n;
}

int main() {
  list_node *l = list(42, list(17, list(69, list(37, nullptr))));
  cout << "l = 42 -> 17 -> 69 -> 37" << endl;
  cout << "count_smaller_than(l, 50) = " << count_smaller_than(l, 50) << '\n';
  cout << "is_descending(l) = " << (is_descending(l) ? "true" : "false") << '\n';

  tree_node *t = tree(42,
      tree(17,
        tree(22, nullptr, tree(6, nullptr, nullptr)),
        tree(4, nullptr, tree(78, nullptr, nullptr))),
      tree(37,
        nullptr,
        tree(89, nullptr, nullptr)));
  cout << "t =    42" << endl;
  cout << "      /  \\" << endl;
  cout << "    17    37" << endl;
  cout << "   /  \\    \\" << endl;
  cout << " 22    4    89" << endl;
  cout << "   \\    \\" << endl;
  cout << "    6    78" << endl;
  cout << "count_internal(t) = " << count_internal(t) << '\n';
  cout << "minimum(t) = " << minimum(t) << '\n';
  cout << "sum_of_children(t) = " << (sum_of_children(t) ? "true" : "false")
    << '\n';
}
