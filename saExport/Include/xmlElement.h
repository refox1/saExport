#ifndef _XMLELEMENT_H_
#define _XMLELEMENT_H_


#include "baseDefine.h"


namespace FOXSDK
{

	enum xmlNodeType
	{
		XML_DOCUMENT,
		XML_ELEMENT,
		XML_COMMENT,
		XML_UNKNOWN,
		XML_TEXT,
		XML_DECLARATION,
		XML_TYPECOUNT
	};

	// interface of all xml
	class xmlNode
	{
	public:

		xmlNodeType					GetType() const
		{
			return mType;
		}

		virtual	~xmlNode(){}

		virtual fvoid				SetValue( const fbyte* value ) = 0;
		virtual const fbyte*		GetValue() const = 0;

		virtual fvoid				InsertEndChild( const xmlNode& addThis ) = 0;
		virtual fvoid				LinkEndChild( xmlNode* addThis ) = 0;

	protected:
	
		xmlNodeType			mType;
	};

	class FOXSDK_DLL xmlDeclaration : public xmlNode
	{
	public:

		xmlDeclaration()
		{
			mType = XML_DECLARATION;
		}

	protected:
	private:
	};

	class FOXSDK_DLL xmlElement : public xmlNode
	{
	public:

		xmlElement()
		{
			mType = XML_ELEMENT;
		}

		virtual const fbyte*		GetText() const = 0;

		virtual xmlElement*			FirstChildElement( const fbyte* name ) = 0;
		virtual xmlElement*			FirstChildElement() = 0;
		virtual xmlElement*			NextSiblingElement() = 0;

		virtual fvoid				SetAttribute( const fbyte* name , const fbyte* value ) = 0;
		virtual fvoid				SetAttribute( const fbyte* name , fint32 value ) = 0;
		virtual fvoid				SetAttribute( const fbyte* name , freal32 value ) = 0;
		virtual fvoid				SetAttribute( const fbyte* name , freal64 value ) = 0;

		virtual fbool				GetAttribute( const fbyte* name , const fbyte** value ) = 0;
		virtual fbool				GetAttribute( const fbyte* name , fint32* value ) = 0;
		virtual fbool				GetAttribute( const fbyte* name , freal32* value ) = 0;
		virtual fbool				GetAttribute( const fbyte* name , freal64* value ) = 0;

	protected:
	private:
	};


	class FOXSDK_DLL xmlComment : public xmlNode
	{
	public:

		xmlComment()
		{
			mType = XML_COMMENT;
		}

	protected:
	private:
	};


	class FOXSDK_DLL xmlDocument : public xmlNode
	{
	public:

		xmlDocument()
		{
			mType = XML_DOCUMENT;
		}

		virtual fvoid			Parse( const fbyte* data ) = 0;

		virtual xmlElement*		Root() = 0;

		virtual fbool			Save( const fbyte* path ,  fbool utf8 = F_TRUE ) = 0;
		virtual fbool			Load( const fbyte* path ) = 0;

		virtual fvoid			Clear() = 0;

	protected:
	private:
	};

	extern "C" FOXSDK_DLL xmlDeclaration*	CreatXMLDeclaration( xmlDocument* doc , const fbyte* version ,
		const fbyte* encoding ,
		const fbyte* standalone );
	extern "C" FOXSDK_DLL xmlElement*		CreatXMLElement( xmlDocument* doc , const fbyte* name );
	extern "C" FOXSDK_DLL xmlComment*		CreatXMLComment( xmlDocument* doc , const fbyte* name );

	extern "C" FOXSDK_DLL xmlDocument*		CreatXMLDocument();
	extern "C" FOXSDK_DLL fvoid				ReleaseXMLDocument( xmlDocument* doc );


};




#endif


