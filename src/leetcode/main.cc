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

  ListNode* sortList(ListNode* head) {
    if (!head || !head->next)
    {
      return head;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast)
    {
      fast = fast->next;
      if (fast && fast->next)
      {
        fast = fast->next;
        slow = slow->next;
      }
    }

    ListNode *head1 = head;
    ListNode *head2 = slow->next;
    slow->next = nullptr;

    ListNode *new_head1 = sortList(head1);
    ListNode *new_head2 = sortList(head2);

    ListNode dummy(0);
    ListNode *cur = &dummy;
    while (new_head1 || new_head2)
    {
      if (!new_head1)
      {
        cur->next = new_head2;
        cur = cur->next;
        new_head2 = new_head2->next;
        continue;
      }

      if (!new_head2)
      {
        cur->next = new_head1;
        cur = cur->next;
        new_head1 = new_head1->next;
        continue;
      }

      if (new_head1->val < new_head2->val)
      {
        cur->next = new_head1;
        cur = cur->next;
        new_head1 = new_head1->next;
      }
      else
      {
        cur->next = new_head2;
        cur = cur->next;
        new_head2 = new_head2->next;
      }
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
