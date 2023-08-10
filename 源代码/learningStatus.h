#ifndef LEARNINGSTATUS_H
#define LEARNINGSTATUS_H
#include<vector>
#include<iostream>
#include<stdexcept>
using std::vector;
using std::string;
//表示学业情况
enum GPA{NONE, FAIL, PASS, EXCELLENT};//表示未考试, 优秀，及格和不及格
//表示年级
enum Grade{GRADE_1 = 0, GRADE_2, GRADE_3, GRADE_4 };//依次表示从大一到大四

struct subject//学科的结构体
{
	subject(string _name, int _score , GPA _subjectGPA = NONE)
		:name(_name), score(_score), subjectGPA(_subjectGPA)
	{
		//empty
	}
	int conversion(int _score)//转换函数，考完试总分定下来
	{
		if (_score >= 85)
		{
			this->subjectGPA = EXCELLENT;
		}
		else if (_score >= 60 && _score < 85)
		{
			this->subjectGPA = PASS;
		}
		else
		{
			this->subjectGPA = FAIL;
		}
		return subjectGPA;
	}
	string name;//学科名
	int score;//成绩
	GPA subjectGPA;
};


class learningStatus
{
public:
	learningStatus();//构造函数,根据年级添加科目, numSubject表示科目数量

	vector<subject>& getSubjectArray(){ return subjectArray; }//获取数组

	int calNumFail(int subject_start, int subject_end);//返回挂科数量
	int calNumPass(int subject_start, int subject_end);//返回及格数量
	int calNumExellent(int subject_start, int subject_end);//返回优秀数量
	int calTotalGPA(int subject_start, int subject_end);//返回总GPA，决定结局

private:
	vector<subject> subjectArray;//存放科目的数组
};

#endif // !LEARNINGSTATUS_H
