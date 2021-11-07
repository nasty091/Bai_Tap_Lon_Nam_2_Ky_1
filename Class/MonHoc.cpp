#include <iostream>

using namespace std;

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
	cout << "Nhap hoc phan: ";
	getline(is, hp.HocPhan);
	cout << "Nhap ten hoc phan: ";
	getline(is, hp.TenHocPhan);
	return is;
}