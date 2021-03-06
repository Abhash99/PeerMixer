// PeerMix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Peer.h"
#include "Course.h"
#include "Mixer.h"
#include "Serializer.h"




int main()
{
	Mixer newMixer;
	newMixer.runMixer();

	exit(0);
}


// =================================================== Commented Old Code Section =============================================================================================================== // 

//void loadPeers(vector<Peer*> &vect)
//{
//	// Declaration of file variables
//	string fileName;
//	string line;
//	ifstream file;
//
//	// Delimiter is ";"
//	string delimeter = ";";
//
//	// Ask user for filename (with extension)
//	cout << "Please enter the name of the file to load peers with extension: " << endl;
//	cin >> fileName;
//
//	// Open file
//	file.open(fileName.c_str());
//
//	// Start storing tokens line-by-line
//	if (file.is_open())
//	{
//		while (getline(file, line))
//		{
//			// Set of arrays to store tokens
//			vector<string> token;
//			vector<string> first;
//			vector <string> second;
//
//
//			size_t i = 0;
//			size_t next = 0;
//			size_t last = 0;
//			size_t count = 0;
//
//			// Store all the words seperated by delimeter in a token array
//			while ((next = line.find(delimeter, last)) != string::npos)
//			{
//				string tok = line.substr(last, next - last);
//				token.push_back(tok);
//				last = next + 1;
//			}
//			count = token.size(); // Count gives the number of tokens in the array
//
//			bool check = false; // Check if it is Second Choice Option or not
//
//			for (int j = 2; j < (int)count; j++)
//			{
//				// If check is false (before the second choice times), store in first array
//				if (check == false && (token[j] != "-"))
//				{
//					first.push_back(token[j]);
//				}
//				// If we see a - sign, all words after - is second choice time
//				if (token[j] == "-")
//				{
//					check = true;
//					j++;
//				}
//
//				// If check is true, store all the following words in the second array
//				if (check == true)
//				{
//					second.push_back(token[j]);
//				}
//			}
//
//			// New Peer
//			Peer* P = new Peer(token[0], token[1]);
//			P->firstChoice = first;
//			P->secondChoice = second;
//			vect.push_back(P);
//		}
//	}
//	else
//	{
//		cout << "Could not open file!" << endl;
//		exit(1);
//	}
//}
//
//
//void loadCourses(vector<Course*> &courseList)
//{
//	// Declaration of file variables
//	string fileName;
//	string line;
//	ifstream file;
//
//	// Delimiter is ";"
//	string delimeter = ";";
//
//	// Ask user for filename (with extension)
//	cout << "Please enter the name of the file to load courses with extension: " << endl;
//	cin >> fileName;
//
//	// Open file
//	file.open(fileName.c_str());
//
//	// Start storing tokens line-by-line
//	if (file.is_open())
//	{
//		while (getline(file, line))
//		{
//			// Set of arrays to store tokens
//			vector<string> token;
//
//			size_t i = 0;
//			size_t next = 0;
//			size_t last = 0;
//			size_t count = 0;
//
//			// Store all the words seperated by delimeter in a token array
//			while ((next = line.find(delimeter, last)) != string::npos)
//			{
//				string tok = line.substr(last, next - last);
//				token.push_back(tok);
//				last = next + 1;
//			}
//			count = token.size(); // Count gives the number of tokens in the array
//
//			// convert from string to integer
//			int id = stoi(token[0]);
//
//			// Create course list
//			Course* newCourse = new Course(id, token[1]);
//			courseList.push_back(newCourse);
//		}
//	}
//	else
//	{
//		cout << "Could not open file!" << endl;
//		exit(1);
//	}
//}
//
//// Sort Peers
//void sortPeers(vector<Peer*> &peerList)
//{
//	for (unsigned i = 0; i < peerList.size(); i++)
//	{
//		for (unsigned j = i + 1; j < peerList.size(); j++)
//		{
//			if (peerList.at(i)->firstChoice.size() > peerList.at(j)->firstChoice.size())
//			{
//				swap(peerList.at(i), peerList.at(j));
//			}
//		}
//	}
//
//}
//
//// Sort Courses
//void sortCourses(vector<Course*> &courseList)
//{
//	for (unsigned i = 0; i < courseList.size(); i++)
//	{
//		for (unsigned j = i + 1; j < courseList.size(); j++)
//		{
//			int left_available_peers = courseList.at(i)->n_firstChoice.size() + courseList.at(i)->r_firstChoice.size();
//			int right_available_peers = courseList.at(j)->n_firstChoice.size() + courseList.at(j)->r_firstChoice.size();
//			if (left_available_peers > right_available_peers)
//			{
//				swap(courseList.at(i), courseList.at(j));
//			}
//		}
//	}
//}
//
//
//
//void loadPeersToCourses(vector<Course*> &courseList, const vector<Peer*> peerList)
//{
//	// For each course
//	for (auto course : courseList)
//	{
//		// For each peer
//		for (auto peer : peerList)
//		{
//			// Check First Choice
//			for (auto time : peer->firstChoice)
//			{
//				time = removeSpaces(time);
//				time = toLowerCase(time);
//				string courseTime = removeSpaces(course->getTime());
//				courseTime = toLowerCase(courseTime);
//				
//				// If time found
//				if (time == courseTime)
//				{
//					// If new peer, add to new firstChoice list
//					if (peer->getType().compare("N") == 0)
//					{
//						course->n_firstChoice.push_back(peer);
//					}
//					// Else, add to returning firstChoice list
//					else
//					{
//						course->r_firstChoice.push_back(peer);
//					}
//				}
//					
//			}
//
//			// Check Second Choice
//			for (auto time : peer->secondChoice)
//			{
//				time = removeSpaces(time);
//				time = toLowerCase(time);
//				string courseTime = removeSpaces(course->getTime());
//				courseTime = toLowerCase(courseTime);
//
//				// If time found
//				if (time == courseTime)
//				{
//					// If new peer, add to new secondChoice list
//					if (peer->getType().compare("N") == 0)
//					{
//						course->n_secondChoice.push_back(peer);
//					}
//					// Else, add to returning secondChoice list
//					else
//					{
//						course->r_secondChoice.push_back(peer);
//					}
//				}
//				
//			}
//
//		}
//
//	}
//
//}
//
//
//void sortEverything(vector<Course*> &courseList)
//{
//	sortCourses(courseList);
//	for (auto course : courseList)
//	{
//		sortPeers(course->n_firstChoice);
//		sortPeers(course->n_secondChoice);
//		sortPeers(course->r_firstChoice);
//		sortPeers(course->r_secondChoice);
//	}
//}
//
//void setNewPeer(Course* course)
//{
//	if (!course->n_firstChoice.empty())
//	{
//		for (auto peer : course->n_firstChoice)
//		{
//			if (peer->isOccupied() == false)
//			{
//				course->setNewPeer(peer);
//				peer->setOccupied(true);
//				return;
//			}
//		}
//	}
//
//	else if (!course->n_secondChoice.empty())
//	{
//		for (auto peer : course->n_secondChoice)
//		{
//			if (peer->isOccupied() == false)
//			{
//				course->setNewPeer(peer);
//				peer->setOccupied(true);
//				return;
//			}
//		}
//	}
//
//
//	// If we get to this point, we didn't find any matching new peer from both the list. 
//	// Two Option: Either get a returning peer from the peerList, or leave as "not found".
//}
//
//void setReturningPeer(Course* course)
//{
//	if (!course->r_firstChoice.empty())
//	{
//		for (auto peer : course->r_firstChoice)
//		{
//			if (peer->isOccupied() == false)
//			{
//				course->setReturningPeer(peer);
//				peer->setOccupied(true);
//				return;
//			}
//		}
//	}
//
//	else if (!course->r_secondChoice.empty())
//	{
//		for (auto peer : course->r_secondChoice)
//		{
//			if (peer->isOccupied() == false)
//			{
//				course->setReturningPeer(peer);
//				peer->setOccupied(true);
//				return;
//			}
//		}
//	}
//
//	// If we get to this point, we didn't find any matching returning peer from both the list. 
//	// Two Option: Either get a new peer from the peerList, or leave as "not found".
//}
//
//
//void printPeers(const vector<Course*> courseList)
//{
//	for (auto course : courseList)
//	{
//		cout << course->getId() << ". " << course->getTime() << endl;
//		if (course->getNewPeer() != NULL)
//		{ 
//			cout << "\t New Peer: " << course->getNewPeer()->getName() << endl;
//		}
//		else
//		{
//			cout << "\t New Peer: Not Found" << endl;
//		}
//
//		if (course->getReturningPeer() != NULL)
//		{
//			cout << "\t Returning Peer: " << course->getReturningPeer()->getName() << endl;
//		}
//		else
//		{
//			cout << "\t Returning Peer: Not Found" << endl;
//		}
//	}
//
//	return;
//}
//
//string removeSpaces(string str)
//{
//	string copy = str;
//	copy.erase(remove(copy.begin(), copy.end(), ' '), copy.end());
//	return copy;
//}
//
//string toLowerCase(string str)
//{
//	string sl = str;
//	transform(sl.begin(), sl.end(), sl.begin(), ::tolower);
//	return sl;
//}

//=================================================================================================================================================================================