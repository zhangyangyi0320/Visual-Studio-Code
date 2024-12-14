#include <bits/stdc++.h> 
#include<windows.h>//Sleep(延迟优化)  system("pause");   system("cls")(界面优化)
using namespace std; 
double shengmingli=2000;//定义主角初始生命力 
int gongjili=150;//定义主角初始攻击力 
int fangyuli=50;//定义主角初始防御力 
int money=0;//定义主角初始金钱数量 
int yaoji[100]={0,1,1,1,1,1,1};
int kuangbao,gongji,fangyu,jinqian,zaisheng,yinshen,kong;
int dp;
int sw=1;
bool guoguan;//定义是否通关判定 
bool shitu=false;
void wuqidian();//定义武器店函数 
void yaodian();//定义药店函数 
void yaojidian();
void guaiwu1();//定义小怪物函数 
void guaiwu2();//定义大怪物函数 
void guaiwu3();
void god();
void last();
bool siwang=0;//记录死亡，及时结束游戏 

void huijia(){
	kuangbao=0,gongji=0,fangyu=0,jinqian=0,zaisheng=0,yinshen=0;
	system("cls");
	cout<<"欢迎你开始玩打怪物小游戏！\n"; 
	cout<<"小镇\n"; 
	cout<<"一个1000年的只因镇。周围有一条河，有一片树林，很多房子和很多小黑子。\n和很多家黑店(bushi)"<<endl; 
	cout<<"1.去武器店"<<endl; 
	cout<<"2.去药品店"<<endl; 
	cout<<"3.去药剂店"<<endl; 
	cout<<"4.去打僵尸"<<endl; 
	cout<<"5.去打骷髅"<<endl; 
	cout<<"6.去打铁傀儡"<<endl; 
	cout<<"7.退出游戏(有彩蛋)"<<endl; 
	cout<<"8.显示你的状态"<<endl; 
}

void die(){
	cout<<"你死啦！"<<endl; 
	Sleep(1000);
	cout<<"算了"<<endl; 
	Sleep(1000);
	cout<<"为了不让游戏这么快结束"<<endl; 
	Sleep(1000);
	cout<<"让你再复活一次"<<endl; 
	Sleep(1000);
	system("clear");
	shengmingli=2000;
}

int main() 
{ 
    cout<<"欢迎你开始玩打怪物小游戏！\n"; 
    huijia();
    int xiaozhen;//定义选择项目 
	cin>>xiaozhen; 
	while(xiaozhen!=7)//输入5时退出游戏 
	{ 
		if(shengmingli<=0){//主角生命力小于等于0时游戏结束 { 
			die();
		}
		if(xiaozhen==8)
		{ 
			cout<<"你的生命力:"<<shengmingli<<endl; 
			cout<<"你的攻击力:"<<gongjili<<endl; 
			cout<<"你的防御力:"<<fangyuli<<endl; 
			cout<<"你拥有的钱:"<<money<<endl; 
			cout<<"盾牌耐久还剩:"<<dp<<endl;
		} 
		else{ 
			switch(xiaozhen) 
			{ 
				case 1 : wuqidian();break; 
				case 2 : yaodian();break; 
				case 3 : yaojidian();break; 
				case 4 : guaiwu1();break;
				case 5 : guaiwu3();break;
				case 6 : guaiwu2();break;
				case 666 : god();break; 
				default : cout<<"请不要乱选！"<<endl;break; 
			} 
		}
		cin>>xiaozhen; 
	}	 
	if(xiaozhen==7) 
	{ 
		system("cls");
		cout<<"正在退出游戏……"<<endl;
		cout<<"进度："<<0<<"%";
		Sleep(1000);
		system("cls");
		for(int i=0;i<100;i++){
			cout<<"正在退出游戏……"<<endl; 
			cout<<"进度："<<i<<"%";
			if(i==99){
				Sleep(3000);
				cout<<endl<<"行 70 列 5 信息[Error]wxpected';'before'cout'"<<endl;
				Sleep(500);
				cout<<"???";
				Sleep(500);
				cout<<"检查错误中"<<endl;
				Sleep(2000);
				cout<<"退出失败\n";
				Sleep(2000);
				cout<<"才怪"<<endl;
				Sleep(500);
				return 0;
			}
			Sleep(5);
			system("cls");
			
		}
		
	}
	return 0; 
} 

