#include "Speedometr.h"

Speedometr::Speedometr()
{
	width = 100;
	height = 20;
	min = 0;
	max = 100;
	cur = 0;
	x = 0;
	y = 0;
}
Speedometr::Speedometr(float w, float h, float m, float M, float c, float x1, float y1) 
{
	width = w;
	height = h;
	min = m;
	max = M;
	cur = c;
	x = x1;
	y = y1;
}


std::string Speedometr::getUnit() 
{ 
	return UNITS[unit]; 
}

unsigned int Speedometr::getUnitNum() 
{ 
	return unit; 
}

float Speedometr::getX() 
{ 
	return x; 

}
float Speedometr::getY() 
{ 
	return y; 
}

float Speedometr::getMin() 
{ 
	return min; 
}

float Speedometr::getMax() 
{ 
	return max; 
}

float Speedometr::getCur() 
{ 
	return cur; 
}

float Speedometr::getCur(unsigned int unit) 
{
	if (unit == this->unit)
		return cur;
	else if (unit == 0)
		return cur * 3.6f;
	else
		return cur / 3.6f;
}
float Speedometr::getWidth() 
{ 
	return width; 
}

float Speedometr::getHeight() 
{ 
	return height; 
}

Color Speedometr::getColor() 
{
	return Color::FromArgb(a, r, g, b);
}

void Speedometr::setX(float i) 
{ 
	x = i;
}

void Speedometr::setY(float i) 
{ 
	y = i;
}

void Speedometr::setMin(float i) 
{ 
	min = i;
}

void Speedometr::setMax(float i) 
{ 
	max = i;
}
void Speedometr::setCur(float i) 
{ 
	cur = i;
}

void Speedometr::setWidth(float i) 
{
	if (i <= 0)
		throw "Некорректный размер";
	width = i;
	

}

void Speedometr::setHeight(float i) {
	if (i <= 0)
		throw "Некорректный размер";
	height = i;
	
}

bool Speedometr::operator>(Speedometr& sp) 
{ 
	return cur > sp.getCur(unit); 
}
bool Speedometr::operator<(Speedometr& sp) 
{ 
	return cur < sp.getCur(unit); 
}
bool Speedometr::operator==(Speedometr& sp) 
{ 
	return cur == sp.getCur(unit); 
}

void Speedometr::operator=(float cur) {
	this->cur = cur;
}

void Speedometr::setMode(unsigned char mode) {
	this->mode = mode;
	
}

unsigned char Speedometr::getMode()
{
	return mode;
}


void Speedometr::setUnit(unsigned int unit) {
	cur = getCur(unit);
	this->unit = unit;
	
}

void Speedometr::setColor(Color c) {
	a = c.A;
	r = c.R;
	g = c.G;
	b = c.B;
	
}

bool Speedometr::isOverScale()
{
	if (cur > max || cur < min)
		return false;
}

void SpeedometrA::Draw(PaintEventArgs^ e)
{
	// 
}

void SpeedometrB::Draw(PaintEventArgs^ e)
{
	// 
}

void SpeedometrC::Draw(PaintEventArgs^ e)
{
	// 
}