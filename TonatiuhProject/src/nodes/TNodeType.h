/***************************************************************************
Copyright (C) 2008 by the Tonatiuh Software Development Team.

This file is part of Tonatiuh.

Tonatiuh program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.


Acknowledgments:

The development of Tonatiuh was started on 2004 by Dr. Manuel J. Blanco,
then Chair of the Department of Engineering of the University of Texas at
Brownsville. From May 2004 to July 2008, it was supported by the Department
of Energy (DOE) and the National Renewable Energy Laboratory (NREL) under
the Minority Research Associate (MURA) Program Subcontract ACQ-4-33623-06.
During 2007, NREL also contributed to the validation of Tonatiuh under the
framework of the Memorandum of Understanding signed with the Spanish
National Renewable Energy Centre (CENER) on February, 20, 2007 (MOU#NREL-07-117).
Since June 2006, the development of Tonatiuh is being led by the CENER, under the
direction of Dr. Blanco, now Director of CENER Solar Thermal Energy Department.

Developers: Manuel J. Blanco (mblanco@cener.com), Amaia Mutuberria, Victor Martin.

Contributors: Javier Garcia-Barberena, Inaki Perez, Inigo Pagola,  Gilda Jimenez,
Juana Amieva, Azael Mancillas, Cesar Cantu.
***************************************************************************/

#ifndef TNODETYPE_H_
#define TNODETYPE_H_

#include <memory>
#include <string>
#include <vector>

#include "NodeLibrary.h"

struct TTypeData;
struct TNode;


//! TNodeType class is the class to describe type of the node.
/*!
*  TNodeType class specifies the type of the node and could give information if it is a derived type of return the type of a parent.
*  Constructor method of object of the nodes could also be obtained from the type.
*
*  The static member \a m_typeList stores a list of all available types. The types are unique and cannot be duplicated.
*/

class  NODE_API TNodeType
{

public:
	typedef std::shared_ptr< TNode > (*ConstructorMethod)();

	static bool Contains(const std::string& name);
	static const TNodeType CreateEmptyType();
	static const TNodeType CreateType(const TNodeType parent, const std::string name,
	        const ConstructorMethod method = 0 );
	static TNodeType FromName( const std::string name );

	std::string GetName() const;
	const TNodeType GetParent() const;

	//static void Init();
	bool IsDerivedFrom(const TNodeType type) const;
	bool IsValid() const;

	std::shared_ptr< TNode > NodeFromType() const;

	bool operator==( const TNodeType type );


private:
  int m_index;
  //static std::vector< std::unique_ptr< TTypeData > > m_typeList;
  static std::vector< TTypeData > m_typeList;

};


#endif /* TNODETYPE_H_ */
