#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
// Class MonHoc
class MonHoc{
	private:
		string HocPhan,TenHocPhan;
	public:
		MonHoc();
		MonHoc(string HocPhan, string TenHocPhan);
		~MonHoc();
		void setHocPhan(string HocPhan);
		string getHocPhan();
		void setTenHocPhan(string TenHocPhan);
		string getTenHocPhan();
		friend istream& operator >> (istream& is, MonHoc& hp);
		void doc(ifstream&);
};
// Ham khoi tao class MonHoc
MonHoc::MonHoc(){
	HocPhan = "";
	TenHocPhan = "";
}
// Ham khoi tao day du class MonHoc
MonHoc::MonHoc(string HocPhan, string TenHocPhan){
	this->HocPhan = HocPhan;
	this->TenHocPhan = TenHocPhan;
}
// Ham huy class MonHoc
MonHoc::~MonHoc(){
	
}
// Ham gan gia tri cho HocPhan
void MonHoc::setHocPhan(string HocPhan){
	this->HocPhan = HocPhan;
}
// Ham tra ve HocPhan
string MonHoc::getHocPhan(){
	return HocPhan;
}
// Ham gan gia tri cho TenHocPhan
void MonHoc::setTenHocPhan(string TenHocPhan){
	this->TenHocPhan = TenHocPhan;
}
// Ham tra ve HocPhan
string MonHoc::getTenHocPhan(){
	return TenHocPhan;
}
// Ham dinh dang lai toan tu nhap
istream& operator >> (istream& is, MonHoc& hp){
	char a[40], b[40];
	fflush(stdin);
	cout << "Nhap hoc phan: ";
	is.getline(a, 40);
	cout << "Nhap ten hoc phan: ";
	is.getline(b, 40);
	hp.setHocPhan(a);
	hp.setTenHocPhan(b);
	return is;
}
// Ham doc file class MonHoc
void MonHoc::doc(ifstream& is){
	char a[40], b[40];
	fflush(stdin);
	is.getline(a, 40);
	is.getline(b, 40);
	setHocPhan(a);
	setTenHocPhan(b);
}
// Class Diem
class Diem : public MonHoc{
	private:
		float DiemQuaTrinh,DiemThi,DiemTong;
	public:
		Diem();
		Diem(float DiemQuaTrinh, float DiemThi, float DiemTong);
		~Diem();
		void setDiemQuaTrinh(float DiemQuaTrinh);
		float getDiemQuaTrinh();
		void setDiemThi(float DiemThi);
		float getDiemThi();
		void setDiemTong(float DiemTong);
		float getDiemTong();
		friend istream& operator >> (istream& is, Diem& ds);
		void doc(ifstream&);
};
// Ham khoi tao class Diem
Diem::Diem(){
	DiemQuaTrinh = 0;
	DiemThi = 0;
	DiemTong = 0;
}
// Ham khoi tao day du class Diem
Diem::Diem(float DiemQuaTrinh, float DiemThi, float DiemTong){
	this->DiemQuaTrinh = DiemQuaTrinh;
	this->DiemThi = DiemThi;
	this->DiemTong = DiemTong;
}
// Ham huy class Diem
Diem::~Diem(){
	
}
// Ham gan gia tri cho DiemQuaTrinh
void Diem::setDiemQuaTrinh(float DiemQuaTrinh){
	this->DiemQuaTrinh = DiemQuaTrinh;
}
// Ham tra ve DiemQuaTrinh
float Diem::getDiemQuaTrinh(){
	return DiemQuaTrinh;
}
// Ham gan gia tri cho DiemThi
void Diem::setDiemThi(float DiemThi){
	this->DiemThi = DiemThi;
}
// Ham tra ve DiemThi
float Diem::getDiemThi(){
	return DiemThi;
}
// Ham gan gia tri cho DiemTong
void Diem::setDiemTong(float DiemTong){
	this->DiemTong = DiemTong;
}
// Ham tra ve DiemTong
float Diem::getDiemTong(){
	return DiemTong;
}
// Ham dinh dang lai toan tu nhap
istream& operator >> (istream& is, Diem& ds){
	MonHoc *a = static_cast <MonHoc *> (&ds);
	is >> *a;
	fflush(stdin);
	float c, d, e;
	cout << "Nhap diem qua trinh: ";
	is >> c;
	cout << "Nhap diem thi: ";
	is >> d;
	e = (float)(c + d) / 2;
	ds.setDiemQuaTrinh(c);
	ds.setDiemThi(d);
	ds.setDiemTong(e);
	return is;
}
// Ham doc file class Diem
void Diem::doc(ifstream& is){
	MonHoc::doc(is);
	fflush(stdin);
	float c, d, e;
	is >> c;
	is >> d;
	e = (float)(c + d) / 2;
	char ss[5];
	is.getline(ss, 3);
	setDiemQuaTrinh(c);
	setDiemThi(d);
	setDiemTong(e);
}
// Class TinChi
class TinChi : public Diem{
	private:
		int SoTinChi;
	public:
		TinChi();
		TinChi(int SoTinChi);
		~TinChi();
		void setSoTinChi(int SoTinChi);
		int getSoTinChi();
		friend istream& operator >> (istream& is, TinChi& tc);
		friend ostream& operator << (ostream& os, TinChi& tc);
		void doc(ifstream&);
		void ghi(ofstream&);
};
// Ham khoi tao class TinChi
TinChi::TinChi(){
	SoTinChi = 0;
}
// Ham khoi tao day du class TinChi
TinChi::TinChi(int SoTinChi){
	this->SoTinChi = SoTinChi;
}
// Ham huy class TinChi
TinChi::~TinChi(){
	
}
// Ham gan gia tri cho SoTinChi
void TinChi::setSoTinChi(int SoTinChi){
	this->SoTinChi = SoTinChi;
}
// Ham tra ve SoTinChi
int TinChi::getSoTinChi(){
	return SoTinChi;
}
// Ham dinh dang lai toan tu nhap
istream& operator >> (istream& is, TinChi& tc){
	Diem *a = static_cast <Diem *> (&tc);
	fflush(stdin);
	is >> *a;
	int f;
	cout << "Nhap so tin chi: ";
	is >> f;
	tc.setSoTinChi(f);
	return is;
}
// ham dinh dang lai toan tu xuat
ostream& operator << (ostream& os, TinChi& tc){
	if(tc.getDiemTong() < 4){
		os << left << setw(10) << "|" << setw(17) << tc.getHocPhan() << setw(12) << "|" << setw(39) << tc.getTenHocPhan() << setw(13) << "|" << setw(13) <<  tc.getDiemQuaTrinh() << setw(11) << "|" << setw(12) << tc.getDiemThi() << setw(11) << "|" << setw(13) << tc.getDiemTong() << setw(13) << "|" <<  setw(12) << tc.SoTinChi << setw(9) << "|"  << setw(15) << "CHUA DAT" << "|";
	}
	else{
		os << left << setw(10) << "|" << setw(17) << tc.getHocPhan() << setw(12) << "|" << setw(39) << tc.getTenHocPhan() << setw(13) << "|" << setw(13) <<  tc.getDiemQuaTrinh() << setw(11) << "|" << setw(12) << tc.getDiemThi() << setw(11) << "|" << setw(13) << tc.getDiemTong() << setw(13) << "|" <<  setw(12) << tc.SoTinChi << setw(9) << "|"  << setw(15) << "DAT" <<  "|";
	}
	os << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;	
	return os;
}
// Ham doc file class TinChi
void TinChi::doc(ifstream& is){
	Diem::doc(is);
	fflush(stdin);
	int f;
	is >> f;
	char ss[5];
	is.getline(ss, 3);
	setSoTinChi(f);
}
// Ham ghi class TinChi
void TinChi::ghi(ofstream& os){
	if(getDiemTong() < 4){
		os << left << setw(10) << "|" << setw(17) << getHocPhan() << setw(12) << "|" << setw(39) << getTenHocPhan() << setw(13) << "|" << setw(13) <<  getDiemQuaTrinh() << setw(12) << "|" << setw(11) << getDiemThi() << setw(11) << "|" << setw(13) << getDiemTong() << setw(13) << "|" <<  setw(12) << SoTinChi << setw(9) << "|"  << setw(15) << " CHUA DAT" << "|" << endl;
	}
	else{
		os << left << setw(10) << "|" << setw(17) << getHocPhan() << setw(12) << "|" << setw(39) << getTenHocPhan() << setw(13) << "|" << setw(13) <<  getDiemQuaTrinh() << setw(12) << "|" << setw(11) << getDiemThi() << setw(11) << "|" << setw(13) << getDiemTong() << setw(13) << "|" <<  setw(12) << SoTinChi << setw(9) << "|"  << setw(15) << "DAT" << "|" << endl;
	}
	os << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;	
}
// Class SinhVien
class SinhVien{
	private:
		string HoTen,Lop,MSSV;
	public:
		SinhVien();
		SinhVien(string HoTen, string Lop, string MSSV);
		~SinhVien();
		void setHoTen(string HoTen);
		string getHoTen();
		void setLop(string Lop);
		string getLop();
		void setMSSV(string MSSV);
		string getMSSV();
		friend istream& operator >> (istream& is, SinhVien& sv);
		friend ostream& operator << (ostream& os, const SinhVien& sv);
		void docFile(ifstream&);
};
// Ham khoi tao class SinhVien
SinhVien::SinhVien(){
	HoTen = "";
	Lop = "";
	MSSV = "";
}
// Ham khoi tao day du class SinhVien
SinhVien::SinhVien(string HoTen, string Lop, string MSSV){
	this->HoTen = HoTen;
	this->Lop = Lop;
	this->MSSV = MSSV;
}
// Ham huy class SinhVien
SinhVien::~SinhVien(){
	
}
// Ham gan gia tri cho HoTen
void SinhVien::setHoTen(string HoTen){
	this->HoTen = HoTen;
}
// Ham tra ve HoTen
string SinhVien::getHoTen(){
	return HoTen;
}
// Ham gan gia tri cho Lop
void SinhVien::setLop(string Lop){
	this->Lop = Lop;
}
// Ham tra ve Lop
string SinhVien::getLop(){
	return Lop;
}
// Ham gan gia tri cho MSSV
void SinhVien::setMSSV(string MSSV){
	this->MSSV = MSSV;
}
// Ham tra ve MSSV
string SinhVien::getMSSV(){
	return MSSV;
}
// Ham dinh dang lai toan tu nhap
istream& operator >> (istream& is, SinhVien& sv){
	char ten[40], lop[40], mssv[40];
	is.getline(ten, 40);
	is.getline(lop, 40);
	is.getline(mssv, 40);
	sv.setHoTen(ten);
	sv.setLop(lop);
	sv.setMSSV(mssv);
	return is;
}
// Ham doc file class SinhVien
void SinhVien::docFile(ifstream& is){
	char ten[40], lop[40], mssv[40];
	is.getline(ten, 40);
	is.getline(lop, 40);
	is.getline(mssv, 40);
	setHoTen(ten);
	setLop(lop);
	setMSSV(mssv);
}
// Ham dinh dang lai toan tu xuat
ostream& operator << (ostream& os, const SinhVien& sv){
	os << "Ten: " << sv.HoTen << endl;
	os << "Lop: " << sv.Lop << endl;
	os << "MSSV: " << sv.MSSV << endl;
	return os;
}
// Class Node
class Node{
	public:
		TinChi data;
		Node *pNext;
		Node(TinChi data){
			this->data = data;
			pNext = NULL;
		}
};
// Class SingleList
class SingleList : public SinhVien{
	private:
		Node *pHead;
		Node *pTail;
		int size;
	public:
		SingleList();
		~SingleList();
		void addLast(TinChi& source);
		Node* getHead();
		Node* getTail();
		void traverse();
		void SortByDiemTong();
		void SortByDiemQuaTrinh();
		void SortByDiemThi();
		void SortByTenHocPhan();
		void Swap(TinChi& source1, TinChi& source2);
		float findMaxDiemTong();
		void inMaxDiemTong();
		float findMinDiemTong();
		void inMinDiemTong();
		float DiemTrungBinh();
		string XepLoai();
		int SoMonDat();
		void MonDat();
		int SoMonChuaDat();
		void MonChuaDat();
		int SoTinChiTichLuy();
		void SearchByHocPhan();
		int List_Size();
		void ThemDau(TinChi& source);
		void ThemCuoi(TinChi& source);
		void ThemHocPhan(TinChi& source, int vitri);
		void XoaHocPhan(string name);
		void Menu();
};
// Ham khoi tao class SingleList
SingleList::SingleList(){
	pHead = NULL;
	pTail = NULL;
	size = 0;
}
// Ham huy class SingleList
SingleList::~SingleList(){
	
}
// Ham them phan tu vao cuoi danh sach
void SingleList::addLast(TinChi& source){
    Node *pNode = new Node(source);
    if(size == 0){
        pHead = pTail = pNode;
    } else {
        pTail->pNext = pNode;
        pTail = pNode;
    }
    size++;
}
// Ham in ra danh sach
void SingleList::traverse(){
	Node* temp = pHead;
	int i = 1;
	while(temp != NULL){
		cout << left << setw(5) << "|" << setw(5) << i << temp->data;
		i++;
		temp = temp->pNext;
	}
}
// Ham sap xep theo diem tong
void SingleList::SortByDiemTong(){
	for(Node* temp = pHead; temp != NULL; temp = temp->pNext){
		for(Node* temp2 = temp->pNext; temp2 != NULL; temp2 = temp2->pNext){
			if(temp->data.getDiemTong() < temp2->data.getDiemTong()){
				Swap(temp->data, temp2->data);
			}
		}
	}
	traverse();
}
// Ham sap xep theo diem qua trinh
void SingleList::SortByDiemQuaTrinh(){
	for(Node* temp = pHead; temp != NULL; temp = temp->pNext){
		for(Node* temp2 = temp->pNext; temp2 != NULL; temp2 = temp2->pNext){
			if(temp->data.getDiemQuaTrinh() < temp2->data.getDiemQuaTrinh()){
				Swap(temp->data, temp2->data);
			}
		}
	}
	traverse();
}
// Ham sap xep theo diem thi
void SingleList::SortByDiemThi(){
	for(Node* temp = pHead; temp != NULL; temp = temp->pNext){
		for(Node* temp2 = temp->pNext; temp2 != NULL; temp2 = temp2->pNext){
			if(temp->data.getDiemThi() < temp2->data.getDiemThi()){
				Swap(temp->data, temp2->data);
			}
		}
	}
	traverse();
}
// Ham sap xep theo ten hoc phan
void SingleList::SortByTenHocPhan(){
	for(Node* temp = pHead; temp != NULL; temp = temp->pNext){
		for(Node* temp2 = temp->pNext; temp2 != NULL; temp2 = temp2->pNext){
			if(temp->data.getTenHocPhan() > temp2->data.getTenHocPhan()){
				Swap(temp->data, temp2->data);
			}
		}
	}
	traverse();
}
// Ham hoan doi
void SingleList::Swap(TinChi& source1, TinChi& source2){
	TinChi t = source1;
	source1 = source2;
	source2 = t;
}
// Ham tim diem tong lon nhat
float SingleList::findMaxDiemTong(){
	Node* temp = pHead;
	float max;
	while(temp != NULL){
		if(temp->data.getDiemTong() > max){
			max = temp->data.getDiemTong();
		}
		temp = temp->pNext;
	}
	return max;
}
// Ham in ra cac hoc phan co diem tong lon nhat
void SingleList::inMaxDiemTong(){
	Node* temp = pHead;
	int i = 1;
	cout << "__________________________________________________________________________________" << "HOC PHAN CO DIEM TONG CAO NHAT" << "___________________________________________________________________________________________________";
	while(temp != NULL){
		if(temp->data.getDiemTong() == findMaxDiemTong()){
			cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
			cout << right << setw(80) << i << ") " << temp->data.getTenHocPhan() << ": " << temp->data.getDiemTong() << endl;
			i++;
		}
		temp = temp->pNext;
	}
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
}
// Ham tim diem tong nho nhat
float SingleList::findMinDiemTong(){
	Node* temp = pHead;
	float min = 10;
	while(temp != NULL){
		if(temp->data.getDiemTong() < min){
			min = temp->data.getDiemTong();
		}
		temp = temp->pNext;
	}
	return min;
}
// Ham in ra cac hoc phan co diem tong nho nhat
void SingleList::inMinDiemTong(){
	Node* temp = pHead;
	int i = 1;
	cout << "__________________________________________________________________________________" << "HOC PHAN CO DIEM TONG THAP NHAT" << "__________________________________________________________________________________________________";
	while(temp != NULL){
		if(temp->data.getDiemTong() == findMinDiemTong()){
			cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
			cout << right << setw(80) << i << ") " << temp->data.getTenHocPhan() << ": " << temp->data.getDiemTong() << endl;
			i++;
		}
		temp = temp->pNext;
	}
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
}
// Ham tinh diem trung binh
float SingleList::DiemTrungBinh(){
	Node* temp = pHead;
	float sum = 0;
	float i = 0;
	while(temp != NULL){
		sum += temp->data.getDiemTong();
		i++;
		temp = temp->pNext;
	}
	float GPA = sum / i;
	return GPA;
}
// Ham xep loai hoc luc dua tren diem trung binh
string SingleList::XepLoai(){
	string xl = "";
	if(DiemTrungBinh() > 8){
		xl = "GIOI";
	}
	else if(DiemTrungBinh() > 5 && DiemTrungBinh() < 8){
		xl = "KHA";
	}
	else if(DiemTrungBinh() <= 5 && DiemTrungBinh() >= 3){
		xl = "TRUNG BINH";
	}
	else{
		xl = "YEU KEM";
	}
	return xl;
}
// Ham tinh so luong mon dat
int SingleList::SoMonDat(){
	Node* temp = pHead;
	int count = 0;
	while(temp != NULL){
		if(temp->data.getDiemTong() >= 4){
			count++;
		}
		temp = temp->pNext;
	}
	return count;
}
// Ham in ra mon dat
void SingleList::MonDat(){
	Node* temp = pHead;
	string name;
	while(temp != NULL){
		if(temp->data.getDiemTong() >= 4){
			cout << left << setw(75) << "`" << "----------------------------------------------------------" << endl;
			cout << left << setw(85) << "`" << temp->data.getTenHocPhan() << ": " << temp->data.getSoTinChi() << " tin chi" << endl;
			cout << left << setw(75) << "`" << "----------------------------------------------------------" << endl;
		}
		temp = temp->pNext;
	}
}
// Ham tinh so luong mon chua dat
int SingleList::SoMonChuaDat(){
	Node* temp = pHead;
	int count = 0;
	while(temp != NULL){
		if(temp->data.getDiemTong() < 4){
			count++;
		}
		temp = temp->pNext;
	}
	return count;
}
// Ham in ra mon chua dat
void SingleList::MonChuaDat(){
	Node* temp = pHead;
	string name;
	while(temp != NULL){
		if(temp->data.getDiemTong() < 4){
			cout << left << setw(75) << "`" << "----------------------------------------------------------" << endl;
			cout << left << setw(85) << "`" << temp->data.getTenHocPhan() << ": " << temp->data.getSoTinChi() << " tin chi" << endl;
			cout << left << setw(75) << "`" << "----------------------------------------------------------" << endl;
		}
		temp = temp->pNext;
	}
}
// Ham tinh tong so tin chi cua hoc phan dat 
int SingleList::SoTinChiTichLuy(){
	Node* temp = pHead;
	int sum = 0;
	while(temp != NULL){
		if(temp->data.getDiemTong() >= 4){
			sum += temp->data.getSoTinChi();
		}
		temp = temp->pNext;
	}
	return sum;
}
// Ham tim kiem hoc phan
void SingleList::SearchByHocPhan(){
	Node* temp = pHead;
	Node* temp2 = NULL;
	string name;
	cout << right << setw(102) << "Nhap hoc phan can tim kiem: ";
	fflush(stdin);
	getline(cin,name);
	while(temp != NULL){
		if(temp->data.getHocPhan() == name || temp->data.getTenHocPhan() == name){
			cout << setw(75) << "-" << "------------------------------------------------------------" << endl;
			cout << left << setw(74) << "*" << setw(3) << "|" << setw(15) << "Hoc phan" << ": " << setw(40) << temp->data.getHocPhan() << setw(76) << "|" << "*" << endl;
			cout << left << setw(74) << "*" << setw(3) << "|" << setw(15) << "Ten hoc phan" << ": " << setw(40) << temp->data.getTenHocPhan() << setw(76) << "|" << "*" << endl;
			cout << left << setw(74) << "*" << setw(3) << "|" << setw(15) << "Diem qua trinh" << ": " << setw(40) << temp->data.getDiemQuaTrinh() << setw(76) << "|" << "*" << endl;
			cout << left << setw(74) << "*" << setw(3) << "|" << setw(15) << "Diem thi" << ": " << setw(40) << temp->data.getDiemThi() << setw(76) << "|" << "*" << endl;
			cout << left << setw(74) << "*" << setw(3) << "|" << setw(15) << "Diem Tong" << ": " << setw(40) << temp->data.getDiemTong() << setw(76) << "|" << "*" << endl;
			cout << left << setw(74) << "*" << setw(3) << "|" << setw(15) << "So tin chi" << ": " << setw(40) << temp->data.getSoTinChi() << setw(76) << "|" << "*" << endl;
			if(temp->data.getDiemTong() < 4){
				cout << left << setw(74) << "*" << setw(3) << "|" << setw(15) << "Ghi chu" << ": " << setw(40) << "CHUA DAT" << setw(76) << "|" << "*" << endl;
			}
			else{
				cout << left << setw(74) << "*" << setw(3) << "|" << setw(15) << "Ghi chu" <<  ": " << setw(40) << "DAT" << setw(76) << "|" << "*" << endl;
			}
			cout << right << setw(135) << "-------------------------------------------------------------" << endl;
			temp2 = temp;
		}
		temp = temp->pNext;
	}
	if(temp2 == NULL){
		cout << endl;
		cout << right << setw(103) << "~~~Khong tim thay hoc phan~~~" << endl;
	}
}
// Ham tinh kich thuoc cua danh sach
int SingleList::List_Size(){
	Node* temp = pHead;
	int size = 0;
	while(temp != NULL){
		temp = temp->pNext;
		size++;
	}
	return size;
}
// Ham them hoc phan vao dau
void SingleList::ThemDau(TinChi& source){
	Node* pNode = new Node(source);
	if(pHead == NULL){
		pHead = pNode;
	}
	else{
		pNode->pNext = pHead;
		pHead = pNode;
	}
}
// Ham them hoc phan vao cuoi
void SingleList::ThemCuoi(TinChi& source){
	Node* pNode = new Node(source);
	if(pHead == NULL){
		pHead = pNode;
	}
	else{
		Node* temp = pHead;
		while(temp->pNext != NULL){
			temp = temp->pNext;
		}
	temp->pNext = pNode;
	}
	traverse();
}
// Ham them hoc phan vi tri bat ky
void SingleList::ThemHocPhan(TinChi& source, int vitri){
	if(vitri <= 0 || vitri > List_Size()){
		cout << "Vi tri khong hop le!" << endl;
		return;
	}
	if(vitri == 1){
		ThemDau(source);
	}
//	else if(vitri == List_Size() - 1){
//		ThemCuoi(source);
//	}
	else{
		Node* pNode = new Node(source);
		Node* pIns = pHead;
		Node* pPre = NULL;
		int i = 1;
		while(pIns != NULL){
			if(i == vitri){
				break;
			}
			pPre = pIns;
			pIns = pIns->pNext;
			i++;
		} 
		pNode->pNext = pIns;
		pPre->pNext = pNode;
	}
	traverse();
}
// Ham xoa hoc phan
void SingleList::XoaHocPhan(string name){
	Node* pDel = pHead;
	if(pDel == NULL){
		cout << "Danh sach rong!" << endl;
	}
	else{
		Node* pPre = NULL;
		while(pDel != NULL){
			if(pDel->data.getTenHocPhan() == name || pDel->data.getHocPhan() == name){
				break;
			}
			pPre = pDel;
			pDel = pDel->pNext;
		}
		if(pDel == NULL){
			cout << "Khong tim thay hoc phan!" << endl;
		}
		else{
			if(pDel == pHead){
				pHead = pHead->pNext;
				pDel->pNext = NULL;
				delete pDel;
				pDel = NULL;
			}
			else{
				pPre->pNext = pDel->pNext;
				pDel->pNext = NULL;
				delete pDel;
				pDel = NULL;
			}
		}
	}
	cout << "============================================================================================/ DANH SACH HOC PHAN /=================================================================================================";
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";	
	cout << left << setw(4) << "|" << setw(6) << "STT" << setw(10) << "|" << setw(17) << "HOC PHAN" << setw(20) << "|" << setw(31) << "TEN HOC PHAN" << setw(6) << "|" << setw(20) << "DIEM QUA TRINH" << setw(8) << "|" << setw(15) << "DIEM THI" << setw(8) << "|" << setw(16) << "DIEM TONG" << setw(8) << "|" << setw(17) << "SO TIN CHI" << setw(9) << "|" << setw(15) << "GHI CHU" << "|";
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
	traverse();
}
void SingleList::Menu(){
	int x, t, vitri;
	string name;
	TinChi data2;
	TinChi b[10];
	// Doc file class TinChi
	ifstream file("DocFile.txt", ios::in);
	int n;
	file >> n;
	char ss[5];
	file.getline(ss, 3);
	for(int i = 1; i <= n; i++){
		b[i].doc(file);
		addLast(b[i]);
	}
	cout << endl;
	// Ghi file class TinChi
	ofstream file2 ("GhiFile.txt");
	file2 << "============================================================================================/ DANH SACH HOC PHAN /=================================================================================================" << endl;
	file2 << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	file2 << left << setw(4) << "|" << setw(6) << "STT" << setw(10) << "|" << setw(17) << "HOC PHAN" << setw(20) << "|" << setw(31) << "TEN HOC PHAN" << setw(6) << "|" << setw(20) << "DIEM QUA TRINH" << setw(8) << "|" << setw(15) << "DIEM THI" << setw(8) << "|" << setw(16) << "DIEM TONG" << setw(8) << "|" << setw(17) << "SO TIN CHI" << setw(9) << "|" << setw(15) << "GHI CHU" << "|" << endl;
	file2 << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	int j = 0;
	for(int i = 1; i <= n; i++){
		file2 << left << setw(5) << "|" << setw(5) << j;
		b[i].ghi(file2);
		j++;
	}
	file2.close();
	file.close();
	// Doc file class Sinh Vien
	ifstream ifs("SinhVien.txt", ios::in);			
	docFile(ifs);
	ifs.close();
	do{
		system("cls");
		cout<<"\t\t\t\t\t\t\t==================================Chuong trinh quan ly Hoc Phan==============================";
		cout<<"\n\t\t\t\t\t\t\t**\n\t\t\t\t\t\t\t**\t\t\t 1.Xem danh sach hoc phan.                                         **";
		cout<<"\n\t\t\t\t\t\t\t**\n\t\t\t\t\t\t\t**\t\t\t 2.Them hoc phan vao cuoi.                                         **";
		cout<<"\n\t\t\t\t\t\t\t**\n\t\t\t\t\t\t\t**\t\t\t 3.Them hoc phan vao vi tri bat ky.                                **";
		cout<<"\n\t\t\t\t\t\t\t**\n\t\t\t\t\t\t\t**\t\t\t 4.Xoa hoc phan.                                                   **";
		cout<<"\n\t\t\t\t\t\t\t**\n\t\t\t\t\t\t\t**\t\t\t 5.Tim kiem hoc phan.                                              **";
		cout<<"\n\t\t\t\t\t\t\t**\n\t\t\t\t\t\t\t**\t\t\t 6.Sap xep theo ten hoc phan.                                      **";
		cout<<"\n\t\t\t\t\t\t\t**\n\t\t\t\t\t\t\t**\t\t\t 7.Sap xep theo diem tong.                                         **";
		cout<<"\n\t\t\t\t\t\t\t**\n\t\t\t\t\t\t\t**\t\t\t 8.Sap xep theo diem diem qua trinh.                               **";
		cout<<"\n\t\t\t\t\t\t\t**\n\t\t\t\t\t\t\t**\t\t\t 9.Sap xep theo diem thi.                                          **";
		cout<<"\n\t\t\t\t\t\t\t**\n\t\t\t\t\t\t\t**\t\t\t 10.Hoc phan co diem tong cao nhat, thap nhat.                     **";
		cout<<"\n\t\t\t\t\t\t\t**\n\t\t\t\t\t\t\t**\t\t\t 11.Hoc phan Dat , Chua Dat.                                       **";
		cout<<"\n\t\t\t\t\t\t\t**\n\t\t\t\t\t\t\t**\t\t\t 12.Tong ket.                                                      **";
		cout<<"\n\t\t\t\t\t\t\t**\n\t\t\t\t\t\t\t**\t\t\t 0.Thoat.                                                          **";
		cout<<"\n\t\t\t\t\t\t\t_____________________________________________________________________________________________";
		cout<<"\n\n\t\t\t\t\t\t\tMoi ban nhap lua chon: ";
		cin>>x;
		if(x==0)
		{
			t=0;
		}
		while(x>0 && x<13)
		{
			switch (x)
			{
				case 1:
					system("cls");
					cout << "============================================================================================/ DANH SACH HOC PHAN /=================================================================================================";
					cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";	
					cout << left << setw(4) << "|" << setw(6) << "STT" << setw(10) << "|" << setw(17) << "HOC PHAN" << setw(20) << "|" << setw(31) << "TEN HOC PHAN" << setw(6) << "|" << setw(20) << "DIEM QUA TRINH" << setw(8) << "|" << setw(15) << "DIEM THI" << setw(8) << "|" << setw(16) << "DIEM TONG" << setw(8) << "|" << setw(17) << "SO TIN CHI" << setw(9) << "|" << setw(15) << "GHI CHU" << "|";
					cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
					traverse();
					system("pause");
					break;
				case 2:	
					system("cls");
					cout << "Nhap mon hoc can them:" << endl;
					cin >> data2;
					cout << "============================================================================================/ DANH SACH HOC PHAN /=================================================================================================";
					cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";	
					cout << left << setw(4) << "|" << setw(6) << "STT" << setw(10) << "|" << setw(17) << "HOC PHAN" << setw(20) << "|" << setw(31) << "TEN HOC PHAN" << setw(6) << "|" << setw(20) << "DIEM QUA TRINH" << setw(8) << "|" << setw(15) << "DIEM THI" << setw(8) << "|" << setw(16) << "DIEM TONG" << setw(8) << "|" << setw(17) << "SO TIN CHI" << setw(9) << "|" << setw(15) << "GHI CHU" << "|";
					cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
					ThemCuoi(data2);
					system("pause");
					break;
				case 3:	
					system("cls");
				
					cout << "Nhap mon hoc can them: " << endl;
					cin >> data2;
					cout << "Nhap vi tri can them: ";	
					cin >> vitri;
					cout << "============================================================================================/ DANH SACH HOC PHAN /=================================================================================================";
					cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";	
					cout << left << setw(4) << "|" << setw(6) << "STT" << setw(10) << "|" << setw(17) << "HOC PHAN" << setw(20) << "|" << setw(31) << "TEN HOC PHAN" << setw(6) << "|" << setw(20) << "DIEM QUA TRINH" << setw(8) << "|" << setw(15) << "DIEM THI" << setw(8) << "|" << setw(16) << "DIEM TONG" << setw(8) << "|" << setw(17) << "SO TIN CHI" << setw(9) << "|" << setw(15) << "GHI CHU" << "|";
					cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
					ThemHocPhan(data2,vitri);
					system("pause");
					break;
				case 4:
					system("cls");
					cout << "Nhap ten hoc phan muon xoa: ";
					fflush(stdin);
					getline(cin,name);
					XoaHocPhan(name);
					system("pause");
					system("pause");
					break;
				case 5:
					system("cls");
					SearchByHocPhan();
					system("pause");
					break;
				case 6:
					system("cls");
					cout << "============================================================================================/ DANH SACH HOC PHAN /=================================================================================================";
					cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";	
					cout << left << setw(4) << "|" << setw(6) << "STT" << setw(10) << "|" << setw(17) << "HOC PHAN" << setw(20) << "|" << setw(31) << "TEN HOC PHAN" << setw(6) << "|" << setw(20) << "DIEM QUA TRINH" << setw(8) << "|" << setw(15) << "DIEM THI" << setw(8) << "|" << setw(16) << "DIEM TONG" << setw(8) << "|" << setw(17) << "SO TIN CHI" << setw(9) << "|" << setw(15) << "GHI CHU" << "|";
					cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
					SortByTenHocPhan();
					system("pause");
					break;
				case 7:
					system("cls");
					cout << "============================================================================================/ DANH SACH HOC PHAN /=================================================================================================";
					cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";	
					cout << left << setw(4) << "|" << setw(6) << "STT" << setw(10) << "|" << setw(17) << "HOC PHAN" << setw(20) << "|" << setw(31) << "TEN HOC PHAN" << setw(6) << "|" << setw(20) << "DIEM QUA TRINH" << setw(8) << "|" << setw(15) << "DIEM THI" << setw(8) << "|" << setw(16) << "DIEM TONG" << setw(8) << "|" << setw(17) << "SO TIN CHI" << setw(9) << "|" << setw(15) << "GHI CHU" << "|";
					cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
					SortByDiemTong();
					system("pause");
					break;
				case 8:
					system("cls");
					cout << "============================================================================================/ DANH SACH HOC PHAN /=================================================================================================";
					cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";	
					cout << left << setw(4) << "|" << setw(6) << "STT" << setw(10) << "|" << setw(17) << "HOC PHAN" << setw(20) << "|" << setw(31) << "TEN HOC PHAN" << setw(6) << "|" << setw(20) << "DIEM QUA TRINH" << setw(8) << "|" << setw(15) << "DIEM THI" << setw(8) << "|" << setw(16) << "DIEM TONG" << setw(8) << "|" << setw(17) << "SO TIN CHI" << setw(9) << "|" << setw(15) << "GHI CHU" << "|";
					cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
					SortByDiemQuaTrinh();
					system("pause");
					break;
				case 9:
					system("cls");
					cout << "============================================================================================/ DANH SACH HOC PHAN /=================================================================================================";
					cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";	
					cout << left << setw(4) << "|" << setw(6) << "STT" << setw(10) << "|" << setw(17) << "HOC PHAN" << setw(20) << "|" << setw(31) << "TEN HOC PHAN" << setw(6) << "|" << setw(20) << "DIEM QUA TRINH" << setw(8) << "|" << setw(15) << "DIEM THI" << setw(8) << "|" << setw(16) << "DIEM TONG" << setw(8) << "|" << setw(17) << "SO TIN CHI" << setw(9) << "|" << setw(15) << "GHI CHU" << "|";
					cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
					SortByDiemThi();
					system("pause");
					break;
				case 10:
					system("cls");
					cout << endl;
					inMaxDiemTong();
					cout << endl;
					cout << endl;
					cout << right << setw(102) << "<><><><><><>" << endl;
					cout << endl;
					inMinDiemTong();
					cout << endl;
					system("pause");
					break;
				case 11:
					system("cls");
					cout << left << setw(85) << "`" << "------------------------------------";
					cout << endl << left << setw(85) << "`" << setw(3) << "|" << "So luong hoc phan da dat la  " << setw(3)  << SoMonDat() << "|" << endl;
					cout << left << setw(85) << "`" << "------------------------------------" << endl;
					MonDat();
					cout << left << setw(80) << "`" << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl; 
					cout << endl << left << setw(80) << "`" << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl; 
					cout << left << setw(85) << "`" << "--------------------------------------";
					cout << endl << left << setw(85) << "`" << setw(3) << "|" << "So luong hoc phan chua dat la  " << setw(3)  << SoMonChuaDat() << "|" << endl;
					cout << left << setw(85) << "`" << "--------------------------------------" << endl;
					MonChuaDat(); 
					system("pause");
					break;
				case 12:
					system("cls");
					cout << left << setw(61) << "*" << setw(149) << "-------------------------------------------------------------------------------------" << "*";
					cout << left << setw(61) << "*" << setw(149) << "|***********************************************************************************|" << "*";
					cout << left << setw(61) << "*" << setw(78) << "|******" << setw(71) << "******|" << "*";
					cout << left << setw(61) << "*" << setw(79) << "|*****" << setw(70) << "*****|" << "*";
					cout << left << setw(61) << "*" << setw(80) << "|****" << setw(69) << "****|" << "*";
					cout << left << setw(61) << "*" << setw(81) << "|***" << setw(68) << "***|" << "*";
					cout << left << setw(61) << "*" << setw(82) << "|**" << setw(67) << "**|" << "*";
					cout << left << setw(61) << "*" << setw(83) << "|*" << setw(66) << "*|" << "*";
					cout << left << setw(61) << "*" << setw(29) << "|*" << setw(10) <<"Ho ve ten" << ": " << setw(42) << getHoTen() << setw(66) << "*|" << "*";
					cout << left << setw(61) << "*" << setw(29) << "|*" << setw(10) << "MSSV" << ": " << setw(42) << getMSSV() << setw(66) << "*|" << "*";
					cout << left << setw(61) << "*" << setw(29) << "|*" << setw(10) << "Lop" << ": " << setw(42) << getLop() << setw(66) << "*|" << "*";
					cout << left << setw(61) << "*" << setw(29) << "|*" << setw(10) << "DTB" << ": " << setw(42) << setprecision(2) << DiemTrungBinh() << setw(66) << "*|" << "*";
					cout << left << setw(61) << "*" << setw(29) << "|*" << setw(10) << "Xep loai" << ": " << setw(42) << XepLoai() << setw(66) << "*|" << "*";	
					cout << left << setw(61) << "*" << setw(83) << "|*" << setw(66) << "*|" << "*";	
					cout << left << setw(61) << "*" << setw(82) << "|**" << setw(67) << "**|" << "*";	
					cout << left << setw(61) << "*" << setw(81) << "|***" << setw(68) << "***|" << "*";
					cout << left << setw(61) << "*" << setw(80) << "|****" << setw(69) << "****|" << "*";	
					cout << left << setw(61) << "*" << setw(79) << "|*****" << setw(70) << "*****|" << "*";
					cout << left << setw(61) << "*" << setw(78) << "|******" << setw(71) << "******|" << "*";
					cout << setw(61) << "*" << setw(149) << "|***********************************************************************************|" << "*";
					cout << left << setw(61) << "*" << setw(3) << "|" << "So tin chi tich luy: " << setw(60) << SoTinChiTichLuy() << setw(65) << "|" << "*";
					cout << setw(61) << "*" << setw(149) << "-------------------------------------------------------------------------------------" << "*" << endl;
					system("pause");
				case 0:
					break;
			}
			x=0;t=-1;
		}
	}
	while(t!=0);
	system("pause");
}

int main(){
	SingleList a;	
	a.Menu();
	return 0;
} 