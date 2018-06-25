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
#ifndef _XOS_GRAPHIC_SURFACE_SHAPE_HPP
#define _XOS_GRAPHIC_SURFACE_SHAPE_HPP

#include "xos/graphic/surface/image.hpp"
#include "xos/graphic/shape.hpp"

namespace xos {
namespace graphic {
namespace surface {

///////////////////////////////////////////////////////////////////////
///  Class: shapet
///////////////////////////////////////////////////////////////////////
template
<class TSurfaceImageInterface = image_interface,
 class TImageInterface = graphic::image_interface,
 class TImplements = graphic::shape_interface,
 class TExtends = graphic::shape>

class _EXPORT_CLASS shapet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef TSurfaceImageInterface tSurfaceImageInterface;
    typedef TImageInterface tImageInterface;

    shapet
    (tSurfaceImageInterface& surface_image,
     tSize width = 0, tSize height = 0)
    : extends(surface_image, width, height),
      surface_image_(surface_image) {
    }
    virtual ~shapet() {
    }

protected:
    virtual tImageInterface* surface_select_image(tImageInterface* image) {
        return surface_image_.select_image(image);
    }

protected:
    tSurfaceImageInterface& surface_image_;
};
typedef shapet<> shape;

} /// namespace surface
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_SURFACE_SHAPE_HPP 
