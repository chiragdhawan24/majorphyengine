#include"namedefs.h"
#include"vectormath.h"
namespace wizphys{

	class Particle{
		public:
			Vector3d position;
			Vector3d velocity;
			Vector3d acceleration;
			real damping;
			real massinverse;

	}
}