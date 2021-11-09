#include<iostream>
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
};
TinChi::TinChi(){
	SoTinChi = 0;
}
TinChi::TinChi(int SoTinChi){
	this->SoTinChi = SoTinChi;
}
TinChi::~TinChi(){
	
}
void TinChi::setSoTinChi(int SoTinChi){
	this->SoTinChi = SoTinChi;
}
int TinChi::getSoTinChi(){
	return SoTinChi;
}
istream& operator >> (istream& is, TinChi& tc){
	Diem *a = static_cast <Diem *> (&tc);
	fflush(stdin);
	is >> *a;
	cout << "Nhap so tin chi: ";
	is >> tc.SoTinChi;
	return is;
}
ostream& operator << (ostream& os, TinChi& tc){
	if(tc.getDiemTong() < 4){
		os << tc.getHocPhan() << "\t" << tc.getTenHocPhan() << "\t" << tc.getDiemQuaTrinh() << "\t" << tc.getDiemThi()<< "\t" << tc.getDiemTong() << "\t" << tc.SoTinChi << "\t" << "CHUA DAT" << endl;
	}
	else{
		os << tc.getHocPhan() << "\t" << tc.getTenHocPhan() << "\t" << tc.getDiemQuaTrinh() << "\t" << tc.getDiemThi()<< "\t" << tc.getDiemTong() << "\t" << tc.SoTinChi << "\t" << "DAT" << endl;
	}
	return os;
}
