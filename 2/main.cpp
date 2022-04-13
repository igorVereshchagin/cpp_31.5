#include <iostream>
#include "MatrixGraph.h"


int main()
{
  MatrixGraph gr;
  gr.AddEdge(0, 1);
  gr.AddEdge(1, 2);
  std::cout << gr << std::endl;
  return 0;
}
