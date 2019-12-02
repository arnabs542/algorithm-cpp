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

using namespace std;

class Solution {
 public:
  void RunTest()
  {
    vector<int> input;
    bool result;

    input = {2, 3, 1, 1, 4};
    result = canJump(input);
    cout << "result: " << result << endl;

    input = {3, 2, 1, 0, 4};
    result = canJump(input);
    cout << "result: " << result << endl;
  }

  bool canJump(vector<int>& nums) {
    vector<int> dp(nums.size(), -1);

    return Aux(nums, 0, dp);
  }

  bool Aux(vector<int>& nums, int pos, vector<int> &dp)
  {
    int size = nums.size();
    if (pos >= size)
    {
      return false;
    }

    if (pos == size - 1)
    {
      return true;
    }

    bool result = false;
    for (int i = 1; i <= nums[pos]; ++i)
    {
      if (pos + i >= nums.size())
      {
        return false;
      }

      if (dp[pos + i] == -1)
      {
        result |= Aux(nums, pos + i, dp);
        if (result)
        {
          return true;
        }
        dp[pos + i] = result ? 1 : 0;
      }
      else
      {
        return dp[pos + i] == 1 ? true : false;
      }
    }

    return false;
  }

  void Show(vector<int> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ",";
    }
    cout << endl;
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
