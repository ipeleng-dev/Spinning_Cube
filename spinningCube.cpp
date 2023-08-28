#include <GL/glut.h>

GLfloat angle = 0.0f; //angle for cube rotation

void initGL(){
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);// clear background color to black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); //setting up the stage with transformations or changes
    gluPerspective(45.0f, 1.0f, 1.0f, 100.0f); //setting the perspective projection
    glMatrixMode(GL_MODELVIEW);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear color and depth buffers
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -6.0f); // move the cube away from the camera

    glRotatef(angle, 1.0f, 1.0f, 1.0f); //rotate the cube around its diagonal

    //draw the cube
    glBegin(GL_QUADS);

    //front face
    glColor3f(1.0f, 0.0f, 0.0f); //red
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f( 1.0f, -1.0f, 1.0f);
    glVertex3f( 1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);

    //right face
    glColor3f(0.0f, 1.0f, 0.0f); //green 
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);

    //back face
    glColor3f(0.0f, 0.0f, 1.0f); //blue 
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    //left face
    glColor3f(1.0f, 1.0f, 0.0f); //yellow 
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);

    //top face
    glColor3f(1.0f, 0.0f, 1.0f); //magenta 
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);

    //bottom facce
    glColor3f(0.0f, 1.0f, 1.0f); //cyan 
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    glEnd();

    glutSwapBuffers(); //swap the buffers to diplay the rendered image
}

void reshape(int width, int height){

    //set the viewport to cover the entire window    
    glViewport(0, 0, width, height);
}

void timer(int value){
    angle += 2.0f; // Increment the rotation angle
    if(angle > 360.0f){
        angle -= 360.0f;
    }

    glutPostRedisplay();// mark the window for redrawing
    glutTimerFunc(16, timer, 0); // call the tmer function again after 16 milliseconds
}

int main(int argc, char** argv){
    glutInit(&argc, argv); //initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Spinning Cube");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);

    initGL();

    glutMainLoop();

    return 0;
}

