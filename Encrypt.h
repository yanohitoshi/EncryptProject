#pragma once

#include <iostream>
#include <fstream>

#define Block 1

// 名前空間定義
using namespace std;

class Encrypt
{
public:
	
	/*
	@brief	コンストラクタ
	@param	_openFileName　開くファイルの名前のポインタ
	@param _writeFileName　書き出しするファイルの名前のポインタ
	*/
	Encrypt(char* _openFileName, char* _writeFileName);
	
	/*
	@brief	デストラクタ
	*/
	~Encrypt();

	/*
	@brief	ファイルを開く
	@return true : 成功 , false : 失敗
	*/
	bool OpenFile();

	/*
	@brief  初期ベクトルの生成と最初のブロックの暗号化
	*/
	void FirstWriteEncrypt();

	/*
	@brief  全てのブロックの暗号化
	*/
	void AllWriteEncrypt();

private:
	
	/*
	@brief  暗号化を行う関数
	@param	_dst　暗号化するブロックのポインタ
	*/
	void cipher(char* _dst);

	// 開くファイル名
	string openFileName;

	// 書き出しを行うファイル名
	string writeFileName;

	// 開いたファイルの情報を読み込むファイル
	ifstream* ifsFile;

	// 書き出しを行うファイル
	ofstream* ofsFile;

	// 読み込みデータ
	char data[Block];

	// 初期化ベクトル
	char initialData[Block];

	// 1つ前の暗号ブロック
	char cipherBlockPre[Block];

	// 暗号ブロック
	char cipherBlock[Block];

};

