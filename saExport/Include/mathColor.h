#ifndef _MATHCOLOUR_H_
#define _MATHCOLOUR_H_


#include "mathBase.h"


namespace FOXSDK
{

	struct MathARBG
	{
		MathARBG()
		{
			a = 0;
			r = 0;
			g = 0;
			b = 0;
		}

		fubyte a;
		fubyte r;
		fubyte g;
		fubyte b;
	};


	struct MathColor
	{
		MathColor(void) :
		mAlpha( 1.0f ) ,
		mRed( 1.0f ) ,
		mGreen( 1.0f ) ,
		mBlue( 1.0f ) ,
		mARGB( 0xFFFFFFFF ) ,
		mValid( F_TRUE )
	{
	}


	MathColor( const MathColor& val )
	{
		this->operator=(val);
	}


	MathColor( freal32 alpha , freal32 red , freal32 green , freal32 blue ) :
	mAlpha(alpha),
		mRed(red),
		mGreen(green),
		mBlue(blue),
		mValid( F_FALSE )
	{
	}


	MathColor( fuint32 argb )
	{
		SetARGB(argb);
	}


	fuint32			GetARGB() const
	{
		if (!mValid)
		{
			mARGB = CalculateARGB();
			mValid = F_TRUE;
		}

		return mARGB;
	}

	freal32				GetAlpha(void) const	{return mAlpha;}
	freal32				GetRed(void) const		{return mRed;}
	freal32				GetGreen(void) const	{return mGreen;}
	freal32				GetBlue(void) const		{return mBlue;}

	freal32				GetHue(void) const
	{
		freal32 pRed = mRed;
		freal32 pGreen = mGreen;
		freal32 pBlue = mBlue;

		freal32 pMax = max(max(mRed, mGreen), mBlue);
		freal32 pMin = min(min(mRed, mGreen), mBlue);

		freal32 pHue;

		if( pMax == pMin )
		{
			pHue = 0;
		}
		else
		{
			if( pMax == pRed )
			{
				pHue = (pGreen - pBlue) / (pMax - pMin);
			}
			else if( pMax == pGreen )
			{
				pHue = 2 + (pBlue - pRed) / (pMax - pMin);
			}
			else
			{
				pHue = 4 + (pRed - pGreen) / (pMax - pMin);
			}
		}

		freal32 Hue = pHue / 6;

		if( Hue < 0 )
			Hue += 1;

		return Hue;
	}
	freal32				GetSaturation(void) const
	{
		freal32 pMax = max(max(mRed, mGreen), mBlue);
		freal32 pMin = min(min(mRed, mGreen), mBlue);

		freal32 pLum = (pMax + pMin) / 2;
		freal32 pSat;

		if( pMax == pMin )
		{
			pSat = 0;
		}
		else
		{
			if( pLum < 0.5 )
				pSat = (pMax - pMin) / (pMax + pMin);
			else
				pSat = (pMax - pMin) / (2 - pMax - pMin);
		}

		return pSat;
	}
	freal32				GetLumination(void) const
	{
		freal32 pMax = max(max(mRed, mGreen), mBlue);
		freal32 pMin = min(min(mRed, mGreen), mBlue);

		freal32 pLum = (pMax + pMin) / 2;
		return pLum;
	}

	fvoid				SetARGB( fuint32 argb )
	{
		mARGB = argb;

#ifdef __BIG_ENDIAN__
		mAlpha	= static_cast<freal32>(argb & 0xFF) / 255.0f;
		argb >>= 8;
		mRed	= static_cast<freal32>(argb & 0xFF) / 255.0f;
		argb >>= 8;
		mGreen	= static_cast<freal32>(argb & 0xFF) / 255.0f;
		argb >>= 8;
		mBlue	= static_cast<freal32>(argb & 0xFF) / 255.0f;
#else
		mBlue	= static_cast<freal32>(argb & 0xFF) / 255.0f;
		argb >>= 8;
		mGreen	= static_cast<freal32>(argb & 0xFF) / 255.0f;
		argb >>= 8;
		mRed	= static_cast<freal32>(argb & 0xFF) / 255.0f;
		argb >>= 8;
		mAlpha	= static_cast<freal32>(argb & 0xFF) / 255.0f;
#endif

		mValid = F_FALSE;
	}

	inline void			SetAlpha( freal32 alpha )
	{
		mValid = F_FALSE;
		mAlpha = alpha;
	}

	inline fvoid		SetRed( freal32 red )
	{   
		mValid = F_FALSE;
		mRed = red;
	}

	inline fvoid		SetGreen( freal32 green )
	{
		mValid = F_FALSE;
		mGreen = green;
	}

	inline fvoid		SetBlue( freal32 blue )
	{
		mValid = F_FALSE;
		mBlue = blue;
	}

	inline fvoid		Set( freal32 red , freal32 green , freal32 blue , freal32 alpha = 1.0f )
	{
		mValid = F_FALSE;
		mAlpha = alpha;
		mRed = red;
		mGreen = green;
		mBlue = blue;
	}

