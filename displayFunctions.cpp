


// Initialize OpenGL's rendering modes
void initRendering()
{
    glEnable(GL_DEPTH_TEST);   // Depth testing must be turned on
    glEnable(GL_LIGHTING);     // Enable lighting calculations
    glEnable(GL_LIGHT0);       // Turn on light #0.
}

// Called when the window is resized
// w, h - width and height of the window in pixels.
void reshapeFunc(int w, int h)
{
    // Always use the largest square viewport possible
    if (w > h) {
        glViewport((w - h) / 2, 0, h, h);
    } else {
        glViewport(0, (h - w) / 2, w, w);
    }

    // Set up a perspective view, with square aspect ratio
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // 50 degree fov, uniform aspect ratio, near = 1, far = 100
    gluPerspective(50.0, 1.0, 1.0, 100.0);
}


// This function is responsible for displaying the object.
void drawScene(void)
{
    int i;

    // Clear the rendering window
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Rotate the image
    glMatrixMode( GL_MODELVIEW );  // Current matrix affects objects positions
    glLoadIdentity();              // Initialize to the identity

    // Position the camera at [0,0,5], looking at [0,0,0],
    // with [0,1,0] as the up direction.
    gluLookAt(0.0, 0.0, 5.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);

    // Set material properties of object

	// Here are some colors you might use - feel free to add more
    GLfloat diffColors[4][4] = { {0.5, 0.5, 0.9, 1.0},
                                 {0.9, 0.5, 0.5, 1.0},
                                 {0.5, 0.9, 0.3, 1.0},
                                 {0.3, 0.8, 0.9, 1.0} };
    
	// Here we use the first color entry as the diffuse color
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, diffColors[c]);

	// Define specular color and shininess
    GLfloat specColor[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat shininess[] = {100.0};

	// Note that the specular color and shininess can stay constant
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specColor);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
  
    // Set light properties

    // Light color (RGBA)
    GLfloat Lt0diff[] = {1.0,1.0,1.0,1.0};
    // Light position
	GLfloat Lt0pos[] = {1.0f+0.5*p1, 1.0f+0.5*p2, 5.0f, 1.0f};

    glLightfv(GL_LIGHT0, GL_DIFFUSE, Lt0diff);
    glLightfv(GL_LIGHT0, GL_POSITION, Lt0pos);

	// This GLUT method draws a teapot.  You should replace
	// it with code which draws the object you loaded.
	//glutSolidTeapot(1.0);
	glBegin(GL_TRIANGLES);
float x0=0.5f*(xmax+xmin);
float y0=0.5f*(ymax+ymin);
float z0=0.5f*(zmax+zmin);
float xl=xmax-xmin;
float yl=ymax-ymin;
float zl=zmax-zmin;
glOrtho(xmin,xmax,ymin,ymax,zmin,zmax);

for(int  k=0; i < Model.size(); i++){
	
	for(unsigned int x=0; x < Model[i]->vecf.size(); x++) {
		
	int a,b,c,d,e,f,g,h,i;
	a=Model[k]->vecf[x][0];
	b=Model[k]->vecf[x][1];
	c=Model[k]->vecf[x][2];
	d=Model[k]->vecf[x][3];
	e=Model[k]->vecf[x][4];
	f=Model[k]->vecf[x][5];
	g=Model[k]->vecf[x][6];
	h=Model[k]->vecf[x][7];
	i=Model[k]->vecf[x][8];
	//cout << c << "\t in display fn"<< endl;
	
	//Normals
	if(c == 0){
		glNormal3d(0, 0,0);
	}
	else
		glNormal3d(vecn[c-1][0], vecn[c-1][1],vecn[c-1][2]);
	
	//Textures
	
	if(b == 0)
		glTexCoord3d(0, 0,0);
	else
		glTexCoord3f(vec_tex[b-1][0], vec_tex[b-1][1], vec_tex[b-1][2]); 
	//Vertices

	glVertex3d(vecv[a-1][0]-x0, vecv[a-1][1]-y0, vecv[a-1][2]-z0);
	
	//Normals
	if(f == 0){
		glNormal3d(0, 0,0);
	}
	else
		glNormal3d(vecn[f-1][0],  vecn[f-1][1],  vecn[f-1][2]);
	//Textures
	if(e == 0)
		glTexCoord3d(0, 0,0);
	else
		glTexCoord3f( vec_tex[e-1][0],  vec_tex[e-1][1],  vec_tex[e-1][2]); 
	
	//Vertices

	glVertex3d( vecv[d-1][0]-x0,  vecv[d-1][1]-y0,  vecv[d-1][2]-z0);
	
	//Normals
	if(i == 0){
		glNormal3d(0, 0,0);
	}
	else
		glNormal3d( vecn[i-1][0],  vecn[i-1][1],  vecn[i-1][2]);
	//Textures
	if(h == 0)
		glTexCoord3d(0, 0,0);
	else
		glTexCoord3f( vec_tex[h-1][0],  vec_tex[h-1][1],  vec_tex[h-1][2]); 
	//Vertices

	glVertex3d( vecv[g-1][0]-x0,  vecv[g-1][1]-y0, vecv[g-1][2]-z0);
	

}
}
    glEnd();
    // Dump the image to the screen.
    glutSwapBuffers();


}

