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
#include <list>

using namespace std;

struct LinkedListNode
{
  int data;
  struct LinkedListNode *next;
  LinkedListNode()
      : data(0)
      , next(nullptr)
  {}

  LinkedListNode(int value)
      : data(value)
      , next(nullptr)
  {}
};

class LinkedList
{
 private:
  LinkedListNode *head_;
  LinkedListNode *tail_;
 public:
  LinkedList()
      :head_(new LinkedListNode())
      ,tail_(head_)
  {}

  LinkedListNode * GetHeader()
  {
    return head_;
  }

  void Insert(int value)
  {
    LinkedListNode *node = new LinkedListNode(value);
    tail_->next = node;
    tail_ = node;
  }

  LinkedListNode * Insert(LinkedListNode *prev, LinkedListNode *node)
  {
    prev->next = node;
    return node;
  }

  void DeleteByPos(int pos)
  {
    LinkedListNode *prev = head_;
    LinkedListNode *cur = head_->next;
    int cur_pos = 0;
    while (cur)
    {
      if (cur_pos == pos)
      {
        prev->next = cur->next;
        if (cur == tail_)
        {
          tail_ = prev;
        }
        delete cur;
      }
      prev = cur;
      cur = cur->next;
      ++cur_pos;
    }
  }

  void DeleteByValue(int value)
  {
    LinkedListNode *prev = head_;
    LinkedListNode *cur = head_->next;
    while (cur)
    {
      if (cur->data == value)
      {
        prev->next = cur->next;
        if (cur == tail_)
        {
          tail_ = prev;
        }
        delete cur;
      }
      prev = cur;
      cur = cur->next;
    }
  }

  void Clear()
  {
    LinkedListNode *cur = head_->next;
    LinkedListNode *next = nullptr;
    while (cur)
    {
      next = cur->next;
      delete cur;
      cur = next;
    }

    head_->next = nullptr;
  }

  LinkedListNode * FindRKthNode(int kth)
  {
    LinkedListNode *slow = head_->next;
    LinkedListNode *fast = head_->next;
    while (kth && fast)
    {
      fast = fast->next;
      --kth;
    }

    if (kth != 0)
    {
      return nullptr;
    }

    while (fast)
    {
      fast = fast->next;
      slow = slow->next;
    }

    return slow;
  }

  LinkedListNode * FindMidNode()
  {
    LinkedListNode *slow = head_->next;
    LinkedListNode *fast = head_->next;
    while (fast && fast->next)
    {
      fast = fast->next->next;
      slow = slow->next;
    }

    return slow;
  }

  bool DetectCycle()
  {
    LinkedListNode *slow = head_->next;
    LinkedListNode *fast = head_->next;
    while (fast && fast->next)
    {
      fast = fast->next->next;
      slow = slow->next;
      if (slow == fast)
      {
        return true;
      }
    }

    return false;
  }

  int CycleSize()
  {
    LinkedListNode *slow = head_->next;
    LinkedListNode *fast = head_->next;
    while (fast && fast->next)
    {
      fast = fast->next->next;
      slow = slow->next;
      if (slow == fast)
      {
        break;
      }
    }

    int size = 1;
    fast = fast->next;
    while (fast != slow)
    {
      ++size;
      fast = fast->next;
    }

    return size;
  }

