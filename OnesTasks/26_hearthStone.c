/*26.炉石传说 问题描述
　　《炉石传说：魔兽英雄传》（Hearthstone: Heroes of Warcraft，简称炉石传说）是暴雪娱乐开发的一款集换式卡牌游戏（如下图所示）。游戏在一个战斗棋盘上进行，由两名玩家轮流进行操作，本题所使用的炉石传说游戏的简化规则如下：

　　* 玩家会控制一些角色，每个角色有自己的生命值和攻击力。当生命值小于等于 0 时，该角色死亡。角色分为英雄和随从。
　　* 玩家各控制一个英雄，游戏开始时，英雄的生命值为 30，攻击力为 0。当英雄死亡时，游戏结束，英雄未死亡的一方获胜。
　　* 玩家可在游戏过程中召唤随从。棋盘上每方都有 7 个可用于放置随从的空位，从左到右一字排开，被称为战场。当随从死亡时，它将被从战场上移除。
　　* 游戏开始后，两位玩家轮流进行操作，每个玩家的连续一组操作称为一个回合。
　　* 每个回合中，当前玩家可进行零个或者多个以下操作：
　　1) 召唤随从：玩家召唤一个随从进入战场，随从具有指定的生命值和攻击力。
　　2) 随从攻击：玩家控制自己的某个随从攻击对手的英雄或者某个随从。
　　3) 结束回合：玩家声明自己的当前回合结束，游戏将进入对手的回合。该操作一定是一个回合的最后一个操作。
　　* 当随从攻击时，攻击方和被攻击方会同时对彼此造成等同于自己攻击力的伤害。受到伤害的角色的生命值将会减少，数值等同于受到的伤害。例如，随从 X 的生命值为 HX、攻击力为 AX，随从 Y 的生命值为 HY、攻击力为 AY，如果随从 X 攻击随从 Y，则攻击发生后随从 X 的生命值变为 HX - AY，随从 Y 的生命值变为 HY - AX。攻击发生后，角色的生命值可以为负数。
　　本题将给出一个游戏的过程，要求编写程序模拟该游戏过程并输出最后的局面。

输入格式

　　输入第一行是一个整数 n，表示操作的个数。接下来 n 行，每行描述一个操作，格式如下：
　　<action> <arg1> <arg2> ...
　　其中<action>表示操作类型，是一个字符串，共有 3 种：summon表示召唤随从，attack表示随从攻击，end表示结束回合。这 3 种操作的具体格式如下：
　　* summon <position> <attack> <health>：当前玩家在位置<position>召唤一个生命值为<health>、攻击力为<attack>的随从。其中<position>是一个 1 到 7 的整数，表示召唤的随从出现在战场上的位置，原来该位置及右边的随从都将顺次向右移动一位。
　　* attack <attacker> <defender>：当前玩家的角色<attacker>攻击对方的角色 <defender>。<attacker>是 1 到 7 的整数，表示发起攻击的本方随从编号，<defender>是 0 到 7 的整数，表示被攻击的对方角色，0 表示攻击对方英雄，1 到 7 表示攻击对方随从的编号。
　　* end：当前玩家结束本回合。
　　注意：随从的编号会随着游戏的进程发生变化，当召唤一个随从时，玩家指定召唤该随从放入战场的位置，此时，原来该位置及右边的所有随从编号都会增加 1。而当一个随从死亡时，它右边的所有随从编号都会减少 1。任意时刻，战场上的随从总是从1开始连续编号。

输出格式

　　输出共 5 行。
　　第 1 行包含一个整数，表示这 n 次操作后（以下称为 T 时刻）游戏的胜负结果，1 表示先手玩家获胜，-1 表示后手玩家获胜，0 表示游戏尚未结束，还没有人获胜。
　　第 2 行包含一个整数，表示 T 时刻先手玩家的英雄的生命值。
　　第 3 行包含若干个整数，第一个整数 p 表示 T 时刻先手玩家在战场上存活的随从个数，之后 p 个整数，分别表示这些随从在 T 时刻的生命值（按照从左往右的顺序）。
　　第 4 行和第 5 行与第 2 行和第 3 行类似，只是将玩家从先手玩家换为后手玩家。

样例输入

8
summon 1 3 6
summon 2 4 2
end
summon 1 4 5
summon 1 2 1
attack 1 2
end
attack 1 1

样例输出

0
30
1 2
30
1 2

样例说明

按照样例输入从第 2 行开始逐行的解释如下：
　　1. 先手玩家在位置 1 召唤一个生命值为 6、攻击力为 3 的随从 A，是本方战场上唯一的随从。
　　2. 先手玩家在位置 2 召唤一个生命值为 2、攻击力为 4 的随从 B，出现在随从 A 的右边。
　　3. 先手玩家回合结束。
　　4. 后手玩家在位置 1 召唤一个生命值为 5、攻击力为 4 的随从 C，是本方战场上唯一的随从。
　　5. 后手玩家在位置 1 召唤一个生命值为 1、攻击力为 2 的随从 D，出现在随从 C 的左边。
　　6. 随从 D 攻击随从 B，双方均死亡。
　　7. 后手玩家回合结束。
　　8. 随从 A 攻击随从 C，双方的生命值都降低至 2。
**********************************/
//Minions: 随从结构体
//summon、attack、end：3个函数

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct minions
{
	int position;	//位置
	int attack;	//攻击力
	int health;	//生命值
	struct minions* pNext;	//指向下一个随从
}MINIONS, *PMINIONS;

