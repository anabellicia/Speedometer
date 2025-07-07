#pragma once
#include "Speedometr.h"

class SpeedometrArray
{
private:
	Speedometr** Array = 0;
	unsigned int k = 0;
public:	
	SpeedometrArray(int k = 0);
	~SpeedometrArray();
	SpeedometrArray* Push(Speedometr* w1);
	SpeedometrArray* Remove(int n);
	SpeedometrArray* Length(unsigned int Len);
	unsigned int Length();
	Speedometr* operator[](unsigned int i);
	SpeedometrArray* SpeedometrArray::Push(int n, Speedometr* w1);
	friend bool operator==(SpeedometrArray& a1,SpeedometrArray& a2);
	SpeedometrArray& operator =(SpeedometrArray& a1);
	SpeedometrArray* Clear();
	SpeedometrArray* Copy(SpeedometrArray& a1,unsigned start, unsigned end, unsigned paste );
};



