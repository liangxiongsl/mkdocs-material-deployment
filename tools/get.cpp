#include<bits/stdc++.h>
using namespace std;

signed main(){
	fstream cin("in.txt", ios::in);
	fstream cout("out.txt", ios::out);
	for(char c; (c=cin.get())!=-1; ){
		if(c != ':') cout << c;
		else cout << " -";
	}
}
