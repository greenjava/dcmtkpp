/*************************************************************************
 * dcmtkpp - Copyright (C) Universite de Strasbourg
 * Distributed under the terms of the CeCILL-B license, as published by
 * the CEA-CNRS-INRIA. Refer to the LICENSE file or to
 * http://www.cecill.info/licences/Licence_CeCILL-B_V1-en.html
 * for details.
 ************************************************************************/

#ifndef _dfa4858b_1c9d_4ce9_b220_a1c15d873602
#define _dfa4858b_1c9d_4ce9_b220_a1c15d873602

#include <functional>

#include <dcmtk/config/osconfig.h>
#include <dcmtk/dcmdata/dcelem.h>
#include <dcmtk/dcmdata/dcdatset.h>

#include "dcmtkpp/ElementTraits.h"
#include "dcmtkpp/Exception.h"
#include "dcmtkpp_export.h"

namespace dcmtkpp
{

/// @brief Generic access to values in DcmElement.
template<DcmEVR VR>
struct DCMTKPP_EXPORT ElementAccessor
{
    /// @brief C++ type of the VR.
    typedef typename ElementTraits<VR>::ValueType ValueType;

    /// @brief Getter type.
    typedef std::function<
        ValueType(DcmElement const &, unsigned long const)> GetterType;

    /// @brief Return the value in the element.
    static GetterType const element_get;

    /// @brief Setter type.
    typedef std::function<
        void(DcmElement &, ValueType const &, unsigned long const)> SetterType;

    /// @brief Set the value in the element.
    static SetterType const element_set;

    /// @brief Test whether the data set contains a given tag.
    static bool has(DcmDataset const & dataset, DcmTagKey const & tag)
    {
        DcmElement * dummy;
        OFCondition const condition =
            const_cast<DcmDataset&>(dataset).findAndGetElement(tag, dummy);
        if(condition.good())
        {
            return true;
        }
        else if(condition == EC_TagNotFound)
        {
            return false;
        }
        else
        {
            throw Exception(condition);
        }
    }

    /// @brief Return the value of an element in a dataset.
    static ValueType get(
        DcmDataset const & dataset,
        DcmTagKey const tag, unsigned int const position=0)
    {
        DcmElement * element;
        OFCondition const condition =
            const_cast<DcmDataset &>(dataset).findAndGetElement(tag, element);
        if(condition.bad())
        {
            throw Exception(condition);
        }
        return element_get(*element, position);
    }

    /// @brief Set the value of an element in a dataset.
    static void set(
        DcmDataset & dataset,
        DcmTagKey const tag, ValueType const & value, unsigned int const position=0)
    {
        DcmElement * element;
        OFCondition const get_condition = dataset.findAndGetElement(tag, element);
        if(get_condition.bad())
        {
            OFCondition const insert_condition = dataset.insertEmptyElement(tag);
            if(insert_condition.bad())
            {
                throw Exception(insert_condition);
            }
            OFCondition const new_get_condition =
                dataset.findAndGetElement(tag, element);
            if(new_get_condition.bad())
            {
                throw Exception(insert_condition);
            }
        }
        element_set(*element, value, position);
    }
};

}

#endif // _dfa4858b_1c9d_4ce9_b220_a1c15d873602
