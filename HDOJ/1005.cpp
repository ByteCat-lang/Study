/*
Number Sequence
Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 272578    Accepted Submission(s): 69432


Problem Description
A number sequence is defined as follows:

f(1) = 1, f(2) = 1, f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7.

Given A, B, and n, you are to calculate the value of f(n).
 

Input
The input consists of multiple test cases. Each test case contains 3 integers A, B and n on a single line (1 <= A, B <= 1000, 1 <= n <= 100,000,000). Three zeros signal the end of input and this test case is not to be processed.
 

Output
For each test case, print the value of f(n) on a single line.
 

Sample Input
1 1 3
1 2 10
0 0 0
 

Sample Output
2
5


*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
  int A,B;
  long long n;
  int mem[55];
  while(cin>>A>>B>>n)
  {
    if(A==0 && B==0 && n==0)
    {
      break;
    }
    vector<int> f;
    f.push_back(0);
    f.push_back(1);
    f.push_back(1);
    int period;
    for(int i = 3;i<=50;i++)
    {
      f.push_back((A * f[i-1] + B * f[i-2]) % 7);
      if(f[i]==1 &&f[i-1]==1){
        period=i-2;
        break;
        }
    }
    long long pos=(n-1)%period+1;
    cout<<f[pos]<<endl;
  } 
}