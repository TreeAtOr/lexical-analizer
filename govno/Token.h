#pragma once
#include <iostream>
#include <string>
using namespace std;
struct Token
{
	string type;//DIVIDER KEYWORD IDENTIFIER CONSTANT ���� �������
	string value;//�������� �������
	int pos[2];//������ �� ������� ���������� �����
	bool error = false;
	//int pos[2];
};