#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int ar[n];
    cout<<"Enter Elements: ";

    for(int i=0;i<n;i++){ //read
        cin>>ar[i];
    } 
    int max=0; int min=ar[0];
    for(int i=0;i<n;i++){
        if(max<ar[i]){
          max=ar[i];
        }
        if(min>ar[i]){
            min=ar[i];
        }
    }
    cout<<"The maximum element is : "<<max<<endl;
    cout<<"The minimum element is: "<<min<<endl;
    return 0;
}