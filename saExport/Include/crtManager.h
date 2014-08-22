#ifndef _CRTMANAGER_H_
#define _CRTMANAGER_H_

#include "baseTemplate.h"
#include "crtIFileSystem.h"

namespace FOXSDK
{
	class crtManager 
	{
	public:
 
		static fvoid				Init();
		static fvoid				Release();

		static crtIFileSystem*		GetFileSystem();
	};

};


#endif

