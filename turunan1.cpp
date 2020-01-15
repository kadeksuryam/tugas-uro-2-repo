#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> pol1,pol2;
int deg1=0, deg2=0;
vector<int> f1(deg1-1);

void inPoly(int pilihan){
	if(pilihan==4){
		cout << "Masukkan degree polinomial: \n";
		cin >> deg1;
		for(int i=deg1;i>=0;i--){
			int tmp;
			cout << "Masukkan koefisien x^" << i << "\n";
			cin >> tmp;
			pol1.push_back(tmp);
		}
		reverse(pol1.begin(), pol1.end());
		return;
	}
}

void turunan(vector<int> &pol1){
	for(int i=deg1-1;i>=0;i--){
		f1[i]=pol1[i+1]*(i+1);
	}
}


void outPoly(vector<int> &source){
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
	cout << "Selamat datang di";
	/*int pil;
	cout << "Masukkan pilihan anda: \n";
	cout << "1. Pertambahan Polinomial		2. Pengurangan Polinomial\n";
	cout << "3. Perkalian Polinomial		4. Turunan Polinomial\n"; 
	cin >> pil;
	inPoly(pil);
//	turunan(pol1);
//	outPoly(f1);
	return 0; */
}
