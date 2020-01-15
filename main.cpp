#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> pol1,pol2,source;  //polinomal pertama dan polinomial kedua
int deg1, deg2;  //pol1 = polinomial pertama, pol2 = polinomal kedua
//harus di global karena akan kita pakai di fungsi turunan polinomial

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
	cout << "Masukkan degree polinomial pertama: \n";
	cin >> deg1;
	for(int i=deg1;i>=0;i--){
		int tmp;
		cout << "Masukkan koefisien x^" << i << "\n";
		cin >> tmp;
		pol1.push_back(tmp);  // mengisi vektor pol1 dari koefisien polinomial tertinggi
	}
	cout << "\n";
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

void AddPoly(vector<int> &pol1, vector<int> &pol2, vector<int> &source){
	if (pol1.size() > pol2.size()){ //kasus ketika degree polinomal pertama lebih tinggi dari polinomial kedua
		for (int i = pol1.size()-1; i >= 0; i--){
			if (i > pol2.size()-1) source.push_back(pol1[i]); //ketika degree polinomial pertama masih lebih tinggi dari polinomial kedua langsung saja ambil koefisiennya 
			else source.push_back(pol1[i]+pol2[i]); //saat degree keduanya sudah sama, langsung saja tambahkan tambahkan kedua koefisiennya
		}
		reverse(source.begin(), source.end());
	}else{
		//prosesnya sama dengan diatas cuma untuk kasus degree polinomial pertama lebih kecil dari polinomial kedua
		for (int i = pol2.size()-1; i >=0; i--){
			if (i > pol1.size()-1) source.push_back(pol2[i]);
			else source.push_back(pol1[i] + pol2[i]);
		}
		reverse(source.begin(), source.end());
	}
}

void SubPoly(vector<int> &pol1, vector<int> &pol2, vector<int> &source){
	char pil;
	//ada dua kasus yakni polinomial pertama dikurang kedua atau sebaliknya
	//akibatnya kita perlu meminta user untuk memilih
	cout << "Apakah Anda ingin mengurangi polinomial pertama dengan polinomial kedua? [y/n]" << endl;
	cin >> pil;
	//prosesnya saja saja dengan pertambahan cuma ketika kasus polinomial pertama lebih kecil dari polinomial kedua
	//koefisien dari polinomial pertama akan negatif atau sebaliknya
	if (pil == 'y'){
		if (pol1.size() > pol2.size()){
			for (int i = pol1.size()-1; i >= 0; i--){
				if (i > pol2.size()-1) source.push_back(pol1[i]);
				else source.push_back(pol1[i]-pol2[i]);
			}
			reverse(source.begin(), source.end());
		}else{
			for (int i = pol2.size()-1; i >=0; i--){
				if (i > pol1.size()-1) source.push_back(-1*pol2[i]); //koefisien akan negatif
				else source.push_back(pol1[i] - pol2[i]);
			}
			reverse(source.begin(), source.end());
		}
	}else if (pil == 'n'){
		if (pol1.size() > pol2.size()){
			for (int i = pol1.size()-1; i >= 0; i--){
				if (i > pol2.size()-1) source.push_back(-1*pol1[i]); //koefisien akan negatif
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

vector<int> polymul(vector<int> &poly1, vector<int> &poly2){
	//katakanlah jika kita mengalikan polinomial pertama dengan kedua yang masing-masing degreenya n dan m
	//koefisien tertinggi dari perkaliannya adalah n+m, tapi karena kita menggunakan vektor maka koefisien tertingginya pol1.size() + pol2.size()-2
	vector<int> coeff(poly1.size()+poly2.size()-1); 
	for(int i=0;i<poly1.size();i++){
		for(int j=0;j<poly2.size();j++){
			coeff[i+j] += poly1[i]*poly2[j]; //analoginya seperti perkalian angka biasa
		}
	}
	return coeff;
}

int main(){
	cout << "Selamat datang di Program Operasi Polinomial";
	int pil;
	cout << "Masukkan piliah operasi polinomial yang ingin anda proses: \n";
	cout << "1. Pertambahan Polinomial		2. Pengurangan Polinomial\n";
	cout << "3. Perkalian Polinomial			4. Turunan Polinomial\n";
	cin >> pil;
	cout << "\nCatatan : ^ adalah simbol untuk pangkat\n";
	inPoly(pil);
	cout << "\nHasil polinomial setelah melakukan operasi tersebut adalah ";
	if(pil != 4 && pil != 3) {
		if(pil == 1) AddPoly(pol1, pol2, source);
		else if(pil == 2) SubPoly(pol1, pol2, source);
		outPoly(source);
	}
	else{
		//buat temporary vector yang akan menyimpan kembalian fungsi turunan dan perkalian
		if(pil == 3){
			vector<int> tmp = polymul(pol1, pol2); 
			outPoly(tmp);
		}
		else if(pil == 4){
			vector<int> tmp = turunan(pol1); 
			outPoly(tmp);
		}
	}
	return 0;
}
