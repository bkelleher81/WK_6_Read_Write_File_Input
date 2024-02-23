#pragma once
class FileRW
{
private:
	int myNumbers[20] = { 0 }; // array of 20 numbers
	int total = 0;
	double average = 0; // use double to cover decimal point answers
	string textFile;
	string ansFile;
	int preMade;

public:
	void displayMenu();
	void readData(); // read from data.txt
	void calculateTotal(); // calc total
	void calculateAng(); // calc avg
	void writeData(); // write data, total and avg to answers.txt
	void getData();
	void makeFile();

};
