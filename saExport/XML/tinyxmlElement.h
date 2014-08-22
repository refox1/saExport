#ifndef _TINYXMLELEMENT_H_
#define _TINYXMLELEMENT_H_



#include "xmlElement.h"


#include "tinyxml/tinyxml.h"

namespace FOXSDK
{

    class tinyxmlDocument;

	class tinyxmlElement : public xmlElement
	{
	public:

		friend class tinyxmlDocument;


		tinyxmlElement( tinyxmlDocument& doc , const fbyte* value );
		virtual ~tinyxmlElement();

		virtual fvoid			SetValue( const fbyte* value );
		virtual const fbyte*	GetValue() const;

		virtual const fbyte*	GetText() const;

		virtual fvoid			SetAttribute( const fbyte* name , const fbyte* value );
		virtual fvoid			SetAttribute( const fbyte* name , fint32 value );
		virtual fvoid			SetAttribute( const fbyte* name , freal32 value );
		virtual fvoid			SetAttribute( const fbyte* name , freal64 value );

		virtual fbool			GetAttribute( const fbyte* name , const fbyte** value );
		virtual fbool			GetAttribute( const fbyte* name , fint32* value );
		virtual fbool			GetAttribute( const fbyte* name , freal32* value );
		virtual fbool			GetAttribute( const fbyte* name , freal64* value );

		virtual fvoid			InsertEndChild( const xmlNode& addThis );
		virtual fvoid			LinkEndChild( xmlNode* addThis );

		virtual xmlElement*		FirstChildElement( const fbyte* name );
		virtual xmlElement*		FirstChildElement();
		virtual xmlElement*		NextSiblingElement();

	protected:

		TiXmlElement*		mTinyElement;

		tinyxmlDocument&	mDoc;

	private:

	};



};

#endif




