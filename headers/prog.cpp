#include"namedefs.h"
#include"vectormath.h"
#include<iostream>
using namespace std;
using namespace wizphys;

int main(){
	Vector3D v1 = Vector3D(1.0,2.0,0.0);
	cout << v1.x << "\n";
	Vector3D v2 = v1 + v1;
	cout << v2.x << "\n";

	return 0;
}