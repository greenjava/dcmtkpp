/*************************************************************************
 * dcmtkpp - Copyright (C) Universite de Strasbourg
 * Distributed under the terms of the CeCILL-B license, as published by
 * the CEA-CNRS-INRIA. Refer to the LICENSE file or to
 * http://www.cecill.info/licences/Licence_CeCILL-B_V1-en.html
 * for details.
 ************************************************************************/

#ifndef _f4680d8c_18a8_4317_956d_3ae238cb39cc
#define _f4680d8c_18a8_4317_956d_3ae238cb39cc

#include "dcmtkpp/CEchoRequest.h"
#include "dcmtkpp/ServiceRole.h"
#include "dcmtkpp_export.h"

namespace dcmtkpp
{

/// @brief Base class for all Service Class Providers.
class DCMTKPP_EXPORT SCP: public ServiceRole
{
public:
    SCP();
    virtual ~SCP();
protected:
    /// @brief Send a C-ECHO response.
    void _send_echo_response(CEchoRequest const & request) const;
};

}

#endif // _f4680d8c_18a8_4317_956d_3ae238cb39cc
