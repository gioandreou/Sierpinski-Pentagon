

#include <GLUT/glut.h>
#include <openGL/gl.h>

void myinit(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0); /* white background */
    
    glColor3ub( rand()%255, rand()%255, rand()%255 );

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    
    gluOrtho2D(0.0, 250.0, 0.0, 200.0);
    
    glMatrixMode(GL_MODELVIEW);
}




void display( void )
{

    typedef GLfloat point2[5];

    point2 vertices[5]={{100,0},{0,250},{250,400},{500,250},{400,0}}; /* A triangle */

    int j, k;
    
    int rand();
    
    point2 p ={100.0,75.0};

    glClear(GL_COLOR_BUFFER_BIT);


    for( k=0; k<100000; k++)
    {
         j=rand()%5; /* vertex at random */

         p[0] = (p[0]+vertices[j][0])/3.0;
         p[1] = (p[1]+vertices[j][1])/3.0;
         p[2] = (p[2]+vertices[j][2])/3.0;
         p[3] = (p[3]+vertices[j][3])/3.0;
         p[4] = (p[4]+vertices[j][4])/3.0;
        
        
        glBegin(GL_POINTS);
        
        glVertex2fv(p);
        glEnd();
     }
    
    
    glFlush(); /* clear buffers */
 }

void drawFractal( int Numbers )
{
    
    typedef GLfloat point2[5];
    
    point2 vertices[5]={{100,0},{0,250},{250,400},{500,250},{400,0}};
    
    int j, k;
    int rand();
    point2 p ={100.0,75.0};  /* An arbitrary initial point inside traingle */
    
    
    glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_PROJECTION);
    
    glLoadIdentity();
    
    gluOrtho2D(0.0, 250.0, 0.0, 200.0);
    
    glMatrixMode(GL_MODELVIEW);
    
    glColor3ub( rand()%255, rand()%255, rand()%255 );
    
    
    for(k = 0; k < Numbers; k++)
        
    {
        j = rand() % 5;
        
        p[0] = (p[0]+vertices[j][0])/3.0;
        p[1] = (p[1]+vertices[j][1])/3.0;
        p[2] = (p[2]+vertices[j][2])/3.0;
        p[3] = (p[3]+vertices[j][3])/3.0;
        p[4] = (p[4]+vertices[j][4])/3.0;
        
        glBegin(GL_POINTS);
        glVertex2fv(p);
        
       
        glEnd();
    }
   
    
    glutSwapBuffers();
    
    glutPostRedisplay();
    
}


void menu(int id)
{
    switch(id)
    {
        case
            0:
            drawFractal(20000);
            break;
        case
            1:
            drawFractal(50000);
            break;
        case
            2:
            exit(0);
            break;
    }
    
}


void main(int argc, char** argv)
{

/*  GLUT initialization */

    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500); /* 500 x 500 pixel window */
    glutInitWindowPosition(50,50); /* place window top left on display */
    glutCreateWindow("Sierpinski Pentagon"); /* window title */
    glutDisplayFunc(display);

    myinit();
    
    glutCreateMenu(menu);
    glutAddMenuEntry("20000 σημεία", 0);
    
    glutAddMenuEntry("50000 σημεία",1);
    
    glutAddMenuEntry("Τερματισμός",2);
    
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
}

