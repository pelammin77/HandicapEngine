 

//layout(location = 0 ) in vec4 position;
/*
uniform mat4 pMatrix;
uniform mat4 vMatrix;
uniform mat4 nlMatrix;
  
void main()
{
 gl_position = position;

} 
*/

void main(void)
{
  
   vec4 a = gl_Vertex;
   a.x = a.x * 1;
   a.y = a.y*1 ;


   gl_Position = gl_ModelViewProjectionMatrix * a;

}       

