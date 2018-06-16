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
<class TShape = graphic::shape,
 class TImageInterface = image_interface,
 class TImageBaseInterface = image_base_interface,
 class TSelectedImage = graphic::image_interface,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TExtends = TShape>

class _EXPORT_CLASS shapet: public TExtends {
public:
    typedef TExtends extends;

    typedef TImageInterface tImageInterface;
    typedef TImageBaseInterface tImageBaseInterface;
    typedef TSelectedImage tSelectedImage;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    shapet
    (tImageInterface& surface_image,
     tSize width = 0, tSize height = 0)
    : extends(surface_image, width, height),
      surface_image_(surface_image) {
    }
    virtual ~shapet() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tSelectedImage* surface_select_image(tSelectedImage* image) {
        return surface_image_.select_image(image);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    tImageInterface& surface_image_;
};
typedef shapet<> shape;

} /// namespace surface
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_SURFACE_SHAPE_HPP 
