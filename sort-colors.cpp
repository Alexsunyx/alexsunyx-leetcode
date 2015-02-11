/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

*/

class Solution {
public:
    void sortColors(int A[], int n) {
        int zero = 0;
        int one = 0;
        int two = 0;
        for(int i = 0; i < n; i++)
        {
            if(A[i] == 0)
                zero++;
            else if(A[i] == 1)
                one++;
            else
                two++;
        }
        for(int i = 0; i < n; i++)
        {
            if(i < zero)
                A[i] = 0;
            else if(i < zero + one)
                A[i] = 1;
            else 
                A[i] = 2;
        }
    }
};