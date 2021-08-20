// TrainingFramework.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../Utilities/utilities.h" // if you use STL, please include this line AFTER all other include
#include "Globals.h"
#include "SceneManager.h"
#include "ResourcesManager.h"
#include <conio.h>
#include <cstddef>
#include "Camera.h"
#include <memory>
int Init ( ESContext *esContext )
{
	glClearColor ( 1.0f, 1.0f, 1.0f, 1.0f );
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	char* SM = "../Resources/Managers/SM1.txt";
	char* MAP = "../Resources/Map/maplv1.txt";
	Singleton<SceneManager>::GetInstance()->SetFileManager(SM, MAP);
	printf("ok\n");
	Singleton<SceneManager>::GetInstance()->Init();
	printf("ok\n");

	return 0;
}

void Draw ( ESContext *esContext )
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	Camera::GetInstance()->i_state = 1;
	Singleton<SceneManager>::GetInstance()->Draw();
	eglSwapBuffers(esContext->eglDisplay, esContext->eglSurface);
}

void Update ( ESContext *esContext, float deltaTime )
{
	Singleton<SceneManager>::GetInstance()->Update(deltaTime);

}

void Key ( ESContext *esContext, unsigned char key, bool bIsPressed)
{
	Singleton<SceneManager>::GetInstance()->Key(key, bIsPressed);
}

void CleanUp()
{
	Singleton<SceneManager>::GetInstance()->CleanUp();
	Singleton<SceneManager>::GetInstance()->FreeInstance();
	ResourcesManager::getInstance()->clearMem();
	delete ResourcesManager::getInstance();
}

int _tmain(int argc, _TCHAR* argv[])
{
	ESContext esContext;

    esInitContext ( &esContext );

	esCreateWindow ( &esContext, "Hello Triangle", Globals::screenWidth, Globals::screenHeight, ES_WINDOW_RGB | ES_WINDOW_DEPTH);

	if ( Init ( &esContext ) != 0 )
		return 0;

	esRegisterDrawFunc ( &esContext, Draw );
	esRegisterUpdateFunc ( &esContext, Update );
	esRegisterKeyFunc ( &esContext, Key);

	esMainLoop ( &esContext );

	//releasing OpenGL resources
	CleanUp();

	//identifying memory leaks
	MemoryDump();
	printf("Press any key...\n");
	_getch();

	return 0;
}

