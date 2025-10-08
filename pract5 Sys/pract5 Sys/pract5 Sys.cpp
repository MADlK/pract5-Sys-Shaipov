#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
	Node(int value)
	{
		data = value;
		next = nullptr;
		prev = nullptr;
	}
};
class DoublyLinkedList
{
private:

	Node* head;
	Node* tail;

public:
	DoublyLinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}

	//добавить в начало
	void push_front(int value)
	{
		Node* newNode = new Node(value);
		if (head == nullptr)
		{
			head = tail = newNode;
		}
		else
		{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
	}

	//добавить в конец
	void push_back(int value)
	{
		Node* newNode = new Node(value);
		if (tail == nullptr)
		{
			tail = head = newNode;
		}
		else
		{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
	}

	//удалить с головы
	void pop_front()
	{
		if (head == nullptr)
		{
			cout << "Список пуст\n\n";
			return;
		}
		Node* temp = head;
		head = head->next;
		if (head != nullptr)
		{
			head->prev = nullptr;
		}
		else
		{
			tail = nullptr;
		}
		delete temp;
	}

	
	void pop_back() {
		if (tail == nullptr) {
			cout << "Список пуст\n";
			return;
		}
		Node* temp = tail;
		tail = tail->prev;

		if (tail != nullptr) {
			tail->next = nullptr;
		}
		else
		{
			head = nullptr;
		}
		delete temp;
	}

	//показать список
	void display() {
		Node* current = head;

		if (current == nullptr) {
			cout << "Список пуст\n";
			return;
		}

		cout << "Список: ";
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << "\n";
	}

	
	void sort() {
		if (head == nullptr) {
			return;
		}

		bool swapped;
		do {
			swapped = false;
			Node* current = head;

			while (current->next)
			{
				if (current->data > current->next->data) {

					int temp = current->data;
					current->data = current->next->data;
					current->next->data = temp;

					swapped = true;
				}
				current = current->next;
			}
		} while (swapped);
	}

	//удаление дубликатов
	void remove_duplicates() {
		Node* current = head;
		while (current) {
			Node* runner = current->next;

			while (runner) {
				if (runner->data == current->data) {
					Node* duplicate = runner;
					runner = runner->next;

					if (duplicate->prev) duplicate->prev->next = duplicate->next;
					if (duplicate->next) duplicate->next->prev = duplicate->prev;
					if (duplicate == tail) tail = duplicate->prev;

					delete duplicate;
				}
				else
				{
					runner = runner->next;
				}
			}
			current = current->next;
		}
	}

	//деструктор для очистки памяти
	~DoublyLinkedList() {
		while (head) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
};







int main()
{
	setlocale(00, "rus");

	DoublyLinkedList list;
	int v, value;

	do
	{
		cout << "Меню \n"
				"1. Добавить элемент в начало\n"
				"2. Добавить элемент в конец\n"
				"3. Удалить элемент c начало\n"
				"4. Удалить элемент с конца\n"
				"5. Отобразить список\n"
				"6. Сортировать список\n"
				"7. Удалить дубликаты\n"
				"8. Выйти\n\n"
				"Выберите действие: ";

		cin >> v;

		switch (v)
		{
		case 1:
			cout << "Введите значение ";
			cin >> value;
			list.push_front(value);
			break;

		case 2:
			cout << "Введите значение ";
			cin >> value;
			list.push_back(value);
			break;

		case 3:
			list.pop_front();
			break;

		case 4:
			list.pop_back();
			break;

		case 5:
			list.display();
			break;

		case 6:
			list.sort();
			break;

		case 7:
			list.remove_duplicates();
			cout << "Дубликаты удалены\n";
			break;

		case 8:
				break;

		default:
			cout << "Неверный выбор\n";
		}
	} while (v != 8);
}
