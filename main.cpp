#include "glut.h"
#include "geometry.h"
#include <stdio.h>
#include <stdlib.h>
#include "tgaload.h"
/* Definições da câmera */
#define y_min 60
#define ro_min 120
#define MAX_NO_TEXTURES 6
#define CUBE_TEXTURE 0

GLUquadric* cylinder = gluNewQuadric();

GLUquadric* sphere = gluNewQuadric();

GLuint texture_id[MAX_NO_TEXTURES];


float eyex = 0, eyey = y_min, eyez = ro_min;
float angle = 0, anglex = 0,anglez = 0,angleMX=-60,angleMY= 0,angleMZ=0;
int aux=0;

void initTexture (void)
{
	glBindTexture ( GL_TEXTURE_2D, texture_id[0] );
	image_t temp_image0;
	tgaLoad  ( "Cabo.tga", &temp_image0, TGA_FREE | TGA_LOW_QUALITY );
	
	glBindTexture ( GL_TEXTURE_2D, texture_id[1] );
	image_t temp_image1;
	tgaLoad  ( "lamina.tga", &temp_image1, TGA_FREE | TGA_LOW_QUALITY );
	
//	glBindTexture ( GL_TEXTURE_2D, texture_id[2] );
//	image_t temp_image2;
//	tgaLoad  ( "frente_lado.tga", &temp_image2, TGA_FREE | TGA_LOW_QUALITY );
//	
//	glBindTexture ( GL_TEXTURE_2D, texture_id[3] );
//	image_t temp_image3;
//	tgaLoad  ( "simbolo_marteloG.tga", &temp_image3, TGA_FREE | TGA_LOW_QUALITY );
//	
//	glBindTexture ( GL_TEXTURE_2D, texture_id[4] );
//	image_t temp_image4;
//	tgaLoad  ( "martelo_cimaG.tga", &temp_image4, TGA_FREE | TGA_LOW_QUALITY );
	
}
void make_tex(void){
    unsigned char data[256][256][3];
    for (int y = 0; y < 255; y++) {
		for (int x = 0; x < 255; x++) {
	    unsigned char *p = data[y][x];
	    p[0] = p[1] = p[2] = (x ^ y) & 8 ? 255 : 0;
		}
	}
   
    glGenTextures (5, texture_id);
	glBindTexture ( GL_TEXTURE_2D, texture_id[0] );
//	glBindTexture ( GL_TEXTURE_2D, texture_id[1] );
//	glBindTexture ( GL_TEXTURE_2D, texture_id[2] );
//	glBindTexture ( GL_TEXTURE_2D, texture_id[3] );
//	glBindTexture ( GL_TEXTURE_2D, texture_id[4] );
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, (const GLvoid *) data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
}


