#include "../Mate/Vector3p.h"
#include <iostream>

using namespace std;
class Rigid
{
public:
	Rigid();

	void Init(float _frecare, float _gravitatie, Vector3p * _pos, float * _rotatie ,Vector3p * _scalare, Vector3p * _dim);

	void Refresh();
	void Render(Vector3p c); //desi avem render pt sprite, dar daca avem probleme cu acel corp rigid putem folosi render-ul pentru a vedea unde sunt probleme la randat

	void Forta(Vector3p f);


private:
	Vector3p * pos;
	float * rotatie;
	Vector3p * scalare;
	Vector3p * size;


	float gravitatie;
	float frecare;
	Vector3p acceleratie;
};