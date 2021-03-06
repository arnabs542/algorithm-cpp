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

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  void RunTest()
  {
  }

  int numIslands(vector<vector<char>>& grid) {
    int row_size = grid.size();
    if (row_size == 0)
    {
      return 0;
    }
    int col_size = grid[0].size();
    int counter = 0;
    for (int i = 0; i < row_size; ++i)
    {
      for (int j = 0; j < col_size; ++j)
      {
        if (grid[i][j] == '1')
        {
          ++counter;
          Marking(grid, i, j);
        }
      }
    }
    return counter;
  }

  void Marking(vector<vector<char>>& grid, int row_pos, int col_pos)
  {
    int row_size = grid.size();
    int col_size = grid[0].size();
    if (row_pos < 0
        || row_pos >= row_size
        || col_pos < 0
        || col_pos >= col_size
        || grid[row_pos][col_pos] != '1')
    {
      return;
    }

    grid[row_pos][col_pos] = '0';
    Marking(grid, row_pos + 1, col_pos);
    Marking(grid, row_pos - 1, col_pos);
    Marking(grid, row_pos, col_pos + 1);
    Marking(grid, row_pos, col_pos - 1);
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
