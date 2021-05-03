#include "Encrypt.h"

Encrypt::Encrypt(char* _openFileName, char* _writeFileName)
    : openFileName(_openFileName)
    , writeFileName(_writeFileName)
{
}

Encrypt::~Encrypt()
{
}

bool Encrypt::OpenFile()
{
    ifsFile.open(openFileName, ios::binary);

    if (!ifsFile)
    {
        return false;
    }

    return true;
}

void Encrypt::CreateEncryptData()
{

    // 何も書かれていないファイルを出力
    ofstream ofs(writeFileName, ios::app | ios::binary);

    // 初期化ベクトル作成
    memset(initialData, 'I', Block);

    // データの読み込み
    ifsFile.read(data, Block);

    //ブロック長ごとに処理
    for (int i = 0; i < Block; i++)
    {
        cipherBlock[i] = data[i] ^ initialData[i];
    }

    //暗号化
    cipher(cipherBlock);

    //暗号化したブロックを出力
    ofsFile.write(cipherBlock, Block);

    //1つ前の暗号ブロックに暗号化したブロックを格納
    memcpy(cipherBlockPre, cipherBlock, Block);

}

void Encrypt::WriteFile()
{
    do {

        //データ読込
        ifsFile.read(data, Block);

        //ブロック長ごとに処理
        for (int i = 0; i < Block; i++)
        {
            cipherBlock[i] = data[i] ^ cipherBlockPre[i];
        }

        //暗号化
        cipher(cipherBlock);

        //暗号化したブロックを出力
        ofsFile.write(cipherBlock, Block);

        //1つ前の暗号ブロックに暗号化したブロックを格納
        memcpy(cipherBlockPre, cipherBlock, Block);

    } while (!ifsFile.eof());

}

void Encrypt::cipher(char* dst)
{
    //暗号鍵
    char cipherBlockTemp[Block];

    memset(cipherBlockTemp, 'S', Block);

    //ブロック長ごとに処理
    for (int i = 0; i < Block; i++)
    {
        //XOR暗号
        dst[i] = dst[i] ^ cipherBlockTemp[i];
    }

    return;
}
