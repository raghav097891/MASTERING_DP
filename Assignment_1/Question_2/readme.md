At first, I thought about solving the problem by checking all possible subsequences of the given array and finding the longest increasing one. But this brute force method is very slow because there are 
2
𝑛
2 
n
  subsequences in total, and checking each one would take exponential time.

So, I tried to optimize this.

Initial idea
I started from the beginning of the array and maintained a temporary list tmp which would represent an increasing subsequence. The idea was:

For each element in the array,

If the element is larger than the last element in tmp, I append it to tmp. This extends the increasing subsequence.

But if the element is smaller or equal to some elements in tmp, I thought I could replace the last element of tmp with this smaller element to keep tmp "better" (meaning having a smaller last element).

Why this initial idea was not enough
This naive replacement of the last element in tmp with a smaller element can cause us to miss some subsequences.

For example, if:

The first large element comes, so we add it at the end of tmp.

Then a smaller element appears, replacing the last element.

Then an element larger than the last element but smaller than some other elements inside tmp appears, but since we replaced only the last element, we might have lost track of the possibility to build longer subsequences starting with different elements inside tmp.

Correct idea: replace the element that is just greater than or equal to the current element
To fix this, instead of always replacing the last element, we:

Find the first element in tmp which is strictly greater than or equal to the current element (using binary search).

Replace that element with the current element.

This way, the list tmp always remains sorted and represents the smallest possible tail elements of increasing subsequences of different lengths.

Why does this work?
The length of tmp at the end will give the length of the longest increasing subsequence.

We never lose potential subsequences because replacing the element with the current smaller element keeps options open for building longer increasing subsequences.

Importantly, this process does NOT reconstruct the actual subsequence; it only gives the correct length.

The tmp list acts like a tracker for the smallest possible ending elements of increasing subsequences by length.


