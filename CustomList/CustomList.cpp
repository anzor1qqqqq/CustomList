﻿#include <iostream>

using namespace std;

template <typename T>
struct Node {
	Node<T> *nextElem;
	T elem;

	Node(T elemParam = T(), Node<T>* nextElemParam = nullptr) {
		this->nextElem = nextElemParam;
		this->elem = elemParam;
	};
};

template <typename T>
class CustomList {
private:

	Node<T> *listNode;
	int sizeList;

public:

	CustomList() {
		this->listNode = nullptr;
		this->sizeList = 0;
	};

	CustomList(const CustomList& other) {
		this->listNode = other->listNode;
		this->sizeList = other->sizeList;
	};

	void addElem(T elem) {
		if (this->listNode == nullptr) {
			listNode = new Node<T>(elem);
		} else {
			Node<T>* current = this->listNode;

			while (current->nextElem != nullptr) {
				current = current->nextElem;
			};

			current->nextElem = new Node<T>(elem);
		};

		this->sizeList++;
	};

	void addElemFront(T newElem) {
		Node<T>* newFrontNode = new Node<T>(newElem, this->listNode);

		this->listNode = newFrontNode;

		this->sizeList++;
	};

	void addElemIndex(T newElem, int index) {
		if (this->sizeList == 0) {
			this->addElem(newElem);
		} else if (index == 0) {
			this->addElemFront(newElem);
		} else if (this->sizeList >= index) {
			Node<T>* current = this->listNode;

			for (int i = 0; i < index - 1; i++) {
				current = current->nextElem;
			};

			current->nextElem = new Node<T>(newElem, current->nextElem);

			this->sizeList++;
		} else {
			abort();
		};
	};

	void removeElemFront() {
		if (this->sizeList != 0) {
			this->listNode = this->listNode->nextElem;

			this->sizeList--;
		} else {
			abort();
		};
	};

	void removeElemIndex(int index) {
		if (index == 0) {
			this->removeElemFront();
		} else if (this->sizeList > index) {
			Node<T>* current = this->listNode;

			for (int i = 0; i < index - 1; i++) {
				current = current->nextElem;
			};

			current->nextElem = current->nextElem->nextElem;

			this->sizeList--;
		} else {
			abort();
		};
	};

	T getElemIndex(int index) {
		if (this->sizeList >= index - 1) {
			Node<T>* current = this->listNode;

			for (int i = 0; i < index; i++) {
				current = current->nextElem;
			};

			return current->elem;
		};

		abort();
	};

	~CustomList() {
		delete listNode;
	};
}; 

int main() {
	CustomList<int> firstList;

	firstList.addElem(1);
	firstList.addElem(2);
	firstList.addElem(3);

	cout << firstList.getElemIndex(0) << ' ';

	cout << firstList.getElemIndex(1) << ' ';

	cout << firstList.getElemIndex(2) << ' ';

	firstList.addElemIndex(15, 0);

	firstList.removeElemIndex(0);
};