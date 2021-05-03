//http://yohshiy.blog.fc2.com/blog-entry-260.html
//https://qiita.com/p1ro3/items/6bb1c78a6c27109f6b93
//https://qiita.com/asksaito/items/1793b8d8b3069b0b8d68

#include <iostream>
#include "Encrypt.h"


int main(int argc, char* argv[])
{
    if (argc <= 1)
    {
        cout << "�R�}���h���C����������ł��B" << endl;
        cout << "Enter�L�[�ŏI��" << endl;
        getchar();
        return 0;
    }


    Encrypt* encrypt;
    encrypt = new Encrypt(argv[1], argv[3]);

    bool success = encrypt->OpenFile();

    if (success)
    {
        encrypt->FirstWriteEncrypt();
        encrypt->AllWriteEncrypt();

        delete encrypt;

        return 0;
    }
    else
    {
        cout << "�t�@�C�����J���܂���ł����B" << endl;
        cout << "Enter�L�[�ŏI��" << endl;
        getchar();

        delete encrypt;

        return 0;
    }

}
