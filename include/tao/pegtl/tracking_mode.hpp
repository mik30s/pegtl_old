// Copyright (c) 2017 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/PEGTL/

#ifndef TAOCPP_PEGTL_INCLUDE_TRACKING_MODE_HPP
#define TAOCPP_PEGTL_INCLUDE_TRACKING_MODE_HPP

#include "config.hpp"

namespace tao
{
   namespace pegtl
   {
      enum class tracking_mode : bool
      {
         IMMEDIATE,
         LAZY
      };

   }  // namespace pegtl

}  // namespace tao

#endif
