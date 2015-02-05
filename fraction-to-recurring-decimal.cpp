/**
 *	Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
 *
 *	If the fractional part is repeating, enclose the repeating part in parentheses.
 *
 *	For example,
 *
 *	Given numerator = 1, denominator = 2, return "0.5".
 *	Given numerator = 2, denominator = 1, return "2".
 * 	Given numerator = 2, denominator = 3, return "0.(6)".
 *
 */

class Solution {
public:
	string num2str(long long i)
	{
		stringstream ss;
		ss << i;
		return ss.str();
	}

	string fractionToDecimal(long long numerator, long long denominator) {
		long long before_dot, remain;
		int flag = 0;
		string result;
		vector<int> remain_list;
		if (numerator == 0)
			return "0";
		if (numerator < 0)
		{
			if (denominator > 0)
            {
                numerator = 0 - (long long)numerator;
                flag = 1;
            }
			else
			{
			    denominator = 0 -(long long)denominator;
			    numerator = 0 - (long long)numerator;
			}
		}
		if (denominator < 0)
		{
			denominator = 0 -(long long)denominator;
			flag = 1;
		}
		if (flag) result.append("-");
		if (numerator >= denominator) {
			before_dot = numerator / denominator;
			remain = numerator % denominator;
			result = result.append(num2str(before_dot));
			if (remain == 0)
				return result;
			else
				result.append(".");
		}
		else {
			remain = numerator;
			result.append("0.");
		}

		remain_list.push_back(remain);
		// after dot
		while (remain != 0) {
			remain *= 10;
			if (remain < denominator)
			{
				if (find(remain_list.begin(), remain_list.end(), remain) != remain_list.end())
				{
					vector<int>::iterator iter = find(remain_list.begin(), remain_list.end(), remain);
					int i = 0;
					while (++iter != remain_list.end())
						i++;
					result.insert(result.length() - i - 1, "(");
					result.append(")");
					return result;
				}
				else
				{
					result.append("0");
					remain_list.push_back(remain);
					continue;
				}
			}
			else {
				result.append(num2str(remain / denominator));
				remain = remain % denominator;
				if (find(remain_list.begin(), remain_list.end(), remain) != remain_list.end())
				{
					vector<int>::iterator iter = find(remain_list.begin(), remain_list.end(), remain);
					int i = 0;
					while (++iter != remain_list.end())
						i++;
					result.insert(result.length() - i - 1, "(");
					result.append(")");
					return result;
				}
				else

					remain_list.push_back(remain);
			}
		}

		return result;
	}
};