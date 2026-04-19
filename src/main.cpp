#ifdef _WIN32
#include <windows.h>
#endif

#include "wordcounter.h"
#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif

    // cout << "当前工作目录: " << fs::current_path() << endl;

    WordCounter counter;

    if (counter.countFromFile("../data/test.txt")) {
        counter.printResult();
    }

    cout << "\n===== 从外部获取单词列表 =====\n";
    auto result = counter.getWordMap();
    for (const auto& p : result)
    {
        cout << "单词：" << p.first << " 出现次数：" << p.second << endl;
    }

    return 0;
}