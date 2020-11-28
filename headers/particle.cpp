#include"particle.h"
#include<iostream>
#include<assert.h>
using namespace std;
using namespace wizphys;

void Particle::integrate(real interval)
{
	assert(interval > 0.0);
	position.scaledAdd(velocity, interval);
	Vector3D resultingAcc = acceleration;
	resultingAcc.scaledAdd(forceAccum, massinverse);
	velocity.scaledAdd(resultingAcc, interval);
	float dampval = real_pow(damping, interval);
	// cout << "dampval is " << dampval << endl;
	velocity *= dampval;
}

bool Particle::hasFiniteMass()
{
	if(massinverse != 0.0)
		return true;
	return false;
}

real Particle::getMass() {
	return (1/massinverse);
}
void Particle::addForce(Vector3D newForce) {
	forceAccum += newForce;
}

Vector3D Particle::getVelocity() {
	return velocity;
}

// int main(){
// 	Vector3D v1 = Vector3D(1.0,2.0,0.0);
// 	cout << v1.x << "\n";
// 	Vector3D v2 = v1 + v1;
// 	cout << v2.x << "\n";
// 	Particle p;
// 	// p.position = {1,2,3};
// 	p.velocity = {1,2,3};
// 	p.acceleration = {1,2,3};
// 	p.damping = -1;
// 	p.integrate(2);
// 	cout << p.position.x << " " << p.position.y << " " << p.position.z << "\n";
// 	// cout << p.velocity.x << " " << p.velocity.y << " " << p.velocity.z;
// 	return 0;
// }