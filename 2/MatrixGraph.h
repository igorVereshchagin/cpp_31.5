//
// Created by Igor on 12.04.2022.
//

#ifndef INC_2_MATRIXGRAPH_H
#define INC_2_MATRIXGRAPH_H

#include "IGraph.h"
#include <vector>
#include <iostream>

class MatrixGraph : public IGraph
{
  std::vector<std::vector<int>> matrix;
public:
  virtual ~MatrixGraph() {}
  MatrixGraph() : matrix() {}
  MatrixGraph(IGraph *_oth);
  virtual void AddEdge(int from, int to);
  virtual int VerticesCount() const;
  virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const;
  virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const;
  friend std::ostream& operator<<(std::ostream &os, const MatrixGraph& g)
  {
    for (int i = 0; i < g.matrix.size(); i++)
    {
      for (int j = 0; j < g.matrix.size(); j++)
        os << g.matrix[i][j] << " ";
      os << std::endl;
    }
    return os;
  }
};


#endif //INC_2_MATRIXGRAPH_H
