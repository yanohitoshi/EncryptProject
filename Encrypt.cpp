#include "Encrypt.h"

Encrypt::Encrypt(char* _openFileName, char* _writeFileName)
    : openFileName(_openFileName)
    , writeFileName(_writeFileName)
{
}

Encrypt::~Encrypt()
{
    // 後片付け
    delete ifsFile;
    delete ofsFile;

}

bool Encrypt::OpenFile()
{

    // ファイルを開く
    ifsFile = new ifstream(openFileName, ios::binary);

    // ファイルが開けていなかったらエラー通知
    if (ifsFile == nullptr)
    {
        // コンソールにエラー描画
        cout << "ERROR::ファイルが開けませんでした::ERROR" << endl;

        // 失敗した場合falseを返す
        return false;
    }

    // 成功していたらtrueを返す
    return true;
}

void Encrypt::FirstWriteEncrypt()
{
    // 何も書かれていないファイルを出力
    ofsFile = new ofstream(writeFileName, ios::app | ios::binary);

    // 初期化ベクトルを生成
    memset(initialData, 'I', Block);

    // 暗号化する平文データを読み込み
    ifsFile->read(data, Block);

    // ブロック長ごとに暗号化の下処理
    for (int i = 0; i < Block; i++)
    {
        // XOR演算を行う
        cipherBlock[i] = data[i] ^ initialData[i];
    }

    // 暗号化関数呼び出し
    cipher(cipherBlock);

    // 暗号化したブロックを出力
    ofsFile->write(cipherBlock, Block);

    // 1つ前の暗号ブロックに暗号化したブロックを格納
    memcpy(cipherBlockPre, cipherBlock, Block);

}

void Encrypt::AllWriteEncrypt()
{
    // 先に作った暗号ブロックを用いてファイルの終わりまでループ
    do {

        // データを読込み
        ifsFile->read(data, Block);

        // ブロック長ごとに下処理
        for (int i = 0; i < Block; i++)
        {
            cipherBlock[i] = data[i] ^ cipherBlockPre[i];
        }

        // 暗号化関数呼び出し
        cipher(cipherBlock);

        // 暗号化したブロックを出力
        ofsFile->write(cipherBlock, Block);

        // 1つ前の暗号ブロックに暗号化したブロックを格納
        memcpy(cipherBlockPre, cipherBlock, Block);

    } while (!ifsFile->eof());

}

void Encrypt::cipher(char* _dst)
{
    // 暗号鍵変数
    char cipherBlockTemp[Block];
    // 暗号カギを生成
    memset(cipherBlockTemp, 'S', Block);

    // ブロック長ごとに処理
    for (int i = 0; i < Block; i++)
    {
        // XOR演算を行い暗号化
        _dst[i] = _dst[i] ^ cipherBlockTemp[i];
    }

    return;
}
