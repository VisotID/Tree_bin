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
/// ���������: O(1)
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
/// ���������: O(1)
/// const Tree_Node<T>* tree - ����������� ��������� �� ���� ������
/// ���� ��������� ������, ������� ����������
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
/// ���������: O(n)
/// Tree_Node<T>* tree - ��������� �� ���� ������
template <typename T>
void Del_Tree(Tree_Node<T>* tree)
{
	if (tree != nullptr) // ���� ��������� �� ������
	{
		Del_Tree(tree->left); // ���������� �������� ������� �������� � ����� �������
		Del_Tree(tree->right); // ���������� �������� ������� �������� � ������ �������
		delete tree; // �������� ���������
	}

}

/// ��������� ������� ������ ������ NLR(������, N - ��������� �������� ����, L - ������� � ������ �������, R - ������� � ������� �������)
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

/// ��������� ������� ������ ������ NRL(������, N - ��������� �������� ����, R - ������� � ������� �������, L - ������� � ������ �������)
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

/// ��������� ������� ������ ������ LNR(������������, L - ������� � ������ �������, N - ��������� �������� ����, R - ������� � ������� �������)
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

/// ��������� ������� ������ ������ RNL(������������, R - ������� � ������� �������, N - ��������� �������� ����, L - ������� � ������ �������)
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

/// ��������� ������� ������ ������ LRN(��������, L - ������� � ������ �������, R - ������� � ������� �������, N - ��������� �������� ����)
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

/// ��������� ������� ������ ������ RLN(��������, R - ������� � ������� �������, L - ������� � ������ �������, N - ��������� �������� ����)
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

/// ��������� ������� ������ ������ NLR(������) � ������� �����
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
/// ���������: O(n)
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
/// ���������: O(n)
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

/// ��������� ������� ������� ������ ���� � �������� ������
/// ���������: O(n)
/// T data - ������ ����, Tree_Node<T>* curr - ��������� �� ���� ������
template <typename T>
Tree_Node<T>* Add_Bin_Tree(T data, Tree_Node<T>* curr)
{
	if (curr == nullptr) // ���� ������� ���� ������
	{
		return new Tree_Node<T>(data); // ������ ����� ����
	}
	if (data < curr->date) // ���� ������ ������ �������� ����
	{
		curr->left = Add_Bin_Tree<T>(data, curr->left); // ���������� �������� ������� � ��������� ���� � ����� ���������
	}
	if (data > curr->date) // ���� ������ ������ �������� ����
	{
		curr->right = Add_Bin_Tree<T>(data, curr->right); // ���������� �������� ������� � ��������� ���� � ������ ���������
	}
	return curr; // ������� ��������� �� ������� ����
}

/// ��������� ������� ������ ���� � �������� ���������
/// ���������: O(log n) - � ������������, O(n) - �����������
/// T data - ������ ����, Tree_Node<T>* curr - ��������� �� ���� ������
template <typename T>
T find(T data, Tree_Node<T>* curr)
{
	if (curr == nullptr) // ���� ���� ������
	{
		throw out_of_range("������� �� ������"); // ������� ����������
	}
	if (data == curr->date) // ���� ������ �������
	{
		return curr->date; // ���������� ������ ����
	}
	if (data < curr->date) // ���� ������ ������ �������� ����
	{
		return find<T>(data, curr->left); // ���������� �������� ������� � ���� � ����� ���������
	}
	if (data > curr->date) // ���� ������ ������ �������� ����
	{
		return find<T>(data, curr->right); // ���������� �������� ������� � ���� ���� � ������ ���������
	}
}

/// ��������� ������� ������ ���� � ����������� ��������� ������
/// ���������: O(log n) - � ������������������, O(n) - �����������
/// Tree_Node<T>* curr - ��������� �� ���� ������
template <typename T>
Tree_Node<T>* Find_min(Tree_Node<T>* curr)
{
	Tree_Node<T>* temp = curr; // ��������� ��������� �� ������� ����
	while (temp && temp->left != nullptr) // ���� ���������� ����� �������� ����
	{
		temp = temp->left; // ������� � ������ ����
	}
	return temp; // ������� ��������� �� ���� � ����������� ���������
}

/// ��������� ������� ������ ���� � ������������ ��������� ������
/// ���������: O(log n) - � ������������������, O(n) - �����������
/// Tree_Node<T>* curr - ��������� �� ���� ������
template <typename T>
Tree_Node<T>* Find_max(Tree_Node<T>* curr)
{
	Tree_Node<T>* temp = curr; // ��������� ��������� �� ������� ����
	while (temp && temp->right != nullptr) // ���� ���������� ������ �������� ����
	{
		temp = temp->right; // ������� � ������� ����
	}
	return temp; // ������� ��������� �� ���� � ������������ ���������
}
///////////////////////////
/// ��������� ������� �������� ���� ������
/// ���������: O(n)
/// T data - ������ ����, Tree_Node<T>* curr - ��������� �� ���� ������
template <typename T>
Tree_Node<T>* remove(Tree_Node<T>* curr, T data)
{
	if (curr == nullptr) // ���� ���� ������
	{
		return curr; // ���������� ������ ���������
	}
	if (data < curr->date) // ���� ������ ������ �������� ����
	{
		curr->left = remove<T>(curr->left, data); // ���������� �������� ������� � ������� � ����� ���������
	}
	else if (data > curr->date) // ���� ������ ������ �������� ����
	{
		curr->right = remove<T>(curr->right, data); // ���������� �������� ������� � ������� � ������ ���������
	}
	else // ���� ������ ���� ��� ��������
	{
		Tree_Node<T>* temp; // ��������� ��������� ��� �������� ����
		if (curr->left == nullptr) // ���� ��� ������ ���������
		{
			temp = curr->right; // ��������� �� ��������� ���������� ������ ���������
			delete(curr); // �������� �������� ����
			return temp; // ���������� ������ ���������
		}
		else if (curr->right == nullptr) // ���� ��� ������� ���������
		{
			temp = curr->left; // ��������� �� ��������� ���������� ����� ���������
			delete(curr); // �������� �������� ����
			return temp; // ���������� ����� ���������
		}
		// ���� ���� ��� ���������
		temp = Find_min<T>(curr->right); // ����� ������������ ���� � ������ ���������
		curr->date = temp->date; // ������ ������ �������� ����
		curr->right = remove<T>(curr->right, temp->date); // �������� ������������ ���� �� ������� ���������
	}
	return curr; // ������� ��������� �� ������� ����
}

/// ��������� ������� ����������� ������ �� ������
/// Tree_Node<T>* curr - ��������� �� ���� ������
template <typename T>
Tree_Node<T>* copy_tree(Tree_Node<T>* curr)
{
	if (curr) // ���� ������ ����
	{
		Tree_Node<T>* temp = new Tree_Node<T>(); // �������� ������ �����
		temp->data = curr->data; // �������� ������ ��� �����
		temp->left = copy_tree(curr->left); // ���������� �������� ������� � �������� ����� ���������
		temp->right = copy_tree(curr->right); // ���������� �������� ������� � �������� ������ ���������
		return temp; // ���������� ��������� �� ����� ������
	}
	return nullptr;
}

void test();
