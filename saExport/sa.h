#ifndef _SA_H_
#define _SA_H_


#include <vector>
#include <map>
#include <string>
#include <stdio.h>
#include <math.h>
#include <iconv.h>
#include <stdlib.h>

using namespace std;

struct ItemInfo 
{
	string name;
	string explain1;
	string explain2;
	string explain3;

	int quaint;
	int unknow1;
	int unknow2;
	int unknow3;
	int unknow4;
	int unknow5;

	
	string useItem;
	string suitEquip;
	string resuitEquip;

	string dropItem;
	string pickupItem;

	string autoResume;

	int		id;
	int		img;
	int		sell;
	int		type;
	int		stage;
	int		range;
	int		level;
	int		num;
	int		unknow6;
	int		alchemyAttr;
	int		unknow7;
	int		unknow8;
	int		unknow9;


	int		suit;
	int		perdure1;
	int		perdure2;
	int		increase;
	int		decrease;
	int		code;
	int		attackNum1;
	int		attackNum2;
	int		str1;
	int		str2;
	int		tgh1;
	int		tgh2;
	int		dex1;
	int		dex2;
	int		hp1;
	int		hp2;
	int		mp1;
	int		mp2;
	int		luck1;
	int		luck2;
	int		Charm1;
	int		Charm2;

	int		dodge1;
	int		dodge2;

	int		attrType;
	int		attr;

	int		magic;
	int		rare;
	int		mp;
	int		ward;
	int		attackRank;
	int		weight;

	int		Poison1;
	int		Poison2;
	int		Paralysis1;
	int		Paralysis2;
	int		Sleep1;
	int		Sleep2;
	int		Stone1;
	int		Stone2;
	int		Drunk1;
	int		Drunk2;
	int		Confusion1;
	int		Confusion2;

	int		Critical1;
	int		Critical2;

	int		trade;
	int		lose;
	int		drop;
	int		logout;
	int		save;

	int		store;
	int		alchemy;
	
	string	material[ 5 ];
	int		materialNum[ 5 ];

};


struct EnemyCount
{
	int id;
	int mapID;
	
	int x1;
	int y1;
	int x2;
	int y2;

	int min;
	int max;
	int num;

	int unkown;

	int group0;
	int group1;
	int group2;
	int group3;
	int group4;
	int group5;
	int group6;
	int group7;
	int group8;
	int group9;

	int groupPro0;
	int groupPro1;
	int groupPro2;
	int groupPro3;
	int groupPro4;
	int groupPro5;
	int groupPro6;
	int groupPro7;
	int groupPro8;
	int groupPro9;
};


struct group
{
	string name;
	int id;

	int item0;
	int item1;

	int enemy0;
	int enemy1;
	int enemy2;
	int enemy3;
	int enemy4;
	int enemy5;
	int enemy6;
	int enemy7;
	int enemy8;
	int enemy9;

	int enemyPro0;
	int enemyPro1;
	int enemyPro2;
	int enemyPro3;
	int enemyPro4;
	int enemyPro5;
	int enemyPro6;
	int enemyPro7;
	int enemyPro8;
	int enemyPro9;


};

struct enemy 
{
	string name;

	int attack;
	int attackTarget;
	int attackAI;

	int defence;
	int magic;
	int escape;

	int wa0;
	int wa1;
	int wa2;
	int wa3;
	int wa4;
	int wa5;
	int wa6;
	int rn;

	int unknow;
	int id;
	int baseID;
	int levelMin;
	int levelMax;
	int numMax;
	int numMin;

	int fight;
	int exp;
	int dp;
	int type;
	int pet;


	int item0;
	int item1;
	int item2;
	int item3;
	int item4;
	int item5;
	int item6;
	int item7;
	int item8;
	int item9;


	int itemPro0;
	int itemPro1;
	int itemPro2;
	int itemPro3;
	int itemPro4;
	int itemPro5;
	int itemPro6;
	int itemPro7;
	int itemPro8;
	int itemPro9;

	enemy()
	{
		magic = 0;
	}
};

struct enemybase
{
	string name;
	string alchemy[ 5 ];

	int id;
	int initNum;
	float	levelUpPoint;

	int baseVitality;
	int baseStrength;
	int baseToughness;
	int baseDexterity;

	int ai;

	int get;

	int earth;
	int water;
	int fire;
	int wind;

	int poison;	
	int paralysis;
	int sleep;
	int stone;
	int drunk;
	int confusion;

	int petSkill0;
	int petSkill1;
	int petSkill2;
	int petSkill3;
	int petSkill4;
	int petSkill5;
	int petSkill6;

	int rare;
	int critical;
	int counter;
	int slot;
	int imgNum;
	int petFlag;
	int size;

