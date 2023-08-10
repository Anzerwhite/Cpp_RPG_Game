#include "NPC.h"
#include <string>
using namespace std;

NPC::NPC (string& name, string& gender, string& relationship, string& job)
{
	setname(name);
	setgender(gender);
	setrelationship(relationship);
	setjob(job);
}

void NPC::setname(string& name)
{
	NPC_name = name;
}

string NPC::getname()
{
	return NPC_name;
}

void NPC::setgender(string& gender)
{
	NPC_gender = gender;
}

string NPC::getgender()
{
	return NPC_gender;
}

void NPC::setrelationship(string& relationship)
{
	NPC_relationship = relationship;
}

string NPC::getrelationship()
{
	return NPC_name;
}

void NPC::setjob(string& job)
{
	NPC_job = job;
}

string NPC::getjob()
{
	return NPC_job;
}