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
///   Date: 6/12/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_SHAPE_HPP
#define _XOS_GRAPHIC_IMAGE_SHAPE_HPP

#include "xos/graphic/shape_interface.hpp"
#include "xos/graphic/shape_item.hpp"

namespace xos {
namespace graphic {

///////////////////////////////////////////////////////////////////////
///  Class: shapet
///////////////////////////////////////////////////////////////////////
template 
<class TImageInterface = image_interface, class TItem = shape_item,
 class TImplements = shape_interface, class TExtends = base>

class _EXPORT_CLASS shapet: virtual public TImplements, private TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef TItem tItem;
    typedef TImageInterface tImageInterface;
    
    shapet
    (tImageInterface& image,
     tSize width = 0, tSize height = 0, 
     tImageInterface* selected_image = 0)
    : item_(*this), image_(image),
      selected_image_(selected_image),
      width_(width), height_(height) {
    }
    virtual ~shapet() {
    }

    virtual tImageInterface* select_as_image() {
        tImageInterface* prev_image = image_.select_image(this);
        return prev_image;
    }
    virtual tImageInterface* set_as_image() {
        tImageInterface* prev_image = image_.set_image(this);
        return prev_image;
    }

    virtual tImageInterface* set_image(tImageInterface* image) {
        tImageInterface* prev_image = this->image();
        selected_image_ = image;
        return prev_image;
    }
    virtual tImageInterface* image() const {
        tImageInterface* image = selected_image_;
        return image;
    }

    virtual eError set_size(tSize width, tSize height) {
        eError error = e_ERROR_NONE;
        width_ = width;
        height_ = height;
        error = this->on_set_size(width, height);
        return error;
    }

    virtual tSize width() const {
        return width_;
    }
    virtual tSize height() const {
        return height_;
    }
    
protected:
    tItem item_;
    tImageInterface& image_;
    tImageInterface* selected_image_;
    tSize width_, height_;
};
typedef shapet<> shape;

} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_SHAPE_HPP 
