                                 Approach
Detailed Explanation of the Approach
At first, I tried the brute force method where I would generate all possible subsequences of the array and find the longest strictly increasing one. However, I realized this approach has a time complexity of 
𝑂
(
2
𝑛
)
, which is too slow for large inputs.

To optimize, I started thinking about building the subsequence step by step from the start of the array:

I maintained a temporary vector tmp to keep track of an increasing subsequence.

For each element in the array, if it was larger than the last element in tmp, I simply appended it to tmp.

But if the element was smaller, I thought about replacing the last element of tmp with this smaller element to keep tmp’s last element as small as possible. The idea was that by keeping the last element smaller, I could have a better chance to extend the subsequence later.

However, this approach didn’t always work because replacing the last element could cause me to miss better subsequences. For example, if a large element came first and then a smaller element came, replacing only the last element means I might lose some valid subsequences that could have been formed by replacing other elements inside tmp.

To fix this, I decided to:

Replace not just the last element, but the first element in tmp which is greater than or equal to the current element.

I found this position using binary search (upper_bound or lower_bound).

By doing this, I ensured tmp stays sorted and its elements represent the smallest possible tail values for increasing subsequences of each length.

This method doesn’t actually build the subsequence itself but correctly computes its length. The length of tmp at the end is the length of the longest increasing subsequence.

This approach improved the time complexity to 
𝑂
(
𝑛
log
⁡
𝑛
)
because each element is processed with a binary search.




