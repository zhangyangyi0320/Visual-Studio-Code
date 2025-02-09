#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <cmath>
#include <chrono>
#include <fstream>
#include <vector>

using namespace std;

// 函数生成随机算术题目并返回正确答案
pair<string, int> generateQuestion(char op, int difficulty)
{
    int num1 = rand() % (difficulty * 100) + 1;
    int num2 = rand() % (difficulty * 100) + 1;
    string question;
    int answer;
    switch (op)
    {
    case '+': // 加法
        question = to_string(num1) + " + " + to_string(num2);
        answer = num1 + num2;
        break;
    case '-': // 减法
        question = to_string(num1) + " - " + to_string(num2);
        answer = num1 - num2;
        break;
    case '*': // 乘法
        question = to_string(num1) + " * " + to_string(num2);
        answer = num1 * num2;
        break;
    case '/': // 除法（整数除法）
        // 确保num2不为零
        num2 = num2 == 0 ? 1 : num2;
        question = to_string(num1) + " / " + to_string(num2);
        answer = num1 / num2;
        break;
    case '%': // 取模运算
        // 确保num2不为零
        num2 = num2 == 0 ? 1 : num2;
        question = to_string(num1) + " % " + to_string(num2);
        answer = num1 % num2;
        break;
    case '^': // 幂运算
        question = to_string(num1) + " ^ " + to_string(num2);
        answer = pow(num1, num2);
        break;
    }

    return {question, answer};
}

// 保存得分到文件
void saveScore(int score)
{
    ofstream outFile("score.txt");
    if (outFile.is_open())
    {
        outFile << score;
        outFile.close();
    }
    else
    {
        cout << "无法打开文件保存得分。" << endl;
    }
}

// 保存游戏进度到文件
void saveGame(int score, int difficulty)
{
    ofstream outFile("game_save.txt");
    if (outFile.is_open())
    {
        outFile << score << " " << difficulty;
        outFile.close();
    }
    else
    {
        cout << "无法打开文件保存游戏进度。" << endl;
    }
}

// 从文件加载游戏进度
bool loadGame(int &score, int &difficulty)
{
    ifstream inFile("game_save.txt");
    if (inFile.is_open())
    {
        inFile >> score >> difficulty;
        inFile.close();
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    // 设置控制台输出为UTF-8编码
    SetConsoleOutputCP(CP_UTF8);

    cout << "欢迎来到算术挑战游戏！" << endl;
    cout << "+:加法" << endl;
    cout << "-:减法" << endl;
    cout << "*:乘法" << endl;
    cout << "/:除法(整数除法)" << endl;
    cout << "%:取模运算" << endl;
    cout << "^:幂运算" << endl;
    cout << "游戏规则：在规定时间内选择一个框，并答题，答对得1分，答错扣3分。" << endl;
    cout << "游戏将保存得分，并记录游戏进度。" << endl;
    srand(time(0)); // 随机数生成的种子
    int score = 0;
    int difficulty = 1;
    int difficultyGrowthRate;
    int timeLimit;

    cout << "请选择难度增长速率（1-5）：" << endl;
    while (!(cin >> difficultyGrowthRate) || difficultyGrowthRate < 1 || difficultyGrowthRate > 5)
    {
        cout << "无效输入。请输入一个1到5之间的数字。" << endl;
        cin.clear();                                         // 清除输入缓冲区
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略错误输入
    }

    cout << "请输入时间限制（秒）：" << endl;
    while (!(cin >> timeLimit) || timeLimit <= 0)
    {
        cout << "无效输入。请输入一个正整数。" << endl;
        cin.clear();                                         // 清除输入缓冲区
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略错误输入
    }

    // 检查是否存在保存的进度
    if (loadGame(score, difficulty))
    {
        cout << "继续上次的进度。" << endl;
    }
    else
    {
        cout << "开始新游戏。" << endl;
    }

    auto startTime = chrono::steady_clock::now();

    while (true)
    {
        // 检查是否超时
        auto currentTime = chrono::steady_clock::now();
        auto elapsedTime = chrono::duration_cast<chrono::seconds>(currentTime - startTime).count();
        if (elapsedTime >= timeLimit)
        {
            cout << "时间到！游戏结束。" << endl;
            saveScore(score);            // 保存得分
            saveGame(score, difficulty); // 保存游戏进度
            break;
        }

        // 生成两个随机运算符，包含新的运算符
        char op1 = "+-*/%^"[rand() % 6];
        char op2 = "+-*/%^"[rand() % 6];

        // 显示运算符及其对应的框
        cout << "选择一个框（1或2）并记住运算符：" << endl;
        cout << "框1: " << op1 << endl;
        cout << "框2: " << op2 << endl;

        int choice;
        while (!(cin >> choice))
        {
            cout << "无效输入。请输入一个数字。" << endl;
            cin.clear();                                         // 清除输入缓冲区
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略错误输入
        }

        if (choice != 1 && choice != 2)
        {
            cout << "无效选择。请输入1或2。" << endl;
            continue;
        }

        // 根据选择的运算符和题目类型生成问题
        auto question = generateQuestion(choice == 1 ? op1 : op2, difficulty);

        int playerAnswer;
        cout << "问题是: " << question.first << endl;
        cout << "输入你的答案: ";
        while (!(cin >> playerAnswer))
        {
            cout << "无效输入。请输入一个数字。" << endl;
            cin.clear();                                         // 清除输入缓冲区
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略错误输入
        }

        // 检查玩家的答案并更新分数
        if (playerAnswer == question.second)
        {
            score++;
            cout << "正确！你的分数是: " << score << endl;
        }
        else
        {
            score -= 3;
            cout << "错误！你的分数是: " << score << endl;
        }

        //判断分数是否为负数
        if (score < 0)
        {
            cout << "分数为负数，游戏结束。" << endl;
            score = 0;
            saveScore(score);            // 保存得分
            saveGame(score, difficulty); // 保存游戏进度
            break;
        }

        // 根据得分调整难度
        difficulty = score / difficultyGrowthRate + 1;
    }

    Sleep(5000); // 等待5秒后退出

    return 0;
}
