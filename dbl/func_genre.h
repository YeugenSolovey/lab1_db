#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
//#include "struct.h"

using namespace std;


struct Genre {
	int id;
	int gameId;
	string name;
};

void DataEntryGE(Genre* (&d), int& n);//enter data
void ReadingDataGE(Genre* (&d), int& n, string foleName);//read data
void PrintGE(Genre* d, int n);// output data
void DataChangeGE(Genre* (&d), int n);//Change data
void DeleteDataGE(Genre* (&d), int& n);//delete data
void CopyGE(Genre* (&d_n), Genre* (&d_o), int n);//copy data
void CopyGE(Genre& d_n, Genre& d_o);//copy data element
void AddDateGE(Genre* (&d), int& n);//add data
void DataSortingGE(Genre* d, int n);//sort data
void SavingDataGE(Genre* d, int n, string fileName);//save data
void ccount(Genre* d, int n);