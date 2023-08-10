#ifndef MANAGER_H
#define MANAGER_H
#include"Player.h"
#include<vector>
#include"Tool.h"
#include<conio.h>
#include"Article.h"
#include<iomanip>
#include<Windows.h>
#include"LivingArea.h"
#include"TeachingArea.h"
#include<fstream>
#include<thread>
using std::vector;
//#define articleArray Manager::getPlayer().getArticleArray()
enum WhichMap { LIVINGAREA, TEACHINGAREA };
enum LivingPlace {NONE_LIVING = -1,BRIDGE_LIVING = 0, DORM, GYM, CANTEEN, SUPERMARKET, HOSPITAL };
enum TeachingPlace { NONE_TEACHING = -1, BRIDGE_TEACHING = 0, CLASSROOM, LIBRARY, LABORTORY };

class Manager
{
public:
	Manager();//构造函数
	~Manager();//析构函数
	Player& getPlayer() { return player; };// 获取人物
	WhichMap getWhichMap() const { return whichMap; };//获取地图类型
	bool isOutofRange(int x, int y) const;//判断是否越过边界

	void showAttribute() const;//在上方显示属性栏(待做)

	//背包部分
	
	void printArticle() const;//将物品打印到背包中
	void printBag() const;//显示背包(设置样式)
	void bag();//背包
	void addToBag();//往背包里加东西

	void GameMenu();//游戏菜单, 包括开始新游戏, 读取存档, 退出游戏, 游戏帮助(教程) (待做)
	void GameStart();//开始游戏(待做)

	void Game();//游戏进行

	void GameEnd();//退出游戏(待做)

	void printWhole() const;//打印地图和人物

	int isPlace() const;//(待做)[潜在问题:多次访问]
	
	void inPlace();//在某个地点里

	void showTime() const;//显示时间
	void showTask() const;//显示任务栏

	void saveGame();//保存函数
	void deleteFile();//删除存档
private:
	Player player;
	vector<Article*> articleArray;//存放物品的数组
	WhichMap whichMap;//地图状态
	LivingArea livingArea;//生活区地图
	TeachingArea teachingArea;//教学区地图
};
#endif // !MANAGER_H