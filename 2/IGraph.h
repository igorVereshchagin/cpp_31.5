//
// Created by Igor on 12.04.2022.
//

#ifndef INC_2_IGRAPH_H
#define INC_2_IGRAPH_H
#include <vector>

class IGraph
{
public:
  virtual ~IGraph() {}
  IGraph() {};
  IGraph(IGraph *_oth) {};
  virtual void AddEdge(int from, int to) = 0; // Метод принимает вершины начала и конца ребра и добавляет ребро
  virtual int VerticesCount() const = 0; // Метод должен считать текущее количество вершин
  virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const = 0; // Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
  virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const = 0; // Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную
};

#endif //INC_2_IGRAPH_H
