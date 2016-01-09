
//Mouse Fn
#include<math.h>

bool rot=false,scale=false,trans=false;
int prevX,prevY,currentX,currentY;
float rotX,rotY,rotZ,scalX=1,scalY=1,scalZ=1;
//int width,height;

void MouseClick(int button, int state, int x, int y){
if(state==GLUT_DOWN){prevX=x;
prevY=y;}
if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
{
rot=true;



}
if(button==GLUT_LEFT_BUTTON && state==GLUT_UP)
{
rot=false;

}
if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
{
scale=true;
}
if(button==GLUT_RIGHT_BUTTON && state==GLUT_UP)
{
scale=false;
}
if(button==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN)
{
trans=true;
}
if(button==GLUT_MIDDLE_BUTTON && state==GLUT_UP)
{
trans=false;
}

}

void MouseMove(int x,int y){
if(rot)
{
if (y > prevY)
                            rotX += 2 * atan2(abs(y - prevY), abs(x - prevX));
                        else
                            rotX -= 2 * atan2(abs(y - prevY), abs(x - prevX));
                        if (x > prevX)
                            rotY += 2 * atan2(abs(x - prevX), abs(y - prevY));
                        else
                            rotY -= 2 * atan2(abs(x - prevX), abs(y - prevY));
}
if(scale){
if (y > prevY)
                        {
                            scalX *= 1.01;
                            scalY *= 1.01;
                            scalZ *= 1.01;
                            
                        }
                        else if (y < prevY)
                        {
                            scalX /= 1.01;
                            scalY /= 1.01;
                            scalZ /= 1.01;
                            
                        }
}
glutPostRedisplay();
}

// This function is called whenever a "Normal" key press is received.
void keyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {
    case 27: // Escape key
        exit(0);
        break;
    case 'c':
        // add code to change color here
//		cout << "Unhandled key press " << key << "." << endl; 
if(c<3)
c++;
else c=0;
        break;
    default:
        cout << "Unhandled key press " << key << "." << endl;        
    }

	// this will refresh the screen so that the user sees the color change
    glutPostRedisplay();
}

// This function is called whenever a "Special" key press is received.
// Right now, it's handling the arrow keys.
void specialFunc( int key, int x, int y )
{
    switch ( key )
    {
    case GLUT_KEY_UP:
        // add code to change light position
		p2++;
		break;
    case GLUT_KEY_DOWN:
        // add code to change light position
		p2--;
		break;
    case GLUT_KEY_LEFT:
        // add code to change light position
		p1--;
		break;
    case GLUT_KEY_RIGHT:
        // add code to change light position
		p1++;
		break;
    }

	// this will refresh the screen so that the user sees the light position
    glutPostRedisplay();
}

