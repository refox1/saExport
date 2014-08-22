#include "crtLimitReadFile.h"

using namespace FOXSDK;

crtLimitReadFile::crtLimitReadFile()	
:	mFile(0) , 
	mAreaStart(0) , mAreaEnd(0) , mAreaSize(0)
{
}

crtLimitReadFile::~crtLimitReadFile()
{

}

fvoid				crtLimitReadFile::Init( const fbyte* filename , fint32 areasize /* = 0  */, crtIReadFile* file /* = F_NULL */ )
{	
	mAreaStart = 0;
	mAreaEnd = 0;

	mAreaSize = areasize;
	mFile = file;
	mFileName = filename;

	Init();
}

fvoid				crtLimitReadFile::Release()
{
	crtRes::Release();
}

fvoid				crtLimitReadFile::Init()
{
	if (!mFile)
		return;

	mAreaStart = mFile->GetPos();
	mAreaEnd = mAreaStart + mAreaSize;
}


fuint32				crtLimitReadFile::Read( fvoid* buffer, fint32 size )
{
	fint32 pos = mFile->GetPos();

	if (pos >= mAreaEnd)
		return 0;

	if (pos + size >= mAreaEnd)
		size = mAreaEnd - pos;

	return mFile->Read(buffer, size);
}

fbool				crtLimitReadFile::Seek( fint32 finalpos , fbool relativemovement /* = F_FALSE */ )
{
	fint32 pos = mFile->GetPos();

	if (relativemovement)
	{
		if (pos + finalpos > mAreaEnd)
			finalpos = mAreaEnd - pos;
	}
	else
	{
		finalpos += mAreaStart;
		if (finalpos > mAreaEnd)
			return false;
	}

	return mFile->Seek( finalpos , relativemovement );	
}

fint32				crtLimitReadFile::GetSize()
{
	return mAreaSize;
}

fint32				crtLimitReadFile::GetPos()
{
	return mFile->GetPos() - mAreaStart;
}

const fbyte*		crtLimitReadFile::GetFileName()
{
	return mFileName.c_str();
}

