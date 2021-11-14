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