	inline fvoid		SetRGB( freal32 red , freal32 green , freal32 blue )
	{
		mValid = F_FALSE;
		mRed = red;
		mGreen = green;
		mBlue = blue;
	}

	inline fvoid		SetRGB( const MathColor& val )
	{
		mRed = val.mRed;
		mGreen = val.mGreen;
		mBlue = val.mBlue;

		if ( mValid )
		{
			mValid = val.mValid;

			if (mValid)
				mARGB = (mARGB & 0xFF000000) | (val.mARGB & 0x00FFFFFF);
		}
	}

	fvoid				SetHSL( freal32 alpha , freal32 hue , freal32 saturation , freal32 luminance )
	{
		mAlpha = alpha;

		freal32 temp3[3];

		freal32 pHue = hue;
		freal32 pSat = saturation;
		freal32 pLum = luminance;

		if( pSat == 0 )
		{
			mRed = pLum;
			mGreen = pLum;
			mBlue = pLum;
		}
		else
		{
			freal32 temp2;
			if( pLum < 0.5f )
			{
				temp2 = pLum * (1 + pSat);
			}
			else
			{
				temp2 = pLum + pSat - pLum * pSat;
			}

			freal32 temp1 = 2 * pLum - temp2;

			temp3[0] = pHue + (1.0f / 3);
			temp3[1] = pHue;
			temp3[2] = pHue - (1.0f / 3);

			for( int n = 0; n < 3; n ++ )
			{
				if( temp3[n] < 0 )
					temp3[n] ++;
				if( temp3[n] > 1 )
					temp3[n] --;

				if( (temp3[n] * 6) < 1 )
				{
					temp3[n] = temp1 + (temp2 - temp1) * 6 * temp3[n];
				}
				else
				{
					if( (temp3[n] * 2) < 1 )
					{
						temp3[n] = temp2;
					}
					else
					{
						if( (temp3[n] * 3) < 2 )
						{
							temp3[n] = temp1 + (temp2 - temp1) * ((2.0f / 3) - temp3[n]) * 6;
						}
						else
						{
							temp3[n] = temp1;
						}
					}
				}
			}

			mRed = temp3[0];
			mGreen = temp3[1];
			mBlue = temp3[2];
		}

		mValid = F_FALSE;
	}

	fvoid				InvertColour(void)
	{
		mRed	= 1.0f - mRed;
		mGreen	= 1.0f - mGreen;
		mBlue	= 1.0f - mBlue;
	}
	fvoid				InvertColourWithAlpha(void)
	{
		mAlpha	= 1.0f - mAlpha;
		mRed	= 1.0f - mRed;
		mGreen	= 1.0f - mGreen;
		mBlue	= 1.0f - mBlue;
	}


	inline MathColor& operator=( fuint32 val )
	{
		SetARGB( val );

		return *this;
	}

	inline MathColor& operator=( const MathColor& val )
	{
		mAlpha = val.mAlpha;
		mRed   = val.mRed;
		mGreen = val.mGreen;
		mBlue  = val.mBlue;
		mARGB  = val.mARGB;

		mValid = val.mValid;

		return *this;
	}

	inline MathColor& operator&=( fuint32 val )
	{
		SetARGB(GetARGB() & val);

		return *this;
	}

	inline MathColor& operator&=( const MathColor& val )
	{
		SetARGB( GetARGB() & val.GetARGB() );
		return *this;
	}

	inline MathColor& operator|=( fuint32 val )
	{
		SetARGB( GetARGB() | val );
		return *this;
	}

	inline MathColor& operator|=( const MathColor& val )
	{
		SetARGB( GetARGB() | val.GetARGB() );
		return *this;
	}

	inline MathColor& operator<<=( fint32 val )
	{
		SetARGB( GetARGB() << val );
		return *this;
	}

	inline MathColor& operator>>=( fint32 val )
	{
		SetARGB( GetARGB() >> val );
		return *this;
	}

	inline MathColor operator+( const MathColor& val ) const
	{
		return MathColor(
			mAlpha + val.mAlpha,
			mRed   + val.mRed, 
			mGreen + val.mGreen, 
			mBlue  + val.mBlue
			);
	}

	inline MathColor operator-( const MathColor& val ) const
	{
		return MathColor(
			mAlpha - val.mAlpha,
			mRed   - val.mRed,
			mGreen - val.mGreen,
			mBlue  - val.mBlue
			);
	}

	inline MathColor operator*( const freal32 val ) const
	{       
		return MathColor(
			mAlpha * val,
			mRed   * val,
			mGreen * val,
			mBlue  * val
			);  
	}

	inline MathColor& operator*=( const MathColor& val )
	{
		mAlpha *= val.mAlpha;
		mRed *= val.mRed;
		mBlue *= val.mBlue;
		mGreen *= val.mGreen;

		mValid = F_FALSE;

		return *this;
	}