	int ATOMBASEADD0;
	int ATOMFIXMIN0;
	int ATOMFIXMAX0;
	int ATOMBASEADD1;
	int ATOMFIXMIN1;
	int ATOMFIXMAX1;
	int ATOMBASEADD2;
	int ATOMFIXMIN2;
	int ATOMFIXMAX2;
	int ATOMBASEADD3;
	int ATOMFIXMIN3;
	int ATOMFIXMAX3;
	int ATOMBASEADD4;
	int ATOMFIXMIN4;
	int ATOMFIXMAX4;

	int limitLevel;
	int amalgamation;
};

struct mapHead
{
	char head[6];
	unsigned char id1;
	unsigned char id2;
	char name[32];

	unsigned char x1;
	unsigned char x2;
	unsigned char y1;
	unsigned char y2;
};

struct image
{
	int id;
	int pos;
	int len;
	int px;
	int py;
	int w;
	int h;
	char e;
	char s;
	unsigned char flag;
	char unknow[45];
	long mapID;
};

struct imagehead
{
	char buffer[2];
	short unkonw;
	int w;
	int h;
	int len;
};


struct role
{
public:

	short	direction;
	short	action;
	int     time;

	int     numframe;

	int     unknow0;
	int     unknow1;
	int     unknow2;
};

struct spradrn 
{
	int id;
	int pos;
	short num;
	short unkonw;

};

struct roleframe 
{
	int	id;
	char	unkonw[6];
};




#define IS_2BYTEWORD( _a_ ) ( (char)(0x80) <= (_a_) && (_a_) <= (char)(0xFF) )

void chompex( char *buf )
{
	while( *buf ){
		if( *buf == '\r' || *buf == '\n' ){
			*buf='\0';
		}
		buf++;
	}
}

void chop( char* src )
{
	int length = strlen( src );
	if( length == 0 ) return;
	src[length-1] = '\0';
}


void dchop( char* src , char* del)
{
	int dellen, srclen;
	int i;
	bool delete1 = false;

	srclen = strlen( src );
	dellen = strlen( del );
	if( srclen == 0 || dellen == 0 ) return;

	for( i = 0 ; i < dellen ; i ++ ){
		if( src[srclen-1] == del[i] ){
			delete1 = true;
			break;
		}
	}

	if( delete1 )src[srclen - 1] = '\0';
}


void pohcd( char* src , char* del)
{
	int dellen, srclen;
	int i;
	bool delete1 = false;

	srclen = strlen( src );
	dellen = strlen( del );
	if( srclen == 0 || dellen == 0 )
        return;

	for( i = 0 ; i < dellen ; i ++ ){
		if( src[0] == del[i] ){
			delete1 = true;
			break;
		}
	}

	if( delete1 )
		for( i = 0 ; i < srclen ; i ++ )
			src[i] = src[i+1];
}


//this function copy all from the second
char * ScanOneByte( char *src, char delim )
{

	if (!src) return NULL;

	for( ;src[0] != '\0'; src ++ ){

//		if( IS_2BYTEWORD( src[0] ) ){
//
//			if( src[1] != 0 ){
//                
//				src ++;
////                if( src[0] == delim ){
////                    src++;
////                    return (src);
////                }
//			}
//			continue;
//		}

		if( src[0] == delim ){
			return src;
		}
	}

	return NULL;
}

char* strncpy2( char* dest, const char* src, size_t n )
{
	if( n > 0 ){
		char*   d = dest;
		const char*   s = src;
		int i;
		for( i=0; i<n ; i++ ){
			if( *(s+i) == 0 ){
				*(d+i) = '\0';
				return dest;
			}
			if( *(s+i) & 0x80 ){
				*(d+i)  = *(s+i);
				i++;
				if( i>=n ){
					*(d+i-1)='\0';
					break;
				}
				*(d+i)  = *(s+i);
			}else
				*(d+i) = *(s+i);
		}
	}
	return dest;
}

void strcpysafe( char* dest ,size_t n ,const char* src )
{
	if (!src) {
		*dest = '\0';
		return;
	}
	if( n <= 0 )
		return;

	else if( n < strlen( src ) + 1 ){
		
		strncpy2( dest , src , n-1 );
		dest[n-1]='\0';
	}else
		strcpy( dest , src );

}

void strncpysafe( char* dest , const size_t n ,
				 const char* src ,const int length )
{
    for ( int i = 0 ; i < length ; ++i )
    {
        dest[ i ] = src[ i ];
    }
    dest[ length ] = 0;
    
    return;
    
	int Short;
	Short = ::min( (int)strlen( src ) , length );

	if( n < Short + 1 ){
	
		strncpy2( dest , src , n-1 );
		dest[n-1]='\0';

	}else if( n <= 0 ){
		return;
	}else{
		strncpy2( dest , src , Short );
		dest[Short]= '\0';

	}
}

