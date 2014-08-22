#ifndef _CRTFREADFILE_H_
#define _CRTFREADFILE_H_

#include "crtIReadFile.h"
#include "crtRes.h"

namespace FOXSDK
{
	class crtReadFile : public crtIReadFile , public crtRes
	{
	public:

		crtReadFile();
		virtual ~crtReadFile();

		fvoid					Release();

		virtual fvoid			Init( const fbyte* filename , fint32 areasize = 0 , crtIReadFile* name = F_NULL );

		virtual fvoid			Init( fvoid* memory , fint32 len , const fbyte* fileName , fbool deletememory){};

		virtual fuint32			Read( fvoid* buffer , fint32 size );

		virtual fbool			Seek( fint32 finalpos , fbool relativemovement = F_FALSE );

		virtual fint32			GetSize();

		virtual fint32			GetPos();

		virtual const fbyte*	GetFileName();

		virtual fbool			IsOpen()
		{
			return mFile != 0;
		}

	private:


		fvoid					OpenFile();	

		string					mFileName;
		FILE*					mFile;
		fint32					mFileSize;
	};

};


#endif

