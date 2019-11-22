#ifndef MERGE_TWO_LINKED_LIST_ALTERNATE_H
#define MERGE_TWO_LINKED_LIST_ALTERNATE_H

#include <iostream>
#include <testsuit/TestBase.h>
#include <linkedlist/LinkedList.h>

using namespace std;

class MergeTwoLinkedListAlternate : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================MergeTwoLinkedListAlternate====================" << endl;
    LinkedList linkedList;
    linkedList.PushBack(3);
    linkedList.PushBack(2);
    linkedList.PushBack(1);
    linkedList.Show();
    LinkedList linkedList1;
    linkedList1.PushBack(8);
    linkedList1.PushBack(7);
    linkedList1.PushBack(6);
    linkedList1.PushBack(5);
    linkedList1.PushBack(4);
    linkedList1.Show();
    linkedList.MergeLinkedListAlternate(linkedList1.GetHeader()->next);
    linkedList.Show();

    cout << "=================MergeTwoLinkedListAlternate====================" << endl;
  }
};

#endif
