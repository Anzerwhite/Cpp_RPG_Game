#pragma once

#include"Article.h"
//用于放置物品的定义的类
using std::cout;
using std::string;
//Cola

class Cola :public Article
{
public:
	Cola(string _articleName, string _articleExplain)
		:Article(_articleName,_articleExplain){}
	virtual void articleFunction(Player& player) override
	{
		player.setEmotion(player.getEmotion() + 3);
		player.setHealth(player.getHealth() - 5);
		player.setMoney(player.getMoney() - 0.5);
	}
};

//问题：如何在背包中使用
class Paper :public Article
{
public:
	Paper(string _articleName, string _articleExplain)
		:Article(_articleName, _articleExplain) {}
	virtual void articleFunction(Player& player)
	{
		player.getAddArticleToBag() = BAGARTICLE::BAGPAPER;
		player.setMoney(player.getMoney() - 1);
	}
};

class Radio :public Article
{
public:
	Radio(string _articleName, string _articleExplain)
		:Article(_articleName, _articleExplain) {}
	virtual void articleFunction(Player& player)
	{
		player.getAddArticleToBag() = BAGARTICLE::BAGRADIO;
		player.setMoney(player.getMoney() - 1);
	}

};

//睡觉
class Bed : public Article
{
public:
	Bed(string _articleName, string _articleExplain)
		: Article(_articleName, _articleExplain) {}
	virtual void articleFunction(Player& player)
	{
		player.setEnergy(player.getEnergy() + 70);
		player.gameTime += 420;//7个小时
	}
	virtual void printExplain() const override
	{
		Article::printExplain();
		Tool::setCursorPos(95, 17);//94 <= x <= 97 && y == 17
		cout << "睡觉";//打印购买选项
	}
};


//打电动
class ComputerGame : public Article
{
public:
	ComputerGame(string _articleName, string _articleExplain)
		: Article(_articleName, _articleExplain) {}
	virtual void articleFunction(Player& player)
	{
		player.setEmotion(player.getEmotion() + 5);
		player.setEnergy(player.getEnergy() - 8);
		player.gameTime += 60;//1个小时
	}
	virtual void printExplain() const override
	{
		Article::printExplain();
		Tool::setCursorPos(95, 17);//94 <= x <= 97 && y == 17
		cout << "开打";//打印购买选项
	}
};

//食物
class StonepotRice : public Article
{
public:
	StonepotRice(string _articleName, string _articleExplain)
		: Article(_articleName, _articleExplain) {}
	virtual void articleFunction(Player& player)
	{
		player.setHunger(player.getHunger() + 20);
		player.setEmotion(player.getEmotion() + 2);
		player.setMoney(player.getMoney() - 1.5);
		player.gameTime += 30;
	}
};

class OilBing : public Article
{
public:
	OilBing(string _articleName, string _articleExplain)
		: Article(_articleName, _articleExplain) {}
	virtual void articleFunction(Player& player)
	{
		player.setHunger(player.getHunger() + 10);
		player.setEmotion(player.getEmotion() + 2);
		player.setMoney(player.getMoney() - 0.5);
		player.gameTime += 15;
	}
};

class Duck : public Article
{
public:
	Duck(string _articleName, string _articleExplain)
		: Article(_articleName, _articleExplain) {}
	virtual void articleFunction(Player& player)
	{
		player.setHunger(player.getHunger() + 15);
		player.setEmotion(player.getEmotion() + 2);
		player.gameTime += 25;
		player.setMoney(player.getMoney() - 1);
	}
};
class Hamburger : public Article
{
public:
	Hamburger(string _articleName, string _articleExplain)
		: Article(_articleName, _articleExplain) {}
	virtual void articleFunction(Player& player)
	{
		player.setHunger(player.getHunger() + 15);
		player.setEmotion(player.getEmotion() + 2);
		player.setMoney(player.getMoney() - 1);
		player.gameTime += 25;
	}
};
class BridgeNoodles : public Article
{
public:
	BridgeNoodles(string _articleName, string _articleExplain)
		: Article(_articleName, _articleExplain) {}
	virtual void articleFunction(Player& player)
	{
		player.setHunger(player.getHunger() + 15);
		player.setEmotion(player.getEmotion() + 2);
		player.setMoney(player.getMoney() - 1);
		player.gameTime += 25;
	}
};
class BlackFish : public Article
{
public:
	BlackFish(string _articleName, string _articleExplain)
		: Article(_articleName, _articleExplain) {}
	virtual void articleFunction(Player& player)
	{
		player.setHunger(player.getHunger() + 20);
		player.setEmotion(player.getEmotion() + 2);
		player.setMoney(player.getMoney() - 1.5);
		player.gameTime += 30;
	}
};
class PigLegRice : public Article
{
public:
	PigLegRice(string _articleName, string _articleExplain)
		: Article(_articleName, _articleExplain) {}
	virtual void articleFunction(Player& player)
	{
		player.setHunger(player.getHunger() + 20);
		player.setEmotion(player.getEmotion() + 2);
		player.setMoney(player.getMoney() - 1.5);
		player.gameTime += 30;
	}
};