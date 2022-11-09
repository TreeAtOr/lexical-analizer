#include "KeywordReader.h"

std::set<std::string> KeywordReader(const char* keywordsFileName)
{
	std::ifstream keywordsFile; // ���� � ��������� �������
	std::string str; // ������ ��� ���������� �� �����
	std::set<std::string> keywordsSet; // ��� �������� ����

	keywordsFile.open(keywordsFileName);

	while (std::getline(keywordsFile, str))
		keywordsSet.insert(str); // ���������� ����

	std::set<std::string>::iterator it = keywordsSet.begin(); // ������������� ��������� ��� ������ �� �����	| *
	for (int i = 0; it != keywordsSet.end(); i++, it++)		  //												| * ��� ��� ������ ���� ����� ������ ��� ������������,
		std::cout << *it << std::endl;						  // ����� ����������� ���� �� �����				| * ������ ��� ����� �������� ����� ����� ��� ������ � �����, ��� ��� �������� ��������
															  // 												| *

	keywordsFile.close();

	return keywordsSet;
}