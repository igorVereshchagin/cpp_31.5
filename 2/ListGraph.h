//
// Created by Igor on 12.04.2022.
//

#ifndef INC_2_LISTGRAPH_H
#define INC_2_LISTGRAPH_H

#include "IGraph.h"
#include <vector>

class ListGraph : public IGraph
{
  std::vector<std::vector<int>> list;
public:
  virtual ~ListGraph() {}
  ListGraph() : list() {};
//  ListGraph(ListGraph *_oth) {};
  virtual void AddEdge(int from, int to);
  virtual int VerticesCount() const;
  virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const;
  virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const;
};


#endif //INC_2_LISTGRAPH_H