typedef struct player	//玩家
{
	int hero;	//英雄血量
	PMINIONS minions;//随从链表
}PLAYER;

/*************声明函数***********/
bool summon(PLAYER*);	//召唤：链表插入
void attack(PLAYER*,PLAYER*,PLAYER*);	//攻击
PLAYER* end(PLAYER*,PLAYER*,PLAYER*);		//换人：指向另一个结构体
bool delete_minion(PMINIONS pHead, int pos);
/*******************************/

int main(void)
{
	int operations;
	//2个玩家初始化
	PLAYER * p1=(PLAYER*)malloc(sizeof(PLAYER));//p1指向玩家1
	PLAYER * p2=(PLAYER*)malloc(sizeof(PLAYER));//p2指向玩家2
	p1->hero = p2->hero = 30;
	//生成随从链表头结点，再将其赋值给p1,p2
	PMINIONS p1Head = (PMINIONS)malloc(sizeof(MINIONS));
	p1->minions = p1Head;
	PMINIONS p1Tail = p1Head;
	p1Tail->pNext = NULL;

	PMINIONS p2Head = (PMINIONS)malloc(sizeof(MINIONS));
	p2->minions = p2Head;
	PMINIONS p2Tail = p2Head;
	p2Tail->pNext = NULL;

	PLAYER * pcurr = p1;	//当前操作者初始为p1
	
	printf("请输入操作次数：");
	scanf("%d",&operations);
	
	//for循环接收指令并执行相应函数
	for(int i=0; i<8; i++)
	{
		char opcode[10];	//操作码
		scanf("%s",opcode);	//读操作码
		
		if("summon" == opcode)
		{
			summon(pcurr);
		}
		else if("attack" == opcode)
		{
			attack(pcurr,p1,p2);
		}
		else if("end" == opcode)
		{
			end(pcurr,p1,p2);
		}
	}
	return 0;
}
bool summon(PLAYER* pcurr)//插入节点
{
	int pos,attack,health;
	int i = 0;
	PMINIONS p = pcurr->minions;

	scanf("%d %d %d", &pos, &attack, &health);
	
	while(NULL != p && i<pos-1)
	{
		p = p->pNext;
		++i;
	}
	if(i>pos-1 || NULL==p)
		return false;
	PMINIONS pNew = (PMINIONS)malloc(sizeof(MINIONS));
	if(NULL == pNew)
	{
		printf("动态分配内存失败！\n");
		exit(-1);
	}
	pNew->position=pos;
	pNew->attack=attack;
	pNew->health=health;
	PMINIONS q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;
	
	return true;
}
void attack(PLAYER* pcurr,PLAYER* p1, PLAYER* p2)//谁伤害谁
{
	int pos1, pos2;
	scanf("%d %d", &pos1, &pos2);

	if(pcurr == p1)//p1的pos1攻击p2的pos2
	{
		((p2->minions)+pos2)->health -= ((p1->minions)+pos1)->attack;
		if(((p2->minions)+pos2)->health <= 0)
			delete_minion(p2->minions, pos2);
		((p1->minions)+pos1)->health -= ((p2->minions)+pos2)->attack;
		if( ((p1->minions)+pos1)->health <= 0 )
			delete_minion(p1->minions, pos2);
	}
	else if(pcurr == p2)//p2的pos1攻击p1的pos2
	{
		((p1->minions)+pos2)->health -= ((p2->minions)+pos1)->attack;
		if(((p2->minions)+pos2)->health <= 0)
			delete_minion(p2->minions, pos2);
		((p2->minions)+pos1)->health -= ((p1->minions)+pos2)->attack;
		if( ((p1->minions)+pos1)->health <= 0 )
			delete_minion(p1->minions, pos2);
	}
}
bool delete_minion(PMINIONS pHead, int pos)
{
	int i = 0;
	PMINIONS p = pHead;

	while(NULL != p->pNext && i<pos-1)
	{
		p = p->pNext;
		++i;
	}
	if(i>pos-1 || NULL== p->pNext)
		return false;
	PMINIONS q = p->pNext;
	p->pNext = p->pNext->pNext;
	free(q);
	q=NULL;

	return true;
}
PLAYER* end(PLAYER* pcurr,PLAYER* p1,PLAYER* p2)
{
	if(pcurr == p1)
		pcurr = p2;
	else if(pcurr == p2)
		pcurr = p1;

	return pcurr;
}
