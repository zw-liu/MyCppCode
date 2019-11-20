#include<iostream>
using namespace std;
template<typename T>
class LinkList
{
	struct Node
	{
		T data;
		Node *next;
	};
	Node *head;
public:LinkList();//构造函数，创建空链表；
	   //~LinkList();//析构函数，删除表空间
	   void CreateList(int n);//创建具有n个元素的线性链表
	   void Insert(int i, T e);//在表中第i个位置插入元素
	   T Delete(int i);//删除表中第i个元素
	   T GetElem(int i);//获取表中第i个元素
	   int locate(T e);//返回在链表中查找值为 T e的元素的位置
	   T prior(T e);//返回元素e的前驱
	   int Length();//求表长
	   void Traverse(void(*fp)(T &e));//遍历链表并且对链表的每一个元素进行fp（T e）操作
};
/******************构造函数************************/
template<typename T>
LinkList<T>::LinkList()
{
	head = new Node();
	head->next = NULL;
}
/******************析构函数************************/
/*template<typename T>
LinkList<T>::~LinkList()
{

}*/
/******************创建多个链表(从后插入)*********************/
template<typename T>
void LinkList<T>::CreateList(int n)
{
	Node *p = head;
	for (int i = 0; i < n; i++)
	{
		Node *q = new Node();
		cin >>q->data  ;
		
		q->next = p->next;
		p->next = q;
		p = p->next;
	}
}/******************插入函数************************/
/******************在指定位置插入一个节点************************/
template<typename T>
void LinkList<T>::Insert(int i, T e)
{
	Node *p = head;
	int j = 0;
	while (p&&j < i- 1)
	{
		p = p->next;
		j++;
	}
	Node *q = new Node();
	q->data = e;
	q->next = p->next;
	p->next = q;
}
/******************删除表中第i个元素************************/
template<typename T>
T LinkList<T>::Delete(int i)
{
	Node *p = head;
	int j = 0;
	while (p&&j < i - 1)
	{
		p = p->next;
		j++;
	}
	Node *q = new Node();
	q = p->next;
	T e = q->data;
	p->next = q->next;
	delete q;
	return e;
}
/******************获取表中第i个元素************************/
template<typename T>
T LinkList<T>::GetElem(int i)
{
	Node *p = head;
	int j = 0;
	while (p&&j < i)
	{
		p = p->next;
		j++;
	}
	return p->data;
}
/******************返回链表中第一个元素值为 T e的节点位置************************/
template<typename T>
int LinkList<T>::locate(T e)
{
	Node *p = head;
	int j = 0;
	while (p)
	{
		p = p->next;
		j++;
		if (p->data == e)
		{
			return j;
		}

	}
	return 0;
}
/******************返回元素T e 的前驱************************/
template<typename T>
T LinkList < T>::prior(T e)
{
	Node *p = head;
	int j = 0;
	while (p)
	{
		p = p->next;
		j++;
		if (p->next->data == e)
		{
			return p->data;
		}
	}
	exit(0);
	Node *q = new Node();
	return q->data;
}
/******************求表长************************/
template<typename T>
int LinkList<T>::Length()
{
	Node *p = head;
	int j = 0;
	while (p)
	{
		p = p->next;
		j++;
	}
	return j - 1;
}
template<typename T>
void LinkList<T>::Traverse(void(*fp)(T &e))
{
	Node *p = head->next;
	while (p)
	{
		fp(p->data);
		p = p->next;
		
	}
	cout << endl;
}
void print(char &B)
{
	cout << B;
}

int main()
{
	LinkList<char> list;
	list.CreateList(3); list.Traverse(print);
	list.Insert(2, 'B'); list.Traverse(print);
	cout<<list.prior('B')<<endl;
	list.Delete(1); list.Traverse(print);
	cout << list.GetElem(1) << endl;
	cout << list.Length();
	system("pause");
	return 0;
}
