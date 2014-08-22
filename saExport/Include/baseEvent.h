#ifndef _BASEEVENT_H_
#define _BASEEVENT_H_

#include "baseDefine.h"


namespace FOXSDK
{

	class baseEvent
	{
	public:

		fvoid			SetID( fint32 id )
		{
			mID = id;
		}

		fint32			GetID() const
		{
			return mID;
		}

	protected:

		fint32			mID;
	};



	typedef fvoid (*GameEventCallBack)( baseEvent* event );


	typedef map< fint32 , GameEventCallBack >				ListenerByIDMap;
	typedef map< fint32 , GameEventCallBack >::iterator		ListenerByIDIter;


	class BaseEventDispatcher
	{
	public:

		fvoid			AddEventListener( fint32 id , GameEventCallBack fun )
		{
			mListenerByID[ id ] = fun;
		}

		fvoid			RemoveEventListener( fint32 id )
		{
			ListenerByIDIter iter = mListenerByID.find( id );

			if ( iter != mListenerByID.end() )
			{
				mListenerByID.erase( iter );
			}
		}

		fvoid			FireEvent( baseEvent* event )
		{
			ListenerByIDIter iter = mListenerByID.find( event->GetID() );

			if ( iter != mListenerByID.end() )
			{
				(iter->second)( event );
			}
		}

		fvoid			Release()
		{
			mListenerByID.clear();
		}


	protected:

		map< fint32 , GameEventCallBack > mListenerByID;

	};




};


#endif


