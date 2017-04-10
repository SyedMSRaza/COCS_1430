#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
	long int totalScore = 0, order = 1;
	string line;
	ifstream myfile;
	myfile.open("test.txt");
	while (getline(myfile, line))
	{
		int nameScore = 0;

		for (int i = 0; i < line.length(); i++)
		{	
			if (isalpha(line[i]))
			{
				char letter = line[i];
				nameScore += (int)letter - 64;
			}
		}
		cout << line << "\t" << nameScore << endl;
		totalScore += (nameScore*order);
		order++;
	}
	cout << "The sum total of all the name score is: " << totalScore << endl;
	system("pause");
}