// Copyright (c) 2014-2017 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/PEGTL/

#ifndef TAOCPP_PEGTL_INCLUDE_INTERNAL_REP_OPT_HH
#define TAOCPP_PEGTL_INCLUDE_INTERNAL_REP_OPT_HH

#include "../config.hh"

#include "skip_control.hh"
#include "duseltronik.hh"
#include "seq.hh"

#include "../apply_mode.hh"
#include "../rewind_mode.hh"

#include "../analysis/generic.hh"

namespace TAOCPP_PEGTL_NAMESPACE
{
   namespace internal
   {
      template< unsigned Max, typename ... Rules >
      struct rep_opt
      {
         using analyze_t = analysis::generic< analysis::rule_type::OPT, Rules ... >;

         template< apply_mode A, rewind_mode, template< typename ... > class Action, template< typename ... > class Control, typename Input, typename ... States >
         static bool match( Input & in, States && ... st )
         {
            for ( unsigned i = 0; ( i != Max ) && duseltronik< seq< Rules ... >, A, rewind_mode::REQUIRED, Action, Control >::match( in, st ... ); ++i ) {}
            return true;
         }
      };

      template< unsigned Max, typename ... Rules >
      struct skip_control< rep_opt< Max, Rules ... > > : std::true_type {};

   } // namespace internal

} // namespace TAOCPP_PEGTL_NAMESPACE

#endif