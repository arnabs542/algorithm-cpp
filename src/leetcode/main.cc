#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <cassert>
#include <stack>
#include <limits>
#include <deque>

using namespace std;

class Solution {
public:
  void RunTest()
  {
    int divident = 10;
    int divisor = 3;
    int result = divide(divident, divisor);
    cout << "result: " << result << endl;
    assert(result == 3);

    divident = 7;
    divisor = -3;
    result = divide(divident, divisor);
    cout << "result: " << result << endl;
    assert(result == -2);

  }

  int divide(int dividend, int divisor) {
    int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;

    long lDividend = std::abs((long)dividend);
    long lDivisor = std::abs((long)divisor);

    long count = 0;
    while (lDividend >= lDivisor)
    {
      lDividend -= lDivisor;
      ++count;
    }

    return count * sign;
  }

};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
