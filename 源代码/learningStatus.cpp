#include "learningStatus.h"
//大一: C++, 工科数学分析, 线性代数, 大学物理, 大学英语, 大学体育(六门)
//大二: 数据结构, 离散数学, 计算机操作系统, 计算机组成原理(四门)
//大三: 编译原理,计算机网络, 大数据开发(三门)
//大四: 无
using std::cerr;
using std::invalid_argument;
learningStatus::learningStatus()
{
	//添加学科
	subjectArray.push_back(subject("C++", 50));
	subjectArray.push_back(subject("工科数学分析", 50));
	subjectArray.push_back(subject("线性代数", 50));
	subjectArray.push_back(subject("大学物理", 50));
	subjectArray.push_back(subject("大学英语", 50));
	subjectArray.push_back(subject("概率论与数理统计", 50));//大一											  
	
	subjectArray.push_back(subject("数据结构", 50));
	subjectArray.push_back(subject("离散数学", 50));
	subjectArray.push_back(subject("计算机操作系统", 50));
	subjectArray.push_back(subject("计算机组成原理", 50));//大二
	
	subjectArray.push_back(subject("编译原理", 50));
	subjectArray.push_back(subject("计算机网络", 50));
	subjectArray.push_back(subject("大数据开发", 50));//大三
}

int learningStatus::calNumFail(int subject_start, int subject_end)
{
	int num = 0;
	for (int i = subject_start; i < subject_end; i++)
	{
		if (getSubjectArray()[i].score == FAIL)
			num++;
	}
	return num;
}

int learningStatus::calNumExellent(int subject_start, int subject_end)
{
	int num = 0;
	for (int i = subject_start; i < subject_end; i++)
	{
		if (getSubjectArray()[i].score == EXCELLENT)
			num++;
	}
	return num;
}

int learningStatus::calNumPass(int subject_start, int subject_end) 
{
	int num = 0;
	for (int i = subject_start; i < subject_end; i++)
	{
		if (getSubjectArray()[i].score == PASS)
			num++;
	}
	return num;
}

int learningStatus::calTotalGPA(int subject_start, int subject_end)
{
	int totalGPA = 0;
	for (int i = subject_start; i < subject_end; i++)
	{
		totalGPA += getSubjectArray()[i].subjectGPA;
	}
	return totalGPA;
}
