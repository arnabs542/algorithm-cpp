#ifndef DETECT_LOOP_AND_REMOVE_H
#define DETECT_LOOP_AND_REMOVE_H

#include <iostream>
#include <testsuit/TestBase.h>
#include <linkedlist/LinkedList.h>

using namespace std;

class DetectLoopAndRemove : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================DetectLoopAndRemove====================" << endl;
    ListNodeT *head = new ListNodeT({0, nullptr});
    head->next = new ListNodeT({50, nullptr});
    head->next->next = new ListNodeT({20, nullptr});
    head->next->next->next = new ListNodeT({15, nullptr});
    head->next->next->next->next = new ListNodeT({4, nullptr});
    head->next->next->next->next->next = new ListNodeT({10, nullptr});
    head->next->next->next->next->next->next = head->next->next->next;

    bool hasCycle = HasCycle(head);
    cout << "HasCycle: " << hasCycle << endl;
    cout << "=================DetectLoopAndRemove====================" << endl;
  }

  bool HasCycle(ListNodeT *head)
  {
    ListNodeT *fast = head->next;
    ListNodeT *slow = head->next;
    while (fast)
    {
      fast = fast->next;
      if (fast && fast->next)
      {
        slow = slow->next;
        fast = fast->next;
      }

      if (fast == slow)
      {
        return true;
      }
    }

    return false;
  }
};

#endif
