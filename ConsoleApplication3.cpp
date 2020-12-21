// ConsoleApplication3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <list>
using namespace std;

template <class T>
class Node
{
public:
	T data; // хранимые данные элемента
	Node* sled, * pred; // указатели на соседние элементы
};

template <class T>
class List 
{
	Node<T>* head, * khvost; // указатели на крайние элементы
	int number; // количество элементов в листе
public:
	List() : head(NULL), khvost(NULL), number(0) {};
	~List();

	void Add(T data); // добавление элемента в конец списка
	void Delete(); // удаление элемента из конца списка
	void Show(); // получение данных из списка
	
	bool operator == (const List<T>&); //перегрузка оператора ==

	//перегрузка оператора вывода
	friend ostream& operator<<(ostream& os, const List<T>& List)
	{
		Node<T>* temp = List.head;
		while (temp != NULL)
		{
			os << temp->data << " ";
			temp = temp->sled;
		}
		os << endl;
		return os;
	}
};

template <class T>
List<T>::~List()
{
	while (head)
	{
		khvost = head->sled;
		delete head;
		head = khvost;
	}
}

template <class T>
void List<T>::Show()
{
	Node<T>* temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->sled;
	}
	cout << "\n";
}

template <class T>
void List<T>::Add(T data)
{
	Node<T>* temp = new Node<T>;
	temp->sled = NULL;
	temp->data = data;

	if (head != NULL)
	{
		temp->pred = khvost;
		khvost->sled = temp;
		khvost = temp;
	}
	else
	{
		temp->pred = NULL;
		head = khvost = temp;
	}
	number++;
}

template <class T>
void List<T>::Delete()
{
	Node<T>* temp = khvost;
	khvost = khvost->pred;
	khvost->sled = NULL;
	number--;
	delete temp;
}

template <class T>
bool List<T>::operator == (const List<T>& List)
{
	if (number != List.number)
	{
		return false;
	}

	Node<T>* el_one, * el_two;
	el_one = head;
	el_two = List.head;

	while (el_one != NULL)
	{
		if (el_one->data != el_two->data)
		{
			return false;
		}

		el_one = el_one->sled;
		el_two = el_two->sled;
	}

	return true;
}

void read(int& size)
{
	bool corrects = true;
	while (corrects) {
		while (!(cin >> size))
		{
			cout << "Данные введены неверно! Введите ещё раз\n";

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if (size > 1) {
			corrects = false;
		}
		else {
			cout << "Меньше 2 элементов нельзя. Введите ещё раз\n";
		}
	}

}

template <class T>
void elem(List<T>& List, int size) {
	int element;
	while (size > 0)
	{
		cout << "Элемент: ";
		cin >> element;
		List.Add(element);
		size--;
	}
}

template <class T>
void ravny(List<T>& firstList, List<T>& secondList)
{
	if (firstList == secondList)
	{
		cout << "Списки равны" << endl;
	}
	else
	{
		cout << "Списки неравны" << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	List<int> first;
	List<int> second;

	int size_one = 0, size_two = 0;

	cout << "Количество элементов 1 списка: ";
	read(size_one);
	elem(first, size_one);

	cout << "Количество элементов 2 списка: ";
	read(size_two);
	elem(second, size_two);

	first.Show();
	second.Show();
	
	ravny(first, second);

	first.Delete();
	second.Delete();

}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
