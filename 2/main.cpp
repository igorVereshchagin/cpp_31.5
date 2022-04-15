#include <iostream>
#include "MatrixGraph.h"
#include "ListGraph.h"

int main()
{
  MatrixGraph mgr1;
  mgr1.AddEdge(0, 1);
  mgr1.AddEdge(1, 0);
  mgr1.AddEdge(1, 2);
  mgr1.AddEdge(1, 3);
  mgr1.AddEdge(2, 0);
  mgr1.AddEdge(2, 4);
  mgr1.AddEdge(3, 0);
  mgr1.AddEdge(3, 4);
  mgr1.AddEdge(4, 0);
  mgr1.AddEdge(4, 3);

  ListGraph lgr1;
  lgr1.AddEdge(0, 1);
  lgr1.AddEdge(1, 0);
  lgr1.AddEdge(1, 2);
  lgr1.AddEdge(1, 3);
  lgr1.AddEdge(2, 0);
  lgr1.AddEdge(2, 4);
  lgr1.AddEdge(3, 0);
  lgr1.AddEdge(3, 4);
  lgr1.AddEdge(4, 0);
  lgr1.AddEdge(4, 3);

  MatrixGraph mgr2(&lgr1);
  ListGraph   lgr2(&mgr1);

  std::cout << mgr1 << std::endl << lgr1 << std::endl;
  std::cout << "=================" << std::endl;
  std::cout << mgr2 << std::endl << lgr2 << std::endl;
  return 0;
}
