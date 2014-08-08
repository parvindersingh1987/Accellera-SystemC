/*****************************************************************************

  The following code is derived, directly or indirectly, from the SystemC
  source code Copyright (c) 1996-2014 by all Contributors.
  All Rights reserved.

  The contents of this file are subject to the restrictions and limitations
  set forth in the SystemC Open Source License (the "License");
  You may not use this file except in compliance with such restrictions and
  limitations. You may obtain instructions on how to receive a copy of the
  License at http://www.accellera.org/. Software distributed by Contributors
  under the License is distributed on an "AS IS" basis, WITHOUT WARRANTY OF
  ANY KIND, either express or implied. See the License for the specific
  language governing rights and limitations under the License.

 *****************************************************************************/

/*****************************************************************************

  sc_buffer_edge_reset.cpp -- Test sc_buffer<bool> edge events and reset

  Original Author: Philipp A. Hartmann, OFFIS, 2013-10-12

 -----------------------------------------------------------------------------

 This test checks the functionality of the pos(), neg() event finders and
 the async_reset_signal_is functionality, if the target port is bound to
 an sc_buffer instead of an sc_signal.

 *****************************************************************************/

#define SC_INCLUDE_DYNAMIC_PROCESSES
#include <systemc.h>
#include <iomanip>

SC_MODULE(print_edge)
{
  sc_in<bool> in;

  SC_CTOR(print_edge)
    : in("in")
  {
    spawn_trigger( "trigger_val", &in.value_changed() );
    spawn_trigger( "trigger_pos", &in.pos() );
    spawn_trigger( "trigger_neg", &in.neg() );
    spawn_trigger( "trigger_rst", NULL );
  }

  void spawn_trigger( const char* name, sc_event_finder* ef )
  {
    sc_spawn_options opts;
      opts.spawn_method();
      opts.dont_initialize();
    if( ef ) {
      opts.set_sensitivity( ef );
    } else {
      opts.async_reset_signal_is( in, true );
    }
    sc_spawn( sc_bind(&print_edge::trigger,this)
            , name, &opts);
  }

  void trigger()
  {
    std::cout << sc_get_current_process_handle().name()
              << " @ " << std::setw(4) << sc_time_stamp() 
              << ": " << "in = " << in.read()
              << std::endl;
  }
};

int sc_main(int, char*[])
{
  sc_report_handler::set_actions( SC_ID_DISABLE_WILL_ORPHAN_PROCESS_
                                , SC_DO_NOTHING );

  sc_signal<int>  sig_int;

  sc_buffer<bool> buf;
  sc_signal<bool> sig;

  print_edge sig_mod("sig_mod");
    sig_mod.in(sig);

  print_edge buf_mod("buf_mod");
    buf_mod.in(buf);

  for(int i=0; i<4; ++i) {
    buf.write( !buf.read() );
    sig.write( !sig.read() );
    sc_start( 1, SC_NS );

    buf.write( buf.read() );
    sig.write( sig.read() );
    sc_start( 1, SC_NS );
  }

  return 0;
}