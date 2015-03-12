/*************************************************************************
 * dcmtkpp - Copyright (C) Universite de Strasbourg
 * Distributed under the terms of the CeCILL-B license, as published by
 * the CEA-CNRS-INRIA. Refer to the LICENSE file or to
 * http://www.cecill.info/licences/Licence_CeCILL-B_V1-en.html
 * for details.
 ************************************************************************/

#ifndef _ba1518e7_8123_46c9_81c0_65439717e40e
#define _ba1518e7_8123_46c9_81c0_65439717e40e

#include <stdint.h>
#include <string>
#include <utility>
#include <vector>

#include <dcmtk/config/osconfig.h>
#include <dcmtk/dcmdata/dcdatset.h>
#include <dcmtk/dcmnet/assoc.h>

#include "dcmtkpp/Association.h"
#include "dcmtkpp/Network.h"

namespace dcmtkpp
{

/**
 * @brief Base class for all SCU.
 */
class SCU
{
public:
    
    /// @brief Create a default, non-associated SCU.
    SCU();
    
    /// @brief Copy the other SCU. Associate if other is associated.
    SCU(SCU const & other);
    
    /// @brief Copy the other SCU. Associate if other is associated.
    SCU const & operator=(SCU const & other);
    
    /// @brief Destroy the SCU. Release the association if existing.
    virtual ~SCU();
    
    /// @brief Return the network used by the SCU.
    Network * get_network() const;
    /// @brief Set the network used by the SCU.
    void set_network(Network * network);
    
    /// @brief Return the association used by the SCU.
    Association * get_association() const;
    /// @brief Set the association used by the SCU.
    void set_association(Association * association);
    
    /// @brief Return the affected SOP class. Defaults to "".
    std::string const & get_affected_sop_class() const;
    /// @brief Set the affected SOP class
    void set_affected_sop_class(std::string const & sop_class);
    
    /// @brief Perform DICOM ping
    void echo() const;

protected:
    Network * _network;
    Association * _association;
    std::string _affected_sop_class;
};

}

#endif // _ba1518e7_8123_46c9_81c0_65439717e40e