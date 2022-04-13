//
// Created by Igor on 12.04.2022.
//

#include "ListGraph.h"

void ListGraph::AddEdge(int from, int to)
{
  int max_v = 1 + (from > to ? from : to);
  if (max_v > list.size())
    list.resize(max_v);
  if ((list[from]).find(to))
  {

  }
  if (to != from)
    matrix[to][from] = 1;
}

int ListGraph::VerticesCount() const
{
  return 0;
}
void ListGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const
{

}
void ListGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const
{

}
