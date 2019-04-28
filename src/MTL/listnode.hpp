#ifndef _MTL_LISTNODE_H_
#define _MTL_LISTNODE_H_


namespace MTL {


	template<class T>
	class ListNode {

	public:

		ListNode(const T& obj) : value(obj), nextptr(0) {};
		//ListNode() :value(), nextptr(0) {};
		virtual ~ListNode();

		T& getVal() { return value; };
		ListNode<T>* next() { return nextptr; };
		void setNext(ListNode<T>&);
		void setNext(ListNode<T>*);
	protected:

		
	private:
		//friend class List;
		ListNode<T>* nextptr;
		T value;
	};



	template<class T>
	ListNode<T>::~ListNode() {
		delete nextptr;
	}

	template<class T>
	void ListNode<T>::setNext(ListNode<T>& obj) {
		nextptr = &obj;
	};

	template<class T>
	void ListNode<T>::setNext(ListNode<T>* obj) {
		nextptr = obj;
	};
}


#endif // !_MTL_LISTNODE_H_
