#pragma once
#define VECTOR3F_H
class Vertex3D
{
	float x, y, z;
public:


	Vertex3D() {
		x = 0;
		y = 0;
		z = 0;
	}
	Vertex3D(float a, float b, float c) {
		x = a;
		y = b;
		z = c;
	}


	Vertex3D(const Vertex3D& obj) {

		x = obj.x;
		y = obj.y;
		z = obj.z;
	}
	void SetVertex(float x0, float y0, float z0) {

		x = x0; y = y0; z = 0;
	}

	void Setx(float x0) { x = x0; }
	void Sety(float y0) { y = y0; }
	void Setz(float z0) { z = z0; }

	float Getx() { return x; }
	float Gety() { return y; }
	float Getz() { return z; }

	void operator=(const Vertex3D& obj)
	{
		(*this).x = obj.x;
		(*this).y = obj.y;
		(*this).y = obj.z;

	}




};
