#ifndef _CRTRESCACHE_H_
#define _CRTRESCACHE_H_

#include "crtRes.h"


namespace FOXSDK
{
	#define MAX_CACHE 32

	// res cache
	class crtResCache
	{
	public:

		crtResCache();
		~crtResCache();

		fvoid				Push(crtRes* pt);

		crtRes*				GetData()
		{
			for ( vector<crtRes*>::iterator iter = mData.begin() ; iter != mData.end() ; iter++ )
			{
				if ( (*iter)->IsEnable() )
					return (*iter);
			}

			return F_NULL;
		}

	protected:

	private:

		vector<crtRes*> mData;
	};

};



#endif

