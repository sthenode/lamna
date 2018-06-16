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
///   File: image_interface.hpp
///
/// Author: $author$
///   Date: 6/12/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_SURFACE_IMAGE_INTERFACE_HPP
#define _XOS_GRAPHIC_SURFACE_IMAGE_INTERFACE_HPP

#include "xos/graphic/surface/context.hpp"
#include "xos/graphic/image.hpp"

namespace xos {
namespace graphic {
namespace surface {

///////////////////////////////////////////////////////////////////////
///  Class: image_interfacet
///////////////////////////////////////////////////////////////////////
template
<class TContextInterface = context_interface,
 class TImageInterface = image_interface,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TImplements = TImageInterface>

class _EXPORT_CLASS image_interfacet: virtual public TImplements {
public:
    typedef TImplements implements;

    typedef TContextInterface tContextInterface;
    typedef TImageInterface tImageInterface;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    virtual tContextInterface& context_interface() const = 0;
};
typedef image_interfacet<> image_interface;

} /// namespace surface
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_SURFACE_IMAGE_INTERFACE_HPP 
