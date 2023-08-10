#pragma once
#include <string>
#include <iostream>
#include"Player.h"
#include"Tool.h"
using std::string;
//enum ARTICLETYPE { FOOD = 1, ELECTRIC, STUDY, RADIO};

class Article
{
public:
	//物品的构造函数与析构函数
	Article(string _articleName, string _articleExplain);
	virtual ~Article() {};
	//设置物品的ID
	void setArticleName(string& _articleName) { articleName = _articleName; }
	void setArticleExplain(string _articleExplain) { articleExplain = _articleExplain; }//设置物品说明
	//得到物品的ID
    string getArticleName() const { return articleName; }
	string getArticleExplain() const { return articleExplain; }//得到物品说明
	virtual void printExplain() const;//打印说明
	//信息
	//功能(公式)
	virtual void articleFunction(Player& player) {/*None*/ };//实现功能
private:
	string articleName;//物品的名称
	string articleExplain;//物品的作用说明
};

