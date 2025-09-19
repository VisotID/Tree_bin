// Автор:Высоцкая И.Д.
#pragma once// директива в С++, для предотвращения многократного включения одного и того же заголовочного файла

#include <iostream>
#include <vector>
#include <stack> // библиотека С++ для работы со стеком
#include <stdexcept> // библиотека С++ для обработки ошибок

using namespace std; // используем пространство имен std для того, чтобы не писать перед функциями cin, cout "std"

// Шаблонный класс узла дерева
template <typename T>
class Tree_Node {
public:
		Tree_Node<T>* left; // указатель на левую ветку
		Tree_Node<T>* right; // указатель на правую ветку
		T date; // элемент

		/// Конструктор узла
		/// T data - элемент
		Tree_Node(T data)
		{
			this->date = data;
			this->left = this->right = nullptr;
		}
	};

/// Шаблонная функция добавления узла в дерево
/// T x - элемент, Tree_Node<T>* tree - указатель на узел
template <typename T>
void AddNode(T x, Tree_Node<T>* tree)
{
	if (tree == nullptr) // если указатель пустой
	{
		tree = new Tree_Node<T>(x); // выделяем память под вершину дерева
		return;
	}
	if (tree->left == nullptr) // если указатель на левую ветку пустой
	{
		tree->left = new Tree_Node<T>(x); // выделяем память под узел левой ветки
		return;
	}
	if (tree->right == nullptr) // если указатель на правую ветку пустой
	{
		tree->right = new Tree_Node<T>(x); // выделяем память под узел правой ветки
		return;
	}
}

/// Шаблонная функция получения данных узла
/// const Tree_Node<T>* tree - константный указатель на узел дерева
/// Если указатель пустой, 
template <typename T>
T Data_Tree(const Tree_Node<T>* tree)
{
	if (tree != nullptr) // если указатель не пустой
	{
		return tree->date; // считываем данные узла
	}
	throw underflow_error("Пустой указатель"); // бросаем исключение
}

/// Шаблонная функция удаления дерева
/// Tree_Node<T>* tree - указатель на узел дерева
template <typename T>
void Del_Tree(Tree_Node<T>* tree)
{
	if (tree != nullptr) // если указатель не пустой
	{
		Del_Tree(tree->right); // рекурсивно вызываем функцию удаления в правую сторону
		Del_Tree(tree->left); // рекурсивно вызываем функцию удаления в левую сторону
		delete tree; // удаление указателя
	}

}

/// Шаблонная функция обхода дерева NLR
/// Tree_Node<T>* tree - указатель на узел дерева, vector<T>& arr - массив типа вектор
template <typename T>
void NLR(Tree_Node<T>* tree, vector<T>& arr)
{
	if (tree != nullptr) // если указатель не пустой
	{
		cout << tree->date << " "; // вывод данных узла
		arr.push_back(tree->date); // записываем данные узла в массив
		NLR(tree->left, arr); // рекурсивно вызываем функцию обхода в левую сторону
		NLR(tree->right, arr); // рекурсивно вызываем функцию обхода в правую сторону
	}
}

/// Шаблонная функция обхода дерева NRL
/// Tree_Node<T>* tree - указатель на узел дерева, vector<T>& arr - массив типа вектор
template <typename T>
void NRL(Tree_Node<T>* tree, vector<T>& arr)
{
	if (tree != nullptr) // если указатель не пустой
	{
		cout << tree->date << " "; // вывод данных узла
		arr.push_back(tree->date); // записываем данные узла в массив
		NRL(tree->right, arr); // рекурсивно вызываем функцию обхода в правую сторону
		NRL(tree->left, arr); // рекурсивно вызываем функцию обхода в левую сторону
	}
}

/// Шаблонная функция обхода дерева LNR
/// Tree_Node<T>* tree - указатель на узел дерева, vector<T>& arr - массив типа вектор
template <typename T>
void LNR(Tree_Node<T>* tree, vector<T>& arr)
{
	if (tree != nullptr) // если указатель не пустой
	{
		LNR(tree->left, arr); // рекурсивно вызываем функцию обхода в левую сторону
		cout << tree->date << " "; // вывод данных узла
		arr.push_back(tree->date); // записываем данные узла в массив
		LNR(tree->right, arr); // рекурсивно вызываем функцию обхода в правую сторону
	}
}

