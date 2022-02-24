# HEModeler

MFC based package program

- Window 10 Pro
- Visual studio 2019

## Project 구성

- HEModeler : Main Project
- HEM_LIB : HEM (HEModeler) Library Project
- HEM_RENDER : HEM (HEModeler) Render Project

## Library 구성

- openGL

### GLM (OpenGL Mathematics)

Build 를 하지 않고 glm 파일만 include 시키면 사용할 수 있다.

**header** 를 추가하는 방법은 속성 > c/c++ > 추가 포함 디렉터리에 glm 폴더를 참조로 추가하면 된다.

- GLM v0.9.9.8
- Attached on 22/02/24

### GLFW (OpenGL FrameWork)

개발환경 설정은 header 와 library 를 추가해야 한다. header 는 x86/x64 가 공용으로 사용하고 있으며, library는 비트에 따라 구분되어 진다.

**header** 를 추가하는 방법은 속성 > c/c++ > 추가 포함 디렉터리에 GLFW 폴더를 참조로 추가하면 된다. **Library** 는 static link 를 이용할 경우 glfw3.lib 를 추가하고 프로그램 실행 시 exe 와 동일한 경로에 glfw3.dll 을 추가해야 한다.

- GLFW v3.3.6
- Attached on 22/02/24

### GLEW (OpenGL Extension Wrangler)

개발환경 설정은 c++ 버전에 따라 visual studio 를 실행하여 build 후 dll/lib 를 생성해야 한다. 생성된 library 와 header 를 해당 비트에 맞춰 추가해야 한다.

**header** 를 추가하는 방법은 속성 > c/c++ > 추가 포함 디렉터리에 GL 폴더를 참조로 추가하면 된다. **Library** 는 static link 를 이용할 경우 glew32.lib 를 추가하고 프로그램 실행 시 exe 와 동일한 경로에 glew32.dll 을 추가해야 한다.

- GLEW v2.2.0
- Attached on 22/02/24
