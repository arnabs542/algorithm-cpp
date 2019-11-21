#include <testsuit/TestBase.h>
#include <dp/LongestIncreasingSubSequence.h>
#include <dp/LongestCommonSubSequence.h>
#include <dp/EditDistance.h>
#include <dp/MinimumPartition.h>
#include <dp/PartitionProblem.h>
#include <dp/CoverDistance.h>
#include <dp/FindLongestPath.h>
#include <dp/SubsetSumProblem.h>
#include <dp/OptimalStrategyForGame.h>
#include <dp/KnapsackProblem.h>
#include <dp/BooleanParenthesizationProblem.h>
#include <dp/CutRod.h>
#include <dp/CoinChange.h>
#include <dp/WordBreak.h>
#include <dp/FrogJump.h>
#include <greedy/ActivitySelection.h>
#include <array_stack_queue/ArrayStackQueue.h>
#include <graph/Graph.h>
#include <tree_heap/Heap.h>
#include <tree_heap/BinaryTree.h>
#include <tree_heap/BinarySearchTree.h>
#include <tree_heap/FindMinimumDepthOfBinaryTree.h>
#include <tree_heap/FindMaxPathSumInBinaryTree.h>
#include <sort_search/NormalSearchAlgo.h>
#include <sort_search/NormalSortAlgo.h>
#include <sort_search/FindKthElement.h>
#include <sort_search/FindPairSumClosest.h>
#include <sort_search/FindPairEqSum.h>
#include <linkedlist/ReverseLinkedList.h>
#include <linkedlist/LinkedListSortByMergeSort.h>
#include <linkedlist/MergeTwoSortedLinkedList.h>
#include <bit_manipulation/FindMaxSubArrayXor.h>
#include <bit_manipulation/FindNthMagicNumber.h>
#include <string_array/ReverseString.h>
#include <string_array/FindLongestSubString.h>
#include <string_array/CountTripletsSumSmaller.h>
#include <string_array/ConvertArrayInfoZigZag.h>
#include <string_array/GenAllSortedArrayFromTwoArray.h>
#include <string_array/PythagoreanTriplet.h>
#include <string_array/LargestContiguousSubArray.h>
#include <string_array/SmallestSubArrayWithSum.h>
#include <string_array/StockBuySell.h>
#include <string_array/LongestPalindromicSubString.h>
#include <string_array/StringWordDict.h>

int main()
{
  TestBase *testCase = nullptr;
  // testCase = new LongestIncreasingSubSequence();
  // testCase = new LongestCommonSubSequence();
  // testCase = new EditDistance();
  // testCase = new MinimumPartition();
  // testCase = new PartitionProblem();
  // testCase = new CoverDistance();
  // testCase = new FindLongestPath();
  // testCase = new SubsetSumProblem();
  // testCase = new OptimalStrategyForGame();
  // testCase = new BooleanParenthesizationProblem();
  // testCase = new KnapsackIgnoreGoodsValueProblem();
  // testCase = new KnapsackProblem();
  // testCase = new CutRod();
  // testCase = new CoinChange();
  // testCase = new WordBreak();
  // testCase = new ArrayStackQueueTest();
  // testCase = new HeapTest();
  // testCase = new BinarySearchTreeTest();
  testCase = new GraphTest();
  // testCase = new NormalSortAlgo();
  // testCase = new FindKthElement();
  // testCase = new FindPairEqSum();
  // testCase = new FindPairSumClosest();
  // testCase = new NormalSearchAlgo();
  // testCase = new FindMinimumDepthOfBinaryTree();
  // testCase = new BinaryTreeTest();
  // testCase = new ReverseLinkedList();
  // testCase = new MergeTwoSortedLinkedList();
  // testCase = new LinkedListSortByMergeSort();
  // testCase = new FindNthMagicNumber();
  // testCase = new ReverseString();
  // testCase = new FindLongestSubString();
  // testCase = new CountTripletsSumSmaller();
  // testCase = new ConvertArrayInfoZigZag();
  // testCase = new GenAllSortedArrayFromTwoArray();
  // testCase = new PythagoreanTriplet();
  // testCase = new LargestContiguousSubArray();
  // testCase = new SmallestSubArrayWithSum();
  // testCase = new StockBuySell();
  // testCase = new ActivitySelection();
  // testCase = new LongestPalindromicSubString();
  // testCase = new StringWordDict();
  // testCase = new FrogJump();
  testCase->DoTest();

  delete testCase;
  return 0;
}
