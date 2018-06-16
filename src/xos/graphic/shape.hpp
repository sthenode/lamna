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

typedef shape_interface shape_implements;
typedef base shape_extends;
///////////////////////////////////////////////////////////////////////
///  Class: shape
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS shape
: virtual public shape_implements, private shape_extends {
public:
    typedef shape_implements implements;
    typedef shape_extends extends;

    shape
    (image_interface& image,
     tSize width = 0, tSize height = 0,
     image_interface* selectedImage = 0)
    : m_item(*this), m_image(image),
      m_width(width), m_height(height),
      m_selectedImage(selectedImage) {
    }
    virtual ~shape() {
    }

    virtual tImageInterface* select_as_image() {
        tImageInterface* prevImage = 0;
        prevImage = m_image.select_image(this);
        return prevImage;
    }
    virtual tImageInterface* set_as_image() {
        tImageInterface* prevImage = 0;
        prevImage = m_image.set_image(this);
        return prevImage;
    }

    virtual tImageInterface* set_image(tImageInterface* image) {
        tImageInterface* prevImage = this->image();
        m_selectedImage = image;
        return prevImage;
    }
    virtual tImageInterface* image() const {
        tImageInterface* image = 0;
        image = m_selectedImage;
        return image;
    }

    virtual eError set_size(tSize width, tSize height) {
        eError error = e_ERROR_NONE;
        m_width = width;
        m_height = height;
        error = on_set_size(width, height);
        return error;
    }

    virtual tSize width() const {
        return m_width;
    }
    virtual tSize height() const {
        return m_height;
    }
    
protected:
    shape_item m_item;
    image_interface& m_image;
    image_interface* m_selectedImage;
    tSize m_width, m_height;
};

} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_SHAPE_HPP 
