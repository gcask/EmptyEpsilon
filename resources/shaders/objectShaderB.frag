#version 120
//Simple per-pixel light shader.

const vec4 light_position = vec4(20000., 20000., 20000., 1.0);

// Program inputs
uniform sampler2D baseMap;
uniform vec4 color;

// Per-fragment inputs
varying vec3 fragnormal;
varying vec3 viewspace_position;
varying vec2 fragtexcoords;

void main()
{
	vec3 lightDir = normalize(vec3(light_position) - viewspace_position);
	float intensity = max(0.1, dot(lightDir, fragnormal));
	
	vec3 base = texture2D(baseMap, fragtexcoords.st).rgb;
	
	gl_FragColor = vec4((base * intensity), color.a);
}
