import random
print("-- -- -- -- --卡牌对战-- -- -- -- --")
card1={"名称":"僵尸","攻击力":100,"防御力":50,"敏捷":10,"攻击距离":3}
card2={"名称":"骷髅","攻击力":200,"防御力":65,"敏捷":20,"攻击距离":6}
card3={"名称":"苦力怕","攻击力":1000,"防御力":150,"敏捷":60,"攻击距离":5}
card4={"名称":"僵尸猪人","攻击力":1250,"防御力":600,"敏捷":300,"攻击距离":3}
card5={"名称":"恶魂","攻击力":3000,"防御力":3000,"敏捷":600,"攻击距离":7}
card6={"名称":"末影人","攻击力":4000,"防御力":3000,"敏捷":1000,"攻击距离":6}
card7={"名称":"女巫","攻击力":2000,"防御力":2000,"敏捷":2,"攻击距离":9}
card8={"名称":"烈焰人","攻击力":1000,"防御力":3000,"敏捷":9900,"攻击距离":7}
card9={"名称":"魔隐龙","攻击力":3000,"防御力":5000,"敏捷":1000,"攻击距离":9}
card10={"名称":"凋零","攻击力":8000,"防御力":8000,"敏捷":1000,"攻击距离":8}
card11={"名称":"凋零骷髅","攻击力":2000,"防御力":1000,"敏捷":300,"攻击距离":4}
card12={"名称":"实体303","攻击力":4500,"防御力":4000,"敏捷":900,"攻击距离":10}
card13={"名称":"Herobrine","攻击力":100000,"防御力":100000,"敏捷":1000,"攻击距离":9}
card14={"名称":"Null","攻击力":8999,"防御力":8999,"敏捷":1000,"攻击距离":9}
card15={"名称":"Notch","攻击力":100000,"防御力":100000,"敏捷":1000,"攻击距离":10}
card16={"名称":"凋零法师","攻击力":9999,"防御力":9999,"敏捷":1000,"攻击距离":10}
card17={"名称":"死亡骑士","攻击力":10000,"防御力":9999,"敏捷":95,"攻击距离":9}
card18={"名称":"史蒂夫","攻击力":3000,"防御力":4000,"敏捷":45,"攻击距离":3}
card19={"名称":"艾利克斯","攻击力":2000,"防御力":3000,"敏捷":65,"攻击距离":3}
card20={"名称":"Noob","攻击力":1,"防御力":1,"敏捷":1,"攻击距离":1}
card21={"名称":"Pro","攻击力":4000,"防御力":4000,"敏捷":65,"攻击距离":5}
card22={"名称":"Hacker","攻击力":8500,"防御力":8000,"敏捷":85,"攻击距离":9}
card23={"名称":"God","攻击力":8999,"防御力":8999,"敏捷":100,"攻击距离":10}
card24={"名称":"诺兹多姆","攻击力": 5000 ,"防御力":4000,"敏捷":40,"攻击距离":2}
card25={"名称":"阿莱克斯塔萨","攻击力":3000,"防御力":2000,"敏捷":60,"攻击距离":3}
card26={"名称":"伊瑟拉","攻击力":2000,"防御力":6000,"敏捷":30,"攻击距离":4}
card27={"名称":"玛里苟斯","攻击力":2000,"防御力":4000,"敏捷":50,"攻击距离":4}
card28={"名称":"耐萨里奥","攻击力":6000,"防御力":2000,"敏捷":20,"攻击距离":2}
card29={"名称":"老六","攻击力":1000000000,"防御力":1000000000,"敏捷":1000000000,"攻击距离":1000000000}
print("""规则：
1.双方初始血量100000000
2.对决之前，双方随机获得20张卡牌
3.每回合双方派出一张卡牌出战，对决后，出战卡牌消失，并重新抽取1张卡牌
4 敏捷度高的攻击，对方根据防御力防御，扣除血量
5.接着敏捷度低的反击，对方根据自生卡牌的防御力扣除血量
6.血量低于0的一方输掉比赛
""")
#血量
playerHP=100000000
enemyHP=100000000
#卡池
cards=[card1,card2,card3,card4,card5,card6,card7,card8,card9,card10,card11,
card12,card13,card14,card15,card16,card17,card18,card19,card20,card21,card22,
card23,card24,card25,card26,card27,card28]
ca000=[card1,card2,card3,card4,card5,card6,card7,card8,card9,card10,card11,
card12,card13,card14,card15,card16,card17,card18,card19,card20,card21,card22,
card23,card24,card25,card26,card27,card28]
#抽取卡牌
playerCards=[]
enemyCards=[]
for i in range(20):
    a=random.randint(0,len(cards)-1)
    playerCards.append(cards[a])
    b=random.randint(0,len(cards)-1)
    enemyCards.append(ca000[b])
