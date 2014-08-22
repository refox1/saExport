#ifndef _MATHBOUNDING_H_
#define _MATHBOUNDING_H_

#include "mathBase.h"


namespace FOXSDK
{

	// Bounding Objects

	struct MathBoundingBox
	{
		MathBoundingBox()
		{

		}

		MathBoundingBox( MathVector3 min , MathVector3 max )
		{
			this->min = min;
			this->max = max;
		}

		fbool			IsPointInside( const MathVector3& p )
		{
			if( p.x >= min.x && p.y >= min.y && p.z >= min.z &&
				p.x <= max.x && p.y <= max.y && p.z <= max.z )
			{
				return F_TRUE;
			}
			else
			{
				return F_FALSE;
			}
		}

		MathVector3 min , max;
	};


	struct MathBoundingSphere
	{
		MathBoundingSphere()
		{

		}
		
		MathBoundingSphere( MathVector3 center , freal32 radius )
		{
			this->center = center;
			this->radius = radius;
		}

		fbool			IsPointInside( const MathVector3& p )
		{
			if( radius * radius >= ( (p.x - center.x) * (p.x - center.x) +
								(p.y - center.y) * (p.y - center.y) + 
								(p.z - center.z) * (p.z - center.z) ) )
			{
				return F_TRUE;
			}
			else
			{
				return F_FALSE;
			}
		}
		
		MathVector3 center;
		freal32		radius;
	};


};


#endif

