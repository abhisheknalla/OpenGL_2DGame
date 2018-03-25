#include "ball.h"
#include "main.h"
#define PI 3.14159

Ball::Ball(float x, float y, color_t color, float speed_x, float speed_y) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->speed_x = speed_x;
    this->speed_y = speed_y;
    this->flag_air = 0;
    this->pond_flag = 0;
    GLfloat g_vertex_buffer_data[3240] = {};
  	    double angle = 0.0;
  	    int i;
  	for(i=0;i<3240;){
  	    g_vertex_buffer_data[i] = (0.4 * cos(angle) - 0.0 * sin(angle));
  	    g_vertex_buffer_data[i + 1] = (0.4 * sin(angle) + 0.0 * cos(angle));
  	    g_vertex_buffer_data[i + 2] = 0;

  	    g_vertex_buffer_data[i + 3] = (0.4 * cos(angle + PI/180) - 0.0 * sin(angle + PI/180));
  	    g_vertex_buffer_data[i + 4] = (0.4 * sin(angle + PI/ 180) + 0.0 * cos(angle + PI/ 180));
  	    g_vertex_buffer_data[i + 5] = 0;

  	    g_vertex_buffer_data[i + 6] = 0;
  	    g_vertex_buffer_data[i + 7] = 0;
  	    g_vertex_buffer_data[i + 8] = 0;
  			i+=9;
  	    angle = PI/180 + angle;
  	}

    /*static const GLfloat vertex_buffer_data[] = {
        -0.2, -0.2, 0, // vertex 1
        0.2,  -0.2, 0, // vertex 2
        0.2,  0.2, 0, // vertex 3

        0.2,  0.2, 0, // vertex 3
        -0.2, 0.2, 0, // vertex 4
        -0.2, -0.2, 0 // vertex 1
    };*/

    this->object = create3DObject(GL_TRIANGLES, 1080, g_vertex_buffer_data, color, GL_FILL);
  }

void Ball::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    rotate          = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Ball::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Ball::tick() {
  if((this->position.x <= 1 && this->position.x >=-1) && this->position.y <= -2.0)
  {
  //  if(this->position.x <= 1 && this->position.x > 0.9)
  //    this->position.x = 0.8;

//    this->speed_y = 0.1;
    this->speed_x=0;
    float speedo = 0.1;
  //if(this->.position.x<=0.1 &&this->.position.x>=-0.1&&this->.position.y<=-2.75)
  //  this->.speed_x = 0.01;
    if(this->position.x < 0)
    {
      this->position.x += 0.01;//    move_flag=1;
    }
    if(this->position.x > 0)
    {
      this->position.x -= 0.01;
  //    move_flag=2;
    }
    float cx=this->position.x;
    float temp;
    if(cx > 4.3 && cx < 5.7)
      temp=1-((cx -0.7)*(cx-0.7));
    else
      temp =  1 - ((cx)*(cx));
    float tot = abs(sqrt(temp));

    this->position.y = -2.0 - tot;
    if(this->position.y > -2.35 &&  this->position.y <= -2.15 )
      this->position.y = -2.10;
    if(this->position.y > -2.15)
    {
      this->position.y = -2;
      this->speed_y=0;
    }
  }
  if((this->position.x <= 5.7 && this->position.x >=4.3) && this->position.y <= -2.0)
  {
  //  if(this->position.x <= 1 && this->position.x > 0.9)
  //    this->position.x = 0.8;

//    this->speed_y = 0.1;
    this->speed_x=0;
    float speedo = 0.1;
  //if(this->.position.x<=0.1 &&this->.position.x>=-0.1&&this->.position.y<=-2.75)
  //  this->.speed_x = 0.01;
    if(this->position.x < 5)
    {
      this->position.x += 0.01;//    move_flag=1;
    }
    if(this->position.x > 5)
    {
      this->position.x -= 0.01;
  //    move_flag=2;
    }
    float cx=this->position.x;
    float temp;
    temp=0.49-((cx-5)*(cx-5));
    float tot = abs(sqrt(temp));
    this->position.y = -2.0 - tot;
    if(this->position.y > -2.35 &&  this->position.y <= -2.15 )
      this->position.y = -2.10;
    if(this->position.y > -2.15)
    {
      this->position.y = -2;
      this->speed_y=0;
    }
  }

  //  this->position.x -= this->speed_x;
  if(this->position.y <=-2 && this->flag_air == -1){
    this->position.y = -2;
    this->speed_y = 0;
    this->flag_air = 0;
  }
  if(this->position.y <=-1.6 && this->position.x >= 1.5 && this->position.x <= 2.5 && this->flag_air==-1){
    this->speed_y += 0.5;
    printf("flag:%d",this->flag_air);
    this->flag_air = 1;
  }
  this->position.y += this->speed_y;

}

bounding_box_t Ball::bounding_box() {
    float x = this->position.x, y = this->position.y;
    bounding_box_t bbox = { x, y, 0.4 };
    return bbox;
}
