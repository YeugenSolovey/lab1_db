#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
//#include "struct.h"

using namespace std;

struct Game {
	int id;
	string name;
};




void DataEntryGA(Game* (&d), int& n);//enter data
void ReadingDataGA(Game* (&d), int& n, string foleName);//read data
void PrintGA(Game* d, int n);// output data
void DataChangeGA(Game* (&d), int n);//Change data
void DeleteDataGA(Game* (&d), int& n);//delete data
void CopyGA(Game* (&d_n), Game* (&d_o), int n);//copy data
void CopyGA(Game&d_n, Game &d_o);//copy data element
void AddDateGA(Game* (&d), int& n);//add data
void DataSortingGA(Game* d, int n);//sort data
void SavingDataGA(Game* d, int n, string fileName);//save data
int GetCount(Game* (&d), int& n);
