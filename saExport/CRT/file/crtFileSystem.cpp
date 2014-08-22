#include "crtFileSystem.h"
#include "crtReadFile.h"
#include "crtWriteFile.h"

#include "crtResManager.h"

using namespace FOXSDK;

#ifdef WIN32
#include <direct.h> // for _chdir
#endif

#if (defined(LINUX))
#include <unistd.h>
#endif


crtFileSystem::crtFileSystem()
{
}

crtFileSystem::~crtFileSystem()
{

}

fvoid					crtFileSystem::Release()
{
	delete mThis;
	mThis = NULL;
}

crtIReadFile*			crtFileSystem::CreateAndOpenFile( const fbyte* filename )
{
	crtIReadFile* file = 0;

	file = (crtReadFile*)crtResManager::Instance()->GetRes( CRTRT_READFILE );
	file->Init( filename );

	return file;
}

crtIWriteFile*		crtFileSystem::CreateAndWriteFile( const fbyte* filename , fbool append /* = F_FALSE */ )
{
	crtIWriteFile* pfile = (crtWriteFile*)crtResManager::Instance()->GetRes( CRTRT_WRITEFILE );
	pfile->Init(filename , append);

	return pfile;
}


const fbyte*		crtFileSystem::GetWorkingDirectory()
{
#ifdef WIN32
	_getcwd(mWorkingDirectory , FILE_SYSTEM_MAX_PATH);
#endif

#if (defined(LINUX))
	getcwd(mWorkingDirectory, (size_t)FILE_SYSTEM_MAX_PATH);
#endif
	return mWorkingDirectory;
}


//! Changes the current Working Directory to the string given.
//! The string is operating system dependent. Under Windows it will look
//! like this: "drive:\directory\sudirectory\"
//! \return
//! Returns true if successful, otherwise false.
fbool				crtFileSystem::ChangeWorkingDirectoryTo( const fbyte* directory )
{
// 	fbool success = F_FALSE;
// 
// #ifdef WIN32
// 	success = (_chdir(directory) == 0);
// #endif
// 
// #if (defined(LINUX))
// 	success = (chdir(directory) != 0);
// #endif

//	return success;

	// no use
	return F_FALSE;
}

fbool				crtFileSystem::ExistFile( const fbyte* filename )
{
	FILE* f = fopen(filename, "rb");
	
	if (f) 
	{
		fclose(f);
		return F_TRUE;
	}

	return F_FALSE;
}
