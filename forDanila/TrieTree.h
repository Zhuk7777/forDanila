#pragma once

#include<string>

class TrieTree
{
	struct TrieNode
	{
		TrieNode* alph[27];

		TrieNode()
		{
			for (int i = 0; i < 27; i++)
				alph[i] = nullptr;
		}
	};

		typedef TrieNode* TTrie;
		TrieNode* root;
		TrieNode* tail;

		void domesticClear(TTrie& node)
		{
			for (int i = 0; i < 27; i++)
			{
				if (node->alph[i] != nullptr)domesticClear(node->alph[i]);
				node->alph[i] = nullptr;
			}


			for (int i = 0; i < 27; i++) {
				delete node->alph[i];
				node->alph[i] = nullptr;
			}
		}
		void domesticRemove(TTrie& r, std::string word, int i, int size)
		{
			if (i < size)
				domesticRemove(r->alph[int(word[i] - 'a')], word, i + 1, size);

			if (i == size)
				r->alph[26] = nullptr;

		}


		void domesticDWCTS(TTrie& r, std::string substr, int i, int size)//DWCTS-deleting words containing this substring
		{
			if (i < size)
				domesticDWCTS(r->alph[int(substr[i] - 'a')], substr, i + 1, size);

			if (i == size)
				domesticClear(r);

		}

	public:

		TrieTree() : root(new TrieNode), tail(new TrieNode) {};
		~TrieTree()
		{
			clear();
			delete root;
			delete tail;
		}

		void clear()
		{
			domesticClear(root);

			root = new TrieNode;
			tail = new TrieNode;
		}

		void add(std::string word)
		{
			TrieNode* newRoot = root;
			for (int i = 0; i < word.size(); i++)
			{
				if (newRoot->alph[int(word[i] - 'a')] != nullptr)
				{
					newRoot = newRoot->alph[int(word[i] - 'a')];
				}
				else
				{
					newRoot->alph[int(word[i] - 'a')] = new TrieNode;
					newRoot = newRoot->alph[int(word[i] - 'a')];
				}

			}
			newRoot->alph[26] = tail;
		}

		bool wordFind(std::string word)
		{
			bool flag = true;
			TrieNode* newRoot = root;
			int i = 0;
			while (flag && i < word.size())
			{
				if (newRoot->alph[int(word[i] - 'a')] == nullptr)
					flag = false;
				else {
					newRoot = newRoot->alph[int(word[i] - 'a')];
					i++;
				}
			}
			if (newRoot->alph[26] != tail)
				flag = false;
			return flag;
		}

		void remove(std::string word)
		{
			if (wordFind(word) == true)
				domesticRemove(root, word, 0, word.size());
		}

		void DWCTS(std::string substr)//deleting words containing this substring
		{
			domesticDWCTS(root, substr, 0, substr.size());
		}
};
