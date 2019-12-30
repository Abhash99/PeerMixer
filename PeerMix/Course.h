#pragma once
#include "Peer.h"
class Course
{
public:
	Course()
	{
		this->id = 0;
		this->time = "NULL";
		this->r_peer = NULL;
		this->n_peer = NULL;

	}
	~Course(){}

	Course(int id, string time)
	{
		this->id = id;
		this->time = time;
	}

	// Accessors
	int getId()
	{
		return this->id;
	}

	string getTime()
	{
		return this->time;
	}

	Peer* getReturningPeer()
	{
		return this->r_peer;
	}

	Peer* getNewPeer()
	{
		return this->n_peer;
	}

	// Mutators
	void setId(int id)
	{
		this->id = id;
	}

	void setTime(string Time)
	{
		this->time = time;
	}

	void setReturningPeer(Peer* r_peer)
	{
		this->r_peer = r_peer;
	}

	void setNewPeer(Peer* n_peer)
	{
		this->n_peer = n_peer;
	}


	// Utility Functions


	// Public Member Variables
	vector<Peer*> r_firstChoice;
	vector<Peer*> r_secondChoice;
	vector<Peer*> n_firstChoice;
	vector<Peer*> n_secondChoice;

private:
	int id;
	string time;
	Peer* r_peer;
	Peer* n_peer;

};

