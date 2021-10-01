#include <iostream>
using namespace std;


//Function to swap two numbers
void swap(int &a,int &b){
    int t = a;
    a = b;
    b = t;
}


//cycle sort program
void Cyclesort(int arr[],int n){
    for(int cy = 0 ; cy <= n-2 ; cy++){
        int pos = cy;
        int &item = arr[pos];
        for(int i = cy + 1 ; i < n ; i++){
            if(item > arr[i])
                pos++;
        }

        if(pos == cy) continue;    //main!
        while(arr[pos] == item){
            pos++;
        }
        swap(item,arr[pos]);

        while(cy != pos){
            pos = cy;
            for(int i = cy + 1 ; i < n ; i++){
                if(arr[i] < item)
                    pos++;
            }
            if(pos == cy) break;
            while(arr[pos] == item){
                pos++;
            }
            swap(item,arr[pos]);
        }
    }
}


//main function
int main() {
	int arr[10] = {3,6,9,1,3,9,5,0,2,11};
	Cyclesort(arr,10);
	for(int i = 0 ; i < 10 ; i++){
	    cout<<arr[i]<<endl;
	}
	return 0;
}
