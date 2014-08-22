#include "crtResManager.h"

using namespace FOXSDK;

void			crtResManager::Release()
{
	delete mThis;
	mThis = NULL;
}

crtRes*			crtResManager::GetRes(crtResType type)
{
	crtRes* p = m_Cache[type].GetData();

	if (!p)
	{
		assert(0);
	}

	p->SetEnable(false);

	return p;
}

crtResManager::crtResManager()
{
	for (int i = 0 ; i < CRTRT_COUNT ; i++)
	{
		crtRes* p = F_NULL;

		for (int j = 0 ; j < MAX_CACHE ; j++)
		{
			switch(i)
			{
			case CRTRT_WRITEFILE:
				p = new crtWriteFile();
				break;
			case CRTRT_READFILE:
				p = new crtReadFile();
				break;
			case CRTRT_MEMORYREADFILE:
				p = new crtMemoryReadFile();
				break;
			case CRTRT_LIMITREADFILE:
				p = new crtLimitReadFile();
				break;
			}

			p->SetEnable(true);

			m_Cache[i].Push(p);
		}
	}
}

crtResManager::~crtResManager()
{

}

