#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int sum=0; int min=arr[0], max=min;
    
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(arr[i]<min){
            min=arr[i];
        }
        if(arr[i]>max){
            max=arr[i];
        }
    }
    cout<<"Minimum Sum = "<<sum-max<<endl;
    cout<<"Maximum Sum = "<<sum-min;
    
    return 0;
}
