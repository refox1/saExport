#ifndef _CRTFLIMITREADFILE_H_
#define _CRTFLIMITREADFILE_H_

#include "crtIReadFile.h"
#include "crtRes.h"

namespace FOXSDK
{
	class crtLimitReadFile : public crtIReadFile , public crtRes
	{
	public:

		crtLimitReadFile();
		 ~crtLimitReadFile();

		virtual fvoid				Release();

		virtual fvoid				Init( const fbyte* filename , fint32 areasize = 0 , crtIReadFile* file = F_NULL );

		virtual fvoid				Init( fvoid* memory , fint32 len , const fbyte* fileName , fbool deletememory ){};

		virtual fuint32				Read( fvoid* buffer, fint32 size );

		virtual fbool				Seek( fint32 finalpos , fbool relativemovement = F_FALSE );

		virtual fint32				GetSize();

		virtual fint32				GetPos();

		virtual const fbyte*		GetFileName();

		virtual fbool				IsOpen()
		{
			return mFile != 0;
		}

	private:

		fvoid						Init();

		string						mFileName;
		fint32						mAreaSize;
		fint32						mAreaStart;
		fint32						mAreaEnd;
		crtIReadFile*				mFile;
	};

};


#endif