void yaojidian(){
	system("cls");
	cout<<"欢迎来到药剂店！（药剂在战斗时使用）"<<endl; 
	cout<<"1、买攻击药剂（使攻击力增加1.5倍）40元"<<endl; 
	cout<<"2、买狂暴药剂（使攻击力增加3倍，但是受到的伤害增加2倍）50元"<<endl; 
	cout<<"3、买防御药剂（使防御力增加3倍，时长10回合) 100元"<<endl; 
	cout<<"4、买金钱药剂（使战斗获得的金钱增加2倍） 110元"<<endl; 
	cout<<"5、买再生药剂（使战斗时每回合回50滴血，时长10回合） 200元"<<endl; 
	cout<<"6、买隐身药剂（使下回合先攻击3次，且每次攻击必定暴击） 200元"<<endl; 
	cout<<"7、离开药剂店"<<endl; 
	int wuqidian; 
	cin>>wuqidian; 
	while(wuqidian!=7){//输入7时结束函数  
		switch(wuqidian) {
			case 1 : 
				if(money<40)
					cout<<"你的钱不够"<<endl;//钱不够时返回Flase 
				else{
					cout<<"购买成功！"<<endl;//钱足够时返回True 
					yaoji[1]++;
					money-=40;	
				}break; 
			case 2 :
				if(money<50) 
					cout<<"你的钱不够"<<endl; 
				else{
					cout<<"购买成功！"<<endl; 
					yaoji[2]++;
					money-=50; 
				}break;
			case 3 : 
				if(money<100) 
					cout<<"你的钱不够"<<endl; 
	    		else{
					cout<<"购买成功！"<<endl; 
					yaoji[3]++;
					money-=100; 
				}break;
			case 4 : 
				if(money<110) 
					cout<<"你的钱不够"<<endl; 
				else{
					cout<<"购买成功！"<<endl; 
					yaoji[4]++;
					money-=110; 
				}break; 
			case 5 : 
				if(money<200) 
					cout<<"你的钱不够"<<endl; 
				else{
					cout<<"购买成功！"<<endl; 
					yaoji[5]++;
					money-=200; 
				}break;
			case 6 :
				if(money<200)
					cout<<"你的钱不够"<<endl;
				else{
					cout<<"购买成功！"<<endl; 
					yaoji[6]++;
					money-=200;
				}break;
			break;
			default : 
				cout<<"无"<<endl; 
	    		break;
		}
	cin>>wuqidian; 
	} 
	if(wuqidian==7) 
	{	  //返回main()主函数 
		cout<<"欢迎下次再来！"<<endl; 
		Sleep(1000);
		huijia();
	} 
}

