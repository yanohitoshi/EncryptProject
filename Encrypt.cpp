#include "Encrypt.h"

Encrypt::Encrypt(char* _openFileName, char* _writeFileName)
    : openFileName(_openFileName)
    , writeFileName(_writeFileName)
{
}

Encrypt::~Encrypt()
{
    // ��Еt��
    delete ifsFile;
    delete ofsFile;

}

bool Encrypt::OpenFile()
{

    // �t�@�C�����J��
    ifsFile = new ifstream(openFileName, ios::binary);

    // �t�@�C�����J���Ă��Ȃ�������G���[�ʒm
    if (ifsFile == nullptr)
    {
        // �R���\�[���ɃG���[�`��
        cout << "ERROR::�t�@�C�����J���܂���ł���::ERROR" << endl;

        // ���s�����ꍇfalse��Ԃ�
        return false;
    }

    // �������Ă�����true��Ԃ�
    return true;
}

void Encrypt::FirstWriteEncrypt()
{
    // ����������Ă��Ȃ��t�@�C�����o��
    ofsFile = new ofstream(writeFileName, ios::app | ios::binary);

    // �������x�N�g���𐶐�
    memset(initialData, 'I', Block);

    // �Í������镽���f�[�^��ǂݍ���
    ifsFile->read(data, Block);

    // �u���b�N�����ƂɈÍ����̉�����
    for (int i = 0; i < Block; i++)
    {
        // XOR���Z���s��
        cipherBlock[i] = data[i] ^ initialData[i];
    }

    // �Í����֐��Ăяo��
    cipher(cipherBlock);

    // �Í��������u���b�N���o��
    ofsFile->write(cipherBlock, Block);

    // 1�O�̈Í��u���b�N�ɈÍ��������u���b�N���i�[
    memcpy(cipherBlockPre, cipherBlock, Block);

}

void Encrypt::AllWriteEncrypt()
{
    // ��ɍ�����Í��u���b�N��p���ăt�@�C���̏I���܂Ń��[�v
    do {

        // �f�[�^��Ǎ���
        ifsFile->read(data, Block);

        // �u���b�N�����Ƃɉ�����
        for (int i = 0; i < Block; i++)
        {
            cipherBlock[i] = data[i] ^ cipherBlockPre[i];
        }

        // �Í����֐��Ăяo��
        cipher(cipherBlock);

        // �Í��������u���b�N���o��
        ofsFile->write(cipherBlock, Block);

        // 1�O�̈Í��u���b�N�ɈÍ��������u���b�N���i�[
        memcpy(cipherBlockPre, cipherBlock, Block);

    } while (!ifsFile->eof());

}

void Encrypt::cipher(char* _dst)
{
    // �Í����ϐ�
    char cipherBlockTemp[Block];
    // �Í��J�M�𐶐�
    memset(cipherBlockTemp, 'S', Block);

    // �u���b�N�����Ƃɏ���
    for (int i = 0; i < Block; i++)
    {
        // XOR���Z���s���Í���
        _dst[i] = _dst[i] ^ cipherBlockTemp[i];
    }

    return;
}
