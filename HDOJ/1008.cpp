/*
Quoit Design
Time Limit: 10000/5000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 93843    Accepted Submission(s): 25339


Problem Description
Have you ever played quoit in a playground? Quoit is a game in which flat rings are pitched at some toys, with all the toys encircled awarded.
In the field of Cyberground, the position of each toy is fixed, and the ring is carefully designed so it can only encircle one toy at a time. On the other hand, to make the game look more attractive, the ring is designed to have the largest radius. Given a configuration of the field, you are supposed to find the radius of such a ring.

Assume that all the toys are points on a plane. A point is encircled by the ring if the distance between the point and the center of the ring is strictly less than the radius of the ring. If two toys are placed at the same point, the radius of the ring is considered to be 0.
 

Input
The input consists of several test cases. For each case, the first line contains an integer N (2 <= N <= 100,000), the total number of toys in the field. Then N lines follow, each contains a pair of (x, y) which are the coordinates of a toy. The input is terminated by N = 0.
 

Output
For each test case, print in one line the radius of the ring required by the Cyberground manager, accurate up to 2 decimal places.
 

Sample Input
2
0 0
1 1
2
1 1
1 1
3
-1.5 0
0 0
0 1.5
0
 

Sample Output
0.71
0.00
0.75
 */
#include<iostream>
using namespace std;
int main()
{
  int N;
  int level;
  while(cin>>level)
  {
    if(level==0)
      break;
    int time=0;
    int current=0;
    for(int j = 0;j < level;j++)
    {
      int target;
      cin>>target;
      if(target>current)
      {
        time+=(target-current)*6+5;
        current=target;
      }
      else if(target<current)
      {
        time+=(current-target)*4+5;
        current=target; 
      }
      else
      {
        time+=5;
      }
      
    }
    cout<<time<<endl;
  }
}