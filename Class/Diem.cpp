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
	cout << "Nhap diem qua trinh: ";
	is >> ds.DiemQuaTrinh;
	cout << "Nhap diem thi: ";
	is >> ds.DiemThi;
	ds.DiemTong = (float)(ds.DiemQuaTrinh + ds.DiemThi) / 2;
	return is;
}
