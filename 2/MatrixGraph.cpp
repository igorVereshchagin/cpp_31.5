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
}

MatrixGraph::MatrixGraph(IGraph *_oth) : matrix()
{
  for (int v = 0; v < _oth->VerticesCount(); v++)
  {
    std::vector<int> vertices;
    _oth->GetNextVertices(v, vertices);
    for (int i = 0; i < vertices.size(); i++)
      this->AddEdge(v, vertices[i]);
  }
}
int  MatrixGraph::VerticesCount() const
{
  return matrix.size();
}
void MatrixGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const
{
  vertices.clear();
  if (vertex >= matrix.size())
    return;
  for (int i = 0; i < matrix[vertex].size(); i++)
    if (matrix[vertex][i] != 0)
      vertices.push_back(i);
}

void MatrixGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const
{
  vertices.clear();
  if (vertex >= matrix.size())
    return;
  for (int i = 0; i < matrix.size(); i++)
    if (matrix[i][vertex] != 0)
      vertices.push_back(i);
}
