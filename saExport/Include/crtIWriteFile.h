#ifndef _CRTIWRITEFILE_H_
#define _CRTIWRITEFILE_H_

#include "baseDefine.h"

namespace FOXSDK
{
	class FOXSDK_DLL crtIWriteFile
	{
	public:

		virtual fvoid				Release() = 0;

		virtual fvoid				Init( const fbyte* filename , fbool append ) = 0;

		virtual fuint32				Write( const fvoid* buffer , fint32 size ) = 0;

		virtual fbool				Delete( fint32 delpos , fint32 dellen ) = 0;

		virtual fbool				Seek( fint32 finalpos , fbool relativeMovement = F_FALSE ) = 0;

		virtual fint32				GetPos() = 0;

		virtual const fbyte*		GetFileName() = 0;

		virtual fbool				IsOpen() = 0;
	};

};

#endif


