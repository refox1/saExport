
#include "tinyxmlComment.h"
#include "tinyxmlDocument.h"
#include "tinyxmlDeclaration.h"

using namespace FOXSDK;


tinyxmlDocument::tinyxmlDocument():
xmlDocument(),
mRoot( *this , "root" )
{
	delete mRoot.mTinyElement;
	mRoot.mTinyElement = F_NULL;
}

tinyxmlDocument::~tinyxmlDocument()
{
	Clear();
}


fvoid			tinyxmlDocument::SetValue( const fbyte* value )
{
	mTiXmlDocument.SetValue( value );
}


const fbyte*	tinyxmlDocument::GetValue() const
{
	return mTiXmlDocument.Value();
}


xmlElement*		tinyxmlDocument::Root()
{
	TiXmlElement* root = mTiXmlDocument.RootElement();

	mRoot.mTinyElement = root;

	if ( root )
		return &mRoot;

	return F_NULL;
}


fbool			tinyxmlDocument::Save( const fbyte* path , fbool utf8 )
{
	fbool save = mTiXmlDocument.SaveFile( path , utf8 == F_TRUE );

	return save;
}


fvoid			tinyxmlDocument::Parse( const fbyte* data )
{
	mTiXmlDocument.Parse( data );
}


fbool			tinyxmlDocument::Load( const fbyte* path )
{
	mLoad = mTiXmlDocument.LoadFile( path , TIXML_ENCODING_UNKNOWN );

	return mLoad;
}


fvoid			tinyxmlDocument::Clear()
{
	mTiXmlDocument.Clear();

	ClearNode();
}


fvoid			tinyxmlDocument::InsertEndChild( const xmlNode& addThis )
{
	switch ( addThis.GetType() )
	{
	case XML_DECLARATION:
		{

		}
		break;
	case XML_ELEMENT:
		{
			tinyxmlElement& element = ( tinyxmlElement& )addThis;

			mTiXmlDocument.InsertEndChild( *element.mTinyElement );
		}
		break;
	case XML_COMMENT:
		{
			tinyxmlComment& element = ( tinyxmlComment& )addThis;

			mTiXmlDocument.InsertEndChild( *element.mTinyComment );
		}
		break;
	}

}


fvoid			tinyxmlDocument::LinkEndChild( xmlNode* addThis )
{
	switch ( addThis->GetType() )
	{
	case XML_DECLARATION:
		{
			tinyxmlDeclaration* element = ( tinyxmlDeclaration* )addThis;

			mTiXmlDocument.LinkEndChild( element->mDec );
		}
		break;
	case XML_ELEMENT:
		{
			tinyxmlElement* element = ( tinyxmlElement* )addThis;

			mTiXmlDocument.LinkEndChild( element->mTinyElement );
		}
		break;
	case XML_COMMENT:
		{
			tinyxmlComment* element = ( tinyxmlComment* )addThis;

			mTiXmlDocument.LinkEndChild( element->mTinyComment );
		}
		break;
	}

}






fvoid			tinyxmlDocument::PushNode( xmlNode* node )
{
	switch ( node->GetType() )
	{
	case XML_DECLARATION:
		{
			tinyxmlDeclaration* element = ( tinyxmlDeclaration* )node;

			mNodes[element->mDec] = node;
		}
		break;
	case XML_ELEMENT:
		{
			tinyxmlElement* element = ( tinyxmlElement* )node;

			mNodes[element->mTinyElement] = node;
		}
		break;
	case XML_COMMENT:
		{

		}
		break;
	}

	
}


fvoid			tinyxmlDocument::ClearNode()
{
	for (map< TiXmlNode* , xmlNode* >::iterator iter = mNodes.begin() ; iter != mNodes.end() ; iter++ )
	{
		delete iter->second;
	}

	mNodes.clear();
}


xmlNode*		tinyxmlDocument::GetNode( TiXmlNode* node )
{
	map< TiXmlNode* , xmlNode* >::iterator iter = mNodes.find( node );

	if ( iter != mNodes.end() )
		return iter->second;

	return F_NULL;
}

