#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <iostream>
#include <testsuit/TestBase.h>

using namespace std;

typedef struct ListNodeS{
  int value;
  ListNodeS *next;
} ListNodeT;

class LinkedList
{
 public:
  LinkedList() :
      head_(new ListNodeT({0, nullptr})),
      tail_(head_),
      size_(0)
  {}

  ListNodeT *PushBack(int value)
  {
    tail_->next = new ListNodeT({value, nullptr});
    tail_ = tail_->next;
    ++size_;
    return tail_;
  }

  ListNodeT *InsertAfter(ListNodeT *prevNode, int value)
  {
    ListNodeT *newNode = new ListNodeT({value, nullptr});
    newNode->next = prevNode->next;
    prevNode->next = newNode;

    return newNode;
  }

  void MergeSortedLinkedList(ListNodeT *sortedListHead)
  {
    ListNodeT *listNode1 = head_->next;
    ListNodeT *listNode2 = sortedListHead->next;
    ListNodeT dummy = {0, nullptr};
    ListNodeT *tail = &dummy;
    dummy.next = nullptr;
    while (true)
    {
      if (!listNode1)
      {
        tail->next = listNode2;
        break;
      }

      if (!listNode2)
      {
        tail->next = listNode1;
        break;
      }

      if (listNode1->value <= listNode2->value)
      {
        tail->next = listNode1;
        tail = tail->next;
        listNode1 = listNode1->next;
      }
      else
      {
        tail->next = listNode2;
        tail = tail->next;
        listNode2 = listNode2->next;
      }
    }
    head_->next = dummy.next;
  }

  ListNodeT *GetHeader()
  {
    return head_;
  }

  void Reverse()
  {
    ListNodeT *curNode = head_->next;
    ListNodeT *prevNode = nullptr;
    ListNodeT *nextNode = nullptr;
    while (curNode)
    {
      nextNode = curNode->next;
      curNode->next = prevNode;
      prevNode = curNode;
      curNode = nextNode;
    }

    head_->next = prevNode;
  }

  void MergeSort()
  {
    MergeSortAux(&(head_->next));
  }

  void SplitList(ListNodeT *leftFirst, ListNodeT **rightFirst)
  {
    ListNodeT *slow = leftFirst;
    ListNodeT *fast = leftFirst;
    while (fast)
    {
      fast = fast->next;
      if (fast and fast->next)
      {
        fast = fast->next;
        slow = slow->next;
      }
    }

    *rightFirst = slow->next;
    slow->next = nullptr;
  }

  void Show()
  {
    ListNodeT *curNode = head_->next;
    Show(curNode);
  }

  void MergeLinkedListAlternate(ListNodeT *linkedHead)
  {
    ListNodeT *curNode = head_->next;
    ListNodeT *curNodeNext = nullptr;
    ListNodeT *linkedNodeNext = nullptr;
    while (curNode && linkedHead)
    {
      curNodeNext = curNode->next;
      linkedNodeNext = linkedHead->next;

      curNode->next = linkedHead;
      linkedHead->next = curNodeNext;

      curNode = curNodeNext;
      linkedHead = linkedNodeNext;
    }
  }

 private:
  void MergeSortAux(ListNodeT **nodeaddr)
  {
    ListNodeT *node = *nodeaddr;
    if (!node->next)
    {
      return;
    }

    ListNodeT *middleNode;
    SplitList(node, &middleNode);
    MergeSortAux(&node);
    MergeSortAux(&middleNode);

    ListNodeT dummy = {0, nullptr};
    ListNodeT *currentNode = &dummy;
    while (node || middleNode)
    {
      if (!node)
      {
        currentNode->next = middleNode;
        currentNode = currentNode->next;
        middleNode = middleNode->next;
        continue;
      }

      if (!middleNode)
      {
        currentNode->next = node;
        currentNode = currentNode->next;
        node = node->next;
        continue;
      }

      if (node->value > middleNode->value)
      {
        currentNode->next = middleNode;
        currentNode = currentNode->next;
        middleNode = middleNode->next;
      }
      else
      {
        currentNode->next = node;
        currentNode = currentNode->next;
        node = node->next;
      }
    }

    *nodeaddr = dummy.next;
  }

  void Show(ListNodeT *curNode)
  {
    while (curNode)
    {
      cout << curNode->value << ", ";
      curNode = curNode->next;
    }

    cout << endl;
  }


 private:
  ListNodeT *head_;
  ListNodeT *tail_;
  int size_;
};


class LinkedListTest: public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================LinkedListTest====================" << endl;
    cout << "=================LinkedListTest====================" << endl;
  }
};

#endif
