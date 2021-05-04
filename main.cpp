//�Q�l����(URL�������̂�����܂��B�\���󂠂�܂���)
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
    string firstArg = argv[FIRST];
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

        // �f�o�b�O�o��
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
        // �f�o�b�O�o��
        if (isFirstInput)
        {
            cout << "���͂���" << endl;
        }

        // �f�o�b�O�o��
        if (isAbridgementOption)
        {
            cout << "�ȗ�" << endl;
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
        case FIRST:

            // �f�o�b�O�o��
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

        case SECOND:

            // �f�o�b�O�o��
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

        case THIRD:

            // �f�o�b�O�o��
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

        case FOURTH:

            // �f�o�b�O�o��
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
