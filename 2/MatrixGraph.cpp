//
// Created by Igor on 12.04.2022.
//

#include "MatrixGraph.h"

void MatrixGraph::AddEdge(int from, int to)
{
  int max_v = 1 + (from > to ? from : to);
  if (max_v > matrix.size())
  {
    matrix.resize(max_v);
    for (int i = 0; i < max_v; i++)
      matrix[i].resize(max_v);
  }
  matrix[from][to] = 1;
  if (to != from)
    matrix[to][from] = 1;
}
int  MatrixGraph::VerticesCount() const
{
  return 0;
}
void MatrixGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const
{

}
void MatrixGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const
{

}
