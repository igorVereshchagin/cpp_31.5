//
// Created by Igor on 12.04.2022.
//

#include "ListGraph.h"
#include <algorithm>

void ListGraph::AddEdge(int from, int to)
{
  int max_v = 1 + (from > to ? from : to);
  if (max_v > list.size())
    list.resize(max_v);
  if (std::find(list[from].begin(), list[from].end(), to) == list[from].end())
    list[from].push_back(to);
}

ListGraph::ListGraph(IGraph *_oth) : list()
{
  for (int v = 0; v < _oth->VerticesCount(); v++)
  {
    std::vector<int> vertices;
    _oth->GetNextVertices(v, vertices);
    for (int i = 0; i < vertices.size(); i++)
      this->AddEdge(v, vertices[i]);
  }
}

int ListGraph::VerticesCount() const
{
  return list.size();
}
void ListGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const
{
  vertices.clear();
  if (vertex >= list.size())
    return;
  for (int i = 0; i < list[vertex].size(); i++)
      vertices.push_back(list[vertex][i]);
}
void ListGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const
{
  vertices.clear();
  if (vertex >= list.size())
    return;
  for (int i = 0; i < list.size(); i++)
    if (std::find(list[i].begin(), list[i].end(), vertex) != list[i].end())
      vertices.push_back(i);
}