void wuqidian()
{ 
	system("cls");
	cout<<"欢迎来到武器店！"<<endl; 
	cout<<"1、买小刀（10块钱加2攻击力）"<<endl; 
	cout<<"2、买短剑（20块钱加20攻击力）"<<endl; 
	cout<<"3、买大砍刀（50块钱加60攻击力)"<<endl; 
	cout<<"4、买双节棍（70块钱加100攻击力）"<<endl; 
	cout<<"5、买皮革套（20块钱加30防御力）"<<endl; 
	cout<<"6、买锁链铠甲（50块钱加60防御力）"<<endl;
	cout<<"7、买盾牌（100块钱受到攻击时40%减伤60%，20%免疫，触发20次后损坏）"<<endl;
	cout<<"8、离开武器店"<<endl; 
	int wuqidian; 
	cin>>wuqidian; 
	while(wuqidian!=8){//输入7时结束函数  
		switch(wuqidian) {
			case 1 : 
				if(money<10)
					cout<<"你的钱不够"<<endl;//钱不够时返回Flase 
				else{
					cout<<"购买成功！"<<endl;//钱足够时返回True 
					gongjili+=2; 
					money-=10;	
				}break; 
			case 2 :
				if(money<20) 
					cout<<"你的钱不够"<<endl; 
				else{
					cout<<"购买成功！"<<endl; 
					gongjili+=20; 
					money-=20; 
				}break;
			case 3 : 
				if(money<50) 
					cout<<"你的钱不够"<<endl; 
    			else{
					cout<<"购买成功！"<<endl; 
					gongjili+=60; 
					money-=50; 
				}break;
			case 4 : 
				if(money<70) 
					cout<<"你的钱不够"<<endl; 
				else{
					cout<<"购买成功！"<<endl; 
					gongjili+=100; 
					money-=70; 
				}break; 
			case 5 : 
				if(money<20) 
					cout<<"你的钱不够"<<endl; 
				else{
					cout<<"购买成功！"<<endl; 
					fangyuli+=30; 
					money-=20; 
				}break;
			case 6 :
				if(money<50)
					cout<<"你的钱不够"<<endl;
				else{
					cout<<"购买成功！"<<endl; 
					fangyuli+=60; 
					money-=50;
				}break;
			case 7 :
				if(money<100)
					cout<<"你的钱不够"<<endl;
				else{
					cout<<"购买成功！"<<endl; 
					dp+=20;
					money-=100;
				}break;
			break;
			default : 
				cout<<"无"<<endl; 
    			break;
		}
	cin>>wuqidian; 
	} 
	if(wuqidian==8) 
	{	  //返回main()主函数 
		cout<<"欢迎下次再来！"<<endl; 
		Sleep(1000);
		huijia();
	} 
} 
/* 
yaodian()的设置与wuqidian()相同,可参照阅读. 
*/ 
void yaodian() 
{ 
	system("cls");
	cout<<"欢迎来到药品店！"<<endl; 
	cout<<"1、买1号补血药（100加200生命）"<<endl; 
	cout<<"2、买2号补血药（500加1000生命力）"<<endl; 
	cout<<"3、买3号补血药（1000加2200生命力)"<<endl; 
	cout<<"4、离开武器店"<<endl; 
	int yaodian; 
	cin>>yaodian; 
	while(yaodian!=4) 
	{ 
		switch(yaodian) 
		{ 
			case 1 : 
				if(money<100)
					cout<<"你的钱不够"<<endl; 
				else{
					cout<<"购买成功！"<<endl; 
					shengmingli+=200; 
					money-=100; 
				}break;
			case 2 : 
				if(money<500) 
					cout<<"你的钱不够"<<endl; 
				else {
					cout<<"购买成功！"<<endl; 
					shengmingli+=1000; 
					money-=500; 
				}break; 
					
			case 3 : 
				if(money<1000) 
					cout<<"你的钱不够"<<endl; 
				else{
					cout<<"购买成功！"<<endl; 
					shengmingli+=2200; 
					money-=1000; 
				}break; 
			default : 
				cout<<"无"<<endl; 
				break; 
		} 
	cin>>yaodian; 
} 
	if(yaodian==4) 
	{	   
	cout<<"欢迎下次再来！"<<endl;
	Sleep(1000);
	huijia();
	} 
} 
/*这里是两个战斗函数,使用指针来处理.避免造成内存崩溃.*/ 
void guaiwu1() 
{ 	
	system("cls");
	cout<<"开始与僵尸战斗！！！"<<endl; 
	double* g_shengmingli=new double;//定义怪物生命 
	int* g_gongjili=new int;//定义怪物攻击力 
	int* g_fangyuli=new int;//定义怪物防御力 
    int* g_money=new int;//定义怪物金钱 
    int* baoji=new int;
    int* jianshang=new int;
	*g_shengmingli=900; 
	*g_gongjili=100;
	*g_fangyuli=3; 
	*g_money=20;
	double* tongji1=new double;//用来计算主角对怪物的杀伤 
	double* tongji2=new double;//用来计算怪物对主角的杀伤
	*tongji1=0; 
	*tongji2=0; 
	int* huihe=new int;//定义回合数 
	*huihe=1; 
	cout<<"你开始对僵尸进行攻击！"<<endl; 
	int* xuanze=new int; 
	int* xuanze2=new int;
/* 
攻击计算公式 
杀伤=攻击力*2-防御力 
玩家每回合可以选择攻击与逃跑 
*/ 
	while((*g_shengmingli)>0 && shengmingli>0 && (*xuanze)!=2) 
	{ 	
		cout<<"现在是"<<"第"<<*huihe<<"回合！"<<endl; 
		cout<<"请选择你的动作:\n"; 
		cout<<"1、攻击\n2、逃跑\n3、使用药剂\n"; 
		*baoji=rand()%3;
		*jianshang=rand()%100+1;
		cin>>*xuanze; 
		switch((*xuanze)) 
		{ 
			case 1 : 
				cout<<"你对僵尸发动了攻击！"<<endl; 
				Sleep(300);
				*tongji1=gongjili*2-(*g_fangyuli); 
				if(yinshen>0){
					*tongji1*=3;
					*baoji=1;
				}
				if(gongji>0) *tongji1*=gongji*1.5;
				if(kuangbao>0) *tongji1*=kuangbao*3;
				if(*baoji==1){
					cout<<"你对僵尸造成了暴击"<<endl;
					*tongji1*=1.5;
					Sleep(200);
				}
				if(*tongji1<0) *tongji1=0;
				if(yinshen>0){
					cout<<"你在隐身时对僵尸偷袭了三下，打掉了僵尸"<<*tongji1<<"的生命！"<<endl;
					yinshen--;
				}
				else cout<<"你打掉了僵尸"<<*tongji1<<"的生命！"<<endl;
				Sleep(300);
				*g_shengmingli-=*tongji1; 
				Sleep(300);
				if(*g_shengmingli<=0){//中途判定伤害是否足够杀死小怪(王路不把小镇输出放到主函数就很难受) 
					cout<<"僵尸还剩0点生命"<<endl; 
					if(shitu){
						cout<<"你将僵尸带到了白夜面前，它将僵尸转变为了使徒"<<endl;
						Sleep(400);
						sw++;
						huijia();
						return;
					}
					else{
						cout<<"僵尸被你杀死了！你真厉害！！！"<<endl;
						if(jinqian>0) *g_money*2;
						cout<<"金币+"<<*g_money;
						money+=(*g_money);
						Sleep(1500);
						huijia();
						return;
					}
				}
				cout<<"僵尸还剩"<<*g_shengmingli<<"点生命"<<endl; 
				Sleep(300);
				if(fangyu>0) *tongji2=(*g_gongjili)*2-fangyuli*3;
				else *tongji2=(*g_gongjili)*2-fangyuli;
				if(kuangbao>0) *tongji2*=kuangbao*2;
				if(*tongji2<0)*tongji2=0;
				if(*jianshang<=20 and *tongji2>0 and dp>0){
					cout<<"盾牌成功格挡了僵尸的攻击"<<endl;
					dp--,*tongji2=0;
					Sleep(300);
				}
				else if(*jianshang<=60 and *tongji2>0 and dp>0){
					cout<<"盾牌成功试僵尸的攻击减伤"<<endl;
					dp--,*tongji2*0.4;
					Sleep(300);
				}
				shengmingli-=*tongji2; 
				cout<<"僵尸对你发动了攻击！"<<endl;
				Sleep(300);

				cout<<"僵尸打掉了你"<<*tongji2<<"的生命！"<<endl; 
				Sleep(300);
				if(shengmingli<=0){//被怪物杀死后的返回 
					die();
				}Sleep(300);
				cout<<"你还剩"<<shengmingli<<"点生命"<<endl;break; 
				Sleep(300);
				system("cls");	
			
			case 2 : 
				cout<<"你决定逃跑！"<<endl; 
				cout<<"逃跑成功！"<<endl;break; 
			case 3 :
				Sleep(300);
				cout<<"1.攻击药剂（"<<yaoji[1]<<")瓶"<<endl;
				cout<<"2.狂暴药剂（"<<yaoji[2]<<")瓶"<<endl;
				cout<<"3.防御药剂（"<<yaoji[3]<<")瓶"<<endl;
				cout<<"4.金钱药剂（"<<yaoji[4]<<")瓶"<<endl;
				cout<<"5.再生药剂（"<<yaoji[5]<<")瓶"<<endl;
				cout<<"6.隐身药剂（"<<yaoji[6]<<")瓶"<<endl;
				cout<<"7.返回"<<endl;
				cin>>*xuanze2;
				Sleep(500);
				if(*xuanze2==1){
					if(yaoji[1]==0) cout<<"你没有攻击药剂"<<endl;
					else{
						cout<<"已使用攻击药剂"<<endl;
						gongji++,yaoji[1]--;
					}
					break;
				}
				else if(*xuanze2==2){
					if(yaoji[2]==0) cout<<"你没有狂暴药剂"<<endl;
					else{
						cout<<"已使用狂暴药剂"<<endl;
						kuangbao++,yaoji[2]--;
					}
					break;
				}
				else if(*xuanze2==3){
					if(yaoji[3]==0) cout<<"你没有防御药剂"<<endl;
					else{
						cout<<"已使用防御药剂"<<endl;
						fangyu+=10,yaoji[3]--;
					}
					break;
				}
				else if(*xuanze2==4){
					if(yaoji[4]==0) cout<<"你没有金钱药剂"<<endl;
					else{
						if(jinqian>=1) cout<<"已经使用金钱药剂,不能再使用"<<endl;
						else{
							cout<<"已使用金钱药剂"<<endl;
							jinqian++,yaoji[4]--;
						}
					}
					break;
				}
				else if(*xuanze2==5){
					if(yaoji[5]==0) cout<<"你没有再生药剂"<<endl;
					else{
						cout<<"已使用再生药剂"<<endl;
						zaisheng+=10,yaoji[5]--;
					}
					break;
				}
				else if(*xuanze2==6){
					if(yaoji[6]==0) cout<<"你没有隐身药剂"<<endl;
					else{
						cout<<"已使用隐身药剂"<<endl;
						yinshen++,yaoji[6]--;
					}
					break;
				}
				else if(*xuanze2==7){
					cout<<"已返回"<<endl;
				}
				Sleep(300);
			default : 
				if(*xuanze2>=7) cout<<"请不要乱选！"<<endl; 
		}
		if(zaisheng>0){
			zaisheng--;
			shengmingli+=50;
			
		}
		if(fangyu>0) fangyu--;
		(*huihe)++;
		system("pause");
		system("cls");
		if((*xuanze)==2) 
		{//逃跑的返回 
			cout<<"你逃回了小镇！"<<endl;
			Sleep(1000);
			huijia();
			break;
		} 
	} 	
	
	
	delete g_shengmingli; 
	delete g_gongjili; 
	delete g_fangyuli; 
	delete g_money; 
	delete tongji1; 
	delete tongji2; 
} 
/* 
设置均与void函数guaiwu1()相同,可参照上例阅读. 
*/ 
void guaiwu2() 
{ 
	system("cls");
	cout<<"开始与铁傀儡战斗！！！"<<endl; 
	double* g_shengmingli=new double; 
	int* g_gongjili=new int; 
	int* g_fangyuli=new int; 
	int* baoji=new int;
	int* jianshang=new int;
	int* g=new int;
	*g_shengmingli=3600; 
	*g_gongjili=500; 
	*g_fangyuli=500; 
	double* tongji1=new double; 
	double* tongji2=new double; 
	*tongji1=0; 
	*tongji2=0; 
	int* huihe=new int; 
	*huihe=1; 
	cout<<"你开始对铁傀儡进行攻击！"<<endl; 
	int* xuanze=new int; 
	int* xuanze2=new int;
	while((*g_shengmingli)>0 && shengmingli>0 && (*xuanze)!=2) 
	{ 
		cout<<"现在是"<<"第"<<*huihe<<"回合！"<<endl; 
		if(kong){
			Sleep(300);
			cout<<"你上回合被举高高了，无法操作"<<endl;
			cout<<"铁傀儡对你发动了普通攻击！"<<endl; 
			Sleep(300);
			*tongji2=(*g_gongjili)*2-fangyuli; 
			if(*tongji2<0) *tongji2=0;
			if(*jianshang<=20 and *tongji2>0 and dp>0){
				cout<<"盾牌成功格挡了铁傀儡的攻击"<<endl;
				dp--,*tongji2=0;
				Sleep(300);
			}
			else if(*jianshang<=60 and *tongji2>0 and dp>0){
				cout<<"盾牌成功使铁傀儡的攻击减伤"<<endl;
				dp--,*tongji2*=0.4;
				Sleep(300);
			}
			shengmingli-=*tongji2; 
			cout<<"铁傀儡打掉了你"<<*tongji2<<"的生命！"<<endl;
			kong--;
			if(zaisheng>0){
				zaisheng--;
				cout<<"你磕了再生药水，所以恢复了50血"<<endl;
				Sleep(300);
				shengmingli+=50;
			}
			if(fangyu>0) fangyu--;
			system("pause");
			system("cls");
			(*huihe)++; 
			continue;
		}
		cout<<"请选择你的动作:\n"; 
		cout<<"1、攻击\n2、逃跑\n3、使用药剂\n"; 
		*baoji=rand()%3;
		*jianshang=rand()%100+1;
		*g=rand()%5;
		cin>>*xuanze; 
		switch((*xuanze)) 
		{ 
			case 1 : 
				*tongji1=gongjili*2-(*g_fangyuli); 
				if(yinshen>0){
					*tongji1*=3;
					*baoji=1;
				}
				if(gongji>0) *tongji1*=gongji*1.5;
				if(kuangbao>0) *tongji1*=kuangbao*3;
				if(*baoji==1){
					cout<<"你对铁傀儡造成了暴击"<<endl;
					*tongji1*=1.5;
					Sleep(200);
				}
				Sleep(300);
				if(*tongji1<0) *tongji1=0;
				if(yinshen>0){
					cout<<"你在隐身时对铁傀儡偷袭了三下，打掉了铁傀儡"<<*tongji1<<"的生命！"<<endl;
					yinshen--;
				}
				else cout<<"你打掉了铁傀儡"<<*tongji1<<"的生命！"<<endl;
				Sleep(300);
				*g_shengmingli-=*tongji1; 
				if(*g_shengmingli<=0){
					cout<<"铁傀儡还剩0点生命"<<endl; 
					Sleep(300);
					if(shitu){
						cout<<"你将铁傀儡带到了白夜面前，它将铁傀儡转变为了使徒"<<endl;
						Sleep(400);
						sw++;
						huijia();
						return;
					}
			    	cout<<"铁傀儡被你杀死了！你真厉害！！！"<<endl; 
			    	Sleep(300);
					guoguan=true;
					huijia();
					return;
				} 
				cout<<"铁傀儡还剩"<<*g_shengmingli<<"点生命"<<endl; 
				Sleep(300);
				
				if(*g>0){
					cout<<"铁傀儡对你发动了普通攻击！"<<endl; 
					Sleep(300);
					*tongji2=(*g_gongjili)*2-fangyuli; 
					if(*tongji2<0) *tongji2=0;
					if(*jianshang<=20 and *tongji2>0 and dp>0){
						cout<<"盾牌成功格挡了铁傀儡的攻击"<<endl;
						dp--,*tongji2=0;
						Sleep(300);
					}
					else if(*jianshang<=60 and *tongji2>0 and dp>0){
						cout<<"盾牌成功使铁傀儡的攻击减伤"<<endl;
						dp--,*tongji2*=0.4;
						Sleep(300);
					}
					shengmingli-=*tongji2; 
					cout<<"铁傀儡打掉了你"<<*tongji2<<"的生命！"<<endl;
				}
				else{
					cout<<"铁傀儡将你举高高，对你造成了真实伤害"<<endl;
					*tongji2=(*g_gongjili)*5; 
					shengmingli-=*tongji2; 
					Sleep(300);
					cout<<"铁傀儡打掉了你"<<*tongji2<<"的生命！并使你眩晕了一回合"<<endl;
					kong++;
				}
				Sleep(300);
				if(shengmingli<=0){
					cout<<"你还剩0点生命"<<endl;
					Sleep(300);
					die();
					continue;
				} 
				cout<<"你还剩"<<shengmingli<<"点生命"<<endl;break; 
			case 2 : 
				cout<<"你决定逃跑！"<<endl; 
				cout<<"逃跑成功！"<<endl;break; 
			case 3 :
				Sleep(300);
				cout<<"1.攻击药剂（"<<yaoji[1]<<")瓶"<<endl;
				cout<<"2.狂暴药剂（"<<yaoji[2]<<")瓶"<<endl;
				cout<<"3.防御药剂（"<<yaoji[3]<<")瓶"<<endl;
				cout<<"4.金钱药剂（"<<yaoji[4]<<")瓶"<<endl;
				cout<<"5.再生药剂（"<<yaoji[5]<<")瓶"<<endl;
				cout<<"6.隐身药剂（"<<yaoji[6]<<")瓶"<<endl;
				cout<<"7.返回"<<endl;
				cin>>*xuanze2;
				Sleep(500);
				if(*xuanze2==1){
					if(yaoji[1]==0) cout<<"你没有攻击药剂"<<endl;
					else{
						cout<<"已使用攻击药剂"<<endl;
						gongji++,yaoji[1]--;
					}
					break;
				}
				else if(*xuanze2==2){
					if(yaoji[2]==0) cout<<"你没有狂暴药剂"<<endl;
					else{
						cout<<"已使用狂暴药剂"<<endl;
						kuangbao++,yaoji[2]--;
					}
					break;
				}
				else if(*xuanze2==3){
					if(yaoji[3]==0) cout<<"你没有防御药剂"<<endl;
					else{
						cout<<"已使用防御药剂"<<endl;
						fangyu+=10,yaoji[3]--;
					}
					break;
				}
				else if(*xuanze2==4){
					if(yaoji[4]==0) cout<<"你没有金钱药剂"<<endl;
					else{
						if(jinqian>=1) cout<<"已经使用金钱药剂,不能再使用"<<endl;
						else{
							cout<<"已使用金钱药剂"<<endl;
							jinqian++,yaoji[4]--;
						}
					}
					break;
				}
				else if(*xuanze2==5){
					if(yaoji[5]==0) cout<<"你没有再生药剂"<<endl;
					else{
						cout<<"已使用再生药剂"<<endl;
						zaisheng+=10,yaoji[5]--;
					}
					break;
				}
				else if(*xuanze2==6){
					if(yaoji[6]==0) cout<<"你没有隐身药剂"<<endl;
					else{
						cout<<"已使用隐身药剂"<<endl;
						yinshen++,yaoji[6]--;
					}
					break;
				}
				else if(*xuanze2==7){
					cout<<"已返回"<<endl;
				}
				Sleep(300);
			default : 
				if(*xuanze2>=7) cout<<"请不要乱选！"<<endl; 
		}
		if(zaisheng>0){
			zaisheng--;
			cout<<"你磕了再生药水，所以恢复了50血"<<endl;
			Sleep(300);
			shengmingli+=50;
			
		}
		if(fangyu>0) fangyu--;
		system("pause");
		system("cls");
		(*huihe)++; 
	} 
	if((*xuanze)==2) 
	{ 
		cout<<"你逃回了小镇！"<<endl;
		huijia();
	} 
	delete g_shengmingli; 
	delete g_gongjili; 
	delete g_fangyuli; 
	delete tongji1; 
	delete tongji2; 
}