void drawLamina(){
	color(1,0,0);
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
	glBindTexture ( GL_TEXTURE_2D, texture_id[1] );
	glPushMatrix();
	glScalef(1,1,0.1);
		glRotatef(-27,0,0,1);
		drawCircleC(3,1);
	glPopMatrix();
	glTranslatef(-2.9,2,-0.1);
	glScalef(2,2,2);
	glPushMatrix();
		glBegin(GL_POLYGON);
			glTexCoord2f(0.0, 0.0);glVertex3f(1.81,-0.49,0); //Ponto B
			glTexCoord2f(1.0, 0.0);glVertex3f(1.81,-1.35,0); // Ponto E
			glTexCoord2f(1.0, 1.0);glVertex3f(2.48,-1.98,0); // Ponto F
			glTexCoord2f(0.0, 1.0);glVertex3f(2.48,0.02,0); //Ponto A
		glEnd();
		
		glBegin(GL_POLYGON);
			glTexCoord2f(0.0, 1.0);glVertex3f(2.48,0.02,0); //Ponto A
			glTexCoord2f(0.0, 0.0);glVertex3f(1.81,-0.49,0); //Ponto B
			glTexCoord2f(0.0, 0.0);glVertex3f(1.81,-0.49,0.1); //Ponto B
			glTexCoord2f(0.0, 1.0);glVertex3f(2.48,0.02,0.1); //Ponto A
		glEnd();
		glBegin(GL_POLYGON);
			glTexCoord2f(0.0, 0.0);glVertex3f(1.81,-0.49,0); //Ponto B
			glTexCoord2f(1.0, 1.0);glVertex3f(1.81,-1.35,0); // Ponto E	
			glTexCoord2f(1.0, 1.0);glVertex3f(1.81,-1.35,0.1); // Ponto E	
			glTexCoord2f(0.0, 0.0);glVertex3f(1.81,-0.49,0.1); //Ponto B
		glEnd();
		
		glBegin(GL_POLYGON);
			glTexCoord2f(1.0, 1.0);glVertex3f(1.81,-1.35,0); // Ponto E
			glTexCoord2f(1.0, 1.0);glVertex3f(2.48,-1.98,0); // Ponto F
			glTexCoord2f(1.0, 1.0);glVertex3f(2.48,-1.98,0.1); // Ponto F
			glTexCoord2f(1.0, 1.0);glVertex3f(1.81,-1.35,0.1); // Ponto E
		glEnd();
		
		glBegin(GL_POLYGON);
			glTexCoord2f(1.0, 1.0);glVertex3f(2.48,-1.98,0); // Ponto F
			glTexCoord2f(0.0, 1.0);glVertex3f(2.48,0.02,0); //Ponto A
			glTexCoord2f(0.0, 1.0);glVertex3f(2.48,0.02,0.1); //Ponto A
			glTexCoord2f(1.0, 1.0);glVertex3f(2.48,-1.98,0.1); // Ponto F	
		glEnd();
		glBegin(GL_POLYGON);
			glTexCoord2f(0.0, 0.0);glVertex3f(1.81,-0.49,0.1); //Ponto B
			glTexCoord2f(1.0, 0.0);glVertex3f(1.81,-1.35,0.1); // Ponto E
			glTexCoord2f(1.0, 1.0);glVertex3f(2.48,-1.98,0.1); // Ponto F
			glTexCoord2f(0.0, 1.0);glVertex3f(2.48,0.02,0.1); //Ponto A
		glEnd();

		glBegin(GL_POLYGON);
			glTexCoord2f(0.0, 1.0);glVertex3f(0.75,-0.49,0); //Ponto C
			glTexCoord2f(1.0, 1.0);glVertex3f(0.74,-1.35,0); // Ponto D
			glTexCoord2f(1.0, 1.0);glVertex3f(1.81,-1.35,0); // Ponto E	
			glTexCoord2f(0.0, 0.0);glVertex3f(1.81,-0.49,0); //Ponto B
		glEnd();
		
		glBegin(GL_POLYGON);
			glTexCoord2f(0.0, 0.0);glVertex3f(1.81,-0.49,0); //Ponto B
			glTexCoord2f(0.0, 1.0);glVertex3f(0.75,-0.49,0); //Ponto C
			glTexCoord2f(0.0, 1.0);glVertex3f(0.75,-0.49,0.1); //Ponto C
			glTexCoord2f(0.0, 0.0);glVertex3f(1.81,-0.49,0.1); //Ponto B
		glEnd();
		
		glBegin(GL_POLYGON);
			glTexCoord2f(0.0, 1.0);glVertex3f(0.75,-0.49,0); //Ponto C
			glTexCoord2f(1.0, 1.0);glVertex3f(0.74,-1.35,0); // Ponto D
			glTexCoord2f(1.0, 1.0);glVertex3f(0.74,-1.35,0.1); // Ponto D
			glTexCoord2f(0.0, 1.0);glVertex3f(0.75,-0.49,0.1); //Ponto C
		glEnd();
		
		glBegin(GL_POLYGON);
			glTexCoord2f(1.0, 1.0);glVertex3f(0.74,-1.35,0); // Ponto D
			glTexCoord2f(1.0, 1.0);glVertex3f(1.81,-1.35,0); // Ponto E
			glTexCoord2f(1.0, 1.0);glVertex3f(1.81,-1.35,0.1); // Ponto E
			glTexCoord2f(1.0, 1.0);glVertex3f(0.74,-1.35,0.1); // Ponto D
		glEnd();
		
		glBegin(GL_POLYGON);
			glTexCoord2f(0.0, 1.0);glVertex3f(0.75,-0.49,0.1); //Ponto C
			glTexCoord2f(1.0, 1.0);glVertex3f(0.74,-1.35,0.1); // Ponto D
			glTexCoord2f(1.0, 1.0);glVertex3f(1.81,-1.35,0.1); // Ponto E	
			glTexCoord2f(0.0, 0.0);glVertex3f(1.81,-0.49,0.1); //Ponto B
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D); 
}

