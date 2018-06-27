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
///   File: shape.hpp
///
/// Author: $author$
///   Date: 6/13/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_SURFACE_QT_SHAPE_HPP
#define _XOS_GRAPHIC_SURFACE_QT_SHAPE_HPP

#include "xos/graphic/surface/qt/image.hpp"
#include "xos/graphic/surface/shape.hpp"

namespace xos {
namespace graphic {
namespace surface {
namespace qt {

///////////////////////////////////////////////////////////////////////
///  Class: shapet
///////////////////////////////////////////////////////////////////////
template
<class TQImageInterface = image_interface,
 class TImplements = graphic::shape_interface, class TExtends = surface::shape>

class _EXPORT_CLASS shapet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef TQImageInterface tQImageInterface;

    shapet(tQImageInterface& surfaceQImage)
    : extends(surfaceQImage), m_surfaceQImage(surfaceQImage) {
    }
    virtual ~shapet() {
    }

    virtual tQImageInterface& surfaceQImage() const {
        return (tQImageInterface&)m_surfaceQImage;
    }

protected:
    tQImageInterface& m_surfaceQImage;
};
typedef shapet<> shape;

} /// namespace qt
} /// namespace surface
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_SURFACE_QT_SHAPE_HPP 