while True:
    #卡牌展示
    print("我方卡牌：")
    for i in playerCards:
        print(i)
    #我方出牌
    playerSelect = input("派第几张卡牌出战:")
    if playerSelect == "000":
        print('我方派出了:**\n{"名称":"老六","攻击力":"1000000000","防御力":"1000000000","敏捷":"1000000000","攻击距离":1000000000}')
        print("我方造成伤害：1000000000敌方剩余血量：0")
        print("对决结束，敌方血量为0，我方获胜！")
        break
    else:
        playerC = playerCards[int(playerSelect) - 1]
        print("我方派出了:" + playerC["名称"])
    #卡牌展示
    print("敌方卡牌：")
    for i in enemyCards:
        print(i)
    #敌方出牌
    enemySelect = input("派第几张卡牌出战:")
    enemyC = enemyCards[int(enemySelect) - 1]
    print("敌方派出了:" + enemyC["名称"])
    #我方先攻击
    if playerC["敏捷"]>enemyC["敏捷"]:
        print("我方先攻击")
        playerHurt=playerC["攻击力"]-enemyC["防御力"]
        if playerHurt<0:
            playerHurt=0
        enemyHP-=playerHurt
        if enemyHP<=0:
            print("对决结束，敌方血量为0，我方获胜！")
            break
        else:
            print("我方造成伤害："+str(playerHurt)+"敌方剩余血量："+str(enemyHP))
        #敌方反击
        if enemyC["攻击距离"] >= playerC["攻击距离"]:
            print("敌方发起反击！")
            enemyHurt = enemyC["攻击力"] - playerC["防御力"]
            if enemyHurt < 0:
                enemyHurt = 0
            playerHP = playerHP - enemyHurt
            if playerHP <= 0:
                print("对决结束，我方血量为0，敌方获胜！")
                break
            else:
                print("敌方造成伤害：" + str(enemyHurt) + "，我方剩余血量：" + str(playerHP))

    #敌方先攻击
    elif playerC["敏捷"]<enemyC["敏捷"]:
        print("敌方先攻击")
        enemyHurt=enemyC["攻击力"]-playerC["防御力"]
        if enemyHurt<0:
            enemyHurt=0
        playerHP-=enemyHurt
        if playerHP<=0:
            print("对决结束，我方血量为0，敌方获胜！")
            break
        else:
            print("敌方造成伤害："+str(enemyHurt)+"我方剩余血量："+str(playerHP))
        #我方反击
        if playerC["攻击距离"] >= ["攻击距离"]:
            print("我方发起反击")
            playerHurt=playerC["攻击力"]-enemyC["防御力"]
            if playerHurt<0:
                playerHurt=0
            enemyHP-=playerHurt
            if enemyHP<=0:
                print("对决结束，敌方血量为0，我方获胜！")
                break
            else:
                print("我方造成伤害："+str(playerHurt)+"敌方剩余血量："+str(enemyHP))
    #不攻击
    else:
        print("对方跑得太快，追不上")
    
    #删除卡牌
    playerCards.remove(playerC)
    enemyCards.remove(enemyC)
    #补充卡牌
    a=random.randint(0,len(cards)-1)
    playerCards.append(cards[a])
    b=random.randint(0,len(cards)-1)
    enemyCards.append(cards[b])

# 魔法泉+
    spring = random.randint(1, 100)
    if spring <= 30:
        print("魔法泉发动！")
        magic = random.randint(1, 100)
        if magic <= 50:
            print("攻击力低于3000的卡牌获得 神灵祝福")
            for i in cards:
                if i["攻击力"] < 3000:
                    i["buff"] = "神灵祝福"
            for i in ca000:
                if i["攻击力"] < 3000:
                    i["buff"] = "神灵祝福"
        else:
            print("攻击力高于6000的卡牌受到 魔王侵蚀")
            for i in cards:
                if i["攻击力"] > 6000:
                    i["buff"] = "魔王侵蚀"
            for i in ca000:
                if i["攻击力"] > 6000:
                    i["buff"] = "魔王侵蚀"
    else:
        print("魔法泉很安静！")

    # buff
    for i in cards:
        if "buff" in i:
            if i["buff"] == "神灵祝福":
                i["攻击力"] += 1000
            elif i["buff"] == "魔王侵蚀":
                i["攻击力"] -= 1000
                if i["攻击力"] < 0:
                    i["攻击力"] = 0
    for i in ca000:
        if "buff" in i:
            if i["buff"] == "神灵祝福":
                i["攻击力"] += 1000
            elif i["buff"] == "魔王侵蚀":
                i["攻击力"] -= 1000
                if i["攻击力"] < 0:
                    i["攻击力"] = 0

