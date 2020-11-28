#include<vector>
#include "particle.h"

namespace wizphys
{
    class ParticleForceGenerator
	{
		public:
			virtual void updateForce(Particle *particle, real duration) = 0;
	};

    class ParticleForceRegistry
	{
		protected:
            struct ParticleForceRegistration
            {
                Particle *particle;
                ParticleForceGenerator *fg;
            };
			typedef std::vector<ParticleForceRegistration> Registry;
			Registry registrations;
		
		public:
			void add(Particle *p, ParticleForceGenerator *fg);
			void remove(Particle *p, ParticleForceGenerator *fg);
			void clear();
			void updateForces(real duration);
	};
	
	// A force generator that applies a gravitational force.
	class GravityFG : public ParticleForceGenerator
	{
		Vector3D gravity;
		public:
			GravityFG(const Vector3D &gravity);
			virtual void updateForce(Particle *p, real duration);

	};
	class DragFG : public ParticleForceGenerator
	{
		real k1;
		real k2;
		
		public:
			DragFG(real k1, real k2);
			virtual void updateForce(Particle *p, real duration);
	};
}