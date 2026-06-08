/*
								————左根右
红黑树是二叉排序树，左子树<=根节点<=右子树

红黑树的每个节点不是红色就是黑色				
								————根叶黑
根节点一定是黑色								

叶子节点(NULL)一定是黑色
								————不红红
不允许存在两个相邻的红色节点，即红色的节点的父节点和子节点必须是黑色
兄弟节点不算相邻的节点，可以同为红色
可以出现相邻的黑色节点
								————黑路同
从任意节点往下走到任意叶子节点的路径上，走不同的路径时，黑色节点的数量必须相同

推出：根节点到叶子节点的路径，最长路径不会超过最短路径的两倍
*/

#include <iostream>

struct RBNode {
	int key;			//数据
	RBNode* lChild;
	RBNode* rChild;
	RBNode* parent;
	int color;			//节点颜色，0是黑，1是白
};

int main() {

	std::cout << "test" << std::endl;

	system("pause");
	return 0;
}