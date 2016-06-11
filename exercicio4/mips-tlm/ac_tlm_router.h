//////////////////////////////////////////////////////////////////////////////

#ifndef AC_TLM_ROUTER_H_
#define AC_TLM_ROUTER_H_

//////////////////////////////////////////////////////////////////////////////

// Standard includes
// SystemC includes
#include <systemc>
// ArchC includes
#include "ac_tlm_protocol.H"
#include <ac_tlm_port.H>

//////////////////////////////////////////////////////////////////////////////

// using statements
using tlm::tlm_transport_if;

//////////////////////////////////////////////////////////////////////////////

//#define DEBUG

/// Namespace to isolate memory from ArchC
namespace user
{

/// A TLM memory
class ac_tlm_router :
  public sc_module,
  public ac_tlm_transport_if // Using ArchC TLM protocol
{
public:
  /// Exposed port with ArchC interface
  sc_export< ac_tlm_transport_if > target_export;
  ac_tlm_port MEM_port;
  ac_tlm_port PERIPHERAL_port;
  /**
   * Default constructor.
   *
   */
  ac_tlm_router( sc_module_name module_name );

  /**
   * Default destructor.
   */
  ~ac_tlm_router();


  /**
  * Implementation of TLM transport method that
  * handle packets of the protocol doing apropriate actions.
  * This method must be implemented (required by SystemC TLM).
  * @param request is a received request packet
  * @return A response packet to be send
  */
  ac_tlm_rsp transport( const ac_tlm_req &request );

private:
};

};

#endif //AC_TLM_ROUTER_H_
