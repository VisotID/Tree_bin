// �����:�������� �.�.
#pragma once// ��������� � �++, ��� �������������� ������������� ��������� ������ � ���� �� ������������� �����

#include <iostream>
#include <vector>
#include <stack> // ���������� �++ ��� ������ �� ������
#include <stdexcept> // ���������� �++ ��� ��������� ������

using namespace std; // ���������� ������������ ���� std ��� ����, ����� �� ������ ����� ��������� cin, cout "std"

// ��������� ����� ���� ������
template <typename T>
class Tree_Node {
public:
		Tree_Node<T>* left; // ��������� �� ����� �����
		Tree_Node<T>* right; // ��������� �� ������ �����
		T date; // �������

		/// ����������� ����
		/// T data - �������
		Tree_Node(T data)
		{
			this->date = data;
			this->left = this->right = nullptr;
		}
	};

/// ��������� ������� ���������� ���� � ������
/// T x - �������, Tree_Node<T>* tree - ��������� �� ����
template <typename T>
void AddNode(T x, Tree_Node<T>* tree)
{
	if (tree == nullptr) // ���� ��������� ������
	{
		tree = new Tree_Node<T>(x); // �������� ������ ��� ������� ������
		return;
	}
	if (tree->left == nullptr) // ���� ��������� �� ����� ����� ������
	{
		tree->left = new Tree_Node<T>(x); // �������� ������ ��� ���� ����� �����
		return;
	}
	if (tree->right == nullptr) // ���� ��������� �� ������ ����� ������
	{
		tree->right = new Tree_Node<T>(x); // �������� ������ ��� ���� ������ �����
		return;
	}
}

/// ��������� ������� ��������� ������ ����
/// const Tree_Node<T>* tree - ����������� ��������� �� ���� ������
/// ���� ��������� ������, 
template <typename T>
T Data_Tree(const Tree_Node<T>* tree)
{
	if (tree != nullptr) // ���� ��������� �� ������
	{
		return tree->date; // ��������� ������ ����
	}
	throw underflow_error("������ ���������"); // ������� ����������
}

/// ��������� ������� �������� ������
/// Tree_Node<T>* tree - ��������� �� ���� ������
template <typename T>
void Del_Tree(Tree_Node<T>* tree)
{
	if (tree != nullptr) // ���� ��������� �� ������
	{
		Del_Tree(tree->right); // ���������� �������� ������� �������� � ������ �������
		Del_Tree(tree->left); // ���������� �������� ������� �������� � ����� �������
		delete tree; // �������� ���������
	}

}

/// ��������� ������� ������ ������ NLR
/// Tree_Node<T>* tree - ��������� �� ���� ������, vector<T>& arr - ������ ���� ������
template <typename T>
void NLR(Tree_Node<T>* tree, vector<T>& arr)
{
	if (tree != nullptr) // ���� ��������� �� ������
	{
		cout << tree->date << " "; // ����� ������ ����
		arr.push_back(tree->date); // ���������� ������ ���� � ������
		NLR(tree->left, arr); // ���������� �������� ������� ������ � ����� �������
		NLR(tree->right, arr); // ���������� �������� ������� ������ � ������ �������
	}
}

/// ��������� ������� ������ ������ NRL
/// Tree_Node<T>* tree - ��������� �� ���� ������, vector<T>& arr - ������ ���� ������
template <typename T>
void NRL(Tree_Node<T>* tree, vector<T>& arr)
{
	if (tree != nullptr) // ���� ��������� �� ������
	{
		cout << tree->date << " "; // ����� ������ ����
		arr.push_back(tree->date); // ���������� ������ ���� � ������
		NRL(tree->right, arr); // ���������� �������� ������� ������ � ������ �������
		NRL(tree->left, arr); // ���������� �������� ������� ������ � ����� �������
	}
}

/// ��������� ������� ������ ������ LNR
/// Tree_Node<T>* tree - ��������� �� ���� ������, vector<T>& arr - ������ ���� ������
template <typename T>
void LNR(Tree_Node<T>* tree, vector<T>& arr)
{
	if (tree != nullptr) // ���� ��������� �� ������
	{
		LNR(tree->left, arr); // ���������� �������� ������� ������ � ����� �������
		cout << tree->date << " "; // ����� ������ ����
		arr.push_back(tree->date); // ���������� ������ ���� � ������
		LNR(tree->right, arr); // ���������� �������� ������� ������ � ������ �������
	}
}

