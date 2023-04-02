#include <iostream>
#include "func_game.h"
#include "func_genre.h"
#include "infodb.h"

using namespace std;

int _stateMenu;
void Menu()
{

    cout << "0 - exit" << endl
        << "1 - Get game" << endl
        << "2 - Insert game" << endl
        << "3 - Update game" << endl
        << "4 - Delete game" << endl
        << "5 - Get genre" << endl
        << "6 - Insert genre" << endl
        << "7 - Update genre" << endl
        << "8 - Delete genre" << endl
        << "9 - Count" << endl
        << "Enter number: ";

    cin >> _stateMenu;
}

int main()
{
    Menu();

    int amountOfData = 0;
    Game* d = new Game[amountOfData];
    Genre* g = new Genre[amountOfData];

    //Game* g = new Game[amountOfData];

    while (_stateMenu != 0) {
        switch (_stateMenu)
        {            
            
            case 1://GET
                system("cls");
                ReadingDataGA(d, amountOfData, "Input_game.txt");
                if (amountOfData != 0) {
                    PrintGA(d, amountOfData);
                }
                else
                    cout << "Data is empty" << endl;
                Menu();
                break;

            case 2://ADD
                //system("cls");

                ReadingDataGA(d, amountOfData, "Input_game.txt");
                if (amountOfData != 0) {
                    AddDateGA(d, amountOfData);
                    amountOfData++;
                }
                else
                    cout << "Data empty" << endl;

                system("cls");
                Menu();
                break;

            case 3://UPDATE
                //system("cls");
                ReadingDataGA(d, amountOfData, "Input_game.txt");
                if (amountOfData != 0) {
                    DataChangeGA(d, amountOfData);
                }
                else
                    cout << "Data is empty" << endl;
                system("cls");
                Menu();
                break;

            case 4://DELETE
                //system("cls");
                ReadingDataGA(d, amountOfData, "Input_game.txt");
                if (amountOfData != 0) {
                    DeleteDataGA(d, amountOfData);
                }
                else {
                    cout << "Data empty";
                }
                system("cls");
                Menu();
                break;
            case 5://GET GENRE
                system("cls");
                ReadingDataGE(g, amountOfData, "Input_genre.txt");
                if (amountOfData != 0) {
                    PrintGE(g, amountOfData);
                }
                else
                    cout << "Data is empty" << endl;
                Menu();
                break;

            case 6://ADD GENRE
               // system("cls");
                ReadingDataGE(g, amountOfData, "Input_genre.txt");
                if (amountOfData != 0) {
                    AddDateGE(g, amountOfData);
                }
                else
                    cout << "Data empty" << endl;
                system("cls");
                Menu();
                break;

            case 7://UPDATE GENRE
                //system("cls");
                ReadingDataGE(g, amountOfData, "Input_genre.txt");
                if (amountOfData != 0) {
                    DataChangeGE(g, amountOfData);
                }
                else
                    cout << "Data empty" << endl;

                system("cls");
                Menu();
                break;

            case 8: //DELETE GENRE
               // system("cls");
                ReadingDataGE(g, amountOfData, "Input_genre.txt");
                if (amountOfData != 0) {
                    DeleteDataGE(g, amountOfData);
                }
                else {
                    cout << "Data empty";
                }
                system("cls");
                Menu();
                break;
            
            case 9:
                //system("cls");
                ReadingDataGE(g, amountOfData, "Input_genre.txt");
                if (amountOfData != 0) {
                    ccount(g, amountOfData);
                }
                else
                {
                    cout << "Error";
                }
               // system("cls");
                Menu();
                break;

            default: 
                cout << "Wrong number";
                system("cls");
                Menu();
                break;
        }
    }
}
