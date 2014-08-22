#ifndef _BASETEMPLATE_H_
#define _BASETEMPLATE_H_

#include "baseDefine.h"


namespace FOXSDK
{
	template<class T> class baseSingle
	{
	public:
		static T* Instance()
		{
			if (!mThis)
				mThis = new T;

			return mThis;
		}

		static T* mThis;
	};

	template<typename T> 
	T* baseSingle<T>::mThis = 0;

};



#endif


