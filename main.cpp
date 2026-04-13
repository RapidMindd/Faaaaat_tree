#include "BTree.hpp"
#include <iostream>

int main()
{
  BTree< int, 3 > root = {{20, 40, 60}, {}, nullptr};
  BTree< int, 3 > child_1 = {{5, 10, 15}, {}, &root};
  BTree< int, 3 > child_2 = {{25, 30, 35}, {}, &root};
  BTree< int, 3 > child_3 = {{45, 50, 55}, {}, &root};
  BTree< int, 3 > child_4 = {{65, 70, 75}, {}, &root};
  BTree< int, 3 > child_5 = {{37, 38, 39}, {}, &child_2};
  BTree< int, 3 > child_6 = {{67, 68, 69}, {}, &child_4};

  root.childs[0] = &child_1;
  root.childs[1] = &child_2;
  root.childs[2] = &child_3;
  root.childs[3] = &child_4;
  child_2.childs[3] = &child_5;
  child_4.childs[1] = &child_6;

  BTreeIt< int, 3 > it = {0, &child_1};
  std::cout << value(it);
  while (hasNext(it))
  {
    it = next(it);
    std::cout << " " << value(it);
  }
  std::cout << "\n";

  std::cout << value(it);
  while (hasPrev(it))
  {
    it = prev(it);
    std::cout << " " << value(it);
  }
  std::cout << "\n";
}
