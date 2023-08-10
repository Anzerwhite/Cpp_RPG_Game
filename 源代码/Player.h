#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
#include<string>
#include<cstring>
#include<Windows.h>
#include<vector>
#include<thread>
#include"Tool.h"
#include"learningStatus.h"
#include<ctime>
using std::string;
using std::vector;
using std::pair;
/*1.	角色类
1.1	角色基础属性
 1.1.1	姓名,性别,年龄,学号,年级等基础信息
 1.1.2	生命值——生命值为0时角色死亡，达成死亡结局
 1.1.3	学业情况——反映各学科成绩，鉴于学业情况高低可触发挂科，退学，得奖，保研等事件，作为触发有关结局的条件
 1.1.4	金钱——用于日常消费，触发有关事件

1.2	角色附加属性（视情况添加）
 1.2.1	家境——反映家庭条件和家庭关系，影响金钱
 1.2.2	人物形状——显示出来的样子
 1.2.3	健康值——反映角色健康状况，与生命值直接相关，低于某一阈值时会触发疾病，使生命值持续降低；高于某一阈值时生命值持续回复
 1.2.4	强壮指数——反映角色抵御疾病或气候变化的能力，与健康值直接相关
 1.2.5	饱食度——不吃饭或吃不饱会扣健康值和强壮指数
 1.2.6	情绪值——影响有关活动的收益，受事件影响
 //1.2.7	人际关系（实现应该较为复杂，若要实现则需作为一大块）——角色的人际关系，可以影响情绪值等属性
1.3	角色属性间的影响（算法）
*/

enum familyStatus{RICH, NORMAL, POOR};
enum Gender{GIRL, BOY};

enum BAGARTICLE { BAGNONE, BAGRADIO, COLA, BAGPAPER };
class Player
{
public:
	Player();//无参构造函数(暂未处理，可用于读取存档)
	void setName(string _name) { name = _name; }
	void setGender(Gender _gender) { gender = _gender; }
	void setAge(int _age) { age = _age; }
	void setID(int _ID) { ID = _ID; }
	void setGrade(Grade _grade) { grade = _grade; }
	//void setHP(int _HP) { HP = _HP; }
	void setMoney( int _money) { money = _money; }
	void setHealth(int _health) { health = _health; }
	void setHunger(int _hunger) { hunger = _hunger; }
	void setEmotion(int _emotion) { emotion = _emotion; }
	void setPosition(short x, short y) { position.X = x; position.Y = y; };//set函数
	void setEnergy(int _energy) { energy = _energy; }

	string getName() const { return name; }
	Gender getGender() const { return gender; }
	string getGenderName() const;
	int getAge() const { return age; }
	long getID() const { return ID; }
	unsigned int getGrade() const { return gameTime / 5760; }
	string getGradeName() const;
	//int getHP() const { return HP; }
	learningStatus& getStatus_learning() { return Status_learning; }
	int getMoney() const { return money; }
	familyStatus getStatus_family() const { return Status_family; }
	string getStatus_familyName() const;
	int getHealth() const { return health; }
	//int getStrong() const { return strong; }
	int getHunger() const { return hunger; }
	int getEmotion() const { return emotion; }
	BAGARTICLE& getAddArticleToBag() { return addArticleToBag; }
	COORD getPosition() const { return position; }//get函数
	int getEnergy() const { return energy; }
	void printPlayer() const;//将人物打印在控制台
	
	void GoLeft() { setPosition(position.X - 2, position.Y); /*printPlayer();*/ }
	void GoRight() { setPosition(position.X + 2, position.Y);/* printPlayer()*/;}
	void GoUp() { setPosition(position.X, position.Y - 1);/*printPlayer();*/}
	void GoDown() { setPosition(position.X, position.Y + 1); /*printPlayer();*/}//设置角色上下左右移动后的坐标 

	pair<int, unsigned long> getClass() const;//获取课表类型和时间
	unsigned long gameTime;//游戏时间
	//学期：gameTime / 5760
	//季度；gameTime / 1440 % 4
	//小时：gameTime / 60 % 24
	//分钟：gameTime % 60
private:
	//基本属性
	string name;//姓名
	Gender gender;//0为女，1为男
	int age;//年龄
	long ID;//学号（不要过长）
	Grade grade;//年级,暂时不分上下学期

	//int HP;//生命值
	learningStatus Status_learning;//学业水平
	int money;//金钱

	familyStatus Status_family;//家境
	int health;//健康值
	int hunger;//饱食度
	int emotion;//情绪
	int energy;//精力(睡眠)
	COORD position;

	BAGARTICLE addArticleToBag = BAGNONE;//往背包添加物品

	
};

#endif // !PLAYER_H