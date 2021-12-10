#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        char map[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string res = "";
        int sizeNum1 = num1.size();
        int sizeNum2 = num2.size();

        int carry = 0;
        int i = 0;
        int j = 0;
        while (i < sizeNum1 || j < sizeNum2 || carry != 0)
        {
            string temp1 = i < sizeNum1 ? num1.substr(i, 1) : "0";
            string temp2 = j < sizeNum2 ? num2.substr(j, 1) : "0";
            cout << "temp1 = " << temp1 << "," << "temp2 = " << temp2 << endl;
            int tempRes = stoi(temp1) + stoi(temp2) + carry;
            cout << "tempRes = " << tempRes << endl;
            carry = tempRes / 10;
            res.push_back(map[tempRes % 10]);
            i++,j++;
        }

        reverse(res.begin(), res.end());

        return res;

    }
};


class Solution {
public:
    string addStrings(string num1, string num2) {
        //reverse(num1.begin(), num1.end());
        //reverse(num2.begin(), num2.end());
        string res = "";
        int sizeNum1 = num1.size();
        int sizeNum2 = num2.size();

        int carry = 0;
        int i = sizeNum1 - 1;
        int j = sizeNum2 - 1;
        while (i > -1 || j > -1 || carry != 0)
        {
            string temp1 = i > -1 ? num1.substr(i, 1) : "0";
            string temp2 = j > -1 ? num2.substr(j, 1) : "0";
            cout << "temp1 = " << temp1 << "," << "temp2 = " << temp2 << endl;
            int tempRes = stoi(temp1) + stoi(temp2) + carry;
            cout << "tempRes = " << tempRes << endl;
            carry = tempRes / 10;
            res = (to_string(tempRes % 10)) + res;
            i--,j--;
        }

        //reverse(res.begin(), res.end());

        return res;

    }
};

