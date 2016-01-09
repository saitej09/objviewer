#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <cstring>
//#include "include/vecmath/vecmath.h"
#include "vecmath/vecmath.cpp"



#define MAX_BUFFER_SIZE 1024
using namespace std;

// Globals

	// This is the list of points (3D vectors)
	vector<Vector3f> vecv;

	// This is the list of normals (also 3D vectors)
	vector<Vector3f> vecn;

	// This is the list of faces (indices into vecv and vecn)
	//vector<vector<unsigned> > vecf;

	
	// this is the list of texture co-ordinates
	vector<Vector3f> vec_tex;
//object name
	//string obj_name;

// You will need more global variables to implement color and position changes
int c=0;
int p1=0,p2=0;
float xmin,xmax,ymin,ymax,zmin,zmax;
// These are convenience functions which allow us to call OpenGL 
// methods on Vec3d objects
inline void glVertex(const Vector3f &a) 
{ glVertex3fv(a); }

inline void glNormal(const Vector3f &a) 
{ glNormal3fv(a); }

//material file name declaration

std::ifstream matl_ObjFile;
//material prop decln
struct MaterialInfo{
	string matl_name;
	Vector3f Ka; //Ambient reflectivity
	Vector3f Kd; //Diffuse reflectivity
	Vector3f Ks; //Specular reflectivity
	Vector3f Tf; //transmission Filter
	float Shininess; //Specular shininess factor
	int illum; //illumination model
	float Ns; //specular exponent
	float d; //dissolving factor
	float Tr; //transparency
};

//vector to hold material data 
	vector <MaterialInfo> materials_data;
	
class Object{
public:
	// Globals
	
	//object name
	string obj_name;

	// This is the list of points (3D vectors)
	//vector<Vector3f> vecv;

	// This is the list of normals (also 3D vectors)
	//vector<Vector3f> vecn;

	// This is the list of faces (indices into vecv and vecn)
	vector<vector<unsigned> > vecf;

	
	// this is the list of texture co-ordinates
	//vector<Vector3f> vec_tex;
	
	//vector to hold material data 
	vector <MaterialInfo> materials_data;
	

};
std::vector <Object*> Model;
#include "streamFunctions.cpp"
#include "readMaterial.cpp"
#include "objLoader.cpp"
#include "displayFunctions.cpp"
#include "Controls.cpp"