/// ��������� ������� ������ ������ RNL
/// Tree_Node<T>* tree - ��������� �� ���� ������, vector<T>& arr - ������ ���� ������
template <typename T>
void RNL(Tree_Node<T>* tree, vector<T>& arr)
{
	if (tree != nullptr) // ���� ��������� �� ������
	{
		RNL(tree->right, arr); // ���������� �������� ������� ������ � ������ �������
		cout << tree->date << " "; // ����� ������ ����
		arr.push_back(tree->date); // ���������� ������ ���� � ������
		RNL(tree->left, arr); // ���������� �������� ������� ������ � ����� �������
	}
}

/// ��������� ������� ������ ������ LRN
/// Tree_Node<T>* tree - ��������� �� ���� ������, vector<T>& arr - ������ ���� ������
template <typename T>
void LRN(Tree_Node<T>* tree, vector<T>& arr)
{
	if (tree != nullptr) // ���� ��������� �� ������
	{
		LRN(tree->left, arr); // ���������� �������� ������� ������ � ����� �������
		LRN(tree->right, arr); // ���������� �������� ������� ������ � ������ �������
		cout << tree->date << " "; // ����� ������ ����
		arr.push_back(tree->date); // ���������� ������ ���� � ������
	}
}

/// ��������� ������� ������ ������ RLN
/// Tree_Node<T>* tree - ��������� �� ���� ������, vector<T>& arr - ������ ���� ������
template <typename T>
void RLN(Tree_Node<T>* tree, vector<T>& arr)
{
	if (tree != nullptr) // ���� ��������� �� ������
	{
		RLN(tree->right, arr); // ���������� �������� ������� ������ � ������ �������
		RLN(tree->left, arr); // ���������� �������� ������� ������ � ����� �������
		cout << tree->date << " "; // ����� ������ ����
		arr.push_back(tree->date); // ���������� ������ ���� � ������
	}
}

/// ��������� ������� ������ ������ NLR � ������� �����
/// Tree_Node<T>* tree - ��������� �� ���� ������, vector<T>& arr - ������ ���� ������
template <typename T>
void Stack_NLR(Tree_Node<T>* tree, vector<T>& arr)
{
	if (tree != nullptr) // ���� ��������� �� ������
	{
		Tree_Node<T>* time_tree; // ������ ��������� ���������
		stack<Tree_Node<T>*> s; // ������ ���������� �����
		s.push(tree); // ���������� ������ � ����
		while (!s.empty()) // ���� ���� �� ������
		{
			time_tree = s.top(); // ���������� �������, ����������� � �����, �� ��������� ����������
			s.pop(); // ����������� ������� �� �����
			cout << time_tree->date << " "; // ����� ������ ����
			arr.push_back(time_tree->date); // ���������� ������ ���� � ������
			if (time_tree->right != nullptr) // ���� ������ ������� �� ������
			{
				s.push(time_tree->right); // ���������� ������ ������� � ����
			}
			if (time_tree->left != nullptr) // ���� ����� ������� �� ������
			{
				s.push(time_tree->left); // ���������� ����� ������� � ����
			}
		}
	}
}

/// ��������� ������� �������� ���������� ����� � ������
/// Tree_Node<T>* tree - ��������� �� ���� ������
template <typename T>
int count(Tree_Node<T>* tree)
{
	if (tree != nullptr) // ���� ��������� �� ������
	{
		return 1 + count(tree->left) + count(tree->right); // ���������� �������� ������� � ������� ����
	}
	return 0;
}

/// ��������� ������� ����������� ������� ������
/// -1 - ������� ������� ������
/// Tree_Node<T>* tree - ��������� �� ���� ������
template <typename T>
int depth(Tree_Node<T>* tree)
{
	if (tree != nullptr) // ���� ��������� �� ������
	{
		int left = depth(tree->left); // ���������� �������� ������� � ���������� ������� ������ ���������
		int right = depth(tree->right); // ���������� �������� ������� � ���������� ������� ������� ���������
		return max(left, right) + 1; // ������� ������� �� �������
	}
	return -1; // ������� ������� ������
}

void test();
