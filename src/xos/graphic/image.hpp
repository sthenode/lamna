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
///   Date: 6/11/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_HPP
#define _XOS_GRAPHIC_IMAGE_HPP

#include "xos/graphic/image_interface.hpp"
#include "xos/graphic/bresenham_image.hpp"
#include "xos/graphic/midpoint_circle_image.hpp"
#include "xos/graphic/midpoint_ellipse_image.hpp"

namespace xos {
namespace graphic {

///////////////////////////////////////////////////////////////////////
///  Class: imaget
///////////////////////////////////////////////////////////////////////
template
<class TImplements = image_interface, class TExtends = base>

class _EXPORT_CLASS imaget: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef implements tImageInterface;

    imaget(tImageInterface* image = 0): image_(image) {
    }
    virtual ~imaget() {
    }

    virtual eError plot(tImageInterface& image, tOffset x, tOffset y) {
        eError error = image.plot(x,y);
        return error;
    }
    virtual eError fill
    (tImageInterface& image, tOffset x, tOffset y, tSize w, tSize h) {
        eError error = image.fill(x,y, w,h);
        return error;
    }

    virtual eError plot(tOffset x, tOffset y) {
        eError error = e_ERROR_NONE;
        tImageInterface* image = 0;
        if ((image = this->image())) {
            error = image->plot(x, y);
        }
        return error;
    }
    virtual eError fill(tOffset x, tOffset y, tSize w, tSize h) {
        eError error = e_ERROR_NONE;
        tImageInterface* image = 0;
        if ((image = this->image())) {
            error = image->fill(x,y, w,h);
        }
        return error;
    }
    virtual eError draw(tOffset x, tOffset y, tOffset x2, tOffset y2) {
        eError error = e_ERROR_NONE;
        tImageInterface* image = 0;
        if ((image = this->image())) {
            bresenham_line_image line(*image);
            line.draw_line(*image, x,y, x2,y2);
        }
        return error;
    }

    virtual eError draw_circle
    (tOffset x, tOffset y, tSize r, eOctant o = e_OCTANT_ALL) {
        eError error = e_ERROR_NONE;
        tImageInterface* image = 0;
        if ((image = this->image())) {
            midpoint_circle_image circle(*image);
            circle.plot_circle(*image, x,y, r, o);
        }
        return error;
    }
    virtual eError fill_circle
    (tOffset x, tOffset y, tSize r, eOctant o = e_OCTANT_ALL) {
        eError error = e_ERROR_NONE;
        tImageInterface* image = 0;
        if ((image = this->image())) {
            filled_midpoint_circle_image circle(*image);
            circle.plot_circle(*image, x,y, r, o);
        }
        return error;
    }
    virtual eError hollow_circle
    (tOffset x, tOffset y, tSize r, eOctant o = e_OCTANT_ALL) {
        eError error = e_ERROR_NONE;
        tImageInterface* image = 0;
        if ((image = this->image())) {
            hollow_midpoint_circle_image circle(*image);
            circle.plot_circle(*image, x,y, r, o);
        }
        return error;
    }

    virtual eError draw_ellipse
    (tOffset x, tOffset y, tSize w, tSize h, eQuadrant q = e_QUADRANT_ALL) {
        eError error = e_ERROR_NONE;
        tImageInterface* image = 0;
        if ((image = this->image())) {
            midpoint_ellipse_image ellipse(*image);
            ellipse.plot_ellipse(*image, x,y, w,h, q);
        }
        return error;
    }
    virtual eError fill_ellipse
    (tOffset x, tOffset y, tSize w, tSize h, eQuadrant q = e_QUADRANT_ALL) {
        eError error = e_ERROR_NONE;
        tImageInterface* image = 0;
        if ((image = this->image())) {
            filled_midpoint_ellipse_image ellipse(*image);
            ellipse.plot_ellipse(*image, x,y, w,h, q);
        }
        return error;
    }
    virtual eError hollow_ellipse
    (tOffset x, tOffset y, tSize w, tSize h, eQuadrant q = e_QUADRANT_ALL) {
        eError error = e_ERROR_NONE;
        tImageInterface* image = 0;
        if ((image = this->image())) {
            hollow_midpoint_ellipse_image ellipse(*image);
            ellipse.plot_ellipse(*image, x,y, w,h, q);
        }
        return error;
    }

    virtual tImageInterface* set_image(tImageInterface* image) {
        tImageInterface* prevImage = image_;
        image_ = image;
        return prevImage;
    }
    virtual tImageInterface* image() const {
        tImageInterface* image = image_;
        return image;
    }

protected:
    tImageInterface* image_;
};
typedef imaget<> image;

} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_HPP 
