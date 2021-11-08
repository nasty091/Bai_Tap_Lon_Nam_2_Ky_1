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
		void ThangDiemChu();
		void GhiChu();
		friend istream& operator >> (istream& is, Diem& ds);
};
Diem::Diem(){
	DiemQuaTrinh = 0;
	DiemThi = 0;
	DiemTong = 0;
}
Diem::Diem(float DiemQuaTrinh, float DiemThi, float DiemTong){
	this->DiemQuaTrinh = DiemQuaTrinh;
	this->DiemThi = DiemThi;
	this->DiemTong = DiemTong;
}
Diem::~Diem(){
	
}
void Diem::setDiemQuaTrinh(float DiemQuaTrinh){
	this->DiemQuaTrinh = DiemQuaTrinh;
}
float Diem::getDiemQuaTrinh(){
	return DiemQuaTrinh;
}
void Diem::setDiemThi(float DiemThi){
	this->DiemThi = DiemThi;
}
float Diem::getDiemThi(){
	return DiemThi;
}
void Diem::setDiemTong(float DiemTong){
	this->DiemTong = DiemTong;
}
float Diem::getDiemTong(){
	return DiemTong;
}
void Diem::ThangDiemChu(){
	if(DiemTong >=0 && DiemTong <=1.9){
		cout<<"F";
	}else if(DiemTong >=2 && DiemTong <=3.9){
		cout<<"F+";
	}else if(DiemTong >=4 && DiemTong <=4.4){
		cout<<"D";
	}else if(DiemTong >=4.5 && DiemTong <=5.4){
		cout<<"D+";
	}else if(DiemTong >=5.5 && DiemTong <=5.9){
		cout<<"C";
	}else if(DiemTong >=6 && DiemTong <=6.9){
		cout<<"C+";
	}else if(DiemTong >=7 && DiemTong <=7.9){
		cout<<"B";
	}else if(DiemTong >=8 && DiemTong <=8.4){
		cout<<"B+";
	}else if(DiemTong >=8.5 && DiemTong <=9.4){
		cout<<"A";
	}else if(DiemTong >=9.5 && DiemTong <=10){
		cout<<"A+";
	}
}
void Diem::GhiChu(){
	if(DiemTong < 4){
		cout << "KHONG DAT";
	}else{
		cout << "DAT";
	}
}
istream& operator >> (istream& is, Diem& ds){
	MonHoc *a = static_cast <MonHoc *> (&ds);
	is >> *a;
	fflush(stdin);
	cout << "Nhap diem qua trinh: ";
	is >> ds.DiemQuaTrinh;
	cout << "Nhap diem thi: ";
	is >> ds.DiemThi;
	ds.DiemTong = (float)(ds.DiemQuaTrinh + ds.DiemThi) / 2;
	return is;
}
