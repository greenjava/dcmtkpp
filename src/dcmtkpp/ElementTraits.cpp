/*************************************************************************
 * dcmtkpp - Copyright (C) Universite de Strasbourg
 * Distributed under the terms of the CeCILL-B license, as published by
 * the CEA-CNRS-INRIA. Refer to the LICENSE file or to
 * http://www.cecill.info/licences/Licence_CeCILL-B_V1-en.html
 * for details.
 ************************************************************************/


#include <functional>
#include <string>

#include <dcmtk/config/osconfig.h>
#include <dcmtk/dcmdata/dcelem.h>
#include <dcmtk/dcmdata/dcvr.h>

#include "dcmtkpp/ElementTraits.h"
#include "dcmtkpp/Exception.h"

namespace dcmtkpp
{

OFCondition
getString(DcmElement & element, OFString & value, unsigned long const position)
{
    return element.getOFString(value, position);
}

OFCondition
getFloat64(DcmElement & element, Float64& value, unsigned long const position)
{
    return element.getFloat64(value, position);
}

OFCondition
getFloat32(DcmElement & element, Float32 & value, unsigned long const position)
{
    return element.getFloat32(value, position);
}

OFCondition
getSint32(DcmElement & element, Sint32 & value, unsigned long const position)
{
    return element.getSint32(value, position);
}

OFCondition
getSint16(DcmElement & element, Sint16 & value, unsigned long const position)
{
    return element.getSint16(value, position);
}

OFCondition
getUint32(DcmElement & element, Uint32 & value, unsigned long const position)
{
    return element.getUint32(value, position);
}

OFCondition
getUint16(DcmElement & element, Uint16 & value, unsigned long const position)
{
    return element.getUint16(value, position);
}


OFCondition
putString(DcmElement & element, OFString const value, unsigned long const position)
{
    if(position != 0)
    {
        throw Exception("Position must be 0");
    }
    return element.putOFStringArray(value);
}

OFCondition
putFloat64(DcmElement & element, Float64 const value, unsigned long const position)
{
    if(position != 0)
    {
        throw Exception("Position must be 0");
    }
    return element.putFloat64(value);
}

OFCondition
putFloat32(DcmElement & element, Float32 const value, unsigned long const position)
{
    if(position != 0)
    {
        throw Exception("Position must be 0");
    }
    return element.putFloat32(value);
}

OFCondition
putSint32(DcmElement & element, Sint32 const value, unsigned long const position)
{
    if(position != 0)
    {
        throw Exception("Position must be 0");
    }
    return element.putSint32(value);
}

OFCondition
putSint16(DcmElement & element, Sint16 const value, unsigned long const position)
{
    if(position != 0)
    {
        throw Exception("Position must be 0");
    }
    return element.putSint16(value);
}

OFCondition
putUint32(DcmElement & element, Uint32 const value, unsigned long const position)
{
    if(position != 0)
    {
        throw Exception("Position must be 0");
    }
    return element.putUint32(value);
}

OFCondition
putUint16(DcmElement & element, Uint16 const value, unsigned long const position)
{
    if(position != 0)
    {
        throw Exception("Position must be 0");
    }
    return element.putUint16(value);
}



#define DEFINE_ELEMENT_TRAITS(vr, getter_, setter_) \
ElementTraits<vr>::GetterType const ElementTraits<vr>::getter = getter_; \
ElementTraits<vr>::SetterType const ElementTraits<vr>::setter = setter_;

DEFINE_ELEMENT_TRAITS(EVR_AE, getString, putString)
DEFINE_ELEMENT_TRAITS(EVR_AS, getString, putString)
//DEFINE_ELEMENT_TRAITS(EVR_AT
DEFINE_ELEMENT_TRAITS(EVR_CS, getString, putString)
DEFINE_ELEMENT_TRAITS(EVR_DA, getString, putString)
DEFINE_ELEMENT_TRAITS(EVR_DS, getFloat64, putFloat64)
DEFINE_ELEMENT_TRAITS(EVR_DT, getString, putString)
DEFINE_ELEMENT_TRAITS(EVR_FD, getFloat64, putFloat64)
DEFINE_ELEMENT_TRAITS(EVR_FL, getFloat32, putFloat32)
DEFINE_ELEMENT_TRAITS(EVR_IS, getSint32, putSint32)
DEFINE_ELEMENT_TRAITS(EVR_LO, getString, putString)
DEFINE_ELEMENT_TRAITS(EVR_LT, getString, putString)
//DEFINE_ELEMENT_TRAITS(EVR_OB
//DEFINE_ELEMENT_TRAITS(EVR_OF
//DEFINE_ELEMENT_TRAITS(EVR_OW
DEFINE_ELEMENT_TRAITS(EVR_PN, getString, putString)
DEFINE_ELEMENT_TRAITS(EVR_SH, getString, putString)
DEFINE_ELEMENT_TRAITS(EVR_SL, getSint32, putSint32)
//DEFINE_ELEMENT_TRAITS(EVR_SQ
DEFINE_ELEMENT_TRAITS(EVR_SS, getSint16, putSint16)
DEFINE_ELEMENT_TRAITS(EVR_ST, getString, putString)
DEFINE_ELEMENT_TRAITS(EVR_TM, getString, putString)
DEFINE_ELEMENT_TRAITS(EVR_UI, getString, putString)
DEFINE_ELEMENT_TRAITS(EVR_UL, getUint32, putUint32)
//DEFINE_ELEMENT_TRAITS(EVR_UN
DEFINE_ELEMENT_TRAITS(EVR_US, getUint16, putUint16)
DEFINE_ELEMENT_TRAITS(EVR_UT, getString, putString)

#undef DEFINE_ELEMENT_TRAITS

}
