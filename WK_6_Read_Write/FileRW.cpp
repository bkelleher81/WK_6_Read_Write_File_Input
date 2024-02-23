#include "FileRW.h"
#include <iostream>
#include <string> // string variable
#include <fstream> // file input database. fstream <<  >>
					//ifstream >> same as cin
					//ofstream << same as cout
using namespace std;


void FileRW::displayMenu()
{
	int choice;
	cout << "1. Enter the name of the text file and the answer file." << endl;
	cout << "2. Use default files already compiled." << endl;
	cout << "3. Quit." << endl;
	cin >> choice;

	if (choice == 1)
	{
		cout << "Text file name and Answer key name:  " << endl;
		cin >> textFile >> ansFile; // string variable
		cout << " " << endl;
		getData();
		makeFile();
		cout << endl;
		displayMenu();
		

		
	}

	else if (choice == 2)
	{
		cout << "You have chosen pre-saved files." << endl;
		readData();
		calculateTotal();
		calculateAng();
		writeData();
		cout << endl;
		displayMenu();
	}

	else if (choice == 3)
	{
		cout << "Goodbye!" << endl;
	}
}

void FileRW::readData()
{
	fstream fileInput;
	fileInput.open("data.txt");
	int i = 0;
	while (!fileInput.eof()) // read each number until the end of the file
	{
		fileInput >> myNumbers[i];
		i++;
	}
	fileInput.close(); // close file
	cout << "\nNumber of elements read = " << i  << endl; // cout the number of elements read, increase i by 1
	cout <<"Numbers read from data.txt " << endl;

	for (int j = 0; j < i; j++)
	{
		cout << myNumbers[j] << " ";
	}
	cout << endl;
}

void FileRW::writeData()
{
	ofstream outputFile;
	outputFile.open("key.txt");
	for (int i = 0; i < 20; i++)
	{
		outputFile << myNumbers[i] << endl;
	}
	outputFile << "\nTotal = " << total << endl;
	outputFile << "Average = " << average << endl;
	outputFile.close();
}

void FileRW::calculateTotal()
{
	total =0;
	for (int i = 0; i < 20; i++)
	{
		total = total + myNumbers[i];
	}
	cout << "\nTotal = " << total << endl;
}
void FileRW::getData()
{
	fstream fileInput;
	fileInput.open(textFile);
	int i = 0;
	while (!fileInput.eof()) // read each number until the end of the file
	{
		fileInput >> myNumbers[i];
		i++;
	}
	fileInput.close(); // close file
	cout << "\nNumber of elements read = " << i << endl; // cout the number of elements read, increase i by 1
	cout << "Numbers read from " << textFile << endl;

	for (int j = 0; j < i; j++)
	{
		cout << myNumbers[j] << " ";
	}
	cout << endl;
}

void FileRW::makeFile()
{
	ofstream outputFile;
	int i = 0;
	total = 0;
	outputFile.open(ansFile);
	for (int i = 0; i < 20; i++)
	{
		outputFile << myNumbers[i] << endl;
	}
	for (int i = 0; i < 20; i++)
	{
		total = total + myNumbers[i];
	}
	average = static_cast<double>(total) / 20;
	cout << "\nTotal = " << total << endl;
	cout << "\nAverage= " << average<< endl;
	outputFile << "\nTotal = " << total << endl;
	outputFile << "Average = " << average << endl;
	outputFile.close();
	
}

void FileRW::calculateAng()
{
	average = static_cast<double>(total) / 20;
	cout << "Average = " << average << endl;
}
