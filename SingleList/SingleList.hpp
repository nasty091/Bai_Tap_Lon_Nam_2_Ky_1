class Node{
	public:
		TinChi data;
		Node *pNext;
		Node(TinChi data){
			this->data = data;
			pNext = NULL;
		}
};
class SingleList{
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
		void findMaxDiemTong();
		void findMinDiemTong();
		float DiemTrungBinh();
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
};
int main(){
	int x,t;
	
	do{
		system("cls");
		cout<<"==================================Chuong trinh quan ly Hoc Phan==============================";
		cout<<"\n**\n**\t\t\t 1.Xuat danh sach hoc phan.                                        **";
		cout<<"\n**\n**\t\t\t 2.Them 1 Hoc Phan vao cuoi danh sach.                             **";
		cout<<"\n**\n**\t\t\t 3.Them 1 Hoc Phan vao vi tri bat ki.                              **";
		cout<<"\n**\n**\t\t\t 4.Xoa hoc phan.                                                   **";
		cout<<"\n**\n**\t\t\t 5.Tim kiem Hoc Phan.                                              **";
		cout<<"\n**\n**\t\t\t 6.Sap Xep Theo Ten.                                               **";
		cout<<"\n**\n**\t\t\t 7.Sap Xep theo diem tong.                                         **";
		cout<<"\n**\n**\t\t\t 8.Sap xep theo diem diem qua trinh.                               **";
		cout<<"\n**\n**\t\t\t 9.Sap xep theo diem thi.                                          **";
		cout<<"\n**\n**\t\t\t 10.Hoc Phan co diem tong cao nhat.                                **";
		cout<<"\n**\n**\t\t\t 11.Hoc Phan co diem tong thap nhat.                               **";
		cout<<"\n**\n**\t\t\t 12.Hoc phan Dat , Chua Dat.                                       **";
		cout<<"\n**\n**\t\t\t 14.Tong ket.                                                      **";
		cout<<"\n**\n**\t\t\t 15.Xuat hoc phan ra file.                                         **";
		cout<<"\n**\n**\t\t\t 0.Thoat.                                                          **";
		cout<<"\n_____________________________________________________________________________________________";
		cout<<"\n\nMoi ban nhap lua chon: ";
		cin>>x;
		if(x==0)
		{
			t=0;
		}
		while(x>0 && x<15)
		{
			switch (x)
			{
				case 1:
					system("cls");
					
					system("pause");
					break;
				case 2:	
					system("cls");
					
					system("pause");
					break;	
				case 3:	
					system("cls");
					
					system("pause");
					break;	
				case 4:	
					system("cls");
					
					system("pause");
					break;
				case 5:	
					system("cls");
					
					system("pause");
					break;
				case 6:	
					system("cls");
					
					system("pause");
					break;
				case 7:	
					system("cls");
					
					system("pause");
					break;
				case 8:	
					system("cls");
					
					system("pause");
					break;
				case 9:	
					system("cls");
					
					system("pause");
					break;
				case 10:	
					system("cls");
					
					system("pause");
					break;
				case 11:	
					system("cls");
					
					system("pause");
					break;
				case 12:	
					system("cls");
					
					system("pause");
					break;
				case 13:	
					system("cls");
					
					system("pause");
					break;
				case 14:	
					system("cls");
					
					system("pause");
					break;
				case 15:	
					system("cls");
					
					system("pause");
					break;
				case 0:
					break;
			}
			x=0;t=-1;
		}
	}
	while(t!=0);
	system("pause");
	return 0;
}
