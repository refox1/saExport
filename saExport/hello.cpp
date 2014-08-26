#include "hello.h"
#include "sa.h"
#include <time.h>
#include "tinyxml.h"
#include "baseDefine.h"
#include "crtManager.h"
#include "xmlElement.h"
#include <stdlib.h>

#include <stdio.h>
#include <dirent.h>

#include <sys/stat.h>
#include <unistd.h>
#include <ftw.h>


using namespace FOXSDK;

struct NpcTemplate 
{
	string templateName;
	string nobody;
	string nosee;
	string type;
	string fun;
	string name;
	string hp;
	string mp;
	string str;
	string tough;
	string loopTime;
	string imgName;
	string fly;
	string itemNum;
};

map< string , NpcTemplate > npcTemplateMap;
map< wstring , int > stringMap;
extern void ReadArg( string path , string name , string tem );

void		SaveItem()
{
	crtIFileSystem* fileSystem = crtManager::GetFileSystem();
	crtIReadFile* readFile = fileSystem->CreateAndOpenFile( "C:\\work\\shiqicc95\\sss\\gmsv\\data\\itemset6.txt" );
// 	crtIReadFile* readImageFile = fileSystem->CreateAndOpenFile( "E:\\shiqicc95\\data\\adrn_136.bin" );
// 	crtIReadFile* readDataFile = fileSystem->CreateAndOpenFile( "E:\\shiqicc95\\data\\real_136.bin" );
	char read;
	string strRead;
	string subStr;
	
	xmlDocument* doc = CreatXMLDocument();

	xmlElement* root = CreatXMLElement( doc , "root" );
	doc->LinkEndChild( root );

	map< int , int > mmm;
	map< string , vector< ItemInfo > > sortItems;

	while ( readFile->Read( &read , 1 ) )
	{
		strRead += read;

		if ( read == '\n' )
		{
			ItemInfo info;

			int n = strRead.find( "," );

			if ( n == -1 )
			{
				strRead.clear();
				continue;
			}

			

			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.name = subStr;

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.explain1 = subStr;

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.explain2 = subStr;

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.explain3 = subStr;

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.quaint = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.unknow1 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.unknow2 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.unknow3 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.unknow4 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.unknow5 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.useItem = subStr;

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.suitEquip = subStr;

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.resuitEquip = subStr;

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.dropItem = subStr;

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.pickupItem = subStr;

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.autoResume = subStr;

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.id = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.img = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.sell = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.type = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.stage = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.range = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.level = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.num = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.unknow6 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.alchemyAttr = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.unknow7 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.unknow8 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.unknow9 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.suit = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.perdure1 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.perdure2 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.increase = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.decrease = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.code = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.attackNum1 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.attackNum2 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.str1 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.str2 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.tgh1 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.tgh2 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.dex1 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.dex2 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.hp1 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.hp2 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.mp1 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.mp2 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.luck1 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.luck2 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.Charm1 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.Charm2 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.dodge1 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.dodge2 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.attrType = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.attr = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.magic = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.rare = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.mp = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.ward = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.attackRank = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.weight = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.Poison1 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.Poison2 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.Paralysis1 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.Paralysis2 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.Sleep1 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.Sleep2 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.Stone1 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.Stone2 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.Drunk1 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.Drunk2 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.Confusion1 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.Confusion2 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.Critical1 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.Critical2 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.trade = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.lose = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.drop = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.logout = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.save = atoi( subStr.c_str() );


			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.store = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.alchemy = atoi( subStr.c_str() );




			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.material[ 0 ] = subStr;

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.materialNum[ 0 ] = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.material[ 1 ] = subStr;

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.materialNum[ 1 ] = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.material[ 2 ] = subStr;

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.materialNum[ 2 ] = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.material[ 3 ] = subStr;

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.materialNum[ 3 ] = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			info.material[ 4 ] = subStr;

 			subStr = strRead;
			info.materialNum[ 4 ] = atoi( subStr.c_str() );






			strRead.clear();

			string str = info.useItem;
			str = str.substr( 0 , strlen( str.c_str() ) );
			sortItems[ str ].push_back( info );

			}
		}

	for ( map< string , vector< ItemInfo > >::iterator iter = sortItems.begin() ; iter != sortItems.end() ; ++iter )
	{
		for ( int i44 = 0 ; i44 < iter->second.size() ; i44++  )
		{
			ItemInfo info = iter->second[ i44 ]; 

			xmlElement* element = CreatXMLElement( doc , "item" );
			root->LinkEndChild( element );

// 			xmlElement* element = CreatXMLElement( doc , "i" );
// 			root->LinkEndChild( element );
// 
// 			element->SetAttribute( "id" , info.id );
// 			element->SetAttribute( "n" , info.name.c_str() );
// 			element->SetAttribute( "e" , info.explain2.c_str() );
			
//			element->SetAttribute( "px" , gMapImages[ info.img ].px );
//			element->SetAttribute( "py" , gMapImages[ info.img ].py );

			element->SetAttribute( "name" , info.name.c_str() );
			element->SetAttribute( "explain1" , info.explain1.c_str() );
			element->SetAttribute( "explain2" , info.explain2.c_str() );

			
//			sdfsd[ info.explain3 ] = 0;


			if ( info.useItem[ 0 ] != '\0' )
			{
				
				if ( info.useItem.find( "ITEM_useRecovery" ) == 0 )
				{
					element->SetAttribute( "useType" , 1 );
					
					if ( info.explain3.find( "体" ) != -1 )
					{
						string sub = info.explain3.substr( 2 );

						element->SetAttribute( "recType" , 1 );
						element->SetAttribute( "power" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "气" ) != -1 )
					{
						string sub = info.explain3.substr( 2 );

						element->SetAttribute( "recType" , 2 );
						element->SetAttribute( "power" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "魅" ) != -1 )
					{
						string sub = info.explain3.substr( 2 );

						element->SetAttribute( "recType" , 3 );
						element->SetAttribute( "power" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "忠" ) != -1 )
					{
						string sub = info.explain3.substr( 2 );

						element->SetAttribute( "recType" , 4 );
						element->SetAttribute( "power" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "解猪" ) != -1 )
					{
						string sub = info.explain3.substr( 2 );

						element->SetAttribute( "recType" , 5 );
					}
					else if ( info.explain3.find( "GETEXP" ) != -1 )
					{
						string sub = info.explain3.substr( 2 );

						element->SetAttribute( "recType" , 6 );
					}
					else if ( info.explain3.find( "UP" ) != -1 )
					{
						string sub = info.explain3.substr( 2 );

						element->SetAttribute( "recType" , 7 );
					}
					else if ( info.explain3.find( "PROPERTY-" ) != -1 )
					{
						string sub = info.explain3.substr( 2 );

						element->SetAttribute( "recType" , 8 );
					}
					else if ( info.explain3.find( "PROPERTY+" ) != -1 )
					{
						string sub = info.explain3.substr( 2 );

						element->SetAttribute( "recType" , 9 );
					}

					else if ( info.explain3[ 0 ] != '\0' )
					{
						assert( 0 );
					}
					

					
				}
				else if ( info.useItem.find( "ITEM_useStatusRecovery" ) == 0 )
				{
					element->SetAttribute( "useType" , 2 );


					if ( info.explain3.find( "毒" ) != -1 )
					{
						element->SetAttribute( "status" , 2 );
					}
					else if ( info.explain3.find( "眠" ) != -1 )
					{
						element->SetAttribute( "status" , 7 );
					}
					else if ( info.explain3.find( "乱" ) != -1 )
					{
						element->SetAttribute( "status" , 5 );
					}
					else if ( info.explain3.find( "石" ) != -1 )
					{
						element->SetAttribute( "status" , 4 );
					}
					
					else if ( info.explain3.find( "醉" ) != -1 )
					{
						element->SetAttribute( "status" , 6 );
					}
					else if ( info.explain3.find( "全" ) != -1 )
					{
						element->SetAttribute( "status" , 1 );
					}
					else
					{
						assert( 0 );
					}

					
				}
				else if ( info.useItem.find( "ITEM_Refresh" ) == 0 )
				{
					element->SetAttribute( "useType" , 2 );

					if ( info.explain3.find( "默" ) != -1 )
					{
						element->SetAttribute( "status" , 10 );
					}
					else
					{
						assert( 0 );
					}

				}
				else if ( info.useItem.find( "ITEM_metamo" ) == 0 )
				{
					element->SetAttribute( "useType" , 3 );
					element->SetAttribute( "minute" , info.explain3.c_str() );
				}
				else if ( info.useItem.find( "ITEM_Addexp" ) == 0 )
				{
					element->SetAttribute( "useType" , 4 );

					if ( info.explain3.find( "增" ) != -1 )
					{
						string sub = info.explain3.substr( 2 );

						element->SetAttribute( "recType" , 1 );

						element->SetAttribute( "power" , atoi( sub.c_str() ) );

						int n = info.explain3.find( "分" );
						sub = info.explain3.substr( n + 2 );

						element->SetAttribute( "minute" , atoi( sub.c_str() ) );
					}
					else
					{
						assert( 0 );
					}
				}
				else if ( info.useItem.find( "ITEM_useImprecate" ) == 0 )
				{
					element->SetAttribute( "useType" , 5 );

					if ( info.explain3.find( "咒" ) != -1 )
					{
						string sub = info.explain3.substr( 3 );

						element->SetAttribute( "imprecateType" , 1 );
						element->SetAttribute( "power" , atoi( sub.c_str() ) );

						int n = info.explain3.find( "x" );
						sub = info.explain3.substr( n + 1 );

						element->SetAttribute( "turn" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "祝" ) != -1 )
					{
						string sub = info.explain3.substr( 3 );

						element->SetAttribute( "imprecateType" , 2 );
						element->SetAttribute( "power" , atoi( sub.c_str() ) );

						int n = info.explain3.find( "x" );
						sub = info.explain3.substr( n + 1 );

						element->SetAttribute( "turn" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "恩" ) != -1 )
					{
						string sub = info.explain3.substr( 3 );

						element->SetAttribute( "imprecateType" , 3 );
						element->SetAttribute( "power" , atoi( sub.c_str() ) );

						int n = info.explain3.find( "x" );
						sub = info.explain3.substr( n + 1 );

						element->SetAttribute( "turn" , atoi( sub.c_str() ) );
					}
					else
					{
						assert( 0 );
					}
				}
				else if ( info.useItem.find( "ITEM_useRessurect" ) == 0 )
				{
					element->SetAttribute( "useType" , 6 );

					element->SetAttribute( "power" , atoi( info.explain3.c_str() ) );
				}
				else if ( info.useItem.find( "ITEM_useFusionEditBase" ) == 0 )
				{
					element->SetAttribute( "useType" , 7 );

				}
				else if ( info.useItem.find( "ITEM_ChikulaStone" ) == 0 )
				{
					element->SetAttribute( "useType" , 8 );

					if ( info.explain3.find( "hp" ) != -1 )
					{
						string sub = info.explain3.substr( 3 );

						element->SetAttribute( "chikulaType" , 1 );
						element->SetAttribute( "power" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "mp" ) != -1 )
					{
						string sub = info.explain3.substr( 3 );

						element->SetAttribute( "chikulaType" , 2 );
						element->SetAttribute( "power" , atoi( sub.c_str() ) );
					}
					else
					{
						assert( 0 );
					}
				}
				else if ( info.useItem.find( "ITEM_useMaxRedSocks" ) == 0 )
				{
					element->SetAttribute( "useType" , 8 );
					element->SetAttribute( "redSocks" , atoi( info.explain3.c_str() ) );

				}
				else if ( info.useItem.find( "ITEM_useSkup" ) == 0 )
				{
					element->SetAttribute( "useType" , 9 );
				}
				else if ( info.useItem.find( "ITEM_ThrowItemBox" ) == 0 )
				{
					element->SetAttribute( "useType" , 10 );
				}
				else if ( info.useItem.find( "ITEM_LoverSelectUser" ) == 0 )
				{
					element->SetAttribute( "useType" , 11 );
				}
				else if ( info.useItem.find( "ITEM_WaterWordStatus" ) == 0 )
				{
					element->SetAttribute( "useType" , 12 );
					if ( info.explain3.find( "time" ) != -1 )
					{
						string sub = info.explain3.substr( 5 );

						element->SetAttribute( "minute" , atoi( sub.c_str() ) );
					}
					else
					{
						assert( 0 );
					}
				}
				else if ( info.useItem.find( "ITEM_useSkillCanned" ) == 0 )
				{
					element->SetAttribute( "useType" , 13 );
					element->SetAttribute( "skill" , atoi( info.explain3.c_str() ) );
				}
				else if ( info.useItem.find( "ITEM_useStatusChange" ) == 0 )
				{
					element->SetAttribute( "useType" , 14 );
					
					if ( info.explain3.find( "毒" ) != -1 )
					{
						string sub = info.explain3.substr( 3 );

						element->SetAttribute( "status" , 2 );
						
						int n = info.explain3.find( "turn" );
						sub = info.explain3.substr( n + 4 );
						element->SetAttribute( "turn" , atoi( sub.c_str() ) );

						n = info.explain3.find( "成" );
						sub = info.explain3.substr( n + 2 );
						element->SetAttribute( "per" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "乱" ) != -1 )
					{
						string sub = info.explain3.substr( 3 );

						element->SetAttribute( "status" , 5 );

						int n = info.explain3.find( "turn" );
						sub = info.explain3.substr( n + 4 );
						element->SetAttribute( "turn" , atoi( sub.c_str() ) );

						n = info.explain3.find( "成" );
						sub = info.explain3.substr( n + 2 );
						element->SetAttribute( "per" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "眠" ) != -1 )
					{
						string sub = info.explain3.substr( 3 );

						element->SetAttribute( "status" , 7 );

						int n = info.explain3.find( "turn" );
						sub = info.explain3.substr( n + 4 );
						element->SetAttribute( "turn" , atoi( sub.c_str() ) );

						n = info.explain3.find( "成" );
						sub = info.explain3.substr( n + 2 );
						element->SetAttribute( "per" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "醉" ) != -1 )
					{
						string sub = info.explain3.substr( 3 );

						element->SetAttribute( "status" , 6 );

						int n = info.explain3.find( "turn" );
						sub = info.explain3.substr( n + 4 );
						element->SetAttribute( "turn" , atoi( sub.c_str() ) );

						n = info.explain3.find( "成" );
						sub = info.explain3.substr( n + 2 );
						element->SetAttribute( "per" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "石化" ) != -1 )
					{
						string sub = info.explain3.substr( 5 );

						element->SetAttribute( "status" , 4 );

						int n = info.explain3.find( "turn" );
						sub = info.explain3.substr( n + 4 );
						element->SetAttribute( "turn" , atoi( sub.c_str() ) );

						n = info.explain3.find( "成" );
						sub = info.explain3.substr( n + 2 );
						element->SetAttribute( "per" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "石" ) != -1 )
					{
						string sub = info.explain3.substr( 3 );

						element->SetAttribute( "status" , 4 );

						int n = info.explain3.find( "turn" );
						sub = info.explain3.substr( n + 4 );
						element->SetAttribute( "turn" , atoi( sub.c_str() ) );

						n = info.explain3.find( "成" );
						sub = info.explain3.substr( n + 2 );
						element->SetAttribute( "per" , atoi( sub.c_str() ) );
					}
					else
					{
						assert( 0 );
					}
				}
				else if ( info.useItem.find( "ITEM_ResAndDef" ) == 0 )
				{
					element->SetAttribute( "useType" , 15 );
					element->SetAttribute( "power" ,  atoi( info.explain3.c_str() ) );

					if ( info.explain3.find( "吸" ) != -1 )
					{
						element->SetAttribute( "magicStatus" , 1 );

						int n = info.explain3.find( "turn" );
						string sub = info.explain3.substr( n + 4 );
						element->SetAttribute( "turn" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "无" ) != -1 )
					{
						element->SetAttribute( "magicStatus" , 3 );

						int n = info.explain3.find( "turn" );
						string sub = info.explain3.substr( n + 4 );
						element->SetAttribute( "turn" , atoi( sub.c_str() ) );
					}
					else
					{
						assert( 0 );
					}
				}
				else if ( info.useItem.find( "ITEM_useCaptureUp" ) == 0 )
				{
					element->SetAttribute( "useType" , 16 );
					element->SetAttribute( "captureUp" , atoi( info.explain3.c_str() ) );
				}
				else if ( info.useItem.find( "ITEM_useNoenemy" ) == 0 )
				{
					element->SetAttribute( "useType" , 17 );
				}
				else if ( info.useItem.find( "ITEM_randEnemyEquipOne" ) == 0 )
				{
					element->SetAttribute( "useType" , 18 );

					string sub = info.explain3.substr( 5 );
					element->SetAttribute( "randEnemy" , atoi( sub.c_str() ) );
				}
				else if ( info.useItem.find( "ITEM_useMRecovery" ) == 0 )
				{
					element->SetAttribute( "useType" , 19 );

					if ( info.explain3.find( "全" ) != -1 )
					{
						element->SetAttribute( "magicStatus" , 3 );

						int n = info.explain3.find( "turn" );
						string sub = info.explain3.substr( 3 );
						element->SetAttribute( "turn" , atoi( sub.c_str() ) );
						element->SetAttribute( "target" , 8 );
					}
					else if ( info.explain3.find( "单" ) != -1 )
					{
						element->SetAttribute( "magicStatus" , 3 );

						int n = info.explain3.find( "turn" );
						string sub = info.explain3.substr( 3 );
						element->SetAttribute( "turn" , atoi( sub.c_str() ) );
						element->SetAttribute( "target" , 1 );
					}
					else
					{
						assert( 0 );
					}

				}
				else if ( info.useItem.find( "ITEM_useFieldChange" ) == 0 )
				{
					element->SetAttribute( "useType" , 19 );

					if ( info.explain3.find( "地" ) != -1 )
					{
						element->SetAttribute( "attr" , 1 );

						string sub = info.explain3.substr( 3 );
						element->SetAttribute( "power" , atoi( sub.c_str() ) );

						int n = info.explain3.find( "回合" );
						sub = info.explain3.substr( n + 5 );
						element->SetAttribute( "turn" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "水" ) != -1 )
					{
						element->SetAttribute( "attr" , 2 );

						string sub = info.explain3.substr( 3 );
						element->SetAttribute( "power" , atoi( sub.c_str() ) );

						int n = info.explain3.find( "回合" );
						sub = info.explain3.substr( n + 5 );
						element->SetAttribute( "turn" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "火" ) != -1 )
					{
						element->SetAttribute( "attr" , 3 );

						string sub = info.explain3.substr( 3 );
						element->SetAttribute( "power" , atoi( sub.c_str() ) );

						int n = info.explain3.find( "回合" );
						sub = info.explain3.substr( n + 5 );
						element->SetAttribute( "turn" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "风" ) != -1 )
					{
						element->SetAttribute( "attr" , 4 );

						string sub = info.explain3.substr( 3 );
						element->SetAttribute( "power" , atoi( sub.c_str() ) );

						int n = info.explain3.find( "回合" );
						sub = info.explain3.substr( n + 5 );
						element->SetAttribute( "turn" , atoi( sub.c_str() ) );
					}
					else
					{
						assert( 0 );
					}

				}
				else if ( info.useItem.find( "ITEM_useMic" ) == 0 )
				{
					element->SetAttribute( "useType" , 20 );
				}
				else if ( info.useItem.find( "ITEM_useEncounter" ) == 0 )
				{
					element->SetAttribute( "useType" , 21 );
				}
				else if ( info.useItem.find( "ITEM_useRenameItem" ) == 0 )
				{
					element->SetAttribute( "useType" , 22 );
					element->SetAttribute( "renameItem" , atoi( info.explain3.c_str() ) );
				}
				else if ( info.useItem.find( "ITEM_useDeathcounter" ) == 0 )
				{
					element->SetAttribute( "useType" , 23 );
					element->SetAttribute( "deathCounter" , atoi( info.explain3.c_str() ) );
				}
				else if ( info.useItem.find( "ITEM_petFollow" ) == 0 )
				{
					element->SetAttribute( "useType" , 24 );
					element->SetAttribute( "petFollow" , atoi( info.explain3.c_str() ) );
				}
				else if ( info.useItem.find( "ITEM_Constitution" ) == 0 )
				{
					element->SetAttribute( "useType" , 25 );

					if ( info.explain3.find( "VI" ) != -1 )
					{
						string sub = info.explain3.substr( 3 );
						element->SetAttribute( "constitutionVI" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "DE" ) != -1 )
					{
						string sub = info.explain3.substr( 3 );
						element->SetAttribute( "constitutionDE" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "ST" ) != -1 )
					{
						string sub = info.explain3.substr( 3 );
						element->SetAttribute( "constitutionST" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "TG" ) != -1 )
					{
						string sub = info.explain3.substr( 3 );
						element->SetAttribute( "constitutionTG" , atoi( sub.c_str() ) );
					}
					else
					{
						assert( 0 );
					}

				}
				else if ( info.useItem.find( "ITEM_AngelToken" ) == 0 )
				{
					element->SetAttribute( "useType" , 26 );
				}
				else if ( info.useItem.find( "ITEM_HeroToken" ) == 0 )
				{
					element->SetAttribute( "useType" , 27 );
				}
				else if ( info.useItem.find( "ITEM_useEffectTohelos" ) == 0 )
				{
					element->SetAttribute( "useType" , 28 );
				}
				else if ( info.useItem.find( "ITEM_useLearnRideCode" ) == 0 )
				{
					element->SetAttribute( "useType" , 29 );
					

					if ( info.explain3.find( "巴朵兰恩" ) != -1 )
					{
						element->SetAttribute( "learnRide" , 4 );
					}
					else if ( info.explain3.find( "左迪洛斯" ) != -1 )
					{
						element->SetAttribute( "learnRide" , 3 );
					}
					else if ( info.explain3.find( "玛恩摩洛斯" ) != -1 )
					{
						element->SetAttribute( "learnRide" , 6 );
					}
					else if ( info.explain3.find( "拉奇鲁哥" ) != -1 )
					{
						element->SetAttribute( "learnRide" , 8 );	
					}
					else if ( info.explain3.find( "卡达鲁卡斯" ) != -1 )
					{
						element->SetAttribute( "learnRide" , 10 );	
					}
					else if ( info.explain3.find( "扬奇洛斯" ) != -1 )
					{
						element->SetAttribute( "learnRide" , 9 );	
					}
					else if ( info.explain3.find( "卡卡金宝" ) != -1 )
					{
						element->SetAttribute( "learnRide" , 11 );	
					}
					else if ( info.explain3.find( "朵拉比斯" ) != -1 )
					{
						element->SetAttribute( "learnRide" , 7 );	
					}
					else if ( info.explain3.find( "格尔格" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 12 );	
					}
					else if ( info.explain3.find( "帖拉所伊朵" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 5 );	
					}
					else if ( info.explain3.find( "史卡鲁" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 13 );	
					}
					else if ( info.explain3.find( "奇宝" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 14 );	
					}
					else if ( info.explain3.find( "霍尔克" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 15 );	
					}
					else if ( info.explain3.find( "瑞里西尔" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 16 );	
					}
					else if ( info.explain3.find( "红暴" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 17 );	
					}
					else if ( info.explain3.find( "罗多克雷" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 18 );	
					}
					else if ( info.explain3.find( "沙比西奥" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 19 );	
					}
					else if ( info.explain3.find( "卡卡沃夫" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 20 );	
					}
					else if ( info.explain3.find( "赛洛洛班" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 21 );	
					}
					else if ( info.explain3.find( "佩露夏" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 22 );	
					}
					else if ( info.explain3.find( "牧哈卡" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 23 );	
					}
					else if ( info.explain3.find( "帕格萨卡斯" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 24 );	
					}
					else if ( info.explain3.find( "黑暴" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 25 );	
					}
					else if ( info.explain3.find( "灰飞" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 26 );	
					}
					else if ( info.explain3.find( "金暴" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 27 );	
					}
					else if ( info.explain3.find( "闪暴" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 28 );	
					}
					else if ( info.explain3.find( "黑机虎" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 29 );	
					}
					else if ( info.explain3.find( "斑点白虎" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 30 );	
					}
					else if ( info.explain3.find( "斑点黑虎" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 31 );	
					}
					else if ( info.explain3.find( "银暴" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 32 );	
					}
					else if ( info.explain3.find( "姆伊" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 33 );	
					}
					else if ( info.explain3.find( "白机虎" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 34 );	
					}
					else if ( info.explain3.find( "风人狼" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 35 );	
					}
					else if ( info.explain3.find( "红飞" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 36 );	
					}
					else if ( info.explain3.find( "橙飞" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 37 );	
					}
					else if ( info.explain3.find( "蓝狼" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 38 );	
					}
					else if ( info.explain3.find( "火狼|" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 39 );	
					}
					else if ( info.explain3.find( "海马|" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 40 );	
					}
					else if ( info.explain3.find( "吉比|" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 41 );	
					}
					else if ( info.explain3.find( "巨鹰|" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 42 );	
					}
					else if ( info.explain3.find( "金虎|" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 43 );	
					}
					else if ( info.explain3.find( "蓝怪|" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 44 );	
					}
					else if ( info.explain3.find( "融合|" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 45 );	
					}
					else if ( info.explain3.find( "青龙|" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 46 );	
					}
					else if ( info.explain3.find( "冰象|" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 47 );	
					}
					else if ( info.explain3.find( "橙虎|" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 48 );	
					}
					else if ( info.explain3.find( "星星|" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 49 );	
					}
					else if ( info.explain3.find( "红虎|" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 50 );	
					}
					else if ( info.explain3.find( "绿暴" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 51 );	
					}
					else if ( info.explain3.find( "水晶暴" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 52 );	
					}
					else if ( info.explain3.find( "2D机暴" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 53 );	
					}
					else if ( info.explain3.find( "3D蓝龙" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 54 );	
					}
					else if ( info.explain3.find( "3D绿龙" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 55 );	
					}
					else if ( info.explain3.find( "3D红龙" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 56 );	
					}
					else if ( info.explain3.find( "3D灰龙" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 57 );	
					}
					else if ( info.explain3.find( "3D黄龙" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 58 );	
					}
					else if ( info.explain3.find( "宠物蛋" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 59 );	
					}
					else if ( info.explain3.find( "威威" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 60 );	
					}
					else if ( info.explain3.find( "儱" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 61 );	
					}
					else if ( info.explain3.find( "白虎" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , 62 );	
					}


					else if ( info.explain3.find( "取消了" ) != -1 )
					{
						element->SetAttribute( "learnRide"  , -1 );	
					}
					
					else
					{
						assert( 0 );
					}

				}
				else if ( info.useItem.find( "ITEM_MysteriousGift" ) == 0 )
				{
					element->SetAttribute( "useType" , 30 );
				}
				else if ( info.useItem.find( "ITEM_AddPRSkillPercent" ) == 0 )
				{
					element->SetAttribute( "useType" , 31 );
					element->SetAttribute( "skillPercent" , atoi( info.explain3.c_str() ) );
				}
				else if ( info.useItem.find( "ITEM_useMagic" ) == 0 )
				{
					element->SetAttribute( "useType" , 32 );
					element->SetAttribute( "useMagic" , atoi( info.explain3.c_str() ) );
				}		
				else if ( info.useItem.find( "ITEM_useOtherEditBase" ) == 0 )
				{
					element->SetAttribute( "useType" , 33 );
				}
				else if ( info.useItem.find( "ITEM_changePetOwner" ) == 0 )
				{
					element->SetAttribute( "useType" , 34 );
				}
				else if ( info.useItem.find( "ITEM_contract" ) == 0 )
				{
					element->SetAttribute( "useType" , 35 );
					element->SetAttribute( "contract" , atoi( info.explain3.c_str() ) );
				}
				else if ( info.useItem.find( "ITEM_timeticket" ) == 0 )
				{
					element->SetAttribute( "useType" , 38 );
					element->SetAttribute( "second" , atoi( info.explain3.c_str() ) );
				}
				else if ( info.useItem.find( "ITEM_MapEffect" ) == 0 )
				{
					element->SetAttribute( "useType" , 39 );
					element->SetAttribute( "effect" , atoi( info.explain3.c_str() ) );
				}
				else if ( info.useItem.find( "ITEM_SetLoverUser" ) == 0 )
				{
					element->SetAttribute( "useType" , 40 );
				}
				else if ( info.useItem.find( "ITEM_LoverWarp" ) == 0 )
				{
					element->SetAttribute( "useType" , 41 );
				}
				else if ( info.useItem.find( "ITEM_LoverUnmarry" ) == 0 )
				{
					element->SetAttribute( "useType" , 42 );
				}
				else if ( info.useItem.find( "ITEM_CharaMetamo" ) == 0 )
				{
					element->SetAttribute( "useType" , 43 );

					if ( info.explain3.find( "豆丁囝" ) != -1 )
					{
						element->SetAttribute( "charaMetamo" , 0 );
					}
					else if ( info.explain3.find( "赛亚" ) != -1 )
					{
						element->SetAttribute( "charaMetamo" , 1 );
					}
					else if ( info.explain3.find( "辫子男" ) != -1 )
					{
						element->SetAttribute( "charaMetamo" , 2 );
					}
					else if ( info.explain3.find( "酷哥" ) != -1 )
					{
						element->SetAttribute( "charaMetamo" , 3 );	
					}
					else if ( info.explain3.find( "熊皮男" ) != -1 )
					{
						element->SetAttribute( "charaMetamo" , 4 );	
					}
					else if ( info.explain3.find( "大只佬" ) != -1 )
					{
						element->SetAttribute( "charaMetamo" , 5 );	
					}
					else if ( info.explain3.find( "豆丁囡" ) != -1 )
					{
						element->SetAttribute( "charaMetamo" , 6 );	
					}
					else if ( info.explain3.find( "熊皮妹" ) != -1 )
					{
						element->SetAttribute( "charaMetamo" , 7 );	
					}
					else if ( info.explain3.find( "帽子妹" ) != -1 )
					{
						element->SetAttribute( "charaMetamo"  , 8 );	
					}
					else if ( info.explain3.find( "短发夹" ) != -1 )
					{
						element->SetAttribute( "charaMetamo"  , 9 );	
					}
					else if ( info.explain3.find( "手套女" ) != -1 )
					{
						element->SetAttribute( "charaMetamo"  , 10 );	
					}
					else if ( info.explain3.find( "辣" ) != -1 )
					{
						element->SetAttribute( "charaMetamo"  , 11 );	
					}
					else if ( info.explain3.find( "随机" ) != -1 )
					{
						element->SetAttribute( "charaMetamo"  , -1 );	
					}

					else
					{
						assert( 0 );
					}
					
				}
				else if ( info.useItem.find( "ITEM_SexMetamo" ) == 0 )
				{
					element->SetAttribute( "useType" , 44 );
				}
				else if ( info.useItem.find( "ITEM_ColorMetamo" ) == 0 )
				{
					element->SetAttribute( "useType" , 45 );

					if ( info.explain3.find( "红" ) != -1 )
					{
						element->SetAttribute( "colorMetamo" , 0 );
					}
					else if ( info.explain3.find( "绿" ) != -1 )
					{
						element->SetAttribute( "colorMetamo" , 1 );
					}
					else if ( info.explain3.find( "黄" ) != -1 )
					{
						element->SetAttribute( "colorMetamo" , 2 );
					}
					else if ( info.explain3.find( "灰" ) != -1 )
					{
						element->SetAttribute( "colorMetamo" , 3 );	
					}
					else if ( info.explain3.find( "白" ) != -1 )
					{
						element->SetAttribute( "colorMetamo" , 4 );	
					}
					else if ( info.explain3.find( "黑" ) != -1 )
					{
						element->SetAttribute( "colorMetamo" , 5 );	
					}
					else if ( info.explain3.find( "随" ) != -1 )
					{
						element->SetAttribute( "colorMetamo" , -1 );	
					}
					else
					{
						assert( 0 );
					}

				}
				else if ( info.useItem.find( "ITEM_GMFUNCTION" ) == 0 )
				{
					element->SetAttribute( "useType" , 46 );
				}
				else if ( info.useItem.find( "ITEM_AddFame" ) == 0 )
				{
					element->SetAttribute( "useType" , 46 );
					element->SetAttribute( "fame" , atoi( info.explain3.c_str() ) );
				}
				else if ( info.useItem.find( "ITEM_Luck" ) == 0 )
				{
					element->SetAttribute( "useType" , 47 );

					if ( info.explain3.find( "凶" ) != -1 )
					{
						element->SetAttribute( "luck" , 0 );
					}
					else if ( info.explain3.find( "一般" ) != -1 )
					{
						element->SetAttribute( "luck" , 1 );
					}
					else if ( info.explain3.find( "小" ) != -1 )
					{
						element->SetAttribute( "luck" , 2 );
					}
					else if ( info.explain3.find( "中" ) != -1 )
					{
						element->SetAttribute( "luck" , 3 );
					}
					else if ( info.explain3.find( "大" ) != -1 )
					{
						element->SetAttribute( "luck" , 4 );
					}
					else
					{
						assert( 0 );
					}
				}
				else if ( info.useItem.find( "ITEM_MetamoTime" ) == 0 )
				{
					element->SetAttribute( "useType" , 48 );

					element->SetAttribute( "metamo" , atoi( info.explain3.c_str() ) );

					int n = info.explain3.find( "|" );
					string sub = info.explain3.substr( n + 1 );
					element->SetAttribute( "minute" , atoi( sub.c_str() ) );

				}
				else if ( info.useItem.find( "ITEM_Gold" ) == 0 )
				{
					element->SetAttribute( "useType" , 49 );

					element->SetAttribute( "gold" , atoi( info.explain3.c_str() ) );

				}
				else if ( info.useItem.find( "ITEM_BattlePK" ) == 0 )
				{
					element->SetAttribute( "useType" , 50 );

				}
				else if ( info.useItem.find( "ITEM_VipRide" ) == 0 )
				{
					element->SetAttribute( "useType" , 51 );

				}
				else if ( info.useItem.find( "ITEM_AddMemberPoint" ) == 0 )
				{
					element->SetAttribute( "useType" , 52 );
					element->SetAttribute( "point" , atoi( info.explain3.c_str() ) );
				}
				else if ( info.useItem.find( "ITEM_AddPRSkillPoint" ) == 0 )
				{
					element->SetAttribute( "useType" , 53 );
					element->SetAttribute( "point" , atoi( info.explain3.c_str() ) );
				}
				else if ( info.useItem.find( "ITEM_SetSilentZero" ) == 0 )
				{
					element->SetAttribute( "useType" , 54 );
				}
				else if ( info.useItem.find( "PET_BEATITUDE" ) == 0 )
				{
					element->SetAttribute( "useType" , 55 );
				}
				else if ( info.useItem.find( "ITEM_PetLevelItem" ) == 0 )
				{
					element->SetAttribute( "useType" , 56 );
				}
				else if ( info.useItem.find( "ITEM_ItemPetLocked" ) == 0 )
				{
					element->SetAttribute( "useType" , 57 );
				}
				else if ( info.useItem.find( "ITEM_OnlineCost" ) == 0 )
				{
					element->SetAttribute( "useType" , 58 );
				}
				else if ( info.useItem.find( "ITEM_OldToNew" ) == 0 )
				{
					element->SetAttribute( "useType" , 59 );
				}
				
				else if ( info.useItem.find( "ITEM_firecracker" ) == 0 )
				{
					element->SetAttribute( "useType" , 36 );

					string sub = info.explain3.substr( 5 );
					element->SetAttribute( "kPet0" , atoi( sub.c_str() ) );
					
					int n = info.explain3.find( "_" );
					if ( n >= 0 && n < 6  )
					{
						sub = info.explain3.substr( n + 1 );
						element->SetAttribute( "kPet1" , atoi( sub.c_str() ) );
					}
					n = sub.find( "_" );
					if ( n >= 0 && n < 6  )
					{
						sub = sub.substr( n + 1 );
						element->SetAttribute( "kPet2" , atoi( sub.c_str() ) );
					}
					n = sub.find( "_" );
					if ( n >= 0 && n < 6 )
					{
						sub = sub.substr( n + 1 );
						element->SetAttribute( "kPet3" , atoi( sub.c_str() ) );
					}
					n = sub.find( "_" );
					if ( n >= 0 && n < 6 )
					{
						sub = sub.substr( n + 1 );
						element->SetAttribute( "kPet4" , atoi( sub.c_str() ) );
					}

				}
				else if ( info.useItem.find( "ITEM_useWarpForNum" ) == 0 ||
					info.useItem.find( "ITEM_useWarp" ) == 0 )
				{
					element->SetAttribute( "useType" , 37 );

					int n = info.explain3.find( " " );
					string sub = info.explain3.substr( n + 1 );
					element->SetAttribute( "map" , atoi( sub.c_str() ) );

					n = sub.find( " " );
					sub = sub.substr( n + 1 );
					element->SetAttribute( "x" , atoi( sub.c_str() ) );

					n = sub.find( " " );
					sub = sub.substr( n + 1 );
					element->SetAttribute( "y" , atoi( sub.c_str() ) );

				}
				else
				{
					assert( 0 );
				}
			}
			
			
			if ( info.quaint )
			element->SetAttribute( "quaint" , info.quaint );

// 			if ( info.useItem[ 0 ] != '\0' )
// 			element->SetAttribute( "useItem" , info.useItem.c_str() );

			
 			if ( info.suitEquip[ 0 ] != '\0' )
			{
				if ( info.suitEquip.find( "ITEM_suitEquip" ) == 0 )
				{

					if ( info.explain3.find( "FSTR:" ) != -1 )
					{
						string sub = info.explain3.substr( 5 );
						element->SetAttribute( "suitSTR" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "HP:" ) != -1 )
					{
						string sub = info.explain3.substr( 3 );
						element->SetAttribute( "suitHP" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "MP:" ) != -1 )
					{
						string sub = info.explain3.substr( 3 );
						element->SetAttribute( "suitMP" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "MSTR:" ) != -1 )
					{
						string sub = info.explain3.substr( 5 );
						element->SetAttribute( "suitMSTR" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "MDEX:" ) != -1 )
					{
						string sub = info.explain3.substr( 5 );
						element->SetAttribute( "suitMDEX" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "WAST:" ) != -1 )
					{
						string sub = info.explain3.substr( 5 );
						element->SetAttribute( "suitWAST" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "FTGH:" ) != -1 )
					{
						string sub = info.explain3.substr( 5 );
						element->SetAttribute( "suitFTGH" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "FDEX:" ) != -1 )
					{
						string sub = info.explain3.substr( 5 );
						element->SetAttribute( "suitFDEX" , atoi( sub.c_str() ) );
					} 
					else if ( info.explain3.find( "MTGH:" ) != -1 )
					{
						string sub = info.explain3.substr( 5 );
						element->SetAttribute( "suitMTGH" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "COUNTER:" ) != -1 )
					{
						string sub = info.explain3.substr( 8 );
						element->SetAttribute( "suitCOUNTER" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "M_POW:" ) != -1 )
					{
						string sub = info.explain3.substr( 6 );
						element->SetAttribute( "suitMPOW" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "RESIST:" ) != -1 )
					{
						string sub = info.explain3.substr( 7 );
						element->SetAttribute( "suitRESIST" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "EA:" ) != -1 )
					{
						//string sub = info.explain3.substr( 5 );
						//element->SetAttribute( "suitWAST" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "SUITDEXP:" ) != -1 )
					{
						//string sub = info.explain3.substr( 5 );
						//element->SetAttribute( "suitWAST" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "RENOCASE:" ) != -1 )
					{
						//string sub = info.explain3.substr( 5 );
						//element->SetAttribute( "suitWAST" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "WDUCKPOWER:" ) != -1 )
					{
						//string sub = info.explain3.substr( 5 );
						//element->SetAttribute( "suitWAST" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "SUITPOISON:" ) != -1 )
					{
						//string sub = info.explain3.substr( 5 );
						//element->SetAttribute( "suitWAST" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "M2_POW:" ) != -1 )
					{
						//string sub = info.explain3.substr( 5 );
						//element->SetAttribute( "suitWAST" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "UN_POW_M:" ) != -1 )
					{
						//string sub = info.explain3.substr( 5 );
						//element->SetAttribute( "suitWAST" , atoi( sub.c_str() ) );
					}
					else if (  info.explain3[ 0 ] != '\0' )
					{
						//assert( 0 );
					}
				}
				else if ( info.suitEquip.find( "ITEM_WearEquip" ) == 0 )
				{
					element->SetAttribute( "suitWearEquip" , 1 );
				}
				else if ( info.suitEquip.find( "ITEM_MagicResist" ) == 0 )
				{
					if ( info.explain3.find( "沉默" ) != -1 )
					{
						element->SetAttribute( "suitStatus" , 10 );

						string sub = info.explain3.substr( 4 );
						element->SetAttribute( "suitPower" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "虚弱" ) != -1 )
					{
						element->SetAttribute( "suitStatus" , 11 );

						string sub = info.explain3.substr( 4 );
						element->SetAttribute( "suitPower" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "魔障" ) != -1 )
					{
						element->SetAttribute( "suitStatus" , 9 );

						string sub = info.explain3.substr( 4 );
						element->SetAttribute( "suitPower" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "落马" ) != -1 )
					{
						element->SetAttribute( "suitStatus" , 12 );

						string sub = info.explain3.substr( 4 );
						element->SetAttribute( "suitPower" , atoi( sub.c_str() ) );
					}
					else if ( info.explain3.find( "雷抗" ) != -1 )
					{
						element->SetAttribute( "error" , 1 );
					}
					else if ( info.explain3.find( "冰抗" ) != -1 )
					{
						element->SetAttribute( "error" , 1 );
					}
					else if ( info.explain3.find( "火抗" ) != -1 )
					{
						element->SetAttribute( "error" , 1 );
					}
					else if ( info.explain3.find( "电抗" ) != -1 )
					{
						element->SetAttribute( "error" , 1 );
					}
					else
					{
						assert( 0 );
					}
				}
				else if ( info.suitEquip.find( "ITEM_equipNoenemy" ) == 0 )
				{
					element->SetAttribute( "suitNoenemy" , 1 );
				}
				else if ( info.suitEquip.find( "ITEM_randEnemyEquip" ) == 0 )
				{
					element->SetAttribute( "suitRandEnemy" , 100 );
				}
				else if ( info.suitEquip.find( "ITEM_MagicEquitWear" ) == 0 )
				{
					element->SetAttribute( "suitEA" , 10 );
					element->SetAttribute( "suitWA" , 10 );
					element->SetAttribute( "suitFI" , 10 );
					element->SetAttribute( "suitWI" , 10 );
				}
				else if ( info.suitEquip.find( "ITEM_useMRecovery" ) == 0 )
				{
					//element->SetAttribute( "drop" , atoi( info.explain3.c_str() ) );
				}
				else
				{
					assert( 0 );
				}
			}

			if ( info.resuitEquip[ 0 ] != '\0' )
			{
				
			}

			
			if ( info.dropItem[ 0 ] != '\0' )
			{
				if ( info.dropItem.find( "ITEM_PutOrnaments" ) == 0 )
				{
					element->SetAttribute( "dropItem" , atoi( info.explain3.c_str() ) );
				}
				else if ( info.dropItem.find( "ITEM_dropDice" ) == 0 )
				{
					element->SetAttribute( "dropDice" , 1 );
				}
				else if ( info.dropItem.find( "ITEM_dropMic" ) == 0 )
				{
					element->SetAttribute( "dropMic" , 1 );
				}
				else
				{
					assert( 0 );
				}
				
			}
			if ( info.pickupItem[ 0 ] != '\0' )
			{
				if ( info.pickupItem.find( "ITEM_PutOrnaments" ) == 0 )
				{
					//element->SetAttribute( "pickup" , atoi( info.explain3.c_str() ) );
				}
				else
				{
					//assert( 0 );
				}

			}
			
			if ( info.autoResume[ 0 ] != '\0' )
			element->SetAttribute( "autoResume" , info.autoResume.c_str() );

			if ( info.id )
			element->SetAttribute( "id" , info.id );
			if ( info.img )
			element->SetAttribute( "img" , info.img );
			if ( info.sell )
			element->SetAttribute( "sell" , info.sell );
			if ( info.type )
			element->SetAttribute( "type" , info.type );
			if ( info.stage )
			element->SetAttribute( "stage" , info.stage );
			if ( info.range )
			element->SetAttribute( "range" , info.range );
			if ( info.level )
			element->SetAttribute( "level" , info.level );
			if ( info.num )
			element->SetAttribute( "num" , info.num );
			if ( info.alchemyAttr )
			element->SetAttribute( "alchemyAttr" , info.alchemyAttr );

			if ( info.suit )
			element->SetAttribute( "suit" , info.suit );
			if ( info.perdure1 )
			element->SetAttribute( "perdure1" , info.perdure1 );
			if ( info.perdure2 )
			element->SetAttribute( "perdure2" , info.perdure2 );
			if ( info.increase )
			element->SetAttribute( "increase" , info.increase );
			if ( info.decrease )
			element->SetAttribute( "decrease" , info.decrease );
			if ( info.code )
			element->SetAttribute( "code" , info.code );

			if ( info.attackNum1 )
			element->SetAttribute( "attackNum1" , info.attackNum1 );
			if ( info.attackNum2 )
			element->SetAttribute( "attackNum2" , info.attackNum2 );
			if ( info.str1 )
			element->SetAttribute( "str1" , info.str1 );
			if ( info.str2 )
			element->SetAttribute( "str2" , info.str2 );
			if ( info.tgh1 )
			element->SetAttribute( "tgh1" , info.tgh1 );
			if ( info.tgh2 )
			element->SetAttribute( "tgh2" , info.tgh2 );
			if ( info.dex1 )
			element->SetAttribute( "dex1" , info.dex1 );
			if ( info.dex2 )
			element->SetAttribute( "dex2" , info.dex2 );
			if ( info.hp1 )
			element->SetAttribute( "hp1" , info.hp1 );
			if ( info.hp2 )
			element->SetAttribute( "hp2" , info.hp2 );
			if ( info.mp1 )
			element->SetAttribute( "mp1" , info.mp1 );
			if ( info.mp2 )
			element->SetAttribute( "mp2" , info.mp2 );
			if ( info.luck1 )
			element->SetAttribute( "luck1" , info.luck1 );
			if ( info.luck2 )
			element->SetAttribute( "luck2" , info.luck2 );
			if ( info.Charm1 )
			element->SetAttribute( "charm1" , info.Charm1 );
			if ( info.Charm2 )
			element->SetAttribute( "charm2" , info.Charm2 );
			if ( info.dodge1 )
			element->SetAttribute( "dodge1" , info.dodge1 );
			if ( info.dodge2 )
			element->SetAttribute( "dodge2" , info.dodge2 );
			if ( info.attrType )
			element->SetAttribute( "attrType" , info.attrType );
			if ( info.attr )
			element->SetAttribute( "attr" , info.attr );

			if ( info.magic )
			element->SetAttribute( "magic" , info.magic );
			if ( info.rare )
			element->SetAttribute( "rare" , info.rare );
			if ( info.mp )
			element->SetAttribute( "mp" , info.mp );
			if ( info.ward )
			element->SetAttribute( "ward" , info.ward );
			if ( info.attackRank )
			element->SetAttribute( "attackRank" , info.attackRank );
			if ( info.weight )
			element->SetAttribute( "weight" , info.weight );
			
			
			if ( info.Poison1 )
			element->SetAttribute( "poison1" , info.Poison1 );
			if ( info.Poison2 )
			element->SetAttribute( "poison2" , info.Poison2 );
			if ( info.Paralysis1 )
			element->SetAttribute( "paralysis1" , info.Paralysis1 );
			if ( info.Paralysis2 )
			element->SetAttribute( "paralysis2" , info.Paralysis2 );
			if ( info.Sleep1 )
			element->SetAttribute( "sleep1" , info.Sleep1 );
			if ( info.Sleep2 )
			element->SetAttribute( "sleep2" , info.Sleep2 );
			if ( info.Stone1 )
			element->SetAttribute( "stone1" , info.Stone1 );
			if ( info.Stone2 )
			element->SetAttribute( "stone2" , info.Stone2 );
			if ( info.Drunk1 )
			element->SetAttribute( "drunk1" , info.Drunk1 );
			if ( info.Drunk2 )
			element->SetAttribute( "drunk2" , info.Drunk2 );
			if ( info.Confusion1 )
			element->SetAttribute( "confusion1" , info.Confusion1 );
			if ( info.Confusion2 )
			element->SetAttribute( "confusion2" , info.Confusion2 );
			if ( info.Critical1 )
			element->SetAttribute( "critical1" , info.Critical1 );
			if ( info.Critical2 )
			element->SetAttribute( "critical2" , info.Critical2 );

			if ( info.trade )
			element->SetAttribute( "trade" , info.trade );
			if ( info.lose )
			element->SetAttribute( "lose" , info.lose );
			if ( info.drop )
			element->SetAttribute( "drop" , info.drop );
			if ( info.logout )
			element->SetAttribute( "logout" , info.logout );
			if ( info.save )
			element->SetAttribute( "save" , info.save );
			if ( info.store )
			element->SetAttribute( "store" , info.store );
			if ( info.alchemy )
			element->SetAttribute( "alchemy" , info.alchemy );

            
			for ( int i = 0 ; i < 5 ; i++ )
			{
				string str = info.material[ i ];
				int num = info.materialNum[ i ];

				char buff[ 32 ];
                sprintf( buff , "material%d" , i );
				string material = buff;
                sprintf( buff , "materialNum%d" , i );
				string materialNum = buff;

				if ( str[ 0 ] == '\0' )
				{
					continue;
				}

				int t = 0;

				if ( str.find( "石" ) == 0 )
				{
					t = 0;
				}
				else if ( str.find( "木" ) == 0 )
				{
					 t = 1;
				}
				else if ( str.find( "皮" ) == 0 )
				{
					t = 2;
				}
				else if ( str.find( "骨" ) == 0 )
				{
					t = 3;
				}
				else if ( str.find( "线" ) == 0 )
				{
					t = 4;
				}
				else if ( str.find( "鳞" ) == 0 )
				{
					t = 5;
				}
				else if ( str.find( "叶" ) == 0 )
				{
					t = 6;
				}
				else if ( str.find( "土" ) == 0 )
				{
					t = 7;
				}
				else if ( str.find( "贝" ) == 0 )
				{
					t = 8;
				}
				else if ( str.find( "壳" ) == 0 )
				{
					t = 9;
				}
				else if ( str.find( "爪" ) == 0 )
				{
					t = 10;
				}
				else if ( str.find( "水晶" ) == 0 )
				{
					t = 11;
				}
				else if ( str.find( "花" ) == 0 )
				{
					t = 12;
				}
				else if ( str.find( "牙" ) == 0 )
				{
					t = 13;
				}
				else if ( str.find( "黏土" ) == 0 )
				{
					t = 14;
				}

				else if ( str.find( "毒" ) == 0 )
				{
					t = 20;
				}
				else if ( str.find( "混乱" ) == 0 )
				{
					t = 22;
				}
				else if ( str.find( "酒醉" ) == 0 )
				{
					t = 24;
				}
				else if ( str.find( "昏睡" ) == 0 )
				{
					t = 25;
				}
				else if ( str.find( "回复" ) == 0 )
				{
					t = 26;
				}
				else if ( str.find( "复活" ) == 0 )
				{
					t = 27;
				}

				else if ( str.find( "忠A" ) == 0 )
				{
					t = 30;
				}
				else if ( str.find( "忠B" ) == 0 )
				{
					t = 31;
				}

				else if ( str.find( "地" ) == 0 )
				{
					t = 50;
				}
				else if ( str.find( "水" ) == 0 )
				{
					t = 51;
				}
				else if ( str.find( "火" ) == 0 )
				{
					t = 52;
				}
				else if ( str.find( "风" ) == 0 )
				{
					t = 53;
				}

				else if ( str.find( "橡树果" ) == 0 )
				{
					t = 100;
				}
				else if ( str.find( "豆" ) == 0 )
				{
					t = 101;
				}
				else if ( str.find( "碳火" ) == 0 )
				{
					t = 102;
				}
				else if ( str.find( "砂糖" ) == 0 )
				{
					t = 103;
				}
				else if ( str.find( "香草" ) == 0 )
				{
					t = 104;
				}
				else if ( str.find( "肉" ) == 0 )
				{
					t = 105;
				}
				else if ( str.find( "鱼" ) == 0 )
				{
					t = 106;
				}
				else if ( str.find( "串" ) == 0 )
				{
					t = 107;
				}
				else if ( str.find( "卵" ) == 0 )
				{
					t = 108;
				}
				else if ( str.find( "饮用水" ) == 0 )
				{
					t = 109;
				}
				else if ( str.find( "盐" ) == 0 )
				{
					t = 110;
				}
				else if ( str.find( "虾" ) == 0 )
				{
					t = 111;
				}
				else if ( str.find( "螃蟹" ) == 0 )
				{
					t = 112;
				}
				else if ( str.find( "章鱼" ) == 0 )
				{
					t = 113;
				}
				else if ( str.find( "大蒜" ) == 0 )
				{
					t = 114;
				}
				else if ( str.find( "葱" ) == 0 )
				{
					t = 115;
				}
				else if ( str.find( "胡椒" ) == 0 )
				{
					t = 116;
				}
				else if ( str.find( "香菇" ) == 0 )
				{
					t = 117;
				}
				else if ( str.find( "米" ) == 0 )
				{
					t = 118;
				}
				else if ( str.find( "海草" ) == 0 )
				{
					t = 119;
				}
				else if ( str.find( "苹果" ) == 0 )
				{
					t = 120;
				}
				else if ( str.find( "蜥蜴" ) == 0 )
				{
					t = 121;
				}
				else if ( str.find( "海星" ) == 0 )
				{
					t = 122;
				}
				else if ( str.find( "青蛙" ) == 0 )
				{
					t = 123;
				}
				else if ( str.find( "生姜" ) == 0 )
				{
					t = 124;
				}
				else if ( str.find( "芦笋" ) == 0 )
				{
					t = 125;
				}
				else if ( str.find( "红萝卜" ) == 0 )
				{
					t = 126;
				}
				else if ( str.find( "马铃薯" ) == 0 )
				{
					t = 127;
				}
				else if ( str.find( "梨" ) == 0 )
				{
					t = 128;
				}
				else if ( str.find( "樱桃" ) == 0 )
				{
					t = 129;
				}
				else if ( str.find( "竹笋" ) == 0 )
				{
					t = 130;
				}
				else if ( str.find( "葡萄" ) == 0 )
				{
					t = 131;
				}
				else if ( str.find( "谷" ) == 0 )
				{
					t = 132;
				}
				else if ( str.find( "包心菜" ) == 0 )
				{
					t = 133;
				}
				else if ( str.find( "青椒" ) == 0 )
				{
					t = 134;
				}
				else if ( str.find( "蕃茄" ) == 0 )
				{
					t = 135;
				}
				else if ( str.find( "茄子" ) == 0 )
				{
					t = 136;
				}
				else if ( str.find( "小黄瓜" ) == 0 )
				{
					t = 137;
				}
				else if ( str.find( "桃" ) == 0 )
				{
					t = 138;
				}
				else if ( str.find( "草莓" ) == 0 )
				{
					t = 139;
				}
				else if ( str.find( "油" ) == 0 )
				{
					t = 140;
				}
				else if ( str.find( "橘子" ) == 0 )
				{
					t = 141;
				}
				else if ( str.find( "柿子" ) == 0 )
				{
					t = 142;
				}
				else if ( str.find( "白菜" ) == 0 )
				{
					t = 143;
				}
				else if ( str.find( "南瓜" ) == 0 )
				{
					t = 144;
				}
				else if ( str.find( "味精" ) == 0 )
				{
					t = 145;
				}
				else if ( str.find( "高汤" ) == 0 )
				{
					t = 146;
				}


				else if ( str.find( "铁" ) == 0 )
				{
					t = 200;
				}
				else if ( str.find( "铜" ) == 0 )
				{
					t = 201;
				}
				else if ( str.find( "钻石" ) == 0 )
				{
					t = 202;
				}
				else if ( str.find( "红宝石" ) == 0 )
				{
					t = 203;
				}
				else if ( str.find( "蓝宝石" ) == 0 )
				{
					t = 204;
				}
				else if ( str.find( "绿宝石" ) == 0 )
				{
					t = 205;
				}
				else if ( str.find( "黄宝石" ) == 0 )
				{
					t = 206;
				}
				else if ( str.find( "珍珠" ) == 0 )
				{
					t = 207;
				}

				else if ( str.find( "恒冰结晶" ) == 0 )
				{
					t = 300;
				}
				else if ( str.find( "暴龙的尖牙" ) == 0 )
				{
					t = 301;
				}
				else if ( str.find( "蝎子的刺" ) == 0 )
				{
					t = 302;
				}
				else if ( str.find( "巨象的骨头" ) == 0 )
				{
					t = 303;
				}
				else if ( str.find( "海龙的骨头" ) == 0 )
				{
					t = 304;
				}
				else if ( str.find( "龙蜥的皮" ) == 0 )
				{
					t = 305;
				}
				else if ( str.find( "雷龙的骨头" ) == 0 )
				{
					t = 306;
				}
				else if ( str.find( "老虎的骨头" ) == 0 )
				{
					t = 307;
				}
				else if ( str.find( "人鱼的皮" ) == 0 )
				{
					t = 308;
				}

				else if ( str.find( "炼金粉末" ) == 0 )
				{
					t = 309;
				}

				else if ( str.find( "雷尔一" ) == 0 )
				{
					t = 320;
				}
				else if ( str.find( "雷尔二" ) == 0 )
				{
					t = 321;
				}
				else if ( str.find( "雷尔三" ) == 0 )
				{
					t = 322;
				}

				else if ( str.find( "海盗一" ) == 0 )
				{
					t = 323;
				}
				else if ( str.find( "海盗二" ) == 0 )
				{
					t = 324;
				}
				else if ( str.find( "海盗三" ) == 0 )
				{
					t = 325;
				}

				else if ( str.find( "奶牛一" ) == 0 )
				{
					t = 326;
				}
				else if ( str.find( "奶牛二" ) == 0 )
				{
					t = 327;
				}
				else if ( str.find( "奶牛三" ) == 0 )
				{
					t = 328;
				}

				else if ( str.find( "忍者一" ) == 0 )
				{
					t = 329;
				}
				else if ( str.find( "忍者二" ) == 0 )
				{
					t = 330;
				}
				else if ( str.find( "忍者三" ) == 0 )
				{
					t = 331;
				}

				else if ( str.find( "绅士一" ) == 0 )
				{
					t = 332;
				}
				else if ( str.find( "绅士二" ) == 0 )
				{
					t = 333;
				}
				else if ( str.find( "绅士三" ) == 0 )
				{
					t = 334;
				}
					
				else
				{
 					assert( 0 );
				}

				element->SetAttribute( material.c_str() , t );
				element->SetAttribute( materialNum.c_str() , info.materialNum[ i ] );
			}
// 
// 			element->SetAttribute( "material1" , info.material[ 1 ].c_str() );
// 			element->SetAttribute( "materialNum1" , info.materialNum[ 1 ] );
// 			element->SetAttribute( "material2" , info.material[ 1 ].c_str() );
// 			element->SetAttribute( "materialNum2" , info.materialNum[ 1 ] );
// 			element->SetAttribute( "material3" , info.material3.c_str() );
// 			element->SetAttribute( "materialNum3" , info.materialNum3 );
// 			element->SetAttribute( "material4" , info.material4.c_str() );
// 			element->SetAttribute( "materialNum4" , info.materialNum4 );
// 			element->SetAttribute( "material5" , info.material5.c_str() );
// 			element->SetAttribute( "materialNum5" , info.materialNum5 );

		}
	}

	doc->Save( "c:\\work\\1.xml" , false );
}


fvoid		SaveEnemyCount()
{
	crtIFileSystem* fileSystem = crtManager::GetFileSystem();
	crtIReadFile* readFile = fileSystem->CreateAndOpenFile( "E:\\shiqicc95\\sss\\gmsv\\data\\encount.txt" );
	char read;
	string strRead;
	string subStr;

	xmlDocument* doc = CreatXMLDocument();
	xmlElement* root = CreatXMLElement( doc , "root" );
	doc->LinkEndChild( root );


	while ( readFile->Read( &read , 1 ) )
	{
		strRead += read;

		if ( read == '\n' )
		{
			EnemyCount ec;

			int n = strRead.find( "," );

			if ( n == -1 )
			{
				strRead.clear();
				continue;
			}

			
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			ec.id = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			ec.mapID = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			ec.x1 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			ec.y1 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			ec.x2 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			ec.y2 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			ec.min = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			ec.max = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			ec.num = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			ec.unkown = atoi( subStr.c_str() );


			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			ec.group0 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			ec.group1 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			ec.group2 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			ec.group3 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			ec.group4 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			ec.group5 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			ec.group6 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			ec.group7 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			ec.group8 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			ec.group9 = atoi( subStr.c_str() );


			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			ec.groupPro0 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			ec.groupPro1 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			ec.groupPro2 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			ec.groupPro3 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			ec.groupPro4 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			ec.groupPro5 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			ec.groupPro6 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			ec.groupPro7 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			ec.groupPro8 = atoi( subStr.c_str() );


			subStr = strRead;
			ec.groupPro9 = atoi( subStr.c_str() );






			strRead.clear();


			xmlElement* element = CreatXMLElement( doc , "enemy" );
			root->LinkEndChild( element );


			element->SetAttribute( "id" , ec.id );
			element->SetAttribute( "mapID" , ec.mapID );

			element->SetAttribute( "x1" , ec.x1 );
			element->SetAttribute( "y1" , ec.y1 );
			element->SetAttribute( "x2" , ec.x2 );
			element->SetAttribute( "y2" , ec.y2 );

			element->SetAttribute( "min" , ec.min );
			element->SetAttribute( "max" , ec.max );
			element->SetAttribute( "num" , ec.num );

			element->SetAttribute( "unkown" , ec.unkown );

			element->SetAttribute( "group0" , ec.group0 );
			element->SetAttribute( "group1" , ec.group1 );
			element->SetAttribute( "group2" , ec.group2 );
			element->SetAttribute( "group3" , ec.group3 );
			element->SetAttribute( "group4" , ec.group4 );
			element->SetAttribute( "group5" , ec.group5 );
			element->SetAttribute( "group6" , ec.group6 );
			element->SetAttribute( "group7" , ec.group7 );
			element->SetAttribute( "group8" , ec.group8 );
			element->SetAttribute( "group9" , ec.group9 );

			element->SetAttribute( "groupPro0" , ec.groupPro0 );
			element->SetAttribute( "groupPro1" , ec.groupPro1 );
			element->SetAttribute( "groupPro2" , ec.groupPro2 );
			element->SetAttribute( "groupPro3" , ec.groupPro3 );
			element->SetAttribute( "groupPro4" , ec.groupPro4 );
			element->SetAttribute( "groupPro5" , ec.groupPro5 );
			element->SetAttribute( "groupPro6" , ec.groupPro6 );
			element->SetAttribute( "groupPro7" , ec.groupPro7 );
			element->SetAttribute( "groupPro8" , ec.groupPro8 );
			element->SetAttribute( "groupPro9" , ec.groupPro9 );
		}
	}

	doc->Save( "E:/1.xml" , false );
}



fvoid		SaveGroup()
{
	crtIFileSystem* fileSystem = crtManager::GetFileSystem();
	crtIReadFile* readFile = fileSystem->CreateAndOpenFile( "E:\\shiqicc95\\sss\\gmsv\\data\\group1.txt" );
	char read;
	string strRead;
	string subStr;

	xmlDocument* doc = CreatXMLDocument();
	xmlElement* root = CreatXMLElement( doc , "root" );
	doc->LinkEndChild( root );


	while ( readFile->Read( &read , 1 ) )
	{
		strRead += read;

		if ( read == '\n' )
		{
			group g;

			int n = strRead.find( "," );

			if ( n == -1 )
			{
				strRead.clear();
				continue;
			}

			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			g.name = subStr;

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			g.id = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			g.item0 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			g.item1 = atoi( subStr.c_str() );

		
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			g.enemy0 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			g.enemy1 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			g.enemy2 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			g.enemy3 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			g.enemy4 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			g.enemy5 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			g.enemy6 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			g.enemy7 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			g.enemy8 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			g.enemy9 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			g.enemyPro0 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			g.enemyPro1 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			g.enemyPro2 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			g.enemyPro3 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			g.enemyPro4 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			g.enemyPro5 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			g.enemyPro6 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			g.enemyPro7 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			g.enemyPro8 = atoi( subStr.c_str() );
			

			subStr = strRead;
			g.enemyPro9 = atoi( subStr.c_str() );






			strRead.clear();


 			xmlElement* element = CreatXMLElement( doc , "enemy" );
 			root->LinkEndChild( element );
 
 
 			element->SetAttribute( "name" , g.name.c_str() );
 
 			element->SetAttribute( "id" , g.id );
 			
 
 			element->SetAttribute( "item0" , g.item0 );
 			element->SetAttribute( "item1" , g.item1 );
 			
 
 		
 
 			element->SetAttribute( "enemy0" , g.enemy0 );
 			element->SetAttribute( "enemy1" , g.enemy1 );
 			element->SetAttribute( "enemy2" , g.enemy2 );
 			element->SetAttribute( "enemy3" , g.enemy3 );
 			element->SetAttribute( "enemy4" , g.enemy4 );
 			element->SetAttribute( "enemy5" , g.enemy5 );
 			element->SetAttribute( "enemy6" , g.enemy6 );
 			element->SetAttribute( "enemy7" , g.enemy7 );
 			element->SetAttribute( "enemy8" , g.enemy8 );
 			element->SetAttribute( "enemy9" , g.enemy9 );
 
			element->SetAttribute( "enemyPro0" , g.enemyPro0 );
			element->SetAttribute( "enemyPro1" , g.enemyPro1 );
			element->SetAttribute( "enemyPro2" , g.enemyPro2 );
			element->SetAttribute( "enemyPro3" , g.enemyPro3 );
			element->SetAttribute( "enemyPro4" , g.enemyPro4 );
			element->SetAttribute( "enemyPro5" , g.enemyPro5 );
			element->SetAttribute( "enemyPro6" , g.enemyPro6 );
			element->SetAttribute( "enemyPro7" , g.enemyPro7 );
			element->SetAttribute( "enemyPro8" , g.enemyPro8 );
			element->SetAttribute( "enemyPro9" , g.enemyPro9 );



		}
	}

	doc->Save( "E:/1.xml" , false );
}


fvoid		SaveMonster()
{
	crtIFileSystem* fileSystem = crtManager::GetFileSystem();
	crtIReadFile* readFile = fileSystem->CreateAndOpenFile( "E:\\shiqicc95\\sss\\gmsv\\data\\enemy1.txt" );
	char read;
	string strRead;
	string subStr;

	xmlDocument* doc = CreatXMLDocument();
	xmlElement* root = CreatXMLElement( doc , "root" );
	doc->LinkEndChild( root );


	while ( readFile->Read( &read , 1 ) )
	{
		strRead += read;

		if ( read == '\n' )
		{
			enemy e;

			int n = strRead.find( "," );

			if ( n == -1 )
			{
				strRead.clear();
				continue;
			}

			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.name = subStr;


			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );

			while ( subStr.find( "|" ) != -1 )
			{
				n = subStr.find( "|" );

				subStr[ n ] = '\0';
				string s = subStr;
				subStr.erase( 0 , n + 1 );
				string ss;
				ss += s[0];
				ss += s[1];
				ss += s[2];

				if ( ss == "at:" )
				{
					s.erase( 0 , 3 );
					string sss;
					sss += s[0];
					e.attack = atoi( sss.c_str() );
					s.erase( 0 , 2 );
					sss.clear();
					sss += s[0];
					e.attackTarget = atoi( sss.c_str() );
					s.erase( 0 , 2 );
					sss.clear();
					sss += s[0];
					e.attackAI = atoi( sss.c_str() );
				}
				if ( ss == "gu:" )
				{
					s.erase( 0 , 3 );
					string sss;
					sss += s[0];
					e.defence = atoi( sss.c_str() );
				}
				if ( ss == "ma:" )
				{
					s.erase( 0 , 3 );
					string sss;
					sss += s[0];
					e.magic = atoi( sss.c_str() );
				}
				if ( ss == "es:" )
				{
					s.erase( 0 , 3 );
					string sss;
					sss += s[0];
					e.escape = atoi( sss.c_str() );
				}
				if ( ss == "rn:" )
				{
					s.erase( 0 , 3 );
					string sss;
					sss += s[0];
					e.rn = atoi( sss.c_str() );
				}
			}

			string sss;
			subStr.erase( 0 , 3 );
			sss += subStr[0];
			e.wa0 = atoi( sss.c_str() );
			sss.clear();
			subStr.erase( 0 , 2 );
			sss.clear();
			sss += subStr[0];
			e.wa1 = atoi( sss.c_str() );
			subStr.erase( 0 , 2 );
			sss.clear();
			sss += subStr[0];
			e.wa2 = atoi( sss.c_str() );
			subStr.erase( 0 , 2 );
			sss.clear();
			sss += subStr[0];
			e.wa3 = atoi( sss.c_str() );
			subStr.erase( 0 , 2 );
			sss.clear();
			sss += subStr[0];
			e.wa4 = atoi( sss.c_str() );
			subStr.erase( 0 , 2 );
			sss.clear();
			sss += subStr[0];
			e.wa5 = atoi( sss.c_str() );
			subStr.erase( 0 , 2 );
			sss.clear();
			sss += subStr[0];
			e.wa6 = atoi( sss.c_str() );


			

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.unknow = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.id = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.baseID = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.levelMin = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.levelMax = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.numMax = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.numMin = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.fight = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.exp = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.dp = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.type = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.pet = atoi( subStr.c_str() );



			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.item0 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.item1 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.item2 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.item3 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.item4 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.item5 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.item6 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.item7 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.item8 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.item9 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.itemPro0 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.itemPro1 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.itemPro2 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.itemPro3 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.itemPro4 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.itemPro5 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.itemPro6 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.itemPro7 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			e.itemPro8 = atoi( subStr.c_str() );
			
			subStr = strRead;
			e.itemPro9 = atoi( subStr.c_str() );





			strRead.clear();


			xmlElement* element = CreatXMLElement( doc , "enemy" );
			root->LinkEndChild( element );


			element->SetAttribute( "name" , e.name.c_str() );

			element->SetAttribute( "id" , e.id );
			element->SetAttribute( "baseID" , e.baseID );

			element->SetAttribute( "attack" , e.attack );
			element->SetAttribute( "attackTarget" , e.attackTarget );
			element->SetAttribute( "attackAI" , e.attackAI );

			element->SetAttribute( "defence" , e.defence );
			element->SetAttribute( "magic" , e.magic );
			element->SetAttribute( "escape" , e.escape );

			element->SetAttribute( "wa0" , e.wa0 );
			element->SetAttribute( "wa1" , e.wa1 );
			element->SetAttribute( "wa2" , e.wa2 );
			element->SetAttribute( "wa3" , e.wa3 );
			element->SetAttribute( "wa4" , e.wa4 );
			element->SetAttribute( "wa5" , e.wa5 );
			element->SetAttribute( "wa6" , e.wa6 );

			element->SetAttribute( "rn" , e.rn );

			element->SetAttribute( "unknow" , e.unknow );

			element->SetAttribute( "levelMin" , e.levelMin );
			element->SetAttribute( "levelMax" , e.levelMax );
			element->SetAttribute( "numMax" , e.numMax );
			element->SetAttribute( "numMin" , e.numMin );

			element->SetAttribute( "fight" , e.fight );
			element->SetAttribute( "exp" , e.exp );
			element->SetAttribute( "dp" , e.dp );
			element->SetAttribute( "type" , e.type );
			element->SetAttribute( "pet" , e.pet );

			element->SetAttribute( "item0" , e.item0 );
			element->SetAttribute( "item1" , e.item1 );
			element->SetAttribute( "item2" , e.item2 );
			element->SetAttribute( "item3" , e.item3 );
			element->SetAttribute( "item4" , e.item4 );
			element->SetAttribute( "item5" , e.item5 );
			element->SetAttribute( "item6" , e.item6 );
			element->SetAttribute( "item7" , e.item7 );
			element->SetAttribute( "item8" , e.item8 );
			element->SetAttribute( "item9" , e.item9 );

			element->SetAttribute( "itemPro0" , e.itemPro0 );
			element->SetAttribute( "itemPro1" , e.itemPro1 );
			element->SetAttribute( "itemPro2" , e.itemPro2 );
			element->SetAttribute( "itemPro3" , e.itemPro3 );
			element->SetAttribute( "itemPro4" , e.itemPro4 );
			element->SetAttribute( "itemPro5" , e.itemPro5 );
			element->SetAttribute( "itemPro6" , e.itemPro6 );
			element->SetAttribute( "itemPro7" , e.itemPro7 );
			element->SetAttribute( "itemPro8" , e.itemPro8 );
			element->SetAttribute( "itemPro9" , e.itemPro9 );



		}
	}

	doc->Save( "E:/1.xml" , false );
}




fvoid		SaveMonsterBase()
{
	crtIFileSystem* fileSystem = crtManager::GetFileSystem();
	crtIReadFile* readFile = fileSystem->CreateAndOpenFile( "C:\\work\\shiqicc95\\sss\\gmsv\\data\\enemybase1.txt" );
	char read;
	string strRead;
	string subStr;

	xmlDocument* doc = CreatXMLDocument();
	xmlElement* root = CreatXMLElement( doc , "root" );
	doc->LinkEndChild( root );


	while ( readFile->Read( &read , 1 ) )
	{
		strRead += read;

		if ( read == '\n' )
		{
			enemybase eb;

			int n = strRead.find( "," );

			if ( n == -1 )
			{
				strRead.clear();
				continue;
			}

			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.name = subStr;
			
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.alchemy[ 0 ] = subStr;

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.alchemy[ 1 ] = subStr;

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.alchemy[ 2 ]= subStr;

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.alchemy[ 3 ] = subStr;

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.alchemy[ 4 ] = subStr;


			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.id = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.initNum = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.levelUpPoint = atof( subStr.c_str() );


			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.baseVitality = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.baseStrength = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.baseToughness = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.baseDexterity = atoi( subStr.c_str() );



			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.ai = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.get = atoi( subStr.c_str() );



			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.earth = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.water = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.fire = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.wind = atoi( subStr.c_str() );



			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.poison = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.paralysis = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.sleep = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.stone = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.drunk = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.confusion = atoi( subStr.c_str() );




			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.petSkill0 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.petSkill1 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.petSkill2 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.petSkill3 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.petSkill4 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.petSkill5 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.petSkill6 = atoi( subStr.c_str() );


			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.rare = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.critical = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.counter = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.slot = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.imgNum = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.petFlag = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.size = atoi( subStr.c_str() );



			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.ATOMBASEADD0 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.ATOMFIXMIN0 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.ATOMFIXMAX0 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.ATOMBASEADD1 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.ATOMFIXMIN1 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.ATOMFIXMAX1 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.ATOMBASEADD2 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.ATOMFIXMIN2 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.ATOMFIXMAX2 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.ATOMBASEADD3 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.ATOMFIXMIN3 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.ATOMFIXMAX3 = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.ATOMBASEADD4 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.ATOMFIXMIN4 = atoi( subStr.c_str() );
			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.ATOMFIXMAX4 = atoi( subStr.c_str() );


			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.limitLevel = atoi( subStr.c_str() );

			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			eb.amalgamation = atoi( subStr.c_str() );

			strRead.clear();


			xmlElement* element = CreatXMLElement( doc , "enemy" );
			root->LinkEndChild( element );


			element->SetAttribute( "name" , eb.name.c_str() );
			
			for ( int i = 0 ; i < 5 ; i++ )
			{
				string str = eb.alchemy[ i ];
                

                char buff[ 32 ];
                sprintf( buff , "material%d" , i );
				string material = buff;
                sprintf( buff , "materialNum%d" , i );
				string materialNum = buff;
                
				if ( str[ 0 ] == '\0' )
				{
					continue;
				}

				int t = 0;

				if ( str.find( "石" ) == 0 )
				{
					t = 0;
				}
				else if ( str.find( "木" ) == 0 )
				{
					t = 1;
				}
				else if ( str.find( "皮" ) == 0 )
				{
					t = 2;
				}
				else if ( str.find( "骨" ) == 0 )
				{
					t = 3;
				}
				else if ( str.find( "线" ) == 0 )
				{
					t = 4;
				}
				else if ( str.find( "鳞" ) == 0 )
				{
					t = 5;
				}
				else if ( str.find( "叶" ) == 0 )
				{
					t = 6;
				}
				else if ( str.find( "土" ) == 0 )
				{
					t = 7;
				}
				else if ( str.find( "贝" ) == 0 )
				{
					t = 8;
				}
				else if ( str.find( "壳" ) == 0 )
				{
					t = 9;
				}
				else if ( str.find( "爪" ) == 0 )
				{
					t = 10;
				}
				else if ( str.find( "水晶" ) == 0 )
				{
					t = 11;
				}
				else if ( str.find( "花" ) == 0 )
				{
					t = 12;
				}
				else if ( str.find( "牙" ) == 0 )
				{
					t = 13;
				}
				else if ( str.find( "黏土" ) == 0 )
				{
					t = 14;
				}

				else if ( str.find( "毒" ) == 0 )
				{
					t = 20;
				}
				else if ( str.find( "混乱" ) == 0 )
				{
					t = 22;
				}
				else if ( str.find( "酒醉" ) == 0 )
				{
					t = 24;
				}
				else if ( str.find( "昏睡" ) == 0 )
				{
					t = 25;
				}
				else if ( str.find( "回复" ) == 0 )
				{
					t = 26;
				}
				else if ( str.find( "复活" ) == 0 )
				{
					t = 27;
				}

				else if ( str.find( "忠A" ) == 0 )
				{
					t = 30;
				}
				else if ( str.find( "忠B" ) == 0 )
				{
					t = 31;
				}

				else if ( str.find( "地" ) == 0 )
				{
					t = 50;
				}
				else if ( str.find( "水" ) == 0 )
				{
					t = 51;
				}
				else if ( str.find( "火" ) == 0 )
				{
					t = 52;
				}
				else if ( str.find( "风" ) == 0 )
				{
					t = 53;
				}

				else if ( str.find( "橡树果" ) == 0 )
				{
					t = 100;
				}
				else if ( str.find( "豆" ) == 0 )
				{
					t = 101;
				}
				else if ( str.find( "碳火" ) == 0 )
				{
					t = 102;
				}
				else if ( str.find( "砂糖" ) == 0 )
				{
					t = 103;
				}
				else if ( str.find( "香草" ) == 0 )
				{
					t = 104;
				}
				else if ( str.find( "肉" ) == 0 )
				{
					t = 105;
				}
				else if ( str.find( "鱼" ) == 0 )
				{
					t = 106;
				}
				else if ( str.find( "串" ) == 0 )
				{
					t = 107;
				}
				else if ( str.find( "卵" ) == 0 )
				{
					t = 108;
				}
				else if ( str.find( "饮用水" ) == 0 )
				{
					t = 109;
				}
				else if ( str.find( "盐" ) == 0 )
				{
					t = 110;
				}
				else if ( str.find( "虾" ) == 0 )
				{
					t = 111;
				}
				else if ( str.find( "螃蟹" ) == 0 )
				{
					t = 112;
				}
				else if ( str.find( "章鱼" ) == 0 )
				{
					t = 113;
				}
				else if ( str.find( "大蒜" ) == 0 )
				{
					t = 114;
				}
				else if ( str.find( "葱" ) == 0 )
				{
					t = 115;
				}
				else if ( str.find( "胡椒" ) == 0 )
				{
					t = 116;
				}
				else if ( str.find( "香菇" ) == 0 )
				{
					t = 117;
				}
				else if ( str.find( "米" ) == 0 )
				{
					t = 118;
				}
				else if ( str.find( "海草" ) == 0 )
				{
					t = 119;
				}
				else if ( str.find( "苹果" ) == 0 )
				{
					t = 120;
				}
				else if ( str.find( "蜥蜴" ) == 0 )
				{
					t = 121;
				}
				else if ( str.find( "海星" ) == 0 )
				{
					t = 122;
				}
				else if ( str.find( "青蛙" ) == 0 )
				{
					t = 123;
				}
				else if ( str.find( "生姜" ) == 0 )
				{
					t = 124;
				}
				else if ( str.find( "芦笋" ) == 0 )
				{
					t = 125;
				}
				else if ( str.find( "红萝卜" ) == 0 )
				{
					t = 126;
				}
				else if ( str.find( "马铃薯" ) == 0 )
				{
					t = 127;
				}
				else if ( str.find( "梨" ) == 0 )
				{
					t = 128;
				}
				else if ( str.find( "樱桃" ) == 0 )
				{
					t = 129;
				}
				else if ( str.find( "竹笋" ) == 0 )
				{
					t = 130;
				}
				else if ( str.find( "葡萄" ) == 0 )
				{
					t = 131;
				}
				else if ( str.find( "谷" ) == 0 )
				{
					t = 132;
				}
				else if ( str.find( "包心菜" ) == 0 )
				{
					t = 133;
				}
				else if ( str.find( "青椒" ) == 0 )
				{
					t = 134;
				}
				else if ( str.find( "蕃茄" ) == 0 )
				{
					t = 135;
				}
				else if ( str.find( "茄子" ) == 0 )
				{
					t = 136;
				}
				else if ( str.find( "小黄瓜" ) == 0 )
				{
					t = 137;
				}
				else if ( str.find( "桃" ) == 0 )
				{
					t = 138;
				}
				else if ( str.find( "草莓" ) == 0 )
				{
					t = 139;
				}
				else if ( str.find( "油" ) == 0 )
				{
					t = 140;
				}
				else if ( str.find( "橘子" ) == 0 )
				{
					t = 141;
				}
				else if ( str.find( "柿子" ) == 0 )
				{
					t = 142;
				}
				else if ( str.find( "白菜" ) == 0 )
				{
					t = 143;
				}
				else if ( str.find( "南瓜" ) == 0 )
				{
					t = 144;
				}
				else if ( str.find( "味精" ) == 0 )
				{
					t = 145;
				}
				else if ( str.find( "高汤" ) == 0 )
				{
					t = 146;
				}


				else if ( str.find( "铁" ) == 0 )
				{
					t = 200;
				}
				else if ( str.find( "铜" ) == 0 )
				{
					t = 201;
				}
				else if ( str.find( "钻石" ) == 0 )
				{
					t = 202;
				}
				else if ( str.find( "红宝石" ) == 0 )
				{
					t = 203;
				}
				else if ( str.find( "蓝宝石" ) == 0 )
				{
					t = 204;
				}
				else if ( str.find( "绿宝石" ) == 0 )
				{
					t = 205;
				}
				else if ( str.find( "黄宝石" ) == 0 )
				{
					t = 206;
				}
				else if ( str.find( "珍珠" ) == 0 )
				{
					t = 207;
				}

				else if ( str.find( "恒冰结晶" ) == 0 )
				{
					t = 300;
				}
				else if ( str.find( "暴龙的尖牙" ) == 0 )
				{
					t = 301;
				}
				else if ( str.find( "蝎子的刺" ) == 0 )
				{
					t = 302;
				}
				else if ( str.find( "巨象的骨头" ) == 0 )
				{
					t = 303;
				}
				else if ( str.find( "海龙的骨头" ) == 0 )
				{
					t = 304;
				}
				else if ( str.find( "龙蜥的皮" ) == 0 )
				{
					t = 305;
				}
				else if ( str.find( "雷龙的骨头" ) == 0 )
				{
					t = 306;
				}
				else if ( str.find( "老虎的骨头" ) == 0 )
				{
					t = 307;
				}
				else if ( str.find( "人鱼的皮" ) == 0 )
				{
					t = 308;
				}

				else if ( str.find( "炼金粉末" ) == 0 )
				{
					t = 309;
				}

				else if ( str.find( "雷尔一" ) == 0 )
				{
					t = 320;
				}
				else if ( str.find( "雷尔二" ) == 0 )
				{
					t = 321;
				}
				else if ( str.find( "雷尔三" ) == 0 )
				{
					t = 322;
				}

				else if ( str.find( "海盗一" ) == 0 )
				{
					t = 323;
				}
				else if ( str.find( "海盗二" ) == 0 )
				{
					t = 324;
				}
				else if ( str.find( "海盗三" ) == 0 )
				{
					t = 325;
				}

				else if ( str.find( "奶牛一" ) == 0 )
				{
					t = 326;
				}
				else if ( str.find( "奶牛二" ) == 0 )
				{
					t = 327;
				}
				else if ( str.find( "奶牛三" ) == 0 )
				{
					t = 328;
				}

				else if ( str.find( "忍者一" ) == 0 )
				{
					t = 329;
				}
				else if ( str.find( "忍者二" ) == 0 )
				{
					t = 330;
				}
				else if ( str.find( "忍者三" ) == 0 )
				{
					t = 331;
				}

				else if ( str.find( "绅士一" ) == 0 )
				{
					t = 332;
				}
				else if ( str.find( "绅士二" ) == 0 )
				{
					t = 333;
				}
				else if ( str.find( "绅士三" ) == 0 )
				{
					t = 334;
				}
				else if ( str.find( "加特洛" ) == 0 )
				{
					t = 400;
				}
				else if ( str.find( "美鲁娜" ) == 0 )
				{
					t = 401;
				}
				else
				{
					assert( 0 );
				}

				element->SetAttribute( material.c_str() , t );
			}

			element->SetAttribute( "id" , eb.id );
			element->SetAttribute( "initNum" , eb.initNum );
			element->SetAttribute( "levelUpPoint" , eb.levelUpPoint );

			element->SetAttribute( "baseVitality" , eb.baseVitality );
			element->SetAttribute( "baseStrength" , eb.baseStrength );
			element->SetAttribute( "baseToughness" , eb.baseToughness );
			element->SetAttribute( "baseDexterity" , eb.baseDexterity );

			element->SetAttribute( "ai" , eb.ai );
			element->SetAttribute( "get" , eb.get );

			element->SetAttribute( "earth" , eb.earth );
			element->SetAttribute( "water" , eb.water );
			element->SetAttribute( "fire" , eb.fire );
			element->SetAttribute( "wind" , eb.wind );


			element->SetAttribute( "poison" , eb.poison );
			element->SetAttribute( "paralysis" , eb.paralysis );
			element->SetAttribute( "sleep" , eb.sleep );
			element->SetAttribute( "stone" , eb.stone );
			element->SetAttribute( "drunk" , eb.drunk );
			element->SetAttribute( "confusion" , eb.confusion );

			element->SetAttribute( "petSkill0" , eb.petSkill0 );
			element->SetAttribute( "petSkill1" , eb.petSkill1 );
			element->SetAttribute( "petSkill2" , eb.petSkill2 );
			element->SetAttribute( "petSkill3" , eb.petSkill3 );
			element->SetAttribute( "petSkill4" , eb.petSkill4 );
			element->SetAttribute( "petSkill5" , eb.petSkill5 );
			element->SetAttribute( "petSkill6" , eb.petSkill6 );


			element->SetAttribute( "rare" , eb.rare );
			element->SetAttribute( "critical" , eb.critical );
			element->SetAttribute( "counter" , eb.counter );
			element->SetAttribute( "slot" , eb.slot );
			element->SetAttribute( "imgNum" , eb.imgNum );
			element->SetAttribute( "petFlag" , eb.petFlag );
			element->SetAttribute( "size" , eb.size );


			element->SetAttribute( "ATOMBASEADD0" , eb.ATOMBASEADD0 );
			element->SetAttribute( "ATOMFIXMIN0" , eb.ATOMFIXMIN0 );
			element->SetAttribute( "ATOMFIXMAX0" , eb.ATOMFIXMAX0 );
			element->SetAttribute( "ATOMBASEADD1" , eb.ATOMBASEADD1 );
			element->SetAttribute( "ATOMFIXMIN1" , eb.ATOMFIXMIN1 );
			element->SetAttribute( "ATOMFIXMAX1" , eb.ATOMFIXMAX1 );
			element->SetAttribute( "ATOMBASEADD2" , eb.ATOMBASEADD2 );
			element->SetAttribute( "ATOMFIXMIN2" , eb.ATOMFIXMIN2 );
			element->SetAttribute( "ATOMFIXMAX2" , eb.ATOMFIXMAX2 );
			element->SetAttribute( "ATOMBASEADD3" , eb.ATOMBASEADD3 );
			element->SetAttribute( "ATOMFIXMIN3" , eb.ATOMFIXMIN3 );
			element->SetAttribute( "ATOMFIXMAX3" , eb.ATOMFIXMAX3 );
			element->SetAttribute( "ATOMBASEADD4" , eb.ATOMBASEADD4 );
			element->SetAttribute( "ATOMFIXMIN4" , eb.ATOMFIXMIN4 );
			element->SetAttribute( "ATOMFIXMAX4" , eb.ATOMFIXMAX4 );

			element->SetAttribute( "limitLevel" , eb.limitLevel );
			element->SetAttribute( "amalgamation" , eb.amalgamation );

			
			
		}
	}

	doc->Save( "C:/work/1.xml" , false );
}


fvoid		SaveEXP()
{
	crtIFileSystem* fileSystem = crtManager::GetFileSystem();
	crtIReadFile* readFile = fileSystem->CreateAndOpenFile( "E:\\shiqicc95\\sss\\gmsv\\data\\exp.txt" );
	char read;
	string strRead;
	string subStr;

	xmlDocument* doc = CreatXMLDocument();
	xmlElement* root = CreatXMLElement( doc , "root" );
	root->SetAttribute( "maxLevel" , 120 );
	doc->LinkEndChild( root );


	while ( readFile->Read( &read , 1 ) )
	{
		strRead += read;

		if ( read == '\n' )
		{
			fint32 level = 0;
			fint32 exp = 0;

			fint32 n = strRead.find( " " );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			level = atoi( subStr.c_str() );

			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			exp = atoi( subStr.c_str() );

			strRead.clear();


			xmlElement* element = CreatXMLElement( doc , "exp" );
			root->LinkEndChild( element );


			element->SetAttribute( "level" , level );
			element->SetAttribute( "exp" , exp );
			
		}
	}

	doc->Save( "E:/1.xml" , false );
	
}


void ReadCreate( string path , string name )
{
	string newPath = path + name;
	string xmlPath = "/Users/fox/Desktop/saExport/npc";
	string subPath = path.substr( strlen( "/Users/fox/Desktop/saRes/ssss/gmsv/data/npc" ) );
	xmlPath += subPath;

	int n = name.find( "." );
	subPath = name.substr( 0 , n );

	string tempStr = xmlPath;
	
	createdirectoryex( xmlPath.c_str() );
	xmlPath += subPath;
	xmlPath += ".create";


	
	char	line[20000];
	char	token[16384];
	int		listindex =0;
	int     i;
	FILE* fp;

	fp = fopen( newPath.c_str() , "r");
	if (fp == NULL)
	{
		return;
	}

	map< int , int > mmm;


	xmlDocument* doc = CreatXMLDocument();
	xmlElement* root = CreatXMLElement( doc , "root" );
	doc->LinkEndChild( root );

	xmlElement* xml = NULL;

	while(1){		
		line[0]='\0';	
		if (fgets(line, sizeof(line), fp) == NULL)	break;
		//print("\n %s ", line);
		chop(line);

		if( line[0] == '#' )
			continue;
		for( i=0; i<strlen(line); i++ ){
			if( line[i] == '#' ){
				line[i] = '\0';
				break;
			}
		}

		if ( line[ 0 ] == '{' )
		{
			xml = CreatXMLElement( doc , "npc" );
			root->LinkEndChild( xml );
			continue;
		}

		if ( line[ 0 ] == '}' )
		{
			continue;
		}
		
		if ( !xml )
		{
			continue;
		}
		
		if ( getStringFromIndexWithDelim(line, "loorid=", 2, token, sizeof(token)) )
		{
			xml->SetAttribute( "map" , atoi( token ) );
		}
		else if ( getStringFromIndexWithDelim(line, "orncenter=", 2, token, sizeof(token)) )
		{
			strcpy( line , token );
			
			getStringFromIndexWithDelim( line , ",", 1, token, sizeof(token));
			xml->SetAttribute( "bornCenterX" , atoi( token ) );
			getStringFromIndexWithDelim( line , ",", 2, token, sizeof(token));
			xml->SetAttribute( "bornCenterY" , atoi( token ) );
			getStringFromIndexWithDelim( line , ",", 3, token, sizeof(token));
			xml->SetAttribute( "bornCenterW" , atoi( token ) );
			getStringFromIndexWithDelim( line , ",", 4, token, sizeof(token));
			xml->SetAttribute( "bornCenterH" , atoi( token ) );
		}
		else if ( getStringFromIndexWithDelim(line, "orncorner=", 2, token, sizeof(token)) )
		{
			strcpy( line , token );

			getStringFromIndexWithDelim( line , ",", 1, token, sizeof(token));
			xml->SetAttribute( "bornCornerX" , atoi( token ) );
			getStringFromIndexWithDelim( line , ",", 2, token, sizeof(token));
			xml->SetAttribute( "bornCornerY" , atoi( token ) );
			getStringFromIndexWithDelim( line , ",", 3, token, sizeof(token));
			xml->SetAttribute( "bornCornerW" , atoi( token ) );
			getStringFromIndexWithDelim( line , ",", 4, token, sizeof(token));
			xml->SetAttribute( "bornCornerH" , atoi( token ) );
		}
		else if ( getStringFromIndexWithDelim(line, "ovecenter=", 2, token, sizeof(token)) )
		{
			strcpy( line , token );

			getStringFromIndexWithDelim( line , ",", 1, token, sizeof(token));
			xml->SetAttribute( "moveCenterX" , atoi( token ) );
			getStringFromIndexWithDelim( line , ",", 2, token, sizeof(token));
			xml->SetAttribute( "moveCenterY" , atoi( token ) );
			getStringFromIndexWithDelim( line , ",", 3, token, sizeof(token));
			xml->SetAttribute( "moveCenterW" , atoi( token ) );
			getStringFromIndexWithDelim( line , ",", 4, token, sizeof(token));
			xml->SetAttribute( "moveCenterH" , atoi( token ) );
		}
		else if ( getStringFromIndexWithDelim(line, "ovecorner=", 2, token, sizeof(token)) )
		{
			strcpy( line , token );

			getStringFromIndexWithDelim( line , ",", 1, token, sizeof(token));
			xml->SetAttribute( "moveCornerX" , atoi( token ) );
			getStringFromIndexWithDelim( line , ",", 2, token, sizeof(token));
			xml->SetAttribute( "moveCornerY" , atoi( token ) );
			getStringFromIndexWithDelim( line , ",", 3, token, sizeof(token));
			xml->SetAttribute( "moveCornerW" , atoi( token ) );
			getStringFromIndexWithDelim( line , ",", 4, token, sizeof(token));
			xml->SetAttribute( "moveCornerH" , atoi( token ) );
		}
		else if ( getStringFromIndexWithDelim(line, "reatenum=", 2, token, sizeof(token)) )
		{
			xml->SetAttribute( "num" , atoi( token ) );
		}
		else if ( getStringFromIndexWithDelim(line, "ir=", 2, token, sizeof(token)) )
		{
			xml->SetAttribute( "dir" , atoi( token ) );
		}
		else if ( getStringFromIndexWithDelim(line, "raphicname=", 2, token, sizeof(token)) )
		{
			xml->SetAttribute( "img" , atoi( token ) );
		}
		else if ( line[ 0 ] == 't' && getStringFromIndexWithDelim(line, "ime=", 2, token, sizeof(token)) )
		{
			xml->SetAttribute( "time" , atoi( token ) );
		}
		else if ( line[ 0 ] == 'f' && getStringFromIndexWithDelim(line, "ly=", 2, token, sizeof(token)) )
		{
			xml->SetAttribute( "fly" , atoi( token ) );
		}
		else if ( line[ 0 ] == 'i' && getStringFromIndexWithDelim(line, "temnum=", 2, token, sizeof(token)) )
		{
			xml->SetAttribute( "itemNum" , atoi( token ) );
		}
		else if ( line[ 0 ] == 'a' && getStringFromIndexWithDelim(line, "ction=", 2, token, sizeof(token)) )
		{
			xml->SetAttribute( "action" , atoi( token ) );
		}
		else if ( getStringFromIndexWithDelim(line, "ame=", 2, token, sizeof(token)) )
		{
			wstring str = AnsitoUnicode( token );
			if ( stringMap.find( str ) == stringMap.end() )
			{
				stringMap[ str ] = stringMap.size();
			}
			xml->SetAttribute( "name" , stringMap[ str ] );
		}
		else if ( getStringFromIndexWithDelim(line, "gnoreinvincible=", 2, token, sizeof(token)) )
		{
			xml->SetAttribute( "ignoreInvincible" , atoi( token ) );
		}
		else if ( getStringFromIndexWithDelim(line, "nemy=", 2, token, sizeof(token)) )
		{
			strcpy( line , token );

			getStringFromIndexWithDelim( line , "|", 1, token, sizeof(token));
			xml->SetAttribute( "template" , token );
			string str = token;
			if ( npcTemplateMap.find( str ) != npcTemplateMap.end() )
			{
			}
			else
			{
				fclose(fp);
				ReleaseXMLDocument( doc );
				return;
			}

			if ( getStringFromIndexWithDelim( line , ":", 2, token, sizeof(token)) )
			{
				string path22 = token;
				int n = path22.find( "." );
				if ( n > 0 )
				{
					path22 = path22.substr( 0 , n );
				}

				xml->SetAttribute( "arg" , path22.c_str() );

				string path11 = "/Users/fox/Desktop/saRes/ssss/gmsv/data/npc/";
				path11 += token;

				FILE* fp1;

				fp1 = fopen( path11.c_str() , "r");
				if (fp1 == NULL)
				{
					return;
				}
				fclose( fp1 );

				ReadArg( "/Users/fox/Desktop/saRes/ssss/gmsv/data/npc/" , token , str.c_str() );
			}
		} 
		else if ( line[ 0 ] != '\0' )
		{
			assert( 0 );
		}
		
		listindex++;
	}
	fclose(fp);

	doc->Save( xmlPath.c_str() , true );
	ReleaseXMLDocument( doc );
}


void ReadTemplate1( string path , string name )
{
	string newPath = path + name;
	string subPath = path.substr( strlen( "C:\\work\\shiqicc95\\sss\\gmsv\\data\\npc\\" ) );
	
	int n = name.find( "." );
	subPath = name.substr( 0 , n );

	char	line[20000];
	char	token[16384];
	int		listindex =0;
	int     i;
	FILE* fp;

	fp = fopen( newPath.c_str() , "r");
	if (fp == NULL)
	{
		return;
	}

	bool b = false;
	NpcTemplate template1;
	while(1){		
		line[0]='\0';	
		if (fgets(line, sizeof(line), fp) == NULL)	break;
		//print("\n %s ", line);
		chop(line);

		if( line[0] == '#' )
			continue;
		for( i=0; i<strlen(line); i++ ){
			if( line[i] == '#' ){
				line[i] = '\0';
				break;
			}
		}

		if ( line[ 0 ] == '{' )
		{
			b = true;
			continue;
		}

		if ( line[ 0 ] == '}' )
		{
			continue;
		}

		if ( !b )
		{
			continue;
		}

		if ( getStringFromIndexWithDelim(line, "emplatename=", 2, token, sizeof(token)) )
		{
			template1.templateName = token;

			if ( npcTemplateMap.find( template1.templateName ) == npcTemplateMap.end() )
			{
				npcTemplateMap[ template1.templateName ] = template1;
			}
			else
			{
				printf( "npcTemplateMap %s \n" , template1.templateName.c_str() );
				npcTemplateMap[ template1.templateName ] = template1;
			}

		}
		else if ( getStringFromIndexWithDelim(line, "akeatnobody=", 2, token, sizeof(token)) )
		{
			template1.nobody = token;
		}
		else if ( getStringFromIndexWithDelim(line, "akeatnosee=", 2, token, sizeof(token)) )
		{
			template1.nosee = token;
		}
		else if ( getStringFromIndexWithDelim(line, "ype=", 2, token, sizeof(token)) )
		{
			template1.type = token;
		}
		else if ( getStringFromIndexWithDelim(line, "unctionset=", 2, token, sizeof(token)) )
		{
			template1.fun = token;
		}
		else if ( line[ 0 ] == 'n' && getStringFromIndexWithDelim(line, "ame=", 2, token, sizeof(token)) )
		{
			template1.name = token;
		}
		else if ( line[ 0 ] == 'h' && getStringFromIndexWithDelim(line, "p=", 2, token, sizeof(token)) )
		{
			template1.hp = token;
		}
		else if ( line[ 0 ] == 'm' && getStringFromIndexWithDelim(line, "p=", 2, token, sizeof(token)) )
		{
			template1.mp = token;
		}
		else if ( getStringFromIndexWithDelim(line, "tr=", 2, token, sizeof(token)) )
		{
			template1.str = token;
		}
		else if ( getStringFromIndexWithDelim(line, "ough=", 2, token, sizeof(token)) )
		{
			template1.tough = token;
		}
		else if ( getStringFromIndexWithDelim(line, "oopfunctime=", 2, token, sizeof(token)) )
		{
			template1.loopTime = token;
		}
		else if ( getStringFromIndexWithDelim(line, "raphicname=", 2, token, sizeof(token)) )
		{
			template1.imgName = token;
		}
		else if ( line[ 0 ] == 'f' && getStringFromIndexWithDelim(line, "ly=", 2, token, sizeof(token)) )
		{
			template1.fly = token;
		}
		else if ( line[ 0 ] == 'i' && getStringFromIndexWithDelim(line, "temnum=", 2, token, sizeof(token)) )
		{
			template1.itemNum = token;
		}
		else if ( line[ 0 ] != '\0' )
		{
			assert( 0 );
		}

		npcTemplateMap[ template1.templateName ] = template1;

		listindex++;
	}


	fclose(fp);

	
}


enum FREETYPE
{
    FREE_NOW_EVENT = 1,
    FREE_END_EVENT,
    FREE_NOW_EVENT_NOT,
    FREE_END_EVENT_NOT,
    FREE_LV_MIN,
    FREE_LV_MAX,
    FREE_LV,
    
    FREE_SP,
    
    FREE_REITEM = 10,
    FREE_ITEMNOT,
    
    FREE_GOLDNEED = 20,
    
    FREE_CLASS = 30,
    FREE_CLASS_MIN,
    
    FREE_TRANS = 40,
    FREE_TRANS_MIN,
    FREE_TRANS_MAX,
    
    FREE_HERO_NOW = 50,
    FREE_HERO_OUT,
    FREE_HERO_OVER,
    
    FREE_ANGEL_OUT,
    FREE_ANGEL_OVER,
    
    FREE_DR_MIN = 60,
    FREE_DR_MAX,
    FREE_DR,
    
    FREE_TIME = 70,
    FREE_TIME_NOT,
    
    
    FREE_COUNT
};

void ReadFree( xmlElement* xml , xmlDocument* doc , char* token )
{
    char buffer[ 1024 ];
    int nnss2 = 1;
    
    string check = ";";
    if ( getStringFromIndexWithDelim( token , "," , 2 , buffer , 1024 ) )
    {
        check = ",";
    }
    
    while ( getStringFromIndexWithDelim( token , (char*)check.c_str() , nnss2 , buffer , 1024 ) )
    {
        xmlElement* xml1 = CreatXMLElement( doc , "free" );
        xml->LinkEndChild( xml1 );
        
        int nnss1 = 1;
        
        int typeNum = 0;
        int itemNum = 0;
        int petNum = 0;
        
        char line0[ 1024 ];
        char line1[ 1024 ];
        
        while ( getStringFromIndexWithDelim( buffer , "&" , nnss1 , line0 , 1024 ) )
        {
            if ( line0[ 0 ] == 'N' && getStringFromIndexWithDelim( line0 , "OWEV=" , 2 , line1 , 1024 ) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_NOW_EVENT );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'N' && getStringFromIndexWithDelim( line0 , "OW=" , 2 , line1 , 1024 ) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_NOW_EVENT );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'N' && getStringFromIndexWithDelim( line0 , "OEEV=" , 2 , line1 , 1024 ) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_NOW_EVENT );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'D' && getStringFromIndexWithDelim( line0 , "R<=" , 2 , line1 , 1024 ) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_DR_MAX );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'D' && getStringFromIndexWithDelim( line0 , "R<" , 2 , line1 , 1024 ) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_DR_MAX );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) - 1 );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'D' && getStringFromIndexWithDelim( line0 , "R=" , 2 , line1 , 1024 ) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_DR );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) );
                
                typeNum++;
            }
            
            else if ( line0[ 0 ] == 'T' && getStringFromIndexWithDelim( line0, "IME=", 2, line1 , 1024 ) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_TIME );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'T' && getStringFromIndexWithDelim( line0, "IME!=", 2, line1 , 1024 ) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_TIME_NOT );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) );
                
                typeNum++;
            }
            
            else if ( line0[ 0 ] == 'E' && getStringFromIndexWithDelim( line0, "NDEV=", 2, line1 , 1024 ) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_END_EVENT );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'E' && getStringFromIndexWithDelim( line0, "MDEV=", 2, line1 , 1024 ) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_END_EVENT );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) );
                
                typeNum++;
            }
            
            else if ( line0[ 0 ] == 'N' && getStringFromIndexWithDelim( line0, "OWEV!=", 2, line1 , 1024 ) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_NOW_EVENT_NOT );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'E' && getStringFromIndexWithDelim( line0, "NDEV!=", 2, line1 , 1024 ) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_END_EVENT_NOT );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'r' && getStringFromIndexWithDelim( line0, "eITEM>=", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_REITEM );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'r' && getStringFromIndexWithDelim( line0, "eITEM>", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_REITEM );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) + 1 );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'C' && getStringFromIndexWithDelim( line0, "LASS=", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_CLASS );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'C' && getStringFromIndexWithDelim( line0, "LASS>=", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_CLASS_MIN );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'C' && getStringFromIndexWithDelim( line0, "LASS>", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_CLASS_MIN );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) + 1 );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'I' && getStringFromIndexWithDelim( line0, "TEM=", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                char line2[ 320 ];
                if ( getStringFromIndexWithDelim( line1 , "*", 2, line2 , 256) )
                {
                    getStringFromIndexWithDelim( line1, "*", 1, line2 , 256);
                    sprintf( buffer , "item%d" , itemNum );
                    xml1->SetAttribute( buffer , atoi( line2 ) );
                    
                    getStringFromIndexWithDelim( line1, "*", 2, line2 , 256);
                    sprintf( buffer , "itemNum%d" , itemNum );
                    xml1->SetAttribute( buffer , atoi( line2 ) );
                    
                    itemNum++;
                }
                else
                {
                    sprintf( buffer , "item%d" , itemNum );
                    xml1->SetAttribute( buffer , atoi( line1 ) );
                    sprintf( buffer , "itemNum%d" , itemNum );
                    xml1->SetAttribute( buffer , 1 );
                    
                    itemNum++;
                }
            }
            else if ( line0[ 0 ] == 'I' && getStringFromIndexWithDelim( line0, "TEN=", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                char line2[ 320 ];
                if ( getStringFromIndexWithDelim( line1 , "*", 2, line2 , 256) )
                {
                    getStringFromIndexWithDelim( line1, "*", 1, line2 , 256);
                    sprintf( buffer , "item%d" , itemNum );
                    xml1->SetAttribute( buffer , atoi( line2 ) );
                    
                    getStringFromIndexWithDelim( line1, "*", 2, line2 , 256);
                    sprintf( buffer , "itemNum%d" , itemNum );
                    xml1->SetAttribute( buffer , atoi( line2 ) );
                    
                    itemNum++;
                }
                else
                {
                    sprintf( buffer , "item%d" , itemNum );
                    xml1->SetAttribute( buffer , atoi( line1 ) );
                    sprintf( buffer , "itemNum%d" , itemNum );
                    xml1->SetAttribute( buffer , 1 );
                    
                    itemNum++;
                }
            }
            
            //        else if ( line0[ 0 ] == 'T' && getStringFromIndexWithDelim( line0, "RANS>", 2, token , 1024) )
            //        {
            //            xml1->SetAttribute( "transMin" , atoi( token ) );
            //        }
            //        else if ( line0[ 0 ] == 'V' && getStringFromIndexWithDelim( line0, "IP", 2, token , 1024) )
            //        {
            //            xml1->SetAttribute( "vip" , atoi( token ) );
            //        }
            //        else if ( line0[ 0 ] == 'T' && getStringFromIndexWithDelim( line0, "RANS=", 2, token , 1024) )
            //        {
            //            xml1->SetAttribute( "trans" , atoi( token ) );
            //        }
            else if ( line0[ 0 ] == 'H' && getStringFromIndexWithDelim( line0, "ERO_I_NOW=", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_HERO_NOW );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'H' && getStringFromIndexWithDelim( line0, "ERO_OUT=", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_HERO_OUT );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'H' && getStringFromIndexWithDelim( line0, "ERO_OVER=", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_HERO_OVER );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'H' && getStringFromIndexWithDelim( line0, "ERO_I_OVER=", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_HERO_OVER );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'A' && getStringFromIndexWithDelim( line0, "NGEL_OUT=", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_ANGEL_OUT );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'A' && getStringFromIndexWithDelim( line0, "NGEL_I_OVER=", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_ANGEL_OVER );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) );
                
                typeNum++;
            }
            
            else if ( line0[ 0 ] == 'I' && getStringFromIndexWithDelim( line0, "TEM!=", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_ITEMNOT );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'G' && getStringFromIndexWithDelim( line0, "GOLD>=", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_GOLDNEED );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'L' && getStringFromIndexWithDelim( line0, "V>=", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_LV_MIN );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'L' && getStringFromIndexWithDelim( line0, "V>", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_LV_MIN );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) + 1 );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'L' && getStringFromIndexWithDelim( line0, "V<=", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_LV_MAX );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'L' && getStringFromIndexWithDelim( line0, "V<", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_LV_MAX );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) - 1 );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'L' && getStringFromIndexWithDelim( line0, "V=", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_LV );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) - 1 );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'T' && getStringFromIndexWithDelim( line0, "RANS=", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_TRANS );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'T' && getStringFromIndexWithDelim( line0, "RANS>=", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_TRANS_MIN );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'T' && getStringFromIndexWithDelim( line0, "RANS>", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_TRANS_MIN );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) + 1 );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'T' && getStringFromIndexWithDelim( line0, "RANS<=", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_TRANS_MAX );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'S' && getStringFromIndexWithDelim( line0, "P=", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_SP );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'T' && getStringFromIndexWithDelim( line0, "RANS<", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                
                sprintf( buffer , "t%d" , typeNum );
                xml1->SetAttribute( buffer , FREE_TRANS_MAX );
                sprintf( buffer , "tv%d" , typeNum );
                xml1->SetAttribute( buffer , atoi( line1 ) - 1 );
                
                typeNum++;
            }
            else if ( line0[ 0 ] == 'P' && getStringFromIndexWithDelim( line0, "ET<=", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                char line2[ 320 ];
                char line3[ 320 ];
                
                xmlElement* xml2 = CreatXMLElement( doc , "pet" );
                xml1->LinkEndChild( xml2 );
                
                getStringFromIndexWithDelim( line1, "-", 1, line2 , 256 );
                int lv = atoi( line2 );
                xml2->SetAttribute( "petLVMax" , lv );
                
                getStringFromIndexWithDelim( line1, "-", 2, line2 , 256 );
                getStringFromIndexWithDelim( line2, "*", 1, line3 , 256 );
                int idd = atoi( line3 );
                xml2->SetAttribute( "petBaseID" , idd );
                
                getStringFromIndexWithDelim( line2, "*", 2, line3 , 256 );
                int num = atoi( line3 );
                xml2->SetAttribute( "petNum" , num );
            }
            else if ( line0[ 0 ] == 'P' && getStringFromIndexWithDelim( line0, "ET<", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                char line2[ 320 ];
                char line3[ 320 ];
                
                xmlElement* xml2 = CreatXMLElement( doc , "pet" );
                xml1->LinkEndChild( xml2 );
                
                getStringFromIndexWithDelim( line1, "-", 1, line2 , 256 );
                int lv = atoi( line2 ) - 1;
                xml2->SetAttribute( "petLVMax" , lv );
                
                getStringFromIndexWithDelim( line1, "-", 2, line2 , 256 );
                getStringFromIndexWithDelim( line2, "*", 1, line3 , 256 );
                int idd = atoi( line3 );
                xml2->SetAttribute( "petBaseID" , idd );
                
                getStringFromIndexWithDelim( line2, "*", 2, line3 , 256 );
                int num = atoi( line3 );
                xml2->SetAttribute( "petNum" , num );
            }
            else if ( line0[ 0 ] == 'P' && getStringFromIndexWithDelim( line0, "ET>=", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                char line2[ 320 ];
                char line3[ 320 ];
                
                xmlElement* xml2 = CreatXMLElement( doc , "pet" );
                xml1->LinkEndChild( xml2 );
                
                getStringFromIndexWithDelim( line1, "-", 1, line2 , 256 );
                int lv = atoi( line2 );
                xml2->SetAttribute( "petLVMin" , lv );
                
                getStringFromIndexWithDelim( line1, "-", 2, line2 , 256 );
                getStringFromIndexWithDelim( line2, "*", 1, line3 , 256 );
                int idd = atoi( line3 );
                xml2->SetAttribute( "petBaseID" , idd );
                
                getStringFromIndexWithDelim( line2, "*", 2, line3 , 256 );
                int num = atoi( line3 );
                xml2->SetAttribute( "petNum" , num );
            }
            else if ( line0[ 0 ] == 'P' && getStringFromIndexWithDelim( line0, "ET>", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                char line2[ 320 ];
                char line3[ 320 ];
                
                xmlElement* xml2 = CreatXMLElement( doc , "pet" );
                xml1->LinkEndChild( xml2 );
                
                getStringFromIndexWithDelim( line1, "-", 1, line2 , 256 );
                int lv = atoi( line2 ) + 1;
                xml2->SetAttribute( "petLVMin" , lv );
                
                getStringFromIndexWithDelim( line1, "-", 2, line2 , 256 );
                getStringFromIndexWithDelim( line2, "*", 1, line3 , 256 );
                int idd = atoi( line3 );
                xml2->SetAttribute( "petBaseID" , idd );
                
                getStringFromIndexWithDelim( line2, "*", 2, line3 , 256 );
                int num = atoi( line3 );
                xml2->SetAttribute( "petNum" , num );
            }
            else if ( line0[ 0 ] == 'P' && getStringFromIndexWithDelim( line0, "ET=", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                char line2[ 320 ];
                char line3[ 320 ];
                
                xmlElement* xml2 = CreatXMLElement( doc , "pet" );
                xml1->LinkEndChild( xml2 );
                
                getStringFromIndexWithDelim( line1, "-", 1, line2 , 256 );
                int lv = atoi( line2 );
                xml2->SetAttribute( "petLV" , lv );
                
                getStringFromIndexWithDelim( line1, "-", 2, line2 , 256 );
                getStringFromIndexWithDelim( line2, "*", 1, line3 , 256 );
                int idd = atoi( line3 );
                xml2->SetAttribute( "petBaseID" , idd );
                
                getStringFromIndexWithDelim( line2, "*", 2, line3 , 256 );
                int num = atoi( line3 );
                xml2->SetAttribute( "petNum" , num );
            }
            else if ( line0[ 0 ] == 'P' && getStringFromIndexWithDelim( line0, "ET!=", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                char line2[ 320 ];
                char line3[ 320 ];
                
                
                xmlElement* xml2 = CreatXMLElement( doc , "pet" );
                xml1->LinkEndChild( xml2 );
                
                getStringFromIndexWithDelim( line1, "-", 1, line2 , 256 );
                int lv = atoi( line2 );
                xml2->SetAttribute( "petLVNot" , lv );
                
                getStringFromIndexWithDelim( line1, "-", 2, line2 , 256 );
                getStringFromIndexWithDelim( line2, "*", 1, line3 , 256 );
                int idd = atoi( line3 );
                xml2->SetAttribute( "petBaseID" , idd );
                
                getStringFromIndexWithDelim( line2, "*", 2, line3 , 256 );
                int num = atoi( line3 );
                xml2->SetAttribute( "petNum" , num );
            }
            else if ( line0[ 0 ] == 'E' && getStringFromIndexWithDelim( line0, "VPET>", 2, line1 , 1024) )
            {
                char buffer[ 32 ];
                char line2[ 320 ];
                char line3[ 320 ];
                
                xmlElement* xml2 = CreatXMLElement( doc , "pet" );
                xml1->LinkEndChild( xml2 );
                
                getStringFromIndexWithDelim( line1, "-", 1, line2 , 256 );
                int lv = atoi( line2 ) + 1;
                xml2->SetAttribute( "petLVMin" , lv );
                
                getStringFromIndexWithDelim( line1, "-", 2, line2 , 256 );
                getStringFromIndexWithDelim( line2, "*", 1, line3 , 256 );
                int idd = atoi( line3 );
                xml2->SetAttribute( "petBaseID" , idd );
                xml2->SetAttribute( "petNum" , 1 );
            }
            else if ( line0[ 0 ] != '\0' && line0[ 0 ] != ' ' && line0[ 0 ] != '\r' )
            {
                printf( "%s \n" , line0 );
                assert( 0 );
            }
            
            nnss1++;
        }

        
        nnss2++;
    }
    
}


void ReadArg( string path , string name , string tem )
{
	string newPath = path + name;
	string xmlPath = "/Users/fox/Desktop/saExport/npc/";
	string subPath = path.substr( strlen( "/Users/fox/Desktop/saRes/ssss/gmsv/data/npc/" ) );
	xmlPath += subPath;

	int n = name.find( "." );

	if ( n >= 0 )
	{
		subPath = name.substr( 0 , n );
	}
	else
	{
		subPath = name;
	}
	
	string tempStr = xmlPath;
    
	createdirectoryex( xmlPath.c_str() );
	xmlPath += subPath;
	xmlPath += ".arg";
    
    int addEggID = 0;
    
	char	line[20000];
	char	token[16384];
	int		listindex =0;
	int     i;
	FILE* fp;
    
	fp = fopen( newPath.c_str() , "r");
	if (fp == NULL)
	{
		return;
	}
    
	map< int , int > mmm;
    
	xmlDocument* doc = CreatXMLDocument();
	xmlElement* root = CreatXMLElement( doc , "root" );
	doc->LinkEndChild( root );
    
	xmlElement* xml = NULL;
    xmlElement* xml1 = NULL;
    xmlElement* xml2 = NULL;
    
	while(1){
		line[0]='\0';	
		if (fgets(line, sizeof(line), fp) == NULL)	break;
		//print("\n %s ", line);
		chop(line);

		if( line[0] == '#' )
			continue;
		if( line[0] == '\t' )
			continue;
		for( i=0; i<strlen(line); i++ ){
			if( line[i] == '#' ){
				line[i] = '\0';
				break;
			}
		}
        
        
		if ( (int)tem.find( "sb_" ) == 0 || (int)tem.find( "ev" ) == 0 ||
            tem == "angelfire" ||
            tem == "devilpk" || tem == "frecos" ||
            tem == "koberoll" || tem == "moonenemy" ||
            tem == "moonenemy2" || tem == "moonenemy3" ||
            tem == "sin" || tem == "saveking2pk" )
		{
			// entype:2

            
			continue;
		}
        
        if ( tem == "fmletter" )
        {
            // 家族
            continue;
        }
        if ( tem == "familyman" )
        {
            // 家族
            continue;
        }
        if ( tem == "bankman" )
        {
            // 银行？
            continue;
        }
        if ( tem == "bigsmallmaster" )
        {
            // 比大小
            continue;
        }
        if ( tem == "bigsmallpet" )
        {
            // 比大小
            continue;
        }
        if ( tem == "riderman" )
        {
            // 骑宠
            
            //            winno=1
            //            message=2
            //            message=Œ“ «’‚∏ˆ¥Â◊”¿Ôµƒ∆Ô≥À—µ¡∑ ¶£°
            //            message=ƒ„œÎ∞Ï ≤√¥¬£ø
            //            message=
            //            message=πÿ”⁄∆Ô≥À≥ËŒÔ
            //            message=≤È—Øø…∆Ô≥Àµƒ≥ËŒÔ
            //            message=—ßœ∞∆Ô≥À≥ËŒÔ
            //            wintype=2
            //            buttontype=none
            //            selected=
            //            gotowin=
            //            endbutton=
            //            selected=
            //            gotowin=2
            //            endbutton=
            //            selected=
            //            gotowin=5
            //            endbutton=
            //            selected=
            //            gotowin=100
            //            endbutton=
            //            endwin=
            
            if ( !xml )
            {
                xml = CreatXMLElement( doc , "riderMan" );
				root->LinkEndChild( xml );
            }
            
            continue;
        }
        
        if ( tem == "bluestrong" )
        {
            // new npc enemy
            continue;
        }
        
        if ( tem == "luckyman" )
        {
            continue;
        }
        
        if ( tem == "manorsman" )
        {
            continue;
        }
        
        if ( tem == "exchangeman" || tem == "moon" || tem == "mooni" ||
            tem == "moonn" || tem == "moonno" || tem == "moonqueen" || tem == "moonya" )
        {
            continue;
        }
        
        if ( tem == "moonwarp" || tem == "moonwarp2" || tem == "moonwarp3" )
        {
            // warp man
            
            continue;
        }
        
        if ( tem == "windowman" )
        {
            continue;
        }
        
        if ( tem == "transman" )
        {
            continue;
        }
        
        if ( tem == "vipshop" )
        {
            continue;
        }
        
        if ( tem == "npc_newnpcman" )
        {
            if ( !xml )
            {
                xml = CreatXMLElement( doc , "newNpcMan" );
				root->LinkEndChild( xml );
            }
            
            if ( line[ 0 ] == 'S' && getStringFromIndexWithDelim(line, "TART_MSG:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "startMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'C' && getStringFromIndexWithDelim(line, "HECK_MSG:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "checkMsg" , stringMap[ str ] );
                continue;
			}
            
            if ( line[ 0 ] != '\0' && line[ 0 ] != ' ' && line[ 0 ] != '\r' )
            {
                printf( "%s \n" , line );
                assert( 0 );
            }
            
            continue;
        }
        
        if ( tem == "npc_petfusion" )
        {
            if ( !xml )
            {
                xml = CreatXMLElement( doc , "petfusion" );
				root->LinkEndChild( xml );
            }
            
            if ( line[ 0 ] == 'S' && getStringFromIndexWithDelim(line, "tartMsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "startMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'S' && getStringFromIndexWithDelim(line, "electMsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "selectMsg" , stringMap[ str ] );
                continue;
			}
            
            if ( line[ 0 ] == 'A' && getStringFromIndexWithDelim(line, "DDEGGID:", 2, token, sizeof(token)) )
			{
                char buffer[ 32 ];
                sprintf( buffer , "addEggID%d" , addEggID );
                xml->SetAttribute( buffer , token );
                addEggID++;
                
                continue;
			}
            if ( line[ 0 ] == 'F' && getStringFromIndexWithDelim(line, "REE:", 2, token, sizeof(token)) )
			{
                continue;
			}
            
            if ( line[ 0 ] != '\0' && line[ 0 ] != ' ' && line[ 0 ] != '\r' )
            {
                printf( "%s \n" , line );
                assert( 0 );
            }
            
            continue;
        }
        
        if ( tem == "npc_transmigration" )
        {
            // 转生
            
            if ( !xml )
            {
                xml = CreatXMLElement( doc , "transmigration" );
				root->LinkEndChild( xml );
            }
            
            
            if ( line[ 0 ] == 'P' && getStringFromIndexWithDelim(line, "PETTRANS:", 2, token, sizeof(token)) )
			{
                xml1 = CreatXMLElement( doc , "petTrans" );
				xml->LinkEndChild( xml1 );
                continue;
			}
            
            if ( line[ 0 ] == 'T' && getStringFromIndexWithDelim(line, "ENSEI:", 2, token, sizeof(token)) )
			{
                xml1 = CreatXMLElement( doc , "trans" );
                xml1->SetAttribute( "type" , atoi( token )  - 1 );
				xml->LinkEndChild( xml1 );
                
                continue;
			}
            
            
            if ( line[ 0 ] == 's' && getStringFromIndexWithDelim(line, "tartmsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "startMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'm' && getStringFromIndexWithDelim(line, "ainmsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "mainMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'y' && getStringFromIndexWithDelim(line, "esmsg1:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "yesMsg0" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'y' && getStringFromIndexWithDelim(line, "esmsg2:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "yesMsg1" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'n' && getStringFromIndexWithDelim(line, "omsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "noMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'n' && getStringFromIndexWithDelim(line, "onemsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "noneMsg" , stringMap[ str ] );
                continue;
			}
            
            
            // pet
            if ( line[ 0 ] == 's' && getStringFromIndexWithDelim(line, "electmsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "selectMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'm' && getStringFromIndexWithDelim(line, "ainmsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "mainMsg0" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 's' && getStringFromIndexWithDelim(line, "etpetmsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "setpetMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 't' && getStringFromIndexWithDelim(line, "ransmsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "transMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'm' && getStringFromIndexWithDelim(line, "ain1msg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "mainMsg1" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'f' && getStringFromIndexWithDelim(line, "ailmsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "failMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'e' && getStringFromIndexWithDelim(line, "ndmsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "endMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'c' && getStringFromIndexWithDelim(line, "ancelmsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "cancelMsg" , stringMap[ str ] );
                continue;
			}
            
            
            if ( line[ 0 ] == 'm' && getStringFromIndexWithDelim(line, "axmsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "maxMsg" , stringMap[ str ] );
                continue;
			}
            
            if ( line[ 0 ] == 's' && getStringFromIndexWithDelim(line, "amugiru:", 2, token, sizeof(token)) )
			{
                xmlElement* xml1 = CreatXMLElement( doc , "samugiru" );
				xml->LinkEndChild( xml1 );
                
                char line0[ 320 ];
                char line1[ 320 ];
                char line2[ 320 ];
                getStringFromIndexWithDelim(token, ",", 1, line0, 256);
                getStringFromIndexWithDelim(line0, "=", 2, line1, 256);
                xml1->SetAttribute( "item" , line1 );
                
                getStringFromIndexWithDelim(token, ",", 2, line0, 256);
                getStringFromIndexWithDelim(line0, "=", 2, line1, 256);
                xml1->SetAttribute( "pet" , line1 );
                
                getStringFromIndexWithDelim(token, ",", 2, line0, 256);
                getStringFromIndexWithDelim(line0, "=", 2, line1, 256);
                getStringFromIndexWithDelim(line1, ".", 1, line2, 256);
                xml1->SetAttribute( "present0" , line2 );
                getStringFromIndexWithDelim(line1, ".", 2, line2, 256);
                xml1->SetAttribute( "present1" , line2 );
                getStringFromIndexWithDelim(line1, ".", 3, line2, 256);
                xml1->SetAttribute( "present2" , line2 );
                getStringFromIndexWithDelim(line1, ".", 4, line2, 256);
                xml1->SetAttribute( "present3" , line2 );
                getStringFromIndexWithDelim(line1, ".", 5, line2, 256);
                xml1->SetAttribute( "present4" , line2 );
                
                getStringFromIndexWithDelim(token, ",", 2, line0, 256);
                getStringFromIndexWithDelim(line0, "=", 2, line1, 256);
                getStringFromIndexWithDelim(line1, ".", 1, line2, 256);
                xml1->SetAttribute( "map" , line2 );
                getStringFromIndexWithDelim(line1, ".", 2, line2, 256);
                xml1->SetAttribute( "x" , line2 );
                getStringFromIndexWithDelim(line1, ".", 3, line2, 256);
                xml1->SetAttribute( "y" , line2 );
                
                xml1 = NULL;
                continue;
			}
            
            if ( line[ 0 ] == 'm' && getStringFromIndexWithDelim(line, "arinasu:", 2, token, sizeof(token)) )
			{
                xmlElement* xml1 = CreatXMLElement( doc , "marinasu" );
                xml->LinkEndChild( xml1 );
                
                char line0[ 320 ];
                char line1[ 320 ];
                char line2[ 320 ];
                getStringFromIndexWithDelim(token, ",", 1, line0, 256);
                getStringFromIndexWithDelim(line0, "=", 2, line1, 256);
                xml1->SetAttribute( "item" , line1 );
                
                getStringFromIndexWithDelim(token, ",", 2, line0, 256);
                getStringFromIndexWithDelim(line0, "=", 2, line1, 256);
                xml1->SetAttribute( "pet" , line1 );
                
                getStringFromIndexWithDelim(token, ",", 2, line0, 256);
                getStringFromIndexWithDelim(line0, "=", 2, line1, 256);
                getStringFromIndexWithDelim(line1, ".", 1, line2, 256);
                xml1->SetAttribute( "present0" , line2 );
                getStringFromIndexWithDelim(line1, ".", 2, line2, 256);
                xml1->SetAttribute( "present1" , line2 );
                getStringFromIndexWithDelim(line1, ".", 3, line2, 256);
                xml1->SetAttribute( "present2" , line2 );
                getStringFromIndexWithDelim(line1, ".", 4, line2, 256);
                xml1->SetAttribute( "present3" , line2 );
                getStringFromIndexWithDelim(line1, ".", 5, line2, 256);
                xml1->SetAttribute( "present4" , line2 );
                
                getStringFromIndexWithDelim(token, ",", 2, line0, 256);
                getStringFromIndexWithDelim(line0, "=", 2, line1, 256);
                getStringFromIndexWithDelim(line1, ".", 1, line2, 256);
                xml1->SetAttribute( "map" , line2 );
                getStringFromIndexWithDelim(line1, ".", 2, line2, 256);
                xml1->SetAttribute( "x" , line2 );
                getStringFromIndexWithDelim(line1, ".", 3, line2, 256);
                xml1->SetAttribute( "y" , line2 );
                
                xml1 = NULL;
                continue;
			}
            
            if ( line[ 0 ] == 'j' && getStringFromIndexWithDelim(line, "aja:", 2, token, sizeof(token)) )
			{
                xmlElement* xml1 = CreatXMLElement( doc , "jaja" );
                xml->LinkEndChild( xml1 );
                
                char line0[ 320 ];
                char line1[ 320 ];
                char line2[ 320 ];
                getStringFromIndexWithDelim(token, ",", 1, line0, 256);
                getStringFromIndexWithDelim(line0, "=", 2, line1, 256);
                xml1->SetAttribute( "item" , line1 );
                
                getStringFromIndexWithDelim(token, ",", 2, line0, 256);
                getStringFromIndexWithDelim(line0, "=", 2, line1, 256);
                xml1->SetAttribute( "pet" , line1 );
                
                getStringFromIndexWithDelim(token, ",", 2, line0, 256);
                getStringFromIndexWithDelim(line0, "=", 2, line1, 256);
                getStringFromIndexWithDelim(line1, ".", 1, line2, 256);
                xml1->SetAttribute( "present0" , line2 );
                getStringFromIndexWithDelim(line1, ".", 2, line2, 256);
                xml1->SetAttribute( "present1" , line2 );
                getStringFromIndexWithDelim(line1, ".", 3, line2, 256);
                xml1->SetAttribute( "present2" , line2 );
                getStringFromIndexWithDelim(line1, ".", 4, line2, 256);
                xml1->SetAttribute( "present3" , line2 );
                getStringFromIndexWithDelim(line1, ".", 5, line2, 256);
                xml1->SetAttribute( "present4" , line2 );
                
                getStringFromIndexWithDelim(token, ",", 2, line0, 256);
                getStringFromIndexWithDelim(line0, "=", 2, line1, 256);
                getStringFromIndexWithDelim(line1, ".", 1, line2, 256);
                xml1->SetAttribute( "map" , line2 );
                getStringFromIndexWithDelim(line1, ".", 2, line2, 256);
                xml1->SetAttribute( "x" , line2 );
                getStringFromIndexWithDelim(line1, ".", 3, line2, 256);
                xml1->SetAttribute( "y" , line2 );
                
                xml1 = NULL;
                continue;
			}
            
            if ( line[ 0 ] == 'k' && getStringFromIndexWithDelim(line, "arutarna:", 2, token, sizeof(token)) )
			{
                xmlElement* xml1 = CreatXMLElement( doc , "karutarna" );
                xml->LinkEndChild( xml1 );
                
                char line0[ 320 ];
                char line1[ 320 ];
                char line2[ 320 ];
                getStringFromIndexWithDelim(token, ",", 1, line0, 256);
                getStringFromIndexWithDelim(line0, "=", 2, line1, 256);
                xml1->SetAttribute( "item" , line1 );
                
                getStringFromIndexWithDelim(token, ",", 2, line0, 256);
                getStringFromIndexWithDelim(line0, "=", 2, line1, 256);
                xml1->SetAttribute( "pet" , line1 );
                
                getStringFromIndexWithDelim(token, ",", 2, line0, 256);
                getStringFromIndexWithDelim(line0, "=", 2, line1, 256);
                getStringFromIndexWithDelim(line1, ".", 1, line2, 256);
                xml1->SetAttribute( "present0" , line2 );
                getStringFromIndexWithDelim(line1, ".", 2, line2, 256);
                xml1->SetAttribute( "present1" , line2 );
                getStringFromIndexWithDelim(line1, ".", 3, line2, 256);
                xml1->SetAttribute( "present2" , line2 );
                getStringFromIndexWithDelim(line1, ".", 4, line2, 256);
                xml1->SetAttribute( "present3" , line2 );
                getStringFromIndexWithDelim(line1, ".", 5, line2, 256);
                xml1->SetAttribute( "present4" , line2 );
                
                getStringFromIndexWithDelim(token, ",", 2, line0, 256);
                getStringFromIndexWithDelim(line0, "=", 2, line1, 256);
                getStringFromIndexWithDelim(line1, ".", 1, line2, 256);
                xml1->SetAttribute( "map" , line2 );
                getStringFromIndexWithDelim(line1, ".", 2, line2, 256);
                xml1->SetAttribute( "x" , line2 );
                getStringFromIndexWithDelim(line1, ".", 3, line2, 256);
                xml1->SetAttribute( "y" , line2 );
                
                xml1 = NULL;
                continue;
			}
            
            if ( line[ 0 ] != '\0' && line[ 0 ] != ' ' && line[ 0 ] != '\r' )
            {
                printf( "%s \n" , line );
                assert( 0 );
            }
            
            continue;
        }
        
        if ( tem == "scheduleman" )
        {
            if ( !xml )
            {
                xml = CreatXMLElement( doc , "scheduleMan" );
				root->LinkEndChild( xml );
            }
            
            if ( line[ 0 ] == 'i' && getStringFromIndexWithDelim(line, "d:", 2, token, sizeof(token)) )
			{
                xml->SetAttribute( "ID" , token );
                continue;
			}
            if ( line[ 0 ] == 'l' && getStringFromIndexWithDelim(line, "oopinterval:", 2, token, sizeof(token)) )
			{
                xml->SetAttribute( "loop" , token );
                continue;
			}
            if ( line[ 0 ] == 'c' && getStringFromIndexWithDelim(line, "hallengetimeout:", 2, token, sizeof(token)) )
			{
                xml->SetAttribute( "challengeTimeout" , token );
                continue;
			}
            if ( line[ 0 ] == 's' && getStringFromIndexWithDelim(line, "ettingtimeout:", 2, token, sizeof(token)) )
			{
                xml->SetAttribute( "settingTimeout" , token );
                continue;
			}
            if ( line[ 0 ] == 'f' && getStringFromIndexWithDelim(line, "ightinterval:", 2, token, sizeof(token)) )
			{
                xml->SetAttribute( "fightInterval" , token );
                continue;
			}
            
            if ( line[ 0 ] != '\0' && line[ 0 ] != ' ' && line[ 0 ] != '\r' )
            {
                printf( "%s \n" , line );
                assert( 0 );
            }
            
            continue;
        }
        
        if ( tem == "changeevent" )
        {
            if ( !xml )
            {
                xml = CreatXMLElement( doc , "changeEvent" );
				root->LinkEndChild( xml );
            }
            
            if ( line[ 0 ] == 'E' && getStringFromIndexWithDelim(line, "xChangeMa", 2, token, sizeof(token)) )
			{
                continue;
			}
            
            
            if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "omalMainMsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "nomalMainMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'a' && getStringFromIndexWithDelim(line, "NomalMainMsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "nomalMainMsg" , stringMap[ str ] );
                continue;
			}
            
            
            if ( line[ 0 ] == 'E' && getStringFromIndexWithDelim(line, "ventNo:", 2, token, sizeof(token)) )
            {
                xml1 = CreatXMLElement( doc , "event" );
				xml->LinkEndChild( xml1 );
                xml1->SetAttribute( "No" , token );
                continue;
            }
            if ( line[ 0 ] == 'E' && getStringFromIndexWithDelim(line, "vebtNo:", 2, token, sizeof(token)) )
            {
                xml1 = CreatXMLElement( doc , "event" );
				xml->LinkEndChild( xml1 );
                xml1->SetAttribute( "No" , token );
                continue;
            }
            
            if ( line[ 0 ] == 'E' && getStringFromIndexWithDelim(line, "ventEn", 2, token, sizeof(token)) )
            {
                xml1 = NULL;
                continue;
            }
            if ( line[ 0 ] == 'B' && getStringFromIndexWithDelim(line, "rea", 2, token, sizeof(token)) )
            {
                xml1->SetAttribute( "bk" , 1 );
                continue;
            }
            
            if ( line[ 0 ] == 'T' && getStringFromIndexWithDelim(line, "YPE:MESSAG", 2, token, sizeof(token)) )
            {
                xml1->SetAttribute( "type" , 2 );
                continue;
            }
            if ( line[ 0 ] == 'T' && getStringFromIndexWithDelim(line, "YPE:ACCEP", 2, token, sizeof(token)) )
            {
                xml1->SetAttribute( "type" , 1 );
                continue;
            }
            if ( line[ 0 ] == 'T' && getStringFromIndexWithDelim(line, "YPE:REQUES", 2, token, sizeof(token)) )
            {
                xml1->SetAttribute( "type" , 3 );
                continue;
            }
            if ( line[ 0 ] == 'T' && getStringFromIndexWithDelim(line, "YPE:CLEAN", 2, token, sizeof(token)) )
            {
                xml1->SetAttribute( "type" , 4 );
                continue;
            }
            if ( line[ 0 ] == 'C' && getStringFromIndexWithDelim(line, "harm:", 2, token, sizeof(token)) )
            {
                xml1->SetAttribute( "charm" , token );
                continue;
            }
            if ( line[ 0 ] == 'C' && getStringFromIndexWithDelim(line, "leanFlg:", 2, token, sizeof(token)) )
            {
                xml1->SetAttribute( "cleanFlag" , token );
                continue;
            }
            if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "otDel:", 2, token, sizeof(token)) )
            {
                xml1->SetAttribute( "notDel" , token );
                continue;
            }
            if ( line[ 0 ] == 'E' && getStringFromIndexWithDelim(line, "ndSetFlg:", 2, token, sizeof(token)) )
            {
                xml1->SetAttribute( "endSetFlag" , token );
                continue;
            }
            if ( line[ 0 ] == 'G' && getStringFromIndexWithDelim(line, "etStone:", 2, token, sizeof(token)) )
            {
                xml1->SetAttribute( "getStone" , token );
                continue;
            }
            if ( line[ 0 ] == 'M' && getStringFromIndexWithDelim(line, "ISSIONOVER:", 2, token, sizeof(token)) )
			{
				xml1->SetAttribute( "missionOver" , token );
                continue;
			}
            if ( line[ 0 ] == 'D' && getStringFromIndexWithDelim(line, "elStone:LV*", 2, token, sizeof(token)) )
            {
                xml1->SetAttribute( "delStoneLV" , token );
                continue;
            }
            if ( line[ 0 ] == 'P' && getStringFromIndexWithDelim(line, "ROFESSION:", 2, token, sizeof(token)) )
            {
                xml1->SetAttribute( "pro" , token );
                continue;
            }
            if ( line[ 0 ] == 'D' && getStringFromIndexWithDelim(line, "elStone:", 2, token, sizeof(token)) )
            {
                xml1->SetAttribute( "delStone" , token );
                continue;
            }
            if ( line[ 0 ] == 'E' && getStringFromIndexWithDelim(line, "VENT:", 2, token, sizeof(token)) )
            {
                ReadFree( xml1 , doc , token );
                continue;
            }
            if ( line[ 0 ] == 'D' && getStringFromIndexWithDelim( line, "elItem:", 2, token , 1024) )
            {
                char buffer[ 32 ];
                char line1[ 320 ];
                char line2[ 320 ];
                
                int n = 1;
                while ( getStringFromIndexWithDelim( token , ",", n, line1 , 256) )
                {
                    if ( getStringFromIndexWithDelim( line1 , "*", 2, line2 , 256) )
                    {
                        getStringFromIndexWithDelim( line1, "*", 1, line2 , 256);
                        sprintf( buffer , "delItem%d" , n - 1 );
                        xml1->SetAttribute( buffer , line2 );
                        
                        getStringFromIndexWithDelim( line1, "*", 2, line2 , 256);
                        sprintf( buffer , "delItemNum%d" , n - 1 );
                        xml1->SetAttribute( buffer , line2 );
                    }
                    else
                    {
                        sprintf( buffer , "delItem%d" , n - 1 );
                        xml1->SetAttribute( buffer , line1 );
                        sprintf( buffer , "delItemNum%d" , n - 1 );
                        xml1->SetAttribute( buffer , 1 );
                    }
                    n++;
                }
                continue;
            }
            if ( line[ 0 ] == 'G' && getStringFromIndexWithDelim( line, "etRandItem:", 2, token , 1024) )
            {
                char buffer[ 32 ];
                char line1[ 320 ];
                
                int n = 1;
                while ( getStringFromIndexWithDelim( token , ",", n, line1 , 256) )
                {
                    sprintf( buffer , "randItem%d" , n - 1 );
                    xml1->SetAttribute( buffer , line1 );
                    
                    n++;
                }
                continue;
            }
            
            if ( line[ 0 ] == 'C' && getStringFromIndexWithDelim(line, "leanFlgMsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "cleanFlagMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'C' && getStringFromIndexWithDelim(line, "leanMainMsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "cleanMainMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'A' && getStringFromIndexWithDelim(line, "cceptMsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "acceptMsg0" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'A' && getStringFromIndexWithDelim(line, "cceptMsg1:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "acceptMsg1" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'A' && getStringFromIndexWithDelim(line, "cceptMsg2:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "acceptMsg2" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'A' && getStringFromIndexWithDelim(line, "cceptMsg3:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "acceptMsg3" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'A' && getStringFromIndexWithDelim(line, "cceptMsg4:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "acceptMsg4" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'A' && getStringFromIndexWithDelim(line, "cceptMsg5:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "acceptMsg5" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'A' && getStringFromIndexWithDelim(line, "cceptMsg6:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "acceptMsg6" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'A' && getStringFromIndexWithDelim(line, "cceptMsg7:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "acceptMsg7" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'A' && getStringFromIndexWithDelim(line, "cceptMsg8:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "acceptMsg8" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'A' && getStringFromIndexWithDelim(line, "cceptMsg9:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "acceptMsg9" , stringMap[ str ] );
                continue;
			}
            
            if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "omalWinodowMsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "normalWinMsg0" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "omalWindowMsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "normalWinMsg0" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "omalWindowMsg1:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "normalWinMsg1" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "omalWindowMsg2:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "normalWinMsg2" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "omalWindowMsg3:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "normalWinMsg3" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "omalWindowMsg4:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "normalWinMsg4" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "omalWindowMsg5:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "normalWinMsg5" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "omalWindowMsg6:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "normalWinMsg6" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "omalWindowMsg7:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "normalWinMsg7" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "omalWindowMsg8:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "normalWinMsg8" , stringMap[ str ] );
                continue;
			}
            
            if ( line[ 0 ] == 'P' && getStringFromIndexWithDelim(line, "etFullMsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "petFullMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'I' && getStringFromIndexWithDelim(line, "temFullMsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "itemFullMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'T' && getStringFromIndexWithDelim(line, "hanksMsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "thanksMsg0" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'T' && getStringFromIndexWithDelim(line, "hanksMsg1:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "thanksMsg1" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'T' && getStringFromIndexWithDelim(line, "hanksMsg2:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "thanksMsg2" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'T' && getStringFromIndexWithDelim(line, "hanksMsg3:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "thanksMsg3" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'T' && getStringFromIndexWithDelim(line, "hanksMsg4:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "thanksMsg4" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'T' && getStringFromIndexWithDelim(line, "hanksMsg5:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "thanksMsg5" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'T' && getStringFromIndexWithDelim(line, "hanksMsg6:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "thanksMsg6" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'T' && getStringFromIndexWithDelim(line, "hanksMsg7:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "thanksMsg7" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'T' && getStringFromIndexWithDelim(line, "RANS7:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "thanksMsg7" , stringMap[ str ] );
                continue;
			}
            
            if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "omalMsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "nomalMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'S' && getStringFromIndexWithDelim(line, "toneLessMsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "stoneLessMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'R' && getStringFromIndexWithDelim(line, "equestMsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "requestMsg0" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'R' && getStringFromIndexWithDelim(line, "equestMsg1:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "requestMsg1" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'R' && getStringFromIndexWithDelim(line, "equestMsg2:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "requestMsg2" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'R' && getStringFromIndexWithDelim(line, "equestMsg3:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "requestMsg3" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'R' && getStringFromIndexWithDelim(line, "equestMsg4:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "requestMsg4" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'R' && getStringFromIndexWithDelim(line, "equestMsg5:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "requestMsg5" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'R' && getStringFromIndexWithDelim(line, "equestMsg6:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "requestMsg6" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'R' && getStringFromIndexWithDelim(line, "equestMsg7:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "requestMsg7" , stringMap[ str ] );
                continue;
			}
            
            
            
            
            if ( line[ 0 ] == 'K' && getStringFromIndexWithDelim(line, "eyWord:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "keyWord" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'S' && getStringFromIndexWithDelim(line, "toneFullMsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "stoneFullMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'P' && getStringFromIndexWithDelim(line, "et_Name:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "petName" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'S' && getStringFromIndexWithDelim(line, "topMsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "stopMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'E' && getStringFromIndexWithDelim(line, "ndStopMsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "endStopMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "oStopMsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml1->SetAttribute( "noStopMsg" , stringMap[ str ] );
                continue;
			}
            
            
            if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "pcWarp:", 2, token, sizeof(token)) )
			{
				xml2 = CreatXMLElement( doc , "warp" );
                xml1->LinkEndChild( xml2 );
                
				char	token1[128];
                
				int n = 1;
				while ( getStringFromIndexWithDelim(token, ",", n, token1, 128 ) )
				{
					char token2[ 128 ];
					getStringFromIndexWithDelim(token1, ".", 1, token2, 128 );
					int map = atoi( token2 );
					getStringFromIndexWithDelim(token1, ".", 2, token2, 128 );
					int x = atoi( token2 );
					getStringFromIndexWithDelim(token1, ".", 3, token2, 128 );
					int y = atoi( token2 );
                    
                    char buff[ 32 ];
                    sprintf( buff , "map%d" , n - 1 );
                    xml1->SetAttribute( buff , map );
                    sprintf( buff , "x%d" , n - 1 );
                    xml1->SetAttribute( buff , x );
                    sprintf( buff , "y%d" , n - 1 );
                    xml1->SetAttribute( buff , y );
                    
					n++;
				}
                
                xml2 = NULL;
                
                continue;
			}
            if ( line[ 0 ] == 'G' && getStringFromIndexWithDelim( line, "etItem:", 2, token , 1024) )
            {
                char buffer[ 32 ];
                char line1[ 320 ];
                
                int n = 1;
                while ( getStringFromIndexWithDelim( token , ",", n, line1 , 256) )
                {
                    sprintf( buffer , "getItem%d" , n - 1 );
                    xml1->SetAttribute( buffer , line1 );
                    n++;
                }
                continue;
            }
            if ( line[ 0 ] == 'G' && getStringFromIndexWithDelim( line, "etPet:", 2, token , 1024) )
            {
                char buffer[ 32 ];
                char line1[ 320 ];
                
                int n = 1;
                while ( getStringFromIndexWithDelim( token , ",", n, line1 , 256) )
                {
                    sprintf( buffer , "getPet%d" , n - 1 );
                    xml1->SetAttribute( buffer , line1 );
                    n++;
                }
                continue;
            }
            
            if ( line[ 0 ] == 'D' && getStringFromIndexWithDelim( line, "elPet:", 2, token , 1024) )
            {
                int nnn111 = 1;
                
                while ( getStringFromIndexWithDelim( line, ",", nnn111, token , 1024 ) )
                {
                    char line1[ 320 ];
                    
                    char buffer[ 32 ];
                    char line2[ 320 ];
                    char line3[ 320 ];
                    
                    xmlElement* xml2 = CreatXMLElement( doc , "pet" );
                    xml1->LinkEndChild( xml2 );
                    
                    if ( getStringFromIndexWithDelim( token, "PET=", 2, line1 , 256) )
                    {
                        getStringFromIndexWithDelim( line1, "-", 1, line2 , 256 );
                        int lv = atoi( line2 );
                        xml2->SetAttribute( "delPetLV" , lv );
                    }
                    else if ( getStringFromIndexWithDelim( token, "PET>=", 2, line1 , 256) )
                    {
                        getStringFromIndexWithDelim( line1, "-", 1, line2 , 256 );
                        int lv = atoi( line2 );
                        xml2->SetAttribute( "delPetLVMin" , lv );
                    }
                    else if ( getStringFromIndexWithDelim( token, "PET>", 2, line1 , 256) )
                    {
                        getStringFromIndexWithDelim( line1, "-", 1, line2 , 256 );
                        int lv = atoi( line2 ) + 1;
                        xml2->SetAttribute( "delPetLVMin" , lv );
                    }
                    else if ( getStringFromIndexWithDelim( token, "PET<=", 2, line1 , 256) )
                    {
                        getStringFromIndexWithDelim( line1, "-", 1, line2 , 256 );
                        int lv = atoi( line2 );
                        xml2->SetAttribute( "delPetLVMax" , lv );
                    }
                    else if ( getStringFromIndexWithDelim( token, "PET<", 2, line1 , 256) )
                    {
                        getStringFromIndexWithDelim( line1, "-", 1, line2 , 256 );
                        int lv = atoi( line2 ) - 1;
                        xml2->SetAttribute( "delPetLVMax" , lv );
                    }
                    else if ( getStringFromIndexWithDelim( token, "EVDE", 2, line1 , 256) )
                    {
                        xml2->SetAttribute( "del" , 1 );
                    }
                    else
                    {
                        assert( 0 );
                    }
                    
                    getStringFromIndexWithDelim( line1, "-", 2, line2 , 256 );
                    getStringFromIndexWithDelim( line2, "*", 1, line3 , 256 );
                    int idd = atoi( line3 );
                    xml2->SetAttribute( "delPetBaseID" , idd );
                    
                    getStringFromIndexWithDelim( line2, "*", 2, line3 , 256 );
                    int num = atoi( line3 );
                    xml2->SetAttribute( "delPetNum" , num );
                    xml2 = NULL;
                    
                    nnn111++;
                }
                
                continue;
            }
            
            if ( line[ 0 ] != '\0' && line[ 0 ] != ' ' && line[ 0 ] != '\r' )
            {
                printf( "%s \n" , line );
                assert( 0 );
            }
            
            continue;
        }
        
        if ( tem == "NPC_GambleMaster" )
        {
            if ( !xml )
            {
                xml = CreatXMLElement( doc , "gambleMaster" );
				root->LinkEndChild( xml );
            }
            
//            {
//            GAMBLE_TYPE:master_npc
//            gamble_code:10001
//            game_time:15000
//            standby_time:1000
//            GtoG:1|2
//            AI:0
//            con:TRUE
//            gamble_msg01:欢迎光临！
//            gamble_msg02:            轮盘规则
//            gamble_msg03:            游戏积分
//            gamble_msg04:            个人积分
//            gamble_msg05:              离开
//                //
//            page_num11:\n本游戏为２４小时营业，全年无休。\n每场次间隔约有１到２分钟时间。\n请玩家将彩券丢在圆形格上，\n等候游戏开始。\n一旦主持人喊买好离手，\n便不能再丢彩券及拿走彩券。
//            page_num12:\n红绿单双中奖积分加１点，没中奖扣积分１点。\n号码中奖积分加２０点，没中奖扣积分１点。\n横列中奖积分加２点，没中奖扣积分１点。\n双号中奖积分加１０点，没中奖扣积分１点。
//            page_num13:\n号码００中奖积分加４０点，没中奖扣积分１点。\n范围中奖积分加１点，没中奖扣积分１点。\n符号Ｘ为主持人通杀。
//            page_num14:\n请玩家游戏中不要下线或离开\n轮盘游戏场。\n否则视同弃权论，彩卷及积分不予归还。
//                //
//            page_num21:\n游戏积分可以向游乐场银行\n换取奖品。
//                //
//            page_endmsg:\n如有需要解说的可以来找我。
//            standby_msg:买好离手，即将开始！
//            start_msg:游戏开始。
//            end_msg:游戏结束！
//            }
            
            if ( line[ 0 ] == 'G' && getStringFromIndexWithDelim(line, "AMBLE_TYPE:", 2, token, sizeof(token)) )
			{
                continue;
			}
            if ( line[ 0 ] == 'g' && getStringFromIndexWithDelim(line, "amble_code:", 2, token, sizeof(token)) )
			{
				xml->SetAttribute( "code" , token );
                continue;
			}
            if ( line[ 0 ] == 'g' && getStringFromIndexWithDelim(line, "ame_time:", 2, token, sizeof(token)) )
			{
				xml->SetAttribute( "time" , token );
                continue;
			}
            if ( line[ 0 ] == 's' && getStringFromIndexWithDelim(line, "tandby_time:", 2, token, sizeof(token)) )
			{
				xml->SetAttribute( "standbyTime" , token );
                continue;
			}
            if ( line[ 0 ] == 'G' && getStringFromIndexWithDelim(line, "toG:", 2, token, sizeof(token)) )
			{
                char	token1[128];
                getStringFromIndexWithDelim(token, "|", 1, token1, 128 );
                int x = atoi( token1 );
                getStringFromIndexWithDelim(token, "|", 2, token1, 128 );
                int y = atoi( token1 );
                
				xml->SetAttribute( "to0" , x );
				xml->SetAttribute( "to1" , y );
                
                continue;
			}
            if ( line[ 0 ] == 'A' && getStringFromIndexWithDelim(line, "I:", 2, token, sizeof(token)) )
			{
				xml->SetAttribute( "AI" , token );
                continue;
			}
            if ( line[ 0 ] == 'c' && getStringFromIndexWithDelim(line, "on:TRU", 2, token, sizeof(token)) )
			{
				xml->SetAttribute( "con" , 1 );
                continue;
			}
            if ( line[ 0 ] == 'c' && getStringFromIndexWithDelim(line, "on:FA", 2, token, sizeof(token)) )
			{
				xml->SetAttribute( "con" , 0 );
                continue;
			}
            if ( line[ 0 ] == 'g' && getStringFromIndexWithDelim(line, "amble_msg01:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "gambleMsg0" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'g' && getStringFromIndexWithDelim(line, "amble_msg02:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "gambleMsg1" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'g' && getStringFromIndexWithDelim(line, "amble_msg03:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "gambleMsg2" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'g' && getStringFromIndexWithDelim(line, "amble_msg04:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "gambleMsg3" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'g' && getStringFromIndexWithDelim(line, "amble_msg05:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "gambleMsg4" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'g' && getStringFromIndexWithDelim(line, "amble_msg06:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "gambleMsg5" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'p' && getStringFromIndexWithDelim(line, "age_num11:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "pageNum0" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'p' && getStringFromIndexWithDelim(line, "age_num12:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "pageNum1" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'p' && getStringFromIndexWithDelim(line, "age_num13:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "pageNum2" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'p' && getStringFromIndexWithDelim(line, "age_num14:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "pageNum3" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'p' && getStringFromIndexWithDelim(line, "age_num21:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "pageNum4" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'p' && getStringFromIndexWithDelim(line, "age_endmsg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "pageEndMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 's' && getStringFromIndexWithDelim(line, "tandby_msg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "standbyMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 's' && getStringFromIndexWithDelim(line, "tart_msg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "startMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'e' && getStringFromIndexWithDelim(line, "nd_msg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "endMsg" , stringMap[ str ] );
                continue;
			}
            
            
            if ( line[ 0 ] == '{' )
            {
                continue;
            }
            if ( line[ 0 ] == '}' )
            {
                continue;
            }
            
            if ( line[ 0 ] != '\0' && line[ 0 ] != ' ' && line[ 0 ] != '\r' && line[ 0 ] != '/' )
            {
                printf( "%s \n" , line );
                assert( 0 );
            }
            
            continue;
        }
        
        if ( tem == "NPC_GambleRoulette" )
        {
            if ( !xml )
            {
                xml = CreatXMLElement( doc , "gambleRun" );
				root->LinkEndChild( xml );
            }
            
            if ( line[ 0 ] == 'G' && getStringFromIndexWithDelim(line, "AMBLE_TYPE:", 2, token, sizeof(token)) )
			{
                continue;
			}
            if ( line[ 0 ] == 'r' && getStringFromIndexWithDelim(line, "un_time:", 2, token, sizeof(token)) )
			{
				xml->SetAttribute( "runTime" , token );
                continue;
			}
            if ( line[ 0 ] == 'l' && getStringFromIndexWithDelim(line, "oop_tme:", 2, token, sizeof(token)) )
			{
				xml->SetAttribute( "loopTime" , token );
                continue;
			}
            
            if ( line[ 0 ] == 'r' && getStringFromIndexWithDelim(line, "oulette:", 2, token, sizeof(token)) )
			{
                xml1 = CreatXMLElement( doc , "run" );
                xml->LinkEndChild( xml1 );
                
				char	token1[128];
                
				int n = 1;
				while ( getStringFromIndexWithDelim(token, ";", n, token1, 128 ) )
				{
					char token2[ 128 ];
					getStringFromIndexWithDelim(token1, ",", 1, token2, 128 );
					int x = atoi( token2 );
					getStringFromIndexWithDelim(token1, ",", 2, token2, 128 );
					int y = atoi( token2 );
                    
                    char buff[ 32 ];
                    sprintf( buff , "x%d" , n - 1 );
                    xml1->SetAttribute( buff , x );
                    sprintf( buff , "y%d" , n - 1 );
                    xml1->SetAttribute( buff , y );
                    
					n++;
				}
                
                xml1 = NULL;
                continue;
			}
            
            if ( line[ 0 ] == '{' )
            {
                continue;
            }
            if ( line[ 0 ] == '}' )
            {
                continue;
            }

            if ( line[ 0 ] != '\0' && line[ 0 ] != ' ' && line[ 0 ] != '\r' )
            {
                printf( "%s \n" , line );
                assert( 0 );
            }
            
            continue;
        }
        
        if ( tem == "petracepet" )
        {
            // 宠物竞速
            
            if ( !xml )
            {
                xml = CreatXMLElement( doc , "petRace" );
				root->LinkEndChild( xml );
            }
            
            if ( line[ 0 ] == 's' && getStringFromIndexWithDelim(line, "howstopx:", 2, token, sizeof(token)) )
			{
				xml->SetAttribute( "stopX" , token );
                continue;
			}
            if ( line[ 0 ] == 's' && getStringFromIndexWithDelim(line, "howstopy:", 2, token, sizeof(token)) )
			{
				xml->SetAttribute( "stopY" , token );
                continue;
			}
            if ( line[ 0 ] == 'r' && getStringFromIndexWithDelim(line, "outeto:", 2, token, sizeof(token)) )
			{
                xml1 = CreatXMLElement( doc , "route" );
                xml->LinkEndChild( xml1 );
                
				char	token1[128];
                
				int n = 1;
				while ( getStringFromIndexWithDelim(token, ";", n, token1, 128 ) )
				{
					char token2[ 128 ];
					getStringFromIndexWithDelim(token1, ",", 1, token2, 128 );
					int x = atoi( token2 );
					getStringFromIndexWithDelim(token1, ",", 2, token2, 128 );
					int y = atoi( token2 );
                    
                    char buff[ 32 ];
                    sprintf( buff , "x%d" , n - 1 );
                    xml1->SetAttribute( buff , x );
                    sprintf( buff , "y%d" , n - 1 );
                    xml1->SetAttribute( buff , y );
                    
					n++;
				}
                
                xml1 = NULL;
                continue;
			}
            
            continue;
        }
        
        if ( tem == "petshop" || tem == "npcgen_petshop" )
        {
            if ( !xml )
            {
                xml = CreatXMLElement( doc , "petShop" );
				root->LinkEndChild( xml );
            }
            
            if ( line[ 0 ] == 'n' && getStringFromIndexWithDelim(line, "omal_rate:", 2, token, sizeof(token)) )
			{
				xml->SetAttribute( "normalRate" , token );
                continue;
			}
            
            if ( line[ 0 ] == 'm' && getStringFromIndexWithDelim(line, "ain_msg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "mainMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'r' && getStringFromIndexWithDelim(line, "ealy_msg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "realyMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 't' && getStringFromIndexWithDelim(line, "hanks_msg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "thanksMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'c' && getStringFromIndexWithDelim(line, "ost_msg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "costMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'o' && getStringFromIndexWithDelim(line, "ver_msg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "overMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'p' && getStringFromIndexWithDelim(line, "ooltanks_msg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "poolTanksMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'p' && getStringFromIndexWithDelim(line, "oolfull_msg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "poolFullMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'g' && getStringFromIndexWithDelim(line, "etfull_msg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "getFullMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'p' && getStringFromIndexWithDelim(line, "ool_flg:", 2, token, sizeof(token)) )
			{
				xml->SetAttribute( "poolFlag" , token );
                continue;
			}
            if ( line[ 0 ] == 'p' && getStringFromIndexWithDelim(line, "ool_cost:", 2, token, sizeof(token)) )
			{
				xml->SetAttribute( "poolCost" , token );
                continue;
			}
            if ( line[ 0 ] == 's' && getStringFromIndexWithDelim(line, "pecial_rate:", 2, token, sizeof(token)) )
			{
				xml->SetAttribute( "specialRate" , token );
                continue;
			}
            if ( line[ 0 ] == 's' && getStringFromIndexWithDelim(line, "pecial_pet:", 2, token, sizeof(token)) )
			{
				xml->SetAttribute( "specialPet" , token );
                continue;
			}
            
            if ( line[ 0 ] != '\0' )
            {
                assert( 0 );
            }

            continue;
        }
        
        if ( tem == "GambleBank" )
        {
            
            if ( !xml )
            {
                xml = CreatXMLElement( doc , "gambleBank" );
				root->LinkEndChild( xml );
            }
            
            if ( line[ 0 ] == '{' )
            {
                continue;
            }
            if ( line[ 0 ] == '}' )
            {
                continue;
            }
            
            if ( line[ 0 ] == 'G' && getStringFromIndexWithDelim(line, "AMBLE_TYPE:", 2, token, sizeof(token)) )
			{
				xml->SetAttribute( "type" , token );
                continue;
			}
            if ( line[ 0 ] == 'g' && getStringFromIndexWithDelim(line, "amble_start:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "gambleStart" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'g' && getStringFromIndexWithDelim(line, "amble_msg01:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "gambleMsg1" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'g' && getStringFromIndexWithDelim(line, "amble_msg02:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "gambleMsg2" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'g' && getStringFromIndexWithDelim(line, "amble_msg03:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "gambleMsg3" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'g' && getStringFromIndexWithDelim(line, "amble_msg04:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "gambleMsg4" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'g' && getStringFromIndexWithDelim(line, "amble_msg05:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "gambleMsg5" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'f' && getStringFromIndexWithDelim(line, "ull_msg1:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "fullMsg0" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'f' && getStringFromIndexWithDelim(line, "ull_msg2:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "fullMsg1" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'm' && getStringFromIndexWithDelim(line, "oney_msg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "noMoneyMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'e' && getStringFromIndexWithDelim(line, "nd_msg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "endMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'g' && getStringFromIndexWithDelim(line, "etmax_msg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "maxMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'g' && getStringFromIndexWithDelim(line, "etmin_msg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "minMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'e' && getStringFromIndexWithDelim(line, "rror_msg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "errorMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'n' && getStringFromIndexWithDelim(line, "omal_msg:", 2, token, sizeof(token)) )
			{
                continue;
			}
            
            if ( line[ 0 ] != '\0' )
            {
                assert( 0 );
            }
            

            continue;
        }
        
        if ( tem == "FreePetSkill" || tem == "petskillshop" )
        {
            if ( !xml )
            {
                xml = CreatXMLElement( doc , "petSkill" );
				root->LinkEndChild( xml );
            }
            
            if ( line[ 0 ] == '{' )
            {
                continue;
            }
            if ( line[ 0 ] == '}' )
            {
                continue;
            }
            
            if ( line[ 0 ] == 's' && getStringFromIndexWithDelim(line, "tart_msg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "startMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'm' && getStringFromIndexWithDelim(line, "ain_msg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "mainMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'n' && getStringFromIndexWithDelim(line, "othing_msg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "nothingMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'e' && getStringFromIndexWithDelim(line, "rr_msg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "errorMsg" , stringMap[ str ] );
                continue;
			}
            
            if ( line[ 0 ] == 's' && getStringFromIndexWithDelim(line, "kill_rate:", 2, token, sizeof(token)) )
			{
				xml->SetAttribute( "skillRate" , token );
                continue;
			}
            if ( line[ 0 ] == 'p' && getStringFromIndexWithDelim(line, "rofession_class:", 2, token, sizeof(token)) )
			{
				xml->SetAttribute( "proClass" , token );
                continue;
			}
            if ( line[ 0 ] == 'p' && getStringFromIndexWithDelim(line, "et_skill:", 2, token, sizeof(token)) )
			{
                xml1 = CreatXMLElement( doc , "skill" );
                xml->LinkEndChild( xml1 );
                
				char	token1[128];
                
				int n = 1;
				while ( getStringFromIndexWithDelim(token, ",", n, token1, 128 ) )
				{
                    char buff[ 32 ];
                    sprintf( buff , "s%d" , n - 1 );
                    xml1->SetAttribute( buff , atoi( token1 ) );
					n++;
				}
                xml1 = NULL;
                continue;
			}
            
            if ( line[ 0 ] != '\0' )
            {
                assert( 0 );
            }
            
            continue;
        }
        
        if ( tem == "ITEMCHANGE" )
        {
            if ( !xml )
            {
                xml = CreatXMLElement( doc , "itemChange" );
				root->LinkEndChild( xml );
            }
            
            if ( line[ 0 ] == 'F' && getStringFromIndexWithDelim(line, "REE:", 2, token, sizeof(token)) )
			{
				//ReadFree( xml , doc , token );
                continue;
			}
            
            if ( line[ 0 ] == 'S' && getStringFromIndexWithDelim(line, "TART_MSG:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "startMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'M' && getStringFromIndexWithDelim(line, "enuHead:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "menuHead" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "eedHead:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "needHead" , stringMap[ str ] );
                continue;
			}
            
            if ( line[ 0 ] == '{' )
            {
                xml1 = CreatXMLElement( doc , "change" );
				xml->LinkEndChild( xml1 );
                continue;
            }
            
            if ( line[ 0 ] == '}' )
            {
                xml1 = NULL;
                continue;
            }
            
            if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim( line, "eedItem:", 2, token , 1024) )
            {
                char buffer[ 32 ];
                char line1[ 320 ];
                
                int n = 1;
                while ( getStringFromIndexWithDelim( token , ",", n, line1 , 256) )
                {
                    sprintf( buffer , "needItem%d" , n - 1 );
                    xml1->SetAttribute( buffer , line1 );
                    n++;
                }
                
                continue;
            }
            if ( line[ 0 ] == 'D' && getStringFromIndexWithDelim( line, "elItem:", 2, token , 1024) )
            {
                char buffer[ 32 ];
                char line1[ 320 ];
                char line2[ 320 ];
                
                int n = 1;
                while ( getStringFromIndexWithDelim( token , ",", n, line1 , 256) )
                {
                    if ( getStringFromIndexWithDelim( line1 , "*", 2, line2 , 256) )
                    {
                        getStringFromIndexWithDelim( line1, "*", 1, line2 , 256);
                        sprintf( buffer , "delItem%d" , n - 1 );
                        xml1->SetAttribute( buffer , line2 );
                        
                        getStringFromIndexWithDelim( line1, "*", 2, line2 , 256);
                        sprintf( buffer , "delItemNum%d" , n - 1 );
                        xml1->SetAttribute( buffer , line2 );
                    }
                    else
                    {
                        sprintf( buffer , "delItem%d" , n - 1 );
                        xml1->SetAttribute( buffer , line1 );
                        sprintf( buffer , "delItemNum%d" , n - 1 );
                        xml1->SetAttribute( buffer , 1 );
                    }
                    n++;
                }
                
                continue;
            }
            if ( line[ 0 ] == 'D' && getStringFromIndexWithDelim(line, "elGold:", 2, token, sizeof(token)) )
			{
				xml1->SetAttribute( "delGold" , token );
                continue;
			}
            if ( line[ 0 ] == 'A' && getStringFromIndexWithDelim(line, "ddItem:", 2, token, sizeof(token)) )
			{
				xml1->SetAttribute( "addItem" , token );
                continue;
			}
            if ( line[ 0 ] == 'C' && getStringFromIndexWithDelim(line, "HANGEITEM:", 2, token, sizeof(token)) )
			{
				xml1->SetAttribute( "changeItem" , token );
                continue;
			}
            if ( line[ 0 ] == 'G' && getStringFromIndexWithDelim( line, "etRandItem:", 2, token , 1024) )
            {
                char buffer[ 32 ];
                char line1[ 320 ];
                
                int n = 1;
                while ( getStringFromIndexWithDelim( token , ",", n, line1 , 256) )
                {
                    sprintf( buffer , "randItem%d" , n - 1 );
                    xml1->SetAttribute( buffer , line1 );
                    
                    n++;
                }
                continue;
            }
            

            if ( line[ 0 ] != '\0' )
            {
                assert( 0 );
            }
            
            continue;
        }
        
        if ( tem == "airplane" || tem == "bus" )
        {
            if ( !xml )
            {
                xml = CreatXMLElement( doc , "airplane" );
				root->LinkEndChild( xml );
            }
            
            if ( line[ 0 ] == 'r' && getStringFromIndexWithDelim(line, "routenum:", 2, token, sizeof(token)) )
			{
				xml->SetAttribute( "routeNum" , token );
                continue;
			}
            if ( line[ 0 ] == 'w' && getStringFromIndexWithDelim(line, "aittime:", 2, token, sizeof(token)) )
			{
				xml->SetAttribute( "waitTime" , token );
                continue;
			}
            if ( line[ 0 ] == 'n' && getStringFromIndexWithDelim(line, "eedstone:", 2, token, sizeof(token)) )
			{
				xml->SetAttribute( "needStone" , token );
                continue;
			}
            if ( line[ 0 ] == 's' && getStringFromIndexWithDelim(line, "eflg:", 2, token, sizeof(token)) )
			{
				xml->SetAttribute( "seFlag" , token );
                continue;
			}
            if ( line[ 0 ] == 'p' && getStringFromIndexWithDelim(line, "ickupitem:", 2, token, sizeof(token)) )
			{
				xml->SetAttribute( "pickupItem" , token );
                continue;
			}
            if ( line[ 0 ] == 'o' && getStringFromIndexWithDelim(line, "neway:", 2, token, sizeof(token)) )
			{
				xml->SetAttribute( "oneWay" , token );
                continue;
			}
            if ( line[ 0 ] == 'w' && getStringFromIndexWithDelim(line, "ave:", 2, token, sizeof(token)) )
			{
				xml->SetAttribute( "wave" , token );
                continue;
			}
            if ( line[ 0 ] == 'W' && getStringFromIndexWithDelim(line, "AVE:", 2, token, sizeof(token)) )
			{
				xml->SetAttribute( "wave" , token );
                continue;
			}
            if ( line[ 0 ] == 'r' && getStringFromIndexWithDelim(line, "outename1:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "routeName" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'r' && getStringFromIndexWithDelim(line, "outename1:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "routeName" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'm' && getStringFromIndexWithDelim(line, "sg_gettingon:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "msgGettingOn" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'm' && getStringFromIndexWithDelim(line, "sg_notparty:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "msgNoParty" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'm' && getStringFromIndexWithDelim(line, "sg_overparty:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "msgOverParty" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'm' && getStringFromIndexWithDelim(line, "sg_denieditem:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "msgDeniedItem" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'm' && getStringFromIndexWithDelim(line, "sg_denieditem:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "msgDeniedItem" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'm' && getStringFromIndexWithDelim(line, "sg_stone:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "msgStone" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'm' && getStringFromIndexWithDelim(line, "sg_start:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "msgStart" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'm' && getStringFromIndexWithDelim(line, "sg_end:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "msgEnd" , stringMap[ str ] );
                continue;
			}
            
            
            
            if ( line[ 0 ] == 'd' && getStringFromIndexWithDelim(line, "enieditem:", 2, token, sizeof(token)) )
			{
                xml1 = CreatXMLElement( doc , "deniedItem" );
                xml->LinkEndChild( xml1 );
                
				char	token1[128];
                
				int n = 1;
				while ( getStringFromIndexWithDelim(token, ",", n, token1, 128 ) )
				{
                    char buff[ 32 ];
                    sprintf( buff , "item%d" , n - 1 );
                    xml1->SetAttribute( buff , atoi( token1 ) );
					n++;
				}
                xml1 = NULL;
                continue;
			}
            
            
            if ( line[ 0 ] == 'r' && getStringFromIndexWithDelim(line, "outeto1:", 2, token, sizeof(token)) )
			{
                xml1 = CreatXMLElement( doc , "route" );
                xml->LinkEndChild( xml1 );
                
				char	token1[128];
                
				int n = 1;
				while ( getStringFromIndexWithDelim(token, ";", n, token1, 128 ) )
				{
					char token2[ 128 ];
					getStringFromIndexWithDelim(token1, ",", 1, token2, 128 );
					int map = atoi( token2 );
					getStringFromIndexWithDelim(token1, ",", 2, token2, 128 );
					int x = atoi( token2 );
					getStringFromIndexWithDelim(token1, ",", 3, token2, 128 );
					int y = atoi( token2 );
                    
                    char buff[ 32 ];
                    sprintf( buff , "map%d" , n - 1 );
                    xml1->SetAttribute( buff , map );
                    sprintf( buff , "x%d" , n - 1 );
                    xml1->SetAttribute( buff , x );
                    sprintf( buff , "y%d" , n - 1 );
                    xml1->SetAttribute( buff , y );
                    
					n++;
				}
                
                xml1 = NULL;
                continue;
			}
            
            
            if ( line[ 0 ] != '\0' )
            {
                assert( 0 );
            }
            
            continue;
        }
        
        if ( tem == "ProfessionShop" )
        {
            if ( !xml )
            {
                xml = CreatXMLElement( doc , "professionShop" );
				root->LinkEndChild( xml );
            }
            
            if ( line[ 0 ] == '{' )
            {
                continue;
            }
            if ( line[ 0 ] == '}' )
            {
                continue;
            }
            
            if ( line[ 0 ] == 's' && getStringFromIndexWithDelim(line, "tart_msg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "startMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'm' && getStringFromIndexWithDelim(line, "ain_msg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "mainMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'n' && getStringFromIndexWithDelim(line, "othing_msg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "nothingMsg" , stringMap[ str ] );
                continue;
			}
            if ( line[ 0 ] == 'e' && getStringFromIndexWithDelim(line, "rr_msg:", 2, token, sizeof(token)) )
			{
				wstring str = AnsitoUnicode( token );
				if ( stringMap.find( str ) == stringMap.end() )
				{
					stringMap[ str ] = stringMap.size();
				}
				xml->SetAttribute( "errorMsg" , stringMap[ str ] );
                continue;
			}
            
            if ( line[ 0 ] == 's' && getStringFromIndexWithDelim(line, "kill_rate:", 2, token, sizeof(token)) )
			{
				xml->SetAttribute( "skillRate" , token );
                continue;
			}
            if ( line[ 0 ] == 'p' && getStringFromIndexWithDelim(line, "rofession_class:", 2, token, sizeof(token)) )
			{
				xml->SetAttribute( "proClass" , token );
                continue;
			}
            if ( line[ 0 ] == 'p' && getStringFromIndexWithDelim(line, "rofession_skill:", 2, token, sizeof(token)) )
			{
                xml1 = CreatXMLElement( doc , "skill" );
                xml->LinkEndChild( xml1 );
                
				char	token1[128];
                
				int n = 1;
				while ( getStringFromIndexWithDelim(token, ",", n, token1, 128 ) )
				{
                    char buff[ 32 ];
                    sprintf( buff , "s%d" , n - 1 );
                    xml1->SetAttribute( buff , atoi( token1 ) );
					n++;
				}
                xml1 = NULL;
                continue;
			}
            if ( line[ 0 ] == 't' && getStringFromIndexWithDelim(line, "rans:", 2, token, sizeof(token)) )
			{
                xml1 = CreatXMLElement( doc , "trans" );
                xml->LinkEndChild( xml1 );
                
				char	token1[128];
                
				int n = 1;
				while ( getStringFromIndexWithDelim(token, ",", n, token1, 128 ) )
				{
                    char buff[ 32 ];
                    sprintf( buff , "t%d" , n - 1 );
                    xml1->SetAttribute( buff , atoi( token1 ) );
					n++;
				}
                xml1 = NULL;
                continue;
			}
            
            if ( line[ 0 ] != '\0' )
            {
                assert( 0 );
            }
            
            continue;
        }
        
        if ( (int)tem.find( "npcgen_" ) == 0 )
        {
            continue;
        }
        
        
        
        
        
        
        if ( tem == "DuelRanKings" || tem == "duelranking" )
        {
            assert( 0 );
            continue;
        }
        if ( tem == "BodyLan" )
        {
            assert( 0 );
            continue;
        }
        if ( tem == "Profession" )
        {
            assert( 0 );
            continue;
        }
        if ( tem == "auctioneer" )
        {
            assert( 0 );
            continue;
        }
        if ( tem == "npc_checkman" )
        {
            assert( 0 );
            continue;
        }
        if ( tem == "warp" )
        {
            continue;
        }
        
        printf( "%s\n" , tem.c_str() );
        assert( 0 );
        

//		if ( !xml )
//		{
//			if (  line[ 0 ] == 'e' && getStringFromIndexWithDelim(line, "ntype:", 2, token, sizeof(token)) )
//			{
//				// battle,,
//				xml = CreatXMLElement( doc , "battle" );
//				root->LinkEndChild( xml );
//				n555 = 1;
//				continue;
//			}
//			else if ( line[ 0 ] == 'O' && getStringFromIndexWithDelim(line, "VE", 2, token, sizeof(token)) )
//			{
//				n555 = 2;
//				xml = CreatXMLElement( doc , "ove" );
//				root->LinkEndChild( xml );
//				continue;
//			}
//			else if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "EWEVENT", 2, token, sizeof(token)) )
//			{
//				n555 = 20;
//				xml = CreatXMLElement( doc , "newEvent" );
//				root->LinkEndChild( xml );
//				continue;
//			}
//			else if ( line[ 0 ] == 's' && getStringFromIndexWithDelim(line, "amugiru:", 2, token, sizeof(token) ) )
//			{
//				n555 = 4;
//				xml = CreatXMLElement( doc , "samugiru" );
//				root->LinkEndChild( xml );
//				continue;
//			}
//			else if ( line[ 0 ] == 'm' && getStringFromIndexWithDelim(line, "arinasu:", 2, token, sizeof(token) ) )
//			{
//				n555 = 4;
//				xml = CreatXMLElement( doc , "marinasu" );
//				root->LinkEndChild( xml );
//				continue;
//			}
//			else if ( line[ 0 ] == 'j' && getStringFromIndexWithDelim(line, "aja:", 2, token, sizeof(token) ) )
//			{
//				n555 = 4;
//				xml = CreatXMLElement( doc , "jaja" );
//				root->LinkEndChild( xml );
//				continue;
//			}
//			else if ( line[ 0 ] == 'k' && getStringFromIndexWithDelim(line, "arutarna:", 2, token, sizeof(token) ) )
//			{
//				n555 = 4;
//				xml = CreatXMLElement( doc , "karutarna" );
//				root->LinkEndChild( xml );
//				continue;
//			}
//			else if ( line[ 0 ] == 'P' && getStringFromIndexWithDelim(line, "ETTRANS:", 2, token, sizeof(token) ) )
//			{
//				n555 = 5;
//				xml = CreatXMLElement( doc , "petTrans" );
//				root->LinkEndChild( xml );
//				continue;
//			}
//			else if ( line[ 0 ] == 'T' && getStringFromIndexWithDelim(line, "ENSEI:", 2, token, sizeof(token) ) )
//			{
//				n555 = 5;
//				xml = CreatXMLElement( doc , "trans" );
//				root->LinkEndChild( xml );
//				continue;
//			}
//			else if ( line[ 0 ] == 'b' && getStringFromIndexWithDelim(line, "uy_rate:", 2, token, sizeof(token) ) )
//			{
//				n555 = 10;
//				xml = CreatXMLElement( doc , "shop" );
//				root->LinkEndChild( xml );
//				xml->SetAttribute( "buyRate" , atoi( token ) );
//				continue;
//			}
//			else if ( line[ 0 ] == 'G' && getStringFromIndexWithDelim(line, "AMBLE_TYPE:", 2, token, sizeof(token) ) )
//			{
//				n555 = 30;
//				xml = CreatXMLElement( doc , "bank" );
//				root->LinkEndChild( xml );
//				continue;
//			}
//			else if ( line[ 0 ] == 'w' && getStringFromIndexWithDelim(line, "inno=", 2, token, sizeof(token) ) )
//			{
//				n555 = 40;
//				xml = CreatXMLElement( doc , "win" );
//				root->LinkEndChild( xml );
//				continue;
//			}
//			else if ( line[ 0 ] == 'r' && getStringFromIndexWithDelim(line, "outeto:", 2, token, sizeof(token) ) )
//			{
//				n555 = 41;
//				xml = CreatXMLElement( doc , "routeTo" );
//				root->LinkEndChild( xml );
//				continue;
//			}
//			else if ( line[ 0 ] == 'r' && getStringFromIndexWithDelim(line, "outenum:", 2, token, sizeof(token) ) )
//			{
//				n555 = 50;
//				xml = CreatXMLElement( doc , "route" );
//				root->LinkEndChild( xml );
//				xml->SetAttribute( "num" , atoi( token ) );
//				continue;
//			}
//			else if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "omalMainMsg:", 2, token, sizeof(token) ) )
//			{
//				n555 = 999;
//				xml = CreatXMLElement( doc , "main" );
//				root->LinkEndChild( xml );
//
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				
//				xml->SetAttribute( "msg" , stringMap[ str ] );
//				continue;
//			}
//			else if ( line[ 0 ] == 'W' && getStringFromIndexWithDelim(line, "AVE:", 2, token, sizeof(token) ) )
//			{
//				n555 = 60;
//				xml = CreatXMLElement( doc , "run" );
//				root->LinkEndChild( xml );
//				xml->SetAttribute( "wave" , atoi( token ) );
//				continue;
//			}
//			else if ( line[ 0 ] == 'N' && line[ 1 ] == 'E' && line[ 2 ] == 'W' && line[ 3 ] == 'W' &&
//				line[ 4 ] == 'A' && line[ 5 ] == 'R' && line[ 6 ] == 'P' && line[ 7 ] == 'M' )
//			{
//				n555 = 61;
//				xml = CreatXMLElement( doc , "newWarpMan" );
//				root->LinkEndChild( xml );
//				continue;
//			}
//			else if ( line[ 0 ] == 'N' && line[ 1 ] == 'E' && line[ 2 ] == 'W' && line[ 3 ] == 'N' &&
//				line[ 4 ] == 'P' && line[ 5 ] == 'C' && line[ 6 ] == 'E' && line[ 7 ] == 'N' )
//			{
//				n555 = 62;
//				xml = CreatXMLElement( doc , "newWarpMan" );
//				root->LinkEndChild( xml );
//				continue;
//			}
//			else if ( line[ 0 ] == '\\' && line[ 1 ] == 'n' )
//			{
//				n555 = 63;
//				xml = CreatXMLElement( doc , "unknow" );
//				root->LinkEndChild( xml );
//				continue;
//			}
//			else if ( line[ 0 ] == 'F' && line[ 1 ] == 'R' && line[ 2 ] == 'E' && line[ 3 ] == 'E' &&
//				line[ 4 ] == 'M' && line[ 5 ] == 'O' && line[ 6 ] == 'R' && line[ 7 ] == 'E' )
//			{
//				n555 = 64;
//				xml = CreatXMLElement( doc , "freeMore" );
//				root->LinkEndChild( xml );
//				continue;
//			}
//			else if ( line[ 0 ] == 'L' && line[ 1 ] == 'I' && line[ 2 ] == 'M' && line[ 3 ] == 'I' &&
//				line[ 4 ] == 'T' && line[ 5 ] == 'S' && line[ 6 ] == 'H' && line[ 7 ] == 'O' )
//			{
//				n555 = 65;
//				xml = CreatXMLElement( doc , "limitShop" );
//				root->LinkEndChild( xml );
//				continue;
//			}
//			else if ( line[ 0 ] == 'E' && line[ 1 ] == 'V' && line[ 2 ] == 'E' && line[ 3 ] == 'N' &&
//				line[ 4 ] == 'T' )
//			{
//				n555 = 66;
//				xml = CreatXMLElement( doc , "limitShop" );
//				root->LinkEndChild( xml );
//				continue;
//			}
//
//			else if ( line[ 0 ] == 'S' && getStringFromIndexWithDelim(line, "TART_MSG:", 2, token, sizeof(token) ) )
//			{
//				n555 = 70;
//				xml = CreatXMLElement( doc , "run" );
//				root->LinkEndChild( xml );
//				xml->SetAttribute( "process" , atoi( token ) );
//				continue;
//			}
//			else if ( line[ 0 ] == 'W' && getStringFromIndexWithDelim(line, "ARP:", 2, token, sizeof(token) ) )
//			{
//				// family
//				n555 = 80;
//				xml = CreatXMLElement( doc , "family" );
//				root->LinkEndChild( xml );
//
//				continue;
//			}
//			else if ( line[ 0 ] == 'W' && getStringFromIndexWithDelim(line, "ARP1:", 2, token, sizeof(token) ) )
//			{
//				// family
//				n555 = 80;
//				xml = CreatXMLElement( doc , "family" );
//				root->LinkEndChild( xml );
//
//				continue;
//			}
//			else if ( line[ 0 ] == 'I' && getStringFromIndexWithDelim(line, "D:", 2, token, sizeof(token) ) )
//			{
//				// family
//				n555 = 81;
//				xml = CreatXMLElement( doc , "family" );
//				root->LinkEndChild( xml );
//
//				continue;
//			}
//			else if ( line[ 0 ] == 'i' && getStringFromIndexWithDelim(line, "d:", 2, token, sizeof(token) ) )
//			{
//				// family
//				n555 = 81;
//				xml = CreatXMLElement( doc , "family" );
//				root->LinkEndChild( xml );
//
//				continue;
//			}
//			else if ( line[ 0 ] == 'P' && getStringFromIndexWithDelim(line, "ETSKILL:", 2, token, sizeof(token) ) )
//			{
//				n555 = 90;
//				xml = CreatXMLElement( doc , "petSkill" );
//				root->LinkEndChild( xml );
//
//				continue;
//			}
//			else if ( line[ 0 ] == 'M' && getStringFromIndexWithDelim(line, "ainMsg:", 2, token, sizeof(token) ) )
//			{
//				n555 = 91;
//				xml = CreatXMLElement( doc , "petSkill" );
//				root->LinkEndChild( xml );
//
//				continue;
//			}
//			else if ( line[ 0 ] == 'M' && getStringFromIndexWithDelim(line, "IC:", 2, token, sizeof(token) ) )
//			{
//				n555 = 92;
//				xml = CreatXMLElement( doc , "petSkill" );
//				root->LinkEndChild( xml );
//
//				continue;
//			}
//			else if ( line[ 0 ] == 'c' && getStringFromIndexWithDelim(line, "ost:", 2, token, sizeof(token) ) )
//			{
//				n555 = 93;
//				xml = CreatXMLElement( doc , "petSkill" );
//				root->LinkEndChild( xml );
//
//				continue;
//			}
//			else if ( line[ 0 ] == 'n' && getStringFromIndexWithDelim(line, "omal_rate:", 2, token, sizeof(token) ) )
//			{
//				n555 = 93;
//				xml = CreatXMLElement( doc , "petSkill" );
//				root->LinkEndChild( xml );
//
//				continue;
//			}
//			else if ( line[ 0 ] == 's' && getStringFromIndexWithDelim(line, "kill_rate:", 2, token, sizeof(token) ) )
//			{
//				n555 = 93;
//				xml = CreatXMLElement( doc , "petSkill" );
//				root->LinkEndChild( xml );
//
//				continue;
//			}
//			else if ( line[ 0 ] == 'T' && getStringFromIndexWithDelim(line, "ype:", 2, token, sizeof(token) ) )
//			{
//				n555 = 93;
//				xml = CreatXMLElement( doc , "petSkill" );
//				root->LinkEndChild( xml );
//
//				continue;
//			}
//			else if ( line[ 0 ] == 'm' && getStringFromIndexWithDelim(line, "ain_msg:", 2, token, sizeof(token) ) )
//			{
//				n555 = 93;
//				xml = CreatXMLElement( doc , "petSkill" );
//				root->LinkEndChild( xml );
//
//				continue;
//			}
//			else if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "omalMsg:", 2, token, sizeof(token) ) )
//			{
//				n555 = 93;
//				xml = CreatXMLElement( doc , "petSkill" );
//				root->LinkEndChild( xml );
//
//				continue;
//			}
//			else if ( line[ 0 ] == 'S' && getStringFromIndexWithDelim(line, "tartMsg:", 2, token, sizeof(token) ) )
//			{
//				n555 = 93;
//				xml = CreatXMLElement( doc , "petSkill" );
//				root->LinkEndChild( xml );
//
//				continue;
//			}
//			else if ( line[ 0 ] == 'p' && getStringFromIndexWithDelim(line, "et_skill:", 2, token, sizeof(token) ) )
//			{
//				n555 = 93;
//				xml = CreatXMLElement( doc , "petSkill" );
//				root->LinkEndChild( xml );
//
//				continue;
//			}
//			else if ( line[ 0 ] == 'T' && getStringFromIndexWithDelim(line, "ALKEVENT", 2, token, sizeof(token) ) )
//			{
//				n555 = 93;
//				xml = CreatXMLElement( doc , "petSkill" );
//				root->LinkEndChild( xml );
//
//				continue;
//			}
//			else if ( line[ 0 ] == 's' && getStringFromIndexWithDelim(line, "tart_msg:", 2, token, sizeof(token) ) )
//			{
//				n555 = 93;
//				xml = CreatXMLElement( doc , "petSkill" );
//				root->LinkEndChild( xml );
//
//				continue;
//			}
//			else if ( line[ 0 ] == 'S' && getStringFromIndexWithDelim(line, "tone:", 2, token, sizeof(token) ) )
//			{
//				n555 = 93;
//				xml = CreatXMLElement( doc , "petSkill" );
//				root->LinkEndChild( xml );
//
//				continue;
//			}
//			else if ( line[ 0 ] == 'E' && getStringFromIndexWithDelim(line, "ventNo:", 2, token, sizeof(token)) )
//			{
//				xml = CreatXMLElement( doc , "event" );
//				root->LinkEndChild( xml );
//				xml->SetAttribute( "No" , token );
//				continue;
//			}
//			else if ( line[ 0 ] != '\0' && !xml )
//			{
//				n555 = 4;
//				assert( 0 );
//			}
//		}
//
//		if ( !xml )
//		{
//			continue;
//		}
//
//		if ( n555 == 10 )
//		{
//
//		}
//		else if ( n555 == 999 )
//		{
//			if ( line[ 0 ] == ' ' )
//			{
//
//			}
//			else if ( line[ 0 ] == 'E' && getStringFromIndexWithDelim(line, "ventNo:", 2, token, sizeof(token)) )
//			{
//				xml = CreatXMLElement( doc , "event" );
//				root->LinkEndChild( xml );
//				xml->SetAttribute( "No" , token );
//				continue;
//			}
//			else if ( line[ 0 ] == 'T' && getStringFromIndexWithDelim(line, "YPE:", 2, token, sizeof(token)) )
//			{
//				if ( token[ 0 ] == 'A' && token[ 1 ] == 'C' )
//				{
//					xml->SetAttribute( "type" , 1 );
//				}
//				else if ( token[ 0 ] == 'M' && token[ 1 ] == 'E' )
//				{
//					xml->SetAttribute( "type" , 2 );
//				}
//				else if ( token[ 0 ] == 'R' && token[ 1 ] == 'E' && token[ 2 ] == 'Q' )
//				{
//					xml->SetAttribute( "type" , 3 );
//				}
//				else if ( token[ 0 ] == 'C' && token[ 1 ] == 'L' && token[ 2 ] == 'E' )
//				{
//					xml->SetAttribute( "type" , 4 );
//				}
//				else
//				{
//					assert( 0 );
//				}
//				continue;
//			}
//			else if ( line[ 0 ] == 'A' && getStringFromIndexWithDelim(line, "cceptMsg:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "acceptMsg0" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'A' && getStringFromIndexWithDelim(line, "cceptMsg1:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "acceptMsg1" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'A' && getStringFromIndexWithDelim(line, "cceptMsg2:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "acceptMsg2" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'A' && getStringFromIndexWithDelim(line, "cceptMsg3:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "acceptMsg3" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'A' && getStringFromIndexWithDelim(line, "cceptMsg4:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "acceptMsg4" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'A' && getStringFromIndexWithDelim(line, "cceptMsg5:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "acceptMsg5" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'A' && getStringFromIndexWithDelim(line, "cceptMsg6:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "acceptMsg6" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'A' && getStringFromIndexWithDelim(line, "cceptMsg7:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "acceptMsg7" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'A' && getStringFromIndexWithDelim(line, "cceptMsg8:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "acceptMsg8" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'A' && getStringFromIndexWithDelim(line, "cceptMsg9:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "acceptMsg9" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'A' && getStringFromIndexWithDelim(line, "cceptMsg10:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "acceptMsg10" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'A' && getStringFromIndexWithDelim(line, "cceptMsg11:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "acceptMsg11" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'T' && getStringFromIndexWithDelim(line, "hanksMsg:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "thanksMsg0" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'T' && getStringFromIndexWithDelim(line, "hanksMsg1:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "thanksMsg1" ,stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'T' && getStringFromIndexWithDelim(line, "hanksMsg2:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "thanksMsg2" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'T' && getStringFromIndexWithDelim(line, "hanksMsg3:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "thanksMsg3" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'T' && getStringFromIndexWithDelim(line, "hanksMsg4:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "thanksMsg4" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'T' && getStringFromIndexWithDelim(line, "hanksMsg5:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "thanksMsg5" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'T' && getStringFromIndexWithDelim(line, "hanksMsg6:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "thanksMsg6" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'I' && getStringFromIndexWithDelim(line, "temFullMsg:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "itemFullMsg" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'S' && getStringFromIndexWithDelim(line, "toneLessMsg:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "stoneLessMsg" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "omalMsg:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "normalMsg" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "omalWindowMsg:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "normalWinMsg0" , stringMap[ str ]  );
//			}
//			else if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "omalWindowMsg1:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "normalWinMsg1" , stringMap[ str ]  );
//			}
//			else if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "omalWindowMsg2:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "normalWinMsg2" , stringMap[ str ]  );
//			}
//			else if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "omalWindowMsg3:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "normalWinMsg3" , stringMap[ str ]  );
//			}
//			else if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "omalWindowMsg4:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "normalWinMsg4" , stringMap[ str ]  );
//			}
//			else if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "omalWindowMsg5:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "normalWinMsg5" , stringMap[ str ]  );
//			}
//			else if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "omalWindowMsg6:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "normalWinMsg6" , stringMap[ str ]  );
//			}
//			else if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "omalWindowMsg7:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "normalWinMsg7" , stringMap[ str ]  );
//			}
//			else if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "omalWindowMsg8:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "normalWinMsg8" , stringMap[ str ]  );
//			}
//			else if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "omalWindowMsg9:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "normalWinMsg9" , stringMap[ str ]  );
//			}
//			else if ( line[ 0 ] == 'R' && getStringFromIndexWithDelim(line, "equestMsg:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "requestMsg0" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'R' && getStringFromIndexWithDelim(line, "equestMsg1:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "requestMsg1" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'R' && getStringFromIndexWithDelim(line, "equestMsg2:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "requestMsg2" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'R' && getStringFromIndexWithDelim(line, "equestMsg3:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "requestMsg3" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'R' && getStringFromIndexWithDelim(line, "equestMsg4:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "requestMsg4" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'R' && getStringFromIndexWithDelim(line, "equestMsg5:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "requestMsg5" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'R' && getStringFromIndexWithDelim(line, "equestMsg6:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "requestMsg6" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'R' && getStringFromIndexWithDelim(line, "equestMsg7:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "requestMsg7" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'S' && getStringFromIndexWithDelim(line, "toneFullMsg:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "stoneFullMsg" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'P' && getStringFromIndexWithDelim(line, "etFullMsg:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "petFullMsg" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'S' && getStringFromIndexWithDelim(line, "topMsg:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "stopMsg" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'E' && getStringFromIndexWithDelim(line, "ndStopMsg:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "endStopMsg" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "oStopMsg:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "noStopMsg" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'C' && getStringFromIndexWithDelim(line, "leanMainMsg:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "cleanMainMsg" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'C' && getStringFromIndexWithDelim(line, "leanFlgMsg:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "cleanFlagMsg" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'P' && getStringFromIndexWithDelim(line, "et_Name:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "petName" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'E' && getStringFromIndexWithDelim(line, "ndSetFlg:", 2, token, sizeof(token)) )
//			{
//				xml->SetAttribute( "endFlag" , token );
//			}
//			else if ( line[ 0 ] == 'G' && getStringFromIndexWithDelim(line, "etStone:", 2, token, sizeof(token)) )
//			{
//				xml->SetAttribute( "getStone" , token );
//			}
//			else if ( line[ 0 ] == 'E' && line[ 1 ] == 'v' && line[ 2 ] == 'e' && line[ 3 ] == 'n'  && line[ 4 ] == 't' 
//				&& line[ 5 ] == 'E'  && line[ 6 ] == 'n' )
//			{
//				//xml->SetAttribute( "normalMsg" , token );
//			}
//			else if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "pcWarp:", 2, token, sizeof(token)) )
//			{
//				char	token1[128];
//
//				bool b = true;
//				int n = 1;
//				while ( b || getStringFromIndexWithDelim(token, ",", n, token1, 128 ) )
//				{
//					if ( !getStringFromIndexWithDelim(token, ",", n, token1, 128 ) )
//					{
//						strcpy( token1 , token );
//					}
//
//					char token2[ 128 ];
//					getStringFromIndexWithDelim(token1, ".", 1, token2, 128 );
//					int map = atoi( token2 );
//					getStringFromIndexWithDelim(token1, ".", 2, token2, 128 );
//					int x = atoi( token2 );
//					getStringFromIndexWithDelim(token1, ".", 3, token2, 128 );
//					int y = atoi( token2 );
//
//					xmlElement* xml1 = CreatXMLElement( doc , "warp" );
//					xml->LinkEndChild( xml1 );
//					xml1->SetAttribute( "mapID" , map );
//					xml1->SetAttribute( "mapID" , x );
//					xml1->SetAttribute( "mapID" , y );
//
//					b = false;
//					n++;
//				}
//			}
//			else if ( line[ 0 ] == 'G' && getStringFromIndexWithDelim(line, "etItem:", 2, token, sizeof(token)) )
//			{
//				char	token1[128];
//
//				bool b = true;
//				int n = 1;
//				while ( b || getStringFromIndexWithDelim(token, ",", n, token1, 128 ) )
//				{
//					if ( !getStringFromIndexWithDelim(token, ",", n, token1, 128 ) )
//					{
//						strcpy( token1 , token );
//					}
//
//					char buff[ 32 ];
//					sprintf( buff , "getItem%d" , n - 1 );
//					xml->SetAttribute( buff , atoi( token1 ) );
//
//					b = false;
//					n++;
//				}
//			}
//			else if ( line[ 0 ] == 'D' && getStringFromIndexWithDelim(line, "elItem:", 2, token, sizeof(token)) )
//			{
//				char	token1[128];
//
//				bool b = true;
//				int n = 1;
//				while ( b || getStringFromIndexWithDelim(token, ",", n, token1, 128 ) )
//				{
//					if ( !getStringFromIndexWithDelim(token, ",", n, token1, 128 ) )
//					{
//						strcpy( token1 , token );
//					}
//
//					char buff[ 32 ];
//					sprintf( buff , "delItem%d" , n - 1 );
//					xml->SetAttribute( buff , atoi( token1 ) );
//
//					b = false;
//					n++;
//				}
//			}
//			else if ( line[ 0 ] == 'D' && getStringFromIndexWithDelim(line, "elStone:", 2, token, sizeof(token)) )
//			{
//				//DelStone:LV*3
//				char	token1[128];
//				if ( token[ 0 ] == 'L' && getStringFromIndexWithDelim( token, "V*", 2, token1, sizeof(token1)) )
//				{
//					xml->SetAttribute( "delStoneLV" , atoi( token1 ) );
//				}
//				else
//				{
//					xml->SetAttribute( "delStone" , atoi( token ) );
//				}
//			}
//			else if ( line[ 0 ] == 'D' && getStringFromIndexWithDelim( line , "elPet:PET>0-" , 2 , token, sizeof(token)) )
//			{
//				char	token1[128];
//
//				getStringFromIndexWithDelim( token, "*", 1, token1, sizeof(token1));
//				xml->SetAttribute( "delPet" , atoi( token1 ) );
//				getStringFromIndexWithDelim( token, "*", 2, token1, sizeof(token1));
//				xml->SetAttribute( "delPetNum" , atoi( token1 ) );
//			}
//			else if ( line[ 0 ] == 'D' && getStringFromIndexWithDelim( line , "elPet:PET=1-" , 2 , token, sizeof(token)) )
//			{
//				char	token1[128];
//
//				xml->SetAttribute( "delPetLV" , 1 );
//
//				getStringFromIndexWithDelim( token, "*", 1, token1, sizeof(token1));
//				xml->SetAttribute( "delPet" , atoi( token1 ) );
//				getStringFromIndexWithDelim( token, "*", 2, token1, sizeof(token1));
//				xml->SetAttribute( "delPetNum" , atoi( token1 ) );
//			}
//			else if ( line[ 0 ] == 'D' && getStringFromIndexWithDelim( line , "elPet:PET=30-" , 2 , token, sizeof(token)) )
//			{
//				char	token1[128];
//
//				xml->SetAttribute( "delPetLV" , 30 );
//
//				getStringFromIndexWithDelim( token, "*", 1, token1, sizeof(token1));
//				xml->SetAttribute( "delPet" , atoi( token1 ) );
//				getStringFromIndexWithDelim( token, "*", 2, token1, sizeof(token1));
//				xml->SetAttribute( "delPetNum" , atoi( token1 ) );
//			}
//			else if ( line[ 0 ] == 'D' && getStringFromIndexWithDelim( line , "elPet:PET=33-" , 2 , token, sizeof(token)) )
//			{
//				char	token1[128];
//
//				xml->SetAttribute( "delPetLV" , 33 );
//
//				getStringFromIndexWithDelim( token, "*", 1, token1, sizeof(token1));
//				xml->SetAttribute( "delPet" , atoi( token1 ) );
//				getStringFromIndexWithDelim( token, "*", 2, token1, sizeof(token1));
//				xml->SetAttribute( "delPetNum" , atoi( token1 ) );
//			}
//			else if ( line[ 0 ] == 'D' && getStringFromIndexWithDelim( line , "elPet:EVPET>0-" , 2 , token, sizeof(token)) )
//			{
//				xml->SetAttribute( "delPetMinLV" , 1 );
//				xml->SetAttribute( "delPet" , atoi( token ) );
//			}
//			else if ( line[ 0 ] == 'D' && getStringFromIndexWithDelim( line , "elPet:PET>81" , 2 , token, sizeof(token)) )
//			{
//				char	token1[128];
//
//				xml->SetAttribute( "delPetMinLV" , 81 );
//
//				getStringFromIndexWithDelim( token, "*", 1, token1, sizeof(token1));
//				xml->SetAttribute( "delPet" , atoi( token1 ) );
//				getStringFromIndexWithDelim( token, "*", 2, token1, sizeof(token1));
//				xml->SetAttribute( "delPetNum" , atoi( token1 ) );
//			}
//			else if ( line[ 0 ] == 'D' && getStringFromIndexWithDelim( line , "elPet:PET>49" , 2 , token, sizeof(token)) )
//			{
//				xml->SetAttribute( "delPetMinLV" , 49 );
//				xml->SetAttribute( "delPet" , atoi( token ) );
//				xml->SetAttribute( "delPetNum" , 1 );
//			}
//			else if ( line[ 0 ] == 'D' && getStringFromIndexWithDelim( line , "elPet:PET>59" , 2 , token, sizeof(token)) )
//			{
//				xml->SetAttribute( "delPetMinLV" , 59 );
//				xml->SetAttribute( "delPet" , atoi( token ) );
//				xml->SetAttribute( "delPetNum" , 1 );
//			}
//			else if ( line[ 0 ] == 'D' && getStringFromIndexWithDelim( line , "elPet:PET>14" , 2 , token, sizeof(token)) )
//			{
//				xml->SetAttribute( "delPetMinLV" , 14 );
//				xml->SetAttribute( "delPet" , atoi( token ) );
//				xml->SetAttribute( "delPetNum" , 1 );
//			}
//			else if ( line[ 0 ] == 'D' && getStringFromIndexWithDelim( line , "elPet:PET>99" , 2 , token, sizeof(token)) )
//			{
//				xml->SetAttribute( "delPetMinLV" , 99 );
//				xml->SetAttribute( "delPet" , atoi( token ) );
//				xml->SetAttribute( "delPetNum" , 1 );
//			}
//			else if ( line[ 0 ] == 'D' && getStringFromIndexWithDelim( line , "elPet:PET" , 2 , token, sizeof(token)) )
//			{
//			}
//			else if ( line[ 0 ] == 'G' && getStringFromIndexWithDelim( line , "etPet:" , 2 , token, sizeof(token)) )
//			{
//				xml->SetAttribute( "getPet" , atoi( token ) );
//			}
//			else if ( line[ 0 ] == 'G' && getStringFromIndexWithDelim( line , "etRandItem:" , 2 , token , sizeof(token) ) )
//			{
//				char token1[ 512 ];
//
//				int nn = 1;
//				while ( getStringFromIndexWithDelim( token , "etRandItem:" , nn , token1 , 512 ) )
//				{
//					char buff[ 32 ];
//					sprintf( buff , "getRandItem%d" , nn - 1 ); nn++;
//					xml->SetAttribute( buff , atoi( token1 ) );
//				}
//			}
//			else if ( line[ 0 ] == 'K' && getStringFromIndexWithDelim( line , "eyWord:" , 2 , token , sizeof(token) ) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "keyWord" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'M' && getStringFromIndexWithDelim( line , "ISSIONOVER:" , 2 , token , sizeof(token) ) )
//			{
//				xml->SetAttribute( "missionOver" , atoi( token ) );
//			}
//			else if ( line[ 0 ] == 'B' && line[ 1 ] == 'r' && line[ 2 ] == 'e' && line[ 3 ] == 'a' && line[ 4 ] == 'k' )
//			{
//				
//			}
//			else if ( line[ 0 ] == 'C' && getStringFromIndexWithDelim( line , "leanFlg:" , 2 , token , sizeof(token) ) )
//			{
//				xml->SetAttribute( "cleanFlag" , atoi( token ) );
//			}
//			else if ( line[ 0 ] == 'C' && getStringFromIndexWithDelim( line , "harm:" , 2 , token , sizeof(token) ) )
//			{
//				xml->SetAttribute( "charm" , atoi( token ) );
//			}
//			else if ( line[ 0 ] == 'P' && getStringFromIndexWithDelim( line , "ROFESSION:" , 2 , token , sizeof(token) ) )
//			{
//				xml->SetAttribute( "profession" , atoi( token ) );
//			}
//			else if ( line[ 0 ] == 'E' && getStringFromIndexWithDelim(line, "VENT:", 2, token, sizeof(token)) )
//			{
//				char	token1[256];
//				char	token2[256];
//
//				bool b = true;
//				int dr = 0;
//				int item = 0;
//				int item1 = 0;
//				int n = 1;
//
//				while ( b || getStringFromIndexWithDelim(token, ",", n, token1, 256 ) )
//				{
//					if ( b && !getStringFromIndexWithDelim(token, ",", n, token1, 256 ) && !getStringFromIndexWithDelim(token, "&", n, token1, 256 ) )
//					{
//						strcpy( token1 , token );
//					}
//					else
//					{
//						if ( strcmp( token , token1 ) == 0 )
//						{
//							getStringFromIndexWithDelim(token, "&", n, token1, 256 );
//						}
//					}
//
//					b = false;
//
//					if ( token1[ 0 ] == 'L' && getStringFromIndexWithDelim( token1 , "V<" , 2 , token2 , 256 ) )
//					{
//						xml->SetAttribute( "lvMax" , atoi( token2 ) );
//					}
//					else if ( token1[ 0 ] == 'L' && getStringFromIndexWithDelim( token1 , "V>" , 2 , token2 , 256 ) )
//					{
//						xml->SetAttribute( "lvMin" , atoi( token2 ) );
//					}
//					else if ( token1[ 0 ] == 'D' && getStringFromIndexWithDelim( token1 , "R<" , 2 , token2 , 256 ) )
//					{
//						xml->SetAttribute( "drMax" , atoi( token2 ) );
//					}
//					else if ( token1[ 0 ] == 'D' && getStringFromIndexWithDelim( token1 , "R=" , 2 , token2 , 256 ) )
//					{
//						char buff[ 32 ];
//						sprintf( buff , "dr%d" , dr ); dr++;
//						xml->SetAttribute( buff , atoi( token2 ) );
//					}
//					else if ( token1[ 0 ] == 'I' && getStringFromIndexWithDelim( token1 , "TEM=" , 2 , token2 , 256 ) )
//					{
//						char buff[ 32 ];
//						sprintf( buff , "item%d" , item ); item++;
//						xml->SetAttribute( buff , atoi( token2 ) );
//					}
//					else if ( token1[ 0 ] == 'E' && getStringFromIndexWithDelim( token1 , "NDEV=" , 2 , token2 , 256 ) )
//					{
//						xml->SetAttribute( "endEvent" , atoi( token2 ) );
//					}
//					else if ( token1[ 0 ] == 'E' && getStringFromIndexWithDelim( token1 , "NDEV!=" , 2 , token2 , 256 ) )
//					{
//						xml->SetAttribute( "endEventNot" , atoi( token2 ) );
//					}
//					else if ( token1[ 0 ] == 'N' && getStringFromIndexWithDelim( token1 , "OWEV=" , 2 , token2 , 256 ) )
//					{
//						xml->SetAttribute( "nowEvent" , atoi( token2 ) );
//					}
//					else if ( token1[ 0 ] == 'N' && getStringFromIndexWithDelim( token1 , "OWEV!=" , 2 , token2 , 256 ) )
//					{
//						xml->SetAttribute( "nowEventNot" , atoi( token2 ) );
//					}
//					else if ( token1[ 0 ] == 'N' && getStringFromIndexWithDelim( token1 , "OWEV=" , 2 , token2 , 256 ) )
//					{
//						xml->SetAttribute( "nowEvent" , atoi( token2 ) );
//					}
//					else if ( token1[ 0 ] == 'I' && getStringFromIndexWithDelim( token1 , "TEM!=" , 2 , token2 , 256 ) )
//					{
//						char buff[ 32 ];
//						sprintf( buff , "itemNot%d" , item1 ); item1++;
//						xml->SetAttribute( buff , atoi( token2 ) );
//					}
//					else if ( token1[ 0 ] == 'P' && getStringFromIndexWithDelim( token1 , "PET>0-" , 2 , token2 , 256 ) )
//					{
//						char	token3[128];
//						
//						getStringFromIndexWithDelim( token2, "*", 1, token3, sizeof(token3));
//						xml->SetAttribute( "pet" , atoi( token3 ) );
//						getStringFromIndexWithDelim( token2, "*", 2, token3, sizeof(token3));
//						xml->SetAttribute( "petNum" , atoi( token3 ) );
//					}
//					else if ( token1[ 0 ] == 'E' && getStringFromIndexWithDelim( token1 , "VPET>0-" , 2 , token2 , 256 ) )
//					{
//						xml->SetAttribute( "pet" , atoi( token2 ) );
//					}
//					else if ( token1[ 0 ] == 'H' && getStringFromIndexWithDelim( token1 , "ERO_I_NOW=" , 2 , token2 , 256 ) )
//					{
//						xml->SetAttribute( "heroNow" , atoi( token2 ) );
//					}
//					else if ( token1[ 0 ] == 'H' && getStringFromIndexWithDelim( token1 , "ERO_OUT=" , 2 , token2 , 256 ) )
//					{
//						xml->SetAttribute( "heroOut" , atoi( token2 ) );
//					}
//					else if ( token1[ 0 ] == 'H' && getStringFromIndexWithDelim( token1 , "ERO_OVER=" , 2 , token2 , 256 ) )
//					{
//						xml->SetAttribute( "heroOver" , atoi( token2 ) );
//					}
//					else if ( token1[ 0 ] == 'P' && getStringFromIndexWithDelim( token1 , "PET>14-" , 2 , token2 , 256 ) )
//					{
//						char	token3[128];
//
//						xml->SetAttribute( "petMinLV" , 14 );
//						xml->SetAttribute( "pet" , atoi( token2 ) );
//					}
//					else if ( token1[ 0 ] == 'C' && getStringFromIndexWithDelim( token1 , "LASS" , 2 , token2 , 256 ) )
//					{
//					}
//					else if (  token1[ 0 ] != '\0' )
//					{
//						assert( 0 );
//					}
//
//					n++;
//				}
//				
//				continue;
//			}
//			else if ( line[ 0 ] != '\0' )
//			{
//				assert( 0 );
//			}
//
//		}
//		else if ( n555 == 1 )
//		{
//			if ( getStringFromIndexWithDelim(line, "skbattlemsg:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "askBattleMsg0" , stringMap[ str ] );
//			}
//			else if ( getStringFromIndexWithDelim(line, "skbattlemsg1:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "askBattleMsg1" , stringMap[ str ]  );
//			}
//			else if ( getStringFromIndexWithDelim(line, "skbattlemsg2:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "askBattleMsg2" , stringMap[ str ] );
//			}
//			else if ( getStringFromIndexWithDelim(line, "skbattlemsg3:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "askBattleMsg3" , stringMap[ str ] );
//			}
//			else if ( getStringFromIndexWithDelim(line, "skbattlemsg4:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "askBattleMsg4" , stringMap[ str ] );
//			}
//			else if ( getStringFromIndexWithDelim(line, "skbattlemsg5:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "askBattleMsg5" , stringMap[ str ] );
//			}
//			else if ( getStringFromIndexWithDelim(line, "skbattlemsg6:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "askBattleMsg6" , stringMap[ str ] );
//			}
//			else if ( getStringFromIndexWithDelim(line, "tar tmsg:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "startMsg" , stringMap[ str ] );
//			}
//			else if ( getStringFromIndexWithDelim(line, "tartmsg:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "startMsg" , stringMap[ str ] );
//			}
//			else if ( getStringFromIndexWithDelim(line, "tart msg:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "startMsg" , stringMap[ str ] );
//			}
//			else if ( getStringFromIndexWithDelim(line, "ieact:", 2, token, sizeof(token)) )
//			{
//				xml->SetAttribute( "dieAct" , atoi( token ) );
//			}
//			else if ( getStringFromIndexWithDelim(line, "arpfl:", 2, token, sizeof(token)) )
//			{
//				xml->SetAttribute( "warpMap" , atoi( token ) );
//			}
//			else if ( getStringFromIndexWithDelim(line, "arpx:", 2, token, sizeof(token)) )
//			{
//				xml->SetAttribute( "warpX" , atoi( token ) );
//			}
//			else if ( getStringFromIndexWithDelim(line, "arpy:", 2, token, sizeof(token)) )
//			{
//				xml->SetAttribute( "warpY" , atoi( token ) );
//			}
//			else if ( getStringFromIndexWithDelim(line, "nd msg:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "endMsg" , stringMap[ str ] );
//			}
//			else if ( getStringFromIndexWithDelim(line, "eniedmsg:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "deniedMsg" , stringMap[ str ] );
//			}
//			else if ( getStringFromIndexWithDelim(line, "nebattle:", 2, token, sizeof(token)) )
//			{
//				xml->SetAttribute( "oneBattle" , atoi( token ) );
//			}
//			else if ( getStringFromIndexWithDelim(line, "nemyno:", 2, token, sizeof(token)) )
//			{
//				strcpy( line , token );
//
//				xmlElement* xml1 = CreatXMLElement( doc , "enemy" );
//				xml->LinkEndChild( xml1 );
//
//				int n = 1;
//				while ( getStringFromIndexWithDelim( line , ",", n, token, sizeof(token)) )
//				{
//					char buffer[ 32 ];
//					sprintf( buffer , "e%d" , n - 1 );
//					xml1->SetAttribute( buffer , atoi( token ) );
//					n++;
//				}
//
//			}
//			else if ( getStringFromIndexWithDelim(line, "nemypetno:", 2, token, sizeof(token)) )
//			{
//				strcpy( line , token );
//
//				xmlElement* xml1 = CreatXMLElement( doc , "enemyPet" );
//				xml->LinkEndChild( xml1 );
//
//				int n = 1;
//				while ( getStringFromIndexWithDelim( line , ",", n, token, sizeof(token)) )
//				{
//					char buffer[ 32 ];
//					sprintf( buffer , "e%d" , n - 1 );
//					xml1->SetAttribute( buffer , atoi( token ) );
//					n++;
//				}
//
//			}
//			else if ( line[ 0 ] == 't' && getStringFromIndexWithDelim(line, "ime:", 2, token, sizeof(token)) )
//			{
//				xml->SetAttribute( "time" , atoi( token ) );
//			}
//			else if ( line[ 0 ] == 't' && getStringFromIndexWithDelim(line, "ime=", 2, token, sizeof(token)) )
//			{
//				xml->SetAttribute( "time" , atoi( token ) );
//			}
//			else if ( line[ 0 ] == 'a' && getStringFromIndexWithDelim(line, "lreadymsg:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "alreadyMsg" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'e' && getStringFromIndexWithDelim(line, "ndmsg:", 2, token, sizeof(token)) )
//			{
//				wstring str = AnsitoUnicode( token );
//				if ( stringMap.find( str ) == stringMap.end() )
//				{
//					stringMap[ str ] = stringMap.size();
//				}
//				xml->SetAttribute( "endMsg" , stringMap[ str ] );
//			}
//			else if ( line[ 0 ] == 'i' && getStringFromIndexWithDelim(line, "tem:", 2, token, sizeof(token)) )
//			{
//				xml->SetAttribute( "item" , atoi( token ) );
//			}
//			else if ( line[ 0 ] == 's' && getStringFromIndexWithDelim(line, "teal:", 2, token, sizeof(token)) )
//			{
//				xml->SetAttribute( "steal" , atoi( token ) );
//			}
//			else if ( line[ 0 ] == 'g' && getStringFromIndexWithDelim(line, "ym:", 2, token, sizeof(token)) )
//			{
//				xml->SetAttribute( "gym" , atoi( token ) );
//			}
//			else if ( line[ 0 ] == 'B' && getStringFromIndexWithDelim(line, "_evend:", 2, token, sizeof(token)) )
//			{
//				xml->SetAttribute( "bEventEnd" , atoi( token ) );
//			}
//			else if ( line[ 0 ] == 'B' && getStringFromIndexWithDelim(line, "_evnow:", 2, token, sizeof(token)) )
//			{
//				xml->SetAttribute( "bEventNow" , atoi( token ) );
//			}
//			else if ( line[ 0 ] == 's' && getStringFromIndexWithDelim(line, "ktype:", 2, token, sizeof(token)) )
//			{
//				xml->SetAttribute( "skType" , atoi( token ) );
//			}
//			else if ( line[ 0 ] == 'h' && getStringFromIndexWithDelim(line, "erobattlefield:", 2, token, sizeof(token)) )
//			{
//				xml->SetAttribute( "heroBattleField" , atoi( token ) );
//			}
//			else if ( line[ 0 ] == 'O' && getStringFromIndexWithDelim(line, "VER", 2, token, sizeof(token)) )
//			{
//				//xml->SetAttribute( "heroBattleField" , atoi( token ) );
//			}
//			else if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "EWEVENT2:", 2, token, sizeof(token)) )
//			{
//				//xml->SetAttribute( "heroBattleField" , atoi( token ) );
//			}
//			else if ( line[ 0 ] == 'F' && getStringFromIndexWithDelim(line, "REE:", 2, token, sizeof(token)) )
//			{
//				strcpy( line , token );
//
//				xmlElement* xml1 = CreatXMLElement( doc , "free" );
//				xml->LinkEndChild( xml1 );
//
//				if ( getStringFromIndexWithDelim(line, "&" , 2, token, sizeof(token)) )
//				{
//					char line0[ 320 ];
//					strcpy( line0 , token );
//
//					int n = 1;
//					int n1 = 0;
//					int n2 = 0;
//					int n3 = 0;
//					int n4 = 0;
//					int n5 = 0;
//					int n6 = 0;
//
//					while ( getStringFromIndexWithDelim( line , "&", n, token, sizeof(token)) )
//					{
//						if ( line0[ 0 ] == 'N' && getStringFromIndexWithDelim( line0, "OWEV=", 2, token, sizeof(token)) )
//						{
//							char buffer[ 32 ];
//							sprintf( buffer , "nowEvent%d" , n1 ); n1++;
//							xml1->SetAttribute( buffer , atoi( token ) );
//						}
//						else if ( line0[ 0 ] == 'E' && getStringFromIndexWithDelim( line0, "NDEV=", 2, token, sizeof(token)) )
//						{
//							char buffer[ 32 ];
//							sprintf( buffer , "endEvent%d" , n2 ); n2++;
//							xml1->SetAttribute( buffer , atoi( token ) );
//						}
//						else if ( line0[ 0 ] == 'E' && getStringFromIndexWithDelim( line0, "NDEV!=", 2, token, sizeof(token)) )
//						{
//							char buffer[ 32 ];
//							sprintf( buffer , "endEventNot%d" , n5 ); n5++;
//							xml1->SetAttribute( buffer , atoi( token ) );
//						}
//						else if ( line0[ 0 ] == 'N' && getStringFromIndexWithDelim( line0, "OWEV!=", 2, token, sizeof(token)) )
//						{
//							char buffer[ 32 ];
//							sprintf( buffer , "nowEventNot%d" , n6 ); n6++;
//							xml1->SetAttribute( buffer , atoi( token ) );
//						}
//						else if ( line0[ 0 ] == 'I' && getStringFromIndexWithDelim( line0, "TEM=", 2, token, sizeof(token)) )
//						{
//							char buffer[ 32 ];
//							sprintf( buffer , "item%d" , n3 ); n3++;
//							xml1->SetAttribute( buffer , atoi( token ) );
//						}
//
//						else if ( line0[ 0 ] == 'T' && getStringFromIndexWithDelim( line0, "RANS>", 2, token, sizeof(token)) )
//						{
//							xml1->SetAttribute( "transMin" , atoi( token ) );
//						}
//						else if ( line0[ 0 ] == 'V' && getStringFromIndexWithDelim( line0, "IP", 2, token, sizeof(token)) )
//						{
//							xml1->SetAttribute( "vip" , atoi( token ) );
//						}
//						else if ( line0[ 0 ] == 'T' && getStringFromIndexWithDelim( line0, "RANS=", 2, token, sizeof(token)) )
//						{
//							xml1->SetAttribute( "trans" , atoi( token ) );
//						}
//						else if ( line0[ 0 ] == 'I' && getStringFromIndexWithDelim( line0, "TEM!=", 2, token, sizeof(token)) )
//						{
//							char buffer[ 32 ];
//							sprintf( buffer , "itemNot%d" , n4 ); n4++;
//							xml1->SetAttribute( buffer , atoi( token ) );
//						}
//						else if ( line0[ 0 ] == 'H' && getStringFromIndexWithDelim( line0, "ERO_I_NOW=", 2, token, sizeof(token)) )
//						{
//							xml1->SetAttribute( "heroNow" , atoi( token ) );
//						}
//
//
//						else
//						{
//							assert( 0 );
//						}
//
//
//						n++;
//					}
//
//				
//
//				}
//				else if ( line[ 0 ] == 'N' && getStringFromIndexWithDelim(line, "OWEV=", 2, token, sizeof(token)) )
//				{
//					xml1->SetAttribute( "nowEvent" , atoi( token ) );
//				}
//				else if ( line[ 0 ] == 'E' && getStringFromIndexWithDelim(line, "NDEV=", 2, token, sizeof(token)) )
//				{
//					xml1->SetAttribute( "endEvent" , atoi( token ) );
//				}
//				else if ( line[ 0 ] == 'L' && getStringFromIndexWithDelim(line, "V>", 2, token, sizeof(token)) )
//				{
//					xml1->SetAttribute( "lvMin" , atoi( token ) );
//				}
//				else if ( line[ 0 ] == 'I' && getStringFromIndexWithDelim(line, "TEM!=", 2, token, sizeof(token)) )
//				{
//					xml1->SetAttribute( "itemNot" , atoi( token ) );
//				}
//				else if ( line[ 0 ] == 'E' && getStringFromIndexWithDelim(line, "NDEV!=", 2, token, sizeof(token)) )
//				{
//					xml1->SetAttribute( "endEventNot" , atoi( token ) );
//				}
//				else 
//				{
//					assert( 0 );
//				}
//
//			}
//			else if ( line[ 0 ] == 'W' && getStringFromIndexWithDelim(line, "ARP:", 2, token, sizeof(token)) )
//			{
//				strcpy( line , token );
//
//				xmlElement* xml1 = CreatXMLElement( doc , "warp" );
//				xml->LinkEndChild( xml1 );
//
//				//5576,28,88;5576,24,86;5576,24,87;5576,28,87;5576,24,88;5576,24,89;5576,24,89;5576,24,86;5576,24,86;5576,24,87
//
//				int n = 1;
//				while ( getStringFromIndexWithDelim( line , ";", n, token, sizeof(token) ) )
//				{
//					char line0[ 320 ];
//					strcpy( line0 , token );
//
//					xmlElement* xml2 = CreatXMLElement( doc , "w" );
//					xml1->LinkEndChild( xml2 );
//
//					getStringFromIndexWithDelim( line0 , ",", 1, token, sizeof(token) );
//					xml2->SetAttribute( "map" , atoi( token ) );
//					getStringFromIndexWithDelim( line0 , ",", 2, token, sizeof(token) );
//					xml2->SetAttribute( "x" , atoi( token ) );
//					getStringFromIndexWithDelim( line0 , ",", 3, token, sizeof(token) );
//					xml2->SetAttribute( "y" , atoi( token ) );
//
//					n++;
//				}
//			}
//			else if ( line[ 0 ] == 'O' && getStringFromIndexWithDelim(line, "VE", 2, token, sizeof(token)) )
//			{
//				continue;
//			}
//			else if ( line[ 0 ] != '\0' )
//			{
//				assert( 0 );
//			}
//		
//		}
//		else
//		{
//			
//		}
//
//		continue;
//		
//		if ( getStringFromIndexWithDelim(line, "elItem:", 2, token, sizeof(token)) )
//		{
//			strcpy( line , token );
//
//			xmlElement* xml1 = CreatXMLElement( doc , "delItem" );
//			xml->LinkEndChild( xml1 );
//
//			int n = 1;
//			while ( getStringFromIndexWithDelim( line , ",", n, token, sizeof(token)) )
//			{
//				char buffer[ 32 ];
//				sprintf( buffer , "i%d" , n - 1 );
//				xml1->SetAttribute( buffer , atoi( token ) );
//				n++;
//			}
//
//		}
//		
//		
//		
//		
//		else if ( line[ 0 ] == 'A' && getStringFromIndexWithDelim(line, "ddItem:", 2, token, sizeof(token)) )
//		{
//			xml->SetAttribute( "addItem" , atoi( token ) );
//		}
//		else if ( line[ 0 ] == 'G' && getStringFromIndexWithDelim(line, "etRandItem:", 2, token, sizeof(token)) )
//		{
//			xml->SetAttribute( "getRandItem" , atoi( token ) );
//		}
//		
//		else if ( line[ 0 ] == 'E' && getStringFromIndexWithDelim(line, "vent_Now:", 2, token, sizeof(token)) )
//		{
//			xml->SetAttribute( "eventNow" , atoi( token ) );
//		}
//		else if ( line[ 0 ] == 'n' && getStringFromIndexWithDelim(line, "owev:", 2, token, sizeof(token)) )
//		{
//			xml->SetAttribute( "nowEvent" , atoi( token ) );
//		}
//		else if ( line[ 0 ] == 'C' && getStringFromIndexWithDelim(line, "HANGEBBI:", 2, token, sizeof(token)) )
//		{
//			//xml->SetAttribute( "changeBBI" , AnsitoUtf8( token ) );
//		}
//		else if ( line[ 0 ] == 'e' && getStringFromIndexWithDelim(line, "ndev:", 2, token, sizeof(token)) )
//		{
//			xml->SetAttribute( "endEvent" , atoi( token ) );
//		}
//		else if ( line[ 0 ] == 'E' && getStringFromIndexWithDelim(line, "vent_End:", 2, token, sizeof(token)) )
//		{
//			xml->SetAttribute( "eventEnd" , atoi( token ) );
//		}
//		else if ( line[ 0 ] == 'E' && getStringFromIndexWithDelim(line, "vClr:", 2, token, sizeof(token)) )
//		{
//			xml->SetAttribute( "eventCtrl" , atoi( token ) );
//		}
//		
//		else if ( line[ 0 ] != '\0' )
//		{
//			assert( 0 );
//		}
		
		listindex++;
	}
	fclose(fp);

	doc->Save( xmlPath.c_str() , true );
	ReleaseXMLDocument( doc );
}


void ReadFiles( string path , string name )
{
	int n = name.find( "create" );
	if ( n > 0 )
	{
		ReadCreate( path , name );
	}
	else if ( (int)name.find( "template" ) > 0 )
	{
		//ReadTemplate( path , name );
	}
	else
	{
		//ReadArg( path , name );
	}

}

void ReadFiles1( string path , string name )
{
	int n = name.find( "create" );
	if ( n > 0 )
	{
		//ReadCreate( path , name );
	}
	else if ( (int)name.find( "template" ) > 0 )
	{
		ReadTemplate1( path , name );
	}
	else
	{
		//ReadArg( path , name );
	}

}

int  fn(const  char *file, const struct stat *sb, int flag)
{
    if ( strstr( file , "DS_Store" ) > 0 )
    {
        return 0;
    }
    
    if( flag == FTW_D )
    {
        
    }
    else
    {
        string file1 = file;
        int nf = file1.find_last_of( '/' );
        string path = file1.substr( 0 , nf + 1 );
        string name = file1.substr( nf + 1 , file1.length() );
        
        int n = name.find( "template" );
        if ( n > 0 )
        {
            ReadTemplate1( path , name );
        }
    }
    
    return 0;
}

int  fn1(const  char *file, const struct stat *sb, int flag)
{
    if ( strstr( file , "DS_Store" ) > 0 )
    {
        return 0;
    }
    
    if( flag == FTW_D )
    {
        
    }
    else
    {
        string file1 = file;
        int nf = file1.find_last_of( '/' );
        string path = file1.substr( 0 , nf + 1 );
        string name = file1.substr( nf + 1 , file1.length() );
        
        int n = name.find( "create" );
        if ( n > 0 )
        {
            ReadCreate( path , name );
        }
    }
    
    return 0;
}



void FindFolder( string folderPath )
{
    
//	_finddata_t FileInfo;
//	string strfind = folderPath + "\\*";
//	long Handle = _findfirst(strfind.c_str(), &FileInfo);
//
//	if (Handle == -1L)
//	{
//		exit(-1);
//	}
//	do{
//		if (FileInfo.attrib & _A_SUBDIR)
//		{
//			if( (strcmp(FileInfo.name,".") != 0 ) &&(strcmp(FileInfo.name,"..") != 0))
//			{
//				string newPath = folderPath + "\\" + FileInfo.name;
//				newPath += "\\";
//				FindFolder( newPath );
//			}
//		}
//		else  
//		{
//			//SaveMap( folderPath.c_str() , FileInfo.name );
//			ReadFiles( folderPath.c_str() , FileInfo.name );
//		}
//	}while (_findnext(Handle, &FileInfo) == 0);
//
//	_findclose(Handle);
}

void FindFolder1( string folderPath )
{
//	_finddata_t FileInfo;
//	string strfind = folderPath + "\\*";
//	long Handle = _findfirst(strfind.c_str(), &FileInfo);
//
//	if (Handle == -1L)
//	{
//
//		exit(-1);
//	}
//	do{
//		if (FileInfo.attrib & _A_SUBDIR)    
//		{
//			if( (strcmp(FileInfo.name,".") != 0 ) &&(strcmp(FileInfo.name,"..") != 0))   
//			{
//				string newPath = folderPath + "\\" + FileInfo.name;
//				newPath += "\\";
//				FindFolder1( newPath );
//			}
//		}
//		else  
//		{
//			//SaveMap( folderPath.c_str() , FileInfo.name );
//			ReadFiles1( folderPath.c_str() , FileInfo.name );
//		}
//	}while (_findnext(Handle, &FileInfo) == 0);
//
//	_findclose(Handle);
}


fvoid		SaveMapWarp()
{
	crtIFileSystem* fileSystem = crtManager::GetFileSystem();
	crtIReadFile* readFile = fileSystem->CreateAndOpenFile( "C:\\work\\shiqicc95\\sss\\gmsv\\data\\map\\mapwarp.txt" );
	char read;
	string strRead;
	string subStr;

	xmlDocument* doc = CreatXMLDocument();
	xmlElement* root = CreatXMLElement( doc , "root" );
	doc->LinkEndChild( root );


	while ( readFile->Read( &read , 1 ) )
	{
		strRead += read;

		if ( read == '\n' )
		{
			int n = strRead.find( ":" );

			if ( n == -1 )
			{
				strRead.clear();
				continue;
			}

			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );


			n = strRead.find( ":" );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			int mapID = atoi( subStr.c_str() );

			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			int x = atoi( subStr.c_str() );


			n = strRead.find( ":" );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			int y = atoi( subStr.c_str() );


			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			int mapID1 = atoi( subStr.c_str() );


			n = strRead.find( "," );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			int x1 = atoi( subStr.c_str() );

			n = strRead.find( ":" );
			strRead[ n ] = '\0';
			subStr = strRead;
			strRead.erase( 0 , n + 1 );
			int y1 = atoi( subStr.c_str() );


			strRead.clear();

			xmlElement* element = CreatXMLElement( doc , "l" );
			root->LinkEndChild( element );

			element->SetAttribute( "m" , mapID );
			element->SetAttribute( "x" , x );
			element->SetAttribute( "y" , y );
			element->SetAttribute( "ml" , mapID1 );
			element->SetAttribute( "xl" , x1 );
			element->SetAttribute( "yl" , y1 );

		}
	}

	doc->Save( "c:\\work\\1.xml" , false );
}



fvoid		SaveBattleMap()
{
	xmlDocument* doc = CreatXMLDocument();
	xmlElement* root = CreatXMLElement( doc , "root" );
	doc->LinkEndChild( root );

	FILE*   file;
	char    line[512];

	int     i, j;
	int     linenum=0;
	int 	BattleMapNo[3], iRet, iWork, iPre[3],iFirst, iLast;

	file = fopen( "C:\\work\\shiqicc95\\sss\\gmsv\\data\\map\\battlemap.txt" , "r" );
	if( file == NULL )
	{
		return;
	}

	BattleMapNo[0] = 0;
	BattleMapNo[1] = 0;
	BattleMapNo[2] = 0;

	xmlElement* battleID;


	while( fgets( line , sizeof( line ) , file ) ){
		char    *p;
		linenum++;

		pohcd( line, " \t" );
		dchop(line, " \t");

		if( line[0] == '#' )continue;
		if( line[0] == '\n' )continue;
		chomp( line );

		if( line[0] == '$' ){
			iRet = sscanf( line+1, "%d %d %d", &iPre[0], &iPre[1], &iPre[2] );
			BattleMapNo[0] = BattleMapNo[1] = BattleMapNo[2] = iPre[0];
			if( iRet < 1 ){
			}
			for( i = 0; i < iRet; i ++ ){
				BattleMapNo[i] = iPre[i];
				if( BattleMapNo[i] < 0 ){
				}
			}

			battleID = CreatXMLElement( doc , "b" );
			doc->LinkEndChild( battleID );
			battleID->SetAttribute( "i0" , iPre[ 0 ] );
			battleID->SetAttribute( "i1" , iPre[ 1 ] );
			battleID->SetAttribute( "i2" , iPre[ 2 ] );

			continue;

		}
		if( sscanf( line, "%d", &iWork ) != 1 ){
			continue;
		}
		if( iWork < 0 ){
			continue;
		}
		iFirst = iWork;
		p = strstr( line, "to" );
		if( p != NULL ){
			if( sscanf( p+2, "%d", &iWork ) != 1 ){
				iLast = iFirst;
			}else{
				iLast = iWork;
			}
			if( iWork < 0 ){
				continue;
			}
		}else{
			iLast = iFirst;
		}


		xmlElement* mapID = CreatXMLElement( doc , "m" );
		battleID->LinkEndChild( mapID );
		mapID->SetAttribute( "min" ,iFirst );
		mapID->SetAttribute( "max" , iLast );
	}
	fclose( file );

	

	doc->Save( "c:\\work\\1.xml" , false );
}



fvoid		SaveAppear()
{
	xmlDocument* doc = CreatXMLDocument();
	xmlElement* root = CreatXMLElement( doc , "root" );
	doc->LinkEndChild( root );

	FILE*   file;
	char    line[512];

	int     i, j;
	int     linenum=0;
	int		iRet , mapID , x , y;

	file = fopen( "C:\\work\\shiqicc95\\sss\\gmsv\\data\\appear.txt" , "r" );
	if( file == NULL )
	{
		return;
	}
	

	while( fgets( line , sizeof( line ) , file ) ){
		char    *p;
		linenum++;

		pohcd( line, " \t" );
		dchop(line, " \t");

		if( line[0] == '#' )continue;
		if( line[0] == '\n' )continue;
		chomp( line );

			iRet = sscanf( line , "%d %d %d", &mapID , &x , &y );
			if( iRet == 3 )
			{
				xmlElement* mapID1 = CreatXMLElement( doc , "a" );
				root->LinkEndChild( mapID1 );
				mapID1->SetAttribute( "m" , mapID );
				mapID1->SetAttribute( "x" , x );
				mapID1->SetAttribute( "y" , y );
			}

		
	}
	fclose( file );



	doc->Save( "c:\\work\\1.xml" , false );
}


bool SaveBlackMarketItem( char* filename)
{
	FILE *fp;	
	int  i, j, k;
	char line[512]="", cTmp[256]="";
	char *ip=NULL, *gp=NULL;	

	xmlDocument* doc = CreatXMLDocument();
	xmlElement* root = CreatXMLElement( doc , "root" );
	doc->LinkEndChild( root );


	fp = fopen( "C:\\work\\shiqicc95\\sss\\gmsv\\data\\bmitem.txt" , "r");

	if(fp==NULL){
		return false;
	}else{
		while(fgets( line, sizeof(line), fp)!=NULL){			
			char cTmp1[256]="", cTmp2[256]="", cTmp3[256]="";
			char iTmp1[128]="", iTmp2[128]="", iTmp3[128]="", iTmp4[128]="", iTmp5[128]="";
			

			char name[ 128 ] = {};
			int iamge;

			sscanf( line, "%s %d %s %s %s %s %s", 
				name ,
				&iamge ,
				iTmp1, iTmp2, iTmp3, iTmp4,	cTmp);

			int id[ 4 ][ 3 ] = {};
			for(i=0; i<3; i++)
			{
				if(getStringFromIndexWithDelim( iTmp1, ",", i+1, iTmp5, sizeof( iTmp5))!=false)
					id[0][i] = atoi(iTmp5);
				if(getStringFromIndexWithDelim( iTmp2, ",", i+1, iTmp5, sizeof( iTmp5))!=false)
					id[1][i] = atoi(iTmp5);
				if(getStringFromIndexWithDelim( iTmp3, ",", i+1, iTmp5, sizeof( iTmp5))!=false)
					id[2][i] = atoi(iTmp5);
				if(getStringFromIndexWithDelim( iTmp4, ",", i+1, iTmp5, sizeof( iTmp5))!=false)
					id[3][i] = atoi(iTmp5);
			}

			ip = strstr( cTmp, "I");
			gp = strstr( cTmp, "G");	

			int idc[ 4 ] = {};

			if( ip && gp && gp>ip){
				strncpy( cTmp1, ip+1, gp-ip-1);	
				for(i=0; i<4; i++)
					if(getStringFromIndexWithDelim( cTmp1, ",", i+1, cTmp3, sizeof( cTmp3))!=false)
						idc[i] = atoi(cTmp3);	

				strcpy( cTmp2, gp+1);
			}else if( ip && gp && gp<ip){
				strcpy( cTmp1, ip+1);		
				for(i=0; i<4; i++)
					if(getStringFromIndexWithDelim( cTmp1, ",", i+1, cTmp3, sizeof( cTmp3))!=false)
						idc[i] = atoi(cTmp3);	

				strncpy( cTmp2, gp+1, ip-gp-1);
			}else if( gp && !ip){
				strcpy( cTmp2, gp+1);
				memset( cTmp1 , 0 , 256 );
			}else if( !gp && ip){
				strcpy( cTmp1, ip+1);
				for(i=0; i<4; i++)
					if(getStringFromIndexWithDelim( cTmp1, ",", i+1, cTmp3, sizeof( cTmp3))!=false)
						idc[i] = atoi(cTmp3);	
				memset( cTmp2 , 0 , 256 );
			}

			xmlElement* mapID1 = CreatXMLElement( doc , "b" );
			root->LinkEndChild( mapID1 );

			mapID1->SetAttribute( "str" , name );
			mapID1->SetAttribute( "ex" , iamge );
			for ( int j = 0 ; j < 4 ; j++ )
			{
				char buff[ 32 ];
                sprintf( buff , "item%d" , j );
                string str = buff;

				mapID1->SetAttribute( str.c_str() , idc[ j ] );
			}
			mapID1->SetAttribute( "gp" , atoi( cTmp2 ) );

			int c = 0;
			for ( int i = 0 ; i < 4 ; i++ )
			{
				for ( int j = 0 ; j < 3 ; j++ )
				{
                    char buff[ 32 ];
                    sprintf( buff , "ex%d" , c );
                    string str = buff;

					mapID1->SetAttribute( str.c_str() , iamge );
					c++;

				}
			}
			
		}
	}

	fclose(fp);

	doc->Save( "c:\\work\\1.xml" , false );

	return true;
}


bool SaveEffect( )
{
	xmlDocument* doc = CreatXMLDocument();
	xmlElement* root = CreatXMLElement( doc , "root" );
	doc->LinkEndChild( root );


	FILE*   f;
	char    line[256];
	int     linenum=0;

	int effectreadlen=0;

	f = fopen( "C:\\work\\shiqicc95\\sss\\gmsv\\data\\effect.txt" ,"r");
	if( f == NULL ){
		return false;
	}

	linenum = 0;
	while( fgets( line, sizeof( line ), f ) ){
		linenum ++;
		if( line[0] == '#' )continue;        /* comment */
		if( line[0] == '\n' )continue;       /* none    */
		chomp( line );

		replaceString( line, '\t' , ' ' );
		deleteSequentChar( line, " " );

		if( line[0] == ' ' )continue;
		{
			char    token[256];
			int     ret;

			ret = getStringFromIndexWithDelim( line," ",1,token,
				sizeof(token));
			if( ret==false ){
				continue;
			}
			int floor = atoi(token);

			ret = getStringFromIndexWithDelim( line," ",2,token,
				sizeof(token));
			if( ret==false ){
				continue;
			}

			int effect = atoi( token );

			ret = getStringFromIndexWithDelim( line," ",3,token,
				sizeof(token));
			if( ret ==false){
				continue;
			}

			int level = atoi( token );

			ret = getStringFromIndexWithDelim( line," ",4,token,
				sizeof(token));
			if( ret ==false){
				continue;
			}

			int month = atoi( token );

			ret = getStringFromIndexWithDelim( line," ",5,token,
				sizeof(token));
			if( ret ==false){
				continue;
			}

			int day = atoi( token );

			ret = getStringFromIndexWithDelim( line," ",6,token,
				sizeof(token));
			if( ret ==false){
				continue;
			}

			int hour = atoi( token );


			ret = getStringFromIndexWithDelim( line," ",7,token,
				sizeof(token));
			if( ret ==false){
				continue;
			}

			int min = atoi( token );

			ret = getStringFromIndexWithDelim( line," ",8,token,
				sizeof(token));
			if( ret ==false){
				continue;
			}

			int expire = atoi( token );

			effectreadlen ++;


			xmlElement* e = CreatXMLElement( doc , "e" );
			root->LinkEndChild( e );

			e->SetAttribute( "m" , floor );
			e->SetAttribute( "e" , effect );
			e->SetAttribute( "lv" , level );

			e->SetAttribute( "month" , month );
			e->SetAttribute( "day" , day );
			e->SetAttribute( "hour" , hour );
			e->SetAttribute( "min" , min );
			e->SetAttribute( "expire" , expire );
		}
	}
	fclose(f);
	
	doc->Save( "c:\\work\\1.xml" , false );


	return true;
}


void SaveGambleBankItems()
{

	xmlDocument* doc = CreatXMLDocument();
	xmlElement* root = CreatXMLElement( doc , "root" );
	doc->LinkEndChild( root );



	FILE *fp;
	char filename[256];
	char buf1[256];
	char name[128];
	int num,ID,type;
	int i=0;
	fp = fopen( "C:\\work\\shiqicc95\\sss\\gmsv\\data\\gambleitems.txt" , "r");
	if( fp != NULL ) {
		while( fgets( buf1, sizeof( buf1), fp) != NULL )	{
			if( strstr( buf1, "#") != 0 ) continue;
			sscanf( buf1,"%s %d %d %d", name, &ID, &num , &type);
			i++;


			xmlElement* xml = CreatXMLElement( doc , "g" );
			root->LinkEndChild( xml );
			xml->SetAttribute( "str" , name );
			xml->SetAttribute( "item" , ID );
			xml->SetAttribute( "num" , num );
			xml->SetAttribute( "type" , type );
		}


		fclose( fp);
	}else	{
	}

	doc->Save( "c:\\work\\1.xml" , false );

}


void SaveItemAtom()
{
	xmlDocument* doc = CreatXMLDocument();
	xmlElement* root = CreatXMLElement( doc , "root" );
	doc->LinkEndChild( root );



	FILE *fp;
	int count=0;
	
	fp = fopen( "C:\\work\\shiqicc95\\sss\\gmsv\\data\\itematom.txt" , "r" );
	if( fp == NULL ){
		return;
	}

	fseek( fp, 0, SEEK_SET );
	while(1){
		char line[16384];
		if( fgets( line, sizeof( line ), fp ) == NULL )break;
		if( line[0] != '#' && line[0] != '\n' )count++;
	}

	if( count == 0 ){
		return;
	}
	
	fseek( fp , 0 , SEEK_SET );
	count = 0;
	while(1){
		char line[16384], tk[1024];
		if( fgets( line, sizeof( line ) , fp ) == NULL )break;
		/* chop */
		line[strlen(line)-1]=0;

		getStringFromIndexWithDelim( line, "," , 1 , tk, sizeof( tk ));
		

		xmlElement* xml = CreatXMLElement( doc , "g" );
		root->LinkEndChild( xml );
		xml->SetAttribute( "name" , tk );

		getStringFromIndexWithDelim( line, "," , 2 , tk, sizeof( tk ));
		int magicflg = atoi( tk );
		xml->SetAttribute( "magic" , tk );

		getStringFromIndexWithDelim( line, "," , 3 , tk, sizeof( tk ));

		int i = atoi( tk );
		xml->SetAttribute( "i" , tk );

		count++;
	}

	fclose(fp);
	doc->Save( "c:\\work\\1.xml" , false );
}


bool SaveJobdailyfile(void)
{
	xmlDocument* doc = CreatXMLDocument();
	xmlElement* root = CreatXMLElement( doc , "root" );
	doc->LinkEndChild( root );

	char	line[20000];
	char	token[16384];
	int		listindex =0;
	int     i;
	FILE* fp;

	fp = fopen( "C:\\work\\shiqicc95\\sss\\gmsv\\data\\jobdaily.txt" , "r");
	if (fp == NULL)
	{
		return false;
	}
	
	map< int , int > mmm;

	while(1){		
		line[0]='\0';	
		if (fgets(line, sizeof(line), fp) == NULL)	break;
		//print("\n %s ", line);
		chop(line);

		if( line[0] == '#' )
			continue;
		for( i=0; i<strlen(line); i++ ){
            if( line[i] == '#' ){
			    line[i] = '\0';
		        break;
			}
		}

		
		
		getStringFromIndexWithDelim(line, "|", 1, token, sizeof(token));
		if (strcmp(token, "") == 0)	break;
		int job = atoi( token );
		if ( mmm.find( job ) != mmm.end() )
		{
			continue;;
		}
		

		xmlElement* xml = CreatXMLElement( doc , "j" );
		root->LinkEndChild( xml );
		xml->SetAttribute( "job" , job );


		getStringFromIndexWithDelim(line, "|", 2, token, sizeof(token));
		if (strcmp(token, "") == 0)	break;
		string ids = &token[ 6 ];
		int rule = atoi( ids.c_str() );
		xml->SetAttribute( "rule" , rule );

		getStringFromIndexWithDelim(line, "|", 3, token, sizeof(token));
		string des = token;
		xml->SetAttribute( "des" , des.c_str() );


		getStringFromIndexWithDelim(line, "|", 4, token, sizeof(token));
		string sts = token;
// 		if ( sts == "已完成" )
// 		{
// 			xml->SetAttribute( "state" , 1 );
// 		}
// 		else
// 		{
// 			xml->SetAttribute( "state" , 0 );
// 		}


		mmm[ job ] = 1;
		listindex++;
	}
	fclose(fp);

	doc->Save( "c:\\work\\1.xml" , false );

	return true;
}



bool SaveMagic()
{
	xmlDocument* doc = CreatXMLDocument();
	xmlElement* root = CreatXMLElement( doc , "root" );
	doc->LinkEndChild( root );



	char	line[20000];
	char	token[16384];
	int		listindex =0;
	int     i;
	FILE* fp;

	fp = fopen( "C:\\work\\shiqicc95\\sss\\gmsv\\data\\magic.txt" , "r");
	if (fp == NULL)
	{
		return false;
	}

	map< int , int > mmm;

	while(1){		
		line[0]='\0';	
		if (fgets(line, sizeof(line), fp) == NULL)	break;
		//print("\n %s ", line);
		chop(line);

		if( line[0] == '#' )
			continue;
		for( i=0; i<strlen(line); i++ ){
			if( line[i] == '#' ){
				line[i] = '\0';
				break;
			}
		}


		xmlElement* xml = CreatXMLElement( doc , "m" );
		root->LinkEndChild( xml );
		


		getStringFromIndexWithDelim(line, ",", 1, token, sizeof(token));
		
		xml->SetAttribute( "name" , token );

		getStringFromIndexWithDelim(line, ",", 2, token, sizeof(token));
		
		xml->SetAttribute( "des" , token );

		getStringFromIndexWithDelim(line, ",", 3, token, sizeof(token));
		
		//xml->SetAttribute( "fun" , token );
		string fun = token;

		getStringFromIndexWithDelim(line, ",", 4, token, sizeof(token));
		string option = token;

		if ( fun == "MAGIC_Recovery" || 
			fun == "MAGIC_OtherRecovery" ||
			fun == "MAGIC_Recovery" || 
			fun == "MAGIC_Ressurect" )
		{
			xml->SetAttribute( "type" , 1 );
			xml->SetAttribute( "power" , token );
		}
		else if ( fun == "MAGIC_StatusChange" || 
			fun == "MAGIC_Weaken" || 
			fun == "MAGIC_Barrier" ||
			fun == "MAGIC_Nocast" )
		{
			xml->SetAttribute( "type" , 2 );
			if ( option.find( "毒" ) == 0 )
			{
				xml->SetAttribute( "status" , 2 );
			}
			else if ( option.find( "麻" ) == 0 )
			{
				xml->SetAttribute( "status" , 3 );
			}
			else if ( option.find( "石" ) == 0 )
			{
				xml->SetAttribute( "status" , 4 );
			}
			else if ( option.find( "乱" ) == 0 )
			{
				xml->SetAttribute( "status" , 5 );
			}
			else if ( option.find( "醉" ) == 0 )
			{
				xml->SetAttribute( "status" , 6 );
			}
			else if ( option.find( "眠" ) == 0 )
			{
				xml->SetAttribute( "status" , 7 );
			}
			else if ( option.find( "剧" ) == 0 )
			{
				xml->SetAttribute( "status" , 8 );
			}
			else if ( option.find( "障" ) == 0 )
			{
				xml->SetAttribute( "status" , 9 );
			}
			else if ( option.find( "默" ) == 0 )
			{
				xml->SetAttribute( "status" , 10 );
			}
			else if ( option.find( "虚" ) == 0 )
			{
				xml->SetAttribute( "status" , 11 );
			}
			else
			{
				assert( 0 );
			}

			int n = option.find( "turn" );
			string sub = option.substr( n + 5 );
			int turn = atoi( sub.c_str() ) ;
			xml->SetAttribute( "turn" , turn );

			n = option.find( "成" );
			sub = option.substr( n + 3 );
			xml->SetAttribute( "per" , atoi( sub.c_str() ) );
		}
		else if ( fun == "MAGIC_StatusRecovery" )
		{
			xml->SetAttribute( "type" , 3 );
			 if ( option == "全" )
			 {
				 xml->SetAttribute( "statusRec" , 1 );
			 }
			 else if ( option == "毒" )
			 {
				 xml->SetAttribute( "statusRec" , 2 );
			 }
			 else if ( option == "麻" )
			 {
				 xml->SetAttribute( "statusRec" , 3 );
			 }
			 else if ( option == "石" )
			 {
				 xml->SetAttribute( "statusRec" , 4 );
			 }
			 else if ( option == "乱" )
			 {
				 xml->SetAttribute( "statusRec" , 5 );
			 }
			 else if ( option == "醉" )
			 {
				 xml->SetAttribute( "statusRec" , 6 );
			 }
			 else if ( option == "眠" )
			 {
				 xml->SetAttribute( "statusRec" , 7 );
			 }
			 else if ( option == "剧" )
			 {
				 xml->SetAttribute( "statusRec" , 8 );
			 }
			 else if ( option == "障" )
			 {
				 xml->SetAttribute( "statusRec" , 9 );
			 }
			 else if ( option == "默" )
			 {
				 xml->SetAttribute( "statusRec" , 10 );
			 }
			 else if ( option == "虚" )
			 {
				 xml->SetAttribute( "statusRec" , 11 );
			 }
			 else
			 {
				assert( 0 );
			 }

		}
		else if ( fun == "MAGIC_FieldAttChange" )
		{
			xml->SetAttribute( "type" , 4 );
			if ( option.find( "地" ) == 0 )
			{
				xml->SetAttribute( "attr" , 1 );
			}
			else if ( option.find( "水" ) == 0 )
			{
				xml->SetAttribute( "attr" , 2 );
			}
			else if ( option.find( "火" ) == 0 )
			{
				xml->SetAttribute( "attr" , 3 );
			}
			else if ( option.find( "风" ) == 0 )
			{
				xml->SetAttribute( "attr" , 4 );
			}
			else if ( option.find( "无" ) == 0 )
			{
				xml->SetAttribute( "attr" , 0 );
			}
			else
			{
				assert( 0 );
			}

			if ( option.size() > 3 )
			{
				string sub = option.substr( 3 );
				int n = atoi( sub.c_str() ) ;
				xml->SetAttribute( "attrPer" , n );

				n = option.find( "turn" );
				sub = option.substr( n + 5 );
				xml->SetAttribute( "turn" , atoi( sub.c_str() ) );
			}
			
		}
		else if ( fun == "MAGIC_AttReverse" )
		{
			xml->SetAttribute( "type" , 5 );
		}
		else if ( fun == "MAGIC_MagicDef" )
		{
			xml->SetAttribute( "type" , 6 );
			if ( option.find( "吸" ) == 0 )
			{
				xml->SetAttribute( "magicStatus" , 1 );
			}
			else if ( option.find( "反" ) == 0 )
			{
				xml->SetAttribute( "magicStatus" , 2 );
			}
			else if ( option.find( "无" ) == 0 )
			{
				xml->SetAttribute( "magicStatus" , 3 );
			}
			else
			{
				assert( 0 );
			}

			int n = option.find( "turn" );
			string sub = option.substr( n + 5 );
			xml->SetAttribute( "turn" , atoi( sub.c_str() ) );
		}
		else if ( fun == "MAGIC_ResAndDef" )
		{
			xml->SetAttribute( "type" , 7 );
			if ( option.find( "吸" ) >= 0 )
			{
				xml->SetAttribute( "magicStatus" , 1 );
			}
			else if ( option.find( "反" ) >= 0 )
			{
				xml->SetAttribute( "magicStatus" , 2 );
			}
			else if ( option.find( "无" ) >= 0 )
			{
				xml->SetAttribute( "magicStatus" , 3 );
			}
			else
			{
				assert( 0 );
			}

			int hp = atoi( option.c_str() );
			xml->SetAttribute( "power" , hp );

			int n = option.find( "turn" );
			string sub = option.substr( n + 5 );
			xml->SetAttribute( "turn" , atoi( sub.c_str() ) );
		}
		else if ( fun == "MAGIC_AttMagic" )
		{
			xml->SetAttribute( "type" , 8 );
			if ( option.find( "地" ) == 0 )
			{
				xml->SetAttribute( "attr" , 1 );
			}
			else if ( option.find( "水" ) == 0 )
			{
				xml->SetAttribute( "attr" , 2 );
			}
			else if ( option.find( "火" ) == 0 )
			{
				xml->SetAttribute( "attr" , 3 );
			}
			else if ( option.find( "风" ) == 0 )
			{
				xml->SetAttribute( "attr" , 4 );
			}
			else if ( option.find( "无" ) == 0 )
			{
				xml->SetAttribute( "attr" , 0 );
			}
			else
			{
				assert( 0 );
			}

			if ( option.size() > 3 )
			{
				string sub = option.substr( 3 );
				int n = atoi( sub.c_str() ) ;
				xml->SetAttribute( "power" , n );

				n = sub.find( "|" );
				sub = sub.substr( n + 1 );
				xml->SetAttribute( "level" , atoi( sub.c_str() ) );
			}
		}
		else if ( fun == "MAGIC_AttSkill" )
		{
			xml->SetAttribute( "type" , 9 );

		}
		else if ( fun == "MAGIC_ToCallDragon" )
		{
			xml->SetAttribute( "type" , 9 );

			int n = atoi( option.c_str() ) ;
			xml->SetAttribute( "dragon" , n );

			n = option.find( "|" );
			string sub = option.substr( n + 1 );
			xml->SetAttribute( "power" , atoi( sub.c_str() ) );
		}
		else if ( fun == "MAGIC_Metamo" )
		{
			xml->SetAttribute( "type" , 10 );
			xml->SetAttribute( "second" , option.c_str() );
		}
		else if ( fun == "MAGIC_MagicStatusChange" )
		{
			xml->SetAttribute( "type" , 11 );
			
			if ( option.find( "魔抗" ) == 0 )
			{
				xml->SetAttribute( "attr" , 5 );
			}
			else if ( option.find( "冰抗" ) == 0 )
			{
				xml->SetAttribute( "attr" , 2 );
			}
			else if ( option.find( "电抗" ) == 0 )
			{
				xml->SetAttribute( "attr" , 3 );
			}
			else if ( option.find( "火抗" ) == 0 )
			{
				xml->SetAttribute( "attr" , 4 );
			}

			string sub = option.substr( 5 );
			int n = atoi( sub.c_str() ) ;
			xml->SetAttribute( "turn" , n );

			n = sub.find( "|" );
			sub = sub.substr( n + 1 );
			xml->SetAttribute( "per" , atoi( sub.c_str() ) );
		}
		else if ( fun == "MAGIC_StatusChange2" )
		{
			xml->SetAttribute( "type" , 12 );
		}
		else if ( fun.size() )
		{
			assert( 0 );
		}
		
		getStringFromIndexWithDelim(line, ",", 5, token, sizeof(token));
		xml->SetAttribute( "id" , token );

		getStringFromIndexWithDelim(line, ",", 6, token, sizeof(token));
		xml->SetAttribute( "field" , token );

		getStringFromIndexWithDelim(line, ",", 7, token, sizeof(token));
		xml->SetAttribute( "target" , token );

		getStringFromIndexWithDelim(line, ",", 8, token, sizeof(token));
		if ( atoi( token ) )
		{
			xml->SetAttribute( "targetDead" , token );
		}
		
		

		listindex++;
	}
	fclose(fp);

	doc->Save( "c:\\work\\1.xml" , false );

	return true;
}




bool SaveSkill(void)
{
	xmlDocument* doc = CreatXMLDocument();
	xmlElement* root = CreatXMLElement( doc , "root" );
	doc->LinkEndChild( root );



	char	line[20000];
	char	token[16384];
	int		listindex =0;
	int     i;
	FILE* fp;

	fp = fopen( "C:\\work\\shiqicc95\\sss\\gmsv\\data\\petskill2.txt" , "r");
	if (fp == NULL)
	{
		return false;
	}

	map< int , int > mmm;

	while(1){		
		line[0]='\0';	
		if (fgets(line, sizeof(line), fp) == NULL)	break;
		//print("\n %s ", line);
		chop(line);

		if( line[0] == '#' )
			continue;
		for( i=0; i<strlen(line); i++ ){
			if( line[i] == '#' ){
				line[i] = '\0';
				break;
			}
		}


		xmlElement* xml = CreatXMLElement( doc , "m" );
		root->LinkEndChild( xml );



		getStringFromIndexWithDelim(line, ",", 1, token, sizeof(token));

		xml->SetAttribute( "name" , token );

		getStringFromIndexWithDelim(line, ",", 2, token, sizeof(token));

		xml->SetAttribute( "des" , token );

		getStringFromIndexWithDelim(line, ",", 3, token, sizeof(token));

		//xml->SetAttribute( "fun" , token );
		string fun = token;

		getStringFromIndexWithDelim(line, ",", 4, token, sizeof(token));
		string option = token;

		if ( fun == "PETSKILL_None" )
		{
			xml->SetAttribute( "type" , 1 );
		}
		else if ( fun == "PETSKILL_NormalAttack" )
		{
			xml->SetAttribute( "type" , 2 );
		}
		else if ( fun == "PETSKILL_GuardBreak" )
		{
			xml->SetAttribute( "type" , 3 );
		} 
		else if ( fun == "PETSKILL_ContinuationAttack" )
		{
			xml->SetAttribute( "type" , 4 );
			xml->SetAttribute( "turn" , atoi( option.c_str() ) );
		}
		else if ( fun == "PETSKILL_Guardian" )
		{
			xml->SetAttribute( "type" , 5 );
		}
		else if ( fun == "PETSKILL_ChargeAttack" )
		{
			xml->SetAttribute( "type" , 6 );
			xml->SetAttribute( "turn" , atoi( option.c_str() ) );
		}
		else if ( fun == "PETSKILL_Mighty" )
		{
			xml->SetAttribute( "type" , 7 );

		}
		else if ( fun == "PETSKILL_PowerBalance" )
		{
			xml->SetAttribute( "type" , 8 );

		}
		else if ( fun == "PETSKILL_StatusChange" )
		{
			xml->SetAttribute( "type" , 9 );
		}
		else if ( fun == "PETSKILL_PowerBalance" )
		{
			xml->SetAttribute( "type" , 10 );
		}
		else if ( fun == "PETSKILL_Abduct" )
		{
			xml->SetAttribute( "type" , 11 );
		}
		else if ( fun == "PETSKILL_Steal" )
		{
			xml->SetAttribute( "type" , 12 );
		}
		else if ( fun == "PETSKILL_NoGuard" )
		{
			xml->SetAttribute( "type" , 13 );
		}
		else if ( fun == "PETSKILL_Merge" )
		{
			xml->SetAttribute( "type" , 14 );
		}
		else if ( fun == "PETSKILL_Merge" )
		{
			
		}
		else if ( fun == "PETSKILL_FallGround" )
		{
			xml->SetAttribute( "type" , 16 );
		}
		else if ( fun == "PETSKILL_StealMoney" )
		{
			xml->SetAttribute( "type" , 17 );
		}
		else if ( fun == "PETSKILL_AttackMagic" )
		{
			xml->SetAttribute( "type" , 18 );
		}
		else if ( fun == "ENEMYSKILL_ReLife" )
		{
			xml->SetAttribute( "type" , 19 );
		}
		else if ( fun == "ENEMYSKILL_ReHP" )
		{
			xml->SetAttribute( "type" , 20 );
		}
		else if ( fun == "ENEMYSKILL_EnemyHELP" )
		{
			xml->SetAttribute( "type" , 21 );
		}
		else if ( fun == "PETSKILL_WildViolentAttack" )
		{
			xml->SetAttribute( "type" , 22 );
		}
		else if ( fun == "PETSKILL_DamageToHp" )
		{
			xml->SetAttribute( "type" , 23 );
			xml->SetAttribute( "ATK" , -atoi( option.c_str() ) );

			int n = option.find( "|" );
			if ( n >= 0 )
			{
				string sub = option.substr( n + 1 );
				xml->SetAttribute( "HP" , atoi( sub.c_str() ) );
			}
		}
		else if ( fun == "PETSKILL_Refresh" )
		{
			xml->SetAttribute( "type" , 24 );
		}
		else if ( fun == "PETSKILL_Fixitem" )
		{
			xml->SetAttribute( "type" , 25 );
		}
		else if ( fun == "PETSKILL_SpeedyAttack" )
		{
			xml->SetAttribute( "type" , 26 );
		}
		else if ( fun == "PETSKILL_Modifyattack" )
		{
			xml->SetAttribute( "type" , 27 );
		}
		else if ( fun == "PETSKILL_Mdfyattack" )
		{
			xml->SetAttribute( "type" , 28 );
		}
		else if ( fun == "PETSKILL_MagicStatusChange" )
		{
			xml->SetAttribute( "type" , 29 );

		}
		else if ( fun == "PETSKILL_Combined" )
		{
			xml->SetAttribute( "type" , 30 );
		}
		
		int n = option.find( "倍" );
		if ( n >= 0 )
		{
			string sub = option.substr( n + 2 );
			xml->SetAttribute( "CRT" , atoi( sub.c_str() ) );
		}

		n = option.find( "铁壁|" );
		if ( n >= 0 )
		{
			string sub = option.substr( n + 5 );
			xml->SetAttribute( "turn" , atoi( sub.c_str() ) );

			n = sub.find( "|" );
			sub = sub.substr( n + 1 );
			xml->SetAttribute( "DEF" , atoi( sub.c_str() ) );
		}
		n = option.find( "EA|" );
		if ( n >= 0 )
		{
			string sub = option.substr( n + 3 );
			xml->SetAttribute( "earth" , atoi( sub.c_str() ) );
		}
		n = option.find( "WA|" );
		if ( n >= 0 )
		{
			string sub = option.substr( n + 3 );
			xml->SetAttribute( "water" , atoi( sub.c_str() ) );
		}
		n = option.find( "FI|" );
		if ( n >= 0 )
		{
			string sub = option.substr( n + 3 );
			xml->SetAttribute( "fire" , atoi( sub.c_str() ) );
		}
		n = option.find( "WI|" );
		if ( n >= 0 )
		{
			string sub = option.substr( n + 3 );
			xml->SetAttribute( "wind" , atoi( sub.c_str() ) );
		}


		n = option.find( "回避" );
		if ( n >= 0 )
		{
			string sub = option.substr( n + 4 );
			xml->SetAttribute( "MISS" , atoi( sub.c_str() ) );
		}

		n = option.find( "回避%" );
		if ( n >= 0 )
		{
			string sub = option.substr( n + 5 );
			xml->SetAttribute( "MISS" , atoi( sub.c_str() ) );
		}
		n = option.find( "反击%" );
		if ( n >= 0 )
		{
			string sub = option.substr( n + 5 );
			xml->SetAttribute( "BACK" , atoi( sub.c_str() ) );
		}
		n = option.find( "会心%" );
		if ( n >= 0 )
		{
			string sub = option.substr( n + 5 );
			xml->SetAttribute( "CRT" , atoi( sub.c_str() ) );
		}

		n = option.find( "攻%" );
		if ( n >= 0 )
		{
			string sub = option.substr( n + 3 );
			xml->SetAttribute( "ATK" , atoi( sub.c_str() ) );
		}
		n = option.find( "防%" );
		if ( n >= 0 )
		{
			string sub = option.substr( n + 3 );
			xml->SetAttribute( "DEF" , atoi( sub.c_str() ) );
		}

		n = option.find( "turn" );
		if ( n >= 0 )
		{
			string sub = option.substr( n + 4 );
			xml->SetAttribute( "turn" , atoi( sub.c_str() ) );
		}

		n = option.find( "magic" );
		if ( n >= 0 )
		{
			string sub = option.substr( n + 5 );
			xml->SetAttribute( "magic" , atoi( sub.c_str() ) );
		}
		n = option.find( "item" );
		if ( n >= 0 )
		{
			string sub = option.substr( n + 4 );
			xml->SetAttribute( "item" , atoi( sub.c_str() ) );
		}

		n = option.find( "毒" );
		if ( n >= 0 )
		{
			xml->SetAttribute( "status" , 2 );
		}
		n = option.find( "麻" );
		if ( n >= 0 )
		{
			xml->SetAttribute( "status" , 3 );
		}
		n = option.find( "石" );
		if ( n >= 0 )
		{
			xml->SetAttribute( "status" , 4 );
		}
		n = option.find( "混" );
		if ( n >= 0 )
		{
			xml->SetAttribute( "status" , 5 );
		}
		n = option.find( "醉" );
		if ( n >= 0 )
		{
			xml->SetAttribute( "status" , 6 );
		}
		n = option.find( "睡" );
		if ( n >= 0 )
		{
			xml->SetAttribute( "status" , 7 );
		}
		n = option.find( "剧" );
		if ( n >= 0 )
		{
			xml->SetAttribute( "status" , 8 );
		}
		n = option.find( "障" );
		if ( n >= 0 )
		{
			xml->SetAttribute( "status" , 9 );
		}
		n = option.find( "默" );
		if ( n >= 0 )
		{
			xml->SetAttribute( "status" , 10 );
		}
		n = option.find( "虚" );
		if ( n >= 0 )
		{
			xml->SetAttribute( "status" , 11 );
		}
		n = option.find( "全" );
		if ( n >= 0 )
		{
			xml->SetAttribute( "status" , 1 );
		}

		getStringFromIndexWithDelim(line, ",", 7, token, sizeof(token));
		xml->SetAttribute( "id" , token );

		getStringFromIndexWithDelim(line, ",", 8, token, sizeof(token));
		xml->SetAttribute( "field" , token );

		getStringFromIndexWithDelim(line, ",", 9, token, sizeof(token));
		xml->SetAttribute( "target" , token );

		getStringFromIndexWithDelim(line, ",", 10, token, sizeof(token));
		xml->SetAttribute( "useType" , token );

		getStringFromIndexWithDelim(line, ",", 11, token, sizeof(token));
		xml->SetAttribute( "gold" , token );



		listindex++;
	}
	fclose(fp);

	doc->Save( "c:\\work\\1.xml" , false );

	return true;
}


bool SaveQuestion(void)
{
	xmlDocument* doc = CreatXMLDocument();
	xmlElement* root = CreatXMLElement( doc , "root" );
	doc->LinkEndChild( root );



	char	line[20000];
	char	token[16384];
	int		listindex =0;
	int     i;
	FILE* fp;

	fp = fopen( "C:\\work\\shiqicc95\\sss\\gmsv\\data\\question.txt" , "r");
	if (fp == NULL)
	{
		return false;
	}

	map< int , int > mmm;

	while(1){		
		line[0]='\0';	
		if (fgets(line, sizeof(line), fp) == NULL)	break;
		//print("\n %s ", line);
		chop(line);

		if( line[0] == '#' )
			continue;
		for( i=0; i<strlen(line); i++ ){
			if( line[i] == '#' ){
				line[i] = '\0';
				break;
			}
		}


		xmlElement* xml = CreatXMLElement( doc , "m" );
		root->LinkEndChild( xml );



		getStringFromIndexWithDelim(line, ",", 1, token, sizeof(token));
		xml->SetAttribute( "id" , atoi( token ) );
		getStringFromIndexWithDelim(line, ",", 2, token, sizeof(token));
		xml->SetAttribute( "type" , atoi( token ) );
		getStringFromIndexWithDelim(line, ",", 3, token, sizeof(token));
		xml->SetAttribute( "level" , atoi( token ) );
		getStringFromIndexWithDelim(line, ",", 4, token, sizeof(token));
		xml->SetAttribute( "answerType" , atoi( token ) );
		getStringFromIndexWithDelim(line, ",", 5, token, sizeof(token));
		xml->SetAttribute( "answerID" , atoi( token ) );
		getStringFromIndexWithDelim(line, ",", 6, token, sizeof(token));
		xml->SetAttribute( "question" ,  token );
		getStringFromIndexWithDelim(line, ",", 7, token, sizeof(token));
		xml->SetAttribute( "select1" ,  token );
		getStringFromIndexWithDelim(line, ",", 8, token, sizeof(token));
		xml->SetAttribute( "select2" ,  token );
		getStringFromIndexWithDelim(line, ",", 9, token, sizeof(token));
		xml->SetAttribute( "select3" ,  token );

		
		listindex++;
	}
	fclose(fp);

	doc->Save( "c:\\work\\1.xml" , false );

	return true;
}


bool SaveRace(void)
{
	xmlDocument* doc = CreatXMLDocument();
	xmlElement* root = CreatXMLElement( doc , "root" );
	doc->LinkEndChild( root );



	char	line[20000];
	char	token[16384];
	int		listindex =0;
	int     i;
	FILE* fp;

	fp = fopen( "C:\\work\\shiqicc95\\sss\\gmsv\\data\\raceman.txt" , "r");
	if (fp == NULL)
	{
		return false;
	}

	map< int , int > mmm;

	while(1){		
		line[0]='\0';	
		if (fgets(line, sizeof(line), fp) == NULL)	break;
		//print("\n %s ", line);
		chop(line);

		if( line[0] == '#' )
			continue;
		for( i=0; i<strlen(line); i++ ){
			if( line[i] == '#' ){
				line[i] = '\0';
				break;
			}
		}


		xmlElement* xml = CreatXMLElement( doc , "m" );
		root->LinkEndChild( xml );



		getStringFromIndexWithDelim(line, "|", 1, token, sizeof(token));
		xml->SetAttribute( "id" , atoi( token ) );
		getStringFromIndexWithDelim(line, "|", 2, token, sizeof(token));
		xml->SetAttribute( "name" , token );
		getStringFromIndexWithDelim(line, "|", 3, token, sizeof(token));
		xml->SetAttribute( "img" , atoi( token ) );
		getStringFromIndexWithDelim(line, "|", 4, token, sizeof(token));
		xml->SetAttribute( "min" , atoi( token ) );
		getStringFromIndexWithDelim(line, "|", 5, token, sizeof(token));
		xml->SetAttribute( "max" , atoi( token ) );
		
		listindex++;
	}
	fclose(fp);

	doc->Save( "c:\\work\\1.xml" , true );

	return true;
}


int		main()
{
 	crtIFileSystem* fileSystem = crtManager::GetFileSystem();

    ftw( "/Users/fox/Desktop/saRes/ssss/gmsv/data/npc" , fn , 500 );
    ftw( "/Users/fox/Desktop/saRes/ssss/gmsv/data/npc" , fn1 , 500 );
    
 	crtIWriteFile* writeFile = fileSystem->CreateAndWriteFile( "/Users/fox/Desktop/saExport/npcText.txt" );

	short unicodeFlag= 0xFEFFU;
	writeFile->Write( &unicodeFlag , 2 );
//    const unsigned char TIXML_UTF_LEAD_0 = 0xefU;
//    const unsigned char TIXML_UTF_LEAD_1 = 0xbbU;
//    const unsigned char TIXML_UTF_LEAD_2 = 0xbfU;
//    
//    fputc( TIXML_UTF_LEAD_0, fp );
//    fputc( TIXML_UTF_LEAD_1, fp );
//    fputc( TIXML_UTF_LEAD_2, fp );
    

	vector< wstring > vww;
	vww.reserve( stringMap.size() );

	for ( map< wstring , int >::iterator iter = stringMap.begin() ; iter != stringMap.end() ; ++iter )
	{
		vww.push_back( L"" );
	}
	for ( map< wstring , int >::iterator iter = stringMap.begin() ; iter != stringMap.end() ; ++iter )
	{
		vww[ iter->second ] = iter->first;
	}
	
	for ( fint32 i = 0 ; i < vww.size() ; i++ )
	{
		char buff[ 32 ];
        sprintf( buff , "%d" , i );
		wstring w = AnsitoUnicode( buff );
		writeFile->Write( w.c_str() , w.size() * 4 );
		writeFile->Write( L"=" , 4 );
		writeFile->Write( vww[ i ].c_str()  , vww[ i ].size() * 4 );
		writeFile->Write( L"\n" , 4 );
	}

	writeFile->Release();

    
	xmlDocument* doc = CreatXMLDocument();
	xmlElement* root = CreatXMLElement( doc , "root" );
	doc->LinkEndChild( root );


	for ( map< string, NpcTemplate >::iterator iter = npcTemplateMap.begin() ; iter != npcTemplateMap.end() ; ++iter )
	{
		NpcTemplate& tempalte1 = iter->second;

		xmlElement* xml1 = CreatXMLElement( doc , "t" );
		root->LinkEndChild( xml1 );

		xml1->SetAttribute( "template" , tempalte1.templateName.c_str() );
		xml1->SetAttribute( "name" , tempalte1.name.c_str() );
		xml1->SetAttribute( "nobody" , tempalte1.nobody.c_str() );
		xml1->SetAttribute( "nosee" , tempalte1.nosee.c_str() );
		xml1->SetAttribute( "type" , tempalte1.type.c_str() );
		xml1->SetAttribute( "fun" , tempalte1.fun.c_str() );
		xml1->SetAttribute( "hp" , tempalte1.hp.c_str() );
		xml1->SetAttribute( "mp" , tempalte1.mp.c_str() );
		xml1->SetAttribute( "str" , tempalte1.str.c_str() );
		xml1->SetAttribute( "tough" , tempalte1.tough.c_str() );
		xml1->SetAttribute( "loopTime" , tempalte1.loopTime.c_str() );
		xml1->SetAttribute( "imgName" , tempalte1.imgName.c_str() );
		xml1->SetAttribute( "fly" , tempalte1.fly.c_str() );
		xml1->SetAttribute( "itemNum" , tempalte1.itemNum.c_str() );
	}

	doc->Save( "/Users/fox/Desktop/saExport/npcTemplate.xml" );
	ReleaseXMLDocument( doc );

    return 0;
}

