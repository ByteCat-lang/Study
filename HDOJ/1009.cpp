/*
FatMouse' Trade
Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 142049    Accepted Submission(s): 48987


Problem Description
FatMouse prepared M pounds of cat food, ready to trade with the cats guarding the warehouse containing his favorite food, JavaBean.
The warehouse has N rooms. The i-th room contains J[i] pounds of JavaBeans and requires F[i] pounds of cat food. FatMouse does not have to trade for all the JavaBeans in the room, instead, he may get J[i]* a% pounds of JavaBeans if he pays F[i]* a% pounds of cat food. Here a is a real number. Now he is assigning this homework to you: tell him the maximum amount of JavaBeans he can obtain.
 

Input
The input consists of multiple test cases. Each test case begins with a line containing two non-negative integers M and N. Then N lines follow, each contains two non-negative integers J[i] and F[i] respectively. The last test case is followed by two -1's. All integers are not greater than 1000.
 

Output
For each test case, print in a single line a real number accurate up to 3 decimal places, which is the maximum amount of JavaBeans that FatMouse can obtain.
 

Sample Input
5 3
7 2
4 3
5 2
20 3
25 18
24 15
15 10
-1 -1
 

Sample Output
13.333
31.500
*/
#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef struct
{
  int J;
  int F;
  double V;
}Order;
bool cmp(Order X, Order Y)
{
  return X.V>Y.V;
}
int main()
{
  int M,N;
  while(cin>>M>>N)
  {
    Order F[1001];
    if(M==-1 && N==-1)  break;
    for(int i = 1;i <= N; i++)
    {
      cin>>F[i].J>>F[i].F;
      F[i].V=(double)F[i].J/F[i].F;
    }
    double gain=0;
    sort(F+1,F+N+1,cmp);
    int index=1;
    while(M!=0 && index<=N)
    {
      if(M-F[index].F>=0)
      {
        gain+=F[index].J;
        M-=F[index].F;
        index++;
      }
      else if(M-F[index].F<0)
      {
        gain+=F[index].V*M;
        M=0;
      }
      
    }
    cout<<fixed<<setprecision(3)<<gain<<endl;
  }
}