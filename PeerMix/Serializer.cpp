#include "stdafx.h"
#include "Serializer.h"


Serializer::Serializer()
{
}


Serializer::~Serializer()
{
}

void Serializer::loadPeers(vector<Peer*> &vect)
{
	// Declaration of file variables
	string fileName;
	string line;
	ifstream file;

	// Delimiter is ";"
	string delimeter = ";";

	// Ask user for filename (with extension)
	cout << "Please enter the name of the file to load peers with extension: " << endl;
	cin >> fileName;

	// Open file
	file.open(fileName.c_str());

	// Start storing tokens line-by-line
	if (file.is_open())
	{
		while (getline(file, line))
		{
			// Set of arrays to store tokens
			vector<string> token;
			vector<string> first;
			vector <string> second;


			size_t i = 0;
			size_t next = 0;
			size_t last = 0;
			size_t count = 0;

			// Store all the words seperated by delimeter in a token array
			while ((next = line.find(delimeter, last)) != string::npos)
			{
				string tok = line.substr(last, next - last);
				token.push_back(tok);
				last = next + 1;
			}
			count = token.size(); // Count gives the number of tokens in the array

			bool check = false; // Check if it is Second Choice Option or not

			for (int j = 2; j < (int)count; j++)
			{
				// If check is false (before the second choice times), store in first array
				if (check == false && (token[j] != "-"))
				{
					first.push_back(token[j]);
				}
				// If we see a - sign, all words after - is second choice time
				if (token[j] == "-")
				{
					check = true;
					j++;
				}

				// If check is true, store all the following words in the second array
				if (check == true)
				{
					second.push_back(token[j]);
				}
			}

			// New Peer
			Peer* P = new Peer(token[0], token[1]);
			P->firstChoice = first;
			P->secondChoice = second;
			vect.push_back(P);
		}
	}
	else
	{
		cout << "Could not open file!" << endl;
		exit(1);
	}
}


void Serializer::loadCourses(vector<Course*> &courseList)
{
	// Declaration of file variables
	string fileName;
	string line;
	ifstream file;

	// Delimiter is ";"
	string delimeter = ";";

	// Ask user for filename (with extension)
	cout << "Please enter the name of the file to load courses with extension: " << endl;
	cin >> fileName;

	// Open file
	file.open(fileName.c_str());

	// Start storing tokens line-by-line
	if (file.is_open())
	{
		while (getline(file, line))
		{
			// Set of arrays to store tokens
			vector<string> token;

			size_t i = 0;
			size_t next = 0;
			size_t last = 0;
			size_t count = 0;

			// Store all the words seperated by delimeter in a token array
			while ((next = line.find(delimeter, last)) != string::npos)
			{
				string tok = line.substr(last, next - last);
				token.push_back(tok);
				last = next + 1;
			}
			count = token.size(); // Count gives the number of tokens in the array

								  // convert from string to integer
			int id = stoi(token[0]);

			// Create course list
			Course* newCourse = new Course(id, token[1]);
			courseList.push_back(newCourse);
		}
	}
	else
	{
		cout << "Could not open file!" << endl;
		exit(1);
	}
}
