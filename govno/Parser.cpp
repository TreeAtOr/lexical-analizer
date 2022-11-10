#include "Parser.h"

void Parser::Parser_prog(string prog_text, set<string> dividers, set<string> keywords) {

	string symb;//������� ������ (�� char ������ ��� ������ �������� � set<string>)
	string lexem;//����� �������: �������, �������������, ��������� 
	int n_str = 1;//������� ������ ������

	int i = 0;//������� ��������
	while (prog_text[i] != '\0') {
		symb = prog_text[i];


		if (dividers.find(symb) != dividers.end() || symb[0] == '\n' || symb == " ") {//�������� �������� �� �����������

			if (keywords.find(lexem) != keywords.end()) {//�������� �������� �� keyword
				Token t;
				t.type = "KEYWORD";
				t.value = lexem;
				t.pos = n_str;
				token.push_back(t);
			}

			//�������� �� "�������" divider ����� == += <= � ��
			string ss;
			ss = symb + prog_text[i + 1];
			if (dividers.find(ss) != dividers.end()) {
				Token t;
				t.type = "DIVIDER";
				t.value = ss;
				t.pos = n_str;
				token.push_back(t);//����������� divider
				i++;
			}

			//���� ������ �� ������, ����� ������ � �� ������� divivder, �� divider ������ ����������
			if (symb != " " && symb[0]!='\n' && dividers.find(ss) == dividers.end()) { // �������� �� divide
				Token t;
				t.type = "DIVIDER";
				t.value = symb;
				t.pos = n_str;
				token.push_back(t);//����������� divider
			}

			//e��� ��� keyword � �� divider �� ��� ���� ��������� ���� id
			//�������� �������� �� ��������� � �� id
			lexem = "";
		}
		else 
			lexem += symb;
		if (symb[0] == '\n') n_str++;//�������� �� ����� ������
		i++;

	}

}

void Parser::Write() {
	for (int i = 0; i < token.size(); i++) {
		cout << token[i].type << " = " << token[i].value << "[" << token[i].pos << "]" << endl;
	}
}