///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: pixel.hpp
///
/// Author: $author$
///   Date: 6/11/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_SURFACE_PIXEL_HPP
#define _XOS_GRAPHIC_SURFACE_PIXEL_HPP

#include "xos/graphic/surface/pixel_interface.hpp"

namespace xos {
namespace graphic {
namespace surface {

///////////////////////////////////////////////////////////////////////
///  Class: pixelt
///////////////////////////////////////////////////////////////////////
template
<class TInterfaceBase = pixel_interface,
 class TBase = base,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 TSize VRGBAxisSize = 256,
 class TImplements = TInterfaceBase, class TExtends = TBase>

class _EXPORT_CLASS pixelt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef TInterfaceBase tInterfaceBase;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    pixelt(tSize r, tSize g, tSize b, tSize a) {
    }
    pixelt(tSize r, tSize g, tSize b) {
    }
    pixelt() {
    }
    virtual ~pixelt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef pixelt<> pixel;

} /// namespace surface
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_SURFACE_PIXEL_HPP 
