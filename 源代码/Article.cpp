#include "Article.h"
using std::cout;
Article::Article(string _articleName, string  _articleExplain)
{
	setArticleName(_articleName);
	setArticleExplain(_articleExplain);
}



void Article::printExplain() const
{
	//暂时只输出到第一行
	Tool::setCursorPos(73, 6);
	cout << articleExplain;
	Tool::setCursorPos(95, 17);//94 <= x <= 97 && y == 17
	cout << "购买";//打印购买选项
}

