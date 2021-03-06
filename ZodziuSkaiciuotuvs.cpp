// ZodziuKalkuliatorius.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <set>


using namespace std;

bool jeiNereikalingas(char c)
{
	return c == ',' || c == '.' || c == ')' || c == '(';
}

int main()
{
	ifstream in("input.txt");
	string line;
	string word;
	int linenum=0;
	multimap<string, int> mapas{};
	while (getline(in, line))
	{
		linenum++;
		istringstream iss(line);
		while (iss >> word)
		{
			word.erase(remove_if(word.begin(), word.end(), jeiNereikalingas), word.end());
			transform(word.begin(), word.end(), word.begin(),::tolower);
			mapas.insert(pair<string, int>(word, linenum));
			
		}

	}
	for (multimap<string,int>::iterator it = mapas.begin();it!=mapas.end();it=mapas.upper_bound(it->first))
	{
		if (mapas.count(it->first) > 1)
		{
			cout << it->first << " " << mapas.count(it->first) << " ";
			set<int> setas;
			std::pair<multimap<string, int>::iterator, multimap<string, int>::iterator> result = mapas.equal_range(it->first);
			for (multimap<string, int>::iterator iter = result.first; iter != result.second; ++iter)
				setas.insert(iter->second);
			for (auto i : setas)
				cout << i << " "; 
			cout << endl;
		}
		
	}

	return 0;
}