bool getStringFromIndexWithDelim_body( char* src ,char* delim ,int index,
									  char* buf , int buflen ,
									  char *file, int line )
{
	int i;         
	int length =0; 
	int addlen=0;   
	int oneByteMode = 0;

	if( strlen( delim ) == 1 ){
		oneByteMode = 1;
	}
	for( i =  0 ; i < index ; i ++ ){
		char* last;
		src += addlen;

		if( oneByteMode ){

			last = ScanOneByte( src, delim[0] );
		}else{
			last  = strstr( src , delim );  
		}
		if( last == NULL ){
			strcpysafe( buf , buflen, src );

			if( i == index - 1 )

				return true;

			return false;
		}


		length = last - src;

		addlen= length + strlen( delim );
	}
	strncpysafe( buf, buflen , src,length );

	return true;
}

int code_convert(char *from_charset,char *to_charset,char *inbuf,size_t inlen,char *outbuf,size_t outlen)
{
    iconv_t cd;
    int rc;
    char **pin = &inbuf;
    char **pout = &outbuf;
    
    cd = iconv_open(to_charset,from_charset);
    if (cd==0) return -1;
    memset(outbuf,0,outlen);
    if (iconv(cd,pin,&inlen,pout,&outlen)==-1)
        return -1;
    iconv_close(cd);
    return 0;
}

int uTog(char *inbuf,int inlen,char *outbuf,int outlen)
{
    return code_convert("utf-8","gb2312",inbuf,inlen,outbuf,outlen);
}


int myUTF8_to_UNICODE( wchar_t* unicode, unsigned char* utf8, int len)
{
    int length;
    unsigned char* t = utf8;
    
    length = 0;
    while (utf8 - t < len){
        //one byte.ASCII as a, b, c, 1, 2, 3 ect
        if ( *(unsigned char *) utf8 <= 0x7f ) {
            //expand with 0s.
            *unicode++ = *utf8++;
        }
        //2 byte.
        else if ( *(unsigned char *) utf8 <= 0xdf ) {
            *unicode++ = ((*(unsigned char *) utf8 & 0x1f) << 6) + ((*(unsigned char *) (utf8 + 1)) & 0x3f);
            utf8 += 2;
        }
        //3 byte.Chinese may use 3 byte.
        else {
            *unicode++ = ((int) (*(unsigned char *) utf8 & 0x0f) << 12) +
            ((*(unsigned char *) (utf8 + 1) & 0x3f) << 6) +
            (*(unsigned char *) (utf8 + 2) & 0x3f);
            utf8 += 3;
        }
        length++;
    }
    
    *unicode = 0;
    
    return (length);
}

wchar_t* AnsitoUnicode(char *inbuf)
{
    size_t inlen = strlen( inbuf ) + 1;
    
    char outbuf[ 4096 ];
    size_t outlen = 4096;
    
    int len1 = code_convert("gb2312","utf-8",inbuf,inlen,outbuf,outlen);
    
    static wchar_t buffer[ 4096 ];
    myUTF8_to_UNICODE( buffer , (unsigned char*)outbuf , strlen(outbuf) );
    
    return buffer;
}

char*   replaceString( char* src, char oldc ,char newc )
{
	char*   cp=src;

	do{
		if( *cp == oldc ) *cp=newc;
	}while( *cp++ );
	return src;
}

#define BACKSLASH '\\'

void deleteSequentChar( char* src , char* dels )
{
	int length;
	int delength;
	int i,j;
	int index=0;
	char backchar='\0';

	length = strlen( src );
	delength = strlen( dels );

	for( i = 0 ; i < length ; i ++ ){
		if( src[i] == BACKSLASH ){
			
			src[index++]=src[i++];
			if( i >= length ){
				fprintf( stderr ,"*\n");
				break;
			}
			src[index++]=src[i];
			
			backchar = '\0';
			continue;
		}
		if( src[i] == backchar )
			continue;

		backchar = '\0';
		for( j = 0 ; j < delength ; j ++ ){
			if( src[i] == dels[j] ){
				backchar=src[i];
				break;
			}
		}
		src[index++]=src[i];
	}
	src[index++]='\0';
}


bool getStringFromIndexWithDelim_body( char* src ,char* delim ,int index, char* buf , int buflen, char *file, int line );
#define getStringFromIndexWithDelim( src, delim, index, buf, buflen ) getStringFromIndexWithDelim_body( src, delim, index, buf, buflen, __FILE__, __LINE__ )

#define chomp(src)  dchop(src,"\n");


bool createdirectoryex( const char* lpszcreatepath )
{
	std::string ss1 = "mkdir -p "; ss1 += lpszcreatepath;
    system( ss1.c_str() );

	return true;
}



#endif
