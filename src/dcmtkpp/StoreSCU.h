/*************************************************************************
 * dcmtkpp - Copyright (C) Universite de Strasbourg
 * Distributed under the terms of the CeCILL-B license, as published by
 * the CEA-CNRS-INRIA. Refer to the LICENSE file or to
 * http://www.cecill.info/licences/Licence_CeCILL-B_V1-en.html
 * for details.
 ************************************************************************/

#ifndef _1b2f876e_1ad2_464d_9423_28181320aed0
#define _1b2f876e_1ad2_464d_9423_28181320aed0


#include <dcmtk/config/osconfig.h>
#include <dcmtk/dcmdata/dcdatset.h>

#include "dcmtkpp/SCU.h"
#include "dcmtkpp_export.h"

namespace dcmtkpp
{

/// @brief SCU for C-Store services.
class DCMTKPP_EXPORT StoreSCU: public SCU
{
public:
    /// @brief Destructor.
    virtual ~StoreSCU();
    
    /// @brief Set the affected SOP class based on the dataset.
    void set_affected_sop_class(DcmDataset const * dataset);
    
    /// @brief Perform the C-STORE using an optional callback.
    void store(DcmDataset const * dataset, 
        ProgressCallback callback=NULL, void * data=NULL) const;
};

}

#endif // _1b2f876e_1ad2_464d_9423_28181320aed0
