
#include <iostream>
using namespace std;

int isAnagram(char *arr1, char *arr2){
    int H[26]={0};
    for(int i=0; arr1[i]!='\0'; i++){
        H[arr1[i]-97]++;
    }
    int i;
    for(i=0; arr2[i]!='\0'; i++){
        H[arr2[i]-97]--;
    }
    for(int i=0; arr1[i]!='\0'; i++){
        if(H[arr1[i]-97] != 0)
            return 0;
        else
            return 1;
    }
}

int main(){
    char s1[] = "jargoan";
    char s2[] = "aranjog";
    if(isAnagram(s1,s2))
        cout<<"Anagram."<<endl;
    else
        cout<<"Not an Anagram."<<endl;
    return 0;
}