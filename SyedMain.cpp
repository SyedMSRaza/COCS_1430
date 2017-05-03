#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int binaryVectorSearch(vector<string> v, int first, int last, string name);

int main() {

	long long int totalScore = 0;
	int order = 1, numberOfLines = 0;
	string line;
	ifstream myfile;
	myfile.open("names.txt");

	vector<string> names;

	while (getline(myfile, line))
	{
		names.push_back(line);
		++numberOfLines;
	}
	sort(names.begin(), names.end());
	myfile.close();

	for (int index = 0; index < numberOfLines; index++)
	{
		line = names[index];
		int nameScore = 0;
		for (int i = 0; i < line.length(); i++)
		{

			if (isalpha(line[i]))
			{

				char letter = line[i];
				nameScore += (int)letter - 64;
			}
		}

		totalScore += (nameScore*order);
		order++;
	}
	cout << "The sum total of all the name score is: " << totalScore << endl;
	cout << "Enter a name to find its namescore: ";
	string name;
	cin >> name;

	order = binaryVectorSearch(names, 0, names.size() - 1, name) + 1;

	if (order > 0) {
		int nameScore = 0;
		for (int i = 0; i < name.length(); i++)
		{
			if (isalpha(name[i]))
			{
				char letter = name[i];
				nameScore += (int)letter - 64;
			}
		}
		cout << "Namescore for " << name << ": \t" << nameScore*order << endl;
	}
	else {
		names.push_back(name);
		numberOfLines++;
		sort(names.begin(), names.end());

		for (int index = 0; index < numberOfLines; index++)
		{
			line = names[index];
			int nameScore = 0;
			for (int i = 0; i < line.length(); i++)
			{

				if (isalpha(line[i]))
				{

					char letter = line[i];
					nameScore += (int)letter - 64;
				}
			}

			totalScore += (nameScore*order);
			order++;
		}
	order = binaryVectorSearch(names, 0, names.size() - 1, name) + 1;
	int nameScore = 0;
	for (int i = 0; i < name.length(); i++)
	{
		if (isalpha(name[i]))
		{
			char letter = name[i];
			nameScore += (int)letter - 64;
		}
	}
	cout << "Namescore for " << name << ": \t" << nameScore*order << endl;
	cout << "The updated sum total of all of the namescores is: " << totalScore << endl;
	}

	system("pause");
	return 0;
}

int binaryVectorSearch(vector<string> v, int first, int last, string name) {

	if (first <= last) {
		int mid = (first + last) / 2;
		if (name == v[mid])
			return mid;

		else if (name < v[mid])
			return binaryVectorSearch(v, first, mid - 1, name);

		else
			return binaryVectorSearch(v, mid + 1, last, name);
	}
	return -(first + 1);
}