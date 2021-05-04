//参考文献(URL長いものもあります。申し訳ありません)
//http://yohshiy.blog.fc2.com/blog-entry-260.html
//https://qiita.com/p1ro3/items/6bb1c78a6c27109f6b93
//https://qiita.com/asksaito/items/1793b8d8b3069b0b8d68
//https://qiita.com/omiso/items/6082b765c1257b71985b
//http://www.spiritek.co.jp/spkblog/2016/12/01/%E6%9A%97%E5%8F%B7%E6%8A%80%E8%A1%93%E5%85%A5%E9%96%8004-%E3%83%96%E3%83%AD%E3%83%83%E3%82%AF%E6%9A%97%E5%8F%B7%E3%81%AE%E3%83%A2%E3%83%BC%E3%83%89%E3%80%9C%E3%83%96%E3%83%AD%E3%83%83%E3%82%AF/
//https://programming.pc-note.net/c/commandline.html

#include <iostream>
#include "Encrypt.h"

enum ArgumentName
{
    PASS = 0,
    FIRST = 1,
    SECOND = 2,
    THIRD = 3,
    FOURTH = 4
};

bool ChackArgument(int _count,char* argv, bool _isAbridgementOption);

int main(int argc, char* argv[])
{

    // コマンドライン引数が空でないかチェック
    if (argc <= 1)
    {
        cout << "ERROR::コマンドライン引数が空です::ERROR" << endl;
        cout << "Enterキーで終了" << endl;
        getchar();
        return 0;
    }
    else if (argc > 5)
    {
        cout << "ERROR::コマンドライン引数が許容範囲を超えています::ERROR" << endl;
        cout << "Enterキーで終了" << endl;
        getchar();
        return 0;
    }

    // オプションが省略して使われているかチェックフラグ変数
    string firstArg = argv[FIRST];
    bool isAbridgementOption = false;

    if (firstArg == "-oi" || firstArg == "-io")
    {
        isAbridgementOption = true;
        if (argc > 4)
        {
            cout << "ERROR::オプションに対して引数が多いです::ERROR" << endl;
            cout << "Enterキーで終了" << endl;
            getchar();
            return 0;
        }
    }
    else if (firstArg == "-i" || firstArg == "-o")
    {
        if (argc <= 4)
        {
            cout << "ERROR::オプションに対して引数が少ないです::ERROR" << endl;
            cout << "Enterキーで終了" << endl;
            getchar();
            return 0;
        }
    }

    // コマンドライン引数チェック用フラグ変数
    bool argumentChack = false;

    // 全コマンドライン引数をチェック
    for (int chackCount = 1; chackCount < argc; chackCount++)
    {
        argumentChack = ChackArgument(chackCount, argv[chackCount], isAbridgementOption);

        // デバッグ出力
        cout << "argumentChack" << endl;
        cout << argumentChack << endl;
    }

    // 先に入力ファイル名が入っているかどうか
    bool isFirstInput = false;

    if (firstArg == "-i" || firstArg == "-io")
    {
        isFirstInput = true;
    }

    if (argumentChack)
    {
        Encrypt* encrypt;
        // デバッグ出力
        if (isFirstInput)
        {
            cout << "入力が先" << endl;
        }

        // デバッグ出力
        if (isAbridgementOption)
        {
            cout << "省略" << endl;
        }

        if (isFirstInput)
        {
            if (isAbridgementOption)
            {
                encrypt = new Encrypt(argv[SECOND], argv[THIRD]);
            }
            else
            {
                encrypt = new Encrypt(argv[SECOND], argv[FOURTH]);
            }
        }
        else
        {
            if (isAbridgementOption)
            {
                encrypt = new Encrypt(argv[THIRD], argv[SECOND]);
            }
            else
            {
                encrypt = new Encrypt(argv[FOURTH], argv[SECOND]);
            }
        }

        bool success = encrypt->OpenFile();

        if (success)
        {
            encrypt->FirstWriteEncrypt();
            encrypt->AllWriteEncrypt();

            delete encrypt;

            cout << "終了しました。" << endl;

            return 0;
        }
        else
        {

            cout << "Enterキーで終了" << endl;

            getchar();

            delete encrypt;

            return 0;
        }
    }

}

bool ChackArgument(int _count, char* _argv,bool _isAbridgementOption)
{
    bool nullChack = false;

    if (_argv != nullptr)
    {
        nullChack = true;
    }

    bool erroeChack = false;

    if (nullChack)
    {
        // コマンドライン引数のチェック用string変数
        string chackArgument = _argv;

        switch (_count) 
        {
        case FIRST:

            // デバッグ出力
            cout << "case1" << endl;
            cout << chackArgument <<endl;
            // オプションが入って無ければエラーを返す
            if (chackArgument != "-o" && chackArgument != "-i" &&
                chackArgument != "-oi" && chackArgument != "-io")
            {
                cout << "ERROR::オプションを入力してください::ERROR" << endl;
                cout << "Enterキーで終了" << endl;
                getchar();
                erroeChack = false;
            }
            erroeChack = true;
            break;

        case SECOND:

            // デバッグ出力
            cout << "case2" << endl;
            cout << chackArgument << endl;
            // オプションが入っていたらエラーを返す
            if (chackArgument == "-o" || chackArgument == "-i" ||
                chackArgument == "-oi" || chackArgument == "-io")
            {
                cout << "ERROR::ファイル名を入力してください::ERROR" << endl;
                cout << "Enterキーで終了" << endl;
                getchar();
                erroeChack = false;
            }
            erroeChack = true;
            break;

        case THIRD:

            // デバッグ出力
            cout << "case3" << endl;
            cout << chackArgument << endl;
            cout << _isAbridgementOption << endl;

            if (!_isAbridgementOption)
            {
                // オプションが入って無ければエラーを返す
                if (chackArgument != "-o" && chackArgument != "-i" &&
                    chackArgument != "-oi" && chackArgument != "-io")
                {
                    cout << "ERROR::オプションを入力してください::ERROR" << endl;
                    cout << "Enterキーで終了" << endl;
                    getchar();
                    erroeChack = false;
                }

            }

            erroeChack = true;
            break;

        case FOURTH:

            // デバッグ出力
            cout << "case4" << endl;
            cout << chackArgument << endl;
            // オプションが入っていたらエラーを返す
            if (chackArgument == "-o" || chackArgument == "-i" ||
                chackArgument == "-oi" || chackArgument == "-io")
            {
                cout << "ERROR::ファイル名を入力してください::ERROR" << endl;
                cout << "Enterキーで終了" << endl;
                getchar();
                erroeChack = false;
            }
            erroeChack = true;
            break;
        }
    }

    return erroeChack;

}
