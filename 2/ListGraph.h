//
// Created by Igor on 12.04.2022.
//

#ifndef INC_2_LISTGRAPH_H
#define INC_2_LISTGRAPH_H

#include "IGraph.h"
#include <vector>
#include <iostream>

class ListGraph : public IGraph
{
  std::vector<std::vector<int>> list;
public:
  virtual ~ListGraph() {}
  ListGraph() : list() {};
  ListGraph(IGraph *_oth);
  virtual void AddEdge(int from, int to);
  virtual int VerticesCount() const;
  virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const;
  virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const;
  friend std::ostream& operator<<(std::ostream &os, const ListGraph& g)
  {
    for (int i = 0; i < g.list.size(); i++)
    {
      os << i << ": ";
      for (int j = 0; j < g.list[i].size(); j++)
        os << g.list[i][j] << " ";
      os << std::endl;
    }
    return os;
  }
};


#endif //INC_2_LISTGRAPH_H
