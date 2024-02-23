#include "FileRW.h"
#include <iostream>
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
		cin >> textFile;
		cin >> ansFile;
		cout << " " << endl;
		getData();
		makeFile();
		
	}

	else if (choice == 2)
	{
		cout << "You have chosen pre-saved files." << endl;
		readData();
		calculateTotal();
		calculateAng();
		writeData();
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
	cout << "Numbers read from data.txt " << endl;

	for (int j = 0; j < i; j++)
	{
		cout << myNumbers[j] << " ";
	}
	cout << endl;
}

void FileRW::calculateTotal()
{
	for (int i = 0; i < 20; i++)
	{
		total = total + myNumbers[i];
	}
	cout << "\nTotal = " << total << endl;
}

void FileRW::calculateAng()
{
	average = static_cast<double>( total )/ 20;
	cout << "Average = " << average << endl;
}

void FileRW::writeData()
{
	ofstream outputFile;
	outputFile.open(textFile);
	for (int i = 0; i < 20; i++)
	{
		outputFile << myNumbers[i] << endl;
	}
	outputFile << "\nTotal = " << total << endl;
	outputFile << "Average = " << average << endl;
	outputFile.close();
}

void FileRW::getData()
{
	fstream fileInput;
	fileInput.open("data1.txt");
	int i = 0;
	while (!fileInput.eof()) // read each number until the end of the file
	{
		fileInput >> myNumbers[i];
		i++;
	}
	fileInput.close(); // close file
	cout << "\nNumber of elements read = " << i << endl; // cout the number of elements read, increase i by 1
	cout << "Numbers read from data.txt " << endl;

	for (int j = 0; j < i; j++)
	{
		cout << myNumbers[j] << " ";
	}
	cout << endl;
}

void FileRW::makeFile()
{
	ofstream outputFile;
	outputFile.open("ansFile");
	for (int i = 0; i < 20; i++)
	{
		outputFile << myNumbers[i] << endl;
	}
	outputFile << "\nTotal = " << total << endl;
	outputFile << "Average = " << average << endl;
	outputFile.close();
}
