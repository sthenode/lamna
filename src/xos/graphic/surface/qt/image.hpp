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
///   File: image.hpp
///
/// Author: $author$
///   Date: 6/13/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_SURFACE_QT_IMAGE_HPP
#define _XOS_GRAPHIC_SURFACE_QT_IMAGE_HPP

#include "xos/graphic/surface/qt/context.hpp"
#include "xos/graphic/surface/image.hpp"

namespace xos {
namespace graphic {
namespace surface {
namespace qt {

///////////////////////////////////////////////////////////////////////
///  Class: image_interfacet
///////////////////////////////////////////////////////////////////////
template
<class TQContextInterface = context_interface,
 class TImageInterface = surface::image_interface,
 class TImplements = TImageInterface>

class _EXPORT_CLASS image_interfacet: virtual public TImplements {
public:
    typedef TImplements implements;

    typedef TQContextInterface tQContextInterface;
    typedef TImageInterface tImageInterface;

    virtual tQContextInterface& surfaceQContext() const = 0;
};
typedef image_interfacet<> image_interface;

///////////////////////////////////////////////////////////////////////
///  Class: imaget
///////////////////////////////////////////////////////////////////////
template
<class TQImageInterface = image_interface,
 class TImage = surface::image,
 class TQContextInterface = context_interface,
 class TImplements = TQImageInterface, class TExtends = TImage>

class _EXPORT_CLASS imaget: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef TQImageInterface tQImageInterface;
    typedef TQContextInterface tQContextInterface;

    imaget
    (tQContextInterface& surfaceQContext, tQImageInterface* image = 0)
    : extends(surfaceQContext, image), m_surfaceQContext(surfaceQContext) {
    }
    virtual ~imaget() {
    }

    virtual tQContextInterface& surfaceQContext() const {
        return (tQContextInterface&)m_surfaceQContext;
    }

protected:
    tQContextInterface& m_surfaceQContext;
};
typedef imaget<> image;

} /// namespace qt
} /// namespace surface
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_SURFACE_QT_IMAGE_HPP 
