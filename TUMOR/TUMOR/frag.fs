#version 330 core

uniform int index;
// Ouput data
out vec4 color;

void main(){

	// Output color = color specified in the vertex shader, 
	// interpolated between all 3 surrounding vertices
    if (index == 0)
	    color = vec4(1.0, 0.0, 0.0, 0.3);
    if (index == 1)
	    color = vec4(0.0, 1.0, 0.0, 0.3);
    if (index == 2)
	    color = vec4(0.0, 0.0, 1.0, 0.3);

}