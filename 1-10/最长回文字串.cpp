// ConsoleApplication35.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		string temp = "";
		string temp1 = "";//保存的暂时回文串
		string temp2 = "";//用作返回的回文字符串
		//对比奇串，如adeda
		for (unsigned int i = 0; i<s.length(); i++) {
			temp1 = "";
			temp += s[i];
			temp1.push_back(s[i]);
			for (unsigned int j = 1; j<temp.length() && (i + j<s.length()); j++) {

				if (temp[i - j] == s[i + j])
				{
					temp1 = temp[i - j] + temp1 + s[i + j];

				}
				else
					break;
			}
			if (temp1.length() > temp2.length())
			{
				temp2 = temp1;

			}

		}
		string temps = "";
		string temp1s = "";//保存的暂时回文串
		string temp2s = "";//用作返回的回文字符串
		//对比偶串，如adeleeleda
		for (unsigned int p = 0; p < s.length(); p++) {
			temp1s = "";
			temps += s[p];
			for (unsigned int q = 0; q < temps.length() && (p + q<s.length()); q++) {
				if (temps[p - q] == s[p + q + 1])
				{
					//adeleeleda
					temp1s = temps[p - q] + temp1s + s[p + q + 1];
				}
				else
					break;
			}
			if (temp1s.length() > temp2s.length()) {
				temp2s = temp1s;
			}
		}

		//比较了奇偶，选择一个较长的字串返回
		temp2 = temp2.length() > temp2s.length() ? temp2 : temp2s;

		string temp3 = "";
		if (temp2.length() < 2)
		{
			temp3 = "";
			for (unsigned int i = 0; i < s.length(); i++)
			{
				temp3.push_back(s[i]);
				if (s[i + 1] == s[i])
				{
					temp3.push_back(s[i + 1]);
					return temp3;
				}
				else
					temp3 = "";
			}
		}
		return temp2;
	}
};
int main(void) {
	Solution s1;
	cout << s1.longestPalindrome("ad");

	return 0;

}