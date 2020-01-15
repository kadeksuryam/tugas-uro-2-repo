#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> pol1,pol2;  //polinomal pertama dan polinomial kedua
int deg1, deg2; //harus di global karena akan kita pakai di fungsi turunan polinomial

void inPoly(int &pilihan){ //pass reference karena nilai pilihan tidak akan kita ubah
	if(pilihan==4){  //ketika user memilih operator turunan, harus kita bedakan, karena turunan hanya perlu satu polinomal
		cout << "Masukkan degree polinomial: \n";
		cin >> deg1;
		for(int i=deg1;i>=0;i--){
			int tmp;
			cout << "Masukkan koefisien x^" << i << "\n";
			cin >> tmp;
			pol1.push_back(tmp); // mengisi vektor pol1 dari koefisien polinomial tertinggi
		}
		reverse(pol1.begin(), pol1.end()); //harus di reverse supaya index vektor (degree) sesuai dengan isi vektornya
		return;
	}
	int deg1=0, deg2=0; //pol1 = degree polinomial pertama, pol2 = degree polinomial kedua
	cout << "Masukkan degree polinomial pertama: \n";
	cin >> deg1;
	for(int i=deg1;i>=0;i--){
		int tmp;
		cout << "Masukkan koefisien x^" << i << "\n";
		cin >> tmp;
		pol1.push_back(tmp);  // mengisi vektor pol1 dari koefisien polinomial tertinggi
	}
	//kita menganalogikan index vektor menjadi degree polinomial
	reverse(pol1.begin(), pol1.end()); //harus di reverse supaya index vektor (degree) sesuai dengan isi vektornya
	cout << "Masukkan degree polinomial kedua: \n";
	cin >> deg2;
	for(int i=deg2;i>=0;i--){
		int tmp;
		cout << "Masukkan koefisien x^" << i << "\n";
		cin >> tmp;
		pol2.push_back(tmp);  // mengisi vektor pol2 dari koefisien polinomial tertinggi
	}
	reverse(pol2.begin(), pol2.end()); //harus di reverse supaya index vektor (degree) sesuai dengan isi vektornya
}

void outPoly(vector<int> &source){ //pass reference karena vektor source tidak akan kita ubah nilainya
	//source berisi koefisien polinomial yang akan di keluarkan
	bool cek = true; //untuk mengecek apakah nilai koefisien dari semua degree polinomal tidak bernilai 0
	for (int i = 0; i < source.size();i++){
		if (source[i] != 0) cek = false;
	}
	if (cek) cout << "0" << endl; //jika semua koefisien 0 outputkan 0
	else{
		if(source[source.size()-1] != 0) cout << source[source.size()-1] << "x^" << source.size()-1; //kasus ketika koefisien degree tertinggi tidak 0
		for(int i=source.size()-2;i>=1;i--){
			if (i == 1){  //ketika degree polinomal bernilai 1 kita tidak perlu menuliskan pangkatnya
				if(source[1] < 0) cout << " - " << abs(source[1]) << "x"; //kasus ketika koefisien bernilai negatif
				else if (source[1] > 0) cout << " + " << abs(source[1]) << "x"; //kasus ketika koefisien bernilai positif
			}else{ //ketika degreenya lebih besar dari 1
				if(source[i] < 0) cout << " - " << abs(source[i]) << "x^" << i; //kasus ketika koefisien bernilai negatif
				else if (source[i] > 0) cout << " + " << abs(source[i]) << "x^" << i; //kasus ketika koefisien bernilai negatif
			}
		}
		//ketika degree 0 (konstanta)
		if(source[0] < 0) cout << " - " << abs(source[0]); //konstanta negatif
		else if (source[0] > 0) cout << " + " << abs(source[0]); //konstanta positif
		cout << "\n";
	}

}

vector<int> turunan(vector<int> &pol1){ //fungsi turunan yang akan mengembalikan vector of int 
	vector<int> f1(deg1); //vektor yang nantinya akan berisi koefisien polinomial yang sudah diturunkan
	for(int i=deg1-1;i>=0;i--){
		f1[i]=pol1[i+1]*(i+1); //kalikan koefisien ke i+1 dengan degree i+1 yang nantinya akan menjadi koefisien ke i
	}
	return f1;
}

int main(){
	cout << "Selamat datang di Program Operasi Polinomial"
	int pil;
	cout << "Masukkan piliah operasi polinomial yang ingin anda proses: \n";
	cout << "1. Pertambahan Polinomial		2. Pengurangan Polinomial\n";
	cout << "3. Perkalian Polinomial		4. Turunan Polinomial\n";
	cin >> pil;
	inPoly(pil);
	if(pil != 4) {
		
	}
	else {
		vector<int> tmp = turunan(pol1); //temporary vector hasil kembalian dari fungsi turunan
		outPoly(tmp);
	}
	return 0;
}
