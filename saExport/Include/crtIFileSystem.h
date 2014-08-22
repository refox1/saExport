#ifndef _CRTIFILESYSTEM_H_
#define _CRTIFILESYSTEM_H_

#include "baseDefine.h"

#include "crtIReadFile.h"
#include "crtIWriteFile.h"

namespace FOXSDK
{
	class FOXSDK_DLL crtIFileSystem
	{
	public:

		virtual crtIReadFile*		CreateAndOpenFile( const fbyte* filename ) = 0;

		virtual crtIWriteFile*		CreateAndWriteFile( const fbyte* filename , fbool append = false ) = 0;

		virtual const fbyte*		GetWorkingDirectory() = 0;

		virtual fbool				ChangeWorkingDirectoryTo( const fbyte* directory ) = 0;

		virtual fbool				ExistFile( const fbyte* filename ) = 0;
	};

};

#endif
