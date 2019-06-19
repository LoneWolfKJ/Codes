#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n,k,counts=0,i;
    cin >> n >> k;
    int arr[n];
    for(i=0;i<n;i++)
        cin >> arr[i];
    sort(arr,arr+n);
    for(i=0;i<n;i++)
    {
        int flag=0,mid;
        int lower=0,upper=n-1;
        while(lower<=upper)
        {
            mid= lower + (upper-lower)/2;
            if(arr[mid]==arr[i]+k)
            {
                flag=1;
                break;
            }
            else if(arr[mid]>arr[i]+k){
                upper=mid-1;
                if(arr[upper]<arr[i]+k)
                    break;
            }
            else{
                lower=mid+1;
                if(arr[lower]>arr[i]+k)
                    break;
            }
        }
        if(flag==1)
            counts+=1;
    }
    cout << counts << "\n";
    return 0;
}
