/*************************************************************************
 * dcmtkpp - Copyright (C) Universite de Strasbourg
 * Distributed under the terms of the CeCILL-B license, as published by
 * the CEA-CNRS-INRIA. Refer to the LICENSE file or to
 * http://www.cecill.info/licences/Licence_CeCILL-B_V1-en.html
 * for details.
 ************************************************************************/

#ifndef _8ac39caa_b7b1_44a8_82fc_e8e3de18b2f8
#define _8ac39caa_b7b1_44a8_82fc_e8e3de18b2f8


#include <functional>
#include <utility>

#include <dcmtk/config/osconfig.h>
#include <dcmtk/dcmdata/dcdatset.h>
#include <dcmtk/dcmnet/assoc.h>

#include "dcmtkpp/Association.h"
#include "dcmtkpp/Message.h"
#include "dcmtkpp/Network.h"
#include "dcmtkpp/ServiceRole.h"

namespace dcmtkpp
{

template<typename TMessage>
TMessage
ServiceRole
::_receive(ProgressCallback callback, void* callback_data) const
{
    Message const message = this->_receive(callback, callback_data);
    return TMessage(message);
}

}

#endif // _8ac39caa_b7b1_44a8_82fc_e8e3de18b2f8
