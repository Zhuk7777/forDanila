#include"TrieTree.h"
#include<iostream>


int main()
{
	setlocale(0, "");

	TrieTree tree;

	std::cout << "1-добавить слово, 2-удалить слово, 3-проверить существование слова, 4-удалить все слова, 5-DWCTS, 0-завершить программу\n";

	int flag = 1;
	std::string word;
	while (flag)
	{
		std::cin >> flag;

		if(flag)
			switch (flag)
			{

			case 1:
				std::cout << "Введите слово, которое надо добавить\n";
				std::cin >> word;
				tree.add(word);
				break;

			case 2:
				std::cout << "Введите слово, которое нужно удалить\n";
				std::cin >> word;
				tree.remove(word);
				break;

			case 3:
				std::cout << "Введите слово, которое нужно проверить\n";
				std::cin >> word;
				if (tree.wordFind(word) == true)
					std::cout << "Такое слово есть\n";
				else
					std::cout << "Такого слова нет\n";
				break;

			case 4:
				tree.clear();
				break;

			case 5:
				std::cout << "Введите подстроку\n";
				std::cin >> word;
				tree.DWCTS(word);
				break;

			}
	}

	return 0;
	
}