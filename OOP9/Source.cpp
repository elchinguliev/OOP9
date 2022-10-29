






#include <iostream>
#include <vector>
#include <Windows.h>


//Worker id, name, surname, age, pageCount
//WorkerQueue
//Printer workerQueue
//start - 
//Printer clasinin ichinde workerQueue saxlanilmalidir
//ve printer in start methodu chagrilan kimi
//novbede olan ishchilerin kagizlari ksersks olsun
//kserks emeliyyati bitenden sonra ishci siradan dequeue olunsun
//novbe boshalana qeder bu proses davam etmelidir

using namespace std;

class Worker {
public:
	static int idCounter;
	int id;
	string name;
	string surname;
	int age;
	int pageCount;

	Worker() {
		id = idCounter++;
		name = "";
		surname = "";
		age = 0;
		pageCount = 0;
	}

	Worker(string name, string surname, int age, int pageCount) {
		id = idCounter++;
		this->name = name;
		this->surname = surname;
		this->age = age;
		this->pageCount = pageCount;
	}

	void Show() {
		cout << "Id: " << id << "\nName: " << name << "\nSurname: " << surname << "\nAge: " << age << "\nPageCount: " << pageCount << endl;
	}
};
int Worker::idCounter = 100;

class WorkerQueue {
public:
	vector<Worker> workers;

	bool IsEmpty() const { return workers.empty(); }

	void Push(const Worker worker) {
		workers.push_back(worker);
	}

	void Pop() {
		if (!workers.empty())
			workers.erase(workers.begin());
	}

	Worker& Front() {
		return workers.front();
	}

};

class Printer {
public:
	WorkerQueue queue;

	void AddWorker(const Worker worker) {
		queue.Push(worker);
	}

	void Start() {
		while (!queue.IsEmpty()) {
			Worker worker = queue.Front();
			while (worker.pageCount > 0)
			{
				system("cls");
				worker.Show();
				Sleep(1000);
				worker.pageCount--;
			}
			queue.Pop();
		}

	}

};

void main() {
	Printer p;
	p.AddWorker(Worker("Elchin", "Guliyev", 19, 4));
	p.AddWorker(Worker("Rufet", "Hasanov", 20, 6));
	p.AddWorker(Worker("Elvin", "Rzayev", 18, 4));
	p.AddWorker(Worker("Ferid", "Aliyev", 21, 10));

	p.Start();
}


