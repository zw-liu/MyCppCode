
#include<iostream>
using namespace std;
template<class T>
class SqList
{
private:
	T*data;//用data作为数组的指针
	int capacity, n;//capacity：容积    n:占用了的大小

public:
	SqList(int cap = 100){ data = new T[cap]; capacity = cap; n = 0; }//创造一个空的线性表
	bool insert(int i, T e);
	bool remove(int i);
	bool push_back(T e);
	bool insert_front(T e);
	bool get(int i, T &e);
	int size(){ return n; }
private:
	bool realloc();//当内存不够时，用realloc()重新分配内存空间
};

/*******************【增加新元素】*************************/
template <class T>
bool SqList<T>::push_back(T e)
{
	data[n] = e;
	n++;
	return true;
}

/*******************【扩大容量】*************************/

template <class T>
bool SqList<T>::realloc(){
	T*p = new T[2 * capacity];
	if (!p) return false;
	for (int i = 0; i < capacity; i++)
	{
		p[i] = data[i];

	}
	delete data;
	p = data;
	capacity *= 2;
	return true;
}
/*******************【选择位置插入】*************************/
template<class T>
bool SqList<T>::insert(int i, T e)//此处的i，为放在第i个位置，而不是序号为i ！！！
{
	if (i<1 || i>n) return false;//判断插入的位置是否合理！
	if (capacity == n)//插入的位置合理后，判断容量是否足够
	{
		realloc();
	}
	for (int t = n; t >= i; t--)//从后往前交换，否则会丢失数据！！
	{
		data[n] = data[n - 1];
	}
	data[i - 1] = e;//交换完，把e放在第i个位置
	n++;//最后别忘记将个数+1！
}
/*******************【】*************************/
int main()
{

	system("pause");
	return 0;
}
