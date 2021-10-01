#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct trie2{
	bool isend;
	unordered_map<char,trie2*> mp;

	trie2()
	{
		isend=false;
	}

};

struct trie2* root1;



void insert2(string str)
{
	struct trie2* cur=root1;
	for(char ch:str)
	{
		if(!cur->mp.count(ch))
			cur->mp[ch]=new trie2;
		cur=cur->mp[ch];
	}
	cur->isend=true;
}

bool search2(string str)
{
	struct trie2* cur=root1;
	for(char ch:str)
	{
		if(!cur->mp.count(ch))
			return false;
		cur=cur->mp[ch];
	}
	return cur->isend;
}




int main()
{
	root1=new trie2;

	ll n;
	cin>>n;
	while(n--)
	{
		string str;
		cin>>str;
		insert2(str);
	}
	cin>>n;
	while(n--)
	{
		string str;
		cin>>str;
		if(search2(str))
		{
			cout<<str<<" is present\n";
		}
		else
		{
			cout<<str<<" is not present\n";
		}
	}

}