void drawCabo(){
	color(0.46,0.23,0.21);
	glEnable(GL_TEXTURE_2D);

	gluQuadricDrawStyle(cylinder, GLU_FILL);
    glBindTexture(GL_TEXTURE_2D, texture_id[0]);

    gluQuadricTexture(cylinder, GL_TRUE);
    gluQuadricNormals(cylinder, GLU_SMOOTH);
    gluCylinder(cylinder,0.4,0.4,6,64,64);
	
	glDisable(GL_TEXTURE_2D); 		
	//gluCylinder
}
void display(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    /* Limpa o Buffer de Pixels */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    /* Estabelece a cor da primitiva como preta */
    glColor3f (1.0, 1.0, 1.0);
    
    /* Define a posição do observador */
	gluLookAt(eyex, eyey, eyez, 0, 0, 0, 0, 1, 0);
	glRotatef(angle, 0,1,0);
	glRotatef(anglex, 1,0,0);
	glRotatef(anglez, 0,0,1);
    
    glScalef(6,6,6);
    
    glPushMatrix();
    	glPushMatrix();
			drawLamina();
		glPopMatrix();
		glTranslatef(-1.2,1.2,0);
		glScalef(2,1.5,1);
		glPushMatrix();
			glRotatef(90,1,0,0);
			drawCabo();
		glPopMatrix();
		
		glPushMatrix();
		glRotatef(90,1,0,0);
			drawCircle(0.4,1);	
		glPopMatrix();
		
		glTranslatef(0,-6,0);
		glPushMatrix();
			glRotatef(90,1,0,0);
			drawCircle(0.4,1);	
		glPopMatrix();
		
	glPopMatrix();
	//Executa os comandos OpenGL 
	glFlush();
}

void TimerFunc(int value) {
	angle += 1; 
    glutPostRedisplay();
    glutTimerFunc( 33, TimerFunc, 0.1);
}

void reshape(int width, int height) {
	glViewport(0,0,width,height); // Reset The Current Viewport
	
	glMatrixMode(GL_PROJECTION); // Select The Projection Matrix
	glLoadIdentity(); // Reset The Projection Matrix
	
	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f,(float)640/(float)480,0.1f,1000.0f);
	// Always keeps the same aspect as a 640 wide and 480 high window
	
	glMatrixMode(GL_MODELVIEW); // Select The Modelview Matrix
	glLoadIdentity(); // Reset The Modelview Matrix
}

void key(unsigned char key, int x, int y) {
	switch(key) {
		case 27:
			exit(0);
			break;
		case 'y': /* e key rotates at elbow */
	 	 aux = (int) (angle + 5);
		 angle = aux % 360;
		 glutPostRedisplay();
		 break;
		case 'Y': /* e key rotates at elbow */
	 	 aux = (int) (angle - 5);
		 angle = aux % 360;
		 glutPostRedisplay();
		 break;
		 
		case 'x': /* e key rotates at elbow */
	 	 aux = (int) (anglex + 5);
		 anglex = aux % 360;
		 glutPostRedisplay();
		 break;
		case 'X': /* e key rotates at elbow */
	 	 aux = (int) (anglex - 5);
		 anglex = aux % 360;
		 glutPostRedisplay();
		 break;
		 
		case 'z': /* e key rotates at elbow */
	 	 aux = (int) (anglez + 5);
		 anglez = aux % 360;
		 glutPostRedisplay();
		 break;
		case 'Z': /* e key rotates at elbow */
	 	 aux = (int) (anglez - 5);
		 anglez = aux % 360;
		 glutPostRedisplay();
		 break;
			
	}
}

void init() {
	glClearColor(1,1,1,0);
	glClearDepth(1.0); // Enables Clearing Of The Depth Buffer
	glDepthFunc(GL_LESS); // The Type Of Depth Test To Do
	glEnable(GL_DEPTH_TEST); // Enables Depth Testing
	make_tex();
    initTexture ();
    glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH); // Enables Smooth Color Shading
}

/*
Funcao principal do programa.
*/
int main(int argc, char** argv)
{
	//Inicia a Telinha
	glutInit(&argc,argv);
	
    /*
    Estabelece o modo de exibicao a ser utilizado pela janela a ser
    neste caso utiliza-se de um buffer duplo, ou seja, a apresentacao
    execucao
    Define o modo de cores como RGBA
    */
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    
    /*
    Determina o tamanho em pixels da
    janela a ser criada
    */
    glutInitWindowSize (450, 450);
    
    /*
    Estabelece a posicao inicial para criacao da
    janela
    */
    glutInitWindowPosition (100, 100);
    
    /*
    Cria uma janela com base nos parametros especificados
    nas funcoes glutInitWindowSize e glutInitWindowPosition
    com o nome de titulo especificado em seu argumento
    */
    glutCreateWindow ("Projeto Base");
    
    /*
    Especifica os parametros inicias para as variaveis
    de estado do OpenGL
    */
    init ();
    //TimerFunc(angle);
    // Associa a funcao display como uma funcao de callback
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(key);
    
    /*
    Inicia a execucao do programa OpenGL.
    O programa ira executar num loop infinito devendo
    o desenvolvedor especificar as condicoes de saida do mesmo
    atraves de interrupcoes no proprio programa ou atraves
    de comandos de mouse ou teclado como funcoes de callback
    */
    glutMainLoop();
    return 0;
}
