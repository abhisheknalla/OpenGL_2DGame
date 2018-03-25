#include "magnet.h"
#include "main.h"
#define PI 3.14159

Magnet::Magnet(float x, float y, color_t color, int type) {
 this->position = glm::vec3(x, y, 0);
 GLfloat vertex_buffer_data2[3258] = {};

 if(type==1)
 {
  double angle = PI/2 - PI/180;
  int i;
  for(i=0;i<1620;){
    if(i>100 && i<1520)
    {
      vertex_buffer_data2[i] = (0.5 * cos(angle) + 0.0 * sin(angle));
      vertex_buffer_data2[i + 1] = (0.5 * sin(angle) - 0.0 * cos(angle));
      vertex_buffer_data2[i + 2] = 0;

      vertex_buffer_data2[i + 3] = (0.5 * cos(angle + PI/180) + 0.0 * sin(angle + PI/180));
      vertex_buffer_data2[i + 4] = (0.5 * sin(angle + PI/ 180) - 0.0 * cos(angle + PI/ 180));
      vertex_buffer_data2[i + 5] = 0;

      vertex_buffer_data2[i + 6] = 0;
      vertex_buffer_data2[i + 7] = 0;
      vertex_buffer_data2[i + 8] = 0;
    }
    else
    {
    vertex_buffer_data2[i] = (0.5 * cos(angle) + 0.0 * sin(angle));
    vertex_buffer_data2[i + 1] = (0.5 * sin(angle) - 0.0 * cos(angle));
    vertex_buffer_data2[i + 2] = 0;

    vertex_buffer_data2[i + 3] = (0.5 * cos(angle + PI/180) + 0.0 * sin(angle + PI/180));
    vertex_buffer_data2[i + 4] = (0.5 * sin(angle + PI/ 180) - 0.0 * cos(angle + PI/ 180));
    vertex_buffer_data2[i + 5] = 0;

    vertex_buffer_data2[i + 6] = 0;
    vertex_buffer_data2[i + 8] = 0;
  }
  vertex_buffer_data2[i + 7] = 0;
    i+=9;
    angle = - PI/180 + angle;
}

  vertex_buffer_data2[i] = 0;
  vertex_buffer_data2[i + 1] = -0.5;
  vertex_buffer_data2[i + 2] = 0;

  vertex_buffer_data2[i + 3] = -0.6;
  vertex_buffer_data2[i + 4] = -0.5;
  vertex_buffer_data2[i + 5] = 0;

  vertex_buffer_data2[i + 6] = 0;
  vertex_buffer_data2[i + 7] = -0.20;
  vertex_buffer_data2[i + 8] = 0;


    vertex_buffer_data2[i+9] = -0.6;
    vertex_buffer_data2[i + 10] = -0.20;
    vertex_buffer_data2[i + 11] = 0;

    vertex_buffer_data2[i + 12] = -0.6;
    vertex_buffer_data2[i + 13] = -0.5;
    vertex_buffer_data2[i + 14] = 0;

    vertex_buffer_data2[i + 15] = 0;
    vertex_buffer_data2[i + 16] = -0.20;
    vertex_buffer_data2[i + 17] = 0;
    i+=18;

      vertex_buffer_data2[i] = 0;
      vertex_buffer_data2[i + 1] = 0.5;
      vertex_buffer_data2[i + 2] = 0;

      vertex_buffer_data2[i + 3] = -0.6;
      vertex_buffer_data2[i + 4] = 0.5;
      vertex_buffer_data2[i + 5] = 0;

      vertex_buffer_data2[i + 6] = 0;
      vertex_buffer_data2[i + 7] = 0.20;
      vertex_buffer_data2[i + 8] = 0;


        vertex_buffer_data2[i+9] = -0.6;
        vertex_buffer_data2[i + 10] = 0.20;
        vertex_buffer_data2[i + 11] = 0;

        vertex_buffer_data2[i + 12] = -0.6;
        vertex_buffer_data2[i + 13] = 0.5;
        vertex_buffer_data2[i + 14] = 0;

        vertex_buffer_data2[i + 15] = 0;
        vertex_buffer_data2[i + 16] = 0.20;
        vertex_buffer_data2[i + 17] = 0;
  }
  if(type==2)
  {
   double angle = PI/2 + PI/180;
   int i;
   for(i=0;i<1620;){
     if(i>100 && i<1520)
     {
       vertex_buffer_data2[i] = (0.5 * cos(angle) + 0.0 * sin(angle));
       vertex_buffer_data2[i + 1] = (0.5 * sin(angle) - 0.0 * cos(angle));
       vertex_buffer_data2[i + 2] = 0;

       vertex_buffer_data2[i + 3] = (0.5 * cos(angle + PI/180) + 0.0 * sin(angle + PI/180));
       vertex_buffer_data2[i + 4] = (0.5 * sin(angle + PI/ 180) - 0.0 * cos(angle + PI/ 180));
       vertex_buffer_data2[i + 5] = 0;

       vertex_buffer_data2[i + 6] = 0;
       vertex_buffer_data2[i + 7] = 0;
       vertex_buffer_data2[i + 8] = 0;
     }
     else
     {
     vertex_buffer_data2[i] = (0.5 * cos(angle) + 0.0 * sin(angle));
     vertex_buffer_data2[i + 1] = (0.5 * sin(angle) - 0.0 * cos(angle));
     vertex_buffer_data2[i + 2] = 0;

     vertex_buffer_data2[i + 3] = (0.5 * cos(angle + PI/180) + 0.0 * sin(angle + PI/180));
     vertex_buffer_data2[i + 4] = (0.5 * sin(angle + PI/ 180) - 0.0 * cos(angle + PI/ 180));
     vertex_buffer_data2[i + 5] = 0;

     vertex_buffer_data2[i + 6] = 0;
     vertex_buffer_data2[i + 8] = 0;
   }
   vertex_buffer_data2[i + 7] = 0;
     i+=9;
     angle =  PI/180 + angle;
 }

   vertex_buffer_data2[i] = 0;
   vertex_buffer_data2[i + 1] = -0.5;
   vertex_buffer_data2[i + 2] = 0;

   vertex_buffer_data2[i + 3] = 0.6;
   vertex_buffer_data2[i + 4] = -0.5;
   vertex_buffer_data2[i + 5] = 0;

   vertex_buffer_data2[i + 6] = 0;
   vertex_buffer_data2[i + 7] = -0.20;
   vertex_buffer_data2[i + 8] = 0;


     vertex_buffer_data2[i+9] = 0.6;
     vertex_buffer_data2[i + 10] = -0.20;
     vertex_buffer_data2[i + 11] = 0;

     vertex_buffer_data2[i + 12] = 0.6;
     vertex_buffer_data2[i + 13] = -0.5;
     vertex_buffer_data2[i + 14] = 0;

     vertex_buffer_data2[i + 15] = 0;
     vertex_buffer_data2[i + 16] = -0.20;
     vertex_buffer_data2[i + 17] = 0;
     i+=18;

       vertex_buffer_data2[i] = 0;
       vertex_buffer_data2[i + 1] = 0.5;
       vertex_buffer_data2[i + 2] = 0;

       vertex_buffer_data2[i + 3] = 0.6;
       vertex_buffer_data2[i + 4] = 0.5;
       vertex_buffer_data2[i + 5] = 0;

       vertex_buffer_data2[i + 6] = 0;
       vertex_buffer_data2[i + 7] = 0.20;
       vertex_buffer_data2[i + 8] = 0;


         vertex_buffer_data2[i+9] = 0.6;
         vertex_buffer_data2[i + 10] = 0.20;
         vertex_buffer_data2[i + 11] = 0;

         vertex_buffer_data2[i + 12] = 0.6;
         vertex_buffer_data2[i + 13] = 0.5;
         vertex_buffer_data2[i + 14] = 0;

         vertex_buffer_data2[i + 15] = 0;
         vertex_buffer_data2[i + 16] = 0.20;
         vertex_buffer_data2[i + 17] = 0;
   }
this->object = create3DObject(GL_TRIANGLES, 570, vertex_buffer_data2, color, GL_FILL);
}

void Magnet::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    rotate = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Magnet::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}
/*
void Ball::tick() {
  //  this->position.x -= this->speed_x;
  if(this->position.y <=-2 && this->flag_air == -1){
    this->position.y = -2;
    this->speed_y = 0;
    this->flag_air = 0;
  }
    this->position.y += this->speed_y;
}

bounding_box_t Ball::bounding_box() {
    float x = this->position.x, y = this->position.y;
    bounding_box_t bbox = { x, y, 0.4, 0.4 };
    return bbox;
}
*/
