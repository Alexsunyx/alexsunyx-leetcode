/*
	Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

	If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

	The replacement must be in-place, do not allocate extra memory.

	Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
	1,2,3 → 1,3,2
	3,2,1 → 1,2,3
	1,1,5 → 1,5,1
*/

/*
	1.Find the not increase one position "i" backward
	2.Find the first one position "it" which is bigger than *i
	3.swap(*i,*it)
	4.reverse

*/

class Solution {
public:

    void nextPermutation(vector<int> &num) {

		// use STL is the easiest way to make, but maybe not cool for an interview
		// next_permutation(num.begin(), num.end());

		vector<int>::reverse_iterator i = num.rbegin() + 1;
		while (i != num.rend() && *i >= *(i - 1)) i++;
		if (i == num.rend()) {
			reverse(num.begin(), num.end());
		}
		else {
			int pivot = *i;
			vector<int>::reverse_iterator it = num.rbegin();
			while (*it <= *i && it != num.rend()) it++;
			*i = *it;
			*it = pivot;
			reverse(num.rbegin(), i);
		}
	}
};