#include "DividerReader.h"

std::set<std::string> DividerReader(const char* dividersFileName)
{
	std::ifstream dividersFile; // ���� � �������������
	std::string str; // ������ ��� ���������� �� �����
	std::set<std::string> dividersSet; // ��� ������������
 	
	dividersFile.open(dividersFileName);
	
	while (std::getline(dividersFile, str))
		dividersSet.insert(str); // ���������� ����

	std::set<std::string>::iterator it = dividersSet.begin(); // ������������� ��������� ��� ������ �� �����	| *
	for (int i = 0; it != dividersSet.end(); i++, it++)		  //												| * ��� ��� ������ ���� ����� ������ ��� ������������,
		std::cout << *it << std::endl;						  // ����� ����������� ���� �� �����				| * ������ ��� ����� �������� ����� ����� ��� ������ � �����, ��� ��� �������� ��������
															  // 												| *

	dividersFile.close();

	return dividersSet;
}