#ifndef SORT_H
#define SORT_H

#include "Root.h"
#include "Array.h"

namespace EasyDSL
{

class Sort : public RootClass
{
private:
	Sort(){}
	Sort(const Sort& obj){}
	Sort& operator = (const Sort& obj){}
	~Sort(){}

	template <typename T>
	static void Swap(T& var1, T& var2);
	
	template <typename T>
	static void MergeProcess(T* array, int begin, int end);

	template <typename T>
	static void QuickProcess(T* array, int begin, int end);

public:
	template <typename T>
	static void Select(T* array, int len);

	template <typename T> 
	static void Select(Array<T>& obj, int len);

	template <typename T>
	static void Insert(T* array, int len);

	template <typename T> 
	static void Insert(Array<T>& obj, int len);

	template <typename T>
	static void Bubble(T* array, int len);

	template <typename T> 
	static void Bubble(Array<T>& obj, int len);

	template <typename T>
	static void Shell(T* array, int len);

	template <typename T> 
	static void Shell(Array<T>& obj, int len);

	template <typename T>
	static void Merge(T* array, int len);

	template <typename T> 
	static void Merge(Array<T>& obj, int len);

	template <typename T>
	static void Quick(T* array, int len);
	
	template <typename T> 
	static void Quick(Array<T>& obj, int len);

};

template <typename T>
void Sort::Swap(T& var1, T& var2)
{
	T tmp = var1;
	var1 = var2;
	var2 = tmp;
}

/**********************
* SelectSort 
**********************/

template <typename T>
void Sort::Select(T* array, int len)
{
	if (len < 2)
	{
		return;
	}


	for (int i = 0; i < len; i++)
	{
		int min_index = i;
		for (int j = i + 1; j < len; j++)
		{
			min_index = array[j] < array[min_index] ? j : min_index;
		}
		
		if (min_index != i)
		{
			Swap(array[i], array[min_index]);
		}
	}
}

template <typename T> 
void Sort::Select(Array<T>& obj, int len)
{
	Select(obj.addr(), len);
}

/**********************
* InsertSort 
**********************/

template <typename T>
void Sort::Insert(T* array, int len)
{
	if (len < 2)
	{
		return;
	}

	for (int i = 1; i < len; i++)
	{
		int index = i;
		T val = array[i];
		while (index > 0 && val < array[index - 1])
		{
			array[index] = array[index - 1];
			index--;
		}
		if (index != i)
		{
			array[index] = val;
		}
	}
}

template <typename T> 
void Sort::Insert(Array<T>& obj, int len)
{
	Insert(obj.addr(), len);
}

/**********************
* BubbleSort 
**********************/

template <typename T>
void Sort::Bubble(T* array, int len)
{
	if (len < 2)
	{
		return;
	}

	bool changed = true;
	for (int i = 0; i < len && true == changed; i++)
	{
		changed = false;
		for (int j = 0; j < len - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				Swap(array[j], array[j + 1]);
				changed = true;
			}
		}
	}
}

template <typename T> 
void Sort::Bubble(Array<T>& obj, int len)
{
	Bubble(obj.addr(), len);
}

/**********************
* ShellSort 
**********************/

template <typename T>
void Sort::Shell(T* array, int len)
{
	if (len < 2)
	{
		return;
	}

	int gap = len;
	do
	{	
		gap = gap / 3 + 1;
		for (int i = gap; i < len; i += gap)
		{
			int index = i;
			T val = array[index];
			while (index >= gap && val < array[index - gap])
			{
				array[index] = array[index - gap];
				index -= gap;
			}
			if (index != i)
			{
				array[index] = val;
			}
		}
	} while (gap > 1);
}

template <typename T> 
void Sort::Shell(Array<T>& obj, int len)
{
	Shell(obj.addr(), len);
}

/**********************
* MergeSort 
**********************/

template <typename T>
void Sort::MergeProcess(T* array, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	
	int middle = (begin + end) / 2;
	MergeProcess(array, begin, middle);
	MergeProcess(array, middle + 1, end);

	T buf[end - begin + 1];
	int x = begin, y = middle + 1;
	for (int i = 0; i < end - begin + 1; i++)
	{
		if (x <= middle && y <= end)
		{
			if (array[x] > array[y])
			{
				buf[i] = array[y];
				y++;
			}
			else
			{
				buf[i] = array[x];
				x++;				
			}
		}
		else if (x > middle && y <= end)
		{
			buf[i] = array[y];
			y++;			
		}
		else
		{
			buf[i] = array[x];
			x++;
		}
	}

	for (int i = 0; i < end - begin + 1; i++)
	{
		array[begin + i] = buf[i];
	}
}

template <typename T>
void Sort::Merge(T* array, int len)	
{
	MergeProcess(array, 0, len - 1);
}

template <typename T> 
void Sort::Merge(Array<T>& obj, int len)
{
	Merge(obj.addr(), len);
}

/**********************
* QuickSort 
**********************/

template <typename T>
void Sort::QuickProcess(T* array, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	
	int index = begin;
	for (int i = index; i < end; i++)
	{
		if (array[i] < array[end])
		{
			if (i != index)
			{
				Swap(array[i], array[index]);
			}
			index++;
		}
	}

	Swap(array[end], array[index]);
	
	QuickProcess(array, begin, index - 1);
	QuickProcess(array, index, end);
}

template <typename T>
void Sort::Quick(T* array, int len)	
{
	MergeProcess(array, 0, len - 1);
}

template <typename T> 
void Sort::Quick(Array<T>& obj, int len)
{
	Quick(obj.addr(), len);
}


}   // end namespace EasyDSL

#endif

