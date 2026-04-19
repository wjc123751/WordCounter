#ifdef _WIN32
#include <windows.h>
#endif

#include "wordcounter.h"
#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

fs::path getExeDir()
{
    wchar_t buffer[MAX_PATH] = { 0 };
    GetModuleFileNameW(NULL, buffer, MAX_PATH);
    return fs::path(buffer).parent_path();
}

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif

    fs::path exeFolder = getExeDir();
    fs::path txtPath = exeFolder / L"test.txt";

    cout << "=== 单词统计工具 ===" << endl;
    // cout << "EXE目录: " << exeFolder << endl;
    // cout << "读取文件: " << txtPath << endl;

    if (!fs::exists(txtPath)) {
        cout << "\n错误：test.txt 不存在！" << endl;
        system("pause");
        return 1;
    }

    WordCounter counter;

    // 宽字符打开，支持中文文件夹
    if (counter.countFromFile(txtPath.wstring())) {
        cout << "\n统计结果：\n" << endl;
        counter.printResult();
    } else {
        cout << "\n文件打开失败！" << endl;
    }

    cout << "\n====================" << endl;
    system("pause");
    return 0;
}