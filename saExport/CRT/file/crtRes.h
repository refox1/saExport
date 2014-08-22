#ifndef _CRTRES_H_
#define _CRTRES_H_

#include "baseDefine.h"

namespace FOXSDK
{
	enum crtResType
	{
		CRTRT_WRITEFILE,
		CRTRT_READFILE,
		CRTRT_MEMORYREADFILE,
		CRTRT_LIMITREADFILE,
		//CRTRT_ZIPREADER,
		//RT_PAKREADER,

		CRTRT_COUNT
	};

	//this res not use refCounter

	class crtRes
	{
	public:

		crtRes(){}
		virtual ~crtRes(){};

		virtual fvoid		Release()
		{
			mEnable = true;
		}

		fbool				IsEnable()
		{
			return mEnable;
		}

		fvoid				SetEnable(fbool b)
		{
			mEnable = b;
		}

		crtResType			GetType()
		{
			return mType;
		}

	protected:

		crtResType			mType;
		fbool				mEnable;

	};
};



#endif
