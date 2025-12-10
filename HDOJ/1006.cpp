/*
Tick and Tick
Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 31671    Accepted Submission(s): 9123


Problem Description
The three hands of the clock are rotating every second and meeting each other many times everyday. Finally, they get bored of this and each of them would like to stay away from the other two. A hand is happy if it is at least D degrees from any of the rest. You are to calculate how much time in a day that all the hands are happy.
 

Input
The input contains many test cases. Each of them has a single line with a real number D between 0 and 120, inclusively. The input is terminated with a D of -1.
 

Output
For each D, print in a single line the percentage of time in a day that all of the hands are happy, accurate up to 3 decimal places.
 

Sample Input
0
120
90
-1
 

Sample Output
100.000
0.000
6.251
*/
#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;

int main()
{
  double vsm=59.0/10,vsh=719.0/120,vmh=11.0/120;
  double tsm=360/vsm,tsh=360/vsh,tmh=360/vmh;
  double b1,b2,b3;
  double e1,e2,e3;
  int k1,k2,k3;
  double total,angle,start,ended;
  while(cin>>angle)
  {
    if(angle==-1)
      break;
    total=0;
    b3=angle/vmh;
    e3=(360-angle)/vmh;
    b1=angle/vsm;
    e1=(360-angle)/vsm;
    b2=angle/vsh;
    e2=(360-angle)/vsh;
     while(b3<43200){
                while(b1<e3){
                    while(b2<e3&&b2<e1)
                    {
                      start=max(max(b1,b2),b3);
                      ended=min(min(e1,e2),e3);
                      total+=(ended-start>0)?ended-start:0;
                      b2=b2+tsh; e2=e2+tsh;
                    }
                    b2=b2-tsh;e2=e2-tsh;
                    b1=b1+tsm;e1=e1+tsm;
                }
                b1=b1-tsm;e1=e1-tsm;
               b3=b3+tmh; e3=e3+tmh;
            }
            cout<<fixed<<setprecision(3)<<total/432<<endl;
          }
  
}