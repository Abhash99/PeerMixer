#pragma once
class Peer
{
public:
	Peer()
	{
		this->name = "NULL";
		this->type = "0";
		this->occupied = false;
	}
	~Peer() {};

	Peer(string name, string type)
	{
		this->name = name;
		this->type = type;
		this->occupied = false;

	}

	// Accessors
	string getName()
	{
		return this->name;
	}

	string getType()
	{
		return this->type;
	}

	bool isOccupied()
	{
		return this->occupied;
	}

	// Mutators
	void setName(string name)
	{
		this->name = name;
	}

	void setType(string type)
	{
		this->type = type;
	}

	void setOccupied(bool occupiedState)
	{
		this->occupied = occupiedState;
	}

	// Utility Functions
	unsigned getTotalChoices();

	// Public Member Variables
	vector<string> firstChoice;
	vector<string> secondChoice;

private:
	string name;
	string type;
	bool occupied;
};

