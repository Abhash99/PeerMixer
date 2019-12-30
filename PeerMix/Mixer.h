#pragma once
#include "Peer.h"
#include "Course.h"
#include "Serializer.h"

class Mixer
{
public:
	Mixer();
	~Mixer();


	// Accessors
	inline vector<Peer*> getPeerList() const
	{
		return this->peerList;
	}

	inline vector<Course*> getCourseList() const
	{
		return this->courseList;
	}


	// Mutators
	void setPeerList(vector<Peer*> peerList)
	{
		this->peerList = peerList;
	}

	void setCourseList(vector<Course*> courseList)
	{
		this->courseList = courseList;
	}

	// Printer Functions
	void printPeerList()
	{
		for (auto peer : this->peerList)
		{
			cout << "Name: " << peer->getName() << endl;
			cout << "Type: " << peer->getType() << endl;
			cout << "First Choice Times:" << endl;
			for (string time : peer->firstChoice)
			{
				cout << time << " ";
			}

			cout << endl;
			cout << "Second Choice Times: " << endl;
			for (string time : peer->secondChoice)
			{
				cout << time << " ";
			}
			cout << endl;

		}
	}


	void printCourseList()
	{
		for (auto course : courseList)
		{
			cout << "Course Id: " << course->getId() << " ";
			cout << "Time: " << course->getTime() << endl;
			cout << endl;
		}
	}



	// Utility Functions

	// Mixer function that assigns peers to courses
	void runMixer();

	// Sort Peers
	void sortPeers(vector<Peer*> &peerList);

	// Sort Courses
	void sortCourses(vector<Course*> &courseList);

	// Load peers to courses
	void loadPeersToCourses(vector<Course*> &courseList, const vector<Peer*> peerList);

	// Sort EPeers and Courses based on the least availability
	void sortEverything(vector<Course*> &courseList);

	// Determine new peer for a course
	void setNewPeer(Course* course);

	// Determine returning peer for a course
	void setReturningPeer(Course* course);


	// Print Courses and respective peers
	void printPeers(const vector<Course*> courseList);

	// Remove whitespaces in a string
	string removeSpaces(string str);

	// Convert a string to lowercase
	string toLowerCase(string str);


private:
	vector<Peer*> peerList;
	vector<Course*> courseList;
};