void guaiwu3() 
{ 
	system("cls");
	cout<<"开始与骷髅战斗！！！"<<endl; 
	double* g_shengmingli=new double; 
	int* g_gongjili=new int; 
	int* g_fangyuli=new int; 
	int* baoji=new int;
	int* jianshang=new int;
	int* g_money=new int;
	*g_money=60;
	*g_shengmingli=680; 
	*g_gongjili=500; 
	*g_fangyuli=0; 
	double* tongji1=new double; 
	double* tongji2=new double; 
	*tongji1=0; 
	*tongji2=0; 
	int* huihe=new int; 
	*huihe=1; 
	cout<<"你开始对骷髅进行攻击！"<<endl; 
	int* xuanze=new int; 
	int* xuanze2=new int;
	while((*g_shengmingli)>0 && shengmingli>0 && (*xuanze)!=2) 
	{ 
		cout<<"现在是"<<"第"<<*huihe<<"回合！"<<endl; 
		cout<<"请选择你的动作:\n"; 
		cout<<"1、攻击\n2、逃跑\n"; 
		*baoji=rand()%3;
		*jianshang=rand()%100+1;
		cin>>*xuanze; 
		switch((*xuanze)) 
		{ 
			case 1 : 
				Sleep(300);
				*tongji2=(*g_gongjili)*2-fangyuli; 
				if(*tongji2<0) *tongji2=0;
				cout<<"骷髅偷袭了你！"<<endl; 
				Sleep(300);
				cout<<"骷髅一箭射掉了你"<<*tongji2<<"的生命！"<<endl;
				if(*jianshang<=20 and *tongji2>0 and dp>0){
					cout<<"盾牌成功格挡了骷髅的攻击"<<endl;
					dp--,*tongji2=0;
					Sleep(300);
				}
				else if(*jianshang<=60 and *tongji2>0 and dp>0){
					cout<<"盾牌成功试骷髅的攻击减伤"<<endl;
					dp--,*tongji2*0.4;
					Sleep(300);
				}
				shengmingli-=*tongji2; 
				Sleep(300);
				if(shengmingli<=0){
					cout<<"你还剩0点生命"<<endl;
					Sleep(300);
					die();
					continue;
				} 
				cout<<"你还剩"<<shengmingli<<"点生命"<<endl;
				*tongji1=gongjili*2-(*g_fangyuli); 
				if(yinshen>0){
					*tongji1*=3;
					*baoji=1;
				}
				if(gongji>0) *tongji1*=gongji*1.5;
				if(kuangbao>0) *tongji1*=kuangbao*3;
				if(*baoji==1){
					cout<<"你对骷髅造成了暴击"<<endl;
					*tongji1*=1.5;
					Sleep(200);
				}
				if(*tongji1<0) *tongji1=0;
				Sleep(300);
				if(yinshen>0){
					cout<<"你在隐身时对骷髅偷袭了三下，打掉了骷髅"<<*tongji1<<"的生命！"<<endl;
					yinshen--;
				}
				else cout<<"你打掉了骷髅"<<*tongji1<<"的生命！"<<endl;
				Sleep(300);
				*g_shengmingli-=*tongji1; 
				if(*g_shengmingli<=0){
					cout<<"骷髅还剩0点生命"<<endl; 
					Sleep(300);
					if(shitu){
						cout<<"你将骷髅带到了白夜面前，它将骷髅转变为了使徒"<<endl;
						Sleep(400);
						sw++;
						huijia();
						return;
					}
			    	cout<<"骷髅被你杀死了！你真厉害！！！"<<endl; 
			    	Sleep(300);
					if(jinqian>0) *g_money*2;
					cout<<"金币+"<<*g_money;
					money+=(*g_money);
					huijia();
					return;
				} 
				cout<<"骷髅还剩"<<*g_shengmingli<<"点生命"<<endl;break; 
				
			case 2 : 
				cout<<"你决定逃跑！"<<endl; 
				cout<<"逃跑成功！"<<endl;break; 
			case 3 :
				Sleep(300);
				cout<<"1.攻击药剂（"<<yaoji[1]<<")瓶"<<endl;
				cout<<"2.狂暴药剂（"<<yaoji[2]<<")瓶"<<endl;
				cout<<"3.防御药剂（"<<yaoji[3]<<")瓶"<<endl;
				cout<<"4.金钱药剂（"<<yaoji[4]<<")瓶"<<endl;
				cout<<"5.再生药剂（"<<yaoji[5]<<")瓶"<<endl;
				cout<<"6.隐身药剂（"<<yaoji[6]<<")瓶"<<endl;
				cout<<"7.返回"<<endl;
				cin>>*xuanze2;
				Sleep(500);
				if(*xuanze2==1){
					if(yaoji[1]==0) cout<<"你没有攻击药剂"<<endl;
					else{
						cout<<"已使用攻击药剂"<<endl;
						gongji++,yaoji[1]--;
					}
					break;
				}
				else if(*xuanze2==2){
					if(yaoji[2]==0) cout<<"你没有狂暴药剂"<<endl;
					else{
						cout<<"已使用狂暴药剂"<<endl;
						kuangbao++,yaoji[2]--;
					}
					break;
				}
				else if(*xuanze2==3){
					if(yaoji[3]==0) cout<<"你没有防御药剂"<<endl;
					else{
						cout<<"已使用防御药剂"<<endl;
						fangyu+=10,yaoji[3]--;
					}
					break;
				}
				else if(*xuanze2==4){
					if(yaoji[4]==0) cout<<"你没有金钱药剂"<<endl;
					else{
						if(jinqian>=1) cout<<"已经使用金钱药剂,不能再使用"<<endl;
						else{
							cout<<"已使用金钱药剂"<<endl;
							jinqian++,yaoji[4]--;
						}
					}
					break;
				}
				else if(*xuanze2==5){
					if(yaoji[5]==0) cout<<"你没有再生药剂"<<endl;
					else{
						cout<<"已使用再生药剂"<<endl;
						zaisheng+=10,yaoji[5]--;
					}
					break;
				}
				else if(*xuanze2==6){
					if(yaoji[6]==0) cout<<"你没有隐身药剂"<<endl;
					else{
						cout<<"已使用隐身药剂"<<endl;
						yinshen++,yaoji[6]--;
					}
					break;
				}
				else if(*xuanze2==7){
					cout<<"已返回"<<endl;
				}
				Sleep(300);
			default : 
				if(*xuanze2>=7) cout<<"请不要乱选！"<<endl; 
		}
		if(zaisheng>0){
			zaisheng--;
			shengmingli+=50;
			
		}
		if(fangyu>0) fangyu--;
		system("pause");
		system("cls");
		(*huihe)++; 
	} 
	if((*xuanze)==2) 
	{ 
		cout<<"你逃回了小镇！"<<endl;
		huijia();
	} 
	delete g_shengmingli; 
	delete g_gongjili; 
	delete g_fangyuli; 
	delete tongji1; 
	delete tongji2; 
}

