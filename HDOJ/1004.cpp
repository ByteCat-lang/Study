  /*
  Let the Balloon Rise
Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 210453    Accepted Submission(s): 85420


Problem Description
Contest time again! How excited it is to see balloons floating around. But to tell you a secret, the judges' favorite time is guessing the most popular problem. When the contest is over, they will count the balloons of each color and find the result.

This year, they decide to leave this lovely job to you.
 

Input
Input contains multiple test cases. Each test case starts with a number N (0 < N <= 1000) -- the total number of balloons distributed. The next N lines contain one color each. The color of a balloon is a string of up to 15 lower-case letters.

A test case with N = 0 terminates the input and this test case is not to be processed.
 

Output
For each case, print the color of balloon for the most popular problem on a single line. It is guaranteed that there is a unique solution for each test case.
 

Sample Input
5
green
red
blue
red
red
3
pink
orange
pink
0
 

Sample Output
red
pink
  */
  
  #include<iostream>
  #include<vector>
  #include<unordered_map>
  #include<algorithm>
  using namespace std;
  int main()
  {
    int N;
    while(cin>>N)
    {
      if(N==0) break;
      vector<string> fcolor;
      for(int i = 0;i < N;i++)
      {
        
        string color;
        cin>>color;
        fcolor.push_back(color);

      }
      string pcolor;
      unordered_map<string,int> cnt;
      int maxcnt=-1;
      for(const string& color:fcolor)
      {
        cnt[color]++;
        if(cnt[color]>maxcnt)
          {
            pcolor=color;
            maxcnt=cnt[color];
          }
      }
      cout<<pcolor<<endl;
      
    }

  }