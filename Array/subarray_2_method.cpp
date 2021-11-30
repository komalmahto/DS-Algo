#include <iostream>

using namespace std;
int subarray(int a[],int cu_sum[],int n)
{ int sum{0};
    for (int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {  int csum{0};cout<<cu_sum[i-1];
            csum=cu_sum[j]-cu_sum[i-1];
            
             if (sum<=csum)
                 sum=csum;
            }
            
        }
        return sum;
}
int main()
{   int n{0};
    cin>>n;
    
    int a[n],cu_sum[n];
    
    cin>>a[0];
    cu_sum[0]=a[0];
    
    for(int i{1};i<n;i++)
    {
        cin>>a[i];
        cu_sum[i]=cu_sum[i-1]+a[i];
        }
       cout<<subarray(a,cu_sum,n); 
    return 0;
    }