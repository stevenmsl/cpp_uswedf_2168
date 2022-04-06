#include "solution.h"

#include <unordered_map>
#include <unordered_set>
using namespace sol2168;
using namespace std;

/*takeaways
  - generate all possible substrings and look at the digits of each
    substring to see if it qualifies for the requirement
  - use a set to remove duplicates
  - use rolling hash to optimize string comparison
*/

int Solution::find(string s)
{
  static const int MOD = 1e9 + 7;
  static const int D = 27;
  const int N = size(s);

  /*store the hased substrings
    - use a set to remove duplicates
  */
  auto unique = unordered_set<int>();
  for (int i = 0; i < size(s); ++i)
  {
    /* we are generating all substrings starting
       from s[i]: s[i..i], s[i..i+1]... s[i,n-1]
    */

    /*count how many time a digit appears in a substring */
    auto freq = unordered_map<int, int>();
    long long h = 0;
    /* all digits should appear exactly the "expected"
       times in a substring to qualify
    */
    int expected = 0;
    for (int j = i; j < N; ++j)
    {
      /* extract the digit
         - to avoid the nasty 0, which will hash both "01" and "1"
           to the same hash value for example, we just do a simple
           conversion by adding one to the digit and hence
           0->1,1->2...9->10. As a result, "01" and "1" will be
           hashed to different values
      */
      const int d = s[j] - '0' + 1;
      /*hash function*/
      h = (h * D + d) % MOD;
      /*count the times this digit has appeared so far */
      ++freq[d];
      /* you will always need to add some digit first
         and hence its frequency will be higher than
         anyone else.
         - record the frequency separately and use it
           to check if other digits have achieved
           the same frequency requirement
      */
      expected = max(expected, freq[d]);
      /* this will be true when every digit appears exactly the same number of
         times
         j-i+1 is the length of the substring we arecurrently looking at
      */
      if (size(freq) * expected == j - i + 1)
        unique.emplace(h);
    }
  }
  return size(unique);
}