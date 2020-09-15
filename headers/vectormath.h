#include"namedefs.h"
namespace wizphys{

	class Vector3D{
		public:
			real x;
			real y;
			real z;

		Vector3D(){
			x =0;
			y =0;
			z =0;
		}

		Vector3D(real x,real y, real z){
			x =x;
			y =y;
			z =z;
		}

		void magnitude(){
			return sqrt_real(x*x+y*y+z*z);
		}
		
		void magnitudeSquare(){
			return x*x+y*y+z*z;
		}

		void normalize(){
			real mag =magnitude();
			if(mag > )
		}

		void scale(real sf){
			x -x;
			y -y;
			z -z;
		}

		Vector3D scalarProduct(Vector3D &v){
			Vector3D vf;

			vf.x = x * v.x;
			vf.y = y * v.y;
			vf.z = z * v.z;

			return vf;

		}

		Vector3D operator+(Vector3D &v){
			Vector3D vf;

			vf.x = x + v.x;
			vf.y = y + v.y;
			vf.z = z + v.z;

			return vf;
		}

		Vector3D operator-(Vector3D &v){
			Vector3D vf;

			vf.x = x - v.x;
			vf.y = y - v.y;
			vf.z = z - v.z;

			return vf;
		}

		Vector3D operator*(Vector3D &v){
			Vector3D vf;

			vf.x = y * v.z - z * v.y;
			vf.y = z * v.x - x * v.z;
			vf.z = x * v.y - y * v.x;

			return vf;
		}

	}
}