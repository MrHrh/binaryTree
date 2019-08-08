#include<iostream>
#include<queue>
#include<stack>
using namespace std;

typedef char elemType;
#define END '#'

typedef struct Node
{
	Node* leftChild;
	Node* rightChild;
	elemType data;
}Node;


//����ڵ�
Node* buyNode()
{
	Node* tmpNode = new Node();
	tmpNode->leftChild = NULL;
	tmpNode->rightChild = NULL;
	tmpNode->data = 0;
	return tmpNode;
}

//����ǰ������Ľ��������ʽ�ṹ������
Node* createBinaryTree(const elemType *& str)
{
	Node* p = NULL;
	if (str != NULL && *str != END)
	{
		p = buyNode();
		p->data = *str;
		p->leftChild = createBinaryTree(++str);
		p->rightChild = createBinaryTree(++str);
	}
	return p;
}

//ǰ��ݹ����������
void preOrder(Node *binaryTree)
{
	if (binaryTree != NULL)
	{
		cout << binaryTree->data<<" ";

		if (binaryTree->leftChild != NULL)
		{
			preOrder(binaryTree->leftChild);
		}
		if (binaryTree->rightChild != NULL)
		{
			preOrder(binaryTree->rightChild);
		}
	}
}

//ǰ��ǵݹ����������
void preNonrecursiveOrder(Node* binaryTree)
{
	if (binaryTree == NULL)return;
	stack<Node*> nodeStack;
	nodeStack.push(binaryTree);

	while (!nodeStack.empty())
	{
		Node* p = nodeStack.top();
		nodeStack.pop();
		cout << p->data << " ";

		if (p->rightChild != NULL)
			nodeStack.push(p->rightChild);

		if (p->leftChild != NULL)
			nodeStack.push(p->leftChild);
	}
}

//����ݹ����������
void inOrder(Node* binaryTree)
{
	if (binaryTree != NULL)
	{
		if (binaryTree->leftChild != NULL)
		{
			inOrder(binaryTree->leftChild);
		}

		cout << binaryTree->data<<" ";

		if (binaryTree->rightChild != NULL)
		{
			inOrder(binaryTree->rightChild);
		}
	}
}

//�ǵݹ��������������
void inNonrecursiveOrder(Node* binaryTree)
{
	stack<Node*> nodeStack;
	if (binaryTree == NULL) return;
	Node* p = binaryTree;
	while (p != NULL || !nodeStack.empty())
	{
		while (p != NULL)
		{
			nodeStack.push(p);
			p = p->leftChild;
		}
		p = nodeStack.top();
		nodeStack.pop();
		cout << p->data<<" ";
		p = p->rightChild;
	}
}

//����ݹ����������
void pastOrder(Node* binaryTree)
{
	if (binaryTree != NULL)
	{
		if (binaryTree->leftChild != NULL)
		{
			pastOrder(binaryTree->leftChild);
		}

		if (binaryTree->rightChild != NULL)
		{
			pastOrder(binaryTree->rightChild);
		}
		cout << binaryTree->data << " ";
	}
}

//����ǵݹ����������
void pastNonrecursiveOrder(Node* binaryTree)
{
	if (binaryTree == NULL)return;
	stack<Node*> nodeStack;
	Node* tag = NULL;
	Node* p = binaryTree;
	while (p != NULL || !nodeStack.empty())
	{
		while (p != NULL)
		{
			nodeStack.push(p);
			p = p->leftChild;
		}
		p = nodeStack.top();
		nodeStack.pop();
		if (p->rightChild == NULL || p->rightChild == tag)
		{
			cout << p->data << " ";
			tag = p;
			p = NULL;
		}
		else
		{
			nodeStack.push(p);
			p = p->rightChild;
		}
	}
}

//��α���������
void levelOrder(Node* binaryTree)
{
	if (binaryTree == NULL) return;
	queue<Node*> nodeQueue;
	nodeQueue.push(binaryTree);

	while (!nodeQueue.empty())
	{
		Node* p = nodeQueue.front();
		nodeQueue.pop();
		cout << p->data << " ";
		if (p->leftChild != NULL)
			nodeQueue.push(p->leftChild);
		if (p->rightChild != NULL)
			nodeQueue.push(p->rightChild);
	}
}

int main()
{
	const char *str = "ABDH##J##E##CF##G##";
	Node *myTree = createBinaryTree(str);

	cout << "preOrder: ";
	preOrder(myTree);
	cout << endl;

	cout << "preNonrecursiveOrder:";
	preNonrecursiveOrder(myTree);
	cout << endl;

	cout << "inOrder: ";
	inOrder(myTree);
	cout << endl;

	cout << "inNonrecursiveOrder:";
	inNonrecursiveOrder(myTree);
	cout << endl;

	cout << "pastOrder: ";
	pastOrder(myTree);
	cout << endl;

	cout << "pastNonrecursiveOrder:";
	pastNonrecursiveOrder(myTree);
	cout << endl;

	cout << "levelOrder: ";
	levelOrder(myTree);
	cout << endl;

	return 0;
}