#ifndef _CRTFMEMORYREADFILE_H_
#define _CRTFMEMORYREADFILE_H_

#include "crtIReadFile.h"
#include "crtRes.h"


namespace FOXSDK
{
	class crtMemoryReadFile : public crtIReadFile , public crtRes
	{
	public:

		crtMemoryReadFile();
		~crtMemoryReadFile();

		fvoid						Release();

		virtual fvoid				Init( const fbyte* filename , fint32 areasize = 0 , crtIReadFile* file = F_NULL ){};

		virtual fvoid				Init( fvoid* memory , fint32 len , const fbyte* fileName , fbool deletememory );

		virtual fuint32				Read( fvoid* buffer , fint32 size );

		virtual fbool				Seek( fint32 finalpos , fbool relativemovement = F_FALSE );

		virtual fint32				GetSize();

		virtual fint32				GetPos();

		virtual const fbyte*		GetFileName();

		virtual fbool				IsOpen()
		{
			return F_TRUE;
		}

	private:

		string						mFileName;
		fvoid*						mBuffer;
		fint32						mLen;
		fint32						mPos;
		fbool						mDeleteMemory;

	};
};

#endif
