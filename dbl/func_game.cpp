#include "func_game.h"

void DataEntryGA(Game* (&d), int& n) {
	cout << "Enter data acount";
	cin >> n;

	d = new Game[n];

	for (int i = 0; i < n; i++) {
		cout << "Enter id :";
		cin >> d[i].id;
		cout << "Name: ";
		cin >> d[i].name;



		cout << "___________________________________" << endl;
	}
}

void ReadingDataGA(Game* (&d), int& n, string foleName) {
	ifstream reading(foleName);
	if (reading) {
		reading >> n;
		d = new Game[n];

		for (int i = 0; i < n; i++) {
			reading >> d[i].id;
			reading >> d[i].name;

		}
	}
	else {
		cout << "Error with open file";
	}

	reading.close();
}

void PrintGA(Game* d, int n) {
	for (int i = 0; i < n; i++) {
		cout << "game: #" << i + 1 << ":" << endl;

		cout << "Id and name game:\n" << 
			"Id: " << d[i].id << 
			"\nName: " << d[i].name << endl;

		cout << "______________________" << endl;
	}
}

void DataChangeGA(Game* (&d), int n) {
	int _n;

	cout << "Enter element id: ";
	cin >> _n;
	_n--;

	//system("cls");

	if (_n >= 0 && _n < n) {
		cout << "Enter id: ";
		cin >> d[_n].id;
		cout << "Enter game: ";
		cin >> d[_n].name;
		SavingDataGA(d, n, "Input_game.txt");
		system("cls");
		cout << "Data was change";
	}
	else cout << "Uncorect nuber";

}

void DeleteDataGA(Game* (&d), int& n) {
	int _n;

	cout << "Enter element from 1 to " << n << ": ";
	cin >> _n;
	_n--;

	system("cls");

	if (_n >= 0 && _n < n) {
		Game* buf = new Game[n];

		CopyGA(buf, d, n);

		--n;
		d = new Game[n];

		int q = 0;

		for (int i = 0; i < n; i++) {
			if (i != _n) {
				d[q] = buf[i];
				++q;
			}
		}

		SavingDataGA(d, n, "Input_game.txt");
		system("cls");
		delete[]buf;
		cout << "Data was deleted";
	}
	else cout << "Wrong number" << endl;
}

void CopyGA(Game* (&d_n), Game* (&d_o), int n) {
	for (int i = 0; i < n; i++) {
		d_n[i] = d_o[i];
	}
}

void CopyGA(Game& d_n, Game& d_o) {
	d_n.id = d_o.id;
	d_n.name = d_o.name;
}

void AddDateGA(Game* (&d), int& n) {
	Game* buf;
	buf = new Game[n];

	CopyGA(buf, d, n);

	n++;
	d = new Game[n];

	CopyGA(d, buf, --n);

	cout << "Add id and name game: " << endl;
	cout << "Enter id: "; cin >> d[n].id;
	cout << "Enter name: "; cin >> d[n].name;
	SavingDataGA(d, n + 1, "Input_game.txt");
	//system("cls");

	cout << "Data was addet";

	delete[] buf;
}

//void DataSortingGA(Game* d, int n) {
//	Game buf;
//
//	for (int i = 0; i < n; i++) {
//		for (int j = i + 1; j < n; j++) {
//			if (d[i].name > d[j].name) {
//				CopyGA(buf, d[j]);
//				CopyGA(d[j], d[i]);
//				CopyGA(d[i], buf);
//			}
//		}
//	}
//
//	cout << "Data was sor" << endl;
//}

void SavingDataGA(Game* d, int n, string fileName) {
	ofstream record(fileName, ios::out);

	if (record) {
		record << n << endl;
		for (int i = 0; i < n; i++) {
			record << d[i].id << endl;
			
			if (i < n - 1)
				record << d[i].name << endl;
			else
				record << d[i].name << endl;
		}
	}
	else
		cout << "write error" << endl;

	record.close();
}
