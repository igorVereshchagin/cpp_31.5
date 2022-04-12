//
// Created by Igor on 12.04.2022.
//

#ifndef INC_2_LISTGRAPH_H
#define INC_2_LISTGRAPH_H

#include "IGraph.h"

class ListGraph : public IGraph
{
public:
  virtual ~ListGraph() {}
  ListGraph() {};
  ListGraph(ListGraph *_oth) {};
  virtual void AddEdge(int from, int to) = 0;
  virtual int VerticesCount() const = 0;
  virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const = 0;
  virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const = 0;
};


#endif //INC_2_LISTGRAPH_H
