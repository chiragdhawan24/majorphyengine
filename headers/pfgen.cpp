#include "pfgen.h"
#include<iostream>
using namespace wizphys;
using namespace std;

void ParticleForceRegistry::updateForces(real duration)
{
    Registry::iterator i = registrations.begin();
    for (; i != registrations.end(); i++)
    {
        i->fg->updateForce(i->particle, duration);
    }
}
void GravityFG::updateForce(Particle* particle, real duration)
{
    // Check that we do not have infinite mass.
    if (!particle->hasFiniteMass()) 
        return;
    // Apply the mass-scaled force to the particle.
    particle->addForce(gravity * particle->getMass());
}

void DragFG::updateForce(Particle* particle, real duration)
{
    Vector3D force = particle->getVelocity();
    // Calculate the total drag coefficient.
    real dragCoeff = force.magnitude();
    dragCoeff = k1 * dragCoeff + k2 * dragCoeff * dragCoeff;
    // Calculate the final force and apply it.
    force.normalize();
    force *= -dragCoeff;
    particle->addForce(force);
}
int main()
{
    Particle p;
    p.velocity = {1,2,3};
    p.acceleration = {1,1,1};
    p.massinverse = 2;
    p.damping = -1;
    cout << p.forceAccum.x << " " << p.forceAccum.y << " " << p.forceAccum.z << endl;
    Vector3D f1(3,3,3);
    p.addForce(f1);
    f1.x += 10;
    cout << p.forceAccum.x << " " << p.forceAccum.y << " " << p.forceAccum.z << endl;
    p.addForce(f1);
    cout << p.forceAccum.x << " " << p.forceAccum.y << " " << p.forceAccum.z << endl;
    p.integrate(1);
    cout << p.position.x << " " << p.position.y << " " << p.position.z << endl;
    cout << p.velocity.x << " " << p.velocity.y << " " << p.velocity.z;
    return 0;
}