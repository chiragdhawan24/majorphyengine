#include"namedefs.h"
namespace wizphys{

	class Vector3D{
		public:
			real x;
			real y;
			real z;

		Vector3D(){
			x = 0;
			y = 0;
			z = 0;
		}

		Vector3D(real rx,real ry, real rz){
			x = rx;
			y = ry;
			z = rz;
		}

		real magnitude(){
			return sqrt(x*x+y*y+z*z);
		}
		
		real magnitudeSquare(){
			return x*x+y*y+z*z;
		}

		Vector3D operator*(Vector3D &v){
			Vector3D vf;

			vf.x = y * v.z - z * v.y;
			vf.y = z * v.x - x * v.z;
			vf.z = x * v.y - y * v.x;

			return vf;
		}


		void normalize(){
			real mag =magnitude();
			if(mag > 0)
				(*this).scale(((real)1)/mag);
		}

		void scale(real sf){
			x = sf*x;
			y = sf*y;
			z = sf*z;
		}

		Vector3D operator+(Vector3D &v){
			Vector3D vf(x + v.x,y + v.y,z + v.z);

			return vf;
		}

		Vector3D operator-(Vector3D &v){
			Vector3D vf;

			vf.x = x - v.x;
			vf.y = y - v.y;
			vf.z = z - v.z;

			return vf;
		}

		void scaledAdd(Vector3D &v, real sf){
			v.scale(sf);
			Vector3D vf;
			(*this) = v + (*this);
		}

		Vector3D compProduct(Vector3D &v){
			Vector3D vf(x * v.x,y * v.y,z * v.z);
			return vf;
		}

		real scalarProduct(Vector3D &v){
			real scalep;
			Vector3D vf;
			vf = vf.compProduct(v);

			return vf.x + vf.y + vf.z;
		}

		Vector3D crossProduct(Vector3D &v){
			Vector3D vf(y*v.z - z*v.y,z*v.x - x*v.z,x*v.y - y*v.x);

			return vf;
		}

	};
}