  bool IsPalindrome()
  {
    LinkedListNode *slow = head_->next;
    LinkedListNode *fast = head_->next;
    while (fast && fast->next)
    {
      fast = fast->next;
      if (fast->next)
      {
        slow = slow->next;
        fast = fast->next;
      }
    }

    LinkedListNode *first_head = head_->next;
    LinkedListNode *first_tail = slow;
    LinkedListNode *second_head = slow->next;
    slow->next = nullptr;

    //reverse second list
    LinkedListNode *prev = nullptr;
    LinkedListNode *cur = second_head;
    LinkedListNode *next = nullptr;
    while (cur)
    {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    second_head = prev;

    LinkedListNode *left = first_head;
    LinkedListNode *right = second_head;
    while (left && right)
    {
      if (left->data != right->data)
      {
        return false;
      }
      left = left->next;
      right = right->next;
    }

    return true;
  }

  void RemoveDupNodeInSorted()
  {
    LinkedListNode *cur = head_->next;
    LinkedListNode *next = nullptr;
    while (cur)
    {
      next = cur->next;
      if (next && cur->data == next->data)
      {
        cur->next = next->next;
        delete next;
        continue;
      }
      cur = next;
    }
  }

  void SwapNode(int lvalue, int rvalue)
  {
    LinkedListNode *first_prev = nullptr;
    LinkedListNode *first_cur = nullptr;
    LinkedListNode *second_prev = nullptr;
    LinkedListNode *second_cur = nullptr;

    LinkedListNode *prev = nullptr;
    LinkedListNode *cur = head_->next;
    while (cur)
    {
      if (cur->data == lvalue)
      {
        first_prev = prev;
        first_cur = cur;
      }
      else if (cur->data == rvalue)
      {
        second_prev = prev;
        second_cur = cur;
      }

      prev = cur;
      cur = cur->next;
    }

    LinkedListNode *tmp = nullptr;
    first_prev->next = second_cur;
    tmp = second_cur->next;
    second_cur->next = first_cur->next;

    second_prev->next = first_cur;
    first_cur->next = tmp;
  }

  void SwapPairs()
  {
    LinkedListNode *prev = head_;
    LinkedListNode *cur = head_->next;
    LinkedListNode *tmp = nullptr;
    while (cur && cur->next)
    {
      prev->next = cur->next;
      cur->next = cur->next->next;
      prev->next->next = cur;

      prev = prev->next->next;
      cur = cur->next;
    }
  }

  void ShowList()
  {
    if (!head_->next)
    {
      cout << "empty" << endl;
      return;
    }

    LinkedListNode *node = head_->next;
    while (node)
    {
      cout << node->data << ", ";
      node = node->next;
    }

    cout << endl;
  }
};


class Solution {
 public:
  void TestSwapPair()
  {
    LinkedList list;
    list.Insert(0);
    list.Insert(1);
    list.Insert(2);
    list.Insert(3);
    list.Insert(4);
    list.Insert(5);
    list.ShowList();
    list.SwapPairs();
    list.ShowList();
  }

  void TestSwapNode()
  {
    LinkedList list;
    list.Insert(0);
    list.Insert(1);
    list.Insert(2);
    list.Insert(3);
    list.Insert(4);
    list.Insert(5);
    list.ShowList();
    list.SwapNode(1, 4);
    list.ShowList();
  }

  void TestRemoveDup()
  {
    LinkedList list;
    list.Insert(11);
    list.Insert(11);
    list.Insert(11);
    list.Insert(13);
    list.Insert(13);
    list.Insert(20);
    list.RemoveDupNodeInSorted();
    list.ShowList();
  }

  void TestFind()
  {
    LinkedList list;
    LinkedListNode *node = nullptr;
    list.Insert(0);
    list.Insert(1);
    list.Insert(2);
    list.Insert(3);
    list.Insert(4);
    list.Insert(5);
    list.ShowList();
    node = list.FindRKthNode(6);
    cout << (node ? node->data : -1) << endl;
    node = list.FindMidNode();
    cout << (node ? node->data : -1) << endl;
    list.DeleteByPos(2);
    list.ShowList();
    list.DeleteByValue(4);
    list.ShowList();
    list.Clear();
    list.ShowList();
  }

  void TestCycle()
  {
    LinkedList list;
    LinkedListNode *node = nullptr;
    LinkedListNode *head = list.GetHeader();
    head->next = new LinkedListNode(0);
    head->next->next = new LinkedListNode(1);
    head->next->next->next = new LinkedListNode(2);
    head->next->next->next->next = new LinkedListNode(3);
    head->next->next->next->next->next = new LinkedListNode(4);
    head->next->next->next->next->next->next = head->next->next->next;
    cout << list.DetectCycle() << endl;
    cout << list.CycleSize() << endl;
  }

  void TestPalindrome()
  {
    LinkedList list;
    list.Insert(0);
    list.Insert(1);
    list.Insert(2);
    list.Insert(3);
    list.Insert(3);
    list.Insert(2);
    list.Insert(1);
    list.Insert(0);

    cout << list.IsPalindrome() << endl;
  }

  void RunTest()
  {
    // TestSwapNode();
    TestSwapPair();
  }

  template<class T>
  void Show(const vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", " << endl;
    }
    cout << endl;
  }

  template<class T>
  void Show(const vector<vector<T>> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      for (size_t j = 0; j < result[i].size(); ++j)
      {
        cout << result[i][j] << ", " << endl;
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
