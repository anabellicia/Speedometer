#pragma once
#include <string>

using namespace System::Windows::Forms;
using namespace System::Drawing;


class Speedometr {
protected:
	float width, height, x, y, min, max, cur;
	unsigned int unit;
	unsigned char mode;
	int r, g, b, a;
public:
	const unsigned int UNITS_COUNT = 2;
	const std::string UNITS[2] = { "κμ/χ", "μ/c" };

	Speedometr();
	Speedometr(float w , float h , float m , float M , float c , float x1 , float y1 );
	virtual void Draw(PaintEventArgs^ e) {}
	bool isOverScale();
	void setUnit(unsigned int unit);
	std::string getUnit();
	unsigned int getUnitNum();
	float getX();
	float getY();
	float getMin();
	float getMax();
	float getCur();
	float getCur(unsigned int unit);
	float getWidth();
	float getHeight();
	Color getColor();
	void setX(float i);
	void setY(float i);
	void setMin(float i);
	void setMax(float i);
	void setCur(float i);
	void setWidth(float i);
	void setHeight(float i);
	void setColor(Color c);
	bool operator>(Speedometr& sp);
	bool operator<(Speedometr& sp);
	bool operator==(Speedometr& sp);
	void operator=(float cur);
	void setMode(unsigned char mode);
	unsigned char getMode();
};

class SpeedometrA : public Speedometr
{
public:
	SpeedometrA() {};
	SpeedometrA(float w, float h, float m, float M, float c, float x1, float y1) : Speedometr(w, h, m, M, c, x1, y1) {};
	void Draw(PaintEventArgs^ e);
};

class SpeedometrB : public Speedometr
{
public:
	SpeedometrB() {};
	SpeedometrB(float w, float h, float m, float M, float c, float x1, float y1) : Speedometr(w, h, m, M, c, x1, y1) {};
	void Draw(PaintEventArgs^ e);
};

class SpeedometrC : public Speedometr
{
public:
	SpeedometrC() {};
	SpeedometrC(float w, float h, float m, float M, float c, float x1, float y1) : Speedometr(w, h, m, M, c, x1, y1) {};
	void Draw(PaintEventArgs^ e);
};