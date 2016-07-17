// Given inorder and preorden build the binary tree
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <vector>
using namespace std;

struct tree{
	int data;
	tree* left;
	tree* right;
};

void print_pre(tree* head) {
	if (head == NULL) return;
	cout << head->data << " ";
	print_pre(head->left);
	print_pre(head->right);
}

void print_in(tree* head) {
	if (head == NULL) return;
	print_in(head->left);
	cout << head->data << " ";
	print_in(head->right);
}

vector<int> ino;
vector<int> pre;
tree* build(int ino_begin, int ino_end, int pre_idx) {
	cout << ino_begin << " - " << ino_end << " | " << pre_idx << endl;
	if (ino_end < 0 || 
		ino_end >= ino.size() || 
		ino_begin > ino_end ||
		pre_idx >= ino.size())
		return NULL;
	
	int parent = pre[pre_idx];
	tree* t = new tree;
	for (int i = ino_begin; i <= ino_end; ++i) {
		if (ino[i] == parent) {
			t->data  = parent;
			t->left  = build(ino_begin, i - 1, pre_idx + 1);
			t->right = build(i + 1, ino_end, pre_idx + i + 1 - ino_begin);
			break;
		}
	}
	return t;
}

int main() {
	int N;
	cin >> N;
	pre.assign(N, 0);
	ino.assign(N, 0);
	for (int i = 0; i < N; ++i)	cin >> pre[i];
	for (int i = 0; i < N; ++i)	cin >> ino[i];

	tree* R = build(0, ino.size() - 1, 0);

	cout << endl << endl;
	print_pre(R);
	cout << endl;
	print_in(R);
	return 0;
}
/*
Test cases
8
1 2 3 5 6 4 7 8
5 3 6 2 7 4 8 1

7
2 3 5 6 4 7 8
5 3 6 2 7 4 8

4
1 2 4 3
2 4 1 3

*/
