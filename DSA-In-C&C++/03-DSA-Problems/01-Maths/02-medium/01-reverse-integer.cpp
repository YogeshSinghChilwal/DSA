/*
!7. Reverse Integer
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int x = 123;
    long long reverse = 0;
        int sign = (x < 0) ? -1 : 1;
        x = abs(x);
        
        while(x > 0)
        {
            int lastDigit = x % 10;
            
            if(reverse > numeric_limits<int>::max() / 10 || reverse == numeric_limits<int>::max()/10 && lastDigit > 7)
                return 0;
            
            reverse = reverse * 10 + lastDigit;

            x /= 10;
        }

        //return sign * reverse;
        cout<< sign * reverse;
}