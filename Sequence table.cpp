
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
	bool set(int i, T e);
	bool get(int i, T &e);
	bool find(T e);
	int size();
	void showlist();
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
/*******************【指定位置插入】*************************/
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
		data[t] = data[t - 1];
	}
	data[i - 1] = e;//交换完，把e放在第i个位置
	n++;//最后别忘记将个数+1！
	return true;
}
/*******************【指定位置删除】*************************/
template<class T>
bool SqList<T>::remove(int i)
{
	if (i<1 || i>n)
		return false;
	T*p, *q;//p指的是需要删除的元素的指针，q指的是末尾元素的指针；
	p = data+i-1;
	q = data+n-1;
	for (; p<q; ++p)
	{
		*p = *(p + 1);
	}
	n--;
	*q = NULL;
	return true;
}
/*******************【变化指定位置元素】*************************/
template <class T>
bool SqList<T>::set(int i, T e)
{
	if (i<1 || i>n)return false;
	data[i - 1] = e;
	return true;
}
/*******************【得到指定位置的元素并赋值给引用变量e】*************************/
template <class T>
bool SqList<T>::get(int i,T &e)
{
	if (i<1 || i>n)return false;
	e = data[i - 1];
	return true;
}
/*******************【得到顺序表的长度】*************************/
template<class T>
int SqList<T>::size()
{
	return n;
}
/*******************【查看顺序表中是否存在指定的元素】*************************/
template<class T>
bool SqList<T>::find(T e)
{
	for (int t = 0; t <= n; t++)
	{
		if (data[t] == e)
			return true;
	}
	return false;
}
/*******************【输出顺序表中的所有元素】*************************/
template<class T>
void SqList<T>::showlist()
{
	for (int i = 0; i < n; i++)
	{
		cout << data[i];
	}
	cout << endl;
}




int main()
{
	SqList<char> list;
	list.push_back('i');
	list.push_back(' ');
	list.push_back('l');
	list.push_back('o');
	list.push_back('v');
	list.push_back('e');
	list.push_back(' ');
	list.push_back('y');
	list.push_back('o');
	list.push_back('u');
	list.push_back('/');
	list.showlist();
	list.insert(1, 'I');
	list.showlist();
	list.remove(1);
	list.showlist();
	list.set(1, 'I');
	list.showlist();


	system("pause");
	return 0;
}
