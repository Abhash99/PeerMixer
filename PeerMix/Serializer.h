#pragma once
#include "Peer.h"
#include "Course.h"
class Serializer
{
public:
	Serializer();
	~Serializer();

	// Utility Functions
	void loadPeers(vector<Peer*> &vect);
	void loadCourses(vector<Course*> &courseList);

};

