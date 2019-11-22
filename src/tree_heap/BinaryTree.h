#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <iostream>
#include <queue>
#include <algorithm>

#include <testsuit/TestBase.h>

using namespace std;

typedef struct TreeNodeS{
  int value;
  TreeNodeS *left;
  TreeNodeS *right;
} TreeNodeT;

class BinaryTree
{
 public:
  BinaryTree() :
      root_(nullptr),
      size_(0)
  {}

  TreeNodeT * InitRoot(int value)
  {
    root_ = new TreeNodeT({value, nullptr, nullptr});
    return root_;
  }

  TreeNodeT * InsertLeft(TreeNodeT *fatherNode, int value)
  {
    fatherNode->left = new TreeNodeT({value, nullptr, nullptr});
    return fatherNode->left;
  }

  TreeNodeT * InsertRight(TreeNodeT *fatherNode, int value)
  {
    fatherNode->right = new TreeNodeT({value, nullptr, nullptr});
    return fatherNode->right;
  }

  void ShowPreOrder()
  {
    ShowPreOrder(root_);
    cout << endl;
  }

  void ShowInOrder()
  {
    ShowInOrder(root_);
    cout << endl;
  }

  void ShowPostOrder()
  {
    ShowPostOrder(root_);
    cout << endl;
  }

  void ShowLevelOrder(bool pretty = false)
  {
    ShowLevelOrder(root_, pretty);
    cout << endl;
  }

  void ShowLevelOrderRecursive(bool pretty = false)
  {
    int treeHeight = Height();
    for (int i = 0; i < treeHeight; ++i)
    {
      ShowLevelOrderRecursive(root_, i);
      if (pretty)
      {
        cout << endl;
      }
    }

    cout << endl;
  }

  int Height()
  {
    if (root_ == nullptr)
    {
      return -1;
    }

    return Height(root_);
  }

  int MinimumDepth()
  {
    return MinimumDepth(root_);
  }

  int MinimumDepthRecursive()
  {
    return MinimumDepthRecursive(root_);
  }

  int MaxPathSum()
  {
    return MaxPathSumAux(root_);
  }

 private:
  int MaxPathSumAux(TreeNodeT *node)
  {
    if (node == nullptr)
    {
      return 0;
    }

    int leftSum = MaxPathSumAux(node->left) + node->value;
    int rightSum = MaxPathSumAux(node->right) + node->value;
    int curValue = node->value;
    int allSum = leftSum + rightSum - curValue;

    return std::max({leftSum, rightSum, curValue, allSum});
  }

  int MinimumDepth(TreeNodeT *node)
  {
    queue<TreeNodeT *> buffer;
    buffer.push(node);
    int depth= 1;
    while (!buffer.empty())
    {
      int curSize = buffer.size();
      while (curSize != 0)
      {
        TreeNodeT *curNode = buffer.front();
        buffer.pop();
        --curSize;
        if (!curNode->left && !curNode->right)
        {
          return depth;
        }

        if (curNode->left)
        {
          buffer.push(curNode->left);
        }

        if (curNode->right)
        {
          buffer.push(curNode->right);
        }
      }

      ++depth;
    }

    return depth;
  }

  int MinimumDepthRecursive(TreeNodeT *node)
  {
    if (node == nullptr)
    {
      return 0;
    }

    int leftDepth = 0;
    if (node->left)
    {
      leftDepth = MinimumDepthRecursive(node->left);
    }

    int rightDepth = 0;
    if (node->right)
    {
      rightDepth = MinimumDepthRecursive(node->right);
    }

    return std::min(leftDepth, rightDepth) + 1;
  }

  void ShowPreOrder(TreeNodeT *node)
  {
    if (node != nullptr)
    {
      cout << node->value << ", ";
      ShowPreOrder(node->left);
      ShowPreOrder(node->right);
    }
  }

  void ShowInOrder(TreeNodeT *node)
  {
    if (node != nullptr)
    {
      ShowInOrder(node->left);
      cout << node->value << ", ";
      ShowInOrder(node->right);
    }
  }

  void ShowPostOrder(TreeNodeT *node)
  {
    if (node != nullptr)
    {
      ShowPostOrder(node->left);
      ShowPostOrder(node->right);
      cout << node->value << ", ";
    }
  }

  void ShowLevelOrder(TreeNodeT *node, bool pretty)
  {
    queue<TreeNodeT *> nodeQueue;
    nodeQueue.push(node);
    while (!nodeQueue.empty())
    {
      int curSize = nodeQueue.size();
      while (curSize != 0)
      {
        node = nodeQueue.front();
        nodeQueue.pop();
        cout << node->value << ", ";
        if (node->left)
        {
          nodeQueue.push(node->left);
        }

        if (node->right)
        {
          nodeQueue.push(node->right);
        }
        --curSize;
      }

      if (pretty)
      {
        cout << endl;
      }
    }
  }

  void ShowLevelOrderRecursive(TreeNodeT *node, int level)
  {
    if (node == nullptr)
    {
      return;
    }

    if (level == 0)
    {
      cout << node->value << ", ";
    }
    else
    {
      ShowLevelOrderRecursive(node->left, level - 1);
      ShowLevelOrderRecursive(node->right, level - 1);
    }
  }

  int Height(TreeNodeT *node)
  {
    if (node == nullptr)
    {
      return 0;
    }

    return std::max(Height(node->left), Height(node->right)) + 1;
  }

 private:
  TreeNodeT *root_;
  int size_;
};


class BinaryTreeTest: public TestBase
{
 public:
  void DoTest()
  {
    cout << "=================BinaryTreeTest====================" << endl;
    BinaryTree myTree;
    TreeNodeT *root = myTree.InitRoot(10);
    TreeNodeT *node = myTree.InsertLeft(root, 2);
    myTree.InsertLeft(node, 20);
    myTree.InsertRight(node, 1);
    node = myTree.InsertRight(root, 10);
    node = myTree.InsertRight(node, -25);
    myTree.InsertLeft(node, 3);
    myTree.InsertRight(node, 4);


    cout << "tree height:" << myTree.Height() << endl;

    myTree.ShowPreOrder();
    myTree.ShowInOrder();
    myTree.ShowPostOrder();
    myTree.ShowLevelOrder();
    myTree.ShowLevelOrderRecursive();

    myTree.ShowLevelOrder(true);
    myTree.ShowLevelOrderRecursive(true);
    cout << "=================BinaryTreeTest====================" << endl;
  }
};

#endif
