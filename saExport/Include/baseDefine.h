#ifndef _BASEDEFINE_H_
#define _BASEDEFINE_H_

#include "baseSTLLib.h"


// assert
#include <assert.h>

// #ifdef _DEBUG
// #undef assert
// #define assert(_Expression)			((void)0)
// #endif


#ifdef FOXSDK_DIRECT9
	#include <d3d9.h>
	#include <d3dx9.h>
#endif

#ifdef FOXSDK_OPENGL
#endif


#include <stdint.h>

	typedef int64_t					fint64;

	typedef wchar_t						fwchar;

	typedef char						fbyte;
	typedef unsigned char				fubyte;

	typedef short						fint16;
	typedef unsigned short				fuint16;

	typedef int							fint32;
	typedef unsigned int				fuint32;

	typedef long						flong;
	typedef unsigned long				fulong;

	typedef void						fvoid;

	typedef float						freal32;
	typedef double						freal64;

	typedef int							fbool;

	#define F_TRUE 1
	#define F_FALSE 0
	#define F_NULL 0

	#ifdef FOXSDK_USE_INLINE
		#define FINLINE inline
	#else
		#define FINLINE
	#endif

	#define F_MAX_NAME 32
	#define F_MAX_PATH 256

	#ifndef F_SAFE_FREE
			#define F_SAFE_FREE(a)	if (a) {free(a); (a)=F_NULL;}
		#endif
	#ifndef F_SAFE_RELEASE
		#define F_SAFE_RELEASE(a)	if (a) {(a)->Release(); (a)=F_NULL;}
	#endif

	#ifndef F_SAFE_DELETE
		#define F_SAFE_DELETE(a)	if (a) {delete (a); (a)=F_NULL;}
	#endif
	#ifndef F_SAFE_DELETE_ARRAY
		#define F_SAFE_DELETE_ARRAY(a)	if (a) {delete[] (a); (a)=F_NULL;}
	#endif

	//DLL
	#ifdef _USRDLL
		#define FOXSDK_DLL __declspec(dllexport)
	#else
		#define FOXSDK_DLL
	#endif


#endif