	inline bool operator==( const MathColor& rhs ) const
	{
		return 	mAlpha == rhs.mAlpha &&
			mRed == rhs.mRed &&
			mGreen == rhs.mGreen &&
			mBlue == rhs.mBlue;
	}

	inline bool operator!=(const MathColor& rhs) const
	{
		return !(*this == rhs);
	}

	// Conversion operators
	operator fuint32() const		{return GetARGB();}

	private:

		// calculate and return the ARGB value based on the current colour component values.
		fuint32			CalculateARGB() const
		{
#ifdef __BIG_ENDIAN__
			return (
				static_cast<fuint32>(mBlue * 255) << 24 |
				static_cast<fuint32>(mGreen * 255) << 16 |
				static_cast<fuint32>(mRed * 255) << 8 |
				static_cast<fuint32>(mAlpha * 255)
				);
#else
			return (
				static_cast<fuint32>(mAlpha * 255) << 24 |
				static_cast<fuint32>(mRed * 255) << 16 |
				static_cast<fuint32>(mGreen * 255) << 8 |
				static_cast<fuint32>(mBlue * 255)
				);
#endif
		}

		// Color components.
		freal32 mAlpha , mRed , mGreen , mBlue;


		// Color as ARGB value.
		mutable fuint32		mARGB;


		// True if argb value is valid.
		mutable fbool		mValid;
	};

	class MathColorRect
	{
	public:

		MathColorRect() :
		  mTopLeft() , mTopRight() ,
			  mBottomLeft() , mBottomRight()
		  {

		  }


		  // via single colour.
		  MathColorRect( const MathColor& col ):
		  mTopLeft(col) , mTopRight(col) , 
			  mBottomLeft(col) , mBottomRight(col)
		  {

		  }


		  MathColorRect ( const MathColor& topleft , const MathColor& topright ,
			  const MathColor& bottomleft , const MathColor& bottomright ):
		  mTopLeft(topleft) , mTopRight(topright) ,
			  mBottomLeft(bottomleft) , mBottomRight(bottomright)
		  {

		  }


		  // Set the alpha value to use for all four corners of the ColorRect.
		  fvoid			SetAlpha( freal32 alpha )
		  {
			  mTopLeft.SetAlpha( alpha );
			  mTopRight.SetAlpha( alpha );
			  mBottomLeft.SetAlpha( alpha );
			  mBottomRight.SetAlpha( alpha );
		  }

		  fvoid			SetTopAlpha( freal32 alpha )
		  {
			  mTopLeft.SetAlpha( alpha );
			  mTopRight.SetAlpha( alpha );
		  }
		  fvoid			SetBottomAlpha( freal32 alpha )
		  {
			  mBottomLeft.SetAlpha( alpha );
			  mBottomRight.SetAlpha( alpha );
		  }
		  fvoid			SetLeftAlpha( freal32 alpha )
		  {
			  mTopLeft.SetAlpha( alpha );
			  mBottomLeft.SetAlpha( alpha );
		  }
		  fvoid			SetRightAlpha( freal32 alpha )
		  {
			  mTopRight.SetAlpha( alpha );
			  mBottomRight.SetAlpha( alpha );
		  }


		  MathColor		GetColorAtPoint( freal32 x , freal32 y ) const
		  {
			  MathColor h1( ( mTopRight - mTopLeft ) * x + mTopLeft );
			  MathColor h2( ( mBottomRight - mBottomLeft ) * x + mBottomLeft );

			  return MathColor((h2 - h1) * y + h1);
		  }

		  MathColorRect	GetSubRectangle( freal32 left , freal32 right , freal32 top , freal32 bottom ) const
		  {
			  return MathColorRect(
				  GetColorAtPoint( left , top ),
				  GetColorAtPoint( right , top ),
				  GetColorAtPoint( left , bottom ),
				  GetColorAtPoint( right , bottom )
				  );
		  }

		  // color that is to be set for all four corners of the ColorRect.
		  fvoid			SetColors( const MathColor& col )
		  {
			  mTopLeft = col;
			  mTopRight = col;
			  mBottomLeft = col;
			  mBottomRight = col;
		  }

		  MathColor		mTopLeft , mTopRight , mBottomLeft , mBottomRight;

	};



	const MathColor      MCWHITE( 1.0f , 1.0f , 1.0f , 1.0f );
	const MathColor      MCBLACK( 1.0f , 0.0f , 0.0f , 0.0f );
	const MathColor        MCRED( 1.0f , 1.0f , 0.0f , 0.0f );
	const MathColor      MCGREEN( 1.0f , 0.0f , 1.0f , 0.0f );
	const MathColor       MCBLUE( 1.0f , 0.0f , 0.0f , 1.0f );
	const MathColor     MCYELLOW( 1.0f , 1.0f , 1.0f , 0.0f );
	const MathColor       MCCYAN( 1.0f , 0.0f , 1.0f , 1.0f );
	const MathColor    MCMAGENTA( 1.0f , 1.0f , 0.0f , 1.0f );

}


#endif