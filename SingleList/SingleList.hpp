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
}