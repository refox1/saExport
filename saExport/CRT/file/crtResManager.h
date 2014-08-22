#ifndef _RESMANAGER_H_
#define _RESMANAGER_H_

#include "crtResCache.h"

#include "crtLimitReadFile.h"
#include "crtMemoryReadFile.h"
#include "crtPakReader.h"
#include "crtReadFile.h"
#include "crtWriteFile.h"

#include "baseTemplate.h"

namespace FOXSDK
{
	class crtResManager : public baseSingle<crtResManager>
	{
	public:

		void Release();

		crtRes* GetRes(crtResType type);

		crtResManager();
		~crtResManager();

	protected:
	private:

		crtResCache m_Cache[CRTRT_COUNT];
	};

};

#endif
