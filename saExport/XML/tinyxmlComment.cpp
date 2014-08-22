#include "tinyxmlComment.h"

using namespace FOXSDK;


tinyxmlComment::tinyxmlComment( tinyxmlDocument& doc , const fbyte* value ):
xmlComment() ,
mTinyComment( new TiXmlComment( value ) ) ,
mDoc( doc )
{

}


tinyxmlComment::~tinyxmlComment()
{
}



fvoid			tinyxmlComment::SetValue( const fbyte* value )
{
	mTinyComment->SetValue( value );
}


const fbyte*	tinyxmlComment::GetValue() const
{
	return mTinyComment->Value();
}


fvoid			tinyxmlComment::InsertEndChild( const xmlNode& addThis )
{

}


fvoid			tinyxmlComment::LinkEndChild( xmlNode* addThis )
{

}
