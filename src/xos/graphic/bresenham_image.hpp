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
///   File: bresenham_image.hpp
///
/// Author: $author$
///   Date: 6/11/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_BRESENHAM_IMAGE_HPP
#define _XOS_GRAPHIC_BRESENHAM_IMAGE_HPP

#include "xos/graphic/bresenham_line.hpp"
#include "xos/graphic/base_image.hpp"

namespace xos {
namespace graphic {

typedef bresenham_linet
<base_image, image_interface> bresenham_line_image_extends;
///////////////////////////////////////////////////////////////////////
///  Class: bresenham_line_image
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS bresenham_line_image: public bresenham_line_image_extends {
public:
    typedef bresenham_line_image_extends extends;

    bresenham_line_image(tImageInterface& image): extends(image) {
    }
    virtual ~bresenham_line_image() {
    }

    virtual void draw_line
    (tImageInterface &image, tInt x1,tInt y1, tInt x2,tInt y2) {
        bresenham_line_drawt<Extends, tPixel, tInt>(*this, image, x1,y1, x2,y2);
    }
    virtual void draw_triangle
    (tImageInterface &image, tInt x1,tInt y1, tInt x2,tInt y2, tInt x3,tInt y3) {
        bresenham_line_drawt<Extends, tPixel, tInt>(*this, image, x1,y1, x2,y2);
        bresenham_line_drawt<Extends, tPixel, tInt>(*this, image, x2,y2, x3,y3);
        bresenham_line_drawt<Extends, tPixel, tInt>(*this, image, x3,y3, x1,y1);
    }
};

} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_BRESENHAM_IMAGE_HPP 
