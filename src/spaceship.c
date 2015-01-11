#include <stdio.h>
#include <GL/glut.h>
#include "../headers/spaceship.h"

float turbine_r = 0;

void spaceship_turbine(void)
{
    /* this is the turbine along with the fan */

    /* the color of the turbine */
    glColor3f(1.0f, 0.5f, 0.3f);

    /* the main part of the turbine */
    glPushMatrix();
    glScalef(turbine_scale_x, turbine_scale_y, turbine_scale_z);
    glutSolidTorus(turbine_ring, turbine_radius, 1000, 1000);
    glPopMatrix();
    
    /* the back part of the turbine */
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.12f);
    glScalef(turbine_back_scale_x, turbine_back_scale_y, turbine_back_scale_z);
    glutSolidSphere(turbine_back_radius, 1000, 1000);
    glPopMatrix();

    /* the fan of the turbine */
    glPushMatrix();
    glRotatef(turbine_r, 0.0f, 0.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glScalef(1.0f, 0.05f, 0.20f);
    glutSolidSphere(0.2f, 100.0f, 100.0f);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glRotatef(90 + turbine_r, 0.0f, 0.0f, 1.0f);
    glScalef(1.0f, 0.05f, 0.20f);
    glutSolidSphere(0.2f, 100.0f, 100.0f);
    glPopMatrix();

    turbine_r += 50;
}

void spaceship_wing(void)
{
    /* the spaceship side wings */
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.6f);
    glScalef(wing_scale_x, wing_scale_y, wing_scale_z);
    glutSolidCone(wing_base, wing_height, 1000, 1000);
    glPopMatrix();
}

void spaceship_tail(void)
{
    /* the spaceship tail */
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.6f);
    glScalef(tail_scale_x, tail_scale_y, tail_scale_z);
    glutSolidCone(tail_base, tail_height, 1000, 1000);
    glPopMatrix();
}

void spaceship_body(void)
{
    /* the spaceship body consists of a scaled sphere */
    glPushMatrix();
    glColor3f(0.0f, 1.0f, 0.6f);
    glScalef(body_scale_x, body_scale_y, body_scale_z);
    glutSolidSphere(body_radius, 1000, 1000);
    glPopMatrix();
}

void spaceship(void)
{
    glPushMatrix();

    spaceship_body();

    glPushMatrix();
    glTranslatef(-2.70f, 0.0f, 0.0f);
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    glScalef(2.0f, 2.0f, 2.0f);
    spaceship_turbine();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.00f, 0.0f, 0.0f);
    glRotatef(270, 1.0f, 0.0f, 0.0f);
    glRotatef(-30, 0.0f, 1.0f, 0.0f);
    spaceship_tail();
    glPopMatrix();

    /* right wing */
    glPushMatrix();
    glTranslatef(-0.50f, -0.20f, 0.5f);
    glRotatef(-10, 0.0f, 1.0f, 0.0f);
    glRotatef(10, 1.0f, 0.0f, 0.0f);
    spaceship_wing();
    glPopMatrix();

    /* left wing */
    glPushMatrix();
    glTranslatef(-0.50f, -0.20f, -0.5f);
    glRotatef(180, 1.0f, 0.0f, 0.0f);
    glRotatef(-10, 0.0f, 1.0f, 0.0f);
    glRotatef(-10, 1.0f, 0.0f, 0.0f);
    spaceship_wing();
    glPopMatrix();

    /* right wing turbine */
    glPushMatrix();
    glTranslatef(-0.50f, -0.20f, 0.5f);
    glTranslatef(-0.10f, -0.40f, 0.80f);
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    spaceship_turbine();
    glPopMatrix();

    /* left wing turbine */
    glPushMatrix();
    glTranslatef(-0.50f, -0.20f, -0.5f);
    glTranslatef(-0.10f, -0.40f, -0.80f);
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    spaceship_turbine();
    glPopMatrix();

    glPopMatrix();
}
