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
		void doc(ifstream&);
		void ghi(ofstream&);
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
	int f;
	cout << "Nhap so tin chi: ";
	is >> f;
	tc.setSoTinChi(f);
	return is;
}
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
void TinChi::doc(ifstream& is){
	Diem::doc(is);
	fflush(stdin);
	int f;
	is >> f;
	char ss[5];
	is.getline(ss, 3);
	setSoTinChi(f);
}
