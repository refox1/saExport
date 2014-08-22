#ifndef _CRTIREADFILE_H_
#define _CRTIREADFILE_H_

#include "baseDefine.h"

namespace FOXSDK
{
	class FOXSDK_DLL crtIReadFile
	{
	public:

		virtual fvoid			Release() = 0;

		virtual fvoid			Init( const fbyte* filename , fint32 areasize = 0 , crtIReadFile* file = F_NULL ) = 0;

		virtual fvoid			Init( fvoid* memory , fint32 len , const fbyte* fileName , fbool deletememory ) = 0;

		virtual fuint32			Read( fvoid* buffer , fint32 size ) = 0;

		virtual fbool			Seek( fint32 finalPos , fbool relativeMovement = F_FALSE ) = 0;

		virtual fint32			GetSize() = 0;

		virtual fint32			GetPos() = 0;

		virtual const fbyte*	GetFileName() = 0;

		virtual fbool			IsOpen() = 0;
	};

};


#endif
