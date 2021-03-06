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
#include <queue>
#include <functional>

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

class Node {
 public:
  int val;
  vector<Node*> neighbors;

  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }

  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }

  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

// class Node {
// public:
//     int val;
//     Node* left;
//     Node* right;

//     Node() {}

//     Node(int _val) {
//         val = _val;
//         left = NULL;
//         right = NULL;
//     }

//     Node(int _val, Node* _left, Node* _right) {
//         val = _val;
//         left = _left;
//         right = _right;
//     }
// };


class Solution {
 public:
  void RunTest()
  {

  }

  /*
    Input: 1->2->3->4->5->NULL, m = 2, n = 4
    Output: 1->4->3->2->5->NULL

    dummy->1->2->3->4->5

    [2, 4]

    dummy->1->4->3->2->5
   */

  ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode dummy(0);
    dummy.next = head;

    ListNode *prev = &dummy;
    ListNode *cur = head;
    ListNode *next = nullptr;

    ListNode *left_tail = nullptr;
    ListNode *middle_tail = nullptr;
    ListNode *right_head = nullptr;

    int count = 0;
    while (cur)
    {
      ++count;

      if (count == m)
      {
        left_tail = prev;
        middle_tail = cur;
      }

      if (count > m && count < n)
      {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        continue;
      }

      if (count == n)
      {
        right_head = cur->next;
        cur->next = prev;

        left_tail->next = cur;
        middle_tail->next = right_head;
        break;
      }

      prev = cur;
      cur = cur->next;
    }

    return dummy.next;
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
  delete solution;
  return 0;
}
