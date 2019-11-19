#include<iostream>
using namespace std;

template<typename T>
class LinkList
{
  struct Node
  {
    T data;
    Node *next;
  }*head;
  private:
  LinkList();//构造函数，创建空链表；
  ~LinkList();//析构函数，删除表空间
  void CreateList(int n);//创建具有n个元素的线性链表
  void Insert(int i,T e);//在表中第i个位置插入元素
  T Delete(int i);//删除表中第i个元素
  T GetElem(int i);//获取表中第i个元素
  int locate(T e);//返回在链表中查找值为 T e的元素的位置
  T prior(T e);//返回元素e的前驱
  int Length();//求表长
  void Travese(void (*fp)(T &e));//遍历链表并且对链表的每一个元素进行fp（T e）操作
};
template<typename T>
LinkList<T>::LinkList()
{
  head=new Node();
  head->next=NULL;
}
template<typename T>
LinkList<T>::void CreateList(int t)
{
  Node *p=head;
  for(int i=0;i<n;i++)
  {
    p=p->next;
    cin>>p->data;
  }
  
}
int main()
{
  return 0;
}
