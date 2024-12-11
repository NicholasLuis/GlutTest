#include <windows.h>
#include <GL/glew.h>
#include "freeglut.h"
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>

// Example code that uses glut:


void display() {
	glClear(GL_COLOR_BUFFER_BIT); // Clear the screen

	// Draw a triangle
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f); // Red
	glVertex2f(-0.5f, -0.5f);
	glColor3f(0.0f, 1.0f, 0.0f); // Green
	glVertex2f(0.5f, -0.5f);
	glColor3f(0.0f, 0.0f, 1.0f); // Blue
	glVertex2f(0.0f, 0.5f);
	glEnd();

	glFlush(); // Render the drawing
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);                      // Initialize GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Single buffer, RGB mode
	glutInitWindowSize(500, 500);                // Window size
	glutCreateWindow("GLUT Test - Triangle");    // Create window with title
	glutDisplayFunc(display);                    // Register display callback
	glutMainLoop();                              // Enter GLUT main loop

	return 0;                                    // Never reached
}