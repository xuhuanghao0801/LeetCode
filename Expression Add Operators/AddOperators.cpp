#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        string tmp;
        dfs(num, 0, target, 0, tmp, result);
        return result;
    }

private:
	void dfs(string& num, int pos, long target, long lastDelta, string& tmp, vector<string>& result) {
		// Final case processing.
		if(pos == num.size())
		{
			if((num.size() != 0) && (target == 0)) {
				result.push_back(tmp);
			}
		}

		// Depth first searching...
		int reservedLen = num.size() - pos;
		if(num[pos] == '0') {
			reservedLen = 1;
		}
		long delta = 0;
		for(int len = 1; len <= reservedLen; ++len) {
			delta = delta * 10 + num[pos + len - 1] - '0';
			if(pos == 0) {
				int nowTmpPos = tmp.size();
				tmp.append(num.substr(pos, len));
				dfs(num, pos + len, target - delta, -delta, tmp, result);
				tmp.erase(nowTmpPos, len);
			} else {
				int nowTmpPos = tmp.size();

				// Add '+'
				tmp.append("+");
				tmp.append(num.substr(pos, len));
				dfs(num, pos + len, target - delta, -delta, tmp, result);
				//tmp.erase(nowTmpPos, len + 1);

				// Minus '-'
				//tmp.append("-");
				//tmp.append(num.substr(pos, len));
				tmp[nowTmpPos] = '-';
				dfs(num, pos + len, target + delta, delta, tmp, result);
				//tmp.erase(nowTmpPos, len + 1);

				// Multiply '*'
				//tmp.append("*");
				//tmp.append(num.substr(pos, len));
				tmp[nowTmpPos] = '*';
				dfs(num, pos + len, target - lastDelta + lastDelta * delta, lastDelta * delta, tmp, result);
				tmp.erase(nowTmpPos, len + 1);
			}
		}
		return;
	}
};



int main(void) {
	string testCase = "2147483648";
	Solution sl;
	vector<string> result = sl.addOperators(testCase, -2147483648);
	for(auto ptr = result.begin(); ptr != result.end(); ++ptr) {
		cout << *ptr << endl;
	}
	return 0;
}