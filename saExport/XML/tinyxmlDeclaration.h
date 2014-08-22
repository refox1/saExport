#ifndef _TINYXMLDECLARATION_H_
#define _TINYXMLDECLARATION_H_

#include "xmlElement.h"
#include "tinyxml/tinyxml.h"

namespace FOXSDK
{

	class tinyxmlDeclaration : public xmlDeclaration
	{
	public:

		friend class tinyxmlDocument;

		tinyxmlDeclaration( const fbyte* version ,
			const fbyte* encoding ,
			const fbyte* standalone );

		virtual ~tinyxmlDeclaration();


		virtual fvoid				SetValue( const fbyte* value );
		virtual const fbyte*		GetValue() const;

		virtual fvoid				InsertEndChild( const xmlNode& addThis );
		virtual fvoid				LinkEndChild( xmlNode* addThis );

	protected:

		TiXmlDeclaration*		mDec;
	};
};


#endif

