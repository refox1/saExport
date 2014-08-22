#include "crtReadFile.h"
#include <stdio.h>

using namespace FOXSDK;

crtReadFile::crtReadFile()
:	mFileSize(0) , mFile(0)
{
}

crtReadFile::~crtReadFile()
{

}

fvoid				crtReadFile::Init( const fbyte* filename , fint32 areasize /* = 0  */, crtIReadFile* name /* = F_NULL */ )
{
	mFile = 0;
	mFileSize = 0;
	areasize;
	name;

	mFileName = filename;

	OpenFile();
}

fvoid				crtReadFile::Release()
{
	if (mFile)
	{
		fclose(mFile);
		mFile = 0;
	}

	crtRes::Release();
}

fuint32				crtReadFile::Read( fvoid* buffer , fint32 size )
{
	if ( !IsOpen() )
		return 0;

	return fread( buffer , 1 , size , mFile );
}


fbool				crtReadFile::Seek(fint32 finalpos , fbool relativemovement /* = F_FALSE */)
{
	if ( !IsOpen() )
		return false;

	return fseek( mFile , finalpos , relativemovement ? SEEK_CUR : SEEK_SET ) == 0;
}

fint32				crtReadFile::GetSize()
{
	return mFileSize;
}

fint32				crtReadFile::GetPos()
{
	if ( !IsOpen() )
		return 0;

	return ftell( mFile );
}


fvoid				crtReadFile::OpenFile()
{
	if ( mFileName.empty() )
	{
		mFile = 0;
		return; 
	}

	mFile = fopen( mFileName.c_str(), "rb" );

	if ( mFile )
	{
		fseek( mFile , 0 , SEEK_END );
		mFileSize = ftell( mFile );
		fseek( mFile , 0 , SEEK_SET );
	}
}

const fbyte* crtReadFile::GetFileName()
{
	return mFileName.c_str();
}

