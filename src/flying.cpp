#include "flying.h"
#include "main.h"
#define PI 3.14159
float size;
float prevx;
float prevy;
float prevspeed;
Flying::Flying(float x, float y, color_t color, float speed_x, float speed_y, float ball_size) {
    this->position = glm::vec3(x, y, 0);
    this->radius = ball_size;
    this->rotation = 0;
    this->speed_x = speed_x;
    this->speed_y = speed_y;
    this->flag_air = 0;
    size = ball_size;
    prevx = x;prevy=y;prevspeed = speed_x;
    int color_rand = (rand())%8;
    if(color_rand==0)
      color =  COLOR_RED;// = { 236, 100, 75 };
    if(color_rand==1)
      color = COLOR_GREEN;// = { 135, 211, 124 };
    if(color_rand==2)
      color = COLOR_BLACK;
    if(color_rand==3)
      color = COLOR_BROWN;
    if(color_rand==4)
      color = COLOR_SOIL;
    if(color_rand==5)
      color = COLOR_YELLOW;
    if(color_rand==6)
      color = COLOR_WATER;
    if(color_rand==7)
      color =  COLOR_ORANGE;
    GLfloat g_vertex_buffer_data[3240] = {};
  	    double angle = 0.0;
  	    int i;
  	for(i=0;i<3240;){
  	    g_vertex_buffer_data[i] = (ball_size * cos(angle) - 0.0 * sin(angle));
  	    g_vertex_buffer_data[i + 1] = (ball_size * sin(angle) + 0.0 * cos(angle));
  	    g_vertex_buffer_data[i + 2] = 0;

  	    g_vertex_buffer_data[i + 3] = (ball_size * cos(angle + PI/180) - 0.0 * sin(angle + PI/180));
  	    g_vertex_buffer_data[i + 4] = (ball_size * sin(angle + PI/ 180) + 0.0 * cos(angle + PI/ 180));
  	    g_vertex_buffer_data[i + 5] = 0;

  	    g_vertex_buffer_data[i + 6] = 0;
  	    g_vertex_buffer_data[i + 7] = 0;
  	    g_vertex_buffer_data[i + 8] = 0;
  			i+=9;
  	    angle = PI/180 + angle;
  	}
    this->object = create3DObject(GL_TRIANGLES, 1080, g_vertex_buffer_data, color, GL_FILL);

  }

void Flying::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    rotate          = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Flying::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Flying::tick(float speed, float sized) {
   this->position.x += this->speed_x;
  //    printf("POSBall: %lf \n",this->position.x);
   if(this->position.x >= 8){
    this->position.x = -4;
  //  this->position.y  = 0.5 + (rand()%3);
    this->speed_x = speed;
    int color_rand = (rand())%8;color_t color;
    if(color_rand==0)
      color =  COLOR_RED;// = { 236, 100, 75 };
    if(color_rand==1)
      color = COLOR_GREEN;// = { 135, 211, 124 };
    if(color_rand==2)
      color = COLOR_BLACK;
    if(color_rand==3)
      color = COLOR_BROWN;
    if(color_rand==4)
      color = COLOR_SOIL;
    if(color_rand==5)
      color = COLOR_YELLOW;
    if(color_rand==6)
      color = COLOR_WATER;
    if(color_rand==7)
      color =  COLOR_ORANGE;

  GLfloat g_vertex_buffer_data[3240] = {};
      double angle = 0.0;
      int i;
      size = sized;
  for(i=0;i<3240;){
      g_vertex_buffer_data[i] = (size * cos(angle) - 0.0 * sin(angle));
      g_vertex_buffer_data[i + 1] = (size * sin(angle) + 0.0 * cos(angle));
      g_vertex_buffer_data[i + 2] = 0;

      g_vertex_buffer_data[i + 3] = (size * cos(angle + PI/180) - 0.0 * sin(angle + PI/180));
      g_vertex_buffer_data[i + 4] = (size * sin(angle + PI/ 180) + 0.0 * cos(angle + PI/ 180));
      g_vertex_buffer_data[i + 5] = 0;

      g_vertex_buffer_data[i + 6] = 0;
      g_vertex_buffer_data[i + 7] = 0;
      g_vertex_buffer_data[i + 8] = 0;
      i+=9;
      angle = PI/180 + angle;
  }
  this->object = create3DObject(GL_TRIANGLES, 1080, g_vertex_buffer_data, color, GL_FILL);
  }
}

bounding_box_t Flying::bounding_box() {
    float x = this->position.x, y = this->position.y;
    //bounding_box_t bbox = { x, y, 0.4, 0.4 };
    bounding_box_t bbox = { x, y, size };
    return bbox;
}
