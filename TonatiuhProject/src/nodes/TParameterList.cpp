/*
 * TParameterList.cpp
 *
 *  Created on: 07/09/2016
 *      Author: amutuberria
 */

#include "TParameterList.h"


/*!
 * Constructor
 */
TParameterList::TParameterList()
{
}


/*!
 * Destroys TParameter object
 */
TParameterList::~TParameterList()
{

}


/*!
 * Appends the given parameter. This function does not overwrites any existing ones.
 */
/*void TParameterList::Append(const TParameterList* list)
{
	Append( list->m_parametersList );
	list->m_parametersVisibilityList = m_parametersVisibilityList;
}
*/


/*!
 * Appends the given parameters, not overwriting any existing ones.
 */
/*void TParameterList::Append(const QHash<QString, QVariant>& list)
{
	foreach( const QString& k, list.keys() )
			Append(k, list[k]);
}
*/

/*!
 * Appends the parameter defined with the \a key and its \a value to the list.
 */
void TParameterList::Append(const QString& key, const QVariant& value, bool visibility )
{
	if( m_parametersList.contains( key ) )
		return;

	m_parametersList[key] = value;
	m_parametersVisibilityList[key] = visibility;
	//setProperty( key.toLatin1(), value );
}

/*!
 * Returns true if there is a parameter with the \a name in the list. Otherwise, returns false.
 */
bool TParameterList::Contains(const QString& name) const
{
	if( m_parametersList.contains( name ) )
		return ( true );

    return ( false );
}

/*!
 * Returns the value of the parameter \a name. If a parameter with defined name is not defined in the list, an empty string is returned.
 */
QVariant TParameterList::GetValue(const QString& name) const
{
  return ( GetValue(name, QVariant() ) );
}

/*!
 * Returns the value of the parameter \a name. If there is not a parameter with the name defined \a defaultValue is returned.
 */
QVariant TParameterList::GetValue(const QString& name, const QVariant& defaultValue) const
{
	if( Contains(name) )
		return ( m_parametersList.value(name) );
  else
    return ( defaultValue );
}

/*!
 * Returns if true if the parameter could be used externally to the node.
 * Otherwise return false.
 */
bool TParameterList::GetVisibility(const QString& name) const
{
	if( Contains(name) )
		return ( m_parametersVisibilityList.value(name) );
  else
    return ( false );

}

/*!
 * Returns a list with the name of the parameters.
 */
QStringList TParameterList::GetParametersNames() const
{
	return ( m_parametersList.keys() );
}


/*!
 * Returns the number of parameters in the list.
 */
int TParameterList::NumberOfParameters() const
{
	return ( m_parametersList.count() );
}

/*!
 * Removes the parameter with the name \a name from the parameter list.
 * Return false if the list does not contains a parameter with defined name or the parameter cannot be removed.
 */
bool TParameterList::RemoveParameter( const QString& name )
{
	if( !Contains( name ) )
			return ( false );

	if( ( m_parametersList.remove( name ) > 0 ) && ( m_parametersVisibilityList.remove( name ) ) )
			return ( true );
	return ( false );
}

/*!
 * Sets to the parameter \a name the \a value.
 */
void TParameterList::SetValue(const QString& name, QVariant value )
{
	if( Contains(name) )
		m_parametersList[name] = value;
}
