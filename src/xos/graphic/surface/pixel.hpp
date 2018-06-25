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
<class TImplements = pixel_interface, class TExtends = base>

class _EXPORT_CLASS pixelt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    pixelt(tSize r, tSize g, tSize b, tSize a): r_(r), g_(g), b_(b), a_(a) {
    }
    pixelt(tSize r, tSize g, tSize b): r_(r), g_(g), b_(b), a_(0) {
    }
    pixelt(): r_(0), g_(0), b_(0), a_(0) {
    }
    virtual ~pixelt() {
    }
    
    virtual tSize red() const {
        return r_;
    }
    virtual tSize green() const {
        return g_;
    }
    virtual tSize blue() const {
        return b_;
    }
    virtual tSize alpha() const {
        return a_;
    }

protected:
    tSize r_, g_, b_, a_;
};
typedef pixelt<> pixel;

} /// namespace surface
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_SURFACE_PIXEL_HPP 
