#include <iostream>
using namespace std;

class Array{
    private:
        int *A;
        int size;
        int length;
    public:
        Array(){
            size = 10;
            A = new int[10];
            length = 0;
        }

        Array(int sz, int len){
            size = sz;
            A = new int[size];
            length = len;
        }

        ~Array(){
            delete []A;
        }


        void fillValues(){
            cout<<"Enter array elements : \n";
            for(int i=0; i<length; i++){
                cin>>A[i];
            } 
        }

        void Display(){
            cout<<"\nArray elements\n";
            for(int i=0; i<length; i++){
                cout<<A[i]<<"\t";
            }
            cout<<"\n";
        }

        Array* findMissingUsingHashing(int low, int high){
            int hash[high];
            memset(hash,0,sizeof hash);
            for(int i=0; i<length; i++){
                hash[A[i]]++;
            }
            cout<<"\nMissing Elements : \n";
            for(int i=low; i<=high; i++){
                if(hash[i]==0)
                    cout<<i<<"\t";
            }
        }
};

int main(){
    Array arr(10,6);
    arr.fillValues();
    arr.Display();
    arr.findMissingUsingHashing(1,16);
    return 0;
}