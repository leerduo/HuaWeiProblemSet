# 背景介绍

   RTOSck是中软欧拉开发部自研的一款嵌入式实时操作系统。主要面向中低端嵌入式环境，具有体积小、效率高、易维测等特定。为了实现无上下文及栈切换的高效业务处理，RTOSck支持一种称为软中断的线程机制。软中断具有与中断类似的特性，支持优先级及优先级抢占，处理过程不能挂起。与硬中断通过硬件激活不同，软中断需要通过主动调用软中断激活函数进行激活。

 

# 题目描述

  请模拟实现一个简单软中断调度器。该软中断调度器支持32个优先级（0~31，数值越小，优先级越高）。并支持如下调度行为：
  1、在低优先级软中断中激活高优先级软中断，高优先级软中断将立即抢占执行；
  2、在高优先级软中断中激活低优先级软中断，需要在高优先级软中断执行完成后才能得到调度；
  3、低优先级软中断需要在所有直接或间接抢占的所有高优先级软中断执行完成后，再次恢复执行；
  4、同优先级软中断按照先入先出顺序进行调度；
  5、同一软中断可以连续多次激活，并响应同样多次。


 
# 实现接口

 ## 软中断创建
 
 ```C++
   int SwiCreate(unsigned int swiId, unsigned int prio, void (* proc)(void))；
    swiId为软中断ID，用于唯一标识一个软中断。测试用例保证取值范围[0-99]；
    prio为优先级；
    proc为软中断处理函数；处理函数里面可能会调用SwiActivate激活其它软中断，测试用例保证不会出现函数内部死循环，或者环状互相激活而造成死循环；
    成功返回0， 其它情况返回-1(重复创建、优先级无效、proc为空等）
```

## 软中断激活
  ```C++
    int SwiActivate(unsigned int swiId)；
     swiId为待激活软中断ID；
     成功返回0， 其它情况返回-1（未创建等）
```
## 清空所有信息

```C++
    void Clear(void)；
```
 


```C++
#include <iostream>
#include <cstdlib>
#include <map>
#include <queue>

using namespace std;



//软中断调度器支持32个优先级（0~31，数值越小，优先级越高）。并支持如下调度行为：
//1、在低优先级软中断中激活高优先级软中断，高优先级软中断将立即抢占执行；
//2、在高优先级软中断中激活低优先级软中断，需要在高优先级软中断执行完成后才能得到调度；
//3、低优先级软中断需要在所有直接或间接抢占的所有高优先级软中断执行完成后，再次恢复执行；
//4、同优先级软中断按照先入先出顺序进行调度；
//5、同一软中断可以连续多次激活，并响应同样多次。

class process
{
public:	
	int swiId;
	unsigned int prio;
	void(*proc)(void);
	friend bool operator < (process proc1, process proc2)
	{
		return proc1.prio > proc2.prio;
	}
};
//存储所有的中断
map<int, process> process_save_map;
//优先队列中的process按照prio比较
priority_queue<process> priqueue;
//设置当前中断的id
int currentID = 100;

/*************************************************************************************************
函数说明：创建软中断
输入参数：
swiId： 创建软中断ID；
prio：  创建软中断优先级；
proc：  创建软中断处理函数。
输出参数：无
返回值  ：成功返回0， 其它情况返回-1
**************************************************************************************************/
int SwiCreate(unsigned int swiId, unsigned int prio, void(*proc)(void))
{
	if (swiId > 99 || prio > 31 || prio < 0 || proc == NULL)
	{
		return -1;
	}
	process add;
	add.swiId = swiId;
	add.prio = prio;
	add.proc = proc;
	//判断里面是不是存在这个id
	if (process_save_map.count(add.swiId) != 0)
	{
		return -1;
	}
	else
	{
		//如果符合条件则添加进map
		process_save_map[add.swiId] = add;
	}
	return 0;
}

/*************************************************************************************************
函数说明：软中断激活
输入参数：swiId： 待激活软中断ID
输出参数：无
返回值  ：成功返回0， 其它情况返回-1
**************************************************************************************************/
int SwiActivate(unsigned int swiId)
{
	if (process_save_map.count(swiId) ==0)
	{
		return -1;
	}
	priqueue.push(process_save_map[swiId]);
	while (!priqueue.empty())
	{
		process topprocess = priqueue.top();
		if (currentID != topprocess.swiId)
		{
			int tmp = currentID;
			currentID = topprocess.swiId;
			topprocess.proc();
			currentID = tmp;
			priqueue.pop();
		}
		else
		{
			//是同一个的时候继续
			break;
		}
	}
	return 0;
}

/*************************************************************************************************
函数说明：清空所有的信息
输入参数：无
输出参数：无
返回值  ：无
**************************************************************************************************/
void Clear(void)
{
	currentID = 100;
	process_save_map.clear();
	while (!priqueue.empty())
	{
		priqueue.pop();
	}
}
```
