#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<limits.h>
#include<stdbool.h>
#include<time.h>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define or ||
#define and &&
#define not !
#define size 100001 // Maximum possible length of the string
#define mod 
typedef long long int ll;
void solve(char s[], int length, int a, int b)// Costs: "0 to 1" -> a, "1 to 0" -> b
{
    int *prefix = (int *)malloc(sizeof(int)*length);
    for(int i = 0; i < length; i++)
        prefix[i] = 0;
    int total_ones = 0;
    for(int i = 0; i < length; i++)
        total_ones += s[i]-'0';// To calculate number of ones in given binary String.
    int total_zeroes = length - total_ones;
    ll answer  =  (ll) ( min ( total_ones * b, total_zeroes * a) );//Initialising the answer with Maximum possible value.
    prefix[0] = s[0] - '0';
    for(int i = 1; i < length; i++)
        prefix[i] = prefix[i-1] + s[i] - '0';
    for(int i = 0; i < length; i++)
    {
        int ones_on_left = prefix[i];
        int zeroes_on_left = (i+1) - ones_on_left;
        int ones_on_right = total_ones - ones_on_left;
        int zeroes_on_right = total_zeroes - zeroes_on_left;
        ll temp_cost  =  ( zeroes_on_left * a + ones_on_right * b );//Some ones followed by some zeroes
        answer = min(answer , temp_cost);
        temp_cost = (ones_on_left * b + zeroes_on_right * a);//Some zeroes followed by some ones
        answer = min(answer , temp_cost);
    }
    printf("%lld\n",answer);
    free(prefix);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int test = 0; test < t; test++)
    {
        int n,a,b;
        scanf("%d %d %d",&n,&a,&b);
        char s[size];
        scanf("%s",s);
        solve(s,n,a,b);
    }
    return 0;
}