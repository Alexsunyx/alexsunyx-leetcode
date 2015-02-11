/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int f = 0, result = -2932123;
        for(int i = 0; i < n; i++)
        {
            f = max(A[i], f + A[i]);
            result = max(f, result);
        }
        return result;
    }
};