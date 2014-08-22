#ifndef _TINYXMLDOCUMENT_H_
#define _TINYXMLDOCUMENT_H_

#include "xmlElement.h"

#include "tinyxmlElement.h"


namespace FOXSDK
{

	class tinyxmlDocument : public xmlDocument
	{
	public:


		tinyxmlDocument();
		virtual ~tinyxmlDocument();

		virtual fvoid			Parse( const fbyte* data );

		virtual xmlElement*		Root();

		virtual fbool			Save( const fbyte* path ,  fbool utf8 = F_TRUE );
		virtual fbool			Load( const fbyte* path );

		virtual fvoid			SetValue( const fbyte* value );
		virtual const fbyte*	GetValue() const;

		virtual fvoid			Clear();

		virtual fvoid			InsertEndChild( const xmlNode& addThis );
		virtual fvoid			LinkEndChild( xmlNode* addThis );

		fvoid					PushNode( xmlNode* node );
		fvoid					ClearNode();

		xmlNode*				GetNode( TiXmlNode* node );


	protected:

		fbool				mLoad;

		tinyxmlElement		mRoot;

		TiXmlDocument		mTiXmlDocument;

		map< TiXmlNode* , xmlNode* >		mNodes;
	};


};



#endif


