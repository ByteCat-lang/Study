/*
Max Sum
Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 408262    Accepted Submission(s): 99649


Problem Description
Given a sequence a[1],a[2],a[3]......a[n], your job is to calculate the max sum of a sub-sequence. For example, given (6,-1,5,4,-7), the max sum in this sequence is 6 + (-1) + 5 + 4 = 14.
 

Input
The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. Then T lines follow, each line starts with a number N(1<=N<=100000), then N integers followed(all the integers are between -1000 and 1000).
 

Output
For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case. The second line contains three integers, the Max Sum in the sequence, the start position of the sub-sequence, the end position of the sub-sequence. If there are more than one result, output the first one. Output a blank line between two cases.
 

Sample Input
2
5 6 -1 5 4 -7
7 0 6 -1 1 -6 7 -5
 

Sample Output
Case 1:
14 1 4

Case 2:
7 1 6

*/

#include <stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    int i=0,j=0,k=0;
    int cnum;
    int starts=1;
    int ends=1;
    int sum[100001];
    int max_sum=-10000000;
    int current_sum=0;
    for(i=1;i<=T;++i)
    {
        current_sum=0;
        max_sum=-10000000;
        scanf("%d",&cnum);
        starts=1;
        ends=1;
        int final_starts=1;
        int final_ends=1;
        for(j=1;j<=cnum;j++)
        {
            scanf("%d",&sum[j]);
        }
        for(int ends=1;ends<=cnum;ends++)
        {
            current_sum += sum[ends];
            
            if(current_sum > max_sum)
            {
                max_sum = current_sum;
                final_starts = starts;
                final_ends = ends;
            }
            
            if(current_sum < 0)
            {
                current_sum = 0;
                starts = ends + 1;
            }
        }
        printf("Case %d:\n",i);
        printf("%d %d %d\n\n",max_sum,final_starts,final_ends);
        if(i < T) printf("\n"); 
    }
    return 0;
}