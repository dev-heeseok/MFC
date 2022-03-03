# HEModeler

MFC based package program

- Window 10 Pro
- Visual studio 2019

## Project 구성

- HEModeler : 메인 프로젝트
- HE_LIB : Library 프로젝트
- HE_WGL : WGL 관리 프로젝트
- HE_RENDER : Render 관리 프로젝트
- HE_BASE : 기반 프로젝트
- HEM_UI : UI 관리 프로젝트

### 리소스 관리

프로젝트별 Resource 관리를 위해 ID 의 범위를 지정하여 사용한다.

#### _APS_NEXT_RESOURCE_VALUE

IDD_XXX, IDB_XXX, IDR_XXX ... (1~28,671)

- 1~4999 : HEModeler 프로젝트
- 5000~9999 : HEM_UI 프로젝트
- 10000~14999 : HE_WGL 프로젝트
- 15000~19999
- 20000~28671

#### _APS_NEXT_COMMAND_VALUE

ID_XXX, ... (32,768~57,343)

- 32768~34999 : HEModeler 프로젝트
- 35000~39999 : HEM_UI 프로젝트
- 40000~44999 : HE_WGL 프로젝트
- 45000~50000
- 50000~57343

#### _APS_NEXT_CONTROL_VALUE

IDC_XXX, ... (8~57,343)

- 8~9999 : HEModeler 프로젝트
- 10000~19999 : HEM_UI 프로젝트
- 20000~29999 : HE_WGL 프로젝트
- 30000~39999
- 40000~49999
- 50000~57343

#### _APS_NEXT_SYMED_VALUE

ID_XXX, ... (32,768~57,343)

- 32768~34999 : HEModeler 프로젝트
- 35000~39999 : HEM_UI 프로젝트
- 40000~44999 : HE_WGL 프로젝트
- 45000~50000
- 50000~57343

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
