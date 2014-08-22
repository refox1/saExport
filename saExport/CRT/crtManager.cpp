#include "crtManager.h"

#include "./file/crtResManager.h"
#include "./file/crtFileSystem.h"


namespace FOXSDK
{
    fvoid				crtManager::Init()
	{
		crtResManager::Instance();
		crtFileSystem::Instance();
	}


	fvoid				crtManager::Release()
	{
		crtFileSystem::Instance()->Release();
		crtResManager::Instance()->Release();
	}


	crtIFileSystem*		crtManager::GetFileSystem()
	{
		return crtFileSystem::Instance();
	}


};


