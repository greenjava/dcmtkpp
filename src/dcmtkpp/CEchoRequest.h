/*************************************************************************
 * dcmtkpp - Copyright (C) Universite de Strasbourg
 * Distributed under the terms of the CeCILL-B license, as published by
 * the CEA-CNRS-INRIA. Refer to the LICENSE file or to
 * http://www.cecill.info/licences/Licence_CeCILL-B_V1-en.html
 * for details.
 ************************************************************************/

#ifndef _aec786b8_0074_4cb2_b9a1_4bf26bbd20fc
#define _aec786b8_0074_4cb2_b9a1_4bf26bbd20fc

#include <string>

#include <dcmtk/config/osconfig.h>
#include <dcmtk/ofstd/oftypes.h>

#include "dcmtkpp/Request.h"
#include "dcmtkpp_export.h"

namespace dcmtkpp
{

/// @brief C-ECHO-RQ message.
class DCMTKPP_EXPORT CEchoRequest: public Request
{
public:
    /**
     * @brief Create an echo request with given Message ID and
     * affected SOP class UID.
     */
    CEchoRequest(Uint16 message_id, std::string const & affected_sop_class_uid);

    /**
     * @brief Create a C-ECHO-RQ from a generic Message.
     *
     * Raise an exception if the Message does not contain a C-ECHO-RQ.
     */
    CEchoRequest(Message const & message);

    /// @brief Destructor.
    virtual ~CEchoRequest();
    
    DCMTKPP_MESSAGE_MANDATORY_FIELD_MACRO(
        affected_sop_class_uid, DCM_AffectedSOPClassUID, EVR_UI)
};

}

#endif // _aec786b8_0074_4cb2_b9a1_4bf26bbd20fc
