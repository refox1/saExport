#ifndef _TINYXMLCOMMENT_H_
#define _TINYXMLCOMMENT_H_



#include "xmlElement.h"
#include "tinyxml/tinyxml.h"
#include "tinyxmlDocument.h"

namespace FOXSDK
{

	class tinyxmlComment : public xmlComment
	{
	public:

		friend class tinyxmlDocument;
		friend class tinyxmlElement;

		tinyxmlComment( tinyxmlDocument& doc , const fbyte* value );
		virtual ~tinyxmlComment();

		virtual fvoid				SetValue( const fbyte* value );
		virtual const fbyte*		GetValue() const;

		virtual fvoid				InsertEndChild( const xmlNode& addThis );
		virtual fvoid				LinkEndChild( xmlNode* addThis );


	protected:

		TiXmlComment*				mTinyComment;

		tinyxmlDocument&			mDoc;
	};
};

#endif


