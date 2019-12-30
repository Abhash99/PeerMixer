#include "stdafx.h"
#include "Peer.h"

// Utility Functions
unsigned Peer::getTotalChoices()
{
	unsigned total = firstChoice.size() + secondChoice.size();
	return total;
}