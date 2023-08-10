#pragma once
#include <string>

using namespace std;

class NPC
{
public:
	//构造函数
	NPC(string& name, string& gender, string& relationship, string& job);
	//所有的set函数表示设置某个变量
	//所有的get函数表示得到某个变量
	void setname(string& name);
	string getname();
	void setgender(string& gender);
	string getgender();
	void setrelationship(string& relationship);
	string getrelationship();
	void setjob(string& job);
	string getjob();
protected:
	//NPC的姓名
	string NPC_name;
	//NPC的性别
	string NPC_gender;
	//NPC和主角的关系
	string NPC_relationship;
	//NPC的工作
	string NPC_job;
};

