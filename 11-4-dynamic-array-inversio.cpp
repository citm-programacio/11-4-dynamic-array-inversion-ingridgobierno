#include <iostream>
#include <string>
using namespace std;

class ArrayDinamica {
private:
	int size = 0;
	int capacity;
	int* array;
public:
	ArrayDinamica() {
		size = 10;
		array = new int[capacity];
	}
	ArrayDinamica(int cap) {
		capacity = cap;
		array = new int[capacity];
	}

	void insert(int newElement, int position) {
		if (capacity <= size) {//si la capacitat es igual o menor als elements que hi ha a la array 
			capacity *= 2; //la capacitat es duplica
		}
		int* newArray = new int[capacity]; //crea nova array amb la capacitat
		size++; //amplia el nombre d'elements +1
		int i; // crear variavle de iteració
		for (i = 0; i < position; i++) { //fas for, per anar fins la position
			newArray[i] = array[i];
		}
		newArray[i] = newElement; //insertem el new element a la posició d'i.
		i++; //passem a la seguent posició, s'han avançat dues posicions contant l'ultima.
		while (i < size) {
			newArray[i] = array[i - 1];
			i++;
		}
		delete[] array;
		array = newArray;
		
	}
	void invert(){
		int* newArray = new int[capacity];
		int j = 0;
		for (int i = size; i >= 0; i--) {
			newArray[j] = array[i-1];
			j++;
		}
	
		delete[] array;
		array = newArray;
	}
	void print() {
		cout << "{";
		for (int i = 0; i < size; i++) {
			cout << array[i] << ", ";
		}
		cout << "}" << endl;
	}
};


int main()
{
	ArrayDinamica a(10);
	a.insert(1, 0);
	a.insert(2, 1);
	a.insert(3, 2);
	a.insert(4, 3);
	a.insert(5, 4);
	a.insert(6, 5);
	a.insert(7, 6);
	a.print();
	
	a.invert();
	a.print();


}


