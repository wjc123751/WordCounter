#ifdef _WIN32
#include <windows.h>
#endif

#include "wordcounter.h"
#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

// 获取 exe 所在的文件夹（核心！）
fs::path getExeDir()
{
    wchar_t buffer[MAX_PATH];
    GetModuleFileNameW(NULL, buffer, MAX_PATH);
    return fs::path(buffer).parent_path();
}

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif

    // cout << "当前工作目录: " << fs::current_path() << endl;

    // 重点：获取 exe 所在目录的 test.txt
    fs::path txtPath = getExeDir() / "test.txt";

    WordCounter counter;

    if (counter.countFromFile(txtPath.string())) {
        counter.printResult();
    }

    // cout << "\n===== 从外部获取单词列表 =====\n";
    // auto result = counter.getWordMap();
    // for (const auto& p : result)
    // {
    //     cout << "单词：" << p.first << " 出现次数：" << p.second << endl;
    // }

    system("pause");

    return 0;
}