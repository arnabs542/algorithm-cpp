#ifndef LINKED_LIST_SORT_BY_MERGE_SORT_H
#define LINKED_LIST_SORT_BY_MERGE_SORT_H

#include <iostream>
#include <testsuit/TestBase.h>
#include <linkedlist/LinkedList.h>

using namespace std;

class LinkedListSortByMergeSort : public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================LinkedListSortByMergeSort====================" << endl;
    LinkedList linkedList;
    linkedList.PushBack(15);
    linkedList.PushBack(10);
    linkedList.PushBack(5);
    linkedList.PushBack(20);
    linkedList.PushBack(3);
    linkedList.PushBack(2);
    linkedList.PushBack(1);
    cout << "before sort: ";
    linkedList.Show();
    // ListNodeT *middleNode = nullptr;
    // linkedList.FindMiddle(&middleNode);
    // cout << "middleNode: " << middleNode->value << endl;
    linkedList.MergeSort();
    cout << "after sort: ";
    linkedList.Show();

    cout << "=================LinkedListSortByMergeSort====================" << endl;
  }
};

#endif
