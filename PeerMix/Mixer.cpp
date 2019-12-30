#include "stdafx.h"
#include "Mixer.h"


Mixer::Mixer()
{
}


Mixer::~Mixer()
{
}

// Mixer function that assigns peers to courses
void Mixer::runMixer()
{
	Serializer loadClient;
	loadClient.loadCourses(this->courseList);
	loadClient.loadPeers(this->peerList);

	loadPeersToCourses(this->courseList, this->peerList);
	sortEverything(this->courseList);

	for (auto course : courseList)
	{
		setNewPeer(course);
		setReturningPeer(course);
	}

	printPeers(courseList);
}

// Sort Peers
void Mixer::sortPeers(vector<Peer*> &peerList)
{
	for (unsigned i = 0; i < peerList.size(); i++)
	{
		for (unsigned j = i + 1; j < peerList.size(); j++)
		{
			if (peerList.at(i)->firstChoice.size() > peerList.at(j)->firstChoice.size())
			{
				swap(peerList.at(i), peerList.at(j));
			}
		}
	}

}

// Sort Courses
void Mixer::sortCourses(vector<Course*> &courseList)
{
	for (unsigned i = 0; i < courseList.size(); i++)
	{
		for (unsigned j = i + 1; j < courseList.size(); j++)
		{
			int left_available_peers = courseList.at(i)->n_firstChoice.size() + courseList.at(i)->r_firstChoice.size();
			int right_available_peers = courseList.at(j)->n_firstChoice.size() + courseList.at(j)->r_firstChoice.size();
			if (left_available_peers > right_available_peers)
			{
				swap(courseList.at(i), courseList.at(j));
			}
		}
	}
}

// Load peers to courses
void Mixer::loadPeersToCourses(vector<Course*> &courseList, const vector<Peer*> peerList)
{
	// For each course
	for (auto course : courseList)
	{
		// For each peer
		for (auto peer : peerList)
		{
			// Check First Choice
			for (auto time : peer->firstChoice)
			{
				time = removeSpaces(time);
				time = toLowerCase(time);
				string courseTime = removeSpaces(course->getTime());
				courseTime = toLowerCase(courseTime);

				// If time found
				if (time == courseTime)
				{
					// If new peer, add to new firstChoice list
					if (peer->getType().compare("N") == 0)
					{
						course->n_firstChoice.push_back(peer);
					}
					// Else, add to returning firstChoice list
					else
					{
						course->r_firstChoice.push_back(peer);
					}
				}

			}

			// Check Second Choice
			for (auto time : peer->secondChoice)
			{
				time = removeSpaces(time);
				time = toLowerCase(time);
				string courseTime = removeSpaces(course->getTime());
				courseTime = toLowerCase(courseTime);

				// If time found
				if (time == courseTime)
				{
					// If new peer, add to new secondChoice list
					if (peer->getType().compare("N") == 0)
					{
						course->n_secondChoice.push_back(peer);
					}
					// Else, add to returning secondChoice list
					else
					{
						course->r_secondChoice.push_back(peer);
					}
				}

			}

		}

	}

}

// Sort EPeers and Courses based on the least availability
void Mixer::sortEverything(vector<Course*> &courseList)
{
	sortCourses(courseList);
	for (auto course : courseList)
	{
		sortPeers(course->n_firstChoice);
		sortPeers(course->n_secondChoice);
		sortPeers(course->r_firstChoice);
		sortPeers(course->r_secondChoice);
	}
}

// Determine new peer for a course
void Mixer::setNewPeer(Course* course)
{
	if (!course->n_firstChoice.empty())
	{
		for (auto peer : course->n_firstChoice)
		{
			if (peer->isOccupied() == false)
			{
				course->setNewPeer(peer);
				peer->setOccupied(true);
				return;
			}
		}
	}
	else if (!course->n_secondChoice.empty())
	{
		for (auto peer : course->n_secondChoice)
		{
			if (peer->isOccupied() == false)
			{
				course->setNewPeer(peer);
				peer->setOccupied(true);
				return;
			}
		}
	}


	// If we get to this point, we didn't find any matching new peer from both the list. 
	// Two Option: Either get a returning peer from the peerList, or leave as "not found".
}

// Determine returning peer for a course
void Mixer::setReturningPeer(Course* course)
{
	if (!course->r_firstChoice.empty())
	{
		for (auto peer : course->r_firstChoice)
		{
			if (peer->isOccupied() == false)
			{
				course->setReturningPeer(peer);
				peer->setOccupied(true);
				return;
			}
		}
	}

	else if (!course->r_secondChoice.empty())
	{
		for (auto peer : course->r_secondChoice)
		{
			if (peer->isOccupied() == false)
			{
				course->setReturningPeer(peer);
				peer->setOccupied(true);
				return;
			}
		}
	}

	// If we get to this point, we didn't find any matching returning peer from both the list. 
	// Two Option: Either get a new peer from the peerList, or leave as "not found".
}


// Print Courses and respective peers
void Mixer::printPeers(const vector<Course*> courseList)
{
	for (auto course : courseList)
	{
		cout << course->getId() << ". " << course->getTime() << endl;
		if (course->getNewPeer() != NULL)
		{
			cout << "\t New Peer: " << course->getNewPeer()->getName() << endl;
		}
		else
		{
			cout << "\t New Peer: Not Found" << endl;
		}

		if (course->getReturningPeer() != NULL)
		{
			cout << "\t Returning Peer: " << course->getReturningPeer()->getName() << endl;
		}
		else
		{
			cout << "\t Returning Peer: Not Found" << endl;
		}
	}

	return;
}

// Remove whitespaces in a string
string Mixer::removeSpaces(string str)
{
	string copy = str;
	copy.erase(remove(copy.begin(), copy.end(), ' '), copy.end());
	return copy;
}

// Convert a string to lowercase
string Mixer::toLowerCase(string str)
{
	string sl = str;
	transform(sl.begin(), sl.end(), sl.begin(), ::tolower);
	return sl;
}
