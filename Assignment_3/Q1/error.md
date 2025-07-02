Error 1(Line 2):
This base case is incomplete. It handles only the case when characters match at index 0.
If characters don’t match at n==0 or m==0, this condition fails and control moves to the rest of the code, which leads to unnecessary recursive calls even though we’ve already reached the boundary.
Fix:
if(n<0||m<0) return 0;
use only this base case as when negative m and n become negative it donot call negative indexed dp.

Error 2(Line 4-10):
This logic is wrong. In LCS, when characters match, only the diagonal path (c) should be incremented because it represents including the current character.
Adding +1 to a and b is incorrect because those paths represent skipping a character (not matching)
Fix:
**if(s1[n] == s2[m])
    c=fn(n-1,m-1)
    dp[n][m] = 1 + ;
else
    a=fn(n-1,m)
    b=fn(n,m-1)
    dp[n][m] = max(a, b);**
This approach will be better as it prevents calling a,b,c in all cases as we have to call a,b when characters don't match and c when characters match.
