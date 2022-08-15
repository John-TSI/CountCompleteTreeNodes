// https://leetcode.com/problems/count-complete-tree-nodes/

#include<iostream>
#include"../inc/solution.hpp"


int main()
{
	TreeNode n4(4), n5(5), n6(6);
	TreeNode n3(3, &n6, nullptr);
	TreeNode n2(2, &n4, &n5);
	TreeNode root(1, &n2, &n3);

	std::cout << Solution().countNodes(&root);  // 6
	return 0;
}

