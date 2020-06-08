#pragma once
class UnionFind {

public:

	UnionFind():parent(26,0) {
		int mid = 0;
		for (auto &it : parent)
		{
			it += mid++;
		}
	}

	int find(const int index)
	{
		if (index == parent[index])
			return parent[index];
		int parent_index = find(parent[index]);
		return parent_index;
	}

	void merge(const int index1, const int index2)
	{
		parent[index2] = index1;
	}

private:

	std::vector<int> parent;

};
class Solution {
public:
	bool equationsPossible(std::vector<std::string>& equations) {
		UnionFind collection;
		for (auto equ : equations)
		{
			if (equ[1] == '=')
			{
				int index1 = equ[0] - 'a';
				int index2 = equ[3] - 'a';
				collection.merge(index1, index2);
			}
		}
		for (auto equ : equations)
		{
			if (equ[1] == '!')
			{
				int index1 = equ[0] - 'a';
				int index2 = equ[3] - 'a';
				if (collection.find(index1) == collection.find(index2))
					return false;
			}
		}
		return true;
	}
};
///
