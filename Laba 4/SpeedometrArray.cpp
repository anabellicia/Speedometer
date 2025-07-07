#include "SpeedometrArray.h"
#include <math.h>
#include "Speedometr.h"

SpeedometrArray::SpeedometrArray(int k)
{
	Length(k);
}
SpeedometrArray :: ~SpeedometrArray()
{
	if (Array != 0)
		delete[] Array;
}

SpeedometrArray* SpeedometrArray :: Remove(int n)
{
	Speedometr** Array2 = new Speedometr*[k - 1];
	int j = 0;
	for (int i = 0; i < k; i++)
	{
		if (i != n)
		{
			Array2[j++] = Array[i];
		}
	}
	if (Array != 0)
		delete[]Array;
	Array = Array2;
	k--;
	return this;
}
SpeedometrArray* SpeedometrArray :: Length(unsigned int Len)
{
	Speedometr** Array3 = new Speedometr*[Len];
	for (int i = 0; i < k && i < Len; i++)
		Array3[i] = Array[i];
	if (Array != 0)
		delete[]Array;
	Array = Array3;
	k = Len;
	return this;
}
unsigned SpeedometrArray::Length()
{
	return k;
}
Speedometr* SpeedometrArray :: operator[](unsigned int i)
{
	if (i < k)
		return Array[i];
	throw "ошибка";
}
SpeedometrArray* SpeedometrArray::Push(int n, Speedometr* w1)
{
	Speedometr** Array4 = new Speedometr*[k + 1];
	unsigned int j = 0;
	for (unsigned int i = 0; i < k; i++)
	{
		if (i != n)
			Array4[i] = Array[j++];
		else
			Array4[i] = w1;
	}
	if (Array != 0)
		delete[]Array;
	Array = Array4;
	k++;
	return this;
}
SpeedometrArray* SpeedometrArray::Push(Speedometr* w1)
{
	return Push(k , w1);
}
SpeedometrArray& SpeedometrArray::operator=(SpeedometrArray& a1)
{
	Speedometr** Array1 = new Speedometr*[a1.k];
	for (int i = 0; i < a1.k; i++)
		Array1[i] = a1.Array[i];
	if (Array != 0)
		delete[]Array;
	Array = Array1;
	return *this;
}
bool operator==(SpeedometrArray& a1, SpeedometrArray& a2)
{
	if (a1.k != a2.k)
		return false;
	for (int i = 0; i < a1.k; i++)
		if (!(a1.Array[i] == a2.Array[i]))
			return false;
	return true;
}
SpeedometrArray* SpeedometrArray::Clear()
{
	for (int i = 0; i < k; i++)
		Array[i] = new Speedometr;
	return this;
}
SpeedometrArray* SpeedometrArray::Copy(SpeedometrArray& a1, unsigned start, unsigned end, unsigned paste)
{
	if (start >= end || end >= a1.k)
		throw "Индексы заданы некорретно";

	unsigned l = k, lp = end - start;
	if (paste > k) l = paste;
	l += lp;
	Speedometr** Array4 = new Speedometr*[l];
	unsigned j = 0, m = 0;
	for (int i = 0; i < l; i++)
	{
		if (i < paste || i >= paste + lp)
			Array4[i] = Array[j++];
		else if (i >= paste && i < paste + lp)
			Array4[i] = a1.Array[m++];
	}
	if (Array != 0)
		delete[]Array;
	Array = Array4;
	k = l;
	return this;
}