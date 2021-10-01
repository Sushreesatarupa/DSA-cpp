#include <iostream>
#include <cmath>
using namespace std;
int helper(int h,int *ans){
    if(h <= 1) {
		return 1;
	}
    if(ans[h]!=-1){
        return ans[h];
    }

	int mod = (int) (pow(10, 9)) + 7;
	int x = helper(h - 1,ans);
	int y = helper(h - 2,ans);

	int temp1 = (int)(((long)(x)*x) % mod);
	int temp2 = (int)((2* (long)(x) * y) % mod);
	int output = (temp1 + temp2) % mod;
    ans[h]=output;
    delete ans;
	return output;
}
int binaryTreesOfHeightH(int h) {
    int *ans=new int [h+1];
    for(int i=0; i<h; i++){
        ans[i]=-1;
    }
    return helper(h,ans);
    // Write your code here

}



int main() {
    int h;
    cin >> h;
    int ans = binaryTreesOfHeightH(h);
    ans = ans % ((int)(pow(10, 9)) + 7);
    cout << ans << endl;
}
