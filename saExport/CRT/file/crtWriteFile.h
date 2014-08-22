#ifndef _CRTFWRITEFILE_H_
#define _CRTFWRITEFILE_H_

#include "crtIWriteFile.h"
#include "crtRes.h"

namespace FOXSDK
{
	class crtWriteFile : public crtIWriteFile , public crtRes
	{
	public:

		crtWriteFile();
		virtual ~crtWriteFile();

		fvoid					Release();

		virtual fvoid			Init( const fbyte* filename , fbool append );

		virtual fuint32			Write( const fvoid* buffer, fint32 size );

		virtual fbool			Seek( fint32 finalpos , fbool relativemovement = F_FALSE );

		virtual fbool			Delete( fint32 delpos , fint32 dellen );

		virtual fint32			GetPos();

		virtual const fbyte*	GetFileName();

		virtual fbool			IsOpen()
		{
			return mFile != 0;
		}

	private:

		fvoid					OpenFile( fbool append );	

		string					mFileName;
		FILE*					mFile;
		fint32					mFileSize;
	};
};

#endif
