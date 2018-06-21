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
///   File: context_interface.hpp
///
/// Author: $author$
///   Date: 6/11/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_SURFACE_CONTEXT_INTERFACE_HPP
#define _XOS_GRAPHIC_SURFACE_CONTEXT_INTERFACE_HPP

#include "xos/graphic/surface/pixel_interface.hpp"

namespace xos {
namespace graphic {
namespace surface {

///////////////////////////////////////////////////////////////////////
///  Class: context_interfacet
///////////////////////////////////////////////////////////////////////
template
<class TPixelInterface = pixel_interface,
 class TInterfaceBase = implement_base,
 class TImplements = TInterfaceBase>

class _EXPORT_CLASS context_interfacet: virtual public TImplements {
public:
    typedef TImplements implements;

    typedef TPixelInterface tPixelInterface;
    typedef TInterfaceBase tInterfaceBase;

    virtual eError fill_rectangle
    (tOffset x, tOffset y, tSize width, tSize height) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError fill_rectangle
    (tOffset x, tOffset y, tSize width, tSize height, const tPixelInterface& color) {
        eError error = e_ERROR_NONE;
        return error;
    }

    virtual eError set_foreground
    (tPixelInterface& oldColor, const tPixelInterface& toColor) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError set_foreground(const tPixelInterface& toColor) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual const tPixelInterface* foreground() const {
        const tPixelInterface* color = 0;
        return color;
    }

    virtual eError set_background
    (tPixelInterface& oldColor, const tPixelInterface& toColor) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError set_background(const tPixelInterface& toColor) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual const tPixelInterface* background() const {
        const tPixelInterface* color = 0;
        return color;
    }
};
typedef context_interfacet<> context_interface;

} /// namespace surface
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_SURFACE_CONTEXT_INTERFACE_HPP 
