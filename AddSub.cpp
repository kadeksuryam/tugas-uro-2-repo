#include <bits/stdc++.h>
using namespace std;
vector<int> pol1,pol2;
vector<int> source;

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
	reverse(pol1.begin(), pol1.end());
	cout << "Masukkan degree polinomial kedua: \n";
	cin >> deg2;
	for(int i=deg2;i>=0;i--){
		int tmp;
		cout << "Masukkan koefisien x^" << i << "\n";
		cin >> tmp;
		pol2.push_back(tmp);
	}
	reverse(pol2.begin(), pol2.end());
}

void outPoly(vector<int> &source){
	bool cek = true;
	for (int i = 0; i < source.size();i++){
		if (source[i] != 0) cek = false;
	}
	if (cek) cout << "0" << endl;
	else{
		if(source[source.size()-1] != 0) cout << source[source.size()-1] << "x^" << source.size()-1;
		for(int i=source.size()-2;i>=1;i--){
			if (i == 1){
				if(source[1] < 0) cout << " - " << abs(source[1]);
				else if (source[1] > 0) cout << " + " << abs(source[1]);
			}else{
				if(source[i] < 0) cout << " - " << abs(source[i]) << "x^" << i;
				else if (source[i] > 0) cout << " + " << abs(source[i]) << "x^" << i;
			}
		}
		if(source[0] < 0) cout << " - " << abs(source[0]);
		else if (source[0] > 0) cout << " + " << abs(source[0]);
		cout << "\n";
	}
} 

void AddPoly(vector<int> &pol1, vector<int> &pol2, vector<int> &source){
	if (pol1.size() > pol2.size()){
		for (int i = pol1.size()-1; i >= 0; i--){
			if (i > pol2.size()-1) source.push_back(pol1[i]);
			else source.push_back(pol1[i]+pol2[i]);
		}
		reverse(source.begin(), source.end());
	}else{
		for (int i = pol2.size()-1; i >=0; i--){
			if (i > pol1.size()-1) source.push_back(pol2[i]);
			else source.push_back(pol1[i] + pol2[i]);
		}
		reverse(source.begin(), source.end());
	}
}
void SubPoly(vector<int> &pol1, vector<int> &pol2, vector<int> &source){
	char pil;
	cout << "Apakah Anda ingin mengurangi polinomial pertama dengan polinomial kedua? [y/n]" << endl;
	cin >> pil;
	if (pil == 'y'){
		if (pol1.size() > pol2.size()){
			for (int i = pol1.size()-1; i >= 0; i--){
				if (i > pol2.size()-1) source.push_back(pol1[i]);
				else source.push_back(pol1[i]-pol2[i]);
			}
			reverse(source.begin(), source.end());
		}else{
			for (int i = pol2.size()-1; i >=0; i--){
				if (i > pol1.size()-1) source.push_back(-1*pol2[i]);
				else source.push_back(pol1[i] - pol2[i]);
			}
			reverse(source.begin(), source.end());
		}
	}else if (pil == 'n'){
		if (pol1.size() > pol2.size()){
			for (int i = pol1.size()-1; i >= 0; i--){
				if (i > pol2.size()-1) source.push_back(-1*pol1[i]);
				else source.push_back(pol2[i]-pol1[i]);
			}
			reverse(source.begin(), source.end());
		}else{
			for (int i = pol2.size()-1; i >=0; i--){
				if (i > pol1.size()-1) source.push_back(pol2[i]);
				else source.push_back(pol2[i] - pol1[i]);
			}
			reverse(source.begin(), source.end());
		}
	}
}
int main(){
	inPoly();
}
