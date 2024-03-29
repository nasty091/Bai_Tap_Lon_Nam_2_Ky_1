SingleList::SingleList(){
	pHead = NULL;
	pTail = NULL;
	size = 0;
}
SingleList::~SingleList(){
	
}
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
void SingleList::traverse(){
	Node* temp = pHead;
	while(temp != NULL){
		cout << temp->data;
		temp = temp->pNext;
	}
}
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
void SingleList::Swap(TinChi& source1, TinChi& source2){
	TinChi t = source1;
	source1 = source2;
	source2 = t;
}
void SingleList::findMaxDiemTong(){
	Node* temp = pHead;
	float max;
	string name;
	while(temp != NULL){
		if(temp->data.getDiemTong() > max){
			max = temp->data.getDiemTong();
			name = temp->data.getTenHocPhan();
		}
		temp = temp->pNext;
	}
	cout << "Hoc phan " << name <<  " co diem tong cao nhat la: " << max << endl;
}
void SingleList::findMinDiemTong(){
	Node* temp = pHead;
	float min;
	string name;
	while(temp != NULL){
		if(temp->data.getDiemTong() < min){
			min = temp->data.getDiemTong();
			name = temp->data.getTenHocPhan();
		}
		temp = temp->pNext;
	}
	cout << "Hoc phan " << name <<  " co diem tong thap nhat: " << min << endl;
}
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
void SingleList::MonDat(){
	Node* temp = pHead;
	string name;
	while(temp != NULL){
		if(temp->data.getDiemTong() >= 4){
			cout << temp->data.getTenHocPhan() << ": " << temp->data.getSoTinChi() << " tin chi" << endl;
		}
		temp = temp->pNext;
	}
}
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
void SingleList::MonChuaDat(){
	Node* temp = pHead;
	string name;
	while(temp != NULL){
		if(temp->data.getDiemTong() < 4){
			cout << temp->data.getTenHocPhan() << ": " << temp->data.getSoTinChi() << " tin chi" << endl;
		}
		temp = temp->pNext;
	}
}
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
void SingleList::SearchByHocPhan(){
	Node* temp = pHead;
	Node* temp2 = NULL;
	string name;
	cout << "Nhap hoc phan can tim kiem: ";
	fflush(stdin);
	getline(cin,name);
	while(temp != NULL){
		if(temp->data.getHocPhan() == name){
			cout << "Hoc phan: " << temp->data.getHocPhan() << endl;
			cout << "Ten hoc phan :" << temp->data.getTenHocPhan() << endl;
			cout << "Diem qua trinh: " << temp->data.getDiemQuaTrinh() << endl;
			cout << "Diem thi: " << temp->data.getDiemThi() << endl;
			cout << "Diem Tong: " << temp->data.getDiemTong() << endl;
			cout << "So tin chi: " << temp->data.getSoTinChi() << endl;
			if(temp->data.getDiemTong() < 4){
				cout << "Ghi chu: CHUA DAT" << endl;
			}
			else{
				cout << "Ghi chu: DAT" << endl;
			}
			temp2 = temp;
		}
		temp = temp->pNext;
	}
	if(temp2 == NULL){
		cout << "Khong tim thay hoc phan!" << endl;
	}
}
int SingleList::List_Size(){
	Node* temp = pHead;
	int size = 0;
	while(temp != NULL){
		temp = temp->pNext;
		size++;
	}
	return size;
}
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
void SingleList::ThemCuoi(TinChi& source){
	Node* pNode = new Node(source);
	if(pHead == NULL){
		pHead = pNode;
}
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
	traverse();
}
