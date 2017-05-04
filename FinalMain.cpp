#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int nameScore(string name, int order);
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
		string line = names[index];
		line = names[index];
		int NameScore = nameScore(line, order);

		totalScore += (NameScore);
		order++;
	}
	cout << "The sum total of all the name score is: " << totalScore << endl;
	cout << "Enter a name to find its namescore: ";
	string name;
	cin >> name;

	order = binaryVectorSearch(names, 0, names.size() - 1, name) + 1;

	if (order > 0) {
		int NameScore = nameScore(name, order);
		cout << "Namescore for " << name << ": \t" << NameScore << endl;
	}
	else {
		names.push_back(name);
		numberOfLines++;
		sort(names.begin(), names.end());
		order = 1;
		for (int index = 0; index < numberOfLines; index++)
		{
			string name = names[index];
			int NameScore = nameScore(name, order);

			totalScore += (NameScore);
			order++;
		}

	order = binaryVectorSearch(names, 0, names.size() - 1, name) + 1;
	int NameScore = nameScore(name, order);

	cout << "Namescore for " << name << ": \t" << NameScore << endl;
	cout << "The updated sum total of all of the namescores is: " << totalScore << endl;
	}

	system("pause");
	return 0;
}

int nameScore(string name, int order) {
	int NameScore = 0;
	for (int i = 0; i < name.length(); i++)
	{
		if (isalpha(name[i]))
		{
			char letter = name[i];
			NameScore += (int)letter - 64;
		}
	}
	return NameScore *= order;
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
