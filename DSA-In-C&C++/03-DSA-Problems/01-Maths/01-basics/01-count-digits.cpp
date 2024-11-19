/*
Given a number n. Count the number of digits in n which evenly divide n. Return an integer, total number of digits of n which divides n evenly.

Note :- Evenly divides means whether n is divisible by a digit i.e. leaves a remainder 0 when divided.
 

Examples :

Input: n = 12
Output: 2
Explanation: 1, 2 when both divide 12 leaves remainder 0.
*/


#include<iostream>
using namespace std;

int main(){
    int N = 12;
    int ans = 0;
        
        int num = N;
        
        while(num > 0){
            int temp = num % 10;
            num = num / 10;
            
            // Check if the digit is not zero and divides N evenly
             if (temp != 0 && N % temp == 0) ans++;
        }
        
        return ans;
}