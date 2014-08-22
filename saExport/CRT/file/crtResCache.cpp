#include "crtResCache.h"

using namespace FOXSDK;

crtResCache::crtResCache()
{
	mData.reserve(MAX_CACHE);
}

crtResCache::~crtResCache()
{
	for (vector<crtRes*>::iterator iter = mData.begin() ; iter != mData.end() ; iter++)
	{
		(*iter)->Release();
		delete *iter;
	}
}

fvoid		crtResCache::Push(crtRes* pt)
{
	mData.push_back(pt);
}
