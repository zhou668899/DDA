#include <GL/glut.h>
#include<math.h>
void DDA_Line(int x1, int y1, int x2, int y2) {
    float k, t, x, y;
    float dx = x2 - x1, dy = y2 - y1;
    int d = 1;
    if (abs(x2 - x1) >= abs(y2 - y1)) {
        k = dy / dx;
        t = dx;
    }
    else {
        k = dx / dy;
        t = dy;
        d = 0;
    }
    x = x1;
    y = y1;
    for (int i = 0; i <= t; i++) {
        glPointSize(5.0);
        glBegin(GL_POINTS);
        if (d == 1) {
            glVertex2f(x, int(y + 0.5));
            glEnd();
            x++;
            y = y + k;
        }
        else {
            glVertex2f(int(x + 0.5), y);
            glEnd();
            x = x + k;
            y++;
        }

    }

}

void display(void) {
    glClearColor(1.0, 1.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, 500, 500);

    //直线起点终点坐标
    /*DDA_Line(0, 500, 500, 0);
    DDA_Line(0, 0, 500, 600);
    DDA_Line(250, 0, 250, 500);
    DDA_Line(0, 250, 500, 250);*/
    DDA_Line(1, 0, 1000, 400);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RED);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("DDA");
    glutDisplayFunc(display);


    glColor3f(0.0, 1.0, 1.0);//颜色
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);

    glutMainLoop();
    return 0;

}