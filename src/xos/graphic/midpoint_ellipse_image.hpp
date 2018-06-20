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
///   File: midpoint_ellipse_image.hpp
///
/// Author: $author$
///   Date: 6/16/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_MIDPOINT_ELLIPSE_IMAGE_HPP
#define _XOS_GRAPHIC_MIDPOINT_ELLIPSE_IMAGE_HPP

#include "xos/graphic/hollow_midpoint_ellipse.hpp"
#include "xos/graphic/midpoint_ellipse.hpp"
#include "xos/graphic/base_image.hpp"

namespace xos {
namespace graphic {

typedef midpoint_ellipset
<base_image, image_interface> midpoint_ellipse_image_extends;
///////////////////////////////////////////////////////////////////////
///  Class: midpoint_ellipse_image
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS midpoint_ellipse_image: public midpoint_ellipse_image_extends {
public:
    typedef midpoint_ellipse_image_extends extends;

    midpoint_ellipse_image(tImageInterface& image): extends(image) {
    }

    virtual void plot_ellipse
    (tImageInterface& image, tInt cx,tInt cy, tInt a,tInt b,
     eEllipseQuadrant q = e_ELLIPSE_QUADRANT_ALL) {
        midpoint_ellipse_drawt<extends, tPixel, tInt>(*this, image, cx,cy, a,b, q);
    }
    virtual void plot_circle
    (tImageInterface& image, tInt cx,tInt cy, tInt r,
     eEllipseQuadrant q = e_ELLIPSE_QUADRANT_ALL) {
        plot_ellipse(image, cx,cy, r,r, q);
    }
};

typedef filled_midpoint_ellipset
<midpoint_ellipse_image, image_interface> filled_midpoint_ellipse_image_extends;
///////////////////////////////////////////////////////////////////////
///  Class: filled_midpoint_ellipse_image
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS filled_midpoint_ellipse_image
: public filled_midpoint_ellipse_image_extends {
public:
    typedef filled_midpoint_ellipse_image_extends extends;

    filled_midpoint_ellipse_image(tImageInterface& image): extends(image) {
    }

    virtual void plot_ellipse
    (tImageInterface& image, tInt cx,tInt cy, tInt a,tInt b,
     eEllipseQuadrant q = e_ELLIPSE_QUADRANT_ALL) {
        midpoint_ellipse_drawt<extends, tPixel, tInt>(*this, image, cx,cy, a,b, q);
    }
    virtual void plot_circle
    (tImageInterface& image, tInt cx,tInt cy, tInt r,
     eEllipseQuadrant q = e_ELLIPSE_QUADRANT_ALL) {
        plot_ellipse(image, cx,cy, r,r, q);
    }
};

typedef hollow_midpoint_ellipset
<midpoint_ellipse_image, image_interface> hollow_midpoint_ellipse_image_extends;
///////////////////////////////////////////////////////////////////////
///  Class: hollow_midpoint_ellipse_image
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS hollow_midpoint_ellipse_image
: public hollow_midpoint_ellipse_image_extends {
public:
    typedef hollow_midpoint_ellipse_image_extends extends;

    hollow_midpoint_ellipse_image(tImageInterface& image): extends(image) {
    }

    virtual void plot_ellipse
    (tImageInterface& image, tInt cx,tInt cy, tInt a,tInt b,
     eEllipseQuadrant q = e_ELLIPSE_QUADRANT_ALL) {
        ellipse_start();
        midpoint_ellipse_drawt<extends, tPixel, tInt>(*this, image, cx,cy, a,b, q);
        ellipse_finish(image);
    }
    virtual void plot_circle
    (tImageInterface& image, tInt cx,tInt cy, tInt r,
     eEllipseQuadrant q = e_ELLIPSE_QUADRANT_ALL) {
        plot_ellipse(image, cx,cy, r,r, q);
    }
};

} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_MIDPOINT_ELLIPSE_IMAGE_HPP 
