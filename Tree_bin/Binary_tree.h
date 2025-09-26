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
/// Сложность: O(1)
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
/// Сложность: O(1)
/// const Tree_Node<T>* tree - константный указатель на узел дерева
/// Если указатель пустой, бросаем исключение
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
/// Сложность: O(n)
/// Tree_Node<T>* tree - указатель на узел дерева
template <typename T>
void Del_Tree(Tree_Node<T>* tree)
{
	if (tree != nullptr) // если указатель не пустой
	{
		Del_Tree(tree->left); // рекурсивно вызываем функцию удаления в левую сторону
		Del_Tree(tree->right); // рекурсивно вызываем функцию удаления в правую сторону
		delete tree; // удаление указателя
	}

}

/// Шаблонная функция обхода дерева NLR(прямой, N - обработка текущего узла, L - переход к левому потомку, R - переход к правому потомку)
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

/// Шаблонная функция обхода дерева NRL(прямой, N - обработка текущего узла, R - переход к правому потомку, L - переход к левому потомку)
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

/// Шаблонная функция обхода дерева LNR(симметричный, L - переход к левому потомку, N - обработка текущего узла, R - переход к правому потомку)
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

/// Шаблонная функция обхода дерева RNL(симметричный, R - переход к правому потомку, N - обработка текущего узла, L - переход к левому потомку)
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

/// Шаблонная функция обхода дерева LRN(обратный, L - переход к левому потомку, R - переход к правому потомку, N - обработка текущего узла)
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

/// Шаблонная функция обхода дерева RLN(обратный, R - переход к правому потомку, L - переход к левому потомку, N - обработка текущего узла)
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

/// Шаблонная функция обхода дерева NLR(прямой) с помощью стека
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
/// Сложность: O(n)
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
/// Сложность: O(n)
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

/// Шаблонная функция вставки нового узла в бинарное дерево
/// Сложность: O(n)
/// T data - данные узла, Tree_Node<T>* curr - указатель на узел дерева
template <typename T>
Tree_Node<T>* Add_Bin_Tree(T data, Tree_Node<T>* curr)
{
	if (curr == nullptr) // если текущий узел пустой
	{
		return new Tree_Node<T>(data); // создаём новый узел
	}
	if (data < curr->date) // если данные меньше текущего узла
	{
		curr->left = Add_Bin_Tree<T>(data, curr->left); // рекурсивно вызываем функцию и добавляем узел в левое поддерево
	}
	if (data > curr->date) // если данные больше текущего узла
	{
		curr->right = Add_Bin_Tree<T>(data, curr->right); // рекурсивно вызываем функцию и добавляем узел в правое поддерево
	}
	return curr; // возврат указателя на текущий узел
}

/// Шаблонная функция поиска узла с заданным значением
/// Сложность: O(log n) - у совершенного, O(n) - вырожденное
/// T data - данные узла, Tree_Node<T>* curr - указатель на узел дерева
template <typename T>
T find(T data, Tree_Node<T>* curr)
{
	if (curr == nullptr) // если узел пустой
	{
		throw out_of_range("Элемент не найден"); // бросаем исключение
	}
	if (data == curr->date) // если данные найдены
	{
		return curr->date; // возвращаем данные узла
	}
	if (data < curr->date) // если данные меньше текущего узла
	{
		return find<T>(data, curr->left); // рекурсивно вызываем функцию и ищем в левом поддереве
	}
	if (data > curr->date) // если данные больше текущего узла
	{
		return find<T>(data, curr->right); // рекурсивно вызываем функцию и ищем узел в правом поддереве
	}
}

/// Шаблонная функция поиска узла с минимальным значением данных
/// Сложность: O(log n) - у сбалансированнного, O(n) - вырожденное
/// Tree_Node<T>* curr - указатель на узел дерева
template <typename T>
Tree_Node<T>* Find_min(Tree_Node<T>* curr)
{
	Tree_Node<T>* temp = curr; // временный указатель на текущий узел
	while (temp && temp->left != nullptr) // пока существует левый дочерний узел
	{
		temp = temp->left; // переход к левому узлу
	}
	return temp; // возврат указателя на узел с минимальным значением
}

/// Шаблонная функция поиска узла с максимальным значением данных
/// Сложность: O(log n) - у сбалансированнного, O(n) - вырожденное
/// Tree_Node<T>* curr - указатель на узел дерева
template <typename T>
Tree_Node<T>* Find_max(Tree_Node<T>* curr)
{
	Tree_Node<T>* temp = curr; // временный указатель на текущий узел
	while (temp && temp->right != nullptr) // пока существует правый дочерний узел
	{
		temp = temp->right; // переход к правому узлу
	}
	return temp; // возврат указателя на узел с максимальным значением
}
///////////////////////////
/// Шаблонная функция удаления узла дерева
/// Сложность: O(n)
/// T data - данные узла, Tree_Node<T>* curr - указатель на узел дерева
template <typename T>
Tree_Node<T>* remove(Tree_Node<T>* curr, T data)
{
	if (curr == nullptr) // если узел пустой
	{
		return curr; // возвращаем пустой указатель
	}
	if (data < curr->date) // если данные меньше текущего узла
	{
		curr->left = remove<T>(curr->left, data); // рекурсивно вызываем функцию и удаляем в левом поддереве
	}
	else if (data > curr->date) // если данные больше текущего узла
	{
		curr->right = remove<T>(curr->right, data); // рекурсивно вызываем функцию и удаляем в правом поддереве
	}
	else // если найден узел для удаления
	{
		Tree_Node<T>* temp; // временный указатель для хранения узла
		if (curr->left == nullptr) // если нет левого поддерева
		{
			temp = curr->right; // сохраняем во временную переменную правое поддерево
			delete(curr); // удаление текущего узла
			return temp; // возвращаем правое поддерево
		}
		else if (curr->right == nullptr) // если нет правого поддерева
		{
			temp = curr->left; // сохраняем во временную переменную левое поддерево
			delete(curr); // удаление текущего узла
			return temp; // возвращаем левое поддерево
		}
		// Если есть оба поддерева
		temp = Find_min<T>(curr->right); // поиск минимального узла в правом поддереве
		curr->date = temp->date; // замена данных текущего узла
		curr->right = remove<T>(curr->right, temp->date); // удаление минимального узла из правого поддерева
	}
	return curr; // возврат указателя на текущий узел
}

/// Шаблонная функция копирования дерева из дерева
/// Tree_Node<T>* curr - указатель на узел дерева
template <typename T>
Tree_Node<T>* copy_tree(Tree_Node<T>* curr)
{
	if (curr) // если корень есть
	{
		Tree_Node<T>* temp = new Tree_Node<T>(); // создание нового корня
		temp->data = curr->data; // копируем данные для корня
		temp->left = copy_tree(curr->left); // рекурсивно вызываем функцию и копируем левое поддерево
		temp->right = copy_tree(curr->right); // рекурсивно вызываем функцию и копируем правое поддерево
		return temp; // возвращаем указатель на новое дерево
	}
	return nullptr;
}

void test();
