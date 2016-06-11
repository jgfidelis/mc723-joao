//////////////////////////////////////////////////////////////////////////////
// Standard includes
// SystemC includes
// ArchC includes

#include "ac_tlm_router.h"

//////////////////////////////////////////////////////////////////////////////

/// Namespace to isolate memory from ArchC
using user::ac_tlm_router;

/// Constructor
ac_tlm_router::ac_tlm_router( sc_module_name module_name ) :
  sc_module( module_name ),
  target_export("iport"),
  MEM_port("MEM_port", 104857600U), //100 M
  PERIPHERAL_port("PERIPHERAL_port",4U) // 4 B
{
    /// Binds target_export to the memory
    target_export( *this );
}

ac_tlm_rsp ac_tlm_router::transport( const ac_tlm_req &request ) {

	if((request.addr < 100*1024*1024))
	{
		return MEM_port->transport(request);
	}else{
		return PERIPHERAL_port->transport(request);
	}

}

/// Destructor
ac_tlm_router::~ac_tlm_router() {
}
