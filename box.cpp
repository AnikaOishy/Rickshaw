

/*
Ahsanullah University of Science and Technology
Course Title:Computer Graphice Lab
Course Number: CSE 4204
Name: Lamia Parven Khan
ID : 09.02.04.021
Section: A1
Year/Semester: 4th year 2nd semester
*/

//Continue Pressing 1 to open the door
//Continue pressing 2 to close the door

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include<GL/glut.h>
double cameraAngle;

#define BLACK 0, 0, 0

double _cameraangle=5,_rot =0,_zpos;
double x =60, y=30 ,z =30;
void display(){

	//clear the display
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(BLACK, 0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/********************
	/ set-up camera here
	********************/
	//load the correct matrix -- MODEL-VIEW matrix
	glMatrixMode(GL_MODELVIEW);

	//initialize the matrix
	glLoadIdentity();

	gluLookAt(250*cos(cameraAngle), 250*sin(cameraAngle), 120,0,0,0,		0,0,1);
   // gluLookAt(150, 150, 200,0,0,0,		0,0,1);
	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);


	/****************************
	/ Add your objects from here
	****************************/
	//add objects

  glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0); 
  glutWireCube(120);

	//some gridlines along the field
	int i;
//up

 	glPushMatrix();{
	glColor3f(0.5, 0.5, 0.5);	//grey
	glBegin(GL_LINES);{
		for(i=-5;i<=5;i++){
			//lines parallel to Y-axis
			glVertex3f(i*10,-60, 60);
			glVertex3f(i*10, 60,60);

			//lines parallel to X-axis
			glVertex3f(-60, i*10, 60);
			glVertex3f( 60, i*10, 60);
		}
	}glEnd();
	}glPopMatrix();
    
    	
//bottom
glPushMatrix();{
glColor3f(0.5, 0.5, 0.5);	//grey
	glBegin(GL_LINES);{
		for(i=-5;i<=5;i++){
			glVertex3f(i*10, -60,-60);
            glVertex3f(i*10, 60,-60);

			//lines parallel to X-axis
			glVertex3f(-60, i*10,-60);
			glVertex3f( 60, i*10, -60);
		}
	}glEnd();
	}glPopMatrix();	


//top

    glColor3f(0.5, 0.5, 0.5);
    	//grey
   
   	glPushMatrix();{	
                      glTranslatef(0,-30,30);
	glBegin(GL_LINES);{
           
		for(i=-3;i<=3;i++){
                               
   			//lines parallel to Y-axis
			glVertex3f(60,i*10, -30);
			glVertex3f(60,i*10, 30);
			//lines parallel to X-axis
			glVertex3f(60,-30, i*10);
			glVertex3f(60,30, i*10);
			
		}
	}glEnd();
		}glPopMatrix();		
            
            //front bottom                              
			glPushMatrix();{
                             glTranslatef(60,-60,-60);	
                    glRotatef(_rot,0.0,0.0f,-1.0f); 
        
	glBegin(GL_LINES);{
           
		for(i=0;i<=6;i++)
        {
                               
   			//lines parallel to Y-axis
			glVertex3f(0,i*10, 0); 
			glVertex3f(0,i*10, 60);
			//lines parallel to X-axis
			glVertex3f(0,60, i*10);
			glVertex3f( 0,0,i*10);
			
		}
	}
    glEnd();
		}
        glPopMatrix();
        
        //front bottom                              
			glPushMatrix();{
                             glTranslatef(60,60,-60);	
                    glRotatef(_rot,0.0,0.0f,1.0f); 
        
	glBegin(GL_LINES);{
           
		for(i=0;i<=6;i++)
        {
                               
   			//lines parallel to Y-axis
			glVertex3f(0,-i*10, 0); 
			glVertex3f(0,-i*10, 60);
			//lines parallel to X-axis
			glVertex3f(0,-60, i*10);
			glVertex3f( 0,0,i*10);
			
		}
	}
    glEnd();
		}
        glPopMatrix();
 
        
        
       //front top right 
        	glPushMatrix();{	
                      glTranslatef(0,30,30);
	glBegin(GL_LINES);{
           
		for(i=-3;i<=3;i++){
                               
   			//lines parallel to Y-axis
			glVertex3f(60,i*10, -30);
			glVertex3f(60,i*10, 30);
			//lines parallel to X-axis
			glVertex3f(60,-30, i*10);
			glVertex3f(60,30, i*10);
			
		}
	}glEnd();
		}glPopMatrix();	
        
  
//behind
        glPushMatrix();{
		glBegin(GL_LINES);{
                      
		for(i=-5;i<=5;i++){
        glTranslatef(-100,-100,0);
			//lines parallel to Y-axis
			glVertex3f(-60,i*10, -60);
			glVertex3f(-60,i*10,  60);

			//lines parallel to X-axis
			glVertex3f(-60,-60, i*10);
			glVertex3f(-60,60, i*10);
		}
	}glEnd();
	}glPopMatrix();	
//right
glPushMatrix();{
glColor3f(0.5, 0.5, 0.5);
		glBegin(GL_LINES);{
                      // glTranslatef(100,100,100);
		for(i=-5;i<=5;i++){
            //lines parallel to Y-axis
			glVertex3f(i*10,60,-60);
			glVertex3f(i*10,60,60);

			//lines parallel to X-xis
			glVertex3f(-60,60,i*10);
			glVertex3f( 60,60,i*10);
		}
	}glEnd();
	}glPopMatrix();	
	//left
	 	glPushMatrix();{
          glColor3f(0.5, 0.5, 0.5);
		glBegin(GL_LINES);{
                      // glTranslatef(100,100,100);
		for(i=-5;i<=5;i++){
			//lines parallel to Y-axis
			glVertex3f(i*10,-60,-60);
			glVertex3f(i*10,-60,60);

			//lines parallel to X-xis
			glVertex3f(-60,-60, i*10);
			glVertex3f( 60,-60, i*10);
			}glEnd();
			}glPopMatrix();	
      }
      
 //draw the two AXES
	glColor3f(1, 1, 1);	//100% white
	glBegin(GL_LINES);{
                       
	                
		//Y axis
		glVertex3f(0,-150, -60);	
		glVertex3f(0,   150, -60);

		//X axis
		glVertex3f(-150, 0, -60);
		glVertex3f( 150, 0, -60);
	}glEnd();

	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glutSwapBuffers();
	
}

void animate()
{
	//codes for any changes in Models, Camera
	cameraAngle += 0.002;
	_cameraangle +=.5f;
	glutPostRedisplay();
	
}

void keyboardListener(unsigned char key, int x,int y){
	switch(key){

	case '1':
                if(_rot<=120)
                  _rot +=5;
                   break;
            
            
            case '2':

                       if(_rot!=0)
                        _rot -= 5;
                         break;         	                		
            case '3':
                         exit(0);
                         break; 
    default:
			break;
 glutPostRedisplay();
      
		
			
	
	}
}


void init(){
	//codes for initialization

	//clear the screen
	glClearColor(BLACK, 0);
cameraAngle = 0;
	/************************
	/ set-up projection here
	************************/
	//load the PROJECTION matrix
	glMatrixMode(GL_PROJECTION);
	
	//initialize the matrix
	glLoadIdentity();

	//give PERSPECTIVE parameters
	gluPerspective(70,	1,	0.1,	10000.0);
	
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

	glutCreateWindow("My OpenGL Program");

	init();

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)
	glutKeyboardFunc(keyboardListener);
	glutMainLoop();		//The main loop of OpenGL

	return 0;
}
