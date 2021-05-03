#pragma once

#include <iostream>
#include <fstream>

#define Block 1

// ���O��Ԓ�`
using namespace std;

class Encrypt
{
public:

	Encrypt(char* _openFileName, char* _writeFileName);
	~Encrypt();
	bool OpenFile();
	void FirstWriteEncrypt();
	void AllWriteEncrypt();
private:
	
	void cipher(char* dst);

	// �J���t�@�C����
	string openFileName;
	// �����o�����s���t�@�C����
	string writeFileName;

	// �J�����t�@�C���̏���ǂݍ��ރt�@�C��
	ifstream ifsFile;
	// �����o�����s���t�@�C��
	ofstream ofsFile;

	//�ǂݍ��݃f�[�^
	// ifs���R�s�[���锠
	char data[Block];

	//�������x�N�g��
	char initialData[Block];

	//1�O�̈Í��u���b�N
	char cipherBlockPre[Block];

	//�Í��u���b�N
	char cipherBlock[Block];

};

