#pragma once
#include <iostream>
#include <string>
#include <set>
#include <vector>

#include "Token.h"
using namespace std;
class Parser {
public:
	void Parser_prog(string, set<string>, set<string>);//��� ������
	void Write();//����� �������
	vector<Token> token;//������ �������
	bool Is_digit(string);
};