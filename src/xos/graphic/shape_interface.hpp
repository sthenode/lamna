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
///   File: shape_interface.hpp
///
/// Author: $author$
///   Date: 6/12/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_SHAPE_INTERFACE_HPP
#define _XOS_GRAPHIC_SHAPE_INTERFACE_HPP

#include "xos/graphic/image_interface.hpp"

namespace xos {
namespace graphic {

///////////////////////////////////////////////////////////////////////
///  Class: shape_interface
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS shape_interface: virtual public image_interface {
public:
    typedef image_interface implements;

    virtual tImageInterface* select_as_image() {
        tImageInterface* prevImage = 0;
        return prevImage;
    }
    virtual tImageInterface* set_as_image() {
        tImageInterface* prevImage = 0;
        return prevImage;
    }

    virtual tImageInterface* set_image(tImageInterface* image) {
        tImageInterface* prevImage = this->image();
        return prevImage;
    }
    virtual tImageInterface* image() const {
        tImageInterface* image = 0;
        return image;
    }

    virtual eError set_size(tSize width, tSize height) {
        eError error = e_ERROR_NONE;
        return error;
    }
    virtual eError on_set_size(tSize width, tSize height) {
        eError error = e_ERROR_NONE;
        return error;
    }

    virtual tSize width() const {
        return 0;
    }
    virtual tSize height() const {
        return 0;
    }
};

} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_SHAPE_INTERFACE_HPP 
