#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node *left, *right;

	Node(int n) : val(n), left(NULL), right(NULL) {}
};

vector<int> ans;
void insert(Node* head, int num) {
	if (num < head -> val) {
		if (head -> left == NULL) {
			ans.push_back(head -> val);
			Node *nuevo = new Node(num);
			head -> left = nuevo;
		} else
			insert(head -> left, num);
	} else {
		if (head -> right == NULL) {
			ans.push_back(head -> val);
			Node *nuevo = new Node(num);
			head -> right = nuevo;
		} else
			insert(head -> right, num);
	}
}

int main() {
	int n, num;

	cin >> n >> num;
	
	Node* head = new Node(num);
	for (int i = 1; i < n; ++i) {
		cin >> num;
		insert(head, num);
	}

	for (const auto& var: ans)
		cout << var << ' ';

	return 0;
}