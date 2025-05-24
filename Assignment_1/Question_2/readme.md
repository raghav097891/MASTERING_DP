The problem is to find the length of the Longest Increasing Subsequence (LIS) in a given array.

Brute Force (Naive) Approach
Initially, one might consider generating all possible subsequences of the array and then checking which are strictly increasing to find the longest one. However, this brute force approach has a time complexity of 
𝑂
(
2
𝑛
)
O(2 
n
 ) because there are 
2
𝑛
2 
n
  subsequences for an array of size 
𝑛
n. This is not feasible for large inputs.

Optimized Approach Using Binary Search
To optimize, we use a greedy and binary search method with the following idea:

Maintain a temporary array tmp which helps track the smallest possible tail elements of increasing subsequences of various lengths.

Iterate through each element x in the input array:

If x is greater than the last element in tmp, append x to tmp.
This means we found a longer increasing subsequence.

Otherwise, find the first element in tmp that is greater than or equal to x (using binary search) and replace that element with x.
This step ensures that tmp remains sorted and the tail elements are as small as possible, keeping options open for future elements.

Why this works
The length of tmp at the end of the iteration equals the length of the LIS.

Replacing elements in tmp does not necessarily represent an actual subsequence from the original array; rather, it maintains minimal tail values for subsequences of each possible length.

By always trying to keep these tails as small as possible, the method allows longer increasing subsequences to be built efficiently.

This approach runs in 
𝑂
(
𝑛
log
⁡
𝑛
)
O(nlogn) time due to binary search, which is a significant improvement over the brute force method.




