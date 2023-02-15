#include"TrieTree.h"
#include<iostream>


int main()
{
	setlocale(0, "");

	TrieTree tree;

	std::cout << "1-�������� �����, 2-������� �����, 3-��������� ������������� �����, 4-������� ��� �����, 5-DWCTS, 0-��������� ���������\n";

	int flag = 1;
	std::string word;
	while (flag)
	{
		std::cin >> flag;

		if(flag)
			switch (flag)
			{

			case 1:
				std::cout << "������� �����, ������� ���� ��������\n";
				std::cin >> word;
				tree.add(word);
				break;

			case 2:
				std::cout << "������� �����, ������� ����� �������\n";
				std::cin >> word;
				tree.remove(word);
				break;

			case 3:
				std::cout << "������� �����, ������� ����� ���������\n";
				std::cin >> word;
				if (tree.wordFind(word) == true)
					std::cout << "����� ����� ����\n";
				else
					std::cout << "������ ����� ���\n";
				break;

			case 4:
				tree.clear();
				break;

			case 5:
				std::cout << "������� ���������\n";
				std::cin >> word;
				tree.DWCTS(word);
				break;

			}
	}

	return 0;
	
}