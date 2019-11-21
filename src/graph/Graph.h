#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>

#include <testsuit/TestBase.h>

using namespace std;

class GraphMatrix
{
 public:
  GraphMatrix(int nodeSize) :
      graphData_(vector<vector<int>>(nodeSize, vector<int>(nodeSize, 0)))
  {}

  void AddEdge(int from, int to)
  {
  }

 private:
  vector<vector<int>> graphData_;
};

class GraphList
{
 public:
  GraphList(int nodeSize) :
      graphData_(vector<list<int>>(nodeSize, list<int>()))
  {}

  void AddEdge(int from, int to)
  {
    graphData_[from].push_back(to);
  }

  void ShowGraph()
  {
    int index = 0;
    for (vector<list<int>>::iterator itVec = graphData_.begin(); itVec != graphData_.end(); ++itVec)
    {
      cout << index++ << " -> ";
      for (list<int>::iterator itList = itVec->begin(); itList != itVec->end(); ++itList)
      {
        cout << *itList << " -> ";
      }

      cout << endl;
    }
  }

  void BFS(int from)
  {
  }

  void DFS(int from)
  {
    set<int> bookmark;
    DFSAux(from, bookmark);
    cout << endl;
  }

  bool HasCycle()
  {
    return false;
  }

 private:
  void DFSAux(int from, set<int> &bookmark)
  {
    cout << from << " -> ";
    bookmark.insert(from);
    list<int> &ship = graphData_[from];
    for (auto it = ship.begin(); it != ship.end(); ++it)
    {
      if (bookmark.find(*it) == bookmark.end())
      {
        DFSAux(*it, bookmark);
      }
    }
  }

 private:
  vector<list<int>> graphData_;
};


class GraphTest: public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================GraphTest====================" << endl;
    GraphList graphList(4);
    graphList.AddEdge(0, 1);
    graphList.AddEdge(0, 2);
    graphList.AddEdge(1, 2);
    graphList.AddEdge(2, 0);
    graphList.AddEdge(2, 3);
    graphList.AddEdge(3, 3);
    cout << "----ShowGraph----" << endl;
    graphList.ShowGraph();
    cout << "----BFS----" << endl;
    graphList.BFS(2);
    cout << "----DFS----" << endl;
    graphList.DFS(3);
    cout << "=================GraphTest====================" << endl;
  }
};

#endif
