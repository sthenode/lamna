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
///   File: filled_circle.hpp
///
/// Author: $author$
///   Date: 6/15/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_SURFACE_FILLED_CIRCLE_HPP
#define _XOS_GRAPHIC_SURFACE_FILLED_CIRCLE_HPP

#include "xos/graphic/surface/shape.hpp"

namespace xos {
namespace graphic {
namespace surface {

///////////////////////////////////////////////////////////////////////
///  Class: filled_circlet
///////////////////////////////////////////////////////////////////////
template
<class TShape = shape,
 class TImageInterface = image_interface,
 class TExtends = TShape>

class _EXPORT_CLASS filled_circlet: public TExtends {
public:
    typedef TExtends extends;

    typedef TShape tShape;
    typedef TImageInterface tImageInterface;

    filled_circlet
    (tImageInterface& image, tShape& color, tSize r)
    : extends(image, r,r), circle_(image), color_(color), r_(r) {
    }
    virtual ~filled_circlet() {
    }

    virtual eError fill(tOffset x, tOffset y, tSize w, tSize h) {
        eError error = e_ERROR_NONE;
        if ((0 < w) && (0 < h) && (0 < r_)) {
            circle_.plot_circle(color_, x,y, r_, e_CIRCLE_QUADRANT_4);
            circle_.plot_circle(color_, x,y+h-1, r_, e_CIRCLE_QUADRANT_3);
            if ((2 < w)) {
                color_.fill(this->surface_image_, x+1,y-r_+1, w-2,r_);
                color_.fill(this->surface_image_, x+1,y+h-1, w-2,r_);
            }
            if ((2 < h)) {
                color_.fill(this->surface_image_, x-r_+1,y+1, w+r_+r_-2,h-2);
            }
            circle_.plot_circle(color_, x+w-1,y, r_, e_CIRCLE_QUADRANT_1);
            circle_.plot_circle(color_, x+w-1,y+h-1, r_, e_CIRCLE_QUADRANT_2);
        }
        return error;
    }
    virtual eError plot(tOffset x, tOffset y) {
        eError error = e_ERROR_NONE;
        circle_.plot_circle(color_, x,y, r_);
        return error;
    }

protected:
    filled_midpoint_circle_image circle_;
    tShape& color_;
    tSize r_;
};
typedef filled_circlet<> filled_circle;

} /// namespace surface
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_SURFACE_FILLED_CIRCLE_HPP 
