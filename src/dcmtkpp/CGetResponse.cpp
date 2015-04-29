/*************************************************************************
 * dcmtkpp - Copyright (C) Universite de Strasbourg
 * Distributed under the terms of the CeCILL-B license, as published by
 * the CEA-CNRS-INRIA. Refer to the LICENSE file or to
 * http://www.cecill.info/licences/Licence_CeCILL-B_V1-en.html
 * for details.
 ************************************************************************/


#include <string>

#include <dcmtk/config/osconfig.h>
#include <dcmtk/dcmdata/dcdeftag.h>
#include <dcmtk/dcmnet/dimse.h>
#include <dcmtk/ofstd/oftypes.h>

#include "dcmtkpp/CGetResponse.h"
#include "dcmtkpp/ElementAccessor.h"
#include "dcmtkpp/Exception.h"
#include "dcmtkpp/Response.h"

namespace dcmtkpp
{

CGetResponse
::CGetResponse(
    Uint16 message_id_being_responded_to, Uint16 status,
    DcmDataset const * dataset)
: Response(message_id_being_responded_to, status)
{
    this->set_command_field(DIMSE_C_GET_RSP);

    this->set_data_set(dataset);
}

CGetResponse
::CGetResponse(Message const & message)
: Response(message)
{
    if(message.get_command_field() != DIMSE_C_GET_RSP)
    {
        throw Exception("Message is not a C-GET-RSP");
    }
    this->set_command_field(message.get_command_field());
    
    DCMTKPP_MESSAGE_SET_OPTIONAL_FIELD_MACRO(
        message.get_command_set(), message_id, DCM_MessageID, EVR_US)
    DCMTKPP_MESSAGE_SET_OPTIONAL_FIELD_MACRO(
        message.get_command_set(), affected_sop_class_uid,
        DCM_AffectedSOPClassUID, EVR_UI)

    DCMTKPP_MESSAGE_SET_OPTIONAL_FIELD_MACRO(
        message.get_command_set(), number_of_remaining_sub_operations,
        DcmTagKey(0x0000, 0x1020), EVR_US)
    DCMTKPP_MESSAGE_SET_OPTIONAL_FIELD_MACRO(
        message.get_command_set(), number_of_completed_sub_operations,
        DcmTagKey(0x0000, 0x1021), EVR_US)
    DCMTKPP_MESSAGE_SET_OPTIONAL_FIELD_MACRO(
        message.get_command_set(), number_of_failed_sub_operations,
        DcmTagKey(0x0000, 0x1022), EVR_US)
    DCMTKPP_MESSAGE_SET_OPTIONAL_FIELD_MACRO(
        message.get_command_set(), number_of_warning_sub_operations,
        DcmTagKey(0x0000, 0x1023), EVR_US)

    this->set_data_set(message.get_data_set());
}

CGetResponse
::~CGetResponse()
{
    // Nothing to do.
}

}
