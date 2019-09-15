#include <windows.h>
#include <GL/gl.h>
#include "glext.h"

// Linkare con Crinkler

const GLchar *fragshd= ""
 "uniform float v;"
 "float n(vec3 z) {"
   "float s=1.,i=v*.0003,c=2196.43;"
   "vec3 n=vec3(cos(2.*c)*cos(c),sin(c),sin(2.*c)*cos(c));"
   "float r=cos(i),y=sin(i);"
   "vec3 f=n*y,d=n*n*(1.-r),o=n.yzx*n.zxy*(1.-r);"
   "mat3 x=mat3(r+d.x,o.z-f.z,o.y+f.y,o.z+f.z,r+d.y,o.x-f.x,o.y-f.y,o.x+f.x,r+d.z)*1.26;"
   "for(int m=0;m<30;m++)"
     "z*=x,z.z=abs(z.z)-5.04,s*=1.28;"
	 "return(length(z)-2.)/s;}"
 "void main(){"
   "vec2 x=vec2(700.);"
   "vec3 c=vec3(0.,0.,-30.),o=normalize(vec3((gl_FragCoord.xy-x*.5)/x,1.)),r;"
   "for(int m=0;m<32;m++){"
       "float v=n(c);"
       "c+=v*o;"
       "r+=vec3(1./(1.+v),1./(1.+v*v),1./(1.+v*v*v))*v;}"
   "gl_FragColor=vec4(vec3(1./r/(1.+n(c))),1.);}";


static PIXELFORMATDESCRIPTOR pfd;

void WINAPI wMainCRTStartup()
{
	pfd.cColorBits = pfd.cDepthBits = 32;
	pfd.dwFlags    = PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	HDC hdc = GetDC( CreateWindow("edit", 0, WS_POPUP|WS_VISIBLE|WS_BORDER, 300, 150, 700, 700, 0, 0, 0, 0) );
	SetPixelFormat(hdc, ChoosePixelFormat ( hdc, &pfd), &pfd);
	wglMakeCurrent ( hdc, wglCreateContext(hdc) );

	GLuint p;
	p=((PFNGLCREATESHADERPROGRAMVPROC)wglGetProcAddress("glCreateShaderProgramv"))(GL_FRAGMENT_SHADER, 1, /*(const GLchar**)*/(&fragshd));
	((PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram"))(p);
	PFNGLUNIFORM1FPROC glUniform1f = ((PFNGLUNIFORM1FPROC)wglGetProcAddress("glUniform1f"));
	ShowCursor(FALSE);

	long t,t0 = timeGetTime();

	do {
		t= (long)timeGetTime() - t0;
		glUniform1f(0, (float)t);
		glRecti(-1,-1,1,1);
		SwapBuffers(hdc);
	} while ( !GetAsyncKeyState(VK_ESCAPE) );
	ExitProcess(0);

}