/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(BOOST_FUSION_SUPPORT_UNUSED_20070305_1038)
#define BOOST_FUSION_SUPPORT_UNUSED_20070305_1038

#include <boost/config.hpp>
#if defined(BOOST_MSVC)
# pragma warning(push)
# pragma warning(disable: 4522) // multiple assignment operators specified warning
#endif

#define BOOST_FUSION_UNUSED_HAS_IO

namespace boost { namespace fusion
{
    struct unused_type
    {
        unused_type()
        {
        }

        template <typename T>
        unused_type(T const&)
        {
        }

        template <typename T>
        unused_type const&
        operator=(T const&) const
        {
            return *this;
        }

        template <typename T>
        unused_type&
        operator=(T const&)
        {
            return *this;
        }

        unused_type const&
        operator=(unused_type const&) const
        {
            return *this;
        }

        unused_type&
        operator=(unused_type const&)
        {
            return *this;
        }
    };

    unused_type const unused = unused_type();

    template <typename Out>
    inline Out& operator<<(Out& out, unused_type const&)
    {
        return out;
    }

    template <typename Out>
    inline Out& operator>>(Out& out, unused_type&)
    {
        return out;
    }
}}

#if defined(BOOST_MSVC)
# pragma warning(pop)
#endif

#endif
