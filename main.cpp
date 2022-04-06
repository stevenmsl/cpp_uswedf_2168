#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol2168;

/* return the number of unique substrings of s
   where every digit appears the same number of times
Example 1:
Input: s="1212"
Output: 5
Explanation: "1","2","12","21","1212"

*/

tuple<string, int> testFixture1()
{
  return make_tuple("1212", 5);
}

/*
 Input s="12321"
 Output: 9
 Explanation: "1","2","3","12","23","32","21","123","321"
*/

tuple<string, int> testFixture2()
{
  return make_tuple("12321", 9);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - expect to see " << to_string(get<1>(f)) << endl;
  cout << "result: " << to_string(Solution::find(get<0>(f))) << endl;
}
void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - expect to see " << to_string(get<1>(f)) << endl;
  cout << "result: " << to_string(Solution::find(get<0>(f))) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}