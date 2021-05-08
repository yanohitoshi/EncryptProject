#pragma once

#include <iostream>
#include <fstream>

#define Block 1

// ���O��Ԓ�`
using namespace std;

class Encrypt
{
public:
	
	/*
	@brief	�R���X�g���N�^
	@param	_openFileName�@�J���t�@�C���̖��O�̃|�C���^
	@param _writeFileName�@�����o������t�@�C���̖��O�̃|�C���^
	*/
	Encrypt(char* _openFileName, char* _writeFileName);
	
	/*
	@brief	�f�X�g���N�^
	*/
	~Encrypt();

	/*
	@brief	�t�@�C�����J��
	@return true : ���� , false : ���s
	*/
	bool OpenFile();

	/*
	@brief  �����x�N�g���̐����ƍŏ��̃u���b�N�̈Í���
	*/
	void FirstWriteEncrypt();

	/*
	@brief  �S�Ẵu���b�N�̈Í���
	*/
	void AllWriteEncrypt();

private:
	
	/*
	@brief  �Í������s���֐�
	@param	_dst�@�Í�������u���b�N�̃|�C���^
	*/
	void cipher(char* _dst);

	// �J���t�@�C����
	string openFileName;

	// �����o�����s���t�@�C����
	string writeFileName;

	// �J�����t�@�C���̏���ǂݍ��ރt�@�C��
	ifstream* ifsFile;

	// �����o�����s���t�@�C��
	ofstream* ofsFile;

	// �ǂݍ��݃f�[�^
	char data[Block];

	// �������x�N�g��
	char initialData[Block];

	// 1�O�̈Í��u���b�N
	char cipherBlockPre[Block];

	// �Í��u���b�N
	char cipherBlock[Block];

};

