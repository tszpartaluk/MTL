#ifndef _MTL_LIST_H_
#define _MTL_LIST_H_

#include <cassert>
#include "listnode.hpp"

namespace MTL {

	template<class T>
	class List {
	public:

		List() : nodeCount(0), currentIndex(0), currentNode(0) {};
		virtual ~List();

		//List<T>& push_front(const T&);
		//List<T>& push_back(const T&);

		List<T>& insert(const T&);
		List<T>& insert(const size_t&, const T&);

		List<T>& erase(const size_t&);

		size_t size() { return nodeCount; };

		// acces
		T& operator[](const size_t&);

	private:

		size_t nodeCount;
		size_t currentIndex;
		ListNode<T>* firstNode;

	};


	template<class T>
	List<T>::~List() {
		// go through all nodes and destruct them
		for (size_t i = 0; i < nodeCount; i++)
		{
			// get pointer to next node
			ListNode<T>* next = firstNode->next();
			assert(firstNode != 0);
			// delete
			delete firstNode;
		}
	};



	template<class T>
	inline List<T>& List<T>::insert(const size_t &i,const T& obj)
	{

		ListNode<T> * el = firstNode;
		// go to preceding element
		for (size_t ind = 0; ind < i - 1; ind++)
		{
			el = el->next();
		}
		// jump two elements and set connection
		el->setNext(el->next()->next());

		// look at marked element and delete him
		el = el->next();
		delete el;
	}

	template<class T>
	inline List<T>& List<T>::erase(const size_t &i)
	{
		
		ListNode<T> * el = firstNode;
		// go to preceding element
		for (size_t ind = 0; ind < i-1; ind++)
		{
			el = el->next();
		}
		// jump two elements and set connection
		el->setNext(el->next()->next());

		// look at marked element and delete him
		el = el->next();
		delete el;
	}

	template<class T>
	T& List<T>::operator[](const size_t& i) {

		// go to desired position
		ListNode<T>* node = firstNode;
		for (size_t ind = 0; ind < i; ind++)
		{
			node = node->next();
		}

		return node->getVal();

	};





}


#endif // !_MTL_LIST_H_