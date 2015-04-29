/*************************************************************************
 * dcmtkpp - Copyright (C) Universite de Strasbourg
 * Distributed under the terms of the CeCILL-B license, as published by
 * the CEA-CNRS-INRIA. Refer to the LICENSE file or to
 * http://www.cecill.info/licences/Licence_CeCILL-B_V1-en.html
 * for details.
 ************************************************************************/

#ifndef _ba1518e7_8123_46c9_81c0_65439717e40e
#define _ba1518e7_8123_46c9_81c0_65439717e40e

#include <string>

#include "dcmtkpp/ServiceRole.h"
#include "dcmtkpp_export.h"

namespace dcmtkpp
{

/// @brief Base class for all Service Class Users.
class DCMTKPP_EXPORT SCU: public ServiceRole
{
public:
    SCU();
    ~SCU();
    
    /// @brief Return the affected SOP class. Defaults to "".
    std::string const & get_affected_sop_class() const;
    /// @brief Set the affected SOP class
    void set_affected_sop_class(std::string const & sop_class);
    
    /// @brief Perform DICOM ping
    void echo() const;

protected:
    /// @brief Affected SOP class.
    std::string _affected_sop_class;
};

}

#endif // _ba1518e7_8123_46c9_81c0_65439717e40e