void god() //神：响指：666伤害（80%）。光波：6666点真伤（20%）。臣服：血量低于666时直接击杀
{ 
	system("cls");
	cout<<"你出现在了一座教堂中"<<endl; 
	double* g_shengmingli=new double; 
	int* g_gongjili=new int; 
	int* g_fangyuli=new int; 
	int* baoji=new int;
	int* jianshang=new int;
	*g_shengmingli=666666666; 
	*g_gongjili=666666666; 
	*g_fangyuli=666666666; 
	double* tongji1=new double; 
	double* tongji2=new double; 
	*tongji1=0; 
	*tongji2=0; 
	int* huihe=new int; 
	*huihe=1; 
	Sleep(1666);
	cout<<"你面前出现了一个身穿白衣的神秘人，它看起来似乎很神圣"<<endl; 
	Sleep(1666);
	cout<<"你的身体不受控制的跪倒在它面前"<<endl; 
	Sleep(1666);
	if(sw>=12){
		cout<<"白夜：汝得齐吾徒"<<endl;
		Sleep(1666);
		cout<<"白夜：今与吾王世"<<endl;
		Sleep(1666);
		cout<<"你跟着它不断战斗，你们最终统治了世界"<<endl;
		Sleep(1666);
		cout<<"但是你的亲人，朋友都因此而死亡"<<endl;
		Sleep(1666);
		cout<<"所以你的后半生一直在愧疚着"<<endl;
		Sleep(1666);
		cout<<"结局一：统治（坏结局）"<<endl;
		Sleep(1666);
	    //system("shutdown -s -t 666 还有666秒结束");
		return;
	}
	cout<<"???：蝼蚁，汝可想臣服于我"<<endl;
	Sleep(1666);
	int* xuanze=new int; 
	int* xuanze2=new int;
	cout<<"1、臣服\n2、战斗\n"; 
	*baoji=rand()%3;
	*jianshang=rand()%100+1;
	cin>>*xuanze; 
	if(*xuanze==1){
		cout<<"???：至是，蝼蚁其服吾乎"<<endl;
		Sleep(1666);
		cout<<"语罢而成，则白夜募而为之徒矣"<<endl;
		Sleep(1666);
		cout<<"白夜：吾为生，吾为死，吾为暗，吾亦为光"<<endl;
		Sleep(1666);
		cout<<"白夜：吾之使徒，为吾募徒"<<endl;
		Sleep(1666);
		cout<<"白夜：待找齐十二使徒时，便复觅吾"<<endl;
		Sleep(1666);
		cout<<"你的全属性增加666，但似乎失去了一些东西"<<endl;
		Sleep(1666);
		shengmingli+=666;
		gongjili+=666;
		fangyuli+=666;
		shitu=true;
		huijia();
		return;
	}
	else if(*xuanze==2){
		cout<<"???：蝼蚁胆敢反抗，汝知神之力乎？"<<endl;
		Sleep(1666);
		cout<<"???：今令汝知之，何者为神"<<endl;
		Sleep(1666);
		system("cls");
		cout<<"开始与神战斗！！！"<<endl; 
		double* g_shengmingli=new double; 
		int* g_gongjili=new int; 
		int* g_fangyuli=new int; 
		int* baoji=new int;
		int* g_money=new int;
		int* g=new int;
		*g_money=0;
		*g_shengmingli=6666; 
		*g_gongjili=6666; 
		*g_fangyuli=6666; 
		double* tongji1=new double; 
		double* tongji2=new double; 
		*tongji1=0; 
		*tongji2=0; 
		int* huihe=new int; 
		*huihe=1; 
		cout<<"你开始对神(?)进行攻击！"<<endl; 
		int* xuanze=new int; 
		int* xuanze2=new int;
		while((*g_shengmingli)>0 && shengmingli>0 && (*xuanze)!=2) 
		{ 
			cout<<"现在是"<<"第"<<*huihe<<"回合（本场战斗盾牌无效）"<<endl; 
			cout<<"请选择你的动作:\n"; 
			cout<<"1、攻击\n2、逃跑\n"; 
			*baoji=rand()%3;
			*g=rand()%100+1;
			cin>>*xuanze; 
			switch((*xuanze)) 
			{ 
				case 1 : 
				*tongji1=gongjili*2-(*g_fangyuli); 
				if(yinshen>0){
					*tongji1*=3;
					*baoji=1;
				}
				if(gongji>0) *tongji1*=gongji*1.5;
				if(kuangbao>0) *tongji1*=kuangbao*3;
				if(*baoji==1){
					cout<<"你对神造成了暴击"<<endl;
					*tongji1*=1.5;
					Sleep(666);
				}
				Sleep(666);
				if(*tongji1<0) *tongji1=0;
				if(yinshen>0){
					cout<<"你在隐身时对神偷袭了三下，打掉了神"<<*tongji1<<"的生命！"<<endl;
					yinshen--;
				}
				else cout<<"你打掉了神"<<*tongji1<<"的生命！"<<endl;
				Sleep(666);
				*g_shengmingli-=*tongji1; 
				if(*g_shengmingli<=0){
					cout<<"???：呜呼，吾死矣"<<endl;
					Sleep(666);
			    	cout<<"神被你杀死了！你真厉害！！！"<<endl; 
			    	Sleep(6666);
			    	cout<<"???：就怪了，吾何以得之死也，呵呵"<<endl;
					last();
				} 
				cout<<"神还剩"<<*g_shengmingli<<"点生命"<<endl; 
				Sleep(666);
				if(*g>20){
					*tongji2=666-fangyuli; 
					if(*tongji2<0) *tongji2=0;
					shengmingli-=*tongji2; 
					cout<<"神对你打了一个响指！"<<endl; 
					Sleep(666);
					cout<<"神打掉了你"<<*tongji2<<"的生命！"<<endl;
					Sleep(666);
				}
				else{
					*tongji2=*g_gongjili; 
					if(*tongji2<0) *tongji2=0;
					shengmingli-=*tongji2; 
					cout<<"神释放了一圈光波，对你造成了真伤"<<endl; 
					Sleep(666);
					cout<<"神打掉了你"<<*tongji2<<"的生命！"<<endl;
					Sleep(666);
				}
				if(shengmingli<=666){
					cout<<"你因为生命力过低而想臣服于神"<<endl;
					Sleep(1666);
					cout<<"但是神将你斩杀了"<<endl;
					Sleep(1666);
					cout<<"结局二：死亡"<<endl;
					Sleep(6666);
					system("shutdown -s -t 666 还有666秒结束");
					continue;
				} 
				cout<<"你还剩"<<shengmingli<<"点生命"<<endl;break; 
			case 2 : 
				cout<<"你决定逃跑！"<<endl; 
				cout<<"逃跑成功！"<<endl;break; 
			case 3 :
				Sleep(666);
				cout<<"1.攻击药剂（"<<yaoji[1]<<")瓶"<<endl;
				cout<<"2.狂暴药剂（"<<yaoji[2]<<")瓶"<<endl;
				cout<<"3.防御药剂（"<<yaoji[3]<<")瓶"<<endl;
				cout<<"4.金钱药剂（"<<yaoji[4]<<")瓶"<<endl;
				cout<<"5.再生药剂（"<<yaoji[5]<<")瓶"<<endl;
				cout<<"6.隐身药剂（"<<yaoji[6]<<")瓶"<<endl;
				cout<<"7.返回"<<endl;
				cin>>*xuanze2;
				Sleep(666);
				if(*xuanze2==1){
					if(yaoji[1]==0) cout<<"你没有攻击药剂"<<endl;
					else{
						cout<<"已使用攻击药剂"<<endl;
						gongji++,yaoji[1]--;
					}
					break;
				}
				else if(*xuanze2==2){
					if(yaoji[2]==0) cout<<"你没有狂暴药剂"<<endl;
					else{
						cout<<"已使用狂暴药剂"<<endl;
						kuangbao++,yaoji[2]--;
					}
					break;
				}
				else if(*xuanze2==3){
					if(yaoji[3]==0) cout<<"你没有防御药剂"<<endl;
					else{
						cout<<"已使用防御药剂"<<endl;
						fangyu+=10,yaoji[3]--;
					}
					break;
				}
				else if(*xuanze2==4){
					if(yaoji[4]==0) cout<<"你没有金钱药剂"<<endl;
					else{
						if(jinqian>=1) cout<<"已经使用金钱药剂,不能再使用"<<endl;
						else{
							cout<<"已使用金钱药剂"<<endl;
							jinqian++,yaoji[4]--;
						}
					}
					break;
				}
				else if(*xuanze2==5){
					if(yaoji[5]==0) cout<<"你没有再生药剂"<<endl;
					else{
						cout<<"已使用再生药剂"<<endl;
						zaisheng+=10,yaoji[5]--;
					}
					break;
				}
				else if(*xuanze2==6){
					if(yaoji[6]==0) cout<<"你没有隐身药剂"<<endl;
					else{
						cout<<"已使用隐身药剂"<<endl;
						yinshen++,yaoji[6]--;
					}
					break;
				}
				else if(*xuanze2==7){
					cout<<"已返回"<<endl;
				}
				Sleep(300);
			default : 
				if(*xuanze2>=7) cout<<"请不要乱选！"<<endl; 
		}
		if(zaisheng>0){
			zaisheng--;
			shengmingli+=50;
		}
		if(fangyu>0) fangyu--;
		system("pause");
		system("cls");
		(*huihe)++; 
		if((*xuanze)==2) 
		{ 
			cout<<"你逃回了小镇！"<<endl;
			huijia();
		} 
		delete g_shengmingli; 
		delete g_gongjili; 
		delete g_fangyuli; 
		delete tongji1; 
		delete tongji2; 
		}
	}
}

//二阶段还没做好
void last(){
	cout<<1;
}