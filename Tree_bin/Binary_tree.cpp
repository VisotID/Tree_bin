// �����:�������� �.�.
#include "Binary_tree.h"
#include <cassert>

void test()
{
	Tree_Node<int>* root = nullptr; // ������ ������
	Tree_Node<int>* top_2 = new Tree_Node<int>(9); // ������ �� ������ ��������
	Tree_Node<int>* top = new Tree_Node<int>(8); // ������ �� ������ ���������
	AddNode(5, top);
	AddNode(4, top);
	AddNode(7, top->left);
	/*    8
	*   5   4
	* 7
	*/
	
	Tree_Node<int>* top_3 = new Tree_Node<int>(7); // ����������� ������
	AddNode(3, top_3);
	AddNode(2, top_3->left);
	AddNode(1, top_3->left->left);
	/*		  7
	*	   	 3 
	*      2
	*    1
	*/
	
	Tree_Node<int>* top_4 = new Tree_Node<int>(7); // �����������(������) ������
	AddNode(5, top_4);
	AddNode(4, top_4);
	AddNode(11, top_4->left);
	AddNode(10, top_4->left);
	AddNode(9, top_4->right);
	AddNode(8, top_4->right);
	/*       7
	*   5        4
	* 11  10   9   8
	*/

	/// ����� ������� ��������� ������ ����
	assert(Data_Tree(top) == 8); // ������
	assert(Data_Tree(top->left) == 5); // ������� �����
	assert(Data_Tree(top->left->left) == 7); // ������� ����� �� ����� �����
	assert(Data_Tree(top_2) == 9); // ������ �� ������ ��������

	// ������ ������
	try
	{
		Data_Tree(root);
		assert(false);
	}
	catch (const underflow_error&)
	{

	}
	
	/// ����� �������� ������� �������� �����
	assert(count(root) == 0); // ������ ������
	assert(count(top) == 4);
	assert(count(top_2) == 1); // ������ �� ������ ��������
	assert(count(top_3) == 4); // ����������� ������
	assert(count(top_4) == 7); // �����������(������) ������

	/// ����� �������� ������� ����������� ������� ������
	assert(depth(top) == 2);
	assert(depth(top_2) == 0); // ������ �� ������ ��������
	assert(depth(root) == -1); // ������ ������
	assert(depth(top_3) == 3); // ����������� ������
	assert(depth(top_4) == 2); // �����������(������) ������

	// ����� �������� ������� �������
	// NLR ���������� � � ������� �����
	vector<int> arr;
	vector<int> arr_1;
	vector<int> test_1{ 8, 5, 7, 4 };
	NLR(top, arr);
	Stack_NLR(top, arr_1);
	assert(arr == test_1);
	assert(arr_1 == test_1);
	arr.clear();
	arr_1.clear();

	// � ����� ���������
	vector<int> test_2{ 9 };
	NLR(top_2, arr);
	Stack_NLR(top_2, arr_1);
	assert(arr == test_2);
	assert(arr_1 == test_2);
	arr.clear();
	arr_1.clear();

	// ����������� ������
	vector<int> test_3{ 7, 3, 2, 1};
	NLR(top_3, arr);
	Stack_NLR(top_3, arr_1);
	assert(arr == test_3);
	assert(arr_1 == test_3);
	arr.clear();
	arr_1.clear();

	// �����������(������) ������
	vector<int> test_4{ 7, 5, 11, 10, 4, 9, 8};
	NLR(top_4, arr);
	Stack_NLR(top_4, arr_1);
	assert(arr == test_4);
	assert(arr_1 == test_4);
	arr.clear();
	arr_1.clear();

	// NRL
	vector<int> test_5{8, 4, 5, 7};
	NRL(top, arr);
	assert(arr == test_5);
	arr.clear();

	// � ����� ���������
	vector<int> test_6{ 9 };
	NRL(top_2, arr);
	assert(arr == test_6);
	arr.clear();

	// ����������� ������
	vector<int> test_7{ 7, 3, 2, 1 };
	NRL(top_3, arr);
	assert(arr == test_7);
	arr.clear();

	// �����������(������) ������
	vector<int> test_8{ 7, 4, 8, 9, 5, 10, 11};
	NRL(top_4, arr);
	assert(arr == test_8);
	arr.clear();

	// LNR
	vector<int> test_9{7, 5, 8, 4};
	LNR(top, arr);
	assert(arr == test_9);
	arr.clear();

	// � ����� ���������
	vector<int> test_10{ 9 };
	LNR(top_2, arr);
	assert(arr == test_10);
	arr.clear();

	// ����������� ������
	vector<int> test_11{ 1, 2, 3, 7 };
	LNR(top_3, arr);
	assert(arr == test_11);
	arr.clear();

	// �����������(������) ������
	vector<int> test_12{11, 5, 10, 7, 9, 4, 8};
	LNR(top_4, arr);
	assert(arr == test_12);
	arr.clear();
	
	// RNL
	vector<int> test_13{ 4, 8, 5, 7 };
	RNL(top, arr);
	assert(arr == test_13);
	arr.clear();

	// � ����� ���������
	vector<int> test_14{ 9 };
	RNL(top_2, arr);
	assert(arr == test_14);
	arr.clear();

	// ����������� ������
	vector<int> test_15{ 7, 3, 2, 1 };
	RNL(top_3, arr);
	assert(arr == test_15);
	arr.clear();

	// �����������(������) ������
	vector<int> test_16{ 8, 4, 9, 7, 10, 5, 11};
	RNL(top_4, arr);
	assert(arr == test_16);
	arr.clear();

	// LRN
	vector<int> test_17{ 7, 5, 4, 8 };
	LRN(top, arr);
	assert(arr == test_17);
	arr.clear();

	// � ����� ���������
	vector<int> test_18{ 9 };
	LRN(top_2, arr);
	assert(arr == test_18);
	arr.clear();

	// ����������� ������
	vector<int> test_19{ 1, 2, 3, 7 };
	LRN(top_3, arr);
	assert(arr == test_19);
	arr.clear();

	// �����������(������) ������
	vector<int> test_20{ 11, 10, 5, 9, 8, 4, 7};
	LRN(top_4, arr);
	assert(arr == test_20);
	arr.clear();

	// RLN
	vector<int> test_21{ 4, 7, 5, 8 };
	RLN(top, arr);
	assert(arr == test_21);
	arr.clear();

	// � ����� ���������
	vector<int> test_22{ 9 };
	RLN(top_2, arr);
	assert(arr == test_22);
	arr.clear();

	// ����������� ������
	vector<int> test_23{ 1, 2, 3, 7 };
	RLN(top_3, arr);
	assert(arr == test_23);
	arr.clear();

	// �����������(������) ������
	vector<int> test_24{ 8, 9, 4, 10, 11, 5, 7};
	RLN(top_4, arr);
	assert(arr == test_24);
	arr.clear();

	Tree_Node<int>* top_5 = new Tree_Node<int>(8); // �������� ������ ������
	AddNode(3, top_5);
	AddNode(10, top_5);
	AddNode(1, top_5->left);
	AddNode(6, top_5->left);
	AddNode(9, top_5->right);
	AddNode(14, top_5->right);
	/*      8
	*   3       10
	* 1  6    9   14
	*/

	/// ����� �������� ������� ������� ���� � ������
	root = Add_Bin_Tree(1, root); // ������ ������
	Add_Bin_Tree(2, top);
	Add_Bin_Tree(3, top_2); // ������ �� ������ ��������
	Add_Bin_Tree(4, top_3); // ����������� ������
	Add_Bin_Tree(20, top_4); // �����������(������) ������
	assert(count(root) == 1); // ������ ������
	assert(count(top) == 5);
	assert(count(top_2) == 2); // ������ �� ������ ��������
	assert(count(top_3) == 5); // ����������� ������
	assert(count(top_4) == 8); // �����������(������) ������

	/// ����� �������� ������� �������� ���� �� ������
	remove(root, 1);
	root = nullptr;
	remove(top, 2);
	remove(top_2, 3);
	remove(top_3, 4);
	remove(top_5, 6);
	assert(count(root) == 0); // ������ ������
	assert(count(top) == 4);
	assert(count(top_2) == 1); // ������ �� ������ ��������
	assert(count(top_3) == 4); // ����������� ������
	assert(count(top_5) == 6); // �����������(������) ������

	/// ����� �������� ������� ������ ���� �� ��������� ��������
	assert(find(9, top_2) == 9); // ������ �� ������ ��������
	assert(find(1, top_3) == 1); // ����������� ������
	assert(find(10, top_5) == 10); // �������� ������ ������

	try 
	{
		find(1, root);
		assert(false);
	}
	catch(const out_of_range&)
	{

	}

	/// ����� �������� ������� �������� ������
    Del_Tree(root);
	Del_Tree(top);
	Del_Tree(top_2);
	Del_Tree(top_3);
	Del_Tree(top_4);
	Del_Tree(top_5);
}