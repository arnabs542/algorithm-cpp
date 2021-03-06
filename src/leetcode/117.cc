#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <cassert>
#include <stack>
#include <limits>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <iterator>
#include <set>
#include <cmath>
#include <bitset>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
 public:

  void RunTest()
  {
  }

  Node* connect(Node* root) {
    if (!root)
    {
      return root;
    }
    Aux(root);

    return root;
  }

  void Aux(Node* node)
  {
    deque<Node *> dq;
    dq.push_back(node);
    while (!dq.empty())
    {
      Node *curNode = nullptr;
      Node *prevNode = nullptr;
      int dqSize = dq.size();
      while (dqSize--)
      {
        curNode = dq.front();
        dq.pop_front();
        if (curNode->left)
        {
          dq.push_back(curNode->left);
        }

        if (curNode->right)
        {
          dq.push_back(curNode->right);
        }

        if (prevNode)
        {
          prevNode->next = curNode;
        }
        prevNode = curNode;
      }
    }
  }

  template<class T>
  void Show(vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", ";
    }
    cout << endl;
  }

  template<class T>
  void Show(vector<vector<T>> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      for (size_t j = 0; j < result[i].size(); ++j)
      {
        cout << result[i][j] << ", ";
      }
      cout << endl;
    }
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
