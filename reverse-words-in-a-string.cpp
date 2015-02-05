/*

		Given an input string, reverse the string word by word.

		For example,
		Given s = "the sky is blue",
		return "blue is sky the".

		click to show clarification.

		Clarification:
		What constitutes a word?
		A sequence of non-space characters constitutes a word.
		Could the input string contain leading or trailing spaces?
		Yes. However, your reversed string should not contain leading or trailing spaces.
		How about multiple spaces between two words?
		Reduce them to a single space in the reversed string.

*/

class Solution {
public:
	void reverseWords(string &s) {
		bool valid = false;
		string result;
		int start;
		for (int i = 0; i < s.length(); i++) {
			// find start point
			if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')){
				valid = true;
				start = i;
			}

			// find end point and store
			if (s[i] == ' ' && i != 0 && s[i - 1] != ' ') {
				valid = false;
				result.insert(0, " " + s.substr(start, i -start));
			}

			// find end point with no backspace in the end and store
			if (s[i] != ' ' && i == s.length() - 1) {
				result.insert(0, s.substr(start, i - start + 1));
			}
		}
		start = 0;
		// erase heading backspace
		while (result[0] == ' ')
			result.erase(0, 1);
		s = result;
	}
};