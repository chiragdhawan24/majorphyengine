#include"namedefs.h"
#include"vectormath.h"
namespace wizphys{

	class Particle{
		public:
			Vector3D position;
			Vector3D velocity;
			Vector3D acceleration;
			real damping;
			real massinverse;
			real mass;
			void integrate(real duration);
	};
}