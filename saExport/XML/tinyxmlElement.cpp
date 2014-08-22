#include "tinyxmlDocument.h"
#include "tinyxmlElement.h"
#include "tinyxmlComment.h"
#include "tinyxmlDocument.h"

using namespace FOXSDK;


tinyxmlElement::tinyxmlElement( tinyxmlDocument& doc , const fbyte* value ):
xmlElement() ,
mTinyElement( new TiXmlElement( value ) ) ,
mDoc( doc )
{

}


tinyxmlElement::~tinyxmlElement()
{
}



fvoid			tinyxmlElement::SetValue( const fbyte* value )
{
	mTinyElement->SetValue( value );
}


const fbyte*	tinyxmlElement::GetValue() const
{
	return mTinyElement->Value();
}

const fbyte*	tinyxmlElement::GetText() const
{
	return mTinyElement->GetText();
}

fvoid			tinyxmlElement::SetAttribute( const fbyte* name , const fbyte* value )
{
	mTinyElement->SetAttribute( name , value );
}


fvoid			tinyxmlElement::SetAttribute( const fbyte* name , fint32 value )
{
	mTinyElement->SetAttribute( name , value );
}

fvoid			tinyxmlElement::SetAttribute( const fbyte* name , freal32 value )
{
	mTinyElement->SetFloatAttribute( name , value );
}

fvoid			tinyxmlElement::SetAttribute( const fbyte* name , freal64 value )
{
	mTinyElement->SetDoubleAttribute( name , value );
}


fbool			tinyxmlElement::GetAttribute( const fbyte* name , const fbyte** value )
{
	*value = mTinyElement->Attribute( name );

	return *value != 0;
}


fbool			tinyxmlElement::GetAttribute( const fbyte* name , fint32* value )
{
	const fbyte* attr = mTinyElement->Attribute( name , value );

	return attr != 0;
}


fbool			tinyxmlElement::GetAttribute( const fbyte* name , freal32* value )
{
	const fbyte* attr = mTinyElement->Attribute( name , value );

	return attr != 0;
}

fbool			tinyxmlElement::GetAttribute( const fbyte* name , freal64* value )
{
	const fbyte* attr = mTinyElement->Attribute( name , value );

	return attr != 0;
}


fvoid			tinyxmlElement::InsertEndChild( const xmlNode& addThis )
{
	switch ( addThis.GetType() )
	{
	case XML_ELEMENT:
		{
			tinyxmlElement& element = ( tinyxmlElement& )addThis;

			mTinyElement->InsertEndChild( *element.mTinyElement );
		}
		break;
	case XML_COMMENT:
		{
			tinyxmlComment& element = ( tinyxmlComment& )addThis;

			mTinyElement->InsertEndChild( *element.mTinyComment );
		}
		break;
	}

}


fvoid			tinyxmlElement::LinkEndChild( xmlNode* addThis )
{
	switch ( addThis->GetType() )
	{
	case XML_ELEMENT:
		{
			tinyxmlElement* element = ( tinyxmlElement* )addThis;

			mTinyElement->LinkEndChild( element->mTinyElement );
		}
		break;
	case XML_COMMENT:
		{
			tinyxmlComment* element = ( tinyxmlComment* )addThis;

			mTinyElement->LinkEndChild( element->mTinyComment );
		}
		break;
	}

}

xmlElement*		tinyxmlElement::FirstChildElement( const fbyte* name )
{
	TiXmlElement* element = mTinyElement->FirstChildElement( name );

	if ( !element )
		return F_NULL;

	xmlNode* node = mDoc.GetNode( element );

	if ( !node )
	{
		tinyxmlElement* tinyelement = new tinyxmlElement( mDoc , element->Value() );
		delete tinyelement->mTinyElement;				
		tinyelement->mTinyElement = element;
		mDoc.PushNode( tinyelement );
		node = tinyelement;
	}

	return (xmlElement*)node;
}


xmlElement*		tinyxmlElement::FirstChildElement()
{
	TiXmlElement* element = mTinyElement->FirstChildElement();

	if ( !element )
		return F_NULL;

	xmlNode* node = mDoc.GetNode( element );

	if ( !node )
	{
		tinyxmlElement* tinyelement = new tinyxmlElement( mDoc , element->Value() );
		delete tinyelement->mTinyElement;				
		tinyelement->mTinyElement = element;
		mDoc.PushNode( tinyelement );
		node = tinyelement;
	}

	return (xmlElement*)node;
}


xmlElement*		tinyxmlElement::NextSiblingElement()
{
	TiXmlElement* element = mTinyElement->NextSiblingElement();

	if ( !element )
		return F_NULL;

	xmlNode* node = mDoc.GetNode( element );

	if ( !node )
	{
		tinyxmlElement* tinyelement = new tinyxmlElement( mDoc , element->Value() );
		delete tinyelement->mTinyElement;				
		tinyelement->mTinyElement = element;
		mDoc.PushNode( tinyelement );
		node = tinyelement;
	}

	return (xmlElement*)node;
}

