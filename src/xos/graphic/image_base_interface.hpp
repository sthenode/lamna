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
///   File: image_base_interface.hpp
///
/// Author: $author$
///   Date: 6/11/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_BASE_INTERFACE_HPP
#define _XOS_GRAPHIC_IMAGE_BASE_INTERFACE_HPP

#include "xos/graphic/base.hpp"

namespace xos {
namespace graphic {

///////////////////////////////////////////////////////////////////////
///  Class: image_base_interfacet
///////////////////////////////////////////////////////////////////////
template
<class TInterfaceBase = implement_base,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TImplements = TInterfaceBase>

class _EXPORT_CLASS image_base_interfacet: virtual public TImplements {
public:
    typedef TImplements implements;

    typedef image_base_interfacet tImageBaseInterface;
    typedef TInterfaceBase tInterfaceBase;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError plot
    (tImageBaseInterface& pixel, tOffset x,tOffset y) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError fill
    (tImageBaseInterface& pixel, tOffset x,tOffset y, tSize w,tSize h) {
        eError error = e_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError fill_ellipse
    (tImageBaseInterface& pixel, tOffset x,tOffset y,
     tSize w,tSize h, eQuadrant quadrant=e_QUADRANT_ALL) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError fill_ellipse_rectangle
    (tImageBaseInterface& pixel, tOffset x,tOffset y,
     tSize w,tSize h, eQuadrant quadrant=e_QUADRANT_ALL) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError hollow_ellipse
    (tImageBaseInterface& pixel, tOffset x,tOffset y,
     tSize w,tSize h, eQuadrant quadrant=e_QUADRANT_ALL) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError hollow_ellipse_rectangle
    (tImageBaseInterface& pixel, tOffset x,tOffset y,
     tSize w,tSize h, eQuadrant quadrant=e_QUADRANT_ALL) {
        eError error = e_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError fill_circle
    (tImageBaseInterface& pixel, tOffset x,tOffset y,
     tSize r, eQuadrant quadrant=e_QUADRANT_ALL) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError hollow_circle
    (tImageBaseInterface& pixel, tOffset x,tOffset y,
     tSize r, eQuadrant quadrant=e_QUADRANT_ALL) {
        eError error = e_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError fill_triangle
    (tImageBaseInterface& pixel,
     tOffset x1, tOffset y1, tOffset x2, tOffset y2, tOffset x3, tOffset y3) {
        eError error = e_ERROR_NONE;
        return error;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef image_base_interfacet<> image_base_interface;

} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_BASE_INTERFACE_HPP 
