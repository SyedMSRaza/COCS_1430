#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



int letterValue(char j);

int main()
{
	vector<string> sortedNames;
	ifstream inStream;
	string line;



	inStream.open("names.txt");
	for (line; getline(inStream, line);) // this puts all the names (unsorted) into a vector
	{
		sortedNames.push_back(line);
	}


	sort(sortedNames.begin(), sortedNames.end());  //this sorts all the names in alphabetical order

	int totalNames = static_cast<int>(sortedNames.size());
	int* namesAlphaValues = new int[totalNames];



	//this next for loop puts all the alpha values of each name into another array.
	//the alpha values are in the same order as the names in the sortedNames array 
	//so both can be found by using the same index number

	for (int i = 0; i < totalNames; i++) 
	{										
		int value = 0;
		string currentName = sortedNames[i];
		int hold = currentName.length();
		
		for (int j = 0; j < hold; j++)
		{
			char currentLetter = currentName[j];
			value += letterValue(currentLetter);
		}

		namesAlphaValues[i] = value;
	}

	///////////////


	int* nameScores = new int[totalNames];
	int sumTotal = 0;

	//this for loop puts the name scores for each name in its own array.
	//it's also in order, name scores @ index 'x' will correspond to the sortedName @ index 'x'

	for (int n = 0; n < totalNames; n++)
	{
		int hold = namesAlphaValues[n];
		int thisScore = hold * (n + 1);  // have to multiply by n+1 bc we are multiplying by list position, not name location in array (in terms of indexes starting at 0)
		nameScores[n] = thisScore; 
		sumTotal += thisScore;
	}

	cout << "The sum total of all the name-scores in the file is: " << sumTotal << endl;


	system("pause");
	return 0;
}


int letterValue(char j)
{
	switch (j)
	{
	case 'A': return 1;
	case 'B': return 2;
	case 'C': return 3;
	case 'D': return 4;
	case 'E': return 5;
	case 'F': return 6;
	case 'G': return 7;
	case 'H': return 8;
	case 'I': return 9;
	case 'J': return 10;
	case 'K': return 11;
	case 'L': return 12;
	case 'M': return 13;
	case 'N': return 14;
	case 'O': return 15;
	case 'P': return 16;
	case 'Q': return 17;
	case 'R': return 18;
	case 'S': return 19;
	case 'T': return 20;
	case 'U': return 21;
	case 'V': return 22;
	case 'W': return 23;
	case 'X': return 24;
	case 'Y': return 25;
	case 'Z': return 26;
	default: return 0;
	}
}