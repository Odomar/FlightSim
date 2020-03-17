#version 330

in vec3 vPosition_vs; // Position du sommet transformé dans l'espace View
in vec3 vNormal_vs; // Normale du sommet transformé dans l'espace View
in vec2 vTexCoords; // Coordonnées de texture du sommet

uniform sampler2D uTexture;

uniform vec3 uTextureKd;
uniform vec3 uTextureKs;
uniform float uTextureShininess;

uniform vec3 uLightDir_vs;
uniform vec3 uLightIntensity;
uniform vec3 uLightAmbient;

uniform vec3 uLightPos_vs;
uniform vec3 uPointLightIntensity;


out vec3 fFragColor;

vec3 blinnPhong() {
    vec3 hv = (normalize(-vPosition_vs) +  normalize(uLightDir_vs)) / 2.;
    float dotHvNormal = dot(hv, vec3(normalize(vNormal_vs)));
    float dot = dot(normalize(uLightDir_vs), normalize(vNormal_vs));
    if(dot < 0.) {
        dot = 0.;
    }
    return vec3(uLightIntensity * (uTextureKd * dot) + uTextureKs * dotHvNormal);
}

vec3 pointLight(){
	
	vec3 Ks = vec3(5, 5, 5);
	vec3 Kd = vec3(11, 11, 10);
	float Shininess = 128.;
	
    vec3 wo = normalize(-vPosition_vs);
    vec3 wi = normalize(uLightPos_vs - vPosition_vs);
    vec3 halfvector = normalize(( wo + wi) / 2.0 );
    float widotnormal = dot(wi,normalize(vNormal_vs));
    if (widotnormal < 0)  {
		widotnormal = 0;
	}
    float halfdotnormal = dot(halfvector, normalize(vNormal_vs));
    if (halfdotnormal < 0) {
		halfdotnormal = 0;
	}
    float d = distance(uLightPos_vs, vPosition_vs);
    return (uPointLightIntensity / (d * d) *(Kd * widotnormal + Ks * pow(halfdotnormal, Shininess)));
}

void main() {
	vec4 resTex = texture(uTexture, vTexCoords);
	vec3 ambiantColor = uLightAmbient * vec3(resTex);
	vec3 blinn = blinnPhong() * vec3(resTex);
	vec3 pl = pointLight() * vec3(resTex);
	vec3 color = blinn + ambiantColor + pl;
	fFragColor = vec3(min(color.x, resTex.x), min(color.y, resTex.y), min(color.z, resTex.z));
}
