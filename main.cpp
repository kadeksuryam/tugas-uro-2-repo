#include<iostream>
using namespace std;

void inPoly(){
	int deg1=0, deg2=0;
	cout << "Masukkan degree polinomial pertama: \n";
	cin >> deg1;
	for(int i=deg1;i>=0;i--){
		int tmp;
		cout << "Masukkan koefisien x^" << i << "\n";
		cin >> tmp;
		pol1.push_back(tmp);
	}
	cout << "Masukkan degree polinomial kedua: \n";
	cin >> deg2;
	for(int i=deg2;i>=0;i--){
		int tmp;
		cout << "Masukkan koefisien x^" << i << "\n";
		cin >> tmp;
		pol2.push_back(tmp);
	}
}

void outPoly(vector<int> &source){
	cout << "Hasil dari perkalian dua polynomial tersebut adalah: \n";
	cout << source[source.size()-1] << "x^" << source.size()-1;
	for(int i=source.size()-2;i>=1;i--){
		if(source[i] < 0) cout << " - " << abs(source[i]) << "x^" << i;
		else cout << " + " << abs(source[i]) <<  "x^" << i;
	}
	if(source[0] < 0) cout << " - " << abs(source[0]);
	else cout << " + " << abs(source[0]);
	cout << "\n";
}

int main(){
	return 0;
}
