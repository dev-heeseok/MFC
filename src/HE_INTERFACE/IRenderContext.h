#pragma once

class IRenderContext
{
public:
	virtual void wglBind() = 0;
	virtual void wglUnbind() = 0;
	virtual void wglSwapBuffer() = 0;

};