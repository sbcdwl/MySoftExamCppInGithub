#include <iostream>
using namespace std;

int main() 
{

	////自己写
	////插入排序算法，最终从小到大 
	//
	////设置算法用例并且输出
	//int arr[11] = { 36,27,20,60,55,7,71,36,44,67,16 };
	//cout << "first arr:" << endl;
	//for (int i = 0; i < 11; i++)
	//{
	//	cout << "arr[" << i << "]:" << arr[i] << endl;
	//}

	//int temp = 0;
	//
	//for (int i = 0; i < 11-1; i++)//“手牌”，,0~i为已完成对比区，i作为手牌的边界，i取0，1，。。。，10
	//{
	//	for (int chi = i + 1; ; )//“牌池”，用来挑出来和手牌里的对比，chi即池，记录的时要和手牌最后一个数作比较的那个数的下标
	//	{	
	//		

	//		//先把这一个牌池里要和手牌里比的挑出来，放在temp里
	//		int temp = arr[chi];
	//		//把temp和上一个，也就是手牌里最后一个对比，
	//		// 如果这个数比手牌里的数大，就直接把这个数放在那个手牌的后面（在这里不变），然后手牌的边界加1
	//		// 相等时也是直接往原处放即可
	//		if (temp > arr[chi-1]||temp == arr[chi-1])
	//		{
	//			arr[chi] = temp;
	//			break;//用break，这此的for跳出，跳出i所代表的那个for，让i能自增，也就是手牌边界加1
	//		}
	//		//如果这个数比手牌里的最后的那个数小，则当前手牌往后移动一位腾出位置，并且最后手牌边界加1，然后这个数再和手牌的前面一位数相比，此时如果这个数比手牌的那个数大了，则直接把这个数放在腾出来的位置上
	//		else//（temp<arr[chi - 1]）
	//		{	
	//			//应该放在循环里
	//			while (1) 
	//			{
	//				//往后腾位置
	//				arr[chi] == arr[chi - 1];
	//				//temp再和前一个数相比，也就是chi先自减一次，这样temp就能和前面两个的那个向比了
	//				chi--;
	//				if (temp > arr[chi - 1] || temp == arr[chi - 1] || chi - 1  == 0)
	//				{
	//					arr[chi] = temp;
	//					break;
	//				}
	//				
	//			}
	//			break;
	//			
	//			
	//			
	//		}


	//	}


	//}

	//cout << "666666666" << endl;
	//for (int i = 0; i < 11; i++)
	//{
	//	cout << "arr[" << i << "]:" << arr[i] << endl;
	//}

	//ai写
	// 插入排序算法，最终从小到大

	// 设置算法用例并且输出
	int arr[11] = { 36,27,20,60,55,7,71,36,44,67,16 };
	cout << "first arr:" << endl;
	for (int i = 0; i < 11; i++)   // 输出全部11个元素
	{
		cout << "arr[" << i << "]:" << arr[i] << endl;
	}

	// i 表示已排序手牌的最后一个位置，初始时手牌只有 arr[0]
	for (int i = 0; i < 10; i++)   // 总共需要插入 10 次（把后10张插入）
	{
		int temp = arr[i + 1];     // 牌池中待插入的牌
		int chi = i + 1;           // 这张牌的当前位置

		// 如果 temp 比前一个小，就往前挪
		while (chi > 0 && temp < arr[chi - 1])
		{
			arr[chi] = arr[chi - 1]; // 腾位置
			chi--;
		}
		arr[chi] = temp;            // 插入到正确位置
	}

	cout << "sorted arr:" << endl;
	for (int i = 0; i < 11; i++)
	{
		cout << "arr[" << i << "]:" << arr[i] << endl;
	}
	


	system("pause");
	return 0;
}