#include <iostream>

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
MonHoc::MonHoc(){
	HocPhan = "";
	TenHocPhan = "";
}
MonHoc::MonHoc(string HocPhan, string TenHocPhan){
	this->HocPhan = HocPhan;
	this->TenHocPhan = TenHocPhan;
}
MonHoc::~MonHoc(){
	
}
void MonHoc::setHocPhan(string HocPhan){
	this->HocPhan = HocPhan;
}
string MonHoc::getHocPhan(){
	return HocPhan;
}
void MonHoc::setTenHocPhan(string TenHocPhan){
	this->TenHocPhan = TenHocPhan;
}
string MonHoc::getTenHocPhan(){
	return TenHocPhan;
}
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
void MonHoc::doc(ifstream& is){
	char a[40], b[40];
	fflush(stdin);
	is.getline(a, 40);
	is.getline(b, 40);
	setHocPhan(a);
	setTenHocPhan(b);
}