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

        Array* findMissing(){
            int diff = A[0] - 0;
            int copy_diff = diff;
            cout<<"\nMissing Elements : \n";
            for(int i=0; i<length-1; i++){
                if(A[i]-i != diff){
                    while(diff<A[i]-i){
                        cout<<diff+i<<"\t";
                        diff++;
                    }
                }
            }
            if(copy_diff == diff)
                cout<<"None"<<endl;
        }
};

int main(){
    Array arr(10,6);
    arr.fillValues();
    arr.Display();
    arr.findMissing();
    return 0;
}