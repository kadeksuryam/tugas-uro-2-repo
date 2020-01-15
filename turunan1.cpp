#include<iostream>
#include<array>

using namespace std;

int main(){
	int n;
	cout<<"Masukkan degree polynom f : ";
	cin>>n;
	cout<<'\n';
	int f[n+1];
	for(int i=n;i>=0;i--){
		cout<<"Masukkan koefisien X^"<<i<<" : ";
		cin>>f[i];
	}
	for(int i=n;i>=0;i--){
		if(i!=0){
			cout<<f[i]<<"X^"<<i<<" + ";
		}else{
			cout<<f[i]<<'\n';
		}
	}
	int f1[n];
	for(int i=n-1;i>=0;i--){
		f1[i]=f[i+1]*(i+1);
	}
	
	for(int i=n-1;i>=0;i--){
		if(i!=0){
			cout<<f1[i]<<"X^"<<i<<" + ";
		}else{
			cout<<f1[i]<<'\n';
		}
	}
	
	
	return 0;
}
