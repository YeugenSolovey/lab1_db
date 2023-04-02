#include "func_genre.h"

void DataEntryGE(Genre* (&d), int& n) {
	cout << "Enter data acount";
	cin >> n;

	d = new Genre[n];

	for (int i = 0; i < n; i++) {
		cout << "Enter id :";
		cin >> d[i].id;
		cout << "Enter game id :";
		cin >> d[i].gameId;
		cout << "Name: ";
		cin >> d[i].name;


		cout << "___________________________________" << endl;
	}
}

void ReadingDataGE(Genre* (&d), int& n, string foleName) {
	ifstream reading(foleName);
	if (reading) {
		reading >> n;
		d = new Genre[n];

		for (int i = 0; i < n; i++) {
			reading >> d[i].id;
			reading >> d[i].gameId;
			reading >> d[i].name;
		}
	}
	else {
		cout << "Error with open file";
	}

	reading.close();
}

void PrintGE(Genre* d, int n) {
	for (int i = 0; i < n; i++) {
		cout << "genre: #" << i + 1 << ":" << endl;

		cout << "Id, game id and name genre:\n" <<
			"Id: " << d[i].id << 
			"\nGame id: " << d[i].gameId <<
			"\nName: " << d[i].name << endl;

		cout << "______________________" << endl;
	}
}

void DataChangeGE(Genre* (&d), int n) {
	int _n;

	cout << "Enter element id";
	cin >> _n;
	_n--;

	//system("cls");

	if (_n >= 0 && _n < n) {
		cout << "Enter id: ";
		cin >> d[_n].id;
		cout << "Enter game id: ";
		cin >> d[_n].gameId;
		cout << "Enter genre name: ";
		cin >> d[_n].name;
		SavingDataGE(d, n, "Input_genre.txt");
		system("cls");
		cout << "Data was change";
	}
	else cout << "Uncorect nuber";

}

void DeleteDataGE(Genre* (&d), int& n) {
	int _n;

	cout << "Enter element from 1 to " << n << ": ";
	cin >> _n;
	_n--;

	system("cls");

	if (_n >= 0 && _n < n) {
		Genre* buf = new Genre[n];

		CopyGE(buf, d, n);

		--n;
		d = new Genre[n];

		int q = 0;

		for (int i = 0; i < n; i++) {
			if (i != _n) {
				d[q] = buf[i];
				++q;
			}
		}

		SavingDataGE(d, n, "Input_genre.txt");
		system("cls");
		delete[]buf;
		cout << "Data was deleted";
	}
	else cout << "Wrong number" << endl;
}

void CopyGE(Genre* (&d_n), Genre* (&d_o), int n) {
	for (int i = 0; i < n; i++) {
		d_n[i] = d_o[i];
	}
}

void CopyGE(Genre& d_n, Genre& d_o) {
	d_n.id = d_o.id;
	d_n.gameId = d_o.gameId;
	d_n.name = d_o.name;
}

void AddDateGE(Genre* (&d), int& n) {
	Genre* buf;
	buf = new Genre[n];

	CopyGE(buf, d, n);

	n++;
	d = new Genre[n];

	CopyGE(d, buf, --n);

	cout << "Add id, game id and name game: " << endl;
	cout << "Enter id: "; cin >> d[n].id;
	cout << "Enter game id: "; cin >> d[n].gameId;
	cout << "Enter name: "; cin >> d[n].name;
	SavingDataGE(d, n+1, "Input_genre.txt");
	//system("cls");

	cout << "Data was addet";

	delete[] buf;
}

void DataSortingGE(Genre* d, int n) {
	Genre buf;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (d[i].name > d[j].name) {
				CopyGE(buf, d[j]);
				CopyGE(d[j], d[i]);
				CopyGE(d[i], buf);
			}
		}
	}

	cout << "Data was sor" << endl;
}

void SavingDataGE(Genre* d, int n, string fileName) {
	ofstream record(fileName, ios::out);

	if (record) {
		record << n << endl;
		for (int i = 0; i < n; i++) {
			record << d[i].id << endl;
			record << d[i].gameId << endl;
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

void ccount(Genre* d, int n) {
	int a = 0;
	int f = 0;
	cout << "enter game id:";
	cin >> a;
	for (int i = 0; i < n; i++) {
		if (a == d[i].gameId) {
			cout << "Genre - " << d[i].name << ", with id - " << d[i].id << ", refers to game id - " << d[i].gameId << endl;
			cout << "______________________" << endl;
			f++;
		}
	}
	if (f == 0) cout << "no genres belong to this game id" << endl;
}