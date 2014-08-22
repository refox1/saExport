#include "crtWriteFile.h"

using namespace FOXSDK;

crtWriteFile::crtWriteFile():	
	mFile(0) , 
	mFileSize(0) 
{

}

crtWriteFile::~crtWriteFile()
{

}

fvoid			crtWriteFile::Init( const fbyte* filename , fbool append )
{
	mFileSize = 0; 
	mFile = 0;

	mFileName = filename;

	OpenFile( append );
}

fvoid			crtWriteFile::Release()
{	
	if ( mFile )
	{
		fclose( mFile );
		mFile = 0;
	}

	crtRes::Release();
}

fuint32			crtWriteFile::Write( const fvoid* buffer, fint32 size )
{
	if ( !IsOpen() )
		return 0;

	return fwrite( buffer , 1 , size , mFile );
}

fbool			crtWriteFile::Seek( fint32 finalpos , fbool relativemovement )
{
	if ( !IsOpen() )
		return false;

	return fseek( mFile , finalpos , relativemovement ? SEEK_CUR : SEEK_SET ) == 0;
}

fbool			crtWriteFile::Delete( fint32 delpos , fint32 dellen )
{
	if (!IsOpen())
		return F_FALSE;

	//Î´Íê³É

	return F_TRUE;
}

fint32			crtWriteFile::GetPos()
{
	if ( !IsOpen() )
		return 0;

	return ftell( mFile );
}

fvoid			crtWriteFile::OpenFile( fbool append )
{
	if ( mFileName.empty() )
	{
		mFile = 0;
		return; 
	}

	mFile = fopen( mFileName.c_str() , append ? "ab" : "wb" );

	if ( mFile )
	{
		fseek( mFile , 0 , SEEK_END );
		mFileSize = ftell( mFile );
		fseek( mFile , 0 , SEEK_SET );
	}
}

const fbyte*	crtWriteFile::GetFileName()
{
	return mFileName.c_str();
}
