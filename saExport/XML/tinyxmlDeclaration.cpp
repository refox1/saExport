#include "tinyxmlDeclaration.h"


using namespace FOXSDK;


tinyxmlDeclaration::tinyxmlDeclaration( const fbyte* version , const fbyte* encoding , const fbyte* standalone ):
xmlDeclaration() ,
mDec( new TiXmlDeclaration( version , encoding , standalone ) )
{
	
}


tinyxmlDeclaration::~tinyxmlDeclaration()
{

}


fvoid				tinyxmlDeclaration::SetValue( const fbyte* value )
{
	mDec->SetValue( value );
}


const fbyte*		tinyxmlDeclaration::GetValue() const
{
	return mDec->Value();
}

fvoid				tinyxmlDeclaration::InsertEndChild( const xmlNode& addThis )
{

}


fvoid				tinyxmlDeclaration::LinkEndChild( xmlNode* addThis )
{
	
}

