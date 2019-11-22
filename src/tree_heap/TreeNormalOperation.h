#ifndef TREE_NORMAL_OPERATION_H_
#define TREE_NORMAL_OPERATION_H_

#include <iostream>
#include <queue>

#include <testsuit/TestBase.h>
#include <tree_heap/BinaryTree.h>

using namespace std;

class TreeNormalOperation: public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================TreeNormalOperation====================" << endl;
    TreeNodeT *root = NewNode(10);
    root->left = NewNode(2);
    root->left->left = NewNode(20);
    root->left->right = NewNode(1);
    root->right = NewNode(10);
    root->right->right = NewNode(-25);
    root->right->right->left = NewNode(3);
    root->right->right->right = NewNode(4);

    cout << "PreOrder:" << endl;
    ShowPreOrder(root);
    cout << endl;

    cout << "InOrder:" << endl;
    ShowInOrder(root);
    cout << endl;

    cout << "PostOrder:" << endl;
    ShowPostOrder(root);
    cout << endl;

    cout << "LevelOrder:" << endl;
    ShowLevelOrder(root, true);
    cout << endl;
    cout << "=================TreeNormalOperation====================" << endl;
  }

  void ShowPreOrder(TreeNodeT *node)
  {
    if (!node)
    {
      return;
    }
    cout << node->value << ", ";
    ShowPreOrder(node->left);
    ShowPreOrder(node->right);
  }

  void ShowInOrder(TreeNodeT *node)
  {
    if (!node)
    {
      return;
    }
    ShowInOrder(node->left);
    cout << node->value << ", ";
    ShowInOrder(node->right);
  }

  void ShowPostOrder(TreeNodeT *node)
  {
    if (!node)
    {
      return;
    }
    ShowPostOrder(node->left);
    ShowPostOrder(node->right);
    cout << node->value << ", ";
  }

  void ShowLevelOrder(TreeNodeT *node, bool pretty = false)
  {
    queue<TreeNodeT *> q;
    q.push(node);
    while(!q.empty())
    {
      int size = q.size();
      while (size != 0)
      {
        node = q.front();
        q.pop();
        cout << node->value << ", ";
        if (node->left)
        {
          q.push(node->left);
        }

        if (node->right)
        {
          q.push(node->right);
        }
        --size;
      }

      if (pretty)
      {
        cout << endl;
      }
    }

    cout << endl;
  }

  TreeNodeT * NewNode(int value)
  {
    return new TreeNodeT({value, nullptr, nullptr});
  }
};

#endif

