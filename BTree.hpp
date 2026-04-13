#ifndef BTREE_HPP
#define BTREE_HPP

#include <cstddef>

template< class T, size_t K >
struct BTree
{
  T val[K];
  BTree< T, K >* childs[K + 1];
  BTree< T, K >* parent;
};

template< class T, size_t K >
struct BTreeIt
{
  size_t s;
  BTree< T, K >* current;
};

template< class T, size_t K >
T value(BTreeIt< T, K > it)
{
  return it.current->val[it.s];
}

template< class T, size_t K >
BTreeIt< T, K > min(BTree< T, K >* root)
{
  while (root->childs[0])
  {
    root = root->childs[0];
  }
  return {0, root};
}

template< class T, size_t K >
BTreeIt< T, K > next(BTreeIt< T, K > it)
{
  BTree< T, K >* child = it.current->childs[it.s + 1];
  if (child) return min< T, K >(child);
  if (it.s < K - 1) return {it.s + 1, it.current};
  BTree< T, K >* cur = it.current;
  while (cur->parent)
  {
    BTree< T, K >* parent = cur->parent;
    for (size_t i = 0; i < K; ++i)
    {
      if (parent->childs[i] == cur) return {i, parent};
    }
    cur = cur->parent;
  }
  return {0, nullptr};
}

#endif