/// Шаблонная функция обхода дерева RNL
/// Tree_Node<T>* tree - указатель на узел дерева, vector<T>& arr - массив типа вектор
template <typename T>
void RNL(Tree_Node<T>* tree, vector<T>& arr)
{
	if (tree != nullptr) // если указатель не пустой
	{
		RNL(tree->right, arr); // рекурсивно вызываем функцию обхода в правую сторону
		cout << tree->date << " "; // вывод данных узла
		arr.push_back(tree->date); // записываем данные узла в массив
		RNL(tree->left, arr); // рекурсивно вызываем функцию обхода в левую сторону
	}
}

/// Шаблонная функция обхода дерева LRN
/// Tree_Node<T>* tree - указатель на узел дерева, vector<T>& arr - массив типа вектор
template <typename T>
void LRN(Tree_Node<T>* tree, vector<T>& arr)
{
	if (tree != nullptr) // если указатель не пустой
	{
		LRN(tree->left, arr); // рекурсивно вызываем функцию обхода в левую сторону
		LRN(tree->right, arr); // рекурсивно вызываем функцию обхода в правую сторону
		cout << tree->date << " "; // вывод данных узла
		arr.push_back(tree->date); // записываем данные узла в массив
	}
}

/// Шаблонная функция обхода дерева RLN
/// Tree_Node<T>* tree - указатель на узел дерева, vector<T>& arr - массив типа вектор
template <typename T>
void RLN(Tree_Node<T>* tree, vector<T>& arr)
{
	if (tree != nullptr) // если указатель не пустой
	{
		RLN(tree->right, arr); // рекурсивно вызываем функцию обхода в правую сторону
		RLN(tree->left, arr); // рекурсивно вызываем функцию обхода в левую сторону
		cout << tree->date << " "; // вывод данных узла
		arr.push_back(tree->date); // записываем данные узла в массив
	}
}

/// Шаблонная функция обхода дерева NLR с помощью стека
/// Tree_Node<T>* tree - указатель на узел дерева, vector<T>& arr - массив типа вектор
template <typename T>
void Stack_NLR(Tree_Node<T>* tree, vector<T>& arr)
{
	if (tree != nullptr) // если указатель не пустой
	{
		Tree_Node<T>* time_tree; // создаём временный указатель
		stack<Tree_Node<T>*> s; // создаём переменную стека
		s.push(tree); // записываем корень в стек
		while (!s.empty()) // пока стек не пустой
		{
			time_tree = s.top(); // записываем элемент, находящийся в стеке, во временную переменную
			s.pop(); // вытаскиваем элемент из стека
			cout << time_tree->date << " "; // вывод данных узла
			arr.push_back(time_tree->date); // записываем данные узла в массив
			if (time_tree->right != nullptr) // если правый элемент не пустой
			{
				s.push(time_tree->right); // записываем правый элемент в стек
			}
			if (time_tree->left != nullptr) // если левый элемент не пустой
			{
				s.push(time_tree->left); // записываем левый элемент в стек
			}
		}
	}
}

/// Шаблонная функция подсчёта количества узлов в дереве
/// Tree_Node<T>* tree - указатель на узел дерева
template <typename T>
int count(Tree_Node<T>* tree)
{
	if (tree != nullptr) // если указатель не пустой
	{
		return 1 + count(tree->left) + count(tree->right); // рекурсивно вызываем функцию и считаем узлы
	}
	return 0;
}

/// Шаблонная функция определения глубины дерева
/// -1 - глубина пустого дерева
/// Tree_Node<T>* tree - указатель на узел дерева
template <typename T>
int depth(Tree_Node<T>* tree)
{
	if (tree != nullptr) // если указатель не пустой
	{
		int left = depth(tree->left); // рекурсивно вызываем функцию и определяем глубину левого поддерева
		int right = depth(tree->right); // рекурсивно вызываем функцию и определяем глубину правого поддерева
		return max(left, right) + 1; // считаем глубину по формуле
	}
	return -1; // глубина пустого дерева
}

void test();
