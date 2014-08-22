#ifndef _CRTFFILESYSTEM_H_
#define _CRTFFILESYSTEM_H_

#include "crtIFileSystem.h"
#include "crtIReadFile.h"
#include "crtIWriteFile.h"

#include "baseTemplate.h"

namespace FOXSDK
{
	class crtPakReader;

	#define FILE_SYSTEM_MAX_PATH 256

	class crtFileSystem : public crtIFileSystem , public baseSingle<crtFileSystem>
	{
	public:

		fvoid						Release();

		virtual crtIReadFile*		CreateAndOpenFile( const fbyte* filename );

		virtual crtIWriteFile*		CreateAndWriteFile( const fbyte* filename , fbool append = F_FALSE );

		virtual const fbyte*		GetWorkingDirectory();

		virtual fbool				ChangeWorkingDirectoryTo( const fbyte* directory );

		virtual fbool				ExistFile( const fbyte* filename );

		crtFileSystem();
		~crtFileSystem();

	private:

		fbyte						mWorkingDirectory[FILE_SYSTEM_MAX_PATH];
	};
};

#endif
