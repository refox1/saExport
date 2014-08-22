
#include "xmlElement.h"
#include "tinyxmlDocument.h"
#include "tinyxmlElement.h"
#include "tinyxmlComment.h"
#include "tinyxmlDeclaration.h"

using namespace FOXSDK;

FOXSDK_DLL xmlDeclaration*	FOXSDK::CreatXMLDeclaration( xmlDocument* doc , const fbyte* version ,
												  const fbyte* encoding ,
												  const fbyte* standalone )
{
	tinyxmlDeclaration* dec = new tinyxmlDeclaration( version , encoding , standalone );

	tinyxmlDocument* tidoc = (tinyxmlDocument*)doc;

	tidoc->PushNode( dec );

	return dec;
}


FOXSDK_DLL xmlElement*	FOXSDK::CreatXMLElement( xmlDocument* doc , const fbyte* name )
{
	tinyxmlElement* element = new tinyxmlElement( (tinyxmlDocument&) *doc , name );

	tinyxmlDocument* tidoc = (tinyxmlDocument*)doc;

	tidoc->PushNode( element );

	return element;
}


FOXSDK_DLL xmlComment*	FOXSDK::CreatXMLComment( xmlDocument* doc , const fbyte* name )
{
	tinyxmlComment* comment = new tinyxmlComment( (tinyxmlDocument&) *doc , name );

	tinyxmlDocument* tidoc = (tinyxmlDocument*)doc;

	tidoc->PushNode( comment );

	return comment;
}


FOXSDK_DLL xmlDocument*	FOXSDK::CreatXMLDocument()
{
	return new tinyxmlDocument();
}


FOXSDK_DLL fvoid			FOXSDK::ReleaseXMLDocument( xmlDocument* doc )
{
	delete doc;
}

