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

    // ����������Ă��Ȃ��t�@�C�����o��
    ofstream ofs(writeFileName, ios::app | ios::binary);

    // �������x�N�g���쐬
    memset(initialData, 'I', Block);

    // �f�[�^�̓ǂݍ���
    ifsFile.read(data, Block);

    //�u���b�N�����Ƃɏ���
    for (int i = 0; i < Block; i++)
    {
        cipherBlock[i] = data[i] ^ initialData[i];
    }

    //�Í���
    cipher(cipherBlock);

    //�Í��������u���b�N���o��
    ofsFile.write(cipherBlock, Block);

    //1�O�̈Í��u���b�N�ɈÍ��������u���b�N���i�[
    memcpy(cipherBlockPre, cipherBlock, Block);

}

void Encrypt::WriteFile()
{
    do {

        //�f�[�^�Ǎ�
        ifsFile.read(data, Block);

        //�u���b�N�����Ƃɏ���
        for (int i = 0; i < Block; i++)
        {
            cipherBlock[i] = data[i] ^ cipherBlockPre[i];
        }

        //�Í���
        cipher(cipherBlock);

        //�Í��������u���b�N���o��
        ofsFile.write(cipherBlock, Block);

        //1�O�̈Í��u���b�N�ɈÍ��������u���b�N���i�[
        memcpy(cipherBlockPre, cipherBlock, Block);

    } while (!ifsFile.eof());

}

void Encrypt::cipher(char* dst)
{
    //�Í���
    char cipherBlockTemp[Block];

    memset(cipherBlockTemp, 'S', Block);

    //�u���b�N�����Ƃɏ���
    for (int i = 0; i < Block; i++)
    {
        //XOR�Í�
        dst[i] = dst[i] ^ cipherBlockTemp[i];
    }

    return;
}