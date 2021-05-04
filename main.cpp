//http://yohshiy.blog.fc2.com/blog-entry-260.html
//https://qiita.com/p1ro3/items/6bb1c78a6c27109f6b93
//https://qiita.com/asksaito/items/1793b8d8b3069b0b8d68

#include <iostream>
#include "Encrypt.h"

bool ChackArgument(int _count,char* argv, bool _isAbridgementOption);

int main(int argc, char* argv[])
{

    // �R�}���h���C����������łȂ����`�F�b�N
    if (argc <= 1)
    {
        cout << "ERROR::�R�}���h���C����������ł�::ERROR" << endl;
        cout << "Enter�L�[�ŏI��" << endl;
        getchar();
        return 0;
    }
    else if (argc > 5)
    {
        cout << "ERROR::�R�}���h���C�����������e�͈͂𒴂��Ă��܂�::ERROR" << endl;
        cout << "Enter�L�[�ŏI��" << endl;
        getchar();
        return 0;
    }

    // �I�v�V�������ȗ����Ďg���Ă��邩�`�F�b�N�t���O�ϐ�
    string firstArg = argv[1];
    bool isAbridgementOption = false;

    if (firstArg == "-oi" || firstArg == "-io")
    {
        isAbridgementOption = true;
        if (argc > 4)
        {
            cout << "ERROR::�I�v�V�����ɑ΂��Ĉ����������ł�::ERROR" << endl;
            cout << "Enter�L�[�ŏI��" << endl;
            getchar();
            return 0;
        }
    }
    else if (firstArg == "-i" || firstArg == "-o")
    {
        if (argc <= 4)
        {
            cout << "ERROR::�I�v�V�����ɑ΂��Ĉ��������Ȃ��ł�::ERROR" << endl;
            cout << "Enter�L�[�ŏI��" << endl;
            getchar();
            return 0;
        }
    }

    // �R�}���h���C�������`�F�b�N�p�t���O�ϐ�
    bool argumentChack = false;

    // �S�R�}���h���C���������`�F�b�N
    for (int chackCount = 1; chackCount < argc; chackCount++)
    {
        argumentChack = ChackArgument(chackCount, argv[chackCount], isAbridgementOption);

        cout << "argumentChack" << endl;
        cout << argumentChack << endl;
    }

    // ��ɓ��̓t�@�C�����������Ă��邩�ǂ���
    bool isFirstInput = false;

    if (firstArg == "-i" || firstArg == "-io")
    {
        isFirstInput = true;
    }

    if (argumentChack)
    {
        Encrypt* encrypt;
        if (isFirstInput)
        {
            cout << "���͂���" << endl;
        }

        if (isAbridgementOption)
        {
            cout << "�ȗ�" << endl;
        }

        if (isFirstInput)
        {
            if (isAbridgementOption)
            {
                encrypt = new Encrypt(argv[2], argv[3]);
            }
            else
            {
                encrypt = new Encrypt(argv[2], argv[4]);
            }
        }
        else
        {
            if (isAbridgementOption)
            {
                encrypt = new Encrypt(argv[3], argv[2]);
            }
            else
            {
                encrypt = new Encrypt(argv[4], argv[2]);
            }
        }

        bool success = encrypt->OpenFile();

        if (success)
        {
            encrypt->FirstWriteEncrypt();
            encrypt->AllWriteEncrypt();

            delete encrypt;

            cout << "�I�����܂����B" << endl;

            return 0;
        }
        else
        {

            cout << "Enter�L�[�ŏI��" << endl;

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
        // �R�}���h���C�������̃`�F�b�N�pstring�ϐ�
        string chackArgument = _argv;

        switch (_count) 
        {
        case 1:
            cout << "case1" << endl;
            cout << chackArgument <<endl;
            // �I�v�V�����������Ė�����΃G���[��Ԃ�
            if (chackArgument != "-o" && chackArgument != "-i" &&
                chackArgument != "-oi" && chackArgument != "-io")
            {
                cout << "ERROR::�I�v�V��������͂��Ă�������::ERROR" << endl;
                cout << "Enter�L�[�ŏI��" << endl;
                getchar();
                erroeChack = false;
            }
            erroeChack = true;
            break;

        case 2:
            cout << "case2" << endl;
            cout << chackArgument << endl;
            // �I�v�V�����������Ă�����G���[��Ԃ�
            if (chackArgument == "-o" || chackArgument == "-i" ||
                chackArgument == "-oi" || chackArgument == "-io")
            {
                cout << "ERROR::�t�@�C��������͂��Ă�������::ERROR" << endl;
                cout << "Enter�L�[�ŏI��" << endl;
                getchar();
                erroeChack = false;
            }
            erroeChack = true;
            break;

        case 3:

            cout << "case3" << endl;
            cout << chackArgument << endl;
            cout << _isAbridgementOption << endl;

            if (!_isAbridgementOption)
            {
                // �I�v�V�����������Ė�����΃G���[��Ԃ�
                if (chackArgument != "-o" && chackArgument != "-i" &&
                    chackArgument != "-oi" && chackArgument != "-io")
                {
                    cout << "ERROR::�I�v�V��������͂��Ă�������::ERROR" << endl;
                    cout << "Enter�L�[�ŏI��" << endl;
                    getchar();
                    erroeChack = false;
                }

            }

            erroeChack = true;
            break;

        case 4:
            cout << "case4" << endl;
            cout << chackArgument << endl;
            // �I�v�V�����������Ă�����G���[��Ԃ�
            if (chackArgument == "-o" || chackArgument == "-i" ||
                chackArgument == "-oi" || chackArgument == "-io")
            {
                cout << "ERROR::�t�@�C��������͂��Ă�������::ERROR" << endl;
                cout << "Enter�L�[�ŏI��" << endl;
                getchar();
                erroeChack = false;
            }
            erroeChack = true;
            break;
        }
    }

    return erroeChack;

}
