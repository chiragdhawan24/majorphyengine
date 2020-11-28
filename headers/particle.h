#include"namedefs.h"
#include"vectormath.h"
namespace wizphys{

	class Particle{
		public:
			Vector3D position;
			Vector3D velocity;
			Vector3D acceleration;
			Vector3D forceAccum;
			real damping;
			real massinverse;
			real mass;
			void integrate(real duration);
			bool hasFiniteMass();
			real getMass();
			void addForce(Vector3D newForce);
			Vector3D getVelocity();
	};
}