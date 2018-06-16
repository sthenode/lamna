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
///   File: midpoint_circle_image.hpp
///
/// Author: $author$
///   Date: 6/13/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_MIDPOINT_CIRCLE_IMAGE_HPP
#define _XOS_GRAPHIC_MIDPOINT_CIRCLE_IMAGE_HPP

#include "xos/graphic/midpoint_circle.hpp"
#include "xos/graphic/base_image.hpp"

namespace xos {
namespace graphic {

typedef midpoint_circlet
<base_image, image_interface> midpoint_circle_image_extends;
///////////////////////////////////////////////////////////////////////
///  Class: midpoint_circle_image
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS midpoint_circle_image: public midpoint_circle_image_extends {
public:
    typedef midpoint_circle_image_extends extends;

    midpoint_circle_image(tImageInterface& image): extends(image) {
    }

    virtual void plot_circle
    (tImageInterface &image, tInt cx,tInt cy, tInt r,
     eCircleOctant o = e_CIRCLE_OCTANT_ALL) {
        midpoint_circle_drawt<extends, tPixel, tInt>(*this, image, cx,cy,r, o);
    }
};

typedef filled_midpoint_circlet
<base_image, image_interface> filled_midpoint_circle_image_extends;
///////////////////////////////////////////////////////////////////////
///  Class: filled_midpoint_circle_image
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS filled_midpoint_circle_image
: public filled_midpoint_circle_image_extends {
public:
    typedef filled_midpoint_circle_image_extends extends;

    filled_midpoint_circle_image(tImageInterface& image): extends(image) {
    }

    virtual void plot_circle
    (tImageInterface &image, tInt cx,tInt cy, tInt r,
     eCircleOctant o = e_CIRCLE_OCTANT_ALL) {
        midpoint_circle_drawt<extends, tPixel, tInt>(*this, image, cx,cy,r, o);
    }
};

} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_MIDPOINT_CIRCLE_IMAGE_HPP 
