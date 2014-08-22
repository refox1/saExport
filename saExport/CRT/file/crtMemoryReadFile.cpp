#include "crtMemoryReadFile.h"

#include "crtManager.h"

using namespace FOXSDK;

crtMemoryReadFile::crtMemoryReadFile() :
	mBuffer(0) ,
	mLen(0) ,
	mPos(0) ,
	mDeleteMemory(false)
{
}

crtMemoryReadFile::~crtMemoryReadFile()
{}

fvoid				crtMemoryReadFile::Init( fvoid* memory , fint32 len , const fbyte* fileName , fbool deletememory )
{
	mBuffer = memory;
	mLen = len;
	mPos = 0;
	mDeleteMemory = deletememory;

	mFileName = fileName;
}

fvoid				crtMemoryReadFile::Release()
{
	if (mDeleteMemory)
		delete [] mBuffer;

	crtRes::Release();
}

fuint32				crtMemoryReadFile::Read( fvoid* buffer , fint32 size )
{
	fint32 amount = size;
	if (mPos + amount > mLen)
		amount -= mPos + amount - mLen;

	if (amount < 0)
		amount = 0;

	fbyte* p = (fbyte*)mBuffer;
	memcpy( buffer , p + mPos , amount );

	mPos += static_cast<fuint32> (amount);

	return amount;
}

fbool				crtMemoryReadFile::Seek( fint32 finalpos , fbool relativemovement /* = F_FALSE */ )
{
	if (relativemovement)
	{
		if (mPos + finalpos > mLen)
			return F_FALSE;

		mPos += finalpos;
	}
	else
	{
		if ( finalpos > mLen)
			return F_FALSE;

		mPos = finalpos;
	}

	return F_TRUE;
}

fint32				crtMemoryReadFile::GetSize()
{
	return mLen;
}

fint32				crtMemoryReadFile::GetPos()
{
	return mPos;
}

const fbyte*		crtMemoryReadFile::GetFileName()
{
	return mFileName.c_str();
}
