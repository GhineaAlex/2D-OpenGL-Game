#ifndef Proiect_Vector3p
#define Proiect_Vector3p

class Vector3p
{
public:
	float x, y, z; //vom realiza aceste variabile de tip public 
				  //astfel incat evitam crearea unor get-ere pe care ar trebui sa le apelama de fiecare data
	Vector3p();
	Vector3p(const Vector3p & alt); //ne vom folosi de acest constructor de copiere la supraincarcarea unor operatori
	Vector3p(float _x);
	Vector3p(float _x, float _y, float _z);

	Vector3p & operator = (const Vector3p & alt);
	Vector3p operator + (const Vector3p& alt);
	Vector3p operator - (const Vector3p& alt);
	Vector3p operator * (const Vector3p& alt);
	Vector3p operator * (float _x);

	bool operator == (const Vector3p & alt);
	bool operator != (const Vector3p & alt);

};

#